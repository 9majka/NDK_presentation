#include <jni.h>
#include <string>

#include "ReferenceTable.h"

extern "C"
{

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_MainActivity_localTableReferenceOverflowPositive(JNIEnv *env,
                                                                                      jobject /* this */) {
    localTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_MainActivity_localTableReferenceOverflowNegative(JNIEnv *env,
                                                                                      jobject /* this */) {
    localTableReferenceOverflowNegative(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_MainActivity_globalTableReferenceOverflowPositive(JNIEnv *env,
                                                                                      jobject /* this */) {
    globalTableReferenceOverflowPositive(env);
}

JNIEXPORT void JNICALL
Java_com_softserveinc_ndkexampledemo_MainActivity_globalTableReferenceOverflowNegative(JNIEnv *env,
                                                                                      jobject /* this */) {
    globalTableReferenceOverflowNegative(env);
}

}


