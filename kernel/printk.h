#ifndef __PRINTK_H__
#define __PRINTK_H__

#include <stdarg.h>
#include "font.h"

#define is_degit(c) ((c) >= '0' && (c) <= '9')

#define white	0x00ffffff
#define black	0x00000000
#define red	0x00ff0000

extern unsigned char font_ascii[256][16];

typedef struct position{
    //屏幕分辨率
    int XScreen;
    int YScreen;
    //当前光标坐标
    int Xposition;
    int YPosition;
    //字体矩阵尺寸
    int XCharSize;
    int YCharSize;
    //帧缓冲区其实地址和容量
    unsigned int *FB_addr;
    unsigned int FB_length;
}Position;
Position pos;

int color_printk(unsigned int FRcolor, unsigned int BKcolor, const char *fmt, ...);
#endif
