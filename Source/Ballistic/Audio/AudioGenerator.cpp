#include "AudioGenerator.h"
#include <iostream>
#include <cmath>

namespace Audio {

    void AudioGenerator::generateTone(float frequency, float duration, std::vector<float>& output) {
        // Sample rate and total samples
        const int sampleRate = 44100;
        int totalSamples = static_cast<int>(sampleRate * duration);
        
        output.resize(totalSamples);
        for (int i = 0; i < totalSamples; ++i) {
            output[i] = 0.5f * sin(2 * M_PI * frequency * (i / static_cast<float>(sampleRate)));
        }
    }

    void AudioGenerator::playSound(const std::vector<float>& soundData) {
        // This is a placeholder for playback logic
        for (const auto& sample : soundData) {
            // In a real application, you would send the sample to an audio output device
            std::cout << sample << " ";
        }
        std::cout << std::endl; // End playback simulation
    }

}