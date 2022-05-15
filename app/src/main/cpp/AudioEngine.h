//
// Created by hansa on 4/10/2022.
//

#ifndef AURORA_AUDIOENGINE_H
#define AURORA_AUDIOENGINE_H

#include <oboe/Oboe.h>
#include "Metronome.h"

class AudioEngine
        : public oboe::AudioStreamDataCallback,
          oboe::AudioStreamErrorCallback {
public:
    void startAudio();

    void stopAudio();

    void setTempo(int tempo);

    oboe::DataCallbackResult
    onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames) override;

    void onErrorAfterClose(oboe::AudioStream *stream, oboe::Result result) override;

private:
    std::shared_ptr<oboe::AudioStream> mStream;
    Metronome mMetronome;
};


#endif //AURORA_AUDIOENGINE_H
