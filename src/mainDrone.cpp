#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include "Flight.h"
#include "AircraftData.h"
#include "Obstacle.h"
#include <random>

void PrintFlightDetails(const Vector2& positionStart, const Vector2& positionEnd, const float& displacementX, const float& displacementY, const float& distanceTo) {
    std::cout << "Details: \nFlight start position: (" << positionStart.x << ", " << positionStart.y << ")\n"
              << "Flight end position: (" << positionEnd.x << ", " << positionEnd.y << ")\n"
              << "Flight displacement: (" << displacementX << ", " << displacementY << ")\n"
              << "Flight distance to: " << distanceTo << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
}

void printLiveInfo(const Vector2& position) { // for printing more live data later
    std::cout << "\nCurrent Position: (" << position.x << ", " << position.y << ")";
}

void sleepMilliseconds(const int& x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

float randomFloat(float minimum, float maximum) {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_real_distribution<float> distribution(minimum, maximum);

    return distribution(generator);
}

Vector2 generateRandomPointOnPath(const Vector2& start, const Vector2& destination) {
    float t = randomFloat(0.2f, 0.8f);

    return {
        start.x + t * (destination.x - start.x),
        start.y + t * (destination.y - start.y)
    };
}

int main() {
    
    std::vector<Flight> flightData;
    std::vector<Obstacle> obstacleData;

    Vector2 positionStart = {2.0f, 3.0f};
    Vector2 positionEnd = {155.0f, -97.0f};

    float cruiseAltitude = 0.0f;
    float cruiseSpeed = 10.0f; // make use of cruise speed and altitude when effecting the flight data e.g. cost more accelleration = more fuel burned = higher costs

    Flight flightDetails(positionStart, positionEnd, cruiseAltitude, cruiseSpeed);

    Obstacle obstacleDetails(ObstacleType::MEDIUMWEATHER, {125.0f, -129.54f}, 50.0f);
    Vector2 obstaclePosition = generateRandomPointOnPath(positionStart, positionEnd);
    std::cout << "Obstacle position: (" << obstaclePosition.x << ", " << obstaclePosition.y << ")\n";

    flightData.push_back(flightDetails);
    obstacleData.push_back(obstacleDetails);

    float displacementX = positionEnd.x - positionStart.x;
    float displacementY = positionEnd.y - positionStart.y;
    float distanceTo = sqrt(displacementX * displacementX + displacementY * displacementY);

    Vector2 direction = {displacementX / distanceTo, displacementY / distanceTo};
    Vector2 velocity = {direction.x * cruiseSpeed, direction.y * cruiseSpeed};

    PrintFlightDetails(positionStart, positionEnd, displacementX, displacementY, distanceTo);
    sleepMilliseconds(1000);

    AircraftData inFlightData(positionStart);
    inFlightData.setVelocity(velocity);
    inFlightData.startAircraft();

    auto previousTime = std::chrono::steady_clock::now();

    while (inFlightData.getState() != AircraftState::OFF) {
        auto currentTime = std::chrono::steady_clock::now();

        std::chrono::duration<float> elapsed = currentTime - previousTime;

        float deltaTime = elapsed.count();

        previousTime = currentTime;

        inFlightData.update(deltaTime, flightDetails);

        Vector2 position = inFlightData.getCurrentPosition();

        if (inFlightData.getState() == AircraftState::FLYING) {
            printLiveInfo(position);
        }
        sleepMilliseconds(16);
}
    return 0;
}

// to do:

// create slower moving animation for visual display (later)
// implement events/Obstacles
// introduce more calculations such as fuel costs / weight / make use of altitude (way)