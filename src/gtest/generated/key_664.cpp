#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key664 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "DGMEB-MOHWO-QESLK-DHDAX", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key664() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key664::license_key_;

TEST_F(v20180502_online_Key664, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802039);
  EXPECT_EQ(license_key->get_expires(), 4228141528);
  EXPECT_EQ(license_key->get_period(), 30814);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key664, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 715); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DGMEB-MOHWO-QESLK-DHDAX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "046qsplDyOmvWWTX9FiTixd"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "buBf6TsCLZPja7oZ1\n3S\nrXkyERwCDYDAh Sf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }
}

TEST_F(v20180502_online_Key664, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811928));

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

TEST_F(v20180502_online_Key664, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6712);
    EXPECT_EQ(customer.get_name(), "ZOjb3YNm40qRiXXu0APSxhH");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "Wc0Vq2YHzmrNcJB6sF");
    EXPECT_EQ(customer.get_created(), 1565802038);
  }
}

TEST_F(v20180502_online_Key664, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4888, "t5TE07", "", 496123));
  expected.push_back(cryptolens::DataObject(4889, " fdLUCVpvskPsh7", "", 513741));

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

class v20190401_online_Key664 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "DGMEB-MOHWO-QESLK-DHDAX");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key664() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key664::license_key_;

TEST_F(v20190401_online_Key664, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802039);
  EXPECT_EQ(license_key->get_expires(), 4228141528);
  EXPECT_EQ(license_key->get_period(), 30814);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key664, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 715); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DGMEB-MOHWO-QESLK-DHDAX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "046qsplDyOmvWWTX9FiTixd"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "buBf6TsCLZPja7oZ1\n3S\nrXkyERwCDYDAh Sf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }
}

TEST_F(v20190401_online_Key664, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811928));

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

TEST_F(v20190401_online_Key664, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6712);
    EXPECT_EQ(customer.get_name(), "ZOjb3YNm40qRiXXu0APSxhH");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "Wc0Vq2YHzmrNcJB6sF");
    EXPECT_EQ(customer.get_created(), 1565802038);
  }
}

TEST_F(v20190401_online_Key664, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4888, "t5TE07", "", 496123));
  expected.push_back(cryptolens::DataObject(4889, " fdLUCVpvskPsh7", "", 513741));

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

class v20190401_offline_json_Key664 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3MTUsIktleSI6IkRHTUVCLU1PSFdPLVFFU0xLLURIREFYIiwiQ3JlYXRlZCI6MTU2NTgwMjAzOSwiRXhwaXJlcyI6NDIyODE0MTUyOCwiUGVyaW9kIjozMDgxNCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIwNDZxc3BsRHlPbXZXV1RYOUZpVGl4ZCIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0OTk2LCJDdXN0b21lciI6eyJJZCI6NjcxMiwiTmFtZSI6IlpPamIzWU5tNDBxUmlYWHUwQVBTeGhIIiwiRW1haWwiOm51bGwsIkNvbXBhbnlOYW1lIjoiV2MwVnEyWUh6bXJOY0pCNnNGIiwiQ3JlYXRlZCI6MTU2NTgwMjAzOH0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE5Mjh9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjUsIkFsbG93ZWRNYWNoaW5lcyI6ImJ1QmY2VHNDTFpQamE3b1oxXG4zU1xuclhreUVSd0NEWURBaCBTZiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDg4OCwiTmFtZSI6InQ1VEUwNyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ5NjEyM30seyJJZCI6NDg4OSwiTmFtZSI6IiBmZExVQ1ZwdnNrUHNoNyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjUxMzc0MX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTE3MH0=\",\"signature\":\"crke3r64NL/91TEUa2kFRBlt+pWOpaoHRwbTjcH4DolJ7U45s3tUwX82WQ43nTXmvUpwUYE24qrWn4c8au+2cLjgdso8hlbbON+imSunidSwEipU3qRLrtGqh6UJwu49NaKNKAkNYtSd9CAzyapZhBXoezy/YTspAyMbFBgTGSSteSKI9i1yVZcdNUoAidsOe/uLaVTjs7nEm5xNIyiClsVdPtnC7ghJ6+s3yaZhJMiCrQXo1Ofj32gToQR7cLGnp9bi17DeZQVG5oAAXzAUCDdDJo0b8FQraBcs03RN76EhmLsLHh3ZzFiRlaJ/Tqn28e9pGKRG77zGrxGKuu1TpA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key664() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key664::license_key_;

