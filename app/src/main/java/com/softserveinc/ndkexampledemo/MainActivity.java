package com.softserveinc.ndkexampledemo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ListView;

import com.softserveinc.ndkexampledemo.controller.Callback;
import com.softserveinc.ndkexampledemo.controller.CaseItem;
import com.softserveinc.ndkexampledemo.controller.CaseItemAdapter;

import java.util.ArrayList;

public class MainActivity extends Activity {

    private ArrayList<CaseItem> mCaseArray = new ArrayList<>();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("ndkdemo");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        init();

        ListView listView = findViewById(R.id.mainListView);
        CaseItemAdapter adapter = new CaseItemAdapter(this, mCaseArray);
        listView.setAdapter(adapter);
    }

    void init() {
        mCaseArray.add(getLocalTableReferenceCase());
        mCaseArray.add(getGlobalTableReferenceCase());
        mCaseArray.add(getNativeThreadCase());

    }

    CaseItem getLocalTableReferenceCase() {
        return new CaseItem("1. Local table reference overflow",
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.localTableReferenceOverflowNegative();
                    }
                },
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.localTableReferenceOverflowPositive();
                    }
                });
    }

    CaseItem getGlobalTableReferenceCase() {
        return new CaseItem("2. Global table reference overflow",
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.globalTableReferenceOverflowNegative();
                    }
                },
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.globalTableReferenceOverflowPositive();
                    }
                });
    }

    CaseItem getNativeThreadCase() {
        return new CaseItem("3. NDK native threads",
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.nativeThreadNegative();
                    }
                },
                new Callback() {
                    @Override
                    public void execute() {
                        JNIBridge.nativeThreadPositive();
                    }
                });
    }
}
