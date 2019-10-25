#include <cryptolens/tests/gtest_shared.hpp>
#include <gtest/gtest.h>

namespace tests_v20180502 {

class v20180502_online_Key723 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    Cryptolens cryptolens_handle;
    cryptolens::Error e;
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", "4848", "HJDEC-HSNBA-HHVCD-ATQEG", "a");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20180502_online_Key723() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20180502_online_Key723::license_key_;

TEST_F(v20180502_online_Key723, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802169);
  EXPECT_EQ(license_key->get_expires(), 4198150969);
  EXPECT_EQ(license_key->get_period(), 30466);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20180502_online_Key723, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 774); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HJDEC-HSNBA-HHVCD-ATQEG"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "3Nk8fKqE"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "0OO4LgomuFNbr271osOfENh\nVoiu3LsuQW02"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }
}

TEST_F(v20180502_online_Key723, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811965));

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

TEST_F(v20180502_online_Key723, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6743);
    EXPECT_EQ(customer.get_name(), "ip2pA1zwHqAVz");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "QFGnal2fRK06");
    EXPECT_EQ(customer.get_created(), 1565802168);
  }
}

TEST_F(v20180502_online_Key723, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4984, "oW9bZT0lruECvIEdFCMsC0ybS", "EcaBvqxtdoUearncSJ", 409159));
  expected.push_back(cryptolens::DataObject(4985, "EOt5dPh6Oqeizko", "", 956680));
  expected.push_back(cryptolens::DataObject(4986, "b pUY0C", "icwqn3foCf ", 776980));

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

class v20190401_online_Key723 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    license_key_ = cryptolens_handle.activate(e, "WyI3NzkxIiwiSkV6QmE3TVFDSU5jSmdSQXNwZXdCdnZSODNGeitQYnNDVDltckVvUSJd", 4848, "HJDEC-HSNBA-HHVCD-ATQEG");

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_online_Key723() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_online_Key723::license_key_;

TEST_F(v20190401_online_Key723, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802169);
  EXPECT_EQ(license_key->get_expires(), 4198150969);
  EXPECT_EQ(license_key->get_period(), 30466);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_online_Key723, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 774); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HJDEC-HSNBA-HHVCD-ATQEG"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "3Nk8fKqE"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "0OO4LgomuFNbr271osOfENh\nVoiu3LsuQW02"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }
}

TEST_F(v20190401_online_Key723, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811965));

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

TEST_F(v20190401_online_Key723, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6743);
    EXPECT_EQ(customer.get_name(), "ip2pA1zwHqAVz");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "QFGnal2fRK06");
    EXPECT_EQ(customer.get_created(), 1565802168);
  }
}

TEST_F(v20190401_online_Key723, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4984, "oW9bZT0lruECvIEdFCMsC0ybS", "EcaBvqxtdoUearncSJ", 409159));
  expected.push_back(cryptolens::DataObject(4985, "EOt5dPh6Oqeizko", "", 956680));
  expected.push_back(cryptolens::DataObject(4986, "b pUY0C", "icwqn3foCf ", 776980));

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

class v20190401_offline_json_Key723 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NzQsIktleSI6IkhKREVDLUhTTkJBLUhIVkNELUFUUUVHIiwiQ3JlYXRlZCI6MTU2NTgwMjE2OSwiRXhwaXJlcyI6NDE5ODE1MDk2OSwiUGVyaW9kIjozMDQ2NiwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjp0cnVlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIzTms4ZktxRSIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MDU1LCJDdXN0b21lciI6eyJJZCI6Njc0MywiTmFtZSI6ImlwMnBBMXp3SHFBVnoiLCJFbWFpbCI6bnVsbCwiQ29tcGFueU5hbWUiOiJRRkduYWwyZlJLMDYiLCJDcmVhdGVkIjoxNTY1ODAyMTY4fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTk2NX1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjQsIkFsbG93ZWRNYWNoaW5lcyI6IjBPTzRMZ29tdUZOYnIyNzFvc09mRU5oXG5Wb2l1M0xzdVFXMDIiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQ5ODQsIk5hbWUiOiJvVzliWlQwbHJ1RUN2SUVkRkNNc0MweWJTIiwiU3RyaW5nVmFsdWUiOiJFY2FCdnF4dGRvVWVhcm5jU0oiLCJJbnRWYWx1ZSI6NDA5MTU5fSx7IklkIjo0OTg1LCJOYW1lIjoiRU90NWRQaDZPcWVpemtvIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6OTU2NjgwfSx7IklkIjo0OTg2LCJOYW1lIjoiYiBwVVkwQyIsIlN0cmluZ1ZhbHVlIjoiaWN3cW4zZm9DZiAiLCJJbnRWYWx1ZSI6Nzc2OTgwfV0sIlNpZ25EYXRlIjoxNTcwNDYxMjAzfQ==\",\"signature\":\"H0VrpKC6aBmtQ7NbfQ42DNyfyu6HpyschBz5dsulnqVhFNbITADuM2Vp7Dg9udJV87ppr8QSJBtYiFur6InjrJ/mXplY0G/D4sq40CGTwuJ8f7JVPIvGSAd2TnIGNjp5m2dr1JwgzAh5ntdE4j8NvfytU38iHOIbdS0NN12njO+v7+tjxHk6RFTAFtftSwwch7BP7jH1itFZ33/ygk8IfF7qIys7yWdpxEMep3qAB1rYZ91bKFYh9VD9qgWo+xY8KNpqgOTElWDlbvv5Ul6YShP99TYFR4GmEzHQtXN/sslnuvQn3PgeKkIOzt2QKDCxvQawDJFybFw+C0YfMqnYjw==\",\"result\":0,\"message\":\"\"}");

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_json_Key723() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_json_Key723::license_key_;

