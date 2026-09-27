#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include "Flight.h"
#include "AircraftData.h"
#include "Obstacle.h"


int main() {

    const float epsilon = 0.001f;
    
    std::vector<Flight> flightData;
    std::vector<Obstacle> obstacleData;

    Vector2 positionStart = {2.0f, 3.0f};
    Vector2 positionEnd = {15.0f, -162.0f};
    Vector2 positionCurrent = {0.0f, 0.0f};

    float cruiseAltitude = 0.0f;
    float cruiseSpeed = 0.0f; // make use of cruise speed and altitude when effecting the flight data e.g. cost more accelleration = more fuel burned = higher costs 

    Flight flightDetails(positionStart, positionEnd, cruiseAltitude, cruiseSpeed);

    Obstacle obstacleDetails(ObstacleType(1), {125.0f, -129.54f}, 50.0f); // implement obstacles into the path with automatic obstacle avoidance

    flightData.push_back(flightDetails);
    obstacleData.push_back(obstacleDetails);

    float displacementX = positionEnd.x - positionStart.x;
    float displacementY = positionEnd.y - positionStart.y;

    float distanceTo = sqrt(displacementX * displacementX + displacementY * displacementY);

    int animationSpeed;
    int jumpSpeed;
    if (distanceTo <= 25) {
        jumpSpeed = 10;
        animationSpeed = 620;
    } else if (distanceTo > 25 && distanceTo <= 50) {
        jumpSpeed = 25;
        animationSpeed = 530;
    } else if (distanceTo > 50 && distanceTo <= 75) {
        jumpSpeed = 45;
        animationSpeed = 375;
    } else if (distanceTo > 75 && distanceTo <= 100) {
        jumpSpeed = 75;
        animationSpeed = 285;
    } else {
        jumpSpeed = 100;
        animationSpeed = 200;
    };

    float tenUnitsDown = 1.0f / jumpSpeed; // update later on to be more accurate and tied to velocity instead of just for the animations

    std::cout << "Details: \nFlight start position: (" << positionStart.x << ", " << positionStart.y << ")\n" << 
                          "Flight end position: (" << positionEnd.x << ", " << positionEnd.y << ")\n" << 
                          "Flight displacement: (" << displacementX << ", " << displacementY << ")\n" <<
                          "Flight distance to: " << distanceTo << std::endl; 
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

    positionCurrent = positionStart; // move currentPosition to Aircraft class
    std::cout << "\nCurrent Position: (" << positionCurrent.x << ", " << positionCurrent.y << ")";
    while(true) { // make use of my state system in further versions e.g. while (flight.getState() == DroneState::FLYING)
        positionCurrent.x = positionCurrent.x + tenUnitsDown * (positionEnd.x - positionStart.x);
        positionCurrent.y = positionCurrent.y + tenUnitsDown * (positionEnd.y - positionStart.y);
        std::cout << "\nCurrent Position: (" << positionCurrent.x << ", " << positionCurrent.y << ")";
        std::this_thread::sleep_for(std::chrono::milliseconds(animationSpeed));
        if(std::fabs(positionCurrent.x - positionEnd.x) < epsilon &&
            std::fabs(positionCurrent.y - positionEnd.y) < epsilon) {
            std::cout << "\nWell Done you made it safely to your destination!";
            break;
}
    }

    return 0;
}