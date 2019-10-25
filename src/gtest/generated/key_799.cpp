#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key799 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "BMQFY-KNWFQ-BYRCQ-OPZZM", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key799() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key799::license_key_;

TEST_F(v20180502_online_Key799, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802333);
  EXPECT_EQ(license_key->get_expires(), 3981469619);
  EXPECT_EQ(license_key->get_period(), 27959);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key799, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 850); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BMQFY-KNWFQ-BYRCQ-OPZZM"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "CmbFY99nkU"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }
}

TEST_F(v20180502_online_Key799, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812019));

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

TEST_F(v20180502_online_Key799, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6781);
    EXPECT_EQ(customer.get_name(), "TaOAO7Syjoj");
    EXPECT_EQ(customer.get_email(), "FoQbNEtk1lfqZA8LTzDoN");
    EXPECT_EQ(customer.get_company_name(), "2dVzbYZBY45M3bZL3R4a2y44");
    EXPECT_EQ(customer.get_created(), 1565802332);
  }
}

TEST_F(v20180502_online_Key799, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5092, "cjIqRI9BPaGzdlN5viS nP9", "MKICrgc4jlBk4FqF2XeA4q", 258731));
  expected.push_back(cryptolens::DataObject(5093, "84pimpM", "", 491675));
  expected.push_back(cryptolens::DataObject(5094, "TDfz9f3H1BGg0fPINc0dR", "RhhxAYubRcRKs8E", 505982));

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

class v20190401_online_Key799 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "BMQFY-KNWFQ-BYRCQ-OPZZM");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key799() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key799::license_key_;

TEST_F(v20190401_online_Key799, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802333);
  EXPECT_EQ(license_key->get_expires(), 3981469619);
  EXPECT_EQ(license_key->get_period(), 27959);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key799, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 850); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BMQFY-KNWFQ-BYRCQ-OPZZM"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "CmbFY99nkU"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }
}

TEST_F(v20190401_online_Key799, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812019));

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

TEST_F(v20190401_online_Key799, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6781);
    EXPECT_EQ(customer.get_name(), "TaOAO7Syjoj");
    EXPECT_EQ(customer.get_email(), "FoQbNEtk1lfqZA8LTzDoN");
    EXPECT_EQ(customer.get_company_name(), "2dVzbYZBY45M3bZL3R4a2y44");
    EXPECT_EQ(customer.get_created(), 1565802332);
  }
}

TEST_F(v20190401_online_Key799, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5092, "cjIqRI9BPaGzdlN5viS nP9", "MKICrgc4jlBk4FqF2XeA4q", 258731));
  expected.push_back(cryptolens::DataObject(5093, "84pimpM", "", 491675));
  expected.push_back(cryptolens::DataObject(5094, "TDfz9f3H1BGg0fPINc0dR", "RhhxAYubRcRKs8E", 505982));

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

class v20190401_offline_json_Key799 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4NTAsIktleSI6IkJNUUZZLUtOV0ZRLUJZUkNRLU9QWlpNIiwiQ3JlYXRlZCI6MTU2NTgwMjMzMywiRXhwaXJlcyI6Mzk4MTQ2OTYxOSwiUGVyaW9kIjoyNzk1OSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6dHJ1ZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6IkNtYkZZOTlua1UiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTEzMSwiQ3VzdG9tZXIiOnsiSWQiOjY3ODEsIk5hbWUiOiJUYU9BTzdTeWpvaiIsIkVtYWlsIjoiRm9RYk5FdGsxbGZxWkE4TFR6RG9OIiwiQ29tcGFueU5hbWUiOiIyZFZ6YllaQlk0NU0zYlpMM1I0YTJ5NDQiLCJDcmVhdGVkIjoxNTY1ODAyMzMyfSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMjAxOX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MiwiQWxsb3dlZE1hY2hpbmVzIjoiIiwiRGF0YU9iamVjdHMiOlt7IklkIjo1MDkyLCJOYW1lIjoiY2pJcVJJOUJQYUd6ZGxONXZpUyBuUDkiLCJTdHJpbmdWYWx1ZSI6Ik1LSUNyZ2M0amxCazRGcUYyWGVBNHEiLCJJbnRWYWx1ZSI6MjU4NzMxfSx7IklkIjo1MDkzLCJOYW1lIjoiODRwaW1wTSIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ5MTY3NX0seyJJZCI6NTA5NCwiTmFtZSI6IlREZno5ZjNIMUJHZzBmUElOYzBkUiIsIlN0cmluZ1ZhbHVlIjoiUmhoeEFZdWJSY1JLczhFIiwiSW50VmFsdWUiOjUwNTk4Mn1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI0OX0=\",\"signature\":\"X5F06ybwt+jyxod87NpJcBo1Hx5TvlV6vjRpdYcGDIiqKf6SFNe3sjV2O+lTMMidXl8AcQffpA1T+x3j2uRsfBQ8UtZxsya1dnm9gkJRVpcUUCEVjpgDdK49SJoMFN26RmMMBLVHAM3pqVlGiTWQT4CWZ9Flw9mm80iFQSr9KwG739WRiwgnbBk1U3QECi3lmCpBz2OeqUSBQv3aMy8IFp6p30pYE98ETJBYi9mXI/6MRAd9jB6LAqKPClDYLIW7SyPXPSadBJXa1NSItdspVBXmRxl8GqDaUfjhARciymo5nNLAMazdkJcT1HtroU0kQmIGce37JGGHmsa7t0wfKA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key799() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key799::license_key_;

