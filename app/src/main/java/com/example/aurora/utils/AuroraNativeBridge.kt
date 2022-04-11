package com.example.aurora.utils

class AuroraNativeBridge {
    external fun stringFromJNI(): String

    companion object {
        init {
            System.loadLibrary("aurora")
        }
    }
}