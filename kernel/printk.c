#include <stdarg.h>
#include "printk.h"

int color_printk(unsigned int FRcolor, unsigned int BKcolor, const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    return 0;
}

int vsprintf(char *buf, const char *fmt, va_list args){
    return 0;
}
/*
fb:帧缓存区首地址
Xsize:首像素位置的偏移
x,y:没弄明白...
FRcolor:前颜色
BKcolor:后颜色
font:字符ascii
 */
int putchar(unsigned int *fb, int Xsize, int x, int y, unsigned int FRcolor, unsigned int BKcolor, unsigned char font){
    unsigned int *addr = 0x00;
    unsigned char *fontp = 0x00;
    int testval = 0;
    fontp = font_ascii[font];
    for(int i = 0; i < 16; i++){
	addr = fb + (Xsize * ( y + i ) + x);
	testval = 0x100;//1'0000'0000b
	for(int j = 0; j < 8; j++){
	    testval = testval >> 1;
	    if(*fontp & testval)
		*addr = FRcolor;
	    else *addr = BKcolor;
	    addr++;
	}
	fontp++;
    }
    return *addr;
}
/*
 *string to number
 **s:number string
 *return: 0->string not number; other->result;
 */
int chr2num(const char **s){
    int num = 0;
    while(is_degit(**s))
	num = num * 10 + (*((*s)++) -'0');
    return num;
}

static char *number
