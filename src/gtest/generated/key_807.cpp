#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key807 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "LUDKJ-TYLLF-IUGXS-XKKJI", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key807() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key807::license_key_;

TEST_F(v20180502_online_Key807, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802352);
  EXPECT_EQ(license_key->get_expires(), 4129635952);
  EXPECT_EQ(license_key->get_period(), 29673);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key807, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 858); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LUDKJ-TYLLF-IUGXS-XKKJI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "fMDsfZlf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "sHshNZN2Ff9D2QZlo6WmLU\nwfVXB\nfkFubmAagsEBZLjLDgg"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }
}

TEST_F(v20180502_online_Key807, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812024));

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

TEST_F(v20180502_online_Key807, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6785);
    EXPECT_EQ(customer.get_name(), "XZL7m0c0E");
    EXPECT_EQ(customer.get_email(), "7GJQkqcK");
    EXPECT_EQ(customer.get_company_name(), "QreCmYblJtL9BYXbd3vL");
    EXPECT_EQ(customer.get_created(), 1565802351);
  }
}

TEST_F(v20180502_online_Key807, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5107, "PBztYnB4idvHGffXS2e", "", 615733));

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

class v20190401_online_Key807 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "LUDKJ-TYLLF-IUGXS-XKKJI");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key807() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key807::license_key_;

TEST_F(v20190401_online_Key807, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802352);
  EXPECT_EQ(license_key->get_expires(), 4129635952);
  EXPECT_EQ(license_key->get_period(), 29673);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key807, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 858); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LUDKJ-TYLLF-IUGXS-XKKJI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "fMDsfZlf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "sHshNZN2Ff9D2QZlo6WmLU\nwfVXB\nfkFubmAagsEBZLjLDgg"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }
}

TEST_F(v20190401_online_Key807, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812024));

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

TEST_F(v20190401_online_Key807, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6785);
    EXPECT_EQ(customer.get_name(), "XZL7m0c0E");
    EXPECT_EQ(customer.get_email(), "7GJQkqcK");
    EXPECT_EQ(customer.get_company_name(), "QreCmYblJtL9BYXbd3vL");
    EXPECT_EQ(customer.get_created(), 1565802351);
  }
}

TEST_F(v20190401_online_Key807, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5107, "PBztYnB4idvHGffXS2e", "", 615733));

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

class v20190401_offline_json_Key807 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4NTgsIktleSI6IkxVREtKLVRZTExGLUlVR1hTLVhLS0pJIiwiQ3JlYXRlZCI6MTU2NTgwMjM1MiwiRXhwaXJlcyI6NDEyOTYzNTk1MiwiUGVyaW9kIjoyOTY3MywiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3Ijp0cnVlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJmTURzZlpsZiIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MTM5LCJDdXN0b21lciI6eyJJZCI6Njc4NSwiTmFtZSI6IlhaTDdtMGMwRSIsIkVtYWlsIjoiN0dKUWtxY0siLCJDb21wYW55TmFtZSI6IlFyZUNtWWJsSnRMOUJZWGJkM3ZMIiwiQ3JlYXRlZCI6MTU2NTgwMjM1MX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTIwMjR9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoyLCJBbGxvd2VkTWFjaGluZXMiOiJzSHNoTlpOMkZmOUQyUVpsbzZXbUxVXG53ZlZYQlxuZmtGdWJtQWFnc0VCWkxqTERnZyIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NTEwNywiTmFtZSI6IlBCenRZbkI0aWR2SEdmZlhTMmUiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo2MTU3MzN9XSwiU2lnbkRhdGUiOjE1NzA0NjEyNTJ9\",\"signature\":\"JdxUa9vF1TLtRgkQRpMVVYOGvzXRX5IqidHnWrJdbPdWaeXpCdFbHh3rRaS3FvlNZGNsR+O54InHKYD/3ZwdEfWSXwBXoPQmqmBzfq9+Ixx5O2AoXR0lfVWQ+vp4UvvdxEgd1eqcYCebovNX41laM0iusIhx7CpjYC1AUyGfwoqVOv/T2UNqOp5tfpnkV8FVBtdRxXVaOt9DOshCSOkCvnHFz+1HHHd1czqUryslGwWyu5dhxhvZYpC1Nu2Uc0UvDZDFXshC99wFqw1u7SLxdjvlHUPqvegXc8LhyNhUuZec/c3+fTYXzRcZP8vDrZnsm++VtxY0hoamp4rCZlaNvg==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key807() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key807::license_key_;

