package com.example.aurora.ui

import androidx.compose.material.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.res.stringResource
import com.example.aurora.R

@Composable
fun AuroraApp() {
    Text(text = stringResource(id = R.string.app_name))
}