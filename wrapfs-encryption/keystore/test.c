#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/mm.h>
#include <linux/syscalls.h>
#include <asm/unistd.h>
#include "key_store.h"
MODULE_LICENSE("Dual BSD/GPL");

static int __init init(void)
{
	char *file_name = "/home/yzr/my_passwd1";
        char pwd[12]={0};
        printk(KERN_ALERT"--testkeystoremodule--\n");
	char *user_name;
	wrapfs_key_store(file_name,"user123123", "000fawea");
        wrapfs_get_key(file_name, "user123123", pwd);
	return 0;
}

static void __exit fini(void)
{
        printk(KERN_ALERT"Goodbye,Kernel\n");
}

module_init(init);
module_exit(fini);

MODULE_DESCRIPTION("This is a simple example!!\n");

