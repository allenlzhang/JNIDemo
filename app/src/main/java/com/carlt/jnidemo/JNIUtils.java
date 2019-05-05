package com.carlt.jnidemo;

/**
 * Description:
 * Company    : carlt
 * Author     : zhanglei
 * Date       : 2019/3/21 14:36
 */
public class JNIUtils {

    public native String helloJNI();

    public native int add(int a, int b);
}
