import collections
import json
import random
import string
import urllib
import urllib.parse
import urllib.request



token = "WyI3Nzg4IiwiU2tOVnVKc3k2amxyMmhNU2RLREZSZUNBNlk5WFdIcmlaUW9ZeU5JdSJd"
product_id = 4848

# Generate keys

def _random_bool():
  return random.randint(0,1) == 1

_alphabet = string.ascii_letters + string.digits + " "
def _random_string(empty=None):
  if empty is None:
    empty = -1
  if random.random() < empty:
    return ""

  return "".join(random.choices(_alphabet, k=random.randint(1, 25)))

class LicenseKey(object):
  def __init__(self, key_string=None, product_id=None, period=None, f1=None,
      f2=None, f3=None, f4=None, f5=None, f6=None, f7=None, f8=None, notes=None,
      block=None, customer=None, trial_activation=None, maxnoofmachines=None,
      allowedmachines=None, data_objects=None):
    self.key_string = key_string
    self.product_id = product_id
    self.period = period
    self.f1 = f1
    self.f2 = f2
    self.f3 = f3
    self.f4 = f4
    self.f5 = f5
    self.f6 = f6
    self.f7 = f7
    self.f8 = f8
    self.notes = notes
    self.block = block
    self.customer = customer
    self.trial_activation = trial_activation
    self.maxnoofmachines = maxnoofmachines
    self.allowedmachines = allowedmachines
    self.data_objects = data_objects

  def __str__(self):
    return "".join([
        "LicenseKey(",
        "period=", str(license_key.period), ", ",
        "f1=", str(license_key.f1), ", ",
        "f2=", str(license_key.f2), ", ",
        "f3=", str(license_key.f3), ", ",
        "f4=", str(license_key.f4), ", ",
        "f5=", str(license_key.f5), ", ",
        "f6=", str(license_key.f6), ", ",
        "f7=", str(license_key.f7), ", ",
        "f8=", str(license_key.f8), ", ",
        "notes=\"", str(license_key.notes), "\", ",
        "block=", str(license_key.block), ", ",
        "customer=", str(license_key.customer), ", ",
        "trial_activation=", str(license_key.trial_activation), ", ",
        "maxnoofmachines=", str(license_key.maxnoofmachines), ", ",
        "allowedmachines=\"", str(license_key.allowedmachines.replace("\n", ",")), "\", ",
        "data_objects=[", ",".join([ str(data_object) for data_object in self.data_objects]),
        ")",
      ])

class Customer(object):
  def __init__(self, id=None, name=None, email=None, company_name=None, created=None):
    self.id = id
    self.name = name
    self.email = email
    self.company_name = company_name
    self.created = created

  def __str__(self):
    return "Customer(name=\"{name}\", email=\"{email}\", company_name=\"{company_name}\", created={created})".format(
             name=self.name, email=self.email, company_name=self.company_name, created=self.created
           )

class DataObject(object):
  def __init__(self, id=None, name=None, string_value=None, int_value=None):
    self.id = id
    self.name = name
    self.string_value = string_value
    self.int_value = int_value

  def __str__(self):
    return "DataObject(name=\"{name}\", string_value=\"{string_value}\", int_value={int_value})".format(
             name=self.name, string_value=self.string_value, int_value=self.int_value
           )

def randomize_license_key(license_key):
  if license_key.period is None:
    license_key.period = random.randint(0, 30)

  if license_key.f1 is None:
    license_key.f1 = _random_bool()

  if license_key.f2 is None:
    license_key.f2 = _random_bool()

  if license_key.f3 is None:
    license_key.f3 = _random_bool()

  if license_key.f4 is None:
    license_key.f4 = _random_bool()

  if license_key.f5 is None:
    license_key.f5 = _random_bool()

  if license_key.f6 is None:
    license_key.f6 = _random_bool()

  if license_key.f7 is None:
    license_key.f7 = _random_bool()

  if license_key.f8 is None:
    license_key.f8 = _random_bool()

  if license_key.notes is None:
    license_key.notes = _random_string(empty=0.5)

  if license_key.block is None:
    license_key.block = False

  if license_key.customer is None and random.random() < 0.5:
    license_key.customer = Customer()
  if license_key.customer is not None:
    license_key.customer = randomize_customer(license_key.customer)

  if license_key.trial_activation is None:
    license_key.trial_activation = _random_bool()

  if license_key.maxnoofmachines is None:
    license_key.maxnoofmachines = random.randint(1, 5)

  if license_key.allowedmachines is None:
    license_key.allowedmachines = "\n".join([_random_string() for _ in range(random.randint(0,3))])

  if license_key.data_objects is None:
    license_key.data_objects = [randomize_data_object(DataObject()) for _ in range(random.randint(0, 3))]

  return license_key