TEST_F(v20190401_offline_json_Key664, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802039);
  EXPECT_EQ(license_key->get_expires(), 4228141528);
  EXPECT_EQ(license_key->get_period(), 30814);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key664, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 715); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DGMEB-MOHWO-QESLK-DHDAX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "046qsplDyOmvWWTX9FiTixd"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "buBf6TsCLZPja7oZ1\n3S\nrXkyERwCDYDAh Sf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }
}

TEST_F(v20190401_offline_json_Key664, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811928));

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

TEST_F(v20190401_offline_json_Key664, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6712);
    EXPECT_EQ(customer.get_name(), "ZOjb3YNm40qRiXXu0APSxhH");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "Wc0Vq2YHzmrNcJB6sF");
    EXPECT_EQ(customer.get_created(), 1565802038);
  }
}

TEST_F(v20190401_offline_json_Key664, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4888, "t5TE07", "", 496123));
  expected.push_back(cryptolens::DataObject(4889, " fdLUCVpvskPsh7", "", 513741));

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

class v20190401_offline_compact_Key664 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3MTUsIktleSI6IkRHTUVCLU1PSFdPLVFFU0xLLURIREFYIiwiQ3JlYXRlZCI6MTU2NTgwMjAzOSwiRXhwaXJlcyI6NDIyODE0MTUyOCwiUGVyaW9kIjozMDgxNCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIwNDZxc3BsRHlPbXZXV1RYOUZpVGl4ZCIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU0OTk2LCJDdXN0b21lciI6eyJJZCI6NjcxMiwiTmFtZSI6IlpPamIzWU5tNDBxUmlYWHUwQVBTeGhIIiwiRW1haWwiOm51bGwsIkNvbXBhbnlOYW1lIjoiV2MwVnEyWUh6bXJOY0pCNnNGIiwiQ3JlYXRlZCI6MTU2NTgwMjAzOH0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTE5Mjh9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjUsIkFsbG93ZWRNYWNoaW5lcyI6ImJ1QmY2VHNDTFpQamE3b1oxXG4zU1xuclhreUVSd0NEWURBaCBTZiIsIkRhdGFPYmplY3RzIjpbeyJJZCI6NDg4OCwiTmFtZSI6InQ1VEUwNyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjQ5NjEyM30seyJJZCI6NDg4OSwiTmFtZSI6IiBmZExVQ1ZwdnNrUHNoNyIsIlN0cmluZ1ZhbHVlIjoiIiwiSW50VmFsdWUiOjUxMzc0MX1dLCJTaWduRGF0ZSI6MTU3MDQ2MTE3MH0=";
    saved_response += "-";
    saved_response += "crke3r64NL/91TEUa2kFRBlt+pWOpaoHRwbTjcH4DolJ7U45s3tUwX82WQ43nTXmvUpwUYE24qrWn4c8au+2cLjgdso8hlbbON+imSunidSwEipU3qRLrtGqh6UJwu49NaKNKAkNYtSd9CAzyapZhBXoezy/YTspAyMbFBgTGSSteSKI9i1yVZcdNUoAidsOe/uLaVTjs7nEm5xNIyiClsVdPtnC7ghJ6+s3yaZhJMiCrQXo1Ofj32gToQR7cLGnp9bi17DeZQVG5oAAXzAUCDdDJo0b8FQraBcs03RN76EhmLsLHh3ZzFiRlaJ/Tqn28e9pGKRG77zGrxGKuu1TpA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key664() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key664::license_key_;

TEST_F(v20190401_offline_compact_Key664, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802039);
  EXPECT_EQ(license_key->get_expires(), 4228141528);
  EXPECT_EQ(license_key->get_period(), 30814);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), false);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key664, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 715); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "DGMEB-MOHWO-QESLK-DHDAX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "046qsplDyOmvWWTX9FiTixd"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 5); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "buBf6TsCLZPja7oZ1\n3S\nrXkyERwCDYDAh Sf"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 54996); }
}

TEST_F(v20190401_offline_compact_Key664, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811928));

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

TEST_F(v20190401_offline_compact_Key664, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6712);
    EXPECT_EQ(customer.get_name(), "ZOjb3YNm40qRiXXu0APSxhH");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "Wc0Vq2YHzmrNcJB6sF");
    EXPECT_EQ(customer.get_created(), 1565802038);
  }
}

TEST_F(v20190401_offline_compact_Key664, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4888, "t5TE07", "", 496123));
  expected.push_back(cryptolens::DataObject(4889, " fdLUCVpvskPsh7", "", 513741));

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
