# attack lab 实验记录

## 需要准备的前置内容

其实主要就是看那个attacklab.pdf。attacklab分为两个部分，第一个部分攻击ctarget（前三题），第二部分攻击rtarget（后两题），ctarget是进行Code Injection, rtarget是进行Return Oriented Programming（面向方向）

## Ctarget: level 1

目标是让getbuf返回后执行touch1函数

这题很简单，利用的就是getbuf函数返回时（ret指令执行后）会跳转到原函数下一条指令，而跳转地址就在上一个函数的stack frame的最后，我们只需要用一些文字把40个字节的缓冲区填满，然后用touch1的指令地址覆盖原函数test下一条指令的地址。

所以我的答案就是97 * 40 (97应该是'a'吧好像)然后加上c0 17 40, 用objdump -d 或者(gdb) layout asm可以查到我文件的touch1的地址是0x4017c0，很快通过测试。

## Ctarget: level 2



