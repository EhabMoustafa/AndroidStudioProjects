#include <jni.h>
#include <string>
#include <chrono>
#include <sstream>
#include <queue>

#include <sstream>

template <class T>
inline std::string to_string (const T& t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_ehab_test_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_ehab_test_MainActivity_doQueueTests(
        JNIEnv *env,
jobject /* this */) {
    std::string hello;;
    std::chrono::system_clock::time_point stTime = std::chrono::system_clock::now();
    std::queue<int> q;
    for(int i=0;i<100;i++){
        q.push(i);
    }
    std::chrono::system_clock::duration dur = (std::chrono::system_clock::now() - stTime);
    hello = "C++ Queue add 10000 time = " + to_string(dur.count());
    return env->NewStringUTF(hello.c_str());
}
