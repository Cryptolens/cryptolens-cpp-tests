#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key495 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "EUNBH-YRQPG-CXZFI-AEBBE", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key495() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key495::license_key_;

TEST_F(v20180502_online_Key495, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801690);
  EXPECT_EQ(license_key->get_expires(), 3655050211);
  EXPECT_EQ(license_key->get_period(), 24181);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key495, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 546); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EUNBH-YRQPG-CXZFI-AEBBE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "4liUYN0RXI"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "ZgOt59BmZvk5f4uGtyLfsia"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }
}

TEST_F(v20180502_online_Key495, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811811));

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

TEST_F(v20180502_online_Key495, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6630);
    EXPECT_EQ(customer.get_name(), "IL4e");
    EXPECT_EQ(customer.get_email(), "K3J PT cYTV");
    EXPECT_EQ(customer.get_company_name(), "W1jjExoJTRhLqt");
    EXPECT_EQ(customer.get_created(), 1565801690);
  }
}

TEST_F(v20180502_online_Key495, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4638, "7zA k", "", 930636));

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

class v20190401_online_Key495 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "EUNBH-YRQPG-CXZFI-AEBBE");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key495() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key495::license_key_;

TEST_F(v20190401_online_Key495, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801690);
  EXPECT_EQ(license_key->get_expires(), 3655050211);
  EXPECT_EQ(license_key->get_period(), 24181);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key495, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 546); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EUNBH-YRQPG-CXZFI-AEBBE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "4liUYN0RXI"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "ZgOt59BmZvk5f4uGtyLfsia"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }
}

TEST_F(v20190401_online_Key495, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811811));

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

TEST_F(v20190401_online_Key495, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6630);
    EXPECT_EQ(customer.get_name(), "IL4e");
    EXPECT_EQ(customer.get_email(), "K3J PT cYTV");
    EXPECT_EQ(customer.get_company_name(), "W1jjExoJTRhLqt");
    EXPECT_EQ(customer.get_created(), 1565801690);
  }
}

TEST_F(v20190401_online_Key495, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4638, "7zA k", "", 930636));

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

class v20190401_offline_json_Key495 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1NDYsIktleSI6IkVVTkJILVlSUVBHLUNYWkZJLUFFQkJFIiwiQ3JlYXRlZCI6MTU2NTgwMTY5MCwiRXhwaXJlcyI6MzY1NTA1MDIxMSwiUGVyaW9kIjoyNDE4MSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0Ijp0cnVlLCJGNSI6dHJ1ZSwiRjYiOnRydWUsIkY3Ijp0cnVlLCJGOCI6ZmFsc2UsIk5vdGVzIjoiNGxpVVlOMFJYSSIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0ODI3LCJDdXN0b21lciI6eyJJZCI6NjYzMCwiTmFtZSI6IklMNGUiLCJFbWFpbCI6IkszSiBQVCBjWVRWIiwiQ29tcGFueU5hbWUiOiJXMWpqRXhvSlRSaExxdCIsIkNyZWF0ZWQiOjE1NjU4MDE2OTB9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExODExfV0sIlRyaWFsQWN0aXZhdGlvbiI6dHJ1ZSwiTWF4Tm9PZk1hY2hpbmVzIjo0LCJBbGxvd2VkTWFjaGluZXMiOiJaZ090NTlCbVp2azVmNHVHdHlMZnNpYSIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDYzOCwiTmFtZSI6Ijd6QSBrIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6OTMwNjM2fV0sIlNpZ25EYXRlIjoxNTcwNDYxMDc1fQ==\",\"signature\":\"hd5lUvh1mfqtQMPDYi9fsyUJ6ang20SBOGje7n2ERBDOAUh2iStmJOV6Kef9qqhMpy1JqyI4aw14nh7Sw9VD0GtWzu30rehRP1k4MFYBATVXd6x/wJAErGjgm7u0L8S3nZcfPfsdj7KfHBEd4PdDONQsI0okk3N9SzhFLhKrs5ojuRCsbta20soiwIBKBANpNIOuB/bDM0GZKiaiGTOsPC/SywmKcRVSYV0BDxUIppMeCpOouDOmePnY1WjeTJXC5xyZpybaIwL9+HP6KjT6EA3STGTgcGoWAXDYvyCxLYD9UducSN7B3un1kPEF1brHbpy47uzIiYfaAzf3Nm0nwQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key495() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key495::license_key_;

