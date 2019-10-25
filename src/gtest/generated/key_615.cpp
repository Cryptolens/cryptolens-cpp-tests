#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key615 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "MNACV-JTQJP-OWUER-IPIYS", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key615() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key615::license_key_;

TEST_F(v20180502_online_Key615, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801939);
  EXPECT_EQ(license_key->get_expires(), 4007379539);
  EXPECT_EQ(license_key->get_period(), 28258);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key615, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 666); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MNACV-JTQJP-OWUER-IPIYS"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8E5jV7rqoFq8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }
}

TEST_F(v20180502_online_Key615, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811894));

  // XXX: We have quadratic performance here. Could be some concern here given that set of activated machines can be large
  auto const& activated_machines = *(license_key->get_activated_machines());
  for (auto i = activated_machines.cbegin(); i != activated_machines.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_mid() == j->get_mid() && i->get_ip() == j->get_ip() && i->get_time() == j->get_time()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

TEST_F(v20180502_online_Key615, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6691);
    EXPECT_EQ(customer.get_name(), "FyGBxR5xe3p3");
    EXPECT_EQ(customer.get_email(), "DvsOoCbkX");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801939);
  }
}

TEST_F(v20180502_online_Key615, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4821, "sHA9IZeiAWwiQJ7E5Z0M2d", "6gJJqU01OFRJElKLNWYDrFK", 426441));
  expected.push_back(cryptolens::DataObject(4822, "BXC1r6bIP0jg4hKK", "85Bpyw32OePp", 317623));
  expected.push_back(cryptolens::DataObject(4823, "GdWHUVaU1ngjnGeW3gXx", "c79hiepuk4EJbuuSCXzogsn", 767241));

  // XXX: We have quadratic performance here. It's fine given current restrictions on data objects
  auto const& data_objects = *(license_key->get_data_objects());
  for (auto i = data_objects.cbegin(); i != data_objects.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_id() == j->get_id() && i->get_name() == j->get_name() && i->get_string_value() == j->get_string_value() && i->get_int_value() == j->get_int_value()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}


} // namespace tests_v20180502


namespace tests_v20190401 {

class v20190401_online_Key615 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "MNACV-JTQJP-OWUER-IPIYS");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key615() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key615::license_key_;

TEST_F(v20190401_online_Key615, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801939);
  EXPECT_EQ(license_key->get_expires(), 4007379539);
  EXPECT_EQ(license_key->get_period(), 28258);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key615, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 666); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MNACV-JTQJP-OWUER-IPIYS"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8E5jV7rqoFq8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }
}

TEST_F(v20190401_online_Key615, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811894));

  // XXX: We have quadratic performance here. Could be some concern here given that set of activated machines can be large
  auto const& activated_machines = *(license_key->get_activated_machines());
  for (auto i = activated_machines.cbegin(); i != activated_machines.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_mid() == j->get_mid() && i->get_ip() == j->get_ip() && i->get_time() == j->get_time()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

TEST_F(v20190401_online_Key615, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6691);
    EXPECT_EQ(customer.get_name(), "FyGBxR5xe3p3");
    EXPECT_EQ(customer.get_email(), "DvsOoCbkX");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801939);
  }
}

