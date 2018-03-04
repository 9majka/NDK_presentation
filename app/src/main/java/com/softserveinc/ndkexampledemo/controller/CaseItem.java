package com.softserveinc.ndkexampledemo.controller;

public class CaseItem {
    private String mLabel;
    private Callback mNegative;
    private Callback mPositive;

    public CaseItem(String label, Callback negative, Callback positive) {
        mLabel = label;
        mNegative = negative;
        mPositive = positive;
    }

    public String getLabel() {
        return mLabel;
    }

    public Callback getNegative() {
        return mNegative;
    }

    public Callback getPositive() {
        return mPositive;
    }
}
