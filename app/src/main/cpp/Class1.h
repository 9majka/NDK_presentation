//
// Created by Oleksandr on 03.03.2018.
//

#ifndef PRESENTATION_CLASS1_H
#define PRESENTATION_CLASS1_H

class Class2;

class Class1
{
public:
    Class1();
    ~Class1();
    void testMethod();
    void testMethodImpl();

private:
    Class2 * mMember;
};


#endif //PRESENTATION_CLASS1_H
