#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key720 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "LZEHA-KZMWX-OJZNK-JOPQH", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key720() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key720::license_key_;

TEST_F(v20180502_online_Key720, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802160);
  EXPECT_EQ(license_key->get_expires(), 4645270961);
  EXPECT_EQ(license_key->get_period(), 35642);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key720, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 771); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LZEHA-KZMWX-OJZNK-JOPQH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "6"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "7kh9uiizyStbTGUvcEd6\nCc7pbS\nzYoZfcwlsAJKT67MB4B"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }
}

TEST_F(v20180502_online_Key720, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811963));

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

TEST_F(v20180502_online_Key720, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6742);
    EXPECT_EQ(customer.get_name(), "7J90Ii597Z5GPWA4eOs1Db");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "zecaujRCLLnqVvRKfj8WTdeJ");
    EXPECT_EQ(customer.get_created(), 1565802160);
  }
}

TEST_F(v20180502_online_Key720, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4976, "SweaDezXUzoZx2On1A5KetFiY", "o CIC2W284P6", 52766));
  expected.push_back(cryptolens::DataObject(4977, "MBtp", "xD1q4iJg0L", 695688));

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

class v20190401_online_Key720 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "LZEHA-KZMWX-OJZNK-JOPQH");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key720() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key720::license_key_;

TEST_F(v20190401_online_Key720, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802160);
  EXPECT_EQ(license_key->get_expires(), 4645270961);
  EXPECT_EQ(license_key->get_period(), 35642);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key720, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 771); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LZEHA-KZMWX-OJZNK-JOPQH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "6"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "7kh9uiizyStbTGUvcEd6\nCc7pbS\nzYoZfcwlsAJKT67MB4B"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }
}

TEST_F(v20190401_online_Key720, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811963));

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

TEST_F(v20190401_online_Key720, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6742);
    EXPECT_EQ(customer.get_name(), "7J90Ii597Z5GPWA4eOs1Db");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "zecaujRCLLnqVvRKfj8WTdeJ");
    EXPECT_EQ(customer.get_created(), 1565802160);
  }
}

TEST_F(v20190401_online_Key720, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4976, "SweaDezXUzoZx2On1A5KetFiY", "o CIC2W284P6", 52766));
  expected.push_back(cryptolens::DataObject(4977, "MBtp", "xD1q4iJg0L", 695688));

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

class v20190401_offline_json_Key720 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NzEsIktleSI6IkxaRUhBLUtaTVdYLU9KWk5LLUpPUFFIIiwiQ3JlYXRlZCI6MTU2NTgwMjE2MCwiRXhwaXJlcyI6NDY0NTI3MDk2MSwiUGVyaW9kIjozNTY0MiwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjp0cnVlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiI2IiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUwNTIsIkN1c3RvbWVyIjp7IklkIjo2NzQyLCJOYW1lIjoiN0o5MElpNTk3WjVHUFdBNGVPczFEYiIsIkVtYWlsIjpudWxsLCJDb21wYW55TmFtZSI6InplY2F1alJDTExucVZ2UktmajhXVGRlSiIsIkNyZWF0ZWQiOjE1NjU4MDIxNjB9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExOTYzfV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiN2toOXVpaXp5U3RiVEdVdmNFZDZcbkNjN3BiU1xuellvWmZjd2xzQUpLVDY3TUI0QiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDk3NiwiTmFtZSI6IlN3ZWFEZXpYVXpvWngyT24xQTVLZXRGaVkiLCJTdHJpbmdWYWx1ZSI6Im8gQ0lDMlcyODRQNiIsIkludFZhbHVlIjo1Mjc2Nn0seyJJZCI6NDk3NywiTmFtZSI6Ik1CdHAiLCJTdHJpbmdWYWx1ZSI6InhEMXE0aUpnMEwiLCJJbnRWYWx1ZSI6Njk1Njg4fV0sIlNpZ25EYXRlIjoxNTcwNDYxMjAyfQ==\",\"signature\":\"into0HAXGZYmNsNdWT1ZkGCrd1574Z/QmjshEcsN14rqBI0YJCaIr4agS7rPodZo5SLfeds775qbnBHZv5tf1g6Zg8TULx2lDdRHf/kAqCv0d7NUTP+mV7mEsXM1iDq92oATFQntdZIt9+QpQfCagn7KuV497+SIxgMtYxqxRzjYxxlIFKaOcc0UbPIm8jsgOEMeMSy+JkkGqFz/Y32l1KoSjiJrC2fDHwaRxy0gIG+htmzVbfmtY8EsTix8+hkke4Hrl5qqvuhILsbUrhBgzTu1WXaCyxJ9Qi3igZnUpcUAirmF5OG9TYJp1yoJJPdX8nOnb6L6zEzyoapxsliHjw==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key720() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key720::license_key_;

