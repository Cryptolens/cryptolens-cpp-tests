#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key411 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "MEVJX-OOJAO-GUMJJ-SNDXE", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key411() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key411::license_key_;

TEST_F(v20180502_online_Key411, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801536);
  EXPECT_EQ(license_key->get_expires(), 3833023936);
  EXPECT_EQ(license_key->get_period(), 26240);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key411, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 462); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MEVJX-OOJAO-GUMJJ-SNDXE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Ht0"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "BF\nM33 EHayZ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }
}

TEST_F(v20180502_online_Key411, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811755));

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

TEST_F(v20180502_online_Key411, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6580);
    EXPECT_EQ(customer.get_name(), "meHnxDPJNO TjpyWDDRIM");
    EXPECT_EQ(customer.get_email(), "EV09ofuV3hcaWddpGmCiiV7 ");
    EXPECT_EQ(customer.get_company_name(), "xb8");
    EXPECT_EQ(customer.get_created(), 1565801536);
  }
}

TEST_F(v20180502_online_Key411, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4518, "H3co9a3gArXaDw6fa3s", "", 489111));
  expected.push_back(cryptolens::DataObject(4519, "j6n", "uyHJPah o0", 476735));

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

class v20190401_online_Key411 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "MEVJX-OOJAO-GUMJJ-SNDXE");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key411() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key411::license_key_;

TEST_F(v20190401_online_Key411, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801536);
  EXPECT_EQ(license_key->get_expires(), 3833023936);
  EXPECT_EQ(license_key->get_period(), 26240);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key411, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 462); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MEVJX-OOJAO-GUMJJ-SNDXE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Ht0"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "BF\nM33 EHayZ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }
}

TEST_F(v20190401_online_Key411, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811755));

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

TEST_F(v20190401_online_Key411, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6580);
    EXPECT_EQ(customer.get_name(), "meHnxDPJNO TjpyWDDRIM");
    EXPECT_EQ(customer.get_email(), "EV09ofuV3hcaWddpGmCiiV7 ");
    EXPECT_EQ(customer.get_company_name(), "xb8");
    EXPECT_EQ(customer.get_created(), 1565801536);
  }
}

TEST_F(v20190401_online_Key411, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4518, "H3co9a3gArXaDw6fa3s", "", 489111));
  expected.push_back(cryptolens::DataObject(4519, "j6n", "uyHJPah o0", 476735));

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

class v20190401_offline_json_Key411 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo0NjIsIktleSI6Ik1FVkpYLU9PSkFPLUdVTUpKLVNORFhFIiwiQ3JlYXRlZCI6MTU2NTgwMTUzNiwiRXhwaXJlcyI6MzgzMzAyMzkzNiwiUGVyaW9kIjoyNjI0MCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6dHJ1ZSwiRjciOnRydWUsIkY4IjpmYWxzZSwiTm90ZXMiOiJIdDAiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDc0MywiQ3VzdG9tZXIiOnsiSWQiOjY1ODAsIk5hbWUiOiJtZUhueERQSk5PIFRqcHlXRERSSU0iLCJFbWFpbCI6IkVWMDlvZnVWM2hjYVdkZHBHbUNpaVY3ICIsIkNvbXBhbnlOYW1lIjoieGI4IiwiQ3JlYXRlZCI6MTU2NTgwMTUzNn0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE3NTV9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxLCJBbGxvd2VkTWFjaGluZXMiOiJCRlxuTTMzIEVIYXlaIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0NTE4LCJOYW1lIjoiSDNjbzlhM2dBclhhRHc2ZmEzcyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ4OTExMX0seyJJZCI6NDUxOSwiTmFtZSI6Imo2biIsIlN0cmluZ1ZhbHVlIjoidXlISlBhaCBvMCIsIkludFZhbHVlIjo0NzY3MzV9XSwiU2lnbkRhdGUiOjE1NzA0NjEwMzB9\",\"signature\":\"Lpc8Aq2kD40VnYSkWnB/rOa9vNZ5g0+C8QJDDVN0p6EP2wihSMKcCCS/eW4z+mVdMobRGKKbCkvYISdUOpszX2+ZDmUM2GGmivbJ0xczPhNK3rK5ri9sBI0vp7jNOoonYWFDA7j4g6E25RoGyCczoWa1nKiuYBZtLimiAZOBiXjrurtYTDd3cUN7UJHEU+nN5Nn5Ww1ZkyOW34l7VcYlQoJWHdlP/phnGwDSnGhs4h3PcuJxafu/10BssG4LABAxGAgnupLDX8k7n0knlJy0ekViC2tWAVipvBYCfDJ6oLo2TGlaB0BA4PBtsO6iM6I/mzi0AwWLwUIE4aKAYRDqRw==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key411() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key411::license_key_;

