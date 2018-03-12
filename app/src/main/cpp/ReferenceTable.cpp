#include "ReferenceTable.h"
#include "Logger.h"
#include "Class1.h"

#include <vector>

std::vector<jobject > globalArray;

void localTableReferenceOverflowNegative(JNIEnv *env)
{
    DEMO_LOG("localTableReferenceOverflowNegative\n");

    for(int i = 0; i< 600; i++)
    {
        jstring testString = env->NewStringUTF("Test String");
        jbooleanArray arrayB = env->NewBooleanArray(42);
        jcharArray arrayC = env->NewCharArray(42);
        // do something
    }

    DEMO_LOG("localTableReferenceOverflowNegative DONE\n");
}

void localTableReferenceOverflowPositive(JNIEnv *env)
{
    DEMO_LOG("localTableReferenceOverflowPositive\n");
    for(int i = 0; i< 600; i++)
    {
        jstring testString = env->NewStringUTF("Test String");
        jbooleanArray arrayB = env->NewBooleanArray(5);
        jcharArray arrayC = env->NewCharArray(4);

        // Call some method on the Java side

        // Release immediately
        env->DeleteLocalRef(testString);
        env->DeleteLocalRef(arrayB);
        env->DeleteLocalRef(arrayC);
    }

    DEMO_LOG("localTableReferenceOverflowPositive DONE\n");
}

void globalTableReferenceOverflowNegative(JNIEnv *env)
{
    DEMO_LOG("globalTableReferenceOverflowNegative\n");

    for(int i = 0; i< 100000; i++)
    {
        jstring testString = env->NewStringUTF("Test String");

        jobject globalObject = env->NewGlobalRef(testString);
        globalArray.push_back(globalObject);

        env->DeleteLocalRef(testString);
    }

    DEMO_LOG("globalTableReferenceOverflowNegative DONE\n");
}

void globalTableReferenceOverflowPositive(JNIEnv *env)
{
    DEMO_LOG("globalTableReferenceOverflowPositive IN\n");

    Class1 test;
    test.testMethod();
}

