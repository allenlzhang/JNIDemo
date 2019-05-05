package com.carlt.jnidemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    //    static {
    //        System.loadLibrary("JNITestSample");//名字注意，需要跟你的build.gradle ndk节点       下面的名字一样
    //    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.e("----", add(1, 2) + "");
        JNIUtils jniUtils = new JNIUtils();
        String s = jniUtils.helloJNI();
        Log.e("----", s);
    }

    public void noParamMethod() {
        Log.e("----", "无参的Java方法被调用了");
    }

    public static void test1() {
        Log.e("----", "静态的java方法被调用了");
    }

    public void paramMethod(int num) {
        Log.e("----", "有参的Java方法被调用了" + num);
    }

    public void paramStrMethod(String num) {
        Log.e("----", "有参的Java方法被调用了" + num);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String resultFromJNI();

    public native void testJNI();

    public native void testStaticJNI();

    public native void testParamJNI();

    public native void testStrParamJNI();

    public native int add(int a, int b);

    public void callJNI(View view) {
        //        testJNI();
        testStaticJNI();
    }

    public void callJNInoParam(View view) {
        testJNI();
    }

    public void callJNIhasParam(View view) {
        testParamJNI();
    }

    public void callJNIhasParamStr(View view) {
        testStrParamJNI();
    }
}