TEST_F(v20190401_offline_json_Key495, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801690);
  EXPECT_EQ(license_key->get_expires(), 3655050211);
  EXPECT_EQ(license_key->get_period(), 24181);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key495, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 546); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EUNBH-YRQPG-CXZFI-AEBBE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "4liUYN0RXI"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "ZgOt59BmZvk5f4uGtyLfsia"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }
}

TEST_F(v20190401_offline_json_Key495, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811811));

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

TEST_F(v20190401_offline_json_Key495, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6630);
    EXPECT_EQ(customer.get_name(), "IL4e");
    EXPECT_EQ(customer.get_email(), "K3J PT cYTV");
    EXPECT_EQ(customer.get_company_name(), "W1jjExoJTRhLqt");
    EXPECT_EQ(customer.get_created(), 1565801690);
  }
}

TEST_F(v20190401_offline_json_Key495, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4638, "7zA k", "", 930636));

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

class v20190401_offline_compact_Key495 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1NDYsIktleSI6IkVVTkJILVlSUVBHLUNYWkZJLUFFQkJFIiwiQ3JlYXRlZCI6MTU2NTgwMTY5MCwiRXhwaXJlcyI6MzY1NTA1MDIxMSwiUGVyaW9kIjoyNDE4MSwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0Ijp0cnVlLCJGNSI6dHJ1ZSwiRjYiOnRydWUsIkY3Ijp0cnVlLCJGOCI6ZmFsc2UsIk5vdGVzIjoiNGxpVVlOMFJYSSIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0ODI3LCJDdXN0b21lciI6eyJJZCI6NjYzMCwiTmFtZSI6IklMNGUiLCJFbWFpbCI6IkszSiBQVCBjWVRWIiwiQ29tcGFueU5hbWUiOiJXMWpqRXhvSlRSaExxdCIsIkNyZWF0ZWQiOjE1NjU4MDE2OTB9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExODExfV0sIlRyaWFsQWN0aXZhdGlvbiI6dHJ1ZSwiTWF4Tm9PZk1hY2hpbmVzIjo0LCJBbGxvd2VkTWFjaGluZXMiOiJaZ090NTlCbVp2azVmNHVHdHlMZnNpYSIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDYzOCwiTmFtZSI6Ijd6QSBrIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6OTMwNjM2fV0sIlNpZ25EYXRlIjoxNTcwNDYxMDc1fQ==";
    saved_response += "-";
    saved_response += "hd5lUvh1mfqtQMPDYi9fsyUJ6ang20SBOGje7n2ERBDOAUh2iStmJOV6Kef9qqhMpy1JqyI4aw14nh7Sw9VD0GtWzu30rehRP1k4MFYBATVXd6x/wJAErGjgm7u0L8S3nZcfPfsdj7KfHBEd4PdDONQsI0okk3N9SzhFLhKrs5ojuRCsbta20soiwIBKBANpNIOuB/bDM0GZKiaiGTOsPC/SywmKcRVSYV0BDxUIppMeCpOouDOmePnY1WjeTJXC5xyZpybaIwL9+HP6KjT6EA3STGTgcGoWAXDYvyCxLYD9UducSN7B3un1kPEF1brHbpy47uzIiYfaAzf3Nm0nwQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key495() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key495::license_key_;

TEST_F(v20190401_offline_compact_Key495, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801690);
  EXPECT_EQ(license_key->get_expires(), 3655050211);
  EXPECT_EQ(license_key->get_period(), 24181);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key495, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 546); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "EUNBH-YRQPG-CXZFI-AEBBE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "4liUYN0RXI"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "ZgOt59BmZvk5f4uGtyLfsia"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54827); }
}

TEST_F(v20190401_offline_compact_Key495, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811811));

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

TEST_F(v20190401_offline_compact_Key495, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6630);
    EXPECT_EQ(customer.get_name(), "IL4e");
    EXPECT_EQ(customer.get_email(), "K3J PT cYTV");
    EXPECT_EQ(customer.get_company_name(), "W1jjExoJTRhLqt");
    EXPECT_EQ(customer.get_created(), 1565801690);
  }
}

TEST_F(v20190401_offline_compact_Key495, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4638, "7zA k", "", 930636));

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