TEST_F(v20190401_offline_json_Key723, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802169);
  EXPECT_EQ(license_key->get_expires(), 4198150969);
  EXPECT_EQ(license_key->get_period(), 30466);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_json_Key723, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 774); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HJDEC-HSNBA-HHVCD-ATQEG"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "3Nk8fKqE"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "0OO4LgomuFNbr271osOfENh\nVoiu3LsuQW02"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }
}

TEST_F(v20190401_offline_json_Key723, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811965));

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

TEST_F(v20190401_offline_json_Key723, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6743);
    EXPECT_EQ(customer.get_name(), "ip2pA1zwHqAVz");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "QFGnal2fRK06");
    EXPECT_EQ(customer.get_created(), 1565802168);
  }
}

TEST_F(v20190401_offline_json_Key723, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4984, "oW9bZT0lruECvIEdFCMsC0ybS", "EcaBvqxtdoUearncSJ", 409159));
  expected.push_back(cryptolens::DataObject(4985, "EOt5dPh6Oqeizko", "", 956680));
  expected.push_back(cryptolens::DataObject(4986, "b pUY0C", "icwqn3foCf ", 776980));

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

class v20190401_offline_compact_Key723 : public ::testing::Test {
protected:
  static void SetUpTestCase() {
    cryptolens::Error e;
    Cryptolens cryptolens_handle(e);
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");

    std::string saved_response("v20180502-");
    saved_response += "eyJQcm9kdWN0SWQiOjQ4NDgsIklEIjo3NzQsIktleSI6IkhKREVDLUhTTkJBLUhIVkNELUFUUUVHIiwiQ3JlYXRlZCI6MTU2NTgwMjE2OSwiRXhwaXJlcyI6NDE5ODE1MDk2OSwiUGVyaW9kIjozMDQ2NiwiRjEiOmZhbHNlLCJGMiI6ZmFsc2UsIkYzIjp0cnVlLCJGNCI6ZmFsc2UsIkY1Ijp0cnVlLCJGNiI6dHJ1ZSwiRjciOmZhbHNlLCJGOCI6dHJ1ZSwiTm90ZXMiOiIzTms4ZktxRSIsIkJsb2NrIjpmYWxzZSwiR2xvYmFsSWQiOjU1MDU1LCJDdXN0b21lciI6eyJJZCI6Njc0MywiTmFtZSI6ImlwMnBBMXp3SHFBVnoiLCJFbWFpbCI6bnVsbCwiQ29tcGFueU5hbWUiOiJRRkduYWwyZlJLMDYiLCJDcmVhdGVkIjoxNTY1ODAyMTY4fSwiQWN0aXZhdGVkTWFjaGluZXMiOlt7Ik1pZCI6ImEiLCJJUCI6IjE1OC4xNzQuMTAuMjE4IiwiVGltZSI6MTU2NTgxMTk2NX1dLCJUcmlhbEFjdGl2YXRpb24iOmZhbHNlLCJNYXhOb09mTWFjaGluZXMiOjQsIkFsbG93ZWRNYWNoaW5lcyI6IjBPTzRMZ29tdUZOYnIyNzFvc09mRU5oXG5Wb2l1M0xzdVFXMDIiLCJEYXRhT2JqZWN0cyI6W3siSWQiOjQ5ODQsIk5hbWUiOiJvVzliWlQwbHJ1RUN2SUVkRkNNc0MweWJTIiwiU3RyaW5nVmFsdWUiOiJFY2FCdnF4dGRvVWVhcm5jU0oiLCJJbnRWYWx1ZSI6NDA5MTU5fSx7IklkIjo0OTg1LCJOYW1lIjoiRU90NWRQaDZPcWVpemtvIiwiU3RyaW5nVmFsdWUiOiIiLCJJbnRWYWx1ZSI6OTU2NjgwfSx7IklkIjo0OTg2LCJOYW1lIjoiYiBwVVkwQyIsIlN0cmluZ1ZhbHVlIjoiaWN3cW4zZm9DZiAiLCJJbnRWYWx1ZSI6Nzc2OTgwfV0sIlNpZ25EYXRlIjoxNTcwNDYxMjAzfQ==";
    saved_response += "-";
    saved_response += "H0VrpKC6aBmtQ7NbfQ42DNyfyu6HpyschBz5dsulnqVhFNbITADuM2Vp7Dg9udJV87ppr8QSJBtYiFur6InjrJ/mXplY0G/D4sq40CGTwuJ8f7JVPIvGSAd2TnIGNjp5m2dr1JwgzAh5ntdE4j8NvfytU38iHOIbdS0NN12njO+v7+tjxHk6RFTAFtftSwwch7BP7jH1itFZ33/ygk8IfF7qIys7yWdpxEMep3qAB1rYZ91bKFYh9VD9qgWo+xY8KNpqgOTElWDlbvv5Ul6YShP99TYFR4GmEzHQtXN/sslnuvQn3PgeKkIOzt2QKDCxvQawDJFybFw+C0YfMqnYjw==";

    license_key_ = cryptolens_handle.make_license_key(e, saved_response);

    ASSERT_TRUE(license_key_);
    ASSERT_FALSE(e);
  }

