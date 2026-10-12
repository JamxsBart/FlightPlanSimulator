#pragma once

struct Vector2 {
    float x;
    float y;
};

class Flight {

   private:
    Vector2 startPosition{0.0f, 0.0f};
    Vector2 destinationPosition{0.0f, 0.0f};
    float cruiseAltitude{0.0f};
    float cruiseSpeed{0.0f};

   public:
    Flight(Vector2 startPosition, Vector2 destinationPosition, float cruiseAltitude, float cruiseSpeed) 
    :   startPosition(startPosition),
        destinationPosition(destinationPosition),
        cruiseAltitude(cruiseAltitude),
        cruiseSpeed(cruiseSpeed)
    {}

    Flight() = default;

    void setStartPosition(const Vector2& newStartPosition) {
        this->startPosition = newStartPosition;
    }

    void setDestinationPosition(const Vector2& newDestinationPosition) {
        this->destinationPosition = newDestinationPosition;
    }

    void setCruiseAltitude(float newCruiseAltitude) {
        this->cruiseAltitude = newCruiseAltitude;
    }

    void setCruiseSpeed(float newCruiseSpeed) {
        this->cruiseSpeed = newCruiseSpeed;
    }

    Vector2 getStartPosition() const {
    return startPosition;
    }

    Vector2 getDestinationPosition() const {
    return destinationPosition;
    }

    float getCruiseAltitude() const {
    return cruiseAltitude;
    }

    float getCruiseSpeed() const {
    return cruiseSpeed;
    }
};
