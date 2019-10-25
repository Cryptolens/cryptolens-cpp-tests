#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key131 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "HNLRK-PNROX-VOSZB-LGVRI", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key131() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key131::license_key_;

TEST_F(v20180502_online_Key131, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801121);
  EXPECT_EQ(license_key->get_expires(), 4424863521);
  EXPECT_EQ(license_key->get_period(), 33090);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key131, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 182); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HNLRK-PNROX-VOSZB-LGVRI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "yjPfge6yU9tD5 CCgsPEJrs6P"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8eRjMy 0V\npIajqIthaJq LhWZj5 40nC\nas0YKrivIt3jYQUmeMlwS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }
}

TEST_F(v20180502_online_Key131, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811572));

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

TEST_F(v20180502_online_Key131, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6451);
    EXPECT_EQ(customer.get_name(), "xFU9tg");
    EXPECT_EQ(customer.get_email(), "eDTyAXrmKkAR3cbNLA");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801121);
  }
}

TEST_F(v20180502_online_Key131, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4060, "gIiU65udC4yGa", "", 538773));
  expected.push_back(cryptolens::DataObject(4061, "tRArNQMhUcXPH", "vE N9JcZUWck7OFUObrzo", 438237));
  expected.push_back(cryptolens::DataObject(4062, "RMjhVMszCGbHA7SE w", "", 321499));

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

class v20190401_online_Key131 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "HNLRK-PNROX-VOSZB-LGVRI");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key131() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key131::license_key_;

TEST_F(v20190401_online_Key131, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801121);
  EXPECT_EQ(license_key->get_expires(), 4424863521);
  EXPECT_EQ(license_key->get_period(), 33090);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key131, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 182); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HNLRK-PNROX-VOSZB-LGVRI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "yjPfge6yU9tD5 CCgsPEJrs6P"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8eRjMy 0V\npIajqIthaJq LhWZj5 40nC\nas0YKrivIt3jYQUmeMlwS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }
}

TEST_F(v20190401_online_Key131, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811572));

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

TEST_F(v20190401_online_Key131, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6451);
    EXPECT_EQ(customer.get_name(), "xFU9tg");
    EXPECT_EQ(customer.get_email(), "eDTyAXrmKkAR3cbNLA");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801121);
  }
}

TEST_F(v20190401_online_Key131, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4060, "gIiU65udC4yGa", "", 538773));
  expected.push_back(cryptolens::DataObject(4061, "tRArNQMhUcXPH", "vE N9JcZUWck7OFUObrzo", 438237));
  expected.push_back(cryptolens::DataObject(4062, "RMjhVMszCGbHA7SE w", "", 321499));

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

class v20190401_offline_json_Key131 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoxODIsIktleSI6IkhOTFJLLVBOUk9YLVZPU1pCLUxHVlJJIiwiQ3JlYXRlZCI6MTU2NTgwMTEyMSwiRXhwaXJlcyI6NDQyNDg2MzUyMSwiUGVyaW9kIjozMzA5MCwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjpmYWxzZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2Ijp0cnVlLCJGNyI6ZmFsc2UsIkY4IjpmYWxzZSwiTm90ZXMiOiJ5alBmZ2U2eVU5dEQ1IENDZ3NQRUpyczZQIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTQ0NjIsIkN1c3RvbWVyIjp7IklkIjo2NDUxLCJOYW1lIjoieEZVOXRnIiwiRW1haWwiOiJlRFR5QVhybUtrQVIzY2JOTEEiLCJDb21wYW55TmFtZSI6bnVsbCwiQ3JlYXRlZCI6MTU2NTgwMTEyMX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE1NzJ9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoyLCJBbGxvd2VkTWFjaGluZXMiOiI4ZVJqTXkgMFZcbnBJYWpxSXRoYUpxIExoV1pqNSA0MG5DXG5hczBZS3Jpdkl0M2pZUVVtZU1sd1MiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQwNjAsIk5hbWUiOiJnSWlVNjV1ZEM0eUdhIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NTM4NzczfSx7IklkIjo0MDYxLCJOYW1lIjoidFJBck5RTWhVY1hQSCIsIlN0cmluZ1ZhbHVlIjoidkUgTjlKY1pVV2NrN09GVU9icnpvIiwiSW50VmFsdWUiOjQzODIzN30seyJJZCI6NDA2MiwiTmFtZSI6IlJNamhWTXN6Q0diSEE3U0UgdyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjMyMTQ5OX1dLCJTaWduRGF0ZSI6MTU3MDQ2MDg4Nn0=\",\"signature\":\"MM0Rd6XuQl4w2TQouHFO388YVlvc7ufY/Iy9PEIkz+luleim6Z1/qVmV45MDxDQeNrTlkgNYn+IneyUok4JMKhE42FW9TDa7IDv4edT0ssMr5hfnLf+SjIbKJ6qUGJVR4YYQck5UM8sSiqmmCbUchNDQ4d6aBIaSJ2lqPpkh6P2GGScAEu7d+DRmXAI8Zxzk9UuSUGysgX8vGkGHi0znJI3svk2cuZc5HNm81SSUc5DsYknlVSszNTBiJNXmRjTNNLQja/+Q03nU7J6FFJrGLNc0RopxJ6P/HM5+1WDIe/8lAI9gOZdCUnnWbxOq59AofD5iMxXINbpJ1B6f01/0aQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key131() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key131::license_key_;

