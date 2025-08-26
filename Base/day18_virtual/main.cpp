#include <iostream>
#include "interview.h"

int main()
{
    //useVirtualTable();

    //菱形继承
    Convertible c("TechBrand");
    c.showBrand();


    //协变返回
    Base* b = new Base();
    Base* d = new Derived();

    Base* bClone = b->clone(); // 输出: Base cloned.
    Base* dClone = d->clone(); // 输出: Derived cloned.

    delete b;
    delete d;
    delete bClone;
    delete dClone;
    return 0;
}
