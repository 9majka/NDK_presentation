#include <jni.h>



#include "ReferenceTable.h"
#include "NativeThread.h"
#include "Exception.h"

extern "C"
{

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_localTableReferenceOverflowPositive(JNIEnv *env, jclass /* this */)
{
    localTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_localTableReferenceOverflowNegative(JNIEnv *env, jclass /* this */)
{
    localTableReferenceOverflowNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_globalTableReferenceOverflowPositive(JNIEnv *env, jclass /* this */)
{
    globalTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_globalTableReferenceOverflowNegative(JNIEnv *env, jclass /* this */)
{
    globalTableReferenceOverflowNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_nativeThreadNegative(JNIEnv *env, jclass thiz)
{
    nativeThreadNegative(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_nativeThreadPositive(JNIEnv *env, jclass thiz)
{
    nativeThreadPositive(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_pendingException(JNIEnv *env, jclass thiz)
{
    pendingException(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_pendingExceptionPositive(JNIEnv *env, jclass thiz)
{
    pendingExceptionPositive(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_throwException(JNIEnv *env, jclass thiz)
{
    throwException(env, thiz);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_crashSignal(JNIEnv *env, jclass thiz)
{
    crashHandler(env, thiz);
}

}


