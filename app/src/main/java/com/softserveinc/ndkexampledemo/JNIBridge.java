package com.softserveinc.ndkexampledemo;

import android.util.Log;

public class JNIBridge {

    public static void nativeCallback()
    {
        Log.i("JNIBridge", "nativeCallback: IN");
    }

    public static void nativeCallbackWithException() throws Exception
    {
        Log.i("JNIBridge", "nativeCallbackWithException: IN");
        throw new Exception("Some Exception");
    }


    public static native void localTableReferenceOverflowPositive();
    public static native void localTableReferenceOverflowNegative();

    public static native void globalTableReferenceOverflowPositive();
    public static native void globalTableReferenceOverflowNegative();

    public static native void nativeThreadNegative();
    public static native void nativeThreadPositive();
}
