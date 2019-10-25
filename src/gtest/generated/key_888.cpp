#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key888 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "BTEQZ-SVNUC-CIDUJ-DPFMX", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key888() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key888::license_key_;

TEST_F(v20180502_online_Key888, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802542);
  EXPECT_EQ(license_key->get_expires(), 3955117678);
  EXPECT_EQ(license_key->get_period(), 27654);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key888, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 939); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BTEQZ-SVNUC-CIDUJ-DPFMX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "GzGfKPgv"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "G8xTJCMh2a"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }
}

TEST_F(v20180502_online_Key888, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812078));

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

TEST_F(v20180502_online_Key888, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6825);
    EXPECT_EQ(customer.get_name(), "GAnADpg");
    EXPECT_EQ(customer.get_email(), "sMh2UuJBzRZLe3h");
    EXPECT_EQ(customer.get_company_name(), "63HuMiZptVwgdLgLAAx6");
    EXPECT_EQ(customer.get_created(), 1565802541);
  }
}

TEST_F(v20180502_online_Key888, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5229, "uDpgosYk2QPGBqK", "", 497825));
  expected.push_back(cryptolens::DataObject(5230, "c3PYTiLq FsG", "5uJ6e8WCIQf63g76zc4Ke3m", 364504));

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

class v20190401_online_Key888 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "BTEQZ-SVNUC-CIDUJ-DPFMX");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key888() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key888::license_key_;

TEST_F(v20190401_online_Key888, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802542);
  EXPECT_EQ(license_key->get_expires(), 3955117678);
  EXPECT_EQ(license_key->get_period(), 27654);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key888, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 939); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BTEQZ-SVNUC-CIDUJ-DPFMX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "GzGfKPgv"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "G8xTJCMh2a"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }
}

TEST_F(v20190401_online_Key888, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812078));

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

TEST_F(v20190401_online_Key888, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6825);
    EXPECT_EQ(customer.get_name(), "GAnADpg");
    EXPECT_EQ(customer.get_email(), "sMh2UuJBzRZLe3h");
    EXPECT_EQ(customer.get_company_name(), "63HuMiZptVwgdLgLAAx6");
    EXPECT_EQ(customer.get_created(), 1565802541);
  }
}

TEST_F(v20190401_online_Key888, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5229, "uDpgosYk2QPGBqK", "", 497825));
  expected.push_back(cryptolens::DataObject(5230, "c3PYTiLq FsG", "5uJ6e8WCIQf63g76zc4Ke3m", 364504));

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

class v20190401_offline_json_Key888 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MzksIktleSI6IkJURVFaLVNWTlVDLUNJRFVKLURQRk1YIiwiQ3JlYXRlZCI6MTU2NTgwMjU0MiwiRXhwaXJlcyI6Mzk1NTExNzY3OCwiUGVyaW9kIjoyNzY1NCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0Ijp0cnVlLCJGNSI6dHJ1ZSwiRjYiOmZhbHNlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiR3pHZktQZ3YiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTIyMCwiQ3VzdG9tZXIiOnsiSWQiOjY4MjUsIk5hbWUiOiJHQW5BRHBnIiwiRW1haWwiOiJzTWgyVXVKQnpSWkxlM2giLCJDb21wYW55TmFtZSI6IjYzSHVNaVpwdFZ3Z2RMZ0xBQXg2IiwiQ3JlYXRlZCI6MTU2NTgwMjU0MX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTIwNzh9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6Ikc4eFRKQ01oMmEiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUyMjksIk5hbWUiOiJ1RHBnb3NZazJRUEdCcUsiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo0OTc4MjV9LHsiSWQiOjUyMzAsIk5hbWUiOiJjM1BZVGlMcSBGc0ciLCJTdHJpbmdWYWx1ZSI6IjV1SjZlOFdDSVFmNjNnNzZ6YzRLZTNtIiwiSW50VmFsdWUiOjM2NDUwNH1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI5OH0=\",\"signature\":\"MZPao92WTPY3pQyASa0e3kOKiuXrFoNvevHrixA0cZNhdSDVixT9vApXMZGWutGLjbyFetsZJzd8rxrhKCqWONt1KQhIW58ueNMtvAuG1hTkr2oU5l54tFXRIQLku6S8MGQwmNqGqS4n3hJAcw8VgNv1qpIfHT8YnAXkNhAGsXnPD7hE/nwgH8jVfEDS1QzYd35FeamMzrFRJ69CpCC1IHgr+PbGry9yesm5pPgNePhqBpniL30Oqr1n/GQrzTPliUqphYOt0ZQkOWejMT7d7ZDf1Mfi4rcSaTsbXRWuBrG0+x/wj3Uw103w5V2Idu7e9nqjhC644/fl+gZaIaJvsA==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key888() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key888::license_key_;

TEST_F(v20190401_offline_json_Key888, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802542);
  EXPECT_EQ(license_key->get_expires(), 3955117678);
  EXPECT_EQ(license_key->get_period(), 27654);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key888, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 939); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BTEQZ-SVNUC-CIDUJ-DPFMX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "GzGfKPgv"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "G8xTJCMh2a"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }
}

TEST_F(v20190401_offline_json_Key888, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812078));

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

