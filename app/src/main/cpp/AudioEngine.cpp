//
// Created by hansa on 4/10/2022.
//

#include "AudioEngine.h"
#include "Metronome.h"
#include <oboe/Oboe.h>
#include <android/log.h>

#define TAG "AudioEngine"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, TAG,__VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, TAG,__VA_ARGS__)

void AudioEngine::startAudio() {
    oboe::AudioStreamBuilder builder;
    oboe::Result result = builder.setSharingMode(oboe::SharingMode::Exclusive)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setChannelCount(1)
            ->setDataCallback(this)
            ->setErrorCallback(this)
            ->openStream(mStream);

    if (result != oboe::Result::OK) {
        LOGE("Error opening audio stream!");
        return;
    }

    result = mStream->requestStart();
    if (result != oboe::Result::OK) {
        LOGE("Error starting audio stream!");
        return;
    }

    mMetronome.setSampleRate(mStream->getSampleRate());
    mMetronome.start();
}

void AudioEngine::stopAudio() {
    mMetronome.stop();

    if (mStream) {
        mStream->stop();
        mStream->close();
        mStream.reset();
    }
}

oboe::DataCallbackResult
AudioEngine::onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) {
    auto buffer = static_cast<float *>(audioData);
    mMetronome.render(buffer, numFrames);
    return oboe::DataCallbackResult::Continue;
}

void AudioEngine::onErrorAfterClose(oboe::AudioStream *stream, oboe::Result result) {
    AudioStreamErrorCallback::onErrorAfterClose(stream, result);
}

void AudioEngine::setTempo(int tempo) {
    mMetronome.setTempo(tempo);
}
