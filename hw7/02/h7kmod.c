/* Does Not Work */

#include<linux/init.h>
#include<linux/module.h>
#include<linux/device.h>	//Linux Device model APIs
#include<linux/cdev.h>		//cdev structure defined
#include<linux/types.h>
#include<linux/errno.h>
#include<linux/fs.h>		//character driver file support

/* Module Infomation */
MODULE_AUTHOR("J. Millington");
MODULE_DESCRIPTION("Hw7 Kernel Module");
MODULE_LICENSE("Dual BSD/GPL");

/* Device Structure */
static struct h7kmod_data kmd = {
	.km_mjr=0;
	.km_class=NULL;
};

/* Define device class to create device special file 
 * and define device struct */
static struct class * h7kmod_class = NULL;
static struct device * h7kmod_device = NULL;

/* File Operations for Module 
 * to be added */
static const struct file_operations h7kmod_fops = {
	.owner = THIS_MODULE;
	.open = NULL;
	.release = NULL;
};

/* Module Initialization */
static int __init h7kmod_minit(void)
{
	struct device * dev;

	printk(KERN_INFO "h7kmod initialized\n");
	return 0;

	kmd.km_mjr=register_chrdev(0,"h7kmod",&h7kmod_fops);
	if (kmd.km_mjr<0){
		printk(KERN_NOTICE "Cannot register char device\n");
		return kmd.km_mjr;
	}
	printk(KERN_INFO "Major Device Number %d/n",kmd.km_mjr);
	kmd.km_class=class_create(THIS_MODULE, "km_class");
	if (IS_ERR(kmd.km_class)){
		unregister_chrdev(kmd.km_mjr, "h7kmod");
		return PTR_ERR(kmd.km_class);
	}

	/* Permission callback */
	kmd.km_class->devnode=km_devnode;

	dev = device_create(kmd.km_class,NULL,MKDEV(kmd.km_mjr,0),
			    (void *)&kmd,"h7kmod");
	if(IS_ERR(dev)){
		class_destroy(kmd.km_class);
		unregister_chrdev(kmd.km_mjr, "h7kmod");
		return PTR_ERR(dev);
	}
	return 0;
}


static void __exit h7kmod_mcleanup(void)
{
	device_destroy(kmd.km_class,MKDEV(kmd.km_mjr,0));
	class_destroy(kmd.km_class);
	unregister_chrdev(kmd.km_mjr, "h7kmod");
	printk(KERN_INFO "h7kmod exit\n");
	return 0;
}

module_init(h7kmod_minit);
module_exit(h7kmod_mcleanup);
