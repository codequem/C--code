//位运算的一些有趣的事
void inplace_swap(int *x,int *y)
{
    *y = *x ^ *y;//y = x ^ y
    *x = *x ^ *y;//x = x ^ (x ^ y) = y
    *y = *x ^ *y;//y = (x ^ y) ^ y = x
}

void reverse_array(int a[],int cnt)
{
    int first,last;
    //值得注意的是：first是小于last的，所以当first == last时，就不需要再交换了
    //实际上，如果再次交换，就会出现a^a=0，即数组长度为奇数时，中间一位会被置为0
    for(first = 0,last = cnt - 1;first < last;first++,last--)
        inplace_swap(&a[first],&a[last]);
}

