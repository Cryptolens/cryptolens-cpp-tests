#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key558 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "EMKNS-DGVFH-TJRII-UILDH", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key558() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key558::license_key_;

TEST_F(v20180502_online_Key558, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801819);
  EXPECT_EQ(license_key->get_expires(), 4386339852);
  EXPECT_EQ(license_key->get_period(), 32645);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key558, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 609); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EMKNS-DGVFH-TJRII-UILDH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Qq5VEiVGxS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "EepL0gdzBa0pE6FWK\n5Juyn7jBZ6ZCuQgl2Ch1YF\nC lf5FEQx"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }
}

TEST_F(v20180502_online_Key558, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811852));

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

TEST_F(v20180502_online_Key558, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6657);
    EXPECT_EQ(customer.get_name(), "ifedC9oQq");
    EXPECT_EQ(customer.get_email(), "nUEpU1ewQAiLvg LQeWu0Ki4L");
    EXPECT_EQ(customer.get_company_name(), "vtuFUZjoPUg7Pnhx eV");
    EXPECT_EQ(customer.get_created(), 1565801819);
  }
}

TEST_F(v20180502_online_Key558, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4735, "BxHNcuOy9wKC4YoeX9YlYuW", "FSJqsqQGIFBQTB", 919391));
  expected.push_back(cryptolens::DataObject(4736, "iP", "RIArSMwffX4G9DHcuP8D", 602136));
  expected.push_back(cryptolens::DataObject(4737, "V94aPD9mT", "sKSyJXBfnkXifeteY1BS", 440455));

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

class v20190401_online_Key558 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "EMKNS-DGVFH-TJRII-UILDH");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key558() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key558::license_key_;

TEST_F(v20190401_online_Key558, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801819);
  EXPECT_EQ(license_key->get_expires(), 4386339852);
  EXPECT_EQ(license_key->get_period(), 32645);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key558, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 609); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EMKNS-DGVFH-TJRII-UILDH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Qq5VEiVGxS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "EepL0gdzBa0pE6FWK\n5Juyn7jBZ6ZCuQgl2Ch1YF\nC lf5FEQx"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }
}

TEST_F(v20190401_online_Key558, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811852));

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

TEST_F(v20190401_online_Key558, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6657);
    EXPECT_EQ(customer.get_name(), "ifedC9oQq");
    EXPECT_EQ(customer.get_email(), "nUEpU1ewQAiLvg LQeWu0Ki4L");
    EXPECT_EQ(customer.get_company_name(), "vtuFUZjoPUg7Pnhx eV");
    EXPECT_EQ(customer.get_created(), 1565801819);
  }
}

TEST_F(v20190401_online_Key558, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4735, "BxHNcuOy9wKC4YoeX9YlYuW", "FSJqsqQGIFBQTB", 919391));
  expected.push_back(cryptolens::DataObject(4736, "iP", "RIArSMwffX4G9DHcuP8D", 602136));
  expected.push_back(cryptolens::DataObject(4737, "V94aPD9mT", "sKSyJXBfnkXifeteY1BS", 440455));

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

