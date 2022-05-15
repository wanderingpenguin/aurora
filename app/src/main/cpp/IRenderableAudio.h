//
// Created by hansa on 5/14/2022.
//

#ifndef AURORA_IRENDERABLEAUDIO_H
#define AURORA_IRENDERABLEAUDIO_H

class IRenderableAudio {
public:
    virtual ~IRenderableAudio() = default;
    virtual void render(float *audioData, int numFrames) = 0;
};

#endif //AURORA_IRENDERABLEAUDIO_H