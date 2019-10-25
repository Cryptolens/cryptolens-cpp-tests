#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key8 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "KGXYK-HHMWU-JOCST-RDAID", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key8() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key8::license_key_;

TEST_F(v20180502_online_Key8, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565800988);
  EXPECT_EQ(license_key->get_expires(), 4665228188);
  EXPECT_EQ(license_key->get_period(), 35872);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key8, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 59); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "KGXYK-HHMWU-JOCST-RDAID"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "pvvHCs3IA Xh SkDV0pcM4pR2"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "kVb5KOlq0h\nHvZ0rF\nuQkRk1lapkeUByK6Y3oC"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }
}

TEST_F(v20180502_online_Key8, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811496));

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

TEST_F(v20180502_online_Key8, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6397);
    EXPECT_EQ(customer.get_name(), "WR116");
    EXPECT_EQ(customer.get_email(), "ps2");
    EXPECT_EQ(customer.get_company_name(), "oldwKqA0u9Gu");
    EXPECT_EQ(customer.get_created(), 1565800988);
  }
}

TEST_F(v20180502_online_Key8, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(3881, "oMq4c9qP8fML4FVpIFK30B4", "gr8TM0rlI2nPX0iJ", 719211));
  expected.push_back(cryptolens::DataObject(3882, "QTvqJORM9wEhArCjrzPr6YI", "", 526987));
  expected.push_back(cryptolens::DataObject(3883, "o4C6ohkWpZyLk", "BwYAFy57O6G43qusedX8lR4G", 903988));

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

class v20190401_online_Key8 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "KGXYK-HHMWU-JOCST-RDAID");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key8() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key8::license_key_;

TEST_F(v20190401_online_Key8, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565800988);
  EXPECT_EQ(license_key->get_expires(), 4665228188);
  EXPECT_EQ(license_key->get_period(), 35872);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key8, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 59); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "KGXYK-HHMWU-JOCST-RDAID"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "pvvHCs3IA Xh SkDV0pcM4pR2"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "kVb5KOlq0h\nHvZ0rF\nuQkRk1lapkeUByK6Y3oC"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }
}

TEST_F(v20190401_online_Key8, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811496));

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

TEST_F(v20190401_online_Key8, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6397);
    EXPECT_EQ(customer.get_name(), "WR116");
    EXPECT_EQ(customer.get_email(), "ps2");
    EXPECT_EQ(customer.get_company_name(), "oldwKqA0u9Gu");
    EXPECT_EQ(customer.get_created(), 1565800988);
  }
}

TEST_F(v20190401_online_Key8, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(3881, "oMq4c9qP8fML4FVpIFK30B4", "gr8TM0rlI2nPX0iJ", 719211));
  expected.push_back(cryptolens::DataObject(3882, "QTvqJORM9wEhArCjrzPr6YI", "", 526987));
  expected.push_back(cryptolens::DataObject(3883, "o4C6ohkWpZyLk", "BwYAFy57O6G43qusedX8lR4G", 903988));

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

class v20190401_offline_json_Key8 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1OSwiS2V5IjoiS0dYWUstSEhNV1UtSk9DU1QtUkRBSUQiLCJDcmVhdGVkIjoxNTY1ODAwOTg4LCJFeHBpcmVzIjo0NjY1MjI4MTg4LCJQZXJpb2QiOjM1ODcyLCJGMSI6ZmFsc2UsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3IjpmYWxzZSwiRjgiOmZhbHNlLCJOb3RlcyI6InB2dkhDczNJQSBYaCBTa0RWMHBjTTRwUjIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDMzOSwiQ3VzdG9tZXIiOnsiSWQiOjYzOTcsIk5hbWUiOiJXUjExNiIsIkVtYWlsIjoicHMyIiwiQ29tcGFueU5hbWUiOiJvbGR3S3FBMHU5R3UiLCJDcmVhdGVkIjoxNTY1ODAwOTg4fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTQ5Nn1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjUsIkFsbG93ZWRNYWNoaW5lcyI6ImtWYjVLT2xxMGhcbkh2WjByRlxudVFrUmsxbGFwa2VVQnlLNlkzb0MiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjM4ODEsIk5hbWUiOiJvTXE0YzlxUDhmTUw0RlZwSUZLMzBCNCIsIlN0cmluZ1ZhbHVlIjoiZ3I4VE0wcmxJMm5QWDBpSiIsIkludFZhbHVlIjo3MTkyMTF9LHsiSWQiOjM4ODIsIk5hbWUiOiJRVHZxSk9STTl3RWhBckNqcnpQcjZZSSIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjUyNjk4N30seyJJZCI6Mzg4MywiTmFtZSI6Im80QzZvaGtXcFp5TGsiLCJTdHJpbmdWYWx1ZSI6IkJ3WUFGeTU3TzZHNDNxdXNlZFg4bFI0RyIsIkludFZhbHVlIjo5MDM5ODh9XSwiU2lnbkRhdGUiOjE1NzA0NjA4MjB9\",\"signature\":\"fWChtBiUEq6Gg4zQCwoeDqRQ4BSYAPKz58nov7lyPMGi77pKkdI3ctxy+3FXMZGFdJRyQZHABR4H3XaBjuT7vuJR3QMo0g6uVUIpTcj/KmL8zVbduvjtXue55SY7Za5xGwowm6btwXffC1bnVT6TOfpO9ORkGnn9sjluGdP6xgnOaGqWZJVElz5qe/j4EXdl/prCF8XtSkDE4pStbzv3UzeN8GtC8H2v2FfYHVxfBGu51GwOe9hnQmASh0uYQM3FEw7wOuSbaylHIiv8ZDTNokANUoEmRpI18+9hRj00CUPJg0/in+8tCg0FnxG+gKfgZdWOHcpGo91NXkoipaKAbA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key8() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key8::license_key_;

