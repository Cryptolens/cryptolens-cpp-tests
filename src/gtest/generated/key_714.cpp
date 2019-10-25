#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key714 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "LKPVV-YRZJN-PRAET-ZUPIB", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key714() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key714::license_key_;

TEST_F(v20180502_online_Key714, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802146);
  EXPECT_EQ(license_key->get_expires(), 3827936759);
  EXPECT_EQ(license_key->get_period(), 26182);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key714, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 765); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LKPVV-YRZJN-PRAET-ZUPIB"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "R93LDiw6MftGGsMaNimpgCuDF"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }
}

TEST_F(v20180502_online_Key714, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811959));

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

TEST_F(v20180502_online_Key714, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6738);
    EXPECT_EQ(customer.get_name(), "1RdukNumbXGL CIaUBdj");
    EXPECT_EQ(customer.get_email(), "xeOWsLpAOkmUjZoP50");
    EXPECT_EQ(customer.get_company_name(), "qj1FwCpcnZH");
    EXPECT_EQ(customer.get_created(), 1565802145);
  }
}

TEST_F(v20180502_online_Key714, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4966, "g 1jhhXR", "", 421264));
  expected.push_back(cryptolens::DataObject(4967, "nRVBErDB RQMcvgmPVxzby", "JXFFAzqmdPMwUsqFyuXs8l9", 443435));
  expected.push_back(cryptolens::DataObject(4968, "Q2W", "", 301024));

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

class v20190401_online_Key714 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "LKPVV-YRZJN-PRAET-ZUPIB");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key714() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key714::license_key_;

TEST_F(v20190401_online_Key714, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802146);
  EXPECT_EQ(license_key->get_expires(), 3827936759);
  EXPECT_EQ(license_key->get_period(), 26182);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key714, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 765); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LKPVV-YRZJN-PRAET-ZUPIB"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "R93LDiw6MftGGsMaNimpgCuDF"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }
}

TEST_F(v20190401_online_Key714, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811959));

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

TEST_F(v20190401_online_Key714, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6738);
    EXPECT_EQ(customer.get_name(), "1RdukNumbXGL CIaUBdj");
    EXPECT_EQ(customer.get_email(), "xeOWsLpAOkmUjZoP50");
    EXPECT_EQ(customer.get_company_name(), "qj1FwCpcnZH");
    EXPECT_EQ(customer.get_created(), 1565802145);
  }
}

TEST_F(v20190401_online_Key714, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4966, "g 1jhhXR", "", 421264));
  expected.push_back(cryptolens::DataObject(4967, "nRVBErDB RQMcvgmPVxzby", "JXFFAzqmdPMwUsqFyuXs8l9", 443435));
  expected.push_back(cryptolens::DataObject(4968, "Q2W", "", 301024));

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

class v20190401_offline_json_Key714 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NjUsIktleSI6IkxLUFZWLVlSWkpOLVBSQUVULVpVUElCIiwiQ3JlYXRlZCI6MTU2NTgwMjE0NiwiRXhwaXJlcyI6MzgyNzkzNjc1OSwiUGVyaW9kIjoyNjE4MiwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTA0NiwiQ3VzdG9tZXIiOnsiSWQiOjY3MzgsIk5hbWUiOiIxUmR1a051bWJYR0wgQ0lhVUJkaiIsIkVtYWlsIjoieGVPV3NMcEFPa21ValpvUDUwIiwiQ29tcGFueU5hbWUiOiJxajFGd0NwY25aSCIsIkNyZWF0ZWQiOjE1NjU4MDIxNDV9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExOTU5fV0sIlRyaWFsQWN0aXZhdGlvbiI6dHJ1ZSwiTWF4Tm9PZk1hY2hpbmVzIjo0LCJBbGxvd2VkTWFjaGluZXMiOiJSOTNMRGl3Nk1mdEdHc01hTmltcGdDdURGIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0OTY2LCJOYW1lIjoiZyAxamhoWFIiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo0MjEyNjR9LHsiSWQiOjQ5NjcsIk5hbWUiOiJuUlZCRXJEQiBSUU1jdmdtUFZ4emJ5IiwiU3RyaW5nVmFsdWUiOiJKWEZGQXpxbWRQTXdVc3FGeXVYczhsOSIsIkludFZhbHVlIjo0NDM0MzV9LHsiSWQiOjQ5NjgsIk5hbWUiOiJRMlciLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjozMDEwMjR9XSwiU2lnbkRhdGUiOjE1NzA0NjExOTl9\",\"signature\":\"bZO2WjxELMuRN1S1ACH+HuLoHIi5cfNpztPIIGHdFbHDkVNnfQk0sO5qVac3JZ4I+72XxV08CvYTdqwCR+EtI9slIAYQDP+CsixxCUWl4SF/DBldwGAEnSx3n0IBxu+xMleMFmxtwSLrCoXy9ItJ7QEKcm/fM9MuAd9NAyyC/9BlA6sgRBHLl8IekksxwYYcrMhj0KarjomYzpWsuZQtiYA4rSzqtA73pYi2QGuLie7ECx3RJGBPWDIKZE3w4/+e5Oh7bREWlR4P3d5Aig+kfwN9fUtf2pZDhFmfdyaS1lz8lNqt9iwpLYh4rVXslKTp9Xjf9pb4yJ3l2zz5MLZ/8w==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key714() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key714::license_key_;

