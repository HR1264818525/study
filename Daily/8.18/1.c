#include <linux/module.h>     //模块相关头文件：module_init module_exit
#include <linux/kernel.h>     //printk打印
#include <linux/fs.h>         //文件系统相关，file_operations、设备号
#include <linux/cdev.h>       //cdev字符设备结构体

// dev_t：设备号数据类型，包含主设备号+次设备号
static dev_t dev_num;

// cdev：内核字符设备对象，代表我们这一个设备
static struct cdev my_cdev;

// file_operations：文件操作回调集合，系统调用会跳到这里的函数
static struct file_operations my_fops = {
    .owner = THIS_MODULE,   //防止模块在使用时被卸载，固定写法
};

/**
 * __init 宏：标记初始化函数，模块加载insmod时执行
 * 功能：设备初始化：分配设备号、初始化cdev、注册cdev到内核
 */
static int __init mydrv_init(void)
{
    int ret;
    //①动态分配设备号；参数：&输出设备号，起始次设备号，设备数量，驱动名字
    ret = alloc_chrdev_region(&dev_num, 0, 1, "my_char_dev");
    if(ret < 0)
    {
        printk(KERN_ERR "分配设备号失败\n");
        return ret; //初始化出错，直接返回，insmod加载失败
    }
    printk(KERN_INFO "初始化成功：主设备号=%d,次设备号=%d\n",MAJOR(dev_num),MINOR(dev_num));

    //②cdev_init：初始化cdev结构体，绑定file_operations回调函数表
    cdev_init(&my_cdev, &my_fops);

    //③cdev_add：真正向内核注册字符设备！设备初始化完成
    ret = cdev_add(&my_cdev, dev_num, 1);
    if(ret <0)
    {
        printk(KERN_ERR "cdev_add注册失败\n");
        unregister_chrdev_region(dev_num,1); //失败要回滚，释放已经拿到的设备号
        return ret;
    }
    printk(KERN_INFO ">>>设备初始化完成\n");
    return 0;
}

/**
 * __exit宏：标记卸载函数；rmmod卸载模块的时候执行
 * 注销顺序：和初始化严格相反！先cdev_del，再释放设备号
 */
static void __exit mydrv_exit(void)
{
    cdev_del(&my_cdev);                //从内核移除cdev设备
    unregister_chrdev_region(dev_num,1);//释放分配的设备号资源
    printk(KERN_INFO ">>>设备注销完成\n");
}

//模块入口：insmod的时候调用mydrv_init
module_init(mydrv_init);
//模块出口：rmmod的时候调用mydrv_exit
module_exit(mydrv_exit);

//许可证GPL，必须写，否则很多内核API不能使用，加载警告
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("最简字符驱动：初始化+注销");