TEST_F(v20190401_online_Key615, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4821, "sHA9IZeiAWwiQJ7E5Z0M2d", "6gJJqU01OFRJElKLNWYDrFK", 426441));
  expected.push_back(cryptolens::DataObject(4822, "BXC1r6bIP0jg4hKK", "85Bpyw32OePp", 317623));
  expected.push_back(cryptolens::DataObject(4823, "GdWHUVaU1ngjnGeW3gXx", "c79hiepuk4EJbuuSCXzogsn", 767241));

  // XXX: We have quadratic performance here. It's fine given current restrictions on data objects
  auto const& data_objects = *(license_key->get_data_objects());
  for (auto i = data_objects.cbegin(); i != data_objects.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_id() == j->get_id() && i->get_name() == j->get_name() && i->get_string_value() == j->get_string_value() && i->get_int_value() == j->get_int_value()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

class v20190401_offline_json_Key615 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2NjYsIktleSI6Ik1OQUNWLUpUUUpQLU9XVUVSLUlQSVlTIiwiQ3JlYXRlZCI6MTU2NTgwMTkzOSwiRXhwaXJlcyI6NDAwNzM3OTUzOSwiUGVyaW9kIjoyODI1OCwiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDk0NywiQ3VzdG9tZXIiOnsiSWQiOjY2OTEsIk5hbWUiOiJGeUdCeFI1eGUzcDMiLCJFbWFpbCI6IkR2c09vQ2JrWCIsIkNvbXBhbnlOYW1lIjpudWxsLCJDcmVhdGVkIjoxNTY1ODAxOTM5fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTg5NH1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6IjhFNWpWN3Jxb0ZxOCIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDgyMSwiTmFtZSI6InNIQTlJWmVpQVd3aVFKN0U1WjBNMmQiLCJTdHJpbmdWYWx1ZSI6IjZnSkpxVTAxT0ZSSkVsS0xOV1lEckZLIiwiSW50VmFsdWUiOjQyNjQ0MX0seyJJZCI6NDgyMiwiTmFtZSI6IkJYQzFyNmJJUDBqZzRoS0siLCJTdHJpbmdWYWx1ZSI6Ijg1QnB5dzMyT2VQcCIsIkludFZhbHVlIjozMTc2MjN9LHsiSWQiOjQ4MjMsIk5hbWUiOiJHZFdIVVZhVTFuZ2puR2VXM2dYeCIsIlN0cmluZ1ZhbHVlIjoiYzc5aGllcHVrNEVKYnV1U0NYem9nc24iLCJJbnRWYWx1ZSI6NzY3MjQxfV0sIlNpZ25EYXRlIjoxNTcwNDYxMTQ0fQ==\",\"signature\":\"cEpP8t41+WLsPPS6RzUbH6KCCBSAiMKNNzyYJUkFbG2WHo8bXemG5bAA6lQba8RqROI/jTSXg0ZS4dY8v92wqd+ZdXSaJtcNxmFncY7FGfMO5gNq4p5CGzI6F4HD65mlu63uUH3iZc++4Pr3VzClSPbm04FOpV48m6KkssB7mcox0A+ObveQ7oVR6LU3EoQEjErCMIrDpJ5H4tB/5C4PARClKO5/Z3li4yePJ0wYTIVKzisb9hj/YQufK+XbIhvnvZI5O0Bt2cx8MhQeMqtUCYf+Uxk9/T92NF5lhaNl/prbv1a0ULAyrKznTNCzOSEawtQ4ea7abEkp/gnLJOSrOQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key615() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key615::license_key_;

TEST_F(v20190401_offline_json_Key615, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801939);
  EXPECT_EQ(license_key->get_expires(), 4007379539);
  EXPECT_EQ(license_key->get_period(), 28258);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key615, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 666); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MNACV-JTQJP-OWUER-IPIYS"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8E5jV7rqoFq8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }
}

TEST_F(v20190401_offline_json_Key615, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811894));

  // XXX: We have quadratic performance here. Could be some concern here given that set of activated machines can be large
  auto const& activated_machines = *(license_key->get_activated_machines());
  for (auto i = activated_machines.cbegin(); i != activated_machines.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_mid() == j->get_mid() && i->get_ip() == j->get_ip() && i->get_time() == j->get_time()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

TEST_F(v20190401_offline_json_Key615, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6691);
    EXPECT_EQ(customer.get_name(), "FyGBxR5xe3p3");
    EXPECT_EQ(customer.get_email(), "DvsOoCbkX");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801939);
  }
}