TEST_F(v20190401_offline_json_Key807, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802352);
  EXPECT_EQ(license_key->get_expires(), 4129635952);
  EXPECT_EQ(license_key->get_period(), 29673);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key807, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 858); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LUDKJ-TYLLF-IUGXS-XKKJI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "fMDsfZlf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "sHshNZN2Ff9D2QZlo6WmLU\nwfVXB\nfkFubmAagsEBZLjLDgg"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }
}

TEST_F(v20190401_offline_json_Key807, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812024));

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

TEST_F(v20190401_offline_json_Key807, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6785);
    EXPECT_EQ(customer.get_name(), "XZL7m0c0E");
    EXPECT_EQ(customer.get_email(), "7GJQkqcK");
    EXPECT_EQ(customer.get_company_name(), "QreCmYblJtL9BYXbd3vL");
    EXPECT_EQ(customer.get_created(), 1565802351);
  }
}

TEST_F(v20190401_offline_json_Key807, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5107, "PBztYnB4idvHGffXS2e", "", 615733));

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

class v20190401_offline_compact_Key807 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4NTgsIktleSI6IkxVREtKLVRZTExGLUlVR1hTLVhLS0pJIiwiQ3JlYXRlZCI6MTU2NTgwMjM1MiwiRXhwaXJlcyI6NDEyOTYzNTk1MiwiUGVyaW9kIjoyOTY3MywiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3Ijp0cnVlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJmTURzZlpsZiIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MTM5LCJDdXN0b21lciI6eyJJZCI6Njc4NSwiTmFtZSI6IlhaTDdtMGMwRSIsIkVtYWlsIjoiN0dKUWtxY0siLCJDb21wYW55TmFtZSI6IlFyZUNtWWJsSnRMOUJZWGJkM3ZMIiwiQ3JlYXRlZCI6MTU2NTgwMjM1MX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTIwMjR9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoyLCJBbGxvd2VkTWFjaGluZXMiOiJzSHNoTlpOMkZmOUQyUVpsbzZXbUxVXG53ZlZYQlxuZmtGdWJtQWFnc0VCWkxqTERnZyIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NTEwNywiTmFtZSI6IlBCenRZbkI0aWR2SEdmZlhTMmUiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo2MTU3MzN9XSwiU2lnbkRhdGUiOjE1NzA0NjEyNTJ9";
    saved_response += "-";
    saved_response += "JdxUa9vF1TLtRgkQRpMVVYOGvzXRX5IqidHnWrJdbPdWaeXpCdFbHh3rRaS3FvlNZGNsR+O54InHKYD/3ZwdEfWSXwBXoPQmqmBzfq9+Ixx5O2AoXR0lfVWQ+vp4UvvdxEgd1eqcYCebovNX41laM0iusIhx7CpjYC1AUyGfwoqVOv/T2UNqOp5tfpnkV8FVBtdRxXVaOt9DOshCSOkCvnHFz+1HHHd1czqUryslGwWyu5dhxhvZYpC1Nu2Uc0UvDZDFXshC99wFqw1u7SLxdjvlHUPqvegXc8LhyNhUuZec/c3+fTYXzRcZP8vDrZnsm++VtxY0hoamp4rCZlaNvg==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key807() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key807::license_key_;

TEST_F(v20190401_offline_compact_Key807, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802352);
  EXPECT_EQ(license_key->get_expires(), 4129635952);
  EXPECT_EQ(license_key->get_period(), 29673);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key807, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 858); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LUDKJ-TYLLF-IUGXS-XKKJI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "fMDsfZlf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "sHshNZN2Ff9D2QZlo6WmLU\nwfVXB\nfkFubmAagsEBZLjLDgg"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55139); }
}

TEST_F(v20190401_offline_compact_Key807, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812024));

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

TEST_F(v20190401_offline_compact_Key807, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6785);
    EXPECT_EQ(customer.get_name(), "XZL7m0c0E");
    EXPECT_EQ(customer.get_email(), "7GJQkqcK");
    EXPECT_EQ(customer.get_company_name(), "QreCmYblJtL9BYXbd3vL");
    EXPECT_EQ(customer.get_created(), 1565802351);
  }
}

TEST_F(v20190401_offline_compact_Key807, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5107, "PBztYnB4idvHGffXS2e", "", 615733));

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
