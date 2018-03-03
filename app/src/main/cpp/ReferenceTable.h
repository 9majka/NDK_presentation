#ifndef PRESENTATION_REFERENCETABLE_H
#define PRESENTATION_REFERENCETABLE_H

#include <jni.h>

void localTableReferenceOverflowNegative(JNIEnv *env);
void localTableReferenceOverflowPositive(JNIEnv *env);

void globalTableReferenceOverflowNegative(JNIEnv *env);
void globalTableReferenceOverflowPositive(JNIEnv *env);

#endif //PRESENTATION_REFERENCETABLE_H
