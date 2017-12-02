#include <jni.h>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <memory>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "CServer.h"

template<class  T>
std::string to_string(T t)
{
    std::stringstream ss;
    ss << t;
    return ss.str();
}
std::shared_ptr<CServer> m_Server;

extern "C"
JNIEXPORT jboolean

JNICALL
Java_com_example_ehab_newp_MainActivity_initServer(  JNIEnv *env,
                                                      jobject /* this */){
    int portno=27015;
    m_Server.reset(new CServer(portno));
    m_Server->listen();
    return true;
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
