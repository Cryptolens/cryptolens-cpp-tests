#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key863 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "BJRSO-NFRZY-EFWKG-JLXHY", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key863() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key863::license_key_;

TEST_F(v20180502_online_Key863, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802483);
  EXPECT_EQ(license_key->get_expires(), 4368013683);
  EXPECT_EQ(license_key->get_period(), 32432);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key863, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 914); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BJRSO-NFRZY-EFWKG-JLXHY"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "5Jd11rDR6X7pYGd2qe Q2dw"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }
}

TEST_F(v20180502_online_Key863, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812061));

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

TEST_F(v20180502_online_Key863, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6815);
    EXPECT_EQ(customer.get_name(), "AtAi4eh");
    EXPECT_EQ(customer.get_email(), "Myq5wKUR");
    EXPECT_EQ(customer.get_company_name(), "ZXGs4Lo2dz7Dp6dRek1gX");
    EXPECT_EQ(customer.get_created(), 1565802482);
  }
}

TEST_F(v20180502_online_Key863, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5191, "zBJubXRitIK LsZ4Vn5FXvAyH", "pLYfUutcKSTWfk62HOE", 777247));
  expected.push_back(cryptolens::DataObject(5192, "c0 McO2XdSROaT", "9p9DWD", 623814));
  expected.push_back(cryptolens::DataObject(5193, "ymT", "XkjUtNJf3QOV1mfQ5trS7n", 191851));

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

class v20190401_online_Key863 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "BJRSO-NFRZY-EFWKG-JLXHY");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key863() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key863::license_key_;

TEST_F(v20190401_online_Key863, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802483);
  EXPECT_EQ(license_key->get_expires(), 4368013683);
  EXPECT_EQ(license_key->get_period(), 32432);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key863, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 914); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BJRSO-NFRZY-EFWKG-JLXHY"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "5Jd11rDR6X7pYGd2qe Q2dw"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }
}

TEST_F(v20190401_online_Key863, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812061));

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

TEST_F(v20190401_online_Key863, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6815);
    EXPECT_EQ(customer.get_name(), "AtAi4eh");
    EXPECT_EQ(customer.get_email(), "Myq5wKUR");
    EXPECT_EQ(customer.get_company_name(), "ZXGs4Lo2dz7Dp6dRek1gX");
    EXPECT_EQ(customer.get_created(), 1565802482);
  }
}

TEST_F(v20190401_online_Key863, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5191, "zBJubXRitIK LsZ4Vn5FXvAyH", "pLYfUutcKSTWfk62HOE", 777247));
  expected.push_back(cryptolens::DataObject(5192, "c0 McO2XdSROaT", "9p9DWD", 623814));
  expected.push_back(cryptolens::DataObject(5193, "ymT", "XkjUtNJf3QOV1mfQ5trS7n", 191851));

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

class v20190401_offline_json_Key863 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MTQsIktleSI6IkJKUlNPLU5GUlpZLUVGV0tHLUpMWEhZIiwiQ3JlYXRlZCI6MTU2NTgwMjQ4MywiRXhwaXJlcyI6NDM2ODAxMzY4MywiUGVyaW9kIjozMjQzMiwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6dHJ1ZSwiRjQiOmZhbHNlLCJGNSI6dHJ1ZSwiRjYiOmZhbHNlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUxOTUsIkN1c3RvbWVyIjp7IklkIjo2ODE1LCJOYW1lIjoiQXRBaTRlaCIsIkVtYWlsIjoiTXlxNXdLVVIiLCJDb21wYW55TmFtZSI6IlpYR3M0TG8yZHo3RHA2ZFJlazFnWCIsIkNyZWF0ZWQiOjE1NjU4MDI0ODJ9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODEyMDYxfV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiNUpkMTFyRFI2WDdwWUdkMnFlIFEyZHciLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUxOTEsIk5hbWUiOiJ6Qkp1YlhSaXRJSyBMc1o0Vm41Rlh2QXlIIiwiU3RyaW5nVmFsdWUiOiJwTFlmVXV0Y0tTVFdmazYySE9FIiwiSW50VmFsdWUiOjc3NzI0N30seyJJZCI6NTE5MiwiTmFtZSI6ImMwIE1jTzJYZFNST2FUIiwiU3RyaW5nVmFsdWUiOiI5cDlEV0QiLCJJbnRWYWx1ZSI6NjIzODE0fSx7IklkIjo1MTkzLCJOYW1lIjoieW1UIiwiU3RyaW5nVmFsdWUiOiJYa2pVdE5KZjNRT1YxbWZRNXRyUzduIiwiSW50VmFsdWUiOjE5MTg1MX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI4M30=\",\"signature\":\"Lu2Atj1NdzpkXMHyFFYwHpAO/k0YaRLiPxom3MzcVA9M+mJL+ZTWkOCphiMKEonMyEFWUAVmIUFH3zfJGFT4f9TO5coT+fG5S42erTbI6e5lFM4RasgEHsWFJwNgbEdxcza8apBRJGsoNGjcTzQ/ms+FwVmzUhJKwdS2Q5fUQa//HVTi07L8IAoQU0G/GnoMnGB5GrIVo0fTcK80nQqhMBe0JfKwKwPFSzl67ysrlfewUMLD1k3EBF9a+tO1IyT0vJYMFfQJnOYRDlzLQOxPk/7lzMbb7UBaIUifUwNgHCSBVfJEmGeCdE+1bpDuSQiDwNjL5Ti27rE4t3nPRMrtJQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key863() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key863::license_key_;

