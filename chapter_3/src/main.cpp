//#include "ConcreteComponent.h"
//#include "ConcreteDecorator_1.h"
//#include "ConcreteDecorator_2.h" 

#include "Person.h"
#include "Finery.h"


int main(void)
{
    //ConcreteComponent* component = new ConcreteComponent();
    //ConcreteDecorator_1* decorator_1 = new ConcreteDecorator_1();
    //ConcreteDecorator_2* decorator_2 = new ConcreteDecorator_2();

    //在没有改变原有类的情况下，动态地给一个对象添加一些额外的职责，装饰模式比生成子类更为灵活
    //decorator_1->SetComponent(*component);
    //decorator_2->SetComponent(*decorator_1);
    //decorator_2->Operation();

    Person* person = new Person("Tom");
    TShirt* tShirts = new TShirt();
    BigTrouser* bigTrouser = new BigTrouser();
    Sneakers* sneakers = new Sneakers();
    Suit* suit = new Suit();

    tShirts->decorate(person);
    bigTrouser->decorate(tShirts);
    sneakers->decorate(bigTrouser);
    suit->decorate(sneakers);

    suit->show();
    
    return 0;
}