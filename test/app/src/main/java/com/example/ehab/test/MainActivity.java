package com.example.ehab.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.opencv.android.OpenCVLoader;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private void display(){
        EditText pt = (EditText) findViewById(R.id.editText);
        Integer x = Integer.valueOf(pt.getText().toString());

        EditText pt2 = (EditText) findViewById(R.id.editText2);
        Integer y = Integer.valueOf(pt2.getText().toString());

        Button bt =  (Button) findViewById(R.id.button);
        Integer sum = Integer.valueOf(x+y);
        bt.setText(sum.toString());

    }

    private void display_c_queue_test(){
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(doQueueTests());
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        Button bt =  (Button) findViewById(R.id.button);
        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                display_c_queue_test();
            }
        });
        Button bt2 =  (Button) findViewById(R.id.button2);
        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Button bt =  (Button) findViewById(R.id.button2);
          if (OpenCVLoader.initDebug()) {

              bt.setText("OpenCV On");
                } else {

              bt.setText("OpenCV Off");
                }
            // start activity 2
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String doQueueTests();
}
