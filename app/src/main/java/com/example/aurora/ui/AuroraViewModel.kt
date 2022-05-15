package com.example.aurora.ui

import androidx.lifecycle.ViewModel
import com.example.aurora.utils.AuroraNativeBridge
import dagger.hilt.android.lifecycle.HiltViewModel
import kotlinx.coroutines.flow.MutableStateFlow
import kotlinx.coroutines.flow.StateFlow
import javax.inject.Inject

@HiltViewModel
class AuroraViewModel @Inject constructor(
    private val auroraNativeBridge: AuroraNativeBridge
) : ViewModel() {
    private val _uiState: MutableStateFlow<AuroraState> =
        MutableStateFlow(AuroraState(isPlaying = false))
    val uiState: StateFlow<AuroraState> = _uiState

    fun toggleIsPlaying() {
        val isPlaying = _uiState.value.isPlaying
        if (isPlaying) {
            auroraNativeBridge.stopAudio()
        } else {
            auroraNativeBridge.startAudio()
        }

        _uiState.value = _uiState.value.copy(isPlaying = !isPlaying)
    }

    fun setTempo(tempo: Int) {
        _uiState.value = _uiState.value.copy(tempo = tempo)
        auroraNativeBridge.setTempo(tempo)
    }
}

data class AuroraState(val isPlaying: Boolean, val tempo: Int = 60)