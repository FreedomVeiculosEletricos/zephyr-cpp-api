#ifndef GPI_HPP_
#define GPI_HPP_
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>

namespace zephyrcppapi{
	
class Gpi
{
private:
	struct gpio_dt_spec io;

public:
	Gpi(struct gpio_dt_spec input)
	: io(input)
	{
		if (!device_is_ready(io.port)) {
			printk("ERROR");
		}
		gpio_pin_configure_dt(&io, GPIO_INPUT);
	}

    int get()
    {
	    int gpio_state = gpio_pin_get_dt(&io);
        if (gpio_state == -EIO || gpio_state == -EWOULDBLOCK){
            return (0);
        }
	    else{
			return (1);
		}
    }
};
}

#endif