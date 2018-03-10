#include <stdexcept>
#include "Class2.h"
#include "Logger.h"

void Class2::demoMethod()
{
    demoMethodImpl();
}

void Class2::demoMethodImpl()
{
    DEMO_LOG("Class2::demoMethodImpl IN\n");
   // throw new std::runtime_error("Shouldn't be called");
    int *ptr = nullptr;
    volatile bool check = true;
    if(check)
    {
        DEMO_LOG("Class2::demoMethodImpl %d\n", *ptr);
    }

    DEMO_LOG("Class2::demoMethodImpl OUT\n");
}
