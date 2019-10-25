#include <iostream>

#include <curl/curl.h>

#include <cryptolens/core.hpp>
#include <cryptolens/Error.hpp>
#include <cryptolens/Configuration_Unix.hpp>
#include <cryptolens/MachineCodeComputer_static.hpp>

#include <gtest/gtest.h>
#include <cryptolens/tests/gtest_shared.hpp>

namespace tests_v20190401 {

class v20190401_Configuration_Unix : public ::testing::Test {
protected:
  v20190401_Configuration_Unix() : e(), cryptolens_handle(e) {}

  void SetUp() override {
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");
  }

  cryptolens::Error e;
  Cryptolens cryptolens_handle;
};

TEST_F(v20190401_Configuration_Unix, InvalidSignature) {
  cryptolens_handle.machine_code_computer.set_machine_code(e, "289jf2afs3");

  // Changed first 'S' in signature to 's'
  std::string cryptolens_reply("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjM2NDYsIklEIjo0LCJLZXkiOiJNUERXWS1QUUFPVy1GS1NDSC1TR0FBVSIsIkNyZWF0ZWQiOjE0OTAzMTM2MDAsIkV4cGlyZXMiOjE0OTI5MDU2MDAsIlBlcmlvZCI6MzAsIkYxIjpmYWxzZSwiRjIiOmZhbHNlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3IjpmYWxzZSwiRjgiOmZhbHNlLCJOb3RlcyI6bnVsbCwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6MzE4NzYsIkN1c3RvbWVyIjpudWxsLCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxODk4OTE4fSx7Ik1pZCI6ImxvbCIsIklQIjoiMTU1LjQuMTM0LjI3IiwiVGltZSI6MTQ5MTg5ODk5NX0seyJNaWQiOiIyODlqZjJhZnNmIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxOTAwNTQ2fSx7Ik1pZCI6IjI4OWpmMmFmczMiLCJJUCI6IjE1NS40LjEzNC4yNyIsIlRpbWUiOjE0OTE5MDA2MzZ9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxMCwiQWxsb3dlZE1hY2hpbmVzIjoiIiwiRGF0YU9iamVjdHMiOltdLCJTaWduRGF0ZSI6MTQ5NTAxOTc2Nn0=\",\"signature\":\"sqPm8dtTdVBrXrmJzXer7qq6dvdQfctJxP8mar+RO9p8QABsgWWaX+uH7aOGMBd42eg+2Omorv7Ks6V7itRhXPeeq5qWoKuefd+pTsFagvqiu2N/E2Np8fpt51aqmiygdHLECo42nJwVD8JzlN67hnvJTgY7iyDWhG7qFK9Slk+kEJjjK/0J1pJYI6nOi+7sgBV7ZRca+7DmiP6OmOjNfySps6PdiB7QbiSis5f24Xmc5OYyRe3fzZmAueqF3eymBK19XhYFroWXeT4tcNsBNJsv+YfItovGbJysLx+K4ppltd2GNwEFQgtE3ILGOUj7EVbeQmQXg9m2c5MTPyk8iA==\",\"result\":0,\"message\":\"\"}");

  cryptolens::optional<cryptolens::LicenseKey> license_key = cryptolens_handle.make_license_key(e, cryptolens_reply);

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateBlockedKey) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "EYABD-KAAFI-GQCQW-UPZVD");

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateFloatingBlockedKey) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "EYABD-KAAFI-GQCQW-UPZVD", 10);

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateExpiredKeyLimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "HNOPG-YOVMB-EKADY-AFFJN");

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateExpiredKeyUnlimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "ERLSC-KWCWY-FTNJT-EENXK");

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateFloatingExpiredKeyLimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "HNOPG-YOVMB-EKADY-AFFJN", 10);

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix, ActivateFloatingExpiredKeyUnlimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "ERLSC-KWCWY-FTNJT-EENXK", 10);

  ASSERT_TRUE(e);
}

class v20190401_Configuration_Unix_IgnoreExpires : public ::testing::Test {
protected:
  v20190401_Configuration_Unix_IgnoreExpires() : e(), cryptolens_handle(e) {}

  void SetUp() override {
    cryptolens_handle.signature_verifier.set_modulus_base64(e, "khbyu3/vAEBHi339fTuo2nUaQgSTBj0jvpt5xnLTTF35FLkGI+5Z3wiKfnvQiCLf+5s4r8JB/Uic/i6/iNjPMILlFeE0N6XZ+2pkgwRkfMOcx6eoewypTPUoPpzuAINJxJRpHym3V6ZJZ1UfYvzRcQBD/lBeAYrvhpCwukQMkGushKsOS6U+d+2C9ZNeP+U+uwuv/xu8YBCBAgGb8YdNojcGzM4SbCtwvJ0fuOfmCWZvUoiumfE4x7rAhp1pa9OEbUe0a5HL+1v7+JLBgkNZ7Z2biiHaM6za7GjHCXU8rojatEQER+MpgDuQV3ZPx8RKRdiJgPnz9ApBHFYDHLDzDw==");
    cryptolens_handle.signature_verifier.set_exponent_base64(e, "AQAB");
    cryptolens_handle.machine_code_computer.set_machine_code(e, "a");
  }