class v20190401_offline_json_Key558 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2MDksIktleSI6IkVNS05TLURHVkZILVRKUklJLVVJTERIIiwiQ3JlYXRlZCI6MTU2NTgwMTgxOSwiRXhwaXJlcyI6NDM4NjMzOTg1MiwiUGVyaW9kIjozMjY0NSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0Ijp0cnVlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJRcTVWRWlWR3hTIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTQ4OTAsIkN1c3RvbWVyIjp7IklkIjo2NjU3LCJOYW1lIjoiaWZlZEM5b1FxIiwiRW1haWwiOiJuVUVwVTFld1FBaUx2ZyBMUWVXdTBLaTRMIiwiQ29tcGFueU5hbWUiOiJ2dHVGVVpqb1BVZzdQbmh4IGVWIiwiQ3JlYXRlZCI6MTU2NTgwMTgxOX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4NTJ9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6IkVlcEwwZ2R6QmEwcEU2RldLXG41SnV5bjdqQlo2WkN1UWdsMkNoMVlGXG5DIGxmNUZFUXgiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQ3MzUsIk5hbWUiOiJCeEhOY3VPeTl3S0M0WW9lWDlZbFl1VyIsIlN0cmluZ1ZhbHVlIjoiRlNKcXNxUUdJRkJRVEIiLCJJbnRWYWx1ZSI6OTE5MzkxfSx7IklkIjo0NzM2LCJOYW1lIjoiaVAiLCJTdHJpbmdWYWx1ZSI6IlJJQXJTTXdmZlg0RzlESGN1UDhEIiwiSW50VmFsdWUiOjYwMjEzNn0seyJJZCI6NDczNywiTmFtZSI6IlY5NGFQRDltVCIsIlN0cmluZ1ZhbHVlIjoic0tTeUpYQmZua1hpZmV0ZVkxQlMiLCJJbnRWYWx1ZSI6NDQwNDU1fV0sIlNpZ25EYXRlIjoxNTcwNDYxMTA5fQ==\",\"signature\":\"coZXcnMnptmN7nlZfcZFPXEqEf3RQqBL3MbEF+91vEYGMghqF2ilsvzxr9GcBTxX538zvkh3aGGaGS17HvC2F5IdC7lr5RuurtPJzcMZpDvMjyCWcHmI1YxAMTOcNrHP46daNKRRtr3Y1hL6+ciyF0Q3T2fkAQtaLtBad+6l70iwMynscwX4/7L6hod/ajFI/h4hbSvEE49JGqBPk5wUBAyWBCJdRNYK1AyCmZWhOimPDL599sPyJYDyFHpg37fOb8TkXnCZeeZ+EYHpXgW5PgC0W5FIp18I9LFXCs+MlghyaW+9sB5Msz+zhxY+h9H6ng6+QMlc+L4umxDBkklKXA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key558() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key558::license_key_;

TEST_F(v20190401_offline_json_Key558, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801819);
  EXPECT_EQ(license_key->get_expires(), 4386339852);
  EXPECT_EQ(license_key->get_period(), 32645);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key558, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 609); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EMKNS-DGVFH-TJRII-UILDH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Qq5VEiVGxS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "EepL0gdzBa0pE6FWK\n5Juyn7jBZ6ZCuQgl2Ch1YF\nC lf5FEQx"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }
}

TEST_F(v20190401_offline_json_Key558, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811852));

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

TEST_F(v20190401_offline_json_Key558, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6657);
    EXPECT_EQ(customer.get_name(), "ifedC9oQq");
    EXPECT_EQ(customer.get_email(), "nUEpU1ewQAiLvg LQeWu0Ki4L");
    EXPECT_EQ(customer.get_company_name(), "vtuFUZjoPUg7Pnhx eV");
    EXPECT_EQ(customer.get_created(), 1565801819);
  }
}

TEST_F(v20190401_offline_json_Key558, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4735, "BxHNcuOy9wKC4YoeX9YlYuW", "FSJqsqQGIFBQTB", 919391));
  expected.push_back(cryptolens::DataObject(4736, "iP", "RIArSMwffX4G9DHcuP8D", 602136));
  expected.push_back(cryptolens::DataObject(4737, "V94aPD9mT", "sKSyJXBfnkXifeteY1BS", 440455));

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