TEST_F(v20190401_offline_json_Key720, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802160);
  EXPECT_EQ(license_key->get_expires(), 4645270961);
  EXPECT_EQ(license_key->get_period(), 35642);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key720, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 771); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LZEHA-KZMWX-OJZNK-JOPQH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "6"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "7kh9uiizyStbTGUvcEd6\nCc7pbS\nzYoZfcwlsAJKT67MB4B"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }
}

TEST_F(v20190401_offline_json_Key720, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811963));

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

TEST_F(v20190401_offline_json_Key720, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6742);
    EXPECT_EQ(customer.get_name(), "7J90Ii597Z5GPWA4eOs1Db");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "zecaujRCLLnqVvRKfj8WTdeJ");
    EXPECT_EQ(customer.get_created(), 1565802160);
  }
}

TEST_F(v20190401_offline_json_Key720, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4976, "SweaDezXUzoZx2On1A5KetFiY", "o CIC2W284P6", 52766));
  expected.push_back(cryptolens::DataObject(4977, "MBtp", "xD1q4iJg0L", 695688));

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

class v20190401_offline_compact_Key720 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NzEsIktleSI6IkxaRUhBLUtaTVdYLU9KWk5LLUpPUFFIIiwiQ3JlYXRlZCI6MTU2NTgwMjE2MCwiRXhwaXJlcyI6NDY0NTI3MDk2MSwiUGVyaW9kIjozNTY0MiwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjp0cnVlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiI2IiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUwNTIsIkN1c3RvbWVyIjp7IklkIjo2NzQyLCJOYW1lIjoiN0o5MElpNTk3WjVHUFdBNGVPczFEYiIsIkVtYWlsIjpudWxsLCJDb21wYW55TmFtZSI6InplY2F1alJDTExucVZ2UktmajhXVGRlSiIsIkNyZWF0ZWQiOjE1NjU4MDIxNjB9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExOTYzfV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiN2toOXVpaXp5U3RiVEdVdmNFZDZcbkNjN3BiU1xuellvWmZjd2xzQUpLVDY3TUI0QiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDk3NiwiTmFtZSI6IlN3ZWFEZXpYVXpvWngyT24xQTVLZXRGaVkiLCJTdHJpbmdWYWx1ZSI6Im8gQ0lDMlcyODRQNiIsIkludFZhbHVlIjo1Mjc2Nn0seyJJZCI6NDk3NywiTmFtZSI6Ik1CdHAiLCJTdHJpbmdWYWx1ZSI6InhEMXE0aUpnMEwiLCJJbnRWYWx1ZSI6Njk1Njg4fV0sIlNpZ25EYXRlIjoxNTcwNDYxMjAyfQ==";
    saved_response += "-";
    saved_response += "into0HAXGZYmNsNdWT1ZkGCrd1574Z/QmjshEcsN14rqBI0YJCaIr4agS7rPodZo5SLfeds775qbnBHZv5tf1g6Zg8TULx2lDdRHf/kAqCv0d7NUTP+mV7mEsXM1iDq92oATFQntdZIt9+QpQfCagn7KuV497+SIxgMtYxqxRzjYxxlIFKaOcc0UbPIm8jsgOEMeMSy+JkkGqFz/Y32l1KoSjiJrC2fDHwaRxy0gIG+htmzVbfmtY8EsTix8+hkke4Hrl5qqvuhILsbUrhBgzTu1WXaCyxJ9Qi3igZnUpcUAirmF5OG9TYJp1yoJJPdX8nOnb6L6zEzyoapxsliHjw==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key720() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key720::license_key_;

TEST_F(v20190401_offline_compact_Key720, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802160);
  EXPECT_EQ(license_key->get_expires(), 4645270961);
  EXPECT_EQ(license_key->get_period(), 35642);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key720, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 771); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LZEHA-KZMWX-OJZNK-JOPQH"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "6"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "7kh9uiizyStbTGUvcEd6\nCc7pbS\nzYoZfcwlsAJKT67MB4B"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55052); }
}

TEST_F(v20190401_offline_compact_Key720, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811963));

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

TEST_F(v20190401_offline_compact_Key720, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6742);
    EXPECT_EQ(customer.get_name(), "7J90Ii597Z5GPWA4eOs1Db");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "zecaujRCLLnqVvRKfj8WTdeJ");
    EXPECT_EQ(customer.get_created(), 1565802160);
  }
}

TEST_F(v20190401_offline_compact_Key720, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4976, "SweaDezXUzoZx2On1A5KetFiY", "o CIC2W284P6", 52766));
  expected.push_back(cryptolens::DataObject(4977, "MBtp", "xD1q4iJg0L", 695688));

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
