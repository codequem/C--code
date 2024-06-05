#include "Proxy.h"

int main()
{
    Proxy *proxy = new Proxy();
    proxy->Request();
    delete proxy;
    return 0;
}