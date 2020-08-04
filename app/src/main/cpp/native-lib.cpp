#include <jni.h>
#include <string>
#include <utils/RefBase.h>
#include <binder/IServiceManager.h>
#include <system/audio.h>
#include <system/audio-base.h>
#include <media/IAudioFlinger.h>
#include <media/IAudioPolicyService.h>
#include <log/log.h>

using namespace android;

extern "C" JNIEXPORT jstring JNICALL
Java_com_wyze_bindertest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    sp<IServiceManager> sm = defaultServiceManager();

    sp<IBinder> aps_binder;
    aps_binder = sm->getService(String16("media.audio_policy"));
    sp<IAudioPolicyService> aps = interface_cast<IAudioPolicyService>(aps_binder);

    sp<IBinder> af_binder;
    af_binder = sm->getService(String16("media.audio_flinger"));
    sp<IAudioFlinger> af = interface_cast<IAudioFlinger>(af_binder);

    audio_io_handle_t output = aps->getOutput(AUDIO_STREAM_MUSIC);
    float volume = af->streamVolume(AUDIO_STREAM_MUSIC, output);
    std::string hello = std::string("AudioFlinger AUDIO_STREAM_MUSIC Volume: ") + std::to_string(volume);
    
    return env->NewStringUTF(hello.c_str());
}


