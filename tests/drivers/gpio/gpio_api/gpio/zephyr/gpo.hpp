/*
 * Copyright 2022 Freedom Veículos Elétricos LTDA.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef GPO_HPP_
#define GPO_HPP_
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>

namespace zephyrcppapi {

class Gpo {
private:
  struct gpio_dt_spec io;

public:
  Gpo(struct gpio_dt_spec output) : io(output) {
    if (!device_is_ready(io.port)) {
      printk("ERROR");
    }
    gpio_pin_configure_dt(&io, GPIO_OUTPUT_INACTIVE);
  }

  int set() {
    int rv = gpio_pin_set_dt(&io, 1);
    if (rv < 0) {
      return (0);
    } else {
      return (1);
    }
  }
  int reset() {
    int rv = gpio_pin_set_dt(&io, 0);
    if (rv < 0) {
      return (0);
    } else {
      return (1);
    }
  }
};
} // namespace zephyrcppapi

#endif
