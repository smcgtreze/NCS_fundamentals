/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)
#define LED3_NODE DT_ALIAS(led3)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec led_2 = GPIO_DT_SPEC_GET(LED2_NODE, gpios);
static const struct gpio_dt_spec led_3 = GPIO_DT_SPEC_GET(LED3_NODE, gpios);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&led) || !gpio_is_ready_dt(&led_1) || !gpio_is_ready_dt(&led_2) || !gpio_is_ready_dt(&led_3)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE) || gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_ACTIVE) || gpio_pin_configure_dt(&led_2, GPIO_OUTPUT_ACTIVE) || gpio_pin_configure_dt(&led_3, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	while (1) {
		//Each pin is toggled every 5*SLEEP_TIME_MS = 5 sec, meaning it will be on for 5 sec and off for 5 sec.

		ret = gpio_pin_toggle_dt(&led);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
		ret = gpio_pin_toggle_dt(&led_1);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
		ret = gpio_pin_toggle_dt(&led_2);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
		ret = gpio_pin_toggle_dt(&led_3);
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
