#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key590 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "BISNP-ERIZM-MGBHC-MUGMR", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key590() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key590::license_key_;

TEST_F(v20180502_online_Key590, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801884);
  EXPECT_EQ(license_key->get_expires(), 3312128676);
  EXPECT_EQ(license_key->get_period(), 20212);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key590, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 641); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BISNP-ERIZM-MGBHC-MUGMR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "I13VSIa1tvpSEPhIGD2H8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "taZwwEQCTZwikLj\nEtcX99\n1uwMn11"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }
}

TEST_F(v20180502_online_Key590, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811875));

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

TEST_F(v20180502_online_Key590, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6673);
    EXPECT_EQ(customer.get_name(), "8r3tYcabtqtlrjKtx");
    EXPECT_EQ(customer.get_email(), "cdiARfsaYqredkoo PqB2BKmB");
    EXPECT_EQ(customer.get_company_name(), "B41duXsuLCdc50tj6ZCNjQH4");
    EXPECT_EQ(customer.get_created(), 1565801883);
  }
}

TEST_F(v20180502_online_Key590, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4780, "k2HhwHV5Jt7zg7NJ4mC9i", "", 760143));
  expected.push_back(cryptolens::DataObject(4781, " sI3ZZtrKRE5uhpegcL", "RfSkswO846u MEiTI2", 849151));
  expected.push_back(cryptolens::DataObject(4782, "WtFy53 ZFURyGbFl1SPyid YF", "2W7UoJnvu7KNoYOafJ4 ", 230359));

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

class v20190401_online_Key590 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "BISNP-ERIZM-MGBHC-MUGMR");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key590() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key590::license_key_;

TEST_F(v20190401_online_Key590, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801884);
  EXPECT_EQ(license_key->get_expires(), 3312128676);
  EXPECT_EQ(license_key->get_period(), 20212);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key590, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 641); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BISNP-ERIZM-MGBHC-MUGMR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "I13VSIa1tvpSEPhIGD2H8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "taZwwEQCTZwikLj\nEtcX99\n1uwMn11"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }
}

TEST_F(v20190401_online_Key590, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811875));

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

TEST_F(v20190401_online_Key590, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6673);
    EXPECT_EQ(customer.get_name(), "8r3tYcabtqtlrjKtx");
    EXPECT_EQ(customer.get_email(), "cdiARfsaYqredkoo PqB2BKmB");
    EXPECT_EQ(customer.get_company_name(), "B41duXsuLCdc50tj6ZCNjQH4");
    EXPECT_EQ(customer.get_created(), 1565801883);
  }
}

TEST_F(v20190401_online_Key590, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4780, "k2HhwHV5Jt7zg7NJ4mC9i", "", 760143));
  expected.push_back(cryptolens::DataObject(4781, " sI3ZZtrKRE5uhpegcL", "RfSkswO846u MEiTI2", 849151));
  expected.push_back(cryptolens::DataObject(4782, "WtFy53 ZFURyGbFl1SPyid YF", "2W7UoJnvu7KNoYOafJ4 ", 230359));

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

