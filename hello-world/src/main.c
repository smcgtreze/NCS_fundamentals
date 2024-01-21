#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "myfunction.h"

int main(void)
{
	while(1){
		#ifdef CONFIG_MYFUNCTION
		int a = 3, b = 4;
			printk("The sum of %d and %d is %d\n\r", a, b, sum(a,b));
		#else
			printk("MYFUNCTION not enabled\r\n");
			return;
		#endif
		k_msleep(1000);
	}
}