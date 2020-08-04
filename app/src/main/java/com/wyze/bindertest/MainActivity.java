package com.wyze.bindertest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.AsyncTask;
import android.os.Bundle;
import android.os.SystemClock;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private TextView mTextView;
    private boolean runFlag = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        mTextView = findViewById(R.id.sample_text);
        mTextView.setText(stringFromJNI());
        new Thread() {
            @Override
            public void run() {
                while (runFlag) {
                    String retStr = stringFromJNI();
                    Log.d("Java", retStr);
                    SystemClock.sleep(1000);
                }
            }
        }.start();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mTextView.setText(stringFromJNI());
    }

    @Override
    protected void onStop() {
        super.onStop();
//        runFlag = false;
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
