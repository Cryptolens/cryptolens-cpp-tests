#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key202 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "JWZOG-ELSHB-ZKHQR-MLFQR", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key202() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key202::license_key_;

TEST_F(v20180502_online_Key202, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801209);
  EXPECT_EQ(license_key->get_expires(), 4153654009);
  EXPECT_EQ(license_key->get_period(), 29951);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key202, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 253); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "JWZOG-ELSHB-ZKHQR-MLFQR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "ubL5imlIj1lOAVUgFjz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "41qFWwHhgc\nxj\ncZNHlvQThFNm293mm3oJ3sq"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }
}

TEST_F(v20180502_online_Key202, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811617));

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

TEST_F(v20180502_online_Key202, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6479);
    EXPECT_EQ(customer.get_name(), "6lc2 tk4e15yYsH2");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801209);
  }
}

TEST_F(v20180502_online_Key202, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4166, "0o69cMCXjOU4g1sWnLaLJ1IR0", "xVZqQ ZEaU", 902370));
  expected.push_back(cryptolens::DataObject(4167, "0kGyAD", "", 222953));

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

class v20190401_online_Key202 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "JWZOG-ELSHB-ZKHQR-MLFQR");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key202() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key202::license_key_;

TEST_F(v20190401_online_Key202, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801209);
  EXPECT_EQ(license_key->get_expires(), 4153654009);
  EXPECT_EQ(license_key->get_period(), 29951);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key202, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 253); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "JWZOG-ELSHB-ZKHQR-MLFQR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "ubL5imlIj1lOAVUgFjz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "41qFWwHhgc\nxj\ncZNHlvQThFNm293mm3oJ3sq"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }
}

TEST_F(v20190401_online_Key202, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811617));

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

TEST_F(v20190401_online_Key202, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6479);
    EXPECT_EQ(customer.get_name(), "6lc2 tk4e15yYsH2");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801209);
  }
}

TEST_F(v20190401_online_Key202, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4166, "0o69cMCXjOU4g1sWnLaLJ1IR0", "xVZqQ ZEaU", 902370));
  expected.push_back(cryptolens::DataObject(4167, "0kGyAD", "", 222953));

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

class v20190401_offline_json_Key202 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoyNTMsIktleSI6IkpXWk9HLUVMU0hCLVpLSFFSLU1MRlFSIiwiQ3JlYXRlZCI6MTU2NTgwMTIwOSwiRXhwaXJlcyI6NDE1MzY1NDAwOSwiUGVyaW9kIjoyOTk1MSwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6ZmFsc2UsIk5vdGVzIjoidWJMNWltbElqMWxPQVZVZ0ZqeiIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0NTMzLCJDdXN0b21lciI6eyJJZCI6NjQ3OSwiTmFtZSI6IjZsYzIgdGs0ZTE1eVlzSDIiLCJFbWFpbCI6bnVsbCwiQ29tcGFueU5hbWUiOm51bGwsIkNyZWF0ZWQiOjE1NjU4MDEyMDl9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExNjE3fV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MSwiQWxsb3dlZE1hY2hpbmVzIjoiNDFxRld3SGhnY1xueGpcbmNaTkhsdlFUaEZObTI5M21tM29KM3NxIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0MTY2LCJOYW1lIjoiMG82OWNNQ1hqT1U0ZzFzV25MYUxKMUlSMCIsIlN0cmluZ1ZhbHVlIjoieFZacVEgWkVhVSIsIkludFZhbHVlIjo5MDIzNzB9LHsiSWQiOjQxNjcsIk5hbWUiOiIwa0d5QUQiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjoyMjI5NTN9XSwiU2lnbkRhdGUiOjE1NzA0NjA5MjJ9\",\"signature\":\"Mz+8QLcwSrKidHxu75/flREOIjv1Oz+vhUa9foGkMg0jCTRYaxx7JULQPd7+iOK1t+CHOUzjKKXnJVt11f+Ibs6ZButTyTxS1kmICYKwAPGwTOyzkSWxoWT+AusXMQ5tCRwQT6/5i5Okq7EsJkJq8UmJUQxc4hkrCDdr1VtjRi6Z8eB1p/tibdMmBfl4SQ9bNNSIixBzVOltwiII2jbJ33RQ14kRUldtoZYmPyeY3E2EiedVUcz/jxIQBLqA7uBtOACjvKavWplQBtP6tcKivwZk4u92sS4aUTDlh45EX5JG0Xeh9yv68dao3bTi7xdKV96xGDQ5JgSLeXAlar6Skw==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key202() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key202::license_key_;