TEST_F(v20190401_offline_json_Key714, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802146);
  EXPECT_EQ(license_key->get_expires(), 3827936759);
  EXPECT_EQ(license_key->get_period(), 26182);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key714, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 765); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LKPVV-YRZJN-PRAET-ZUPIB"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "R93LDiw6MftGGsMaNimpgCuDF"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }
}

TEST_F(v20190401_offline_json_Key714, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811959));

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

TEST_F(v20190401_offline_json_Key714, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6738);
    EXPECT_EQ(customer.get_name(), "1RdukNumbXGL CIaUBdj");
    EXPECT_EQ(customer.get_email(), "xeOWsLpAOkmUjZoP50");
    EXPECT_EQ(customer.get_company_name(), "qj1FwCpcnZH");
    EXPECT_EQ(customer.get_created(), 1565802145);
  }
}

TEST_F(v20190401_offline_json_Key714, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4966, "g 1jhhXR", "", 421264));
  expected.push_back(cryptolens::DataObject(4967, "nRVBErDB RQMcvgmPVxzby", "JXFFAzqmdPMwUsqFyuXs8l9", 443435));
  expected.push_back(cryptolens::DataObject(4968, "Q2W", "", 301024));

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

class v20190401_offline_compact_Key714 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NjUsIktleSI6IkxLUFZWLVlSWkpOLVBSQUVULVpVUElCIiwiQ3JlYXRlZCI6MTU2NTgwMjE0NiwiRXhwaXJlcyI6MzgyNzkzNjc1OSwiUGVyaW9kIjoyNjE4MiwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTA0NiwiQ3VzdG9tZXIiOnsiSWQiOjY3MzgsIk5hbWUiOiIxUmR1a051bWJYR0wgQ0lhVUJkaiIsIkVtYWlsIjoieGVPV3NMcEFPa21ValpvUDUwIiwiQ29tcGFueU5hbWUiOiJxajFGd0NwY25aSCIsIkNyZWF0ZWQiOjE1NjU4MDIxNDV9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODExOTU5fV0sIlRyaWFsQWN0aXZhdGlvbiI6dHJ1ZSwiTWF4Tm9PZk1hY2hpbmVzIjo0LCJBbGxvd2VkTWFjaGluZXMiOiJSOTNMRGl3Nk1mdEdHc01hTmltcGdDdURGIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0OTY2LCJOYW1lIjoiZyAxamhoWFIiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo0MjEyNjR9LHsiSWQiOjQ5NjcsIk5hbWUiOiJuUlZCRXJEQiBSUU1jdmdtUFZ4emJ5IiwiU3RyaW5nVmFsdWUiOiJKWEZGQXpxbWRQTXdVc3FGeXVYczhsOSIsIkludFZhbHVlIjo0NDM0MzV9LHsiSWQiOjQ5NjgsIk5hbWUiOiJRMlciLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjozMDEwMjR9XSwiU2lnbkRhdGUiOjE1NzA0NjExOTl9";
    saved_response += "-";
    saved_response += "bZO2WjxELMuRN1S1ACH+HuLoHIi5cfNpztPIIGHdFbHDkVNnfQk0sO5qVac3JZ4I+72XxV08CvYTdqwCR+EtI9slIAYQDP+CsixxCUWl4SF/DBldwGAEnSx3n0IBxu+xMleMFmxtwSLrCoXy9ItJ7QEKcm/fM9MuAd9NAyyC/9BlA6sgRBHLl8IekksxwYYcrMhj0KarjomYzpWsuZQtiYA4rSzqtA73pYi2QGuLie7ECx3RJGBPWDIKZE3w4/+e5Oh7bREWlR4P3d5Aig+kfwN9fUtf2pZDhFmfdyaS1lz8lNqt9iwpLYh4rVXslKTp9Xjf9pb4yJ3l2zz5MLZ/8w==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key714() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key714::license_key_;

TEST_F(v20190401_offline_compact_Key714, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802146);
  EXPECT_EQ(license_key->get_expires(), 3827936759);
  EXPECT_EQ(license_key->get_period(), 26182);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key714, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 765); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "LKPVV-YRZJN-PRAET-ZUPIB"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "R93LDiw6MftGGsMaNimpgCuDF"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55046); }
}

TEST_F(v20190401_offline_compact_Key714, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811959));

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

TEST_F(v20190401_offline_compact_Key714, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6738);
    EXPECT_EQ(customer.get_name(), "1RdukNumbXGL CIaUBdj");
    EXPECT_EQ(customer.get_email(), "xeOWsLpAOkmUjZoP50");
    EXPECT_EQ(customer.get_company_name(), "qj1FwCpcnZH");
    EXPECT_EQ(customer.get_created(), 1565802145);
  }
}

TEST_F(v20190401_offline_compact_Key714, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4966, "g 1jhhXR", "", 421264));
  expected.push_back(cryptolens::DataObject(4967, "nRVBErDB RQMcvgmPVxzby", "JXFFAzqmdPMwUsqFyuXs8l9", 443435));
  expected.push_back(cryptolens::DataObject(4968, "Q2W", "", 301024));

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
