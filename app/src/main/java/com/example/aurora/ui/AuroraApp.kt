package com.example.aurora.ui

import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.lifecycle.viewmodel.compose.viewModel

@Composable
fun AuroraApp() {
    val auroraViewModel: AuroraViewModel = viewModel()
    val uiState = auroraViewModel.uiState.collectAsState()
    Text(text = uiState.value.sampleString)
}