TEST_F(v20190401_offline_json_Key131, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801121);
  EXPECT_EQ(license_key->get_expires(), 4424863521);
  EXPECT_EQ(license_key->get_period(), 33090);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key131, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 182); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HNLRK-PNROX-VOSZB-LGVRI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "yjPfge6yU9tD5 CCgsPEJrs6P"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8eRjMy 0V\npIajqIthaJq LhWZj5 40nC\nas0YKrivIt3jYQUmeMlwS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }
}

TEST_F(v20190401_offline_json_Key131, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811572));

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

TEST_F(v20190401_offline_json_Key131, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6451);
    EXPECT_EQ(customer.get_name(), "xFU9tg");
    EXPECT_EQ(customer.get_email(), "eDTyAXrmKkAR3cbNLA");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801121);
  }
}

TEST_F(v20190401_offline_json_Key131, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4060, "gIiU65udC4yGa", "", 538773));
  expected.push_back(cryptolens::DataObject(4061, "tRArNQMhUcXPH", "vE N9JcZUWck7OFUObrzo", 438237));
  expected.push_back(cryptolens::DataObject(4062, "RMjhVMszCGbHA7SE w", "", 321499));

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

class v20190401_offline_compact_Key131 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoxODIsIktleSI6IkhOTFJLLVBOUk9YLVZPU1pCLUxHVlJJIiwiQ3JlYXRlZCI6MTU2NTgwMTEyMSwiRXhwaXJlcyI6NDQyNDg2MzUyMSwiUGVyaW9kIjozMzA5MCwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjpmYWxzZSwiRjQiOmZhbHNlLCJGNSI6ZmFsc2UsIkY2Ijp0cnVlLCJGNyI6ZmFsc2UsIkY4IjpmYWxzZSwiTm90ZXMiOiJ5alBmZ2U2eVU5dEQ1IENDZ3NQRUpyczZQIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTQ0NjIsIkN1c3RvbWVyIjp7IklkIjo2NDUxLCJOYW1lIjoieEZVOXRnIiwiRW1haWwiOiJlRFR5QVhybUtrQVIzY2JOTEEiLCJDb21wYW55TmFtZSI6bnVsbCwiQ3JlYXRlZCI6MTU2NTgwMTEyMX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE1NzJ9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoyLCJBbGxvd2VkTWFjaGluZXMiOiI4ZVJqTXkgMFZcbnBJYWpxSXRoYUpxIExoV1pqNSA0MG5DXG5hczBZS3Jpdkl0M2pZUVVtZU1sd1MiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQwNjAsIk5hbWUiOiJnSWlVNjV1ZEM0eUdhIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NTM4NzczfSx7IklkIjo0MDYxLCJOYW1lIjoidFJBck5RTWhVY1hQSCIsIlN0cmluZ1ZhbHVlIjoidkUgTjlKY1pVV2NrN09GVU9icnpvIiwiSW50VmFsdWUiOjQzODIzN30seyJJZCI6NDA2MiwiTmFtZSI6IlJNamhWTXN6Q0diSEE3U0UgdyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjMyMTQ5OX1dLCJTaWduRGF0ZSI6MTU3MDQ2MDg4Nn0=";
    saved_response += "-";
    saved_response += "MM0Rd6XuQl4w2TQouHFO388YVlvc7ufY/Iy9PEIkz+luleim6Z1/qVmV45MDxDQeNrTlkgNYn+IneyUok4JMKhE42FW9TDa7IDv4edT0ssMr5hfnLf+SjIbKJ6qUGJVR4YYQck5UM8sSiqmmCbUchNDQ4d6aBIaSJ2lqPpkh6P2GGScAEu7d+DRmXAI8Zxzk9UuSUGysgX8vGkGHi0znJI3svk2cuZc5HNm81SSUc5DsYknlVSszNTBiJNXmRjTNNLQja/+Q03nU7J6FFJrGLNc0RopxJ6P/HM5+1WDIe/8lAI9gOZdCUnnWbxOq59AofD5iMxXINbpJ1B6f01/0aQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key131() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key131::license_key_;

TEST_F(v20190401_offline_compact_Key131, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801121);
  EXPECT_EQ(license_key->get_expires(), 4424863521);
  EXPECT_EQ(license_key->get_period(), 33090);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key131, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 182); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HNLRK-PNROX-VOSZB-LGVRI"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "yjPfge6yU9tD5 CCgsPEJrs6P"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "8eRjMy 0V\npIajqIthaJq LhWZj5 40nC\nas0YKrivIt3jYQUmeMlwS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54462); }
}

TEST_F(v20190401_offline_compact_Key131, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811572));

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

TEST_F(v20190401_offline_compact_Key131, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6451);
    EXPECT_EQ(customer.get_name(), "xFU9tg");
    EXPECT_EQ(customer.get_email(), "eDTyAXrmKkAR3cbNLA");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801121);
  }
}

TEST_F(v20190401_offline_compact_Key131, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4060, "gIiU65udC4yGa", "", 538773));
  expected.push_back(cryptolens::DataObject(4061, "tRArNQMhUcXPH", "vE N9JcZUWck7OFUObrzo", 438237));
  expected.push_back(cryptolens::DataObject(4062, "RMjhVMszCGbHA7SE w", "", 321499));

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
