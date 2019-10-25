#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key875 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "IQRTG-CZWOS-BSHGK-LLXRA", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key875() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key875::license_key_;

TEST_F(v20180502_online_Key875, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802514);
  EXPECT_EQ(license_key->get_expires(), 3584797714);
  EXPECT_EQ(license_key->get_period(), 23367);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key875, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 926); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IQRTG-CZWOS-BSHGK-LLXRA"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "7XtMR"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "zx5YzwujtHu\niNiYRqE\nP"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }
}

TEST_F(v20180502_online_Key875, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812069));

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

TEST_F(v20180502_online_Key875, Customer) {
  EXPECT_FALSE(license_key->get_customer());
}

TEST_F(v20180502_online_Key875, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5213, "UGmFXJv3E5A", "04gz0cK0qmBOL0S", 493809));
  expected.push_back(cryptolens::DataObject(5214, "xLNkKYuL23b0yrnvayt", "", 184948));
  expected.push_back(cryptolens::DataObject(5215, " iSchhq9vogrE0 e uumgQ", "HpK6HxJpxZPz5qxjdOgdlj ", 827120));

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

class v20190401_online_Key875 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "IQRTG-CZWOS-BSHGK-LLXRA");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key875() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key875::license_key_;

TEST_F(v20190401_online_Key875, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802514);
  EXPECT_EQ(license_key->get_expires(), 3584797714);
  EXPECT_EQ(license_key->get_period(), 23367);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key875, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 926); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IQRTG-CZWOS-BSHGK-LLXRA"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "7XtMR"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "zx5YzwujtHu\niNiYRqE\nP"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }
}

TEST_F(v20190401_online_Key875, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812069));

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

TEST_F(v20190401_online_Key875, Customer) {
  EXPECT_FALSE(license_key->get_customer());
}

TEST_F(v20190401_online_Key875, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5213, "UGmFXJv3E5A", "04gz0cK0qmBOL0S", 493809));
  expected.push_back(cryptolens::DataObject(5214, "xLNkKYuL23b0yrnvayt", "", 184948));
  expected.push_back(cryptolens::DataObject(5215, " iSchhq9vogrE0 e uumgQ", "HpK6HxJpxZPz5qxjdOgdlj ", 827120));

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

class v20190401_offline_json_Key875 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MjYsIktleSI6IklRUlRHLUNaV09TLUJTSEdLLUxMWFJBIiwiQ3JlYXRlZCI6MTU2NTgwMjUxNCwiRXhwaXJlcyI6MzU4NDc5NzcxNCwiUGVyaW9kIjoyMzM2NywiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6IjdYdE1SIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUyMDcsIkN1c3RvbWVyIjpudWxsLCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODEyMDY5fV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoieng1WXp3dWp0SHVcbmlOaVlScUVcblAiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUyMTMsIk5hbWUiOiJVR21GWEp2M0U1QSIsIlN0cmluZ1ZhbHVlIjoiMDRnejBjSzBxbUJPTDBTIiwiSW50VmFsdWUiOjQ5MzgwOX0seyJJZCI6NTIxNCwiTmFtZSI6InhMTmtLWXVMMjNiMHlybnZheXQiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjoxODQ5NDh9LHsiSWQiOjUyMTUsIk5hbWUiOiIgaVNjaGhxOXZvZ3JFMCBlIHV1bWdRIiwiU3RyaW5nVmFsdWUiOiJIcEs2SHhKcHhaUHo1cXhqZE9nZGxqICIsIkludFZhbHVlIjo4MjcxMjB9XSwiU2lnbkRhdGUiOjE1NzA0NjEyOTF9\",\"signature\":\"LWGIrJRrlqbPiw/q+mqJmH85FI8HkKQc2Z8yLCx2og24a295by92uzngBguXBGrVQB3XhC6EdVRHAVnY5p3v179RX5L5w89HaRRJZ4WHWz4xAX1t5wMs7BB6c4/oI+HlGsQfHEsMJqKy1xWd3hwpk/ipsyUBYcA9gIONcrJFKTng//JAPzENw/+hpLoOwTj/GJfOmGjQ7h1iAApBeznfHsF5+CizAEvyCgVk/1P6fx2fUUHU0w16oZ21nHf3lYtH1Tk2HVtPR14oMptDUcY+5fFjbBoVRdj9b0EInFzgWDBDZ4MxZkfOPwKqfwJfulHOJUw1wXGG4Hm8J5aP3ABumQ==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key875() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key875::license_key_;

