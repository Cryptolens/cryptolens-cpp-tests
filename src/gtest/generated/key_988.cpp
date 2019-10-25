#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key988 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "MLHFY-CCGCJ-OVJSV-DWXPN", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key988() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key988::license_key_;

TEST_F(v20180502_online_Key988, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802783);
  EXPECT_EQ(license_key->get_expires(), 3990023351);
  EXPECT_EQ(license_key->get_period(), 28058);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key988, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 1039); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MLHFY-CCGCJ-OVJSV-DWXPN"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "jGMfClZ7C7M1OBhYQB9xzc\n5v8epG2kmWPOlvt7sSEg5\nh1mhKjnzZygYxxQyf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }
}

TEST_F(v20180502_online_Key988, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812151));

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

TEST_F(v20180502_online_Key988, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6867);
    EXPECT_EQ(customer.get_name(), "Jdr fKNPHBenJ");
    EXPECT_EQ(customer.get_email(), "0WcoPL");
    EXPECT_EQ(customer.get_company_name(), "XE8SeInEzKjQ");
    EXPECT_EQ(customer.get_created(), 1565802783);
  }
}

TEST_F(v20180502_online_Key988, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5380, "7zL6qMi9Q82Ba4gF1poVsP", "BL7hVky08eqiSEHIZzU0p", 43958));
  expected.push_back(cryptolens::DataObject(5381, "wLstOk3R3", "", 487111));

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

class v20190401_online_Key988 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "MLHFY-CCGCJ-OVJSV-DWXPN");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key988() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key988::license_key_;

TEST_F(v20190401_online_Key988, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802783);
  EXPECT_EQ(license_key->get_expires(), 3990023351);
  EXPECT_EQ(license_key->get_period(), 28058);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key988, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 1039); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MLHFY-CCGCJ-OVJSV-DWXPN"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "jGMfClZ7C7M1OBhYQB9xzc\n5v8epG2kmWPOlvt7sSEg5\nh1mhKjnzZygYxxQyf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }
}

TEST_F(v20190401_online_Key988, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812151));

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

TEST_F(v20190401_online_Key988, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6867);
    EXPECT_EQ(customer.get_name(), "Jdr fKNPHBenJ");
    EXPECT_EQ(customer.get_email(), "0WcoPL");
    EXPECT_EQ(customer.get_company_name(), "XE8SeInEzKjQ");
    EXPECT_EQ(customer.get_created(), 1565802783);
  }
}

TEST_F(v20190401_online_Key988, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5380, "7zL6qMi9Q82Ba4gF1poVsP", "BL7hVky08eqiSEHIZzU0p", 43958));
  expected.push_back(cryptolens::DataObject(5381, "wLstOk3R3", "", 487111));

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

class v20190401_offline_json_Key988 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoxMDM5LCJLZXkiOiJNTEhGWS1DQ0dDSi1PVkpTVi1EV1hQTiIsIkNyZWF0ZWQiOjE1NjU4MDI3ODMsIkV4cGlyZXMiOjM5OTAwMjMzNTEsIlBlcmlvZCI6MjgwNTgsIkYxIjp0cnVlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOnRydWUsIkY2Ijp0cnVlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUzMjAsIkN1c3RvbWVyIjp7IklkIjo2ODY3LCJOYW1lIjoiSmRyIGZLTlBIQmVuSiIsIkVtYWlsIjoiMFdjb1BMIiwiQ29tcGFueU5hbWUiOiJYRThTZUluRXpLalEiLCJDcmVhdGVkIjoxNTY1ODAyNzgzfSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMjE1MX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiakdNZkNsWjdDN00xT0JoWVFCOXh6Y1xuNXY4ZXBHMmttV1BPbHZ0N3NTRWc1XG5oMW1oS2puelp5Z1l4eFF5ZiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NTM4MCwiTmFtZSI6Ijd6TDZxTWk5UTgyQmE0Z0YxcG9Wc1AiLCJTdHJpbmdWYWx1ZSI6IkJMN2hWa3kwOGVxaVNFSElaelUwcCIsIkludFZhbHVlIjo0Mzk1OH0seyJJZCI6NTM4MSwiTmFtZSI6IndMc3RPazNSMyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ4NzExMX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTM1NH0=\",\"signature\":\"galeiaHumUAvFCTH6s5GmDsoGLylGFSS5FkUs9PadO9k70G2+23kPjyQ7eK7hiUa9BpcMEv5XB6ADThJRHnrXFtVDpsg3qnuhbIYExFm4W6ElxhymSPW+ss1Dw/uXALf3o2Sx7t3suDDI+o4KJFUnMaaaTxqBinkrFNLqc7G/7GXgE4qXZmifbNcSnI6DQP7O3h4AArd1xgM9uuhBpJ9hjbVnwLbTSRwfLocTnn+mpMUFOvbXgiW2FQX6rfJBqQMPdPsaCzAYTDcChvJhGa+SUI/rCR5mpKzqu10iJ1ubc5w8nHicHUjYFhEFsvW5PFVU/UM4IHzkEl2cdp012Hlgg==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key988() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key988::license_key_;

