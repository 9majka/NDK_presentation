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

        // NPE
        Object someObj = null;
        Log.i("JNIBridge", "nativeCallbackWithException: " + someObj.toString());
    }

    public static void exceptionFromJNI() {
        try {
            throwException();
        } catch (IllegalArgumentException ex) {
            Log.i("JNIBridge", "Java: IllegalArgumentException is caught: " + ex);
        } catch (Exception ex) {
            Log.i("JNIBridge", "Java: Exception is caught: " + ex);
        }

    }


    public static native void localTableReferenceOverflowPositive();
    public static native void localTableReferenceOverflowNegative();

    public static native void globalTableReferenceOverflowPositive();
    public static native void globalTableReferenceOverflowNegative();

    public static native void nativeThreadNegative();
    public static native void nativeThreadPositive();

    public static native void pendingException();
    public static native void pendingExceptionPositive();
    public static native void throwException();
    public static native void crashSignal();
}