TEST_F(v20190401_offline_json_Key875, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802514);
  EXPECT_EQ(license_key->get_expires(), 3584797714);
  EXPECT_EQ(license_key->get_period(), 23367);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key875, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 926); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IQRTG-CZWOS-BSHGK-LLXRA"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "7XtMR"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "zx5YzwujtHu\niNiYRqE\nP"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }
}

TEST_F(v20190401_offline_json_Key875, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812069));

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

TEST_F(v20190401_offline_json_Key875, Customer) {
  EXPECT_FALSE(license_key->get_customer());
}

TEST_F(v20190401_offline_json_Key875, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5213, "UGmFXJv3E5A", "04gz0cK0qmBOL0S", 493809));
  expected.push_back(cryptolens::DataObject(5214, "xLNkKYuL23b0yrnvayt", "", 184948));
  expected.push_back(cryptolens::DataObject(5215, " iSchhq9vogrE0 e uumgQ", "HpK6HxJpxZPz5qxjdOgdlj ", 827120));

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

class v20190401_offline_compact_Key875 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MjYsIktleSI6IklRUlRHLUNaV09TLUJTSEdLLUxMWFJBIiwiQ3JlYXRlZCI6MTU2NTgwMjUxNCwiRXhwaXJlcyI6MzU4NDc5NzcxNCwiUGVyaW9kIjoyMzM2NywiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2IjpmYWxzZSwiRjciOnRydWUsIkY4Ijp0cnVlLCJOb3RlcyI6IjdYdE1SIiwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6NTUyMDcsIkN1c3RvbWVyIjpudWxsLCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiYSIsIklQIjoiMTU4LjE3NC4xMC4yMTgiLCJUaW1lIjoxNTY1ODEyMDY5fV0sIlRyaWFsQWN0aXZhdGlvbiI6ZmFsc2UsIk1heE5vT2ZNYWNoaW5lcyI6MywiQWxsb3dlZE1hY2hpbmVzIjoieng1WXp3dWp0SHVcbmlOaVlScUVcblAiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUyMTMsIk5hbWUiOiJVR21GWEp2M0U1QSIsIlN0cmluZ1ZhbHVlIjoiMDRnejBjSzBxbUJPTDBTIiwiSW50VmFsdWUiOjQ5MzgwOX0seyJJZCI6NTIxNCwiTmFtZSI6InhMTmtLWXVMMjNiMHlybnZheXQiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjoxODQ5NDh9LHsiSWQiOjUyMTUsIk5hbWUiOiIgaVNjaGhxOXZvZ3JFMCBlIHV1bWdRIiwiU3RyaW5nVmFsdWUiOiJIcEs2SHhKcHhaUHo1cXhqZE9nZGxqICIsIkludFZhbHVlIjo4MjcxMjB9XSwiU2lnbkRhdGUiOjE1NzA0NjEyOTF9";
    saved_response += "-";
    saved_response += "LWGIrJRrlqbPiw/q+mqJmH85FI8HkKQc2Z8yLCx2og24a295by92uzngBguXBGrVQB3XhC6EdVRHAVnY5p3v179RX5L5w89HaRRJZ4WHWz4xAX1t5wMs7BB6c4/oI+HlGsQfHEsMJqKy1xWd3hwpk/ipsyUBYcA9gIONcrJFKTng//JAPzENw/+hpLoOwTj/GJfOmGjQ7h1iAApBeznfHsF5+CizAEvyCgVk/1P6fx2fUUHU0w16oZ21nHf3lYtH1Tk2HVtPR14oMptDUcY+5fFjbBoVRdj9b0EInFzgWDBDZ4MxZkfOPwKqfwJfulHOJUw1wXGG4Hm8J5aP3ABumQ==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key875() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key875::license_key_;

TEST_F(v20190401_offline_compact_Key875, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802514);
  EXPECT_EQ(license_key->get_expires(), 3584797714);
  EXPECT_EQ(license_key->get_period(), 23367);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key875, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 926); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IQRTG-CZWOS-BSHGK-LLXRA"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "7XtMR"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 3); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "zx5YzwujtHu\niNiYRqE\nP"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55207); }
}

TEST_F(v20190401_offline_compact_Key875, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812069));

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

TEST_F(v20190401_offline_compact_Key875, Customer) {
  EXPECT_FALSE(license_key->get_customer());
}

TEST_F(v20190401_offline_compact_Key875, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5213, "UGmFXJv3E5A", "04gz0cK0qmBOL0S", 493809));
  expected.push_back(cryptolens::DataObject(5214, "xLNkKYuL23b0yrnvayt", "", 184948));
  expected.push_back(cryptolens::DataObject(5215, " iSchhq9vogrE0 e uumgQ", "HpK6HxJpxZPz5qxjdOgdlj ", 827120));

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
