package com.softserveinc.ndkexampledemo;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.List;

public class CaseItemAdapter extends ArrayAdapter<CaseItem> {

    public CaseItemAdapter(Context context, List<CaseItem> objects) {
        super(context, R.layout.case_item, objects);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View v = convertView;

        if (v == null) {
            LayoutInflater vi;
            vi = LayoutInflater.from(getContext());
            v = vi.inflate(R.layout.case_item, null);
        }

        final CaseItem caseItem = getItem(position);

        if (caseItem != null) {
            TextView label = v.findViewById(R.id.label);
            label.setText(caseItem.getLabel());

            v.findViewById(R.id.negative).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    caseItem.getNegative().execute();
                }
            });

            v.findViewById(R.id.positive).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    caseItem.getPositive().execute();
                }
            });
        }

        return v;
    }

}