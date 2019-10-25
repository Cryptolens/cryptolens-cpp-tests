#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key768 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "DKHXJ-ZLGTM-NTQIT-RBPTR", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key768() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key768::license_key_;

TEST_F(v20180502_online_Key768, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802266);
  EXPECT_EQ(license_key->get_expires(), 3534944666);
  EXPECT_EQ(license_key->get_period(), 22790);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key768, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 819); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DKHXJ-ZLGTM-NTQIT-RBPTR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "uJKIR1VrI7Ph"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "orOuIer340Y3nGJ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }
}

TEST_F(v20180502_online_Key768, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811997));

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

TEST_F(v20180502_online_Key768, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6766);
    EXPECT_EQ(customer.get_name(), "5");
    EXPECT_EQ(customer.get_email(), "I7QDBbKkawXs7lKv6bTX7VZwP");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565802266);
  }
}

TEST_F(v20180502_online_Key768, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5049, "qQOCP2SLItewclXXgo", "", 713080));
  expected.push_back(cryptolens::DataObject(5050, "rQT2ivH5OTtfiTzkcq", "", 723737));
  expected.push_back(cryptolens::DataObject(5051, "A4x3AAvt", "WKD8GhC4E1XFoe Kkn7Rk", 438017));

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

class v20190401_online_Key768 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "DKHXJ-ZLGTM-NTQIT-RBPTR");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key768() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key768::license_key_;

TEST_F(v20190401_online_Key768, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802266);
  EXPECT_EQ(license_key->get_expires(), 3534944666);
  EXPECT_EQ(license_key->get_period(), 22790);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key768, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 819); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DKHXJ-ZLGTM-NTQIT-RBPTR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "uJKIR1VrI7Ph"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "orOuIer340Y3nGJ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }
}

TEST_F(v20190401_online_Key768, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811997));

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

TEST_F(v20190401_online_Key768, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6766);
    EXPECT_EQ(customer.get_name(), "5");
    EXPECT_EQ(customer.get_email(), "I7QDBbKkawXs7lKv6bTX7VZwP");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565802266);
  }
}

TEST_F(v20190401_online_Key768, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5049, "qQOCP2SLItewclXXgo", "", 713080));
  expected.push_back(cryptolens::DataObject(5050, "rQT2ivH5OTtfiTzkcq", "", 723737));
  expected.push_back(cryptolens::DataObject(5051, "A4x3AAvt", "WKD8GhC4E1XFoe Kkn7Rk", 438017));

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

class v20190401_offline_json_Key768 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4MTksIktleSI6IkRLSFhKLVpMR1RNLU5UUUlULVJCUFRSIiwiQ3JlYXRlZCI6MTU2NTgwMjI2NiwiRXhwaXJlcyI6MzUzNDk0NDY2NiwiUGVyaW9kIjoyMjc5MCwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjpmYWxzZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6InVKS0lSMVZySTdQaCIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MTAwLCJDdXN0b21lciI6eyJJZCI6Njc2NiwiTmFtZSI6IjUiLCJFbWFpbCI6Ikk3UURCYktrYXdYczdsS3Y2YlRYN1Zad1AiLCJDb21wYW55TmFtZSI6bnVsbCwiQ3JlYXRlZCI6MTU2NTgwMjI2Nn0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE5OTd9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjozLCJBbGxvd2VkTWFjaGluZXMiOiJvck91SWVyMzQwWTNuR0oiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUwNDksIk5hbWUiOiJxUU9DUDJTTEl0ZXdjbFhYZ28iLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo3MTMwODB9LHsiSWQiOjUwNTAsIk5hbWUiOiJyUVQyaXZINU9UdGZpVHprY3EiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo3MjM3Mzd9LHsiSWQiOjUwNTEsIk5hbWUiOiJBNHgzQUF2dCIsIlN0cmluZ1ZhbHVlIjoiV0tEOEdoQzRFMVhGb2UgS2tuN1JrIiwiSW50VmFsdWUiOjQzODAxN31dLCJTaWduRGF0ZSI6MTU3MDQ2MTIzMH0=\",\"signature\":\"jlQdcWI8Won6sDMMEdzgiWrngr5qJCkGHRABec9W2RPN/Fumx5ADYXR00f6HyKek/LJSbmO5VfBl2Z8dTjSjjGwpVFsUlXLxjnRH4A/HWXl/I0v5b5mGUty5NcW8Pqdu/SiQWSRWysM7xcDaOZsWocZTqMqS7R1gwPv+tkFRkkS3PGsq2LkmvDY6p0KRi3EjaMqHOQSy6C2I2uOwZjH//+Rhjz5hkDoY0KFsDr9YjGSdGZmbY16hnnzSII3c0oTzUTSrL7lWrrcqvzU7N+pXsXEgVnlmkMO1dMEmIMejfOXpwp1Tv9qqKgX0I4NNy62q4r0Hq/CiVUQs7aafnDLBZQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key768() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key768::license_key_;

