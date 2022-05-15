package com.example.aurora.utils

class AuroraNativeBridge {
    external fun startAudio()

    external fun stopAudio()

    external fun setTempo(tempo: Int)

    companion object {
        init {
            System.loadLibrary("aurora")
        }
    }
}