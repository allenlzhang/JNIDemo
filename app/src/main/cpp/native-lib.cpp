#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_carlt_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_carlt_jnidemo_MainActivity_resultFromJNI(JNIEnv *env, jobject instance) {

    std::string result = "success";
    return env->NewStringUTF(result.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carlt_jnidemo_MainActivity_testJNI(JNIEnv *env, jobject instance) {
    jclass clazz = env->FindClass("com/carlt/jnidemo/MainActivity");
    if (clazz == NULL) {
        printf("class is null");
        return;
    }
    jmethodID id = env->GetMethodID(clazz, "noParamMethod", "()V");
    if (id == NULL) {
        printf("methodID is null");
        return;

    }
    env->CallVoidMethod(instance, id);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carlt_jnidemo_MainActivity_testStaticJNI(JNIEnv *env, jobject instance) {

    jclass clazz = env->FindClass("com/carlt/jnidemo/MainActivity");

    if (clazz == NULL) {
        printf("class is null");
        return;
    }
    jmethodID methodID = env->GetStaticMethodID(clazz, "test1", "()V");
    if (methodID == NULL) {
        printf("methodID is null");
        return;
    }
    env->CallStaticVoidMethod(clazz, methodID);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_carlt_jnidemo_MainActivity_testParamJNI(JNIEnv *env, jobject instance) {
    jclass clazz = env->FindClass("com/carlt/jnidemo/MainActivity");
    if (clazz == NULL) {
        printf("class is null");
        return;
    }


    jmethodID id = env->GetMethodID(clazz, "paramMethod", "(I)V");
    if (id == nullptr) {
        printf("id is null");
        return;
    }
//    std::string a = "我是JNI传来的数据";
    int a = 98;
    env->CallVoidMethod(instance, id, a);

}extern "C"
JNIEXPORT void JNICALL
Java_com_carlt_jnidemo_MainActivity_testStrParamJNI(JNIEnv *env, jobject instance) {
    jclass clazz = env->FindClass("com/carlt/jnidemo/MainActivity");
    if (clazz == NULL) {
        printf("class is null");
        return;
    }
    jmethodID id = env->GetMethodID(clazz, "paramStrMethod", "(Ljava/lang/String;)V");
    std::string a = "我是JNI传来的数据";
    jstring str = env->NewStringUTF(a.c_str());
    env->CallVoidMethod(instance, id, str);
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_carlt_jnidemo_MainActivity_add(JNIEnv *env, jobject instance, jint a, jint b) {

    // TODO
    return a + b;

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_carlt_jnidemo_JNIUtils_helloJNI(JNIEnv *env, jobject instance) {


    std::string str = "MIIEowIBAAKCAQEA1LUwhOyN1hOnrV3g2COyqpcUax8Fq1/0Xuy74ZphNpszZ21c\\n\" +\n"
                      "            \"2CnzXjzbD54kyW8EOOGeDPJvNsWrjyas9VsSxE0nXVARz3yyMBMtNEq42+o8Sd+F\\n\" +\n"
                      "            \"l2PWHOc/uH3BjXM80kmqvonD5sGCYR4wRcThXKuZR9t0ahEZkiH5WNFghSyQEWXH\\n\" +\n"
                      "            \"xvoNNfR5sElArZLS86Ey1R7U5Z0BX9GcRyfXldER61oA71EfOnLoh/XXjtr78ja4\\n\" +\n"
                      "            \"Iq7XJKiYkXqKNTSgHhbQe8g8Qw7xb040Dw9ljOV99q4RoTlQUp7NEmwQYne+b920\\n\" +\n"
                      "            \"TFm67AMVCL9KPCLZneuwfIyXiLidy4RDcWusPwIDAQABAoIBAHxxfO9njhu+6Ayv\\n\" +\n"
                      "            \"rcoGKJNRTGrXfXOj8c5PZiQ5M8LEzjAmdXkqIe3yYJ8kgJUw1CGLLfKZK6O5xgM8\\n\" +\n"
                      "            \"N1hcbgBWuz8Gh0UCySUDMyEyzjArPBZkJT5K9It4Z3lCaaid0Omem7xZ0TkB4Yt8\\n\" +\n"
                      "            \"I/XNl6Ol6Ul3BQbA9lrecYkbBgMi26g/ISF/Ul93aN2/M+IVqdyHL3b2MJ5N5uSU\\n\" +\n"
                      "            \"ed+/JVzes3Kfl+vkMV4PuusO7MIAkA7D3EkZmP2Az2Y8cN2QeLoQIZn+7jZAoSTZ\\n\" +\n"
                      "            \"rDOKBH36PcnPTUK2qoDbhAujOTL0KLT7x83I4eiBLxGAxiPa2Tfi6UKbOh1/ldHC\\n\" +\n"
                      "            \"1jTjoaECgYEA95YM03LpZHgvEcIoqfUYKn20rdjQP1ORIXUMrWQWb5x0dLedst3v\\n\" +\n"
                      "            \"AN8pqxXtuJNsSwyyxxH5hu5s4Q0M1JFE/lVPs/M1KrfhgFWOksbLfKj0qbJlOYJU\\n\" +\n"
                      "            \"Dls49AY7UTUWSJhcZqoX9o5tlt+h5RyOYR9hlwLAOxg10e6AM7ut1KkCgYEA2++0\\n\" +\n"
                      "            \"Y9bcD4Eso8JvJl53WMQCGUnhOMznuAAPGHEMib62d7krkA0OVI6HjeUgaYq7vYUk\\n\" +\n"
                      "            \"ynsHlWpriwegtmozL3YdJnsjJsSQs9Fyfj96KjBl4zV+tIG9GHeGSnOC58HjqMOy\\n\" +\n"
                      "            \"1uklZJXBPeK3WZTsh6VG7+VsnJW6qJniKDO7oqcCgYB49TPa8h8YWKcWU/ct4XIn\\n\" +\n"
                      "            \"ADcPYAeNiLQ01kyVQXq8mIFErJg81LR5ho2C6jmznUKg/9kv7JYt17oV0RxdlYNR\\n\" +\n"
                      "            \"hjhkQAPPlPp0ilgXWUv84UZ2yZMun3+Va/fNMGY2bGswmE88UQlYCYl81lDv8B2X\\n\" +\n"
                      "            \"UY+KCWwE8vUIVS8JFz370QKBgA4XaqBm+MyJgzmu0H5N2Sm3zUafhC2me0Y/wrfX\\n\" +\n"
                      "            \"Lm146an8FD1ziLKEO00tHAmHGQZIjJXokhDRs7hBsdteLI9i6vU3OIZYW8kZp1NN\\n\" +\n"
                      "            \"b99aIH0RRV/9XAdASTtl8UI2GwcKGuBIKdwq+Cml6Ad2Uj1SqpveQDo8IayBx4q5\\n\" +\n"
                      "            \"3dDLAoGBAJ17zUU/ko8fFxcOwlyPnDIMaXsIxjQ/e726+WEB/3c+Zlnazy2yzxiy\\n\" +\n"
                      "            \"dwWsWi0aGRfYMzU7XxYk1853zsJEosgvJLbqlu8Cj8uFj/E02f4E++rDW5JGz7ez\\n\" +\n"
                      "            \"8WIzdo8RIXSTegItyq/XSMeFthpZVgNfwM7pRR1UAb0+IACP1XKs\"";
//    jstring value = env->NewStringUTF(str.c_str());
    return env->NewStringUTF(str.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_carlt_jnidemo_JNIUtils_add(JNIEnv *env, jobject instance, jint a, jint b) {

    return a + b;

}