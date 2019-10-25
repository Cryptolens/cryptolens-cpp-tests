#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key487 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "IIERS-EGJSJ-UGSMV-EJBBU", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key487() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key487::license_key_;

TEST_F(v20180502_online_Key487, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801676);
  EXPECT_EQ(license_key->get_expires(), 3499692876);
  EXPECT_EQ(license_key->get_period(), 22382);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20180502_online_Key487, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 538); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IIERS-EGJSJ-UGSMV-EJBBU"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "EHGJ3XOUG0Bwz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "JfXlOLYVec5nbZPTvZj\nWxvbW\nk Gk"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }
}

TEST_F(v20180502_online_Key487, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811805));

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

TEST_F(v20180502_online_Key487, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6626);
    EXPECT_EQ(customer.get_name(), "k4241Ao9ho");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "cXnnVkfHwgo2jioJbfNHoFbH");
    EXPECT_EQ(customer.get_created(), 1565801675);
  }
}

TEST_F(v20180502_online_Key487, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4625, "G86u vd9s", "fM3YzxX0monxHWMmvz", 353582));
  expected.push_back(cryptolens::DataObject(4626, "hhzldkdGQjKL5zg7w", "", 451989));
  expected.push_back(cryptolens::DataObject(4627, "xCzVqPZI LlVUR70bAu", "saJo", 482576));

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

class v20190401_online_Key487 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "IIERS-EGJSJ-UGSMV-EJBBU");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key487() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key487::license_key_;

TEST_F(v20190401_online_Key487, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801676);
  EXPECT_EQ(license_key->get_expires(), 3499692876);
  EXPECT_EQ(license_key->get_period(), 22382);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_online_Key487, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 538); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IIERS-EGJSJ-UGSMV-EJBBU"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "EHGJ3XOUG0Bwz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "JfXlOLYVec5nbZPTvZj\nWxvbW\nk Gk"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }
}

TEST_F(v20190401_online_Key487, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811805));

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

TEST_F(v20190401_online_Key487, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6626);
    EXPECT_EQ(customer.get_name(), "k4241Ao9ho");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "cXnnVkfHwgo2jioJbfNHoFbH");
    EXPECT_EQ(customer.get_created(), 1565801675);
  }
}

TEST_F(v20190401_online_Key487, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4625, "G86u vd9s", "fM3YzxX0monxHWMmvz", 353582));
  expected.push_back(cryptolens::DataObject(4626, "hhzldkdGQjKL5zg7w", "", 451989));
  expected.push_back(cryptolens::DataObject(4627, "xCzVqPZI LlVUR70bAu", "saJo", 482576));

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

class v20190401_offline_json_Key487 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1MzgsIktleSI6IklJRVJTLUVHSlNKLVVHU01WLUVKQkJVIiwiQ3JlYXRlZCI6MTU2NTgwMTY3NiwiRXhwaXJlcyI6MzQ5OTY5Mjg3NiwiUGVyaW9kIjoyMjM4MiwiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2Ijp0cnVlLCJGNyI6dHJ1ZSwiRjgiOmZhbHNlLCJOb3RlcyI6IkVIR0ozWE9VRzBCd3oiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDgxOSwiQ3VzdG9tZXIiOnsiSWQiOjY2MjYsIk5hbWUiOiJrNDI0MUFvOWhvIiwiRW1haWwiOm51bGwsIkNvbXBhbnlOYW1lIjoiY1hublZrZkh3Z28yamlvSmJmTkhvRmJIIiwiQ3JlYXRlZCI6MTU2NTgwMTY3NX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4MDV9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxLCJBbGxvd2VkTWFjaGluZXMiOiJKZlhsT0xZVmVjNW5iWlBUdlpqXG5XeHZiV1xuayBHayIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDYyNSwiTmFtZSI6Ikc4NnUgdmQ5cyIsIlN0cmluZ1ZhbHVlIjoiZk0zWXp4WDBtb254SFdNbXZ6IiwiSW50VmFsdWUiOjM1MzU4Mn0seyJJZCI6NDYyNiwiTmFtZSI6Imhoemxka2RHUWpLTDV6Zzd3IiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NDUxOTg5fSx7IklkIjo0NjI3LCJOYW1lIjoieEN6VnFQWkkgTGxWVVI3MGJBdSIsIlN0cmluZ1ZhbHVlIjoic2FKbyIsIkludFZhbHVlIjo0ODI1NzZ9XSwiU2lnbkRhdGUiOjE1NzA0NjEwNzF9\",\"signature\":\"SW5XVqViWlQctM1xPLmLb7XT/ae8uvvCo6eFGJZHDvjafokKttvX5GDoQ88OQ/0Ls1F4iGet3W2jzZ/fyWB+2un2JWY5HpnNedOLyI6JNd3WUqdx4/m5c4953NAQoEzXLWqH15/G9Wd3W9eqvFg6NRSxZiiOvwFuY2Kz03WKWKmUxi3gCglgRKPNpWzTKqcx1Zp6Z1gZYWzF2Jd7yvQLQM4QdD3s+E5V+Mb04TTrjD84F8k9JnUp57WWuOBeT2b6bEylqehDE5Fe6/ugvE46daPJlUpIKnACJkUuJS0n+B2brNr68s4vELRR4X2g3Y8oxE97lZMTmEw/e0wccvhMzA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key487() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key487::license_key_;

