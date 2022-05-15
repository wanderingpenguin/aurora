//
// Created by hansa on 5/14/2022.
//

#ifndef AURORA_METRONOME_H
#define AURORA_METRONOME_H

#include "IRenderableAudio.h"
#define DEFAULT_TEMPO 60
#define DEFAULT_SAMPLE_RATE 48000

class Metronome : public IRenderableAudio {
public:
    Metronome() {}
    Metronome(int sampleRate);
    void setSampleRate(int sampleRate);
    void setTempo(int tempo);
    void start();
    void stop();
    void render(float *audioData, int numFrames) override;

private:
    int mSampleRate = DEFAULT_SAMPLE_RATE;

    // Measured in Beats Per Minute (BPM).
    int mTempo = DEFAULT_TEMPO;

    // Elapsed frames since last beat.
    int mFramesCounter = 0;

    // Note length in samples. Default: 1/16 seconds worth of samples.
    int mNoteLengthInSamples = mSampleRate / 16;

    int mFramesPerBeat = (60.0 * mSampleRate) / mTempo;
    bool mIsPlaying = false;
};


#endif //AURORA_METRONOME_H
