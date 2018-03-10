#include "Exception.h"
#include "Logger.h"

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <exception>
#include <stdexcept>

void pendingException(JNIEnv *env, jclass clazz)
{
//    env->ExceptionCheck();
//    env->ExceptionClear();

    jmethodID nativeCallbackWithException = env->GetStaticMethodID(clazz, "nativeCallbackWithException", "()V");
    env->CallStaticVoidMethod(clazz, nativeCallbackWithException);
}

void pendingExceptionPositive(JNIEnv *env, jclass clazz)
{
    jmethodID nativeCallbackWithException = env->GetStaticMethodID(clazz, "nativeCallbackWithException", "()V");
    env->CallStaticVoidMethod(clazz, nativeCallbackWithException);
    if(env->ExceptionCheck())
    {
        DEMO_LOG("Exception is pending. Ignore it\n");
        env->ExceptionClear();
    }
}

void throwException(JNIEnv *env, jclass thiz)
{
    try
    {
        // Do something
        throw std::invalid_argument("Invalid argument");
    }
    catch (const std::exception & exception)
    {
        DEMO_LOG("Exception is caught: %s\n", exception.what());
        jclass exClass = env->FindClass("java/lang/IllegalArgumentException");
        env->ThrowNew(exClass, exception.what());

        DEMO_LOG("Exception is thrown\n");
        DEMO_LOG("But we still here\n");
        DEMO_LOG("Java will catch it once we return from native method\n");
    }
}

static void on_signal (int sig, siginfo_t *siginfo, void *context)
{
    printf ("Sending PID: %ld, UID: %ld\n",
            (long)siginfo->si_pid, (long)siginfo->si_uid);

    DEMO_LOG("Sending PID: %ld, UID: %ld\n", (long)siginfo->si_pid, (long)siginfo->si_uid)
}


static void registerSignalHandler()
{
    struct sigaction act;

    memset (&act, '\0', sizeof(act));

    act.sa_sigaction = &on_signal;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &act, NULL);
}

void crashHandler(JNIEnv *env, jclass thiz)
{
    registerSignalHandler();
}


//


