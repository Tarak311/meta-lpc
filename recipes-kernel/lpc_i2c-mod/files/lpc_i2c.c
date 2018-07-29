/*
 * I2C slave mode EEPROM simulator
 *
 * Copyright (C) 2014 by Wolfram Sang, Sang Engineering <wsa@sang-engineering.com>
 * Copyright (C) 2014 by Renesas Electronics Corporation
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; version 2 of the License.
 *
 * Because most IP blocks can only detect one I2C slave address anyhow, this
 * driver does not support simulating EEPROM types which take more than one
 * address. It is prepared to simulate bigger EEPROMs with an internal 16 bit
 * pointer, yet implementation is deferred until the need actually arises.
 */

#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/sysfs.h>




static int i2c_slave_eeprom_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
	printk(KERN_EMERG "LPC i2c Module probed\n");
	printk(KERN_EMERG "device addr is: %02x\n",client->addr);
	return 0;
	}


static int i2c_slave_eeprom_remove(struct i2c_client *client)
{

	return 0;
}

static const struct of_device_id lpc1769_of_ids[]={
	{.compatible="linux,lpci2c"},
	{},
};
MODULE_DEVICE_TABLE(of,lpc1769_of_ids);




static struct i2c_driver i2c_slave_eeprom_driver = {
	.driver = {
		.name = "i2c-slave-lpc",
	  .of_match_table = of_match_ptr(lpc1769_of_ids),
	},
	.probe = i2c_slave_eeprom_probe,
	.remove = i2c_slave_eeprom_remove,

};
module_i2c_driver(i2c_slave_eeprom_driver);

MODULE_AUTHOR("Wolfram Sang <wsa@sang-engineering.com>");
MODULE_DESCRIPTION("I2C slave mode EEPROM simulator");
MODULE_LICENSE("GPL v2");
