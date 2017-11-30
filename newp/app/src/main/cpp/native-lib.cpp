#include <jni.h>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>

template<class  T>
std::string to_string(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_ehab_newp_MainActivity_stringFromJNI(
       JNIEnv *env,
        jobject /* this */) {
    cv::Rect();
    cv::Mat();
    cv::VideoCapture Cap(0);
    std::string hello;
    if(Cap.isOpened())
        hello = "Camira is opened";
    else
        hello = "Camira is closed";
    return env->NewStringUTF(hello.c_str());
}
