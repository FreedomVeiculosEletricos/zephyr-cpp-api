/*
 *Copyright 2022 Freedom Veículos Elétricos LTDA.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "gpi.hpp"
#include "gpo.hpp"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>

struct gpio_dt_spec io = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);

ZTEST_F(gpio_basic_api, test_set) {
  zephyrcppapi::Gpo output{io};
  int rv = output.set();
  zassert_equal(true, rv, "gpio_pin_is_output() failed: %d", rv);
}

ZTEST_F(gpio_basic_api, test_reset) {
  zephyrcppapi::Gpo output{io};
  int rv = output.reset();
  zassert_equal(true, rv, "gpio reset failed: %d", rv);
}

ZTEST_F(gpio_basic_api, test_get) {
  zephyrcppapi::Gpi input{io};
  int rv = input.get();
  zassert_equal(true, rv, "gpio reset failed: %d", rv);
}

ZTEST_SUITE(gpio_basic_api, NULL, NULL, NULL, NULL, NULL);
