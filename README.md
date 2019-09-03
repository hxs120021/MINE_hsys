#MINE_hsys
参考：《一个64位操作系统的设计与实现》《intel汇编语言程序设计(第五版)》《x86/x64体系探索及变成》
仅自己学习使用......太菜了昂......

```
  dd if=./3_4/boot.bin of=boot.img bs=512 count=1 conv=notrunc
  sudo mount ./boot.img /media -t vfat -o loop 
	sudo cp loader.bin	/media/
  sudo cp kernel.bin /media/
	sync
	sudo umount /media/
```
