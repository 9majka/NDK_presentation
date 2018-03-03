//
// Created by Oleksandr on 03.03.2018.
//

#include "Class1.h"
#include "Class2.h"

Class1::Class1()
    : mMember(new Class2)
{
}

Class1::~Class1()
{
    delete mMember;
}

void Class1::testMethod()
{
    testMethodImpl();
}

void Class1::testMethodImpl()
{
    mMember->demoMethod();
}