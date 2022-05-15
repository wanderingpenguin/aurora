package com.example.aurora.ui

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material.Button
import androidx.compose.material.Slider
import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.stringResource
import androidx.lifecycle.viewmodel.compose.viewModel
import com.example.aurora.R

@Composable
fun AuroraApp() {
    val auroraViewModel: AuroraViewModel = viewModel()
    val uiState = auroraViewModel.uiState.collectAsState()

    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Button(onClick = { auroraViewModel.toggleIsPlaying() }) {
            Text(
                text = if (uiState.value.isPlaying) stringResource(id = R.string.action_pause)
                else stringResource(id = R.string.action_play)
            )
        }

        Row(verticalAlignment = Alignment.CenterVertically) {
            Text(text = stringResource(id = R.string.label_tempo, uiState.value.tempo))
            Slider(
                value = uiState.value.tempo.toFloat(),
                onValueChange = { tempo -> auroraViewModel.setTempo(tempo.toInt()) },
                steps = 120,
                valueRange = 60f..180f,
                modifier = Modifier.weight(1f)
            )
        }
    }
}