def randomize_customer(customer, empty=0.5):
  if customer.name is None:
    customer.name = _random_string()

  if customer.email is None:
    customer.email = _random_string(empty=0.5)

  if customer.company_name is None:
    customer.company_name = _random_string(empty=0.5)

  return customer

def randomize_data_object(data_object):
  if data_object.name is None:
    data_object.name = _random_string()

  if data_object.string_value is None:
    data_object.string_value = _random_string(empty=0.5)

  if data_object.int_value is None:
    data_object.int_value = random.randint(0, 1000000)

  return data_object

# Connect to web api

def create_license_key(license_key, customer_id=None):
  args = {"token": token, "ProductId": product_id, "Period": license_key.period, "F1": license_key.f1, "F2": license_key.f2, "F3": license_key.f3, "F4": license_key.f4, "F5": license_key.f5, "F6": license_key.f6, "F7": license_key.f7, "F8": license_key.f8, "Notes": license_key.notes, "Block": license_key.block, "TrialActivation": license_key.trial_activation, "MaxNoOfMachines": license_key.maxnoofmachines, "AllowedMachines": license_key.allowedmachines}
  if customer_id is not None:
    args["CustomerId"] = customer_id
  args = urllib.parse.urlencode(args)
  args = args.encode()

  with urllib.request.urlopen("https://app.cryptolens.io/api/Key/CreateKey", data=args) as f:
    response = f.readline()
  j = json.loads(response)
  return j["key"]

def create_customer(customer):
  args = urllib.parse.urlencode({"token": token, "ProductId": product_id, "Name": customer.name, "Email": customer.email, "CompanyName": customer.company_name})
  args = args.encode()

  with urllib.request.urlopen("https://app.cryptolens.io/api/customer/AddCustomer", data=args) as f:
    response = f.readline()
  j = json.loads(response)
  return j["customerId"]

def create_data_object(data_object, key_string):
  args = urllib.parse.urlencode({"token": token, "ProductId": product_id, "Name": data_object.name, "StringValue": data_object.string_value, "IntValue": data_object.int_value, "Key": key_string})
  args = args.encode()

  with urllib.request.urlopen("https://app.cryptolens.io/api/data/AddDataObjectToKey", data=args) as f:
    response = f.readline()
  j = json.loads(response)
  return j["id"]

def extend_license(key_string, days):
  args = urllib.parse.urlencode({"token": token, "ProductId": product_id, "Key": key_string, "NoOfDays": days})
  args = args.encode()

  with urllib.request.urlopen("https://app.cryptolens.io/api/key/ExtendLicense", data=args) as f:
    response = f.readline()
  j = json.loads(response)
  if j["result"] != 0:
    raise Exception()

if __name__ == "__main__":
  for i in range(256):
    for _ in range(4):
      license_key = LicenseKey(
                      f1 = i & 0x01 != 0,
                      f2 = i & 0x02 != 0,
                      f3 = i & 0x04 != 0,
                      f4 = i & 0x08 != 0,
                      f5 = i & 0x10 != 0,
                      f6 = i & 0x20 != 0,
                      f7 = i & 0x40 != 0,
                      f8 = i & 0x80 != 0,
                    )
      randomize_license_key(license_key)

      customer_id = create_customer(license_key.customer) if license_key.customer is not None else None
      key_string = create_license_key(license_key, customer_id)
      extend_license(key_string, 50*365 + random.randint(0, 50*365))
      for data_object in license_key.data_objects:
        create_data_object(data_object, key_string)
      print(key_string)