  static void TearDownTestCase() {
    license_key_ = cryptolens::nullopt;
  }

  v20190401_offline_compact_Key723() : ::testing::Test(), license_key(license_key_) {}

  static cryptolens::optional<cryptolens::LicenseKey> license_key_;
  cryptolens::optional<cryptolens::LicenseKey> const& license_key;
};

cryptolens::optional<cryptolens::LicenseKey> v20190401_offline_compact_Key723::license_key_;

TEST_F(v20190401_offline_compact_Key723, MandatoryProperties) {
  EXPECT_EQ(license_key->get_product_id(), 4848);
  EXPECT_EQ(license_key->get_created(), 1565802169);
  EXPECT_EQ(license_key->get_expires(), 4198150969);
  EXPECT_EQ(license_key->get_period(), 30466);
  EXPECT_EQ(license_key->get_block(), false);
  EXPECT_EQ(license_key->get_trial_activation(), false);
  EXPECT_EQ(license_key->get_f1(), false);
  EXPECT_EQ(license_key->get_f2(), false);
  EXPECT_EQ(license_key->get_f3(), true);
  EXPECT_EQ(license_key->get_f4(), false);
  EXPECT_EQ(license_key->get_f5(), true);
  EXPECT_EQ(license_key->get_f6(), true);
  EXPECT_EQ(license_key->get_f7(), false);
  EXPECT_EQ(license_key->get_f8(), true);
}

TEST_F(v20190401_offline_compact_Key723, SimpleOptionalProperties) {
  EXPECT_TRUE(license_key->get_id());
  if (license_key->get_id()) { EXPECT_EQ(*(license_key->get_id()), 774); }

  EXPECT_TRUE(license_key->get_key());
  if (license_key->get_key()) { EXPECT_EQ(*(license_key->get_key()), "HJDEC-HSNBA-HHVCD-ATQEG"); }

  EXPECT_TRUE(license_key->get_notes());
  if (license_key->get_notes()) { EXPECT_EQ(*(license_key->get_notes()), "3Nk8fKqE"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }

  EXPECT_TRUE(license_key->get_maxnoofmachines());
  if (license_key->get_maxnoofmachines()) { EXPECT_EQ(*(license_key->get_maxnoofmachines()), 4); }

  EXPECT_TRUE(license_key->get_allowed_machines());
  if (license_key->get_allowed_machines()) { EXPECT_EQ(*(license_key->get_allowed_machines()), "0OO4LgomuFNbr271osOfENh\nVoiu3LsuQW02"); }

  EXPECT_TRUE(license_key->get_global_id());
  if (license_key->get_global_id()) { EXPECT_EQ(*(license_key->get_global_id()), 55055); }
}

TEST_F(v20190401_offline_compact_Key723, ActivatedMachines) {
  ASSERT_TRUE(license_key->get_activated_machines());

  std::vector<cryptolens::ActivationData> expected;
  expected.push_back(cryptolens::ActivationData("a", "158.174.10.218", 1565811965));

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

TEST_F(v20190401_offline_compact_Key723, Customer) {
  EXPECT_TRUE(license_key->get_customer());
  if (license_key->get_customer()) {
    auto const& customer = *(license_key->get_customer());
    EXPECT_EQ(customer.get_id(), 6743);
    EXPECT_EQ(customer.get_name(), "ip2pA1zwHqAVz");
    EXPECT_EQ(customer.get_email(), "");
    EXPECT_EQ(customer.get_company_name(), "QFGnal2fRK06");
    EXPECT_EQ(customer.get_created(), 1565802168);
  }
}

TEST_F(v20190401_offline_compact_Key723, DataObjects) {
  ASSERT_TRUE(license_key->get_data_objects());

  std::vector<cryptolens::DataObject> expected;
  expected.push_back(cryptolens::DataObject(4984, "oW9bZT0lruECvIEdFCMsC0ybS", "EcaBvqxtdoUearncSJ", 409159));
  expected.push_back(cryptolens::DataObject(4985, "EOt5dPh6Oqeizko", "", 956680));
  expected.push_back(cryptolens::DataObject(4986, "b pUY0C", "icwqn3foCf ", 776980));

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