TEST_F(v20190401_offline_json_Key768, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802266);
  EXPECT_EQ(license_key->get_expires(), 3534944666);
  EXPECT_EQ(license_key->get_period(), 22790);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key768, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 819); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DKHXJ-ZLGTM-NTQIT-RBPTR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "uJKIR1VrI7Ph"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "orOuIer340Y3nGJ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }
}

TEST_F(v20190401_offline_json_Key768, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811997));

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

TEST_F(v20190401_offline_json_Key768, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6766);
    EXPECT_EQ(customer.get_name(), "5");
    EXPECT_EQ(customer.get_email(), "I7QDBbKkawXs7lKv6bTX7VZwP");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565802266);
  }
}

TEST_F(v20190401_offline_json_Key768, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5049, "qQOCP2SLItewclXXgo", "", 713080));
  expected.push_back(cryptolens::DataObject(5050, "rQT2ivH5OTtfiTzkcq", "", 723737));
  expected.push_back(cryptolens::DataObject(5051, "A4x3AAvt", "WKD8GhC4E1XFoe Kkn7Rk", 438017));

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

class v20190401_offline_compact_Key768 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo4MTksIktleSI6IkRLSFhKLVpMR1RNLU5UUUlULVJCUFRSIiwiQ3JlYXRlZCI6MTU2NTgwMjI2NiwiRXhwaXJlcyI6MzUzNDk0NDY2NiwiUGVyaW9kIjoyMjc5MCwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjpmYWxzZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6InVKS0lSMVZySTdQaCIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MTAwLCJDdXN0b21lciI6eyJJZCI6Njc2NiwiTmFtZSI6IjUiLCJFbWFpbCI6Ikk3UURCYktrYXdYczdsS3Y2YlRYN1Zad1AiLCJDb21wYW55TmFtZSI6bnVsbCwiQ3JlYXRlZCI6MTU2NTgwMjI2Nn0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE5OTd9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjozLCJBbGxvd2VkTWFjaGluZXMiOiJvck91SWVyMzQwWTNuR0oiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUwNDksIk5hbWUiOiJxUU9DUDJTTEl0ZXdjbFhYZ28iLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo3MTMwODB9LHsiSWQiOjUwNTAsIk5hbWUiOiJyUVQyaXZINU9UdGZpVHprY3EiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo3MjM3Mzd9LHsiSWQiOjUwNTEsIk5hbWUiOiJBNHgzQUF2dCIsIlN0cmluZ1ZhbHVlIjoiV0tEOEdoQzRFMVhGb2UgS2tuN1JrIiwiSW50VmFsdWUiOjQzODAxN31dLCJTaWduRGF0ZSI6MTU3MDQ2MTIzMH0=";
    saved_response += "-";
    saved_response += "jlQdcWI8Won6sDMMEdzgiWrngr5qJCkGHRABec9W2RPN/Fumx5ADYXR00f6HyKek/LJSbmO5VfBl2Z8dTjSjjGwpVFsUlXLxjnRH4A/HWXl/I0v5b5mGUty5NcW8Pqdu/SiQWSRWysM7xcDaOZsWocZTqMqS7R1gwPv+tkFRkkS3PGsq2LkmvDY6p0KRi3EjaMqHOQSy6C2I2uOwZjH//+Rhjz5hkDoY0KFsDr9YjGSdGZmbY16hnnzSII3c0oTzUTSrL7lWrrcqvzU7N+pXsXEgVnlmkMO1dMEmIMejfOXpwp1Tv9qqKgX0I4NNy62q4r0Hq/CiVUQs7aafnDLBZQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key768() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key768::license_key_;

TEST_F(v20190401_offline_compact_Key768, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802266);
  EXPECT_EQ(license_key->get_expires(), 3534944666);
  EXPECT_EQ(license_key->get_period(), 22790);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key768, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 819); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DKHXJ-ZLGTM-NTQIT-RBPTR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "uJKIR1VrI7Ph"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "orOuIer340Y3nGJ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55100); }
}

TEST_F(v20190401_offline_compact_Key768, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811997));

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

TEST_F(v20190401_offline_compact_Key768, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6766);
    EXPECT_EQ(customer.get_name(), "5");
    EXPECT_EQ(customer.get_email(), "I7QDBbKkawXs7lKv6bTX7VZwP");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565802266);
  }
}

TEST_F(v20190401_offline_compact_Key768, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5049, "qQOCP2SLItewclXXgo", "", 713080));
  expected.push_back(cryptolens::DataObject(5050, "rQT2ivH5OTtfiTzkcq", "", 723737));
  expected.push_back(cryptolens::DataObject(5051, "A4x3AAvt", "WKD8GhC4E1XFoe Kkn7Rk", 438017));

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
