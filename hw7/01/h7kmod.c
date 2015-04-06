#include<linux/init.h>
#include<linux/module.h>

/* License Info */
MODULE_LICENSE("Dual BSD/GPL");

static int h7kmod_init(void)
{
	printk(KERN_INFO "h7kmod\n");
	return 0;
}

static void h7kmod_exit(void)
{
	printk(KERN_INFO "h7kmod exit\n");
	return 0;
}

module_init(h7kmod_init);
module_exit(h7kmod_exit);