class v20190401_offline_json_Key590 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2NDEsIktleSI6IkJJU05QLUVSSVpNLU1HQkhDLU1VR01SIiwiQ3JlYXRlZCI6MTU2NTgwMTg4NCwiRXhwaXJlcyI6MzMxMjEyODY3NiwiUGVyaW9kIjoyMDIxMiwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJJMTNWU0lhMXR2cFNFUGhJR0QySDgiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDkyMiwiQ3VzdG9tZXIiOnsiSWQiOjY2NzMsIk5hbWUiOiI4cjN0WWNhYnRxdGxyakt0eCIsIkVtYWlsIjoiY2RpQVJmc2FZcXJlZGtvbyBQcUIyQkttQiIsIkNvbXBhbnlOYW1lIjoiQjQxZHVYc3VMQ2RjNTB0ajZaQ05qUUg0IiwiQ3JlYXRlZCI6MTU2NTgwMTg4M30sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4NzV9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjIsIkFsbG93ZWRNYWNoaW5lcyI6InRhWnd3RVFDVFp3aWtMalxuRXRjWDk5XG4xdXdNbjExIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0NzgwLCJOYW1lIjoiazJIaHdIVjVKdDd6ZzdOSjRtQzlpIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NzYwMTQzfSx7IklkIjo0NzgxLCJOYW1lIjoiIHNJM1padHJLUkU1dWhwZWdjTCIsIlN0cmluZ1ZhbHVlIjoiUmZTa3N3Tzg0NnUgTUVpVEkyIiwiSW50VmFsdWUiOjg0OTE1MX0seyJJZCI6NDc4MiwiTmFtZSI6Ild0Rnk1MyBaRlVSeUdiRmwxU1B5aWQgWUYiLCJTdHJpbmdWYWx1ZSI6IjJXN1VvSm52dTdLTm9ZT2FmSjQgIiwiSW50VmFsdWUiOjIzMDM1OX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTEyOH0=\",\"signature\":\"MoDO/Ac4KbNBvwBM0Htu1qlQGniQzvcqZJBklfhPC6mG1TIcya0qobIaMKPUEZuikctzaYc3n+QGWd5+wRxvAHGxlj7GYX+ANURJUZVx2xw2NUdxjttzWxVWXlM9g2GGL5zvUml/xw2s6DDbMc+KQ5E3Q44d9e7xL5g+/VdWGUZUqqNtJxhei5BgTjOxgj/OKKR0lTyGBUBNlNnUcGP5t98ZHdto0YgPVOj3i8YhwRIhPZlxhmF3VqvyKRTJPBY3VPq8DYXNZrN6R9fuA+AYV9BpOFRuqs3qxQA/hOwWVyYUWSTBQhiRqHFE/HUBC8SyNQPK3IXghJCD0XsGRQMB0A==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key590() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key590::license_key_;

TEST_F(v20190401_offline_json_Key590, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801884);
  EXPECT_EQ(license_key->get_expires(), 3312128676);
  EXPECT_EQ(license_key->get_period(), 20212);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key590, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 641); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BISNP-ERIZM-MGBHC-MUGMR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "I13VSIa1tvpSEPhIGD2H8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "taZwwEQCTZwikLj\nEtcX99\n1uwMn11"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }
}

TEST_F(v20190401_offline_json_Key590, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811875));

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

TEST_F(v20190401_offline_json_Key590, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6673);
    EXPECT_EQ(customer.get_name(), "8r3tYcabtqtlrjKtx");
    EXPECT_EQ(customer.get_email(), "cdiARfsaYqredkoo PqB2BKmB");
    EXPECT_EQ(customer.get_company_name(), "B41duXsuLCdc50tj6ZCNjQH4");
    EXPECT_EQ(customer.get_created(), 1565801883);
  }
}

TEST_F(v20190401_offline_json_Key590, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4780, "k2HhwHV5Jt7zg7NJ4mC9i", "", 760143));
  expected.push_back(cryptolens::DataObject(4781, " sI3ZZtrKRE5uhpegcL", "RfSkswO846u MEiTI2", 849151));
  expected.push_back(cryptolens::DataObject(4782, "WtFy53 ZFURyGbFl1SPyid YF", "2W7UoJnvu7KNoYOafJ4 ", 230359));

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

