//
// Created by hansa on 5/14/2022.
//

#include "Metronome.h"
#include <memory>

Metronome::Metronome(int sampleRate) {
    mSampleRate = sampleRate;
}

void Metronome::setTempo(int tempo) {
    mTempo = tempo;
    mFramesPerBeat = int ((60.0 * mSampleRate) / tempo);
}

void Metronome::start() {
    mIsPlaying = true;
}

void Metronome::stop() {
    mIsPlaying = false;
    mFramesCounter = 0;
}

void Metronome::render(float *audioData, int numFrames) {
    if (!mIsPlaying) {
        memset(audioData, 0, sizeof(float) * numFrames);
    } else {
        for (int i = 0; i < numFrames; i++) {
            if (mFramesCounter >= (int) mFramesPerBeat) {
                mFramesCounter = 0;
            }

            if (mFramesCounter <= mNoteLengthInSamples) {
                audioData[i] = 420;
            } else {
                audioData[i] = 0;
            }

            mFramesCounter++;
        }
    }
}

void Metronome::setSampleRate(int sampleRate) {
    mSampleRate = sampleRate;
    mFramesPerBeat = int ((60.0 * mSampleRate) / mTempo);
}
