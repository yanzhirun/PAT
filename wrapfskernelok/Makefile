KERNELDIR = /usr/src/linux-$(shell uname -r)
PWD := $(shell pwd)
CC    = $(CROSS_COMPILE)gcc
MODULE_NAME := testpwd
RESMAN_CORE_OBJS := test.o
RESMAN_GLUE_OBJS := crypto_hash.o
#$(MODULE_NAME)-y := crypto_hash.o
$(MODULE_NAME)-objs := $(RESMAN_GLUE_OBJS) $(RESMAN_CORE_OBJS)
obj-m := testpwd.o
moudles:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