TEST_F(v20190401_offline_json_Key487, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801676);
  EXPECT_EQ(license_key->get_expires(), 3499692876);
  EXPECT_EQ(license_key->get_period(), 22382);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_json_Key487, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 538); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IIERS-EGJSJ-UGSMV-EJBBU"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "EHGJ3XOUG0Bwz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "JfXlOLYVec5nbZPTvZj\nWxvbW\nk Gk"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }
}

TEST_F(v20190401_offline_json_Key487, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811805));

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

TEST_F(v20190401_offline_json_Key487, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6626);
    EXPECT_EQ(customer.get_name(), "k4241Ao9ho");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "cXnnVkfHwgo2jioJbfNHoFbH");
    EXPECT_EQ(customer.get_created(), 1565801675);
  }
}

TEST_F(v20190401_offline_json_Key487, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4625, "G86u vd9s", "fM3YzxX0monxHWMmvz", 353582));
  expected.push_back(cryptolens::DataObject(4626, "hhzldkdGQjKL5zg7w", "", 451989));
  expected.push_back(cryptolens::DataObject(4627, "xCzVqPZI LlVUR70bAu", "saJo", 482576));

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

class v20190401_offline_compact_Key487 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo1MzgsIktleSI6IklJRVJTLUVHSlNKLVVHU01WLUVKQkJVIiwiQ3JlYXRlZCI6MTU2NTgwMTY3NiwiRXhwaXJlcyI6MzQ5OTY5Mjg3NiwiUGVyaW9kIjoyMjM4MiwiRjEiOnRydWUsIkYyIjpmYWxzZSwiRjMiOmZhbHNlLCJGNCI6dHJ1ZSwiRjUiOnRydWUsIkY2Ijp0cnVlLCJGNyI6dHJ1ZSwiRjgiOmZhbHNlLCJOb3RlcyI6IkVIR0ozWE9VRzBCd3oiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NDgxOSwiQ3VzdG9tZXIiOnsiSWQiOjY2MjYsIk5hbWUiOiJrNDI0MUFvOWhvIiwiRW1haWwiOm51bGwsIkNvbXBhbnlOYW1lIjoiY1hublZrZkh3Z28yamlvSmJmTkhvRmJIIiwiQ3JlYXRlZCI6MTU2NTgwMTY3NX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE4MDV9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxLCJBbGxvd2VkTWFjaGluZXMiOiJKZlhsT0xZVmVjNW5iWlBUdlpqXG5XeHZiV1xuayBHayIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDYyNSwiTmFtZSI6Ikc4NnUgdmQ5cyIsIlN0cmluZ1ZhbHVlIjoiZk0zWXp4WDBtb254SFdNbXZ6IiwiSW50VmFsdWUiOjM1MzU4Mn0seyJJZCI6NDYyNiwiTmFtZSI6Imhoemxka2RHUWpLTDV6Zzd3IiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6NDUxOTg5fSx7IklkIjo0NjI3LCJOYW1lIjoieEN6VnFQWkkgTGxWVVI3MGJBdSIsIlN0cmluZ1ZhbHVlIjoic2FKbyIsIkludFZhbHVlIjo0ODI1NzZ9XSwiU2lnbkRhdGUiOjE1NzA0NjEwNzF9";
    saved_response += "-";
    saved_response += "SW5XVqViWlQctM1xPLmLb7XT/ae8uvvCo6eFGJZHDvjafokKttvX5GDoQ88OQ/0Ls1F4iGet3W2jzZ/fyWB+2un2JWY5HpnNedOLyI6JNd3WUqdx4/m5c4953NAQoEzXLWqH15/G9Wd3W9eqvFg6NRSxZiiOvwFuY2Kz03WKWKmUxi3gCglgRKPNpWzTKqcx1Zp6Z1gZYWzF2Jd7yvQLQM4QdD3s+E5V+Mb04TTrjD84F8k9JnUp57WWuOBeT2b6bEylqehDE5Fe6/ugvE46daPJlUpIKnACJkUuJS0n+B2brNr68s4vELRR4X2g3Y8oxE97lZMTmEw/e0wccvhMzA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key487() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key487::license_key_;

TEST_F(v20190401_offline_compact_Key487, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565801676);
  EXPECT_EQ(license_key->get_expires(), 3499692876);
  EXPECT_EQ(license_key->get_period(), 22382);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), true);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), false);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), false);
}

TEST_F(v20190401_offline_compact_Key487, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 538); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "IIERS-EGJSJ-UGSMV-EJBBU"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "EHGJ3XOUG0Bwz"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "JfXlOLYVec5nbZPTvZj\nWxvbW\nk Gk"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54819); }
}

TEST_F(v20190401_offline_compact_Key487, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811805));

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

TEST_F(v20190401_offline_compact_Key487, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6626);
    EXPECT_EQ(customer.get_name(), "k4241Ao9ho");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "cXnnVkfHwgo2jioJbfNHoFbH");
    EXPECT_EQ(customer.get_created(), 1565801675);
  }
}

TEST_F(v20190401_offline_compact_Key487, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4625, "G86u vd9s", "fM3YzxX0monxHWMmvz", 353582));
  expected.push_back(cryptolens::DataObject(4626, "hhzldkdGQjKL5zg7w", "", 451989));
  expected.push_back(cryptolens::DataObject(4627, "xCzVqPZI LlVUR70bAu", "saJo", 482576));

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
