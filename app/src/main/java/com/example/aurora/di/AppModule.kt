package com.example.aurora.di

import com.example.aurora.utils.AuroraNativeBridge
import dagger.Module
import dagger.Provides
import dagger.hilt.InstallIn
import dagger.hilt.components.SingletonComponent
import javax.inject.Singleton

@Module
@InstallIn(SingletonComponent::class)
object AppModule {

    @Provides
    @Singleton
    fun provideAuroraNativeBridge(): AuroraNativeBridge = AuroraNativeBridge()
}