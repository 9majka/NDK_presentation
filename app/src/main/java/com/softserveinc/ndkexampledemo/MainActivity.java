package com.softserveinc.ndkexampledemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ListView;

import java.util.ArrayList;

public class MainActivity extends Activity {

    private ArrayList<CaseItem> mCaseArray = new ArrayList<>();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
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
        mCaseArray.add(getLocalTableReference());
        mCaseArray.add(getGlobalTableReference());
    }

    CaseItem getLocalTableReference() {
        return new CaseItem("1. Local table reference overflow",
                new Callback() {
                    @Override
                    public void execute() {
                        localTableReferenceOverflowNegative();
                    }
                },
                new Callback() {
                    @Override
                    public void execute() {
                        localTableReferenceOverflowPositive();
                    }
                });
    }

    CaseItem getGlobalTableReference() {
        return new CaseItem("2. Global table reference overflow",
                new Callback() {
                    @Override
                    public void execute() {
                        globalTableReferenceOverflowNegative();
                    }
                },
                new Callback() {
                    @Override
                    public void execute() {
                        globalTableReferenceOverflowPositive();
                    }
                });
    }

    private native void localTableReferenceOverflowPositive();
    private native void localTableReferenceOverflowNegative();

    private native void globalTableReferenceOverflowPositive();
    private native void globalTableReferenceOverflowNegative();
}
