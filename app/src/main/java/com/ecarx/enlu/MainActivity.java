package com.ecarx.enlu;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.ecarx.enlu.utils.Clibrary;


public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int create_alrm = Clibrary.INSTANCE.create_alarm();
                int insert_alarm = Clibrary.INSTANCE.insert_alarm();
                Log.d(TAG, "onClick: >>>getInt: " + insert_alarm);
                Toast.makeText(MainActivity.this, "getInt:" + insert_alarm, Toast.LENGTH_SHORT).show();
            }
        });

    }
}
