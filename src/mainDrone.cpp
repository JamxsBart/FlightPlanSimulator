#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <chrono>
#include <thread>
#include "Flight.h"
#include "AircraftData.h"
#include "Obstacle.h"

void PrintFlightDetails(Vector2 positionStart, Vector2 positionEnd, float displacementX, float displacementY, float distanceTo)
{
    std::cout << "Details: \nFlight start position: (" << positionStart.x << ", " << positionStart.y << ")\n"
              << "Flight end position: (" << positionEnd.x << ", " << positionEnd.y << ")\n"
              << "Flight displacement: (" << displacementX << ", " << displacementY << ")\n"
              << "Flight distance to: " << distanceTo << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
}

int main()
{

    const float epsilon = 0.001f;

    std::vector<Flight> flightData;
    std::vector<Obstacle> obstacleData;

    Vector2 positionStart = {2.0f, 3.0f};
    Vector2 positionEnd = {15.0f, 7.0f};
    Vector2 positionCurrent = positionStart;

    float cruiseAltitude = 0.0f;
    float cruiseSpeed = 10.0f; // make use of cruise speed and altitude when effecting the flight data e.g. cost more accelleration = more fuel burned = higher costs

    Flight flightDetails(positionStart, positionEnd, cruiseAltitude, cruiseSpeed);

    Obstacle obstacleDetails(ObstacleType(1), {125.0f, -129.54f}, 50.0f);

    flightData.push_back(flightDetails);
    obstacleData.push_back(obstacleDetails);

    float displacementX = positionEnd.x - positionStart.x;
    float displacementY = positionEnd.y - positionStart.y;

    float distanceTo = sqrt(displacementX * displacementX + displacementY * displacementY);

    Vector2 direction = {displacementX / distanceTo, displacementY / distanceTo};

    Vector2 velocity = {direction.x * cruiseSpeed, direction.y * cruiseSpeed};

    PrintFlightDetails(positionStart, positionEnd, displacementX, displacementY, distanceTo);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    AircraftData inFlightData(positionStart);

    inFlightData.setVelocity(velocity);

    inFlightData.setState(AircraftState::TAKINGOFF);

    std::cout << "\nAircraft is taking off";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    inFlightData.setState(AircraftState::FLYING);

    std::cout << "\nAircraft is flying";

    auto previousTime = std::chrono::steady_clock::now();

    while (inFlightData.getState() == AircraftState::FLYING)
    {

        auto currentTime = std::chrono::steady_clock::now();

        std::chrono::duration<float> elapsed =
            currentTime - previousTime;

        float deltaTime = elapsed.count();

        previousTime = currentTime;

        Vector2 velocity = inFlightData.getVelocity();

        positionCurrent.x += velocity.x * deltaTime;
        positionCurrent.y += velocity.y * deltaTime;

        if ((displacementX >= 0.0f &&
             positionCurrent.x >= positionEnd.x) ||
            (displacementX < 0.0f &&
             positionCurrent.x <= positionEnd.x))
        {
            positionCurrent.x = positionEnd.x;
        }

        if ((displacementY >= 0.0f &&
             positionCurrent.y >= positionEnd.y) ||
            (displacementY < 0.0f &&
             positionCurrent.y <= positionEnd.y))
        {
            positionCurrent.y = positionEnd.y;
        }

        inFlightData.setCurrentPosition(positionCurrent);

        std::cout << "\nCurrent Position: ("
                  << positionCurrent.x << ", "
                  << positionCurrent.y << ")";

        std::cout << "\nVelocity: ("
                  << velocity.x << ", "
                  << velocity.y << ")";

        std::cout << "\nDelta Time: "
                  << deltaTime << " s";

        if (std::abs(positionCurrent.x - positionEnd.x) <= epsilon && std::abs(positionCurrent.y - positionEnd.y) <= epsilon)
        {
            positionCurrent = positionEnd;

            std::cout << "\nDestination reached!";

            inFlightData.setState(AircraftState::LANDING);
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(16));
    }

    if (inFlightData.getState() == AircraftState::LANDING)
    {
        std::cout << "\nAircraft is landing";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        inFlightData.setState(AircraftState::LANDED);
    }

    if (inFlightData.getState() == AircraftState::LANDED)
    {
        std::cout << "\nAircraft has landed.";

        inFlightData.setState(AircraftState::OFF);
    }

    if (inFlightData.getState() == AircraftState::OFF)
    {
        std::cout << "\nAircraft is now OFF.";
    }

    return 0;
}

// to do:

// clean up code
// implement state updates directly inside of the AD class
// create slower moving animation for visual display (later) 
// implement events/Obstacles
// introduce more calculations such as fuel costs / weight / make use of altitude