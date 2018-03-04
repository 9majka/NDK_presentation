#include <jni.h>

#include "ReferenceTable.h"
#include "NativeThread.h"

extern "C"
{

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_localTableReferenceOverflowPositive(JNIEnv *env,
                                                                                      jclass /* this */) {
    localTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_localTableReferenceOverflowNegative(JNIEnv *env,
                                                                                   jclass /* this */) {
    localTableReferenceOverflowNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_globalTableReferenceOverflowPositive(JNIEnv *env,
                                                                                    jclass /* this */) {
    globalTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_globalTableReferenceOverflowNegative(JNIEnv *env,
                                                                                    jclass /* this */) {
    globalTableReferenceOverflowNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_nativeThreadNegative(JNIEnv *env,
                                                                                    jclass /* this */) {
    nativeThreadNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_JNIBridge_nativeThreadPositive(JNIEnv *env,
                                                                                    jclass /* this */) {
    nativeThreadPositive(env);
}

}


