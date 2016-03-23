#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

#include <linux/fs.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include "crypto_hash.h"
MODULE_LICENSE("Dual BSD/GPL");

#define NUM 10

static int __init init(void)
{


	int random_number = 0 ;
        char pwd[12]={0};
	printk(KERN_ALERT"--   testfile start get passwd   --\n");


        wrapfs_get_encode_pwd((const char *)"hello",(const char *)random_number,(char *)pwd, 12);

	printk(KERN_ALERT"-- Main get passwd over --\n");

	return 0;
}

static void __exit fini(void)
{
	printk(KERN_ALERT"Goodbye,Kernel\n");
}

module_init(init);
module_exit(fini);

MODULE_DESCRIPTION("This is a simple example!!\n");




