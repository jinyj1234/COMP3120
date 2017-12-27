#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void){
	printk("hello,my name is younjong\n");
	return 0;
}

static void __exit exit_hello(void){
	printk("byebyebye\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
