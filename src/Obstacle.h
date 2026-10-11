#pragma once

#include <iostream>
#include "Flight.h"

enum class ObstacleType {
    LIGHTWEATHER,
    MEDIUMWEATHER,
    HEAVYWEATHER,
    CLOSEDAIRSPACE,
    HEAVYWINDS
};

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
        std::cout << "\nObstacle Details: " << "\nObstacle Type: " << "LIGHTWEATHER" 
                  << "\nObstacle Positions: (" << obstaclePosition.x << ", " << obstaclePosition.y 
                  << ")\nObstacle Radius: " << obstacleRadius << std::endl;
    }
};