TEST_F(v20190401_offline_json_Key988, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802783);
  EXPECT_EQ(license_key->get_expires(), 3990023351);
  EXPECT_EQ(license_key->get_period(), 28058);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key988, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 1039); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MLHFY-CCGCJ-OVJSV-DWXPN"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "jGMfClZ7C7M1OBhYQB9xzc\n5v8epG2kmWPOlvt7sSEg5\nh1mhKjnzZygYxxQyf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }
}

TEST_F(v20190401_offline_json_Key988, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812151));

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

TEST_F(v20190401_offline_json_Key988, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6867);
    EXPECT_EQ(customer.get_name(), "Jdr fKNPHBenJ");
    EXPECT_EQ(customer.get_email(), "0WcoPL");
    EXPECT_EQ(customer.get_company_name(), "XE8SeInEzKjQ");
    EXPECT_EQ(customer.get_created(), 1565802783);
  }
}

TEST_F(v20190401_offline_json_Key988, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5380, "7zL6qMi9Q82Ba4gF1poVsP", "BL7hVky08eqiSEHIZzU0p", 43958));
  expected.push_back(cryptolens::DataObject(5381, "wLstOk3R3", "", 487111));

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

class v20190401_offline_compact_Key988 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjoxMDM5LCJLZXkiOiJNTEhGWS1DQ0dDSi1PVkpTVi1EV1hQTiIsIkNyZWF0ZWQiOjE1NjU4MDI3ODMsIkV4cGlyZXMiOjM5OTAwMjMzNTEsIlBlcmlvZCI6MjgwNTgsIkYxIjp0cnVlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOnRydWUsIkY2Ijp0cnVlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUzMjAsIkN1c3RvbWVyIjp7IklkIjo2ODY3LCJOYW1lIjoiSmRyIGZLTlBIQmVuSiIsIkVtYWlsIjoiMFdjb1BMIiwiQ29tcGFueU5hbWUiOiJYRThTZUluRXpLalEiLCJDcmVhdGVkIjoxNTY1ODAyNzgzfSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMjE1MX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiakdNZkNsWjdDN00xT0JoWVFCOXh6Y1xuNXY4ZXBHMmttV1BPbHZ0N3NTRWc1XG5oMW1oS2puelp5Z1l4eFF5ZiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NTM4MCwiTmFtZSI6Ijd6TDZxTWk5UTgyQmE0Z0YxcG9Wc1AiLCJTdHJpbmdWYWx1ZSI6IkJMN2hWa3kwOGVxaVNFSElaelUwcCIsIkludFZhbHVlIjo0Mzk1OH0seyJJZCI6NTM4MSwiTmFtZSI6IndMc3RPazNSMyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ4NzExMX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTM1NH0=";
    saved_response += "-";
    saved_response += "galeiaHumUAvFCTH6s5GmDsoGLylGFSS5FkUs9PadO9k70G2+23kPjyQ7eK7hiUa9BpcMEv5XB6ADThJRHnrXFtVDpsg3qnuhbIYExFm4W6ElxhymSPW+ss1Dw/uXALf3o2Sx7t3suDDI+o4KJFUnMaaaTxqBinkrFNLqc7G/7GXgE4qXZmifbNcSnI6DQP7O3h4AArd1xgM9uuhBpJ9hjbVnwLbTSRwfLocTnn+mpMUFOvbXgiW2FQX6rfJBqQMPdPsaCzAYTDcChvJhGa+SUI/rCR5mpKzqu10iJ1ubc5w8nHicHUjYFhEFsvW5PFVU/UM4IHzkEl2cdp012Hlgg==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key988() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key988::license_key_;

TEST_F(v20190401_offline_compact_Key988, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802783);
  EXPECT_EQ(license_key->get_expires(), 3990023351);
  EXPECT_EQ(license_key->get_period(), 28058);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key988, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 1039); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "MLHFY-CCGCJ-OVJSV-DWXPN"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "jGMfClZ7C7M1OBhYQB9xzc\n5v8epG2kmWPOlvt7sSEg5\nh1mhKjnzZygYxxQyf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55320); }
}

TEST_F(v20190401_offline_compact_Key988, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812151));

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

TEST_F(v20190401_offline_compact_Key988, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6867);
    EXPECT_EQ(customer.get_name(), "Jdr fKNPHBenJ");
    EXPECT_EQ(customer.get_email(), "0WcoPL");
    EXPECT_EQ(customer.get_company_name(), "XE8SeInEzKjQ");
    EXPECT_EQ(customer.get_created(), 1565802783);
  }
}

TEST_F(v20190401_offline_compact_Key988, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5380, "7zL6qMi9Q82Ba4gF1poVsP", "BL7hVky08eqiSEHIZzU0p", 43958));
  expected.push_back(cryptolens::DataObject(5381, "wLstOk3R3", "", 487111));

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
