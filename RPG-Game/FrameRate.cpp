#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : timer(0) {
    
}

void FrameRate::Initialize() {
    timer = 0;
}

void FrameRate::Load() {
    if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "Font Loaded" << std::endl;
        frameRateText.setFont(font);
    }
    else {
        std::cout << "Failed to load font" << std::endl;
    }
}

void FrameRate::Update(float deltaTime) {
    timer += deltaTime;
    if (timer >= 100.0) {
        float result = 1000.0 / deltaTime;
        frameRateText.setString("FPS: " + std::to_string((int)result) + " FrameTime: " + std::to_string((int)deltaTime));
    }
}

void FrameRate::Draw(sf::RenderWindow& window) {
    window.draw(frameRateText);
}