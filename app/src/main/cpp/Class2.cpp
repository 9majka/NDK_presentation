//
// Created by Oleksandr on 03.03.2018.
//

#include "Class2.h"

void Class2::demoMethod()
{
    demoMethodImpl();
}

void Class2::demoMethodImpl()
{
    int * ptr = reinterpret_cast<int *>(5);

    int value = *ptr;
}