TEST_F(v20190401_offline_json_Key8, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565800988);
  EXPECT_EQ(license_key->get_expires(), 4665228188);
  EXPECT_EQ(license_key->get_period(), 35872);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key8, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 59); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "KGXYK-HHMWU-JOCST-RDAID"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "pvvHCs3IA Xh SkDV0pcM4pR2"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "kVb5KOlq0h\nHvZ0rF\nuQkRk1lapkeUByK6Y3oC"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }
}

TEST_F(v20190401_offline_json_Key8, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811496));

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

TEST_F(v20190401_offline_json_Key8, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6397);
    EXPECT_EQ(customer.get_name(), "WR116");
    EXPECT_EQ(customer.get_email(), "ps2");
    EXPECT_EQ(customer.get_company_name(), "oldwKqA0u9Gu");
    EXPECT_EQ(customer.get_created(), 1565800988);
  }
}

TEST_F(v20190401_offline_json_Key8, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(3881, "oMq4c9qP8fML4FVpIFK30B4", "gr8TM0rlI2nPX0iJ", 719211));
  expected.push_back(cryptolens::DataObject(3882, "QTvqJORM9wEhArCjrzPr6YI", "", 526987));
  expected.push_back(cryptolens::DataObject(3883, "o4C6ohkWpZyLk", "BwYAFy57O6G43qusedX8lR4G", 903988));

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

class v20190401_offline_compact_Key8 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1OSwiS2V5IjoiS0dYWUstSEhNV1UtSk9DU1QtUkRBSUQiLCJDcmVhdGVkIjoxNTY1ODAwOTg4LCJFeHBpcmVzIjo0NjY1MjI4MTg4LCJQZXJpb2QiOjM1ODcyLCJGMSI6ZmFsc2UsIkYyIjp0cnVlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3IjpmYWxzZSwiRjgiOmZhbHNlLCJOb3RlcyI6InB2dkhDczNJQSBYaCBTa0RWMHBjTTRwUjIiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDMzOSwiQ3VzdG9tZXIiOnsiSWQiOjYzOTcsIk5hbWUiOiJXUjExNiIsIkVtYWlsIjoicHMyIiwiQ29tcGFueU5hbWUiOiJvbGR3S3FBMHU5R3UiLCJDcmVhdGVkIjoxNTY1ODAwOTg4fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTQ5Nn1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjUsIkFsbG93ZWRNYWNoaW5lcyI6ImtWYjVLT2xxMGhcbkh2WjByRlxudVFrUmsxbGFwa2VVQnlLNlkzb0MiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjM4ODEsIk5hbWUiOiJvTXE0YzlxUDhmTUw0RlZwSUZLMzBCNCIsIlN0cmluZ1ZhbHVlIjoiZ3I4VE0wcmxJMm5QWDBpSiIsIkludFZhbHVlIjo3MTkyMTF9LHsiSWQiOjM4ODIsIk5hbWUiOiJRVHZxSk9STTl3RWhBckNqcnpQcjZZSSIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjUyNjk4N30seyJJZCI6Mzg4MywiTmFtZSI6Im80QzZvaGtXcFp5TGsiLCJTdHJpbmdWYWx1ZSI6IkJ3WUFGeTU3TzZHNDNxdXNlZFg4bFI0RyIsIkludFZhbHVlIjo5MDM5ODh9XSwiU2lnbkRhdGUiOjE1NzA0NjA4MjB9";
    saved_response += "-";
    saved_response += "fWChtBiUEq6Gg4zQCwoeDqRQ4BSYAPKz58nov7lyPMGi77pKkdI3ctxy+3FXMZGFdJRyQZHABR4H3XaBjuT7vuJR3QMo0g6uVUIpTcj/KmL8zVbduvjtXue55SY7Za5xGwowm6btwXffC1bnVT6TOfpO9ORkGnn9sjluGdP6xgnOaGqWZJVElz5qe/j4EXdl/prCF8XtSkDE4pStbzv3UzeN8GtC8H2v2FfYHVxfBGu51GwOe9hnQmASh0uYQM3FEw7wOuSbaylHIiv8ZDTNokANUoEmRpI18+9hRj00CUPJg0/in+8tCg0FnxG+gKfgZdWOHcpGo91NXkoipaKAbA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key8() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key8::license_key_;

TEST_F(v20190401_offline_compact_Key8, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565800988);
  EXPECT_EQ(license_key->get_expires(), 4665228188);
  EXPECT_EQ(license_key->get_period(), 35872);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key8, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 59); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "KGXYK-HHMWU-JOCST-RDAID"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "pvvHCs3IA Xh SkDV0pcM4pR2"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "kVb5KOlq0h\nHvZ0rF\nuQkRk1lapkeUByK6Y3oC"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54339); }
}

TEST_F(v20190401_offline_compact_Key8, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811496));

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

TEST_F(v20190401_offline_compact_Key8, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6397);
    EXPECT_EQ(customer.get_name(), "WR116");
    EXPECT_EQ(customer.get_email(), "ps2");
    EXPECT_EQ(customer.get_company_name(), "oldwKqA0u9Gu");
    EXPECT_EQ(customer.get_created(), 1565800988);
  }
}

TEST_F(v20190401_offline_compact_Key8, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(3881, "oMq4c9qP8fML4FVpIFK30B4", "gr8TM0rlI2nPX0iJ", 719211));
  expected.push_back(cryptolens::DataObject(3882, "QTvqJORM9wEhArCjrzPr6YI", "", 526987));
  expected.push_back(cryptolens::DataObject(3883, "o4C6ohkWpZyLk", "BwYAFy57O6G43qusedX8lR4G", 903988));

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
