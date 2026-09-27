#include <string>
struct Vector2 {
    float x;
    float y;
};

class Flight {

   private:
    Vector2 startPosition{0.0f, 0.0f};
    Vector2 destinationPosition{0.0f, 0.0f};
    float cruiseAltitude;
    float cruiseSpeed;

   public:
    Flight(Vector2 startPosition, Vector2 destinationPosition, float cruiseAltitude, float cruiseSpeed) 
    :   startPosition(startPosition),
        destinationPosition(destinationPosition),
        cruiseAltitude(cruiseAltitude),
        cruiseSpeed(cruiseSpeed)
    {}

    Flight() = default;

    void setStartPosition(const Vector2& startPosition) {
        this->startPosition = startPosition;
    }

    void setDestinationPosition(const Vector2& destinationPosition) {
        this->destinationPosition = destinationPosition;
    }

    void setCruiseAltitude(float cruiseAltitude) {
        this->cruiseAltitude = cruiseAltitude;
    }

    void setCruiseSpeed(float cruiseSpeed) {
        this->cruiseSpeed = cruiseSpeed;
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