  cryptolens::Error e;
  Cryptolens_IgnoreExpires cryptolens_handle;
};

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, InvalidSignature) {
  cryptolens_handle.machine_code_computer.set_machine_code(e, "289jf2afs3");

  // Changed first 'S' in signature to 's'
  std::string cryptolens_reply("{\"licenseKey\":\"eyJQcm9kdWN0SWQiOjM2NDYsIklEIjo0LCJLZXkiOiJNUERXWS1QUUFPVy1GS1NDSC1TR0FBVSIsIkNyZWF0ZWQiOjE0OTAzMTM2MDAsIkV4cGlyZXMiOjE0OTI5MDU2MDAsIlBlcmlvZCI6MzAsIkYxIjpmYWxzZSwiRjIiOmZhbHNlLCJGMyI6ZmFsc2UsIkY0IjpmYWxzZSwiRjUiOmZhbHNlLCJGNiI6ZmFsc2UsIkY3IjpmYWxzZSwiRjgiOmZhbHNlLCJOb3RlcyI6bnVsbCwiQmxvY2siOmZhbHNlLCJHbG9iYWxJZCI6MzE4NzYsIkN1c3RvbWVyIjpudWxsLCJBY3RpdmF0ZWRNYWNoaW5lcyI6W3siTWlkIjoiIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxODk4OTE4fSx7Ik1pZCI6ImxvbCIsIklQIjoiMTU1LjQuMTM0LjI3IiwiVGltZSI6MTQ5MTg5ODk5NX0seyJNaWQiOiIyODlqZjJhZnNmIiwiSVAiOiIxNTUuNC4xMzQuMjciLCJUaW1lIjoxNDkxOTAwNTQ2fSx7Ik1pZCI6IjI4OWpmMmFmczMiLCJJUCI6IjE1NS40LjEzNC4yNyIsIlRpbWUiOjE0OTE5MDA2MzZ9XSwiVHJpYWxBY3RpdmF0aW9uIjpmYWxzZSwiTWF4Tm9PZk1hY2hpbmVzIjoxMCwiQWxsb3dlZE1hY2hpbmVzIjoiIiwiRGF0YU9iamVjdHMiOltdLCJTaWduRGF0ZSI6MTQ5NTAxOTc2Nn0=\",\"signature\":\"sqPm8dtTdVBrXrmJzXer7qq6dvdQfctJxP8mar+RO9p8QABsgWWaX+uH7aOGMBd42eg+2Omorv7Ks6V7itRhXPeeq5qWoKuefd+pTsFagvqiu2N/E2Np8fpt51aqmiygdHLECo42nJwVD8JzlN67hnvJTgY7iyDWhG7qFK9Slk+kEJjjK/0J1pJYI6nOi+7sgBV7ZRca+7DmiP6OmOjNfySps6PdiB7QbiSis5f24Xmc5OYyRe3fzZmAueqF3eymBK19XhYFroWXeT4tcNsBNJsv+YfItovGbJysLx+K4ppltd2GNwEFQgtE3ILGOUj7EVbeQmQXg9m2c5MTPyk8iA==\",\"result\":0,\"message\":\"\"}");

  cryptolens::optional<cryptolens::LicenseKey> license_key = cryptolens_handle.make_license_key(e, cryptolens_reply);

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateBlockedKey) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "EYABD-KAAFI-GQCQW-UPZVD");

  ASSERT_TRUE(e);
}

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateFloatingBlockedKey) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "EYABD-KAAFI-GQCQW-UPZVD", 10);

  ASSERT_TRUE(e);
}


TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateExpiredKeyLimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "HNOPG-YOVMB-EKADY-AFFJN");

  ASSERT_FALSE(e);
}

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateExpiredKeyUnlimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "ERLSC-KWCWY-FTNJT-EENXK");

  ASSERT_FALSE(e);
}

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateFloatingExpiredKeyLimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "HNOPG-YOVMB-EKADY-AFFJN", 10);

  ASSERT_FALSE(e);
}

TEST_F(v20190401_Configuration_Unix_IgnoreExpires, ActivateFloatingExpiredKeyUnlimitedMachines) {
  cryptolens::optional<cryptolens::LicenseKey> license_key =
    cryptolens_handle.activate_floating(e, "WyI3ODM5IiwiVWRxbUxIc0lrN0ZPcUdiVVZPODVlR0FvZmFvcnhMdklBSlloYmtiRCJd", 4848, "ERLSC-KWCWY-FTNJT-EENXK", 10);

  ASSERT_FALSE(e);
}

} // namespace tests_v20190401