TEST_F(v20190401_offline_json_Key863, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802483);
  EXPECT_EQ(license_key->get_expires(), 4368013683);
  EXPECT_EQ(license_key->get_period(), 32432);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key863, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 914); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BJRSO-NFRZY-EFWKG-JLXHY"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "5Jd11rDR6X7pYGd2qe Q2dw"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }
}

TEST_F(v20190401_offline_json_Key863, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812061));

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

TEST_F(v20190401_offline_json_Key863, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6815);
    EXPECT_EQ(customer.get_name(), "AtAi4eh");
    EXPECT_EQ(customer.get_email(), "Myq5wKUR");
    EXPECT_EQ(customer.get_company_name(), "ZXGs4Lo2dz7Dp6dRek1gX");
    EXPECT_EQ(customer.get_created(), 1565802482);
  }
}

TEST_F(v20190401_offline_json_Key863, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5191, "zBJubXRitIK LsZ4Vn5FXvAyH", "pLYfUutcKSTWfk62HOE", 777247));
  expected.push_back(cryptolens::DataObject(5192, "c0 McO2XdSROaT", "9p9DWD", 623814));
  expected.push_back(cryptolens::DataObject(5193, "ymT", "XkjUtNJf3QOV1mfQ5trS7n", 191851));

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

class v20190401_offline_compact_Key863 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MTQsIktleSI6IkJKUlNPLU5GUlpZLUVGV0tHLUpMWEhZIiwiQ3JlYXRlZCI6MTU2NTgwMjQ4MywiRXhwaXJlcyI6NDM2ODAxMzY4MywiUGVyaW9kIjozMjQzMiwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6dHJ1ZSwiRjQiOmZhbHNlLCJGNSI6dHJ1ZSwiRjYiOmZhbHNlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUxOTUsIkN1c3RvbWVyIjp7IklkIjo2ODE1LCJOYW1lIjoiQXRBaTRlaCIsIkVtYWlsIjoiTXlxNXdLVVIiLCJDb21wYW55TmFtZSI6IlpYR3M0TG8yZHo3RHA2ZFJlazFnWCIsIkNyZWF0ZWQiOjE1NjU4MDI0ODJ9LCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODEyMDYxfV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoiNUpkMTFyRFI2WDdwWUdkMnFlIFEyZHciLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUxOTEsIk5hbWUiOiJ6Qkp1YlhSaXRJSyBMc1o0Vm41Rlh2QXlIIiwiU3RyaW5nVmFsdWUiOiJwTFlmVXV0Y0tTVFdmazYySE9FIiwiSW50VmFsdWUiOjc3NzI0N30seyJJZCI6NTE5MiwiTmFtZSI6ImMwIE1jTzJYZFNST2FUIiwiU3RyaW5nVmFsdWUiOiI5cDlEV0QiLCJJbnRWYWx1ZSI6NjIzODE0fSx7IklkIjo1MTkzLCJOYW1lIjoieW1UIiwiU3RyaW5nVmFsdWUiOiJYa2pVdE5KZjNRT1YxbWZRNXRyUzduIiwiSW50VmFsdWUiOjE5MTg1MX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI4M30=";
    saved_response += "-";
    saved_response += "Lu2Atj1NdzpkXMHyFFYwHpAO/k0YaRLiPxom3MzcVA9M+mJL+ZTWkOCphiMKEonMyEFWUAVmIUFH3zfJGFT4f9TO5coT+fG5S42erTbI6e5lFM4RasgEHsWFJwNgbEdxcza8apBRJGsoNGjcTzQ/ms+FwVmzUhJKwdS2Q5fUQa//HVTi07L8IAoQU0G/GnoMnGB5GrIVo0fTcK80nQqhMBe0JfKwKwPFSzl67ysrlfewUMLD1k3EBF9a+tO1IyT0vJYMFfQJnOYRDlzLQOxPk/7lzMbb7UBaIUifUwNgHCSBVfJEmGeCdE+1bpDuSQiDwNjL5Ti27rE4t3nPRMrtJQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key863() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key863::license_key_;

TEST_F(v20190401_offline_compact_Key863, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802483);
  EXPECT_EQ(license_key->get_expires(), 4368013683);
  EXPECT_EQ(license_key->get_period(), 32432);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key863, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 914); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BJRSO-NFRZY-EFWKG-JLXHY"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), ""); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "5Jd11rDR6X7pYGd2qe Q2dw"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55195); }
}

TEST_F(v20190401_offline_compact_Key863, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812061));

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

TEST_F(v20190401_offline_compact_Key863, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6815);
    EXPECT_EQ(customer.get_name(), "AtAi4eh");
    EXPECT_EQ(customer.get_email(), "Myq5wKUR");
    EXPECT_EQ(customer.get_company_name(), "ZXGs4Lo2dz7Dp6dRek1gX");
    EXPECT_EQ(customer.get_created(), 1565802482);
  }
}

TEST_F(v20190401_offline_compact_Key863, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5191, "zBJubXRitIK LsZ4Vn5FXvAyH", "pLYfUutcKSTWfk62HOE", 777247));
  expected.push_back(cryptolens::DataObject(5192, "c0 McO2XdSROaT", "9p9DWD", 623814));
  expected.push_back(cryptolens::DataObject(5193, "ymT", "XkjUtNJf3QOV1mfQ5trS7n", 191851));

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
