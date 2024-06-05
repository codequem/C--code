#include "Proxy.h"
#include "RealSubject.h"

int main()
{
    RealSubject *realSubject = new RealSubject("Proxy Pattern");
    Proxy *proxy = new Proxy(realSubject);
    proxy->Request();
    delete proxy;
    return 0;
}