TEST_F(v20190401_offline_json_Key888, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6825);
    EXPECT_EQ(customer.get_name(), "GAnADpg");
    EXPECT_EQ(customer.get_email(), "sMh2UuJBzRZLe3h");
    EXPECT_EQ(customer.get_company_name(), "63HuMiZptVwgdLgLAAx6");
    EXPECT_EQ(customer.get_created(), 1565802541);
  }
}

TEST_F(v20190401_offline_json_Key888, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5229, "uDpgosYk2QPGBqK", "", 497825));
  expected.push_back(cryptolens::DataObject(5230, "c3PYTiLq FsG", "5uJ6e8WCIQf63g76zc4Ke3m", 364504));

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

class v20190401_offline_compact_Key888 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo5MzksIktleSI6IkJURVFaLVNWTlVDLUNJRFVKLURQRk1YIiwiQ3JlYXRlZCI6MTU2NTgwMjU0MiwiRXhwaXJlcyI6Mzk1NTExNzY3OCwiUGVyaW9kIjoyNzY1NCwiRjEiOmZhbHNlLCJGMiI6dHJ1ZSwiRjMiOnRydWUsIkY0Ijp0cnVlLCJGNSI6dHJ1ZSwiRjYiOmZhbHNlLCJGNyI6dHJ1ZSwiRjgiOnRydWUsIk5vdGVzIjoiR3pHZktQZ3YiLCJCbG9jayI6ZmFsc2UsIkdsb2JhbElkIjo1NTIyMCwiQ3VzdG9tZXIiOnsiSWQiOjY4MjUsIk5hbWUiOiJHQW5BRHBnIiwiRW1haWwiOiJzTWgyVXVKQnpSWkxlM2giLCJDb21wYW55TmFtZSI6IjYzSHVNaVpwdFZ3Z2RMZ0xBQXg2IiwiQ3JlYXRlZCI6MTU2NTgwMjU0MX0sIkFjdGl2YXRlZE1hY2hpbmVzIjpbeyJNaWQiOiJhIiwiSVAiOiIxNTguMTc0LjEwLjIxOCIsIlRpbWUiOjE1NjU4MTIwNzh9XSwiVHJpYWxBY3RpdmF0aW9uIjp0cnVlLCJNYXhOb09mTWFjaGluZXMiOjEsIkFsbG93ZWRNYWNoaW5lcyI6Ikc4eFRKQ01oMmEiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjUyMjksIk5hbWUiOiJ1RHBnb3NZazJRUEdCcUsiLCJTdHJpbmdWYWx1ZSI6IiIsIkludFZhbHVlIjo0OTc4MjV9LHsiSWQiOjUyMzAsIk5hbWUiOiJjM1BZVGlMcSBGc0ciLCJTdHJpbmdWYWx1ZSI6IjV1SjZlOFdDSVFmNjNnNzZ6YzRLZTNtIiwiSW50VmFsdWUiOjM2NDUwNH1dLCJTaWduRGF0ZSI6MTU3MDQ2MTI5OH0=";
    saved_response += "-";
    saved_response += "MZPao92WTPY3pQyASa0e3kOKiuXrFoNvevHrixA0cZNhdSDVixT9vApXMZGWutGLjbyFetsZJzd8rxrhKCqWONt1KQhIW58ueNMtvAuG1hTkr2oU5l54tFXRIQLku6S8MGQwmNqGqS4n3hJAcw8VgNv1qpIfHT8YnAXkNhAGsXnPD7hE/nwgH8jVfEDS1QzYd35FeamMzrFRJ69CpCC1IHgr+PbGry9yesm5pPgNePhqBpniL30Oqr1n/GQrzTPliUqphYOt0ZQkOWejMT7d7ZDf1Mfi4rcSaTsbXRWuBrG0+x/wj3Uw103w5V2Idu7e9nqjhC644/fl+gZaIaJvsA==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key888() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key888::license_key_;

TEST_F(v20190401_offline_compact_Key888, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802542);
  EXPECT_EQ(license_key->get_expires(), 3955117678);
  EXPECT_EQ(license_key->get_period(), 27654);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), true);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), true);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), true);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), false);
  EXPECT_EQ(license_key->get_f7(), true);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key888, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 939); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "BTEQZ-SVNUC-CIDUJ-DPFMX"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "GzGfKPgv"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 1); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "G8xTJCMh2a"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55220); }
}

TEST_F(v20190401_offline_compact_Key888, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565812078));

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

TEST_F(v20190401_offline_compact_Key888, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6825);
    EXPECT_EQ(customer.get_name(), "GAnADpg");
    EXPECT_EQ(customer.get_email(), "sMh2UuJBzRZLe3h");
    EXPECT_EQ(customer.get_company_name(), "63HuMiZptVwgdLgLAAx6");
    EXPECT_EQ(customer.get_created(), 1565802541);
  }
}

TEST_F(v20190401_offline_compact_Key888, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(5229, "uDpgosYk2QPGBqK", "", 497825));
  expected.push_back(cryptolens::DataObject(5230, "c3PYTiLq FsG", "5uJ6e8WCIQf63g76zc4Ke3m", 364504));

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
