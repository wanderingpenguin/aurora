//
// Created by hansa on 4/17/2022.
//

#ifndef AURORA_OSCILLATOR_H
#define AURORA_OSCILLATOR_H

#include "math.h"

constexpr float kDefaultAmplitude = 0.5;
constexpr float kDefaultFrequency = 440 ;
constexpr int kDefaultSampleRate = 48000;
constexpr double kPi = M_PI;
constexpr double kTwoPi = kPi * 2;

class Oscillator {
public:
    void renderAudio(float *audioData, int32_t numFrames) {
        for (int i = 0; i < numFrames; ++i) {
            audioData[i] = mAmplitude * sinf(mPhase);
            mPhase += kTwoPi * mFrequency / mSampleRate;
            if (mPhase >= kTwoPi) mPhase -= kTwoPi;
        }
    }

private:
    int mSampleRate = kDefaultSampleRate;
    float mAmplitude = kDefaultAmplitude;
    float mFrequency = kDefaultFrequency;
    float mPhase = 0.0;
};

#endif //AURORA_OSCILLATOR_H
