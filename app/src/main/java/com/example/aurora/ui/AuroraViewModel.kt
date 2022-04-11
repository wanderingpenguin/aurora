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
        MutableStateFlow(AuroraState(sampleString = auroraNativeBridge.stringFromJNI()))
    val uiState: StateFlow<AuroraState> = _uiState
}

data class AuroraState(val sampleString: String)