TEST_F(v20190401_offline_json_Key411, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801536);
  EXPECT_EQ(license_key->get_expires(), 3833023936);
  EXPECT_EQ(license_key->get_period(), 26240);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key411, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 462); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MEVJX-OOJAO-GUMJJ-SNDXE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Ht0"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "BF\nM33 EHayZ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }
}

TEST_F(v20190401_offline_json_Key411, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811755));

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

TEST_F(v20190401_offline_json_Key411, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6580);
    EXPECT_EQ(customer.get_name(), "meHnxDPJNO TjpyWDDRIM");
    EXPECT_EQ(customer.get_email(), "EV09ofuV3hcaWddpGmCiiV7 ");
    EXPECT_EQ(customer.get_company_name(), "xb8");
    EXPECT_EQ(customer.get_created(), 1565801536);
  }
}

TEST_F(v20190401_offline_json_Key411, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4518, "H3co9a3gArXaDw6fa3s", "", 489111));
  expected.push_back(cryptolens::DataObject(4519, "j6n", "uyHJPah o0", 476735));

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

class v20190401_offline_compact_Key411 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo0NjIsIktleSI6Ik1FVkpYLU9PSkFPLUdVTUpKLVNORFhFIiwiQ3JlYXRlZCI6MTU2NTgwMTUzNiwiRXhwaXJlcyI6MzgzMzAyMzkzNiwiUGVyaW9kIjoyNjI0MCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6dHJ1ZSwiRjciOnRydWUsIkY4IjpmYWxzZSwiTm90ZXMiOiJIdDAiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDc0MywiQ3VzdG9tZXIiOnsiSWQiOjY1ODAsIk5hbWUiOiJtZUhueERQSk5PIFRqcHlXRERSSU0iLCJFbWFpbCI6IkVWMDlvZnVWM2hjYVdkZHBHbUNpaVY3ICIsIkNvbXBhbnlOYW1lIjoieGI4IiwiQ3JlYXRlZCI6MTU2NTgwMTUzNn0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE3NTV9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxLCJBbGxvd2VkTWFjaGluZXMiOiJCRlxuTTMzIEVIYXlaIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0NTE4LCJOYW1lIjoiSDNjbzlhM2dBclhhRHc2ZmEzcyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ4OTExMX0seyJJZCI6NDUxOSwiTmFtZSI6Imo2biIsIlN0cmluZ1ZhbHVlIjoidXlISlBhaCBvMCIsIkludFZhbHVlIjo0NzY3MzV9XSwiU2lnbkRhdGUiOjE1NzA0NjEwMzB9";
    saved_response += "-";
    saved_response += "Lpc8Aq2kD40VnYSkWnB/rOa9vNZ5g0+C8QJDDVN0p6EP2wihSMKcCCS/eW4z+mVdMobRGKKbCkvYISdUOpszX2+ZDmUM2GGmivbJ0xczPhNK3rK5ri9sBI0vp7jNOoonYWFDA7j4g6E25RoGyCczoWa1nKiuYBZtLimiAZOBiXjrurtYTDd3cUN7UJHEU+nN5Nn5Ww1ZkyOW34l7VcYlQoJWHdlP/phnGwDSnGhs4h3PcuJxafu/10BssG4LABAxGAgnupLDX8k7n0knlJy0ekViC2tWAVipvBYCfDJ6oLo2TGlaB0BA4PBtsO6iM6I/mzi0AwWLwUIE4aKAYRDqRw==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key411() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key411::license_key_;

TEST_F(v20190401_offline_compact_Key411, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801536);
  EXPECT_EQ(license_key->get_expires(), 3833023936);
  EXPECT_EQ(license_key->get_period(), 26240);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key411, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 462); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MEVJX-OOJAO-GUMJJ-SNDXE"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "Ht0"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "BF\nM33 EHayZ"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54743); }
}

TEST_F(v20190401_offline_compact_Key411, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811755));

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

TEST_F(v20190401_offline_compact_Key411, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6580);
    EXPECT_EQ(customer.get_name(), "meHnxDPJNO TjpyWDDRIM");
    EXPECT_EQ(customer.get_email(), "EV09ofuV3hcaWddpGmCiiV7 ");
    EXPECT_EQ(customer.get_company_name(), "xb8");
    EXPECT_EQ(customer.get_created(), 1565801536);
  }
}

TEST_F(v20190401_offline_compact_Key411, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4518, "H3co9a3gArXaDw6fa3s", "", 489111));
  expected.push_back(cryptolens::DataObject(4519, "j6n", "uyHJPah o0", 476735));

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
