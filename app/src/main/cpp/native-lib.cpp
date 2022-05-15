#include <jni.h>
#include <string>
#include <android/log.h>
#include "AudioEngine.h"

#define TAG "NativeLib"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, TAG,__VA_ARGS__)

AudioEngine engine;

extern "C"
JNIEXPORT void JNICALL
Java_com_example_aurora_utils_AuroraNativeBridge_startAudio(JNIEnv *env, jobject thiz) {
    LOGI("startAudio");
    engine.startAudio();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_aurora_utils_AuroraNativeBridge_stopAudio(JNIEnv *env, jobject thiz) {
    LOGI("stopAudio");
    engine.stopAudio();
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_aurora_utils_AuroraNativeBridge_setTempo(JNIEnv *env, jobject thiz, jint tempo) {
    engine.setTempo(tempo);
}