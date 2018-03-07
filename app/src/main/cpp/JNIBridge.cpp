#include <jni.h>



#include "ReferenceTable.h"
#include "NativeThread.h"

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

//#include <stdio.h>
//#include <unistd.h>
//#include <signal.h>
//#include <string.h>
//
//static void on_signal (int sig, siginfo_t *siginfo, void *context)
//{
//    printf ("Sending PID: %ld, UID: %ld\n",
//            (long)siginfo->si_pid, (long)siginfo->si_uid);
//}
//
//void registerSignalHandler()
//{
//    struct sigaction act;
//
//    memset (&act, '\0', sizeof(act));
//
//    act.sa_sigaction = &on_signal;
//    act.sa_flags = SA_SIGINFO;
//    sigaction(SIGSEGV, &act, NULL) < 0)
//}
}


