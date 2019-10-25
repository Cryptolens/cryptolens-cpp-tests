#pragma once

#include <chrono>
#include <deque>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include <time.h>

namespace cryptolens_io {

namespace tests {

std::deque<std::string> read_inputs();

class CharReader {
public:
  CharReader();
  operator bool() const;

  friend CharReader & operator>>(CharReader & in, char & c);
private:
  static constexpr size_t BUFSIZE = 4096;

  void read_();

  char buf_[BUFSIZE];
  size_t pos_ = 0;
  size_t size_ = 0;
};

CharReader &
operator>>(CharReader & in, char & c);

template<char Esc, char Sep, typename Input, typename It>
void
split_input(Input & in, It it)
{
  constexpr int STATE_DEFAULT = 0;
  constexpr int STATE_ESC = 1;

  int state = STATE_DEFAULT;
  std::string current;
  char c;
  while (in >> c) {
    switch (state) {
    case STATE_DEFAULT:
      if (c == Esc) {
        state = STATE_ESC;
      } else {
        current += c;
      }
    break;

    case STATE_ESC:
      if (c == Esc) {
        current += Esc;
      } else if (c == Sep) {
        *it = std::move(current); ++it;
      } else {
        current += Esc;
        current += c;
      }
      state = STATE_DEFAULT;
    break;
    }
  }
  *it = std::move(current); ++it;
}

template<typename T>
void
touch_license_key(T const& license_key)
{
  std::cout << license_key->get_product_id() << std::endl;
  std::cout << license_key->get_created() << std::endl;
  std::cout << license_key->get_expires() << std::endl;
  std::cout << license_key->get_period() << std::endl;
  std::cout << license_key->get_block() << std::endl;
  std::cout << license_key->get_trial_activation() << std::endl;
  std::cout << license_key->get_sign_date() << std::endl;
  std::cout << license_key->get_f1() << std::endl;
  std::cout << license_key->get_f2() << std::endl;
  std::cout << license_key->get_f3() << std::endl;
  std::cout << license_key->get_f4() << std::endl;
  std::cout << license_key->get_f5() << std::endl;
  std::cout << license_key->get_f6() << std::endl;
  std::cout << license_key->get_f7() << std::endl;
  std::cout << license_key->get_f8() << std::endl;

  if (license_key->get_id()) {
    std::cout << *license_key->get_id() << std::endl;
  }

  if (license_key->get_key()) {
    std::cout << *license_key->get_key() << std::endl;
  }

  if (license_key->get_notes()) {
    std::cout << *license_key->get_notes() << std::endl;
  }

  if (license_key->get_global_id()) {
    std::cout << *license_key->get_global_id() << std::endl;
  }

  if (license_key->get_customer()) {
    auto const& customer = *license_key->get_customer();

    std::cout << customer.get_id() << std::endl;
    std::cout << customer.get_name() << std::endl;
    std::cout << customer.get_email() << std::endl;
    std::cout << customer.get_company_name() << std::endl;
    std::cout << customer.get_created() << std::endl;
  }

  if (license_key->get_activated_machines()) {
    auto const& activated_machines = *license_key->get_activated_machines();

    for (auto const& activation_data : activated_machines) {
      std::cout << activation_data.get_mid() << std::endl;
      std::cout << activation_data.get_ip() << std::endl;
      std::cout << activation_data.get_time() << std::endl;
    }
  }

  if (license_key->get_maxnoofmachines()) {
    std::cout << *license_key->get_maxnoofmachines() << std::endl;
  }

  if (license_key->get_allowed_machines()) {
    std::cout << *license_key->get_allowed_machines() << std::endl;
  }

  if (license_key->get_data_objects()) {
    auto const& data_objects = *license_key->get_data_objects();

    for (auto const& data_object : data_objects) {
      std::cout << data_object.get_id() << std::endl;
      std::cout << data_object.get_name() << std::endl;
      std::cout << data_object.get_string_value() << std::endl;
      std::cout << data_object.get_int_value() << std::endl;
    }
  }
}

template<typename Gen>
void
seed_generator(Gen & g)
{
  typedef std::chrono::high_resolution_clock clock;
  clock::time_point p = clock::now();

  auto s = std::chrono::duration_cast<std::chrono::nanoseconds>(p.time_since_epoch()).count();

  g.seed(s);
}

class Chaos {
public:
  virtual bool should_fail() = 0;
};

class RandomChaos : public Chaos {
public:
  RandomChaos(double p) : p_(p), g_(), d_(0.0, 1.0) {
    seed_generator(g_);
  }

  bool should_fail() override {
    return (1.0 - d_(g_)) < p_;
  }

  void set_failure_probability(double p) { p_ = p; }
private:
  double p_;
  std::default_random_engine g_;
  std::uniform_real_distribution<double> d_;
};

namespace override {


namespace openssl { namespace chaos {

extern Chaos * chaos;

}} // namespace openssl::chaos


namespace curl { namespace chaos {

extern Chaos * chaos;

}} // namespace curl::chaos


namespace cryptoapi { namespace chaos {

extern Chaos * chaos;

}} // namespace cryptoapi::chaos


namespace winhttp { namespace chaos {

extern Chaos * chaos;

}} // namespace winhttp::chaos


} // namespace override

} // namespace tests

} // namespace cryptolens_io