class v20190401_offline_compact_Key558 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2MDksIktleSI6IkVNS05TLURHVkZILVRKUklJLVVJTERIIiwiQ3JlYXRlZCI6MTU2NTgwMTgxOSwiRXhwaXJlcyI6NDM4NjMzOTg1MiwiUGVyaW9kIjozMjY0NSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0Ijp0cnVlLCJGNSI6ZmFsc2UsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJRcTVWRWlWR3hTIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTQ4OTAsIkN1c3RvbWVyIjp7IklkIjo2NjU3LCJOYW1lIjoiaWZlZEM5b1FxIiwiRW1haWwiOiJuVUVwVTFld1FBaUx2ZyBMUWVXdTBLaTRMIiwiQ29tcGFueU5hbWUiOiJ2dHVGVVpqb1BVZzdQbmh4IGVWIiwiQ3JlYXRlZCI6MTU2NTgwMTgxOX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4NTJ9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6IkVlcEwwZ2R6QmEwcEU2RldLXG41SnV5bjdqQlo2WkN1UWdsMkNoMVlGXG5DIGxmNUZFUXgiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQ3MzUsIk5hbWUiOiJCeEhOY3VPeTl3S0M0WW9lWDlZbFl1VyIsIlN0cmluZ1ZhbHVlIjoiRlNKcXNxUUdJRkJRVEIiLCJJbnRWYWx1ZSI6OTE5MzkxfSx7IklkIjo0NzM2LCJOYW1lIjoiaVAiLCJTdHJpbmdWYWx1ZSI6IlJJQXJTTXdmZlg0RzlESGN1UDhEIiwiSW50VmFsdWUiOjYwMjEzNn0seyJJZCI6NDczNywiTmFtZSI6IlY5NGFQRDltVCIsIlN0cmluZ1ZhbHVlIjoic0tTeUpYQmZua1hpZmV0ZVkxQlMiLCJJbnRWYWx1ZSI6NDQwNDU1fV0sIlNpZ25EYXRlIjoxNTcwNDYxMTA5fQ==";
    saved_response += "-";
    saved_response += "coZXcnMnptmN7nlZfcZFPXEqEf3RQqBL3MbEF+91vEYGMghqF2ilsvzxr9GcBTxX538zvkh3aGGaGS17HvC2F5IdC7lr5RuurtPJzcMZpDvMjyCWcHmI1YxAMTOcNrHP46daNKRRtr3Y1hL6+ciyF0Q3T2fkAQtaLtBad+6l70iwMynscwX4/7L6hod/ajFI/h4hbSvEE49JGqBPk5wUBAyWBCJdRNYK1AyCmZWhOimPDL599sPyJYDyFHpg37fOb8TkXnCZeeZ+EYHpXgW5PgC0W5FIp18I9LFXCs+MlghyaW+9sB5Msz+zhxY+h9H6ng6+QMlc+L4umxDBkklKXA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key558() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key558::license_key_;

TEST_F(v20190401_offline_compact_Key558, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801819);
  EXPECT_EQ(license_key->get_expires(), 4386339852);
  EXPECT_EQ(license_key->get_period(), 32645);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key558, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 609); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EMKNS-DGVFH-TJRII-UILDH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Qq5VEiVGxS"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "EepL0gdzBa0pE6FWK\n5Juyn7jBZ6ZCuQgl2Ch1YF\nC lf5FEQx"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54890); }
}

TEST_F(v20190401_offline_compact_Key558, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811852));

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

TEST_F(v20190401_offline_compact_Key558, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6657);
    EXPECT_EQ(customer.get_name(), "ifedC9oQq");
    EXPECT_EQ(customer.get_email(), "nUEpU1ewQAiLvg LQeWu0Ki4L");
    EXPECT_EQ(customer.get_company_name(), "vtuFUZjoPUg7Pnhx eV");
    EXPECT_EQ(customer.get_created(), 1565801819);
  }
}

TEST_F(v20190401_offline_compact_Key558, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4735, "BxHNcuOy9wKC4YoeX9YlYuW", "FSJqsqQGIFBQTB", 919391));
  expected.push_back(cryptolens::DataObject(4736, "iP", "RIArSMwffX4G9DHcuP8D", 602136));
  expected.push_back(cryptolens::DataObject(4737, "V94aPD9mT", "sKSyJXBfnkXifeteY1BS", 440455));

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
