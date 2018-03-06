#include "Class2.h"
#include "Logger.h"

void Class2::demoMethod()
{
    demoMethodImpl();
}

void Class2::demoMethodImpl()
{
    DEMO_LOG("Class2::demoMethodImpl IN\n");
    throw 42;
}
