#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/io.h>
#include <linux/delay.h>

#define DEVICE_NAME "flashlight_driver"

static int flashlight_on = 0;

static int flashlight_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "flashlight_driver: device opened\n");
    return 0;
}

static int flashlight_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "flashlight_driver: device closed\n");
    return 0;
}

static ssize_t flashlight_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos) {
    char kbuf[10];
    if (count > sizeof(kbuf) - 1)
        return -EINVAL;

    if (copy_from_user(kbuf, buf, count))
        return -EFAULT;
    kbuf[count] = '\0';

    if (kstrtoint(kbuf, 10, &flashlight_on) < 0)
        return -EINVAL;

    if (flashlight_on) {
        printk(KERN_INFO "flashlight_driver: turning ON the flashlight\n");
        // TODO: ligar hardware da lanterna
    } else {
        printk(KERN_INFO "flashlight_driver: turning OFF the flashlight\n");
        // TODO: desligar hardware da lanterna
    }

    return count;
}

static const struct file_operations flashlight_fops = {
    .owner = THIS_MODULE,
    .open = flashlight_open,
    .release = flashlight_release,
    .write = flashlight_write,
};

static struct miscdevice flashlight_misc_device = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEVICE_NAME,
    .fops = &flashlight_fops,
};

static int __init flashlight_init(void) {
    int ret;
    printk(KERN_INFO "flashlight_driver: initializing\n");
    ret = misc_register(&flashlight_misc_device);
    if (ret) {
        printk(KERN_ERR "flashlight_driver: failed to register device\n");
        return ret;
    }
    printk(KERN_INFO "flashlight_driver: device registered\n");
    return 0;
}

static void __exit flashlight_exit(void) {
    printk(KERN_INFO "flashlight_driver: exiting\n");
    misc_deregister(&flashlight_misc_device);
}

module_init(flashlight_init);
module_exit(flashlight_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Seu Nome");
MODULE_DESCRIPTION("Driver de lanterna nativo");
