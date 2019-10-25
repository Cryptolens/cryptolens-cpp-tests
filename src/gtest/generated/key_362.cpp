#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key362 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "ENXUP-EDCPS-QOLSR-OEGQF", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key362() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key362::license_key_;

TEST_F(v20180502_online_Key362, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801447);
  EXPECT_EQ(license_key->get_expires(), 4285338121);
  EXPECT_EQ(license_key->get_period(), 31476);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key362, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 413); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "ENXUP-EDCPS-QOLSR-OEGQF"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "kMjTqCUZsgKttbmC7iaNp"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "rrNagOtz49D\n6rErc\nXPcvlyTHrLB9V3AXKlsYesT"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }
}

TEST_F(v20180502_online_Key362, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811721));

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

TEST_F(v20180502_online_Key362, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6553);
    EXPECT_EQ(customer.get_name(), "WYkgBdkBKBB6mdNVu ");
    EXPECT_EQ(customer.get_email(), "Vd2");
    EXPECT_EQ(customer.get_company_name(), "AHrwupMCHVY4tALJ4raJUxT");
    EXPECT_EQ(customer.get_created(), 1565801447);
  }
}

TEST_F(v20180502_online_Key362, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4440, "eMdsBCnmu", "Qongz7M59g45XDApdknxGuv", 945900));
  expected.push_back(cryptolens::DataObject(4441, "MfJ62XI5HS9JGOnFs", "", 687856));
  expected.push_back(cryptolens::DataObject(4442, "xz3JbnLKQ8fWj", "", 231882));

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

class v20190401_online_Key362 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "ENXUP-EDCPS-QOLSR-OEGQF");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key362() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key362::license_key_;

TEST_F(v20190401_online_Key362, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801447);
  EXPECT_EQ(license_key->get_expires(), 4285338121);
  EXPECT_EQ(license_key->get_period(), 31476);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key362, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 413); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "ENXUP-EDCPS-QOLSR-OEGQF"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "kMjTqCUZsgKttbmC7iaNp"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "rrNagOtz49D\n6rErc\nXPcvlyTHrLB9V3AXKlsYesT"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }
}

TEST_F(v20190401_online_Key362, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811721));

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

TEST_F(v20190401_online_Key362, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6553);
    EXPECT_EQ(customer.get_name(), "WYkgBdkBKBB6mdNVu ");
    EXPECT_EQ(customer.get_email(), "Vd2");
    EXPECT_EQ(customer.get_company_name(), "AHrwupMCHVY4tALJ4raJUxT");
    EXPECT_EQ(customer.get_created(), 1565801447);
  }
}

TEST_F(v20190401_online_Key362, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4440, "eMdsBCnmu", "Qongz7M59g45XDApdknxGuv", 945900));
  expected.push_back(cryptolens::DataObject(4441, "MfJ62XI5HS9JGOnFs", "", 687856));
  expected.push_back(cryptolens::DataObject(4442, "xz3JbnLKQ8fWj", "", 231882));

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

class v20190401_offline_json_Key362 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo0MTMsIktleSI6IkVOWFVQLUVEQ1BTLVFPTFNSLU9FR1FGIiwiQ3JlYXRlZCI6MTU2NTgwMTQ0NywiRXhwaXJlcyI6NDI4NTMzODEyMSwiUGVyaW9kIjozMTQ3NiwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4IjpmYWxzZSwiTm90ZXMiOiJrTWpUcUNVWnNnS3R0Ym1DN2lhTnAiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDY5NCwiQ3VzdG9tZXIiOnsiSWQiOjY1NTMsIk5hbWUiOiJXWWtnQmRrQktCQjZtZE5WdSAiLCJFbWFpbCI6IlZkMiIsIkNvbXBhbnlOYW1lIjoiQUhyd3VwTUNIVlk0dEFMSjRyYUpVeFQiLCJDcmVhdGVkIjoxNTY1ODAxNDQ3fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTcyMX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MiwiQWxsb3dlZE1hY2hpbmVzIjoicnJOYWdPdHo0OURcbjZyRXJjXG5YUGN2bHlUSHJMQjlWM0FYS2xzWWVzVCIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDQ0MCwiTmFtZSI6ImVNZHNCQ25tdSIsIlN0cmluZ1ZhbHVlIjoiUW9uZ3o3TTU5ZzQ1WERBcGRrbnhHdXYiLCJJbnRWYWx1ZSI6OTQ1OTAwfSx7IklkIjo0NDQxLCJOYW1lIjoiTWZKNjJYSTVIUzlKR09uRnMiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo2ODc4NTZ9LHsiSWQiOjQ0NDIsIk5hbWUiOiJ4ejNKYm5MS1E4ZldqIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6MjMxODgyfV0sIlNpZ25EYXRlIjoxNTcwNDYxMDAzfQ==\",\"signature\":\"YeOkB4SVgKSLJbiazlDQNE4bWO6j7ncE83jpia/rUtd4dmsLWc0Hs8UcGr7R8eykso2RkrWq0EuBMi8ZEyQ9Y18d+oRajP5D2J1OxwGIrYAvRAWf7nixX1nI66ZMv8I6wmrJXVOuzHLI0NJcwsnBv9bBuzqLwFV2PKGN7OkUP97ZPqEgVdgNlHztt3UKr682UCq2+n3i6aCl5q16nOq9G4nQYYVuZzHgG1OSPVWgdk9mjGq/33ykjG1EEF21k5WqnTVEdymtHc6HeF4dmwTr2LGTNdKMRdMHDMZVqh9036wdf3ept5yfcvoCIs6yAz78m0j33Gezk5Jkw0W/50ojhA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key362() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key362::license_key_;

