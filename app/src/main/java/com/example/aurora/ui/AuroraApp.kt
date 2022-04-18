package com.example.aurora.ui

import androidx.compose.material.Button
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.ui.res.stringResource
import androidx.lifecycle.viewmodel.compose.viewModel
import com.example.aurora.R

@Composable
fun AuroraApp() {
    val auroraViewModel: AuroraViewModel = viewModel()
    val uiState = auroraViewModel.uiState.collectAsState()

    Button(onClick = { auroraViewModel.toggleIsPlaying() }) {
        Text(
            text = if (uiState.value.isPlaying) stringResource(id = R.string.action_pause)
            else stringResource(id = R.string.action_play)
        )
    }
}