TEST_F(v20190401_offline_json_Key799, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802333);
  EXPECT_EQ(license_key->get_expires(), 3981469619);
  EXPECT_EQ(license_key->get_period(), 27959);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key799, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 850); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BMQFY-KNWFQ-BYRCQ-OPZZM"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "CmbFY99nkU"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }
}

TEST_F(v20190401_offline_json_Key799, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812019));

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

TEST_F(v20190401_offline_json_Key799, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6781);
    EXPECT_EQ(customer.get_name(), "TaOAO7Syjoj");
    EXPECT_EQ(customer.get_email(), "FoQbNEtk1lfqZA8LTzDoN");
    EXPECT_EQ(customer.get_company_name(), "2dVzbYZBY45M3bZL3R4a2y44");
    EXPECT_EQ(customer.get_created(), 1565802332);
  }
}

TEST_F(v20190401_offline_json_Key799, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5092, "cjIqRI9BPaGzdlN5viS nP9", "MKICrgc4jlBk4FqF2XeA4q", 258731));
  expected.push_back(cryptolens::DataObject(5093, "84pimpM", "", 491675));
  expected.push_back(cryptolens::DataObject(5094, "TDfz9f3H1BGg0fPINc0dR", "RhhxAYubRcRKs8E", 505982));

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

class v20190401_offline_compact_Key799 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4NTAsIktleSI6IkJNUUZZLUtOV0ZRLUJZUkNRLU9QWlpNIiwiQ3JlYXRlZCI6MTU2NTgwMjMzMywiRXhwaXJlcyI6Mzk4MTQ2OTYxOSwiUGVyaW9kIjoyNzk1OSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6dHJ1ZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6IkNtYkZZOTlua1UiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTEzMSwiQ3VzdG9tZXIiOnsiSWQiOjY3ODEsIk5hbWUiOiJUYU9BTzdTeWpvaiIsIkVtYWlsIjoiRm9RYk5FdGsxbGZxWkE4TFR6RG9OIiwiQ29tcGFueU5hbWUiOiIyZFZ6YllaQlk0NU0zYlpMM1I0YTJ5NDQiLCJDcmVhdGVkIjoxNTY1ODAyMzMyfSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMjAxOX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MiwiQWxsb3dlZE1hY2hpbmVzIjoiIiwiRGF0YU9iamVjdHMiOlt7IklkIjo1MDkyLCJOYW1lIjoiY2pJcVJJOUJQYUd6ZGxONXZpUyBuUDkiLCJTdHJpbmdWYWx1ZSI6Ik1LSUNyZ2M0amxCazRGcUYyWGVBNHEiLCJJbnRWYWx1ZSI6MjU4NzMxfSx7IklkIjo1MDkzLCJOYW1lIjoiODRwaW1wTSIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ5MTY3NX0seyJJZCI6NTA5NCwiTmFtZSI6IlREZno5ZjNIMUJHZzBmUElOYzBkUiIsIlN0cmluZ1ZhbHVlIjoiUmhoeEFZdWJSY1JLczhFIiwiSW50VmFsdWUiOjUwNTk4Mn1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI0OX0=";
    saved_response += "-";
    saved_response += "X5F06ybwt+jyxod87NpJcBo1Hx5TvlV6vjRpdYcGDIiqKf6SFNe3sjV2O+lTMMidXl8AcQffpA1T+x3j2uRsfBQ8UtZxsya1dnm9gkJRVpcUUCEVjpgDdK49SJoMFN26RmMMBLVHAM3pqVlGiTWQT4CWZ9Flw9mm80iFQSr9KwG739WRiwgnbBk1U3QECi3lmCpBz2OeqUSBQv3aMy8IFp6p30pYE98ETJBYi9mXI/6MRAd9jB6LAqKPClDYLIW7SyPXPSadBJXa1NSItdspVBXmRxl8GqDaUfjhARciymo5nNLAMazdkJcT1HtroU0kQmIGce37JGGHmsa7t0wfKA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key799() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key799::license_key_;

TEST_F(v20190401_offline_compact_Key799, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802333);
  EXPECT_EQ(license_key->get_expires(), 3981469619);
  EXPECT_EQ(license_key->get_period(), 27959);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key799, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 850); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BMQFY-KNWFQ-BYRCQ-OPZZM"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "CmbFY99nkU"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55131); }
}

TEST_F(v20190401_offline_compact_Key799, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812019));

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

TEST_F(v20190401_offline_compact_Key799, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6781);
    EXPECT_EQ(customer.get_name(), "TaOAO7Syjoj");
    EXPECT_EQ(customer.get_email(), "FoQbNEtk1lfqZA8LTzDoN");
    EXPECT_EQ(customer.get_company_name(), "2dVzbYZBY45M3bZL3R4a2y44");
    EXPECT_EQ(customer.get_created(), 1565802332);
  }
}

TEST_F(v20190401_offline_compact_Key799, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5092, "cjIqRI9BPaGzdlN5viS nP9", "MKICrgc4jlBk4FqF2XeA4q", 258731));
  expected.push_back(cryptolens::DataObject(5093, "84pimpM", "", 491675));
  expected.push_back(cryptolens::DataObject(5094, "TDfz9f3H1BGg0fPINc0dR", "RhhxAYubRcRKs8E", 505982));

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