TEST_F(v20190401_offline_json_Key202, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801209);
  EXPECT_EQ(license_key->get_expires(), 4153654009);
  EXPECT_EQ(license_key->get_period(), 29951);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key202, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 253); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "JWZOG-ELSHB-ZKHQR-MLFQR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "ubL5imlIj1lOAVUgFjz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "41qFWwHhgc\nxj\ncZNHlvQThFNm293mm3oJ3sq"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }
}

TEST_F(v20190401_offline_json_Key202, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811617));

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

TEST_F(v20190401_offline_json_Key202, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6479);
    EXPECT_EQ(customer.get_name(), "6lc2 tk4e15yYsH2");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801209);
  }
}

TEST_F(v20190401_offline_json_Key202, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4166, "0o69cMCXjOU4g1sWnLaLJ1IR0", "xVZqQ ZEaU", 902370));
  expected.push_back(cryptolens::DataObject(4167, "0kGyAD", "", 222953));

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

class v20190401_offline_compact_Key202 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoyNTMsIktleSI6IkpXWk9HLUVMU0hCLVpLSFFSLU1MRlFSIiwiQ3JlYXRlZCI6MTU2NTgwMTIwOSwiRXhwaXJlcyI6NDE1MzY1NDAwOSwiUGVyaW9kIjoyOTk1MSwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6ZmFsc2UsIk5vdGVzIjoidWJMNWltbElqMWxPQVZVZ0ZqeiIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0NTMzLCJDdXN0b21lciI6eyJJZCI6NjQ3OSwiTmFtZSI6IjZsYzIgdGs0ZTE1eVlzSDIiLCJFbWFpbCI6bnVsbCwiQ29tcGFueU5hbWUiOm51bGwsIkNyZWF0ZWQiOjE1NjU4MDEyMDl9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExNjE3fV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MSwiQWxsb3dlZE1hY2hpbmVzIjoiNDFxRld3SGhnY1xueGpcbmNaTkhsdlFUaEZObTI5M21tM29KM3NxIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0MTY2LCJOYW1lIjoiMG82OWNNQ1hqT1U0ZzFzV25MYUxKMUlSMCIsIlN0cmluZ1ZhbHVlIjoieFZacVEgWkVhVSIsIkludFZhbHVlIjo5MDIzNzB9LHsiSWQiOjQxNjcsIk5hbWUiOiIwa0d5QUQiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjoyMjI5NTN9XSwiU2lnbkRhdGUiOjE1NzA0NjA5MjJ9";
    saved_response += "-";
    saved_response += "Mz+8QLcwSrKidHxu75/flREOIjv1Oz+vhUa9foGkMg0jCTRYaxx7JULQPd7+iOK1t+CHOUzjKKXnJVt11f+Ibs6ZButTyTxS1kmICYKwAPGwTOyzkSWxoWT+AusXMQ5tCRwQT6/5i5Okq7EsJkJq8UmJUQxc4hkrCDdr1VtjRi6Z8eB1p/tibdMmBfl4SQ9bNNSIixBzVOltwiII2jbJ33RQ14kRUldtoZYmPyeY3E2EiedVUcz/jxIQBLqA7uBtOACjvKavWplQBtP6tcKivwZk4u92sS4aUTDlh45EX5JG0Xeh9yv68dao3bTi7xdKV96xGDQ5JgSLeXAlar6Skw==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key202() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key202::license_key_;

TEST_F(v20190401_offline_compact_Key202, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801209);
  EXPECT_EQ(license_key->get_expires(), 4153654009);
  EXPECT_EQ(license_key->get_period(), 29951);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key202, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 253); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "JWZOG-ELSHB-ZKHQR-MLFQR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "ubL5imlIj1lOAVUgFjz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "41qFWwHhgc\nxj\ncZNHlvQThFNm293mm3oJ3sq"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54533); }
}

TEST_F(v20190401_offline_compact_Key202, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811617));

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

TEST_F(v20190401_offline_compact_Key202, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6479);
    EXPECT_EQ(customer.get_name(), "6lc2 tk4e15yYsH2");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "");
    EXPECT_EQ(customer.get_created(), 1565801209);
  }
}

TEST_F(v20190401_offline_compact_Key202, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4166, "0o69cMCXjOU4g1sWnLaLJ1IR0", "xVZqQ ZEaU", 902370));
  expected.push_back(cryptolens::DataObject(4167, "0kGyAD", "", 222953));

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
