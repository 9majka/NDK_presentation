#include "NativeThread.h"
#include "Logger.h"

#include <thread>

static JavaVM* s_jvm = 0;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    DEMO_LOG("JNI_OnLoad IN\n");
    JNIEnv* env;

    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return -1;
    }

    //Save pointer to JVM
    // s_jvm = vm;

    return JNI_VERSION_1_6;
}

static void asyncRequest(JNIEnv *env)
{
    DEMO_LOG("asyncRequest env = %p", (void *)env);

    jclass clazz = env->FindClass("com/softserveinc/ndkexampledemo/JNIBridge");
    // Get the method that you want to call
    jmethodID nativeCallback = env->GetStaticMethodID(clazz, "nativeCallback", "()V");
    env->CallStaticVoidMethod(clazz, nativeCallback);
}

static void asyncRequestCorrect(JNIEnv *env)
{
    DEMO_LOG("asyncRequestCorrect env = %p", (void *)env);

    JNIEnv* threadEnv = nullptr;
    s_jvm->AttachCurrentThread(&threadEnv, nullptr);

    asyncRequest(threadEnv);

    s_jvm->DetachCurrentThread();
}

void nativeThreadNegative(JNIEnv *env)
{
    DEMO_LOG("nativeThreadNegative IN\n");

    std::thread nativeThread(asyncRequest, env);
    nativeThread.join();

    DEMO_LOG("nativeThreadNegative OUT\n");
}

void nativeThreadPositive(JNIEnv *env)
{
    DEMO_LOG("nativeThreadPositive IN\n");

    // Get pointer to the JVM
    env->GetJavaVM(&s_jvm);

    std::thread nativeThread(asyncRequestCorrect, env);
    nativeThread.join();

    DEMO_LOG("nativeThreadPositive OUT\n");
}