class v20190401_offline_compact_Key590 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo2NDEsIktleSI6IkJJU05QLUVSSVpNLU1HQkhDLU1VR01SIiwiQ3JlYXRlZCI6MTU2NTgwMTg4NCwiRXhwaXJlcyI6MzMxMjEyODY3NiwiUGVyaW9kIjoyMDIxMiwiRjEiOnRydWUsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiJJMTNWU0lhMXR2cFNFUGhJR0QySDgiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDkyMiwiQ3VzdG9tZXIiOnsiSWQiOjY2NzMsIk5hbWUiOiI4cjN0WWNhYnRxdGxyakt0eCIsIkVtYWlsIjoiY2RpQVJmc2FZcXJlZGtvbyBQcUIyQkttQiIsIkNvbXBhbnlOYW1lIjoiQjQxZHVYc3VMQ2RjNTB0ajZaQ05qUUg0IiwiQ3JlYXRlZCI6MTU2NTgwMTg4M30sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4NzV9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjIsIkFsbG93ZWRNYWNoaW5lcyI6InRhWnd3RVFDVFp3aWtMalxuRXRjWDk5XG4xdXdNbjExIiwiRGF0YU9iamVjdHMiOlt7IklkIjo0NzgwLCJOYW1lIjoiazJIaHdIVjVKdDd6ZzdOSjRtQzlpIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NzYwMTQzfSx7IklkIjo0NzgxLCJOYW1lIjoiIHNJM1padHJLUkU1dWhwZWdjTCIsIlN0cmluZ1ZhbHVlIjoiUmZTa3N3Tzg0NnUgTUVpVEkyIiwiSW50VmFsdWUiOjg0OTE1MX0seyJJZCI6NDc4MiwiTmFtZSI6Ild0Rnk1MyBaRlVSeUdiRmwxU1B5aWQgWUYiLCJTdHJpbmdWYWx1ZSI6IjJXN1VvSm52dTdLTm9ZT2FmSjQgIiwiSW50VmFsdWUiOjIzMDM1OX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTEyOH0=";
    saved_response += "-";
    saved_response += "MoDO/Ac4KbNBvwBM0Htu1qlQGniQzvcqZJBklfhPC6mG1TIcya0qobIaMKPUEZuikctzaYc3n+QGWd5+wRxvAHGxlj7GYX+ANURJUZVx2xw2NUdxjttzWxVWXlM9g2GGL5zvUml/xw2s6DDbMc+KQ5E3Q44d9e7xL5g+/VdWGUZUqqNtJxhei5BgTjOxgj/OKKR0lTyGBUBNlNnUcGP5t98ZHdto0YgPVOj3i8YhwRIhPZlxhmF3VqvyKRTJPBY3VPq8DYXNZrN6R9fuA+AYV9BpOFRuqs3qxQA/hOwWVyYUWSTBQhiRqHFE/HUBC8SyNQPK3IXghJCD0XsGRQMB0A==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key590() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key590::license_key_;

TEST_F(v20190401_offline_compact_Key590, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801884);
  EXPECT_EQ(license_key->get_expires(), 3312128676);
  EXPECT_EQ(license_key->get_period(), 20212);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key590, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 641); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BISNP-ERIZM-MGBHC-MUGMR"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "I13VSIa1tvpSEPhIGD2H8"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "taZwwEQCTZwikLj\nEtcX99\n1uwMn11"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54922); }
}

TEST_F(v20190401_offline_compact_Key590, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811875));

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

TEST_F(v20190401_offline_compact_Key590, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6673);
    EXPECT_EQ(customer.get_name(), "8r3tYcabtqtlrjKtx");
    EXPECT_EQ(customer.get_email(), "cdiARfsaYqredkoo PqB2BKmB");
    EXPECT_EQ(customer.get_company_name(), "B41duXsuLCdc50tj6ZCNjQH4");
    EXPECT_EQ(customer.get_created(), 1565801883);
  }
}

TEST_F(v20190401_offline_compact_Key590, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4780, "k2HhwHV5Jt7zg7NJ4mC9i", "", 760143));
  expected.push_back(cryptolens::DataObject(4781, " sI3ZZtrKRE5uhpegcL", "RfSkswO846u MEiTI2", 849151));
  expected.push_back(cryptolens::DataObject(4782, "WtFy53 ZFURyGbFl1SPyid YF", "2W7UoJnvu7KNoYOafJ4 ", 230359));

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
