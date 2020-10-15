#include <linux/module.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/kd.h>
#include <linux/vt.h>
#include <linux/vt_kern.h>
#include <linux/console_struct.h>
#include <linux/proc_fs.h>


MODULE_LICENSE("GPL");

struct timer_list myTimer;
struct tty_driver *myDriver;
char blinkStatus = 0;

unsigned long blinkSpd;
unsigned long ledsOnState;
#define RESTORE_LEDS  0xFF

ssize_t writeBlinks(struct file* fp, const char *userBuffer, size_t userBufferSize, loff_t *offset)
{
	// for type conversion: 48 ('0') 57 ('9')
    if(userBuffer[0] == 'L')
    {
        if(userBuffer[1] > 47 && userBuffer[1] < 56)
        {
            ledsOnState = userBuffer[1] - 48;
        }

    }
    else if (userBuffer[0] == 'D')
    {
        if(userBuffer[1] > 47 && userBuffer[1] < 59)
        {
            blinkSpd = HZ / (userBuffer[1] - 47);
        }
    }
	return userBufferSize;
}

struct file_operations our_file_operations = {
	write: writeBlinks
};

static void timerFunc(struct timer_list *timers)
{
	int *pstatus = (int *)&blinkStatus;

	if (*pstatus == ledsOnState)
		*pstatus = RESTORE_LEDS;
	else
		*pstatus = ledsOnState;

	(myDriver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED,
			    *pstatus);

	myTimer.expires = jiffies + blinkSpd;
	add_timer(&myTimer);
}

static int __init blinks_init(void)
{
	int i;

	printk(KERN_INFO "blinks: loading\n");
	printk(KERN_INFO "blinks: fgconsole is %x\n", fg_console);
	for (i = 0; i < MAX_NR_CONSOLES; i++) {
		if (!vc_cons[i].d)
			break;
		printk(KERN_INFO "poet_atkm: console[%i/%i] #%i, tty %lx\n", i,
		       MAX_NR_CONSOLES, vc_cons[i].d->vc_num,
		       (unsigned long)vc_cons[i].d->port.tty);
	}
	printk(KERN_INFO "blinks: finished scanning consoles\n");
    proc_create("blinkProc", 0, 0, &our_file_operations);
	myDriver = vc_cons[fg_console].d->port.tty->driver;
	printk(KERN_INFO "blinks: tty driver magic %x\n", myDriver->magic);

	timer_setup(&myTimer, timerFunc, 0);
	myTimer.expires = jiffies + blinkSpd;
	add_timer(&myTimer);

	(myDriver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED, ledsOnState);

	return 0;
}

static void __exit blinks_cleanup(void)
{
    remove_proc_entry("blinkProc", 0);
	printk(KERN_INFO "blinks: unloading...\n");
	del_timer(&myTimer);
	(myDriver->ops->ioctl) (vc_cons[fg_console].d->port.tty, KDSETLED, RESTORE_LEDS);
}

module_init(blinks_init);
module_exit(blinks_cleanup);
