#pragma once

#include <iostream>
#include <string>
#include "Flight.h"

enum class ObstacleType {
    LIGHTWEATHER,
    MEDIUMWEATHER,
    HEAVYWEATHER,
    CLOSEDAIRSPACE,
    HEAVYWINDS
};

inline std::string obstacleTypeToString(ObstacleType obstacleType) {
    switch(obstacleType) {
        case ObstacleType::LIGHTWEATHER:
            return "LightWeather";
        case ObstacleType::MEDIUMWEATHER:
            return "MediumWeather";
        case ObstacleType::HEAVYWEATHER:
            return "HeavyWeather";
        case ObstacleType::CLOSEDAIRSPACE:
            return "ClosedAirspace";
        case ObstacleType::HEAVYWINDS:
            return "HeavyWinds";
    }
}

class Obstacle {

   private:
    ObstacleType obstacleType{ObstacleType::LIGHTWEATHER};
    Vector2 obstaclePosition{0.0f, 0.0f};
    float obstacleRadius{0.0f};

   public:
    Obstacle(ObstacleType obstacleType, Vector2 obstaclePosition, float obstacleRadius) 
    :   obstacleType(obstacleType),
        obstaclePosition(obstaclePosition),
        obstacleRadius(obstacleRadius)
    {}

    void setObstacleType(ObstacleType newObstacleType) {
        this->obstacleType = newObstacleType;
    }

    void setObstaclePosition(const Vector2& newObstaclePosition) {
        this->obstaclePosition = newObstaclePosition;
    }

    void setObstacleRadius(float newObstacleRadius) {
        this->obstacleRadius = newObstacleRadius;
    }

    ObstacleType getObstacleType() const {
        return obstacleType;
    }

    Vector2 getObstaclePosition() const {
        return obstaclePosition;
    }

    float getObstacleRadius() const {
        return obstacleRadius;
    }

    void printObstacleDetails() {
        std::cout << "\nObstacle Details: " << "\nObstacle Type: " << obstacleTypeToString(obstacleType) 
                  << "\nObstacle Positions: (" << obstaclePosition.x << ", " << obstaclePosition.y 
                  << ")\nObstacle Radius: " << obstacleRadius << std::endl;
    }
};