TEST_F(v20190401_offline_json_Key362, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801447);
  EXPECT_EQ(license_key->get_expires(), 4285338121);
  EXPECT_EQ(license_key->get_period(), 31476);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key362, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 413); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "ENXUP-EDCPS-QOLSR-OEGQF"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "kMjTqCUZsgKttbmC7iaNp"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "rrNagOtz49D\n6rErc\nXPcvlyTHrLB9V3AXKlsYesT"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }
}

TEST_F(v20190401_offline_json_Key362, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811721));

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

TEST_F(v20190401_offline_json_Key362, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6553);
    EXPECT_EQ(customer.get_name(), "WYkgBdkBKBB6mdNVu ");
    EXPECT_EQ(customer.get_email(), "Vd2");
    EXPECT_EQ(customer.get_company_name(), "AHrwupMCHVY4tALJ4raJUxT");
    EXPECT_EQ(customer.get_created(), 1565801447);
  }
}

TEST_F(v20190401_offline_json_Key362, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4440, "eMdsBCnmu", "Qongz7M59g45XDApdknxGuv", 945900));
  expected.push_back(cryptolens::DataObject(4441, "MfJ62XI5HS9JGOnFs", "", 687856));
  expected.push_back(cryptolens::DataObject(4442, "xz3JbnLKQ8fWj", "", 231882));

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

class v20190401_offline_compact_Key362 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo0MTMsIktleSI6IkVOWFVQLUVEQ1BTLVFPTFNSLU9FR1FGIiwiQ3JlYXRlZCI6MTU2NTgwMTQ0NywiRXhwaXJlcyI6NDI4NTMzODEyMSwiUGVyaW9kIjozMTQ3NiwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4IjpmYWxzZSwiTm90ZXMiOiJrTWpUcUNVWnNnS3R0Ym1DN2lhTnAiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDY5NCwiQ3VzdG9tZXIiOnsiSWQiOjY1NTMsIk5hbWUiOiJXWWtnQmRrQktCQjZtZE5WdSAiLCJFbWFpbCI6IlZkMiIsIkNvbXBhbnlOYW1lIjoiQUhyd3VwTUNIVlk0dEFMSjRyYUpVeFQiLCJDcmVhdGVkIjoxNTY1ODAxNDQ3fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTcyMX1dLCJUcmlhbEFjdGl2YXRpb24iOnRydWUsIk1heE5vT2ZNYWNoaW5lcyI6MiwiQWxsb3dlZE1hY2hpbmVzIjoicnJOYWdPdHo0OURcbjZyRXJjXG5YUGN2bHlUSHJMQjlWM0FYS2xzWWVzVCIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDQ0MCwiTmFtZSI6ImVNZHNCQ25tdSIsIlN0cmluZ1ZhbHVlIjoiUW9uZ3o3TTU5ZzQ1WERBcGRrbnhHdXYiLCJJbnRWYWx1ZSI6OTQ1OTAwfSx7IklkIjo0NDQxLCJOYW1lIjoiTWZKNjJYSTVIUzlKR09uRnMiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo2ODc4NTZ9LHsiSWQiOjQ0NDIsIk5hbWUiOiJ4ejNKYm5MS1E4ZldqIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6MjMxODgyfV0sIlNpZ25EYXRlIjoxNTcwNDYxMDAzfQ==";
    saved_response += "-";
    saved_response += "YeOkB4SVgKSLJbiazlDQNE4bWO6j7ncE83jpia/rUtd4dmsLWc0Hs8UcGr7R8eykso2RkrWq0EuBMi8ZEyQ9Y18d+oRajP5D2J1OxwGIrYAvRAWf7nixX1nI66ZMv8I6wmrJXVOuzHLI0NJcwsnBv9bBuzqLwFV2PKGN7OkUP97ZPqEgVdgNlHztt3UKr682UCq2+n3i6aCl5q16nOq9G4nQYYVuZzHgG1OSPVWgdk9mjGq/33ykjG1EEF21k5WqnTVEdymtHc6HeF4dmwTr2LGTNdKMRdMHDMZVqh9036wdf3ept5yfcvoCIs6yAz78m0j33Gezk5Jkw0W/50ojhA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key362() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key362::license_key_;

TEST_F(v20190401_offline_compact_Key362, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801447);
  EXPECT_EQ(license_key->get_expires(), 4285338121);
  EXPECT_EQ(license_key->get_period(), 31476);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key362, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 413); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "ENXUP-EDCPS-QOLSR-OEGQF"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "kMjTqCUZsgKttbmC7iaNp"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 2); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "rrNagOtz49D\n6rErc\nXPcvlyTHrLB9V3AXKlsYesT"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54694); }
}

TEST_F(v20190401_offline_compact_Key362, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811721));

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

TEST_F(v20190401_offline_compact_Key362, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6553);
    EXPECT_EQ(customer.get_name(), "WYkgBdkBKBB6mdNVu ");
    EXPECT_EQ(customer.get_email(), "Vd2");
    EXPECT_EQ(customer.get_company_name(), "AHrwupMCHVY4tALJ4raJUxT");
    EXPECT_EQ(customer.get_created(), 1565801447);
  }
}

TEST_F(v20190401_offline_compact_Key362, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4440, "eMdsBCnmu", "Qongz7M59g45XDApdknxGuv", 945900));
  expected.push_back(cryptolens::DataObject(4441, "MfJ62XI5HS9JGOnFs", "", 687856));
  expected.push_back(cryptolens::DataObject(4442, "xz3JbnLKQ8fWj", "", 231882));

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