TEST_F(v20190401_offline_json_Key615, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4821, "sHA9IZeiAWwiQJ7E5Z0M2d", "6gJJqU01OFRJElKLNWYDrFK", 426441));
  expected.push_back(cryptolens::DataObject(4822, "BXC1r6bIP0jg4hKK", "85Bpyw32OePp", 317623));
  expected.push_back(cryptolens::DataObject(4823, "GdWHUVaU1ngjnGeW3gXx", "c79hiepuk4EJbuuSCXzogsn", 767241));

  // XXX: We have quadratic performance here. It's fine given current restrictions on data objects
  auto const& data_objects = *(license_key->get_data_objects());
  for (auto i = data_objects.cbegin(); i != data_objects.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_id() == j->get_id() && i->get_name() == j->get_name() && i->get_string_value() == j->get_string_value() && i->get_int_value() == j->get_int_value()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

class v20190401_offline_compact_Key615 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2NjYsIktleSI6Ik1OQUNWLUpUUUpQLU9XVUVSLUlQSVlTIiwiQ3JlYXRlZCI6MTU2NTgwMTkzOSwiRXhwaXJlcyI6NDAwNzM3OTUzOSwiUGVyaW9kIjoyODI1OCwiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDk0NywiQ3VzdG9tZXIiOnsiSWQiOjY2OTEsIk5hbWUiOiJGeUdCeFI1eGUzcDMiLCJFbWFpbCI6IkR2c09vQ2JrWCIsIkNvbXBhbnlOYW1lIjpudWxsLCJDcmVhdGVkIjoxNTY1ODAxOTM5fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTg5NH1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6IjhFNWpWN3Jxb0ZxOCIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDgyMSwiTmFtZSI6InNIQTlJWmVpQVd3aVFKN0U1WjBNMmQiLCJTdHJpbmdWYWx1ZSI6IjZnSkpxVTAxT0ZSSkVsS0xOV1lEckZLIiwiSW50VmFsdWUiOjQyNjQ0MX0seyJJZCI6NDgyMiwiTmFtZSI6IkJYQzFyNmJJUDBqZzRoS0siLCJTdHJpbmdWYWx1ZSI6Ijg1QnB5dzMyT2VQcCIsIkludFZhbHVlIjozMTc2MjN9LHsiSWQiOjQ4MjMsIk5hbWUiOiJHZFdIVVZhVTFuZ2puR2VXM2dYeCIsIlN0cmluZ1ZhbHVlIjoiYzc5aGllcHVrNEVKYnV1U0NYem9nc24iLCJJbnRWYWx1ZSI6NzY3MjQxfV0sIlNpZ25EYXRlIjoxNTcwNDYxMTQ0fQ==";
    saved_response += "-";
    saved_response += "cEpP8t41+WLsPPS6RzUbH6KCCBSAiMKNNzyYJUkFbG2WHo8bXemG5bAA6lQba8RqROI/jTSXg0ZS4dY8v92wqd+ZdXSaJtcNxmFncY7FGfMO5gNq4p5CGzI6F4HD65mlu63uUH3iZc++4Pr3VzClSPbm04FOpV48m6KkssB7mcox0A+ObveQ7oVR6LU3EoQEjErCMIrDpJ5H4tB/5C4PARClKO5/Z3li4yePJ0wYTIVKzisb9hj/YQufK+XbIhvnvZI5O0Bt2cx8MhQeMqtUCYf+Uxk9/T92NF5lhaNl/prbv1a0ULAyrKznTNCzOSEawtQ4ea7abEkp/gnLJOSrOQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key615() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key615::license_key_;

TEST_F(v20190401_offline_compact_Key615, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801939);
  EXPECT_EQ(license_key->get_expires(), 4007379539);
  EXPECT_EQ(license_key->get_period(), 28258);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key615, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 666); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MNACV-JTQJP-OWUER-IPIYS"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8E5jV7rqoFq8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54947); }
}

TEST_F(v20190401_offline_compact_Key615, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811894));

  // XXX: We have quadratic performance here. Could be some concern here given that set of activated machines can be large
  auto const& activated_machines = *(license_key->get_activated_machines());
  for (auto i = activated_machines.cbegin(); i != activated_machines.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_mid() == j->get_mid() && i->get_ip() == j->get_ip() && i->get_time() == j->get_time()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}

TEST_F(v20190401_offline_compact_Key615, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6691);
    EXPECT_EQ(customer.get_name(), "FyGBxR5xe3p3");
    EXPECT_EQ(customer.get_email(), "DvsOoCbkX");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801939);
  }
}

TEST_F(v20190401_offline_compact_Key615, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4821, "sHA9IZeiAWwiQJ7E5Z0M2d", "6gJJqU01OFRJElKLNWYDrFK", 426441));
  expected.push_back(cryptolens::DataObject(4822, "BXC1r6bIP0jg4hKK", "85Bpyw32OePp", 317623));
  expected.push_back(cryptolens::DataObject(4823, "GdWHUVaU1ngjnGeW3gXx", "c79hiepuk4EJbuuSCXzogsn", 767241));

  // XXX: We have quadratic performance here. It's fine given current restrictions on data objects
  auto const& data_objects = *(license_key->get_data_objects());
  for (auto i = data_objects.cbegin(); i != data_objects.cend(); ++i) {
    ASSERT_NE(expected.size(), 0);
    for (auto j = expected.begin(); j != expected.end(); ++j) {
      if (i->get_id() == j->get_id() && i->get_name() == j->get_name() && i->get_string_value() == j->get_string_value() && i->get_int_value() == j->get_int_value()) {
        expected.erase(j);
        break;
      }
    }
  }
  ASSERT_EQ(expected.size(), 0);
}


} // namespace tests_v20190401
