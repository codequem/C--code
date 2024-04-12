//打印变量的字节表示
#include <stdio.h>
#include <iostream>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
        printf("%.2x", start[i]);//start是一个指向一个字节的地址的指针，那start[i]实际上是这个地址上的内容
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));//取地址运算符&创建一个指针，指向x的地址
    //这个指针的类型是int *，然后强制转换为byte_pointer类型,使它符合show_bytes函数的参数类型
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{
    int a = -12345;
    float b = 12345.0;
    int *c = &a;
    show_int(a);//在该地址上的内容为0x00003039，按照十六进制转十进制，可知就是12345
    show_int(unsigned(a));
    std::cout<<unsigned(a)<<std::endl;
    show_float(b);//在该地址上的内容为0x4640E400，这说明浮点数有特殊的编码规则
    show_pointer(c);
    getchar();
    return 0;
}