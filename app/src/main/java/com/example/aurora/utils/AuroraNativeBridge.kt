package com.example.aurora.utils

class AuroraNativeBridge {
    external fun startAudio()

    external fun stopAudio()

    companion object {
        init {
            System.loadLibrary("aurora")
        }
    }
}