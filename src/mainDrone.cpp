#include <iostream>
#include <string>
#include <cmath>
#include <vector>

struct Vector2 {
    float x;
    float y;
};

struct Orientation {
    float roll;
    float pitch;
    float yaw;
};

enum class AircraftState {
    OFF,
    TAKINGOFF,
    FLYING,
    LANDING,
    LANDED
};

class AircraftData {

   private:
    Vector2 velocity{0.0f, 0.0f};
    AircraftState state{AircraftState::OFF};

   public:
    AircraftData(Vector2 velocity, AircraftState state) 
    :   velocity(velocity),
        state(state)
    {}

    AircraftData() = default;

    void setVelocity(const Vector2& velocity) {
        this->velocity = velocity;
    }

    void setState(const AircraftState& state) {
        this->state = state;
    }

    Vector2 getVelocity() const {
    return velocity;
    }

    AircraftState getState() const {
    return state;
    }
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

int main() {

    std::vector<Flight> flightData;


    Vector2 positionStart = {3.4f, 5.3f};
    Vector2 positionEnd = {4.1f, 3.5f};
    float cruiseAltitude = 0.0f;
    float cruiseSpeed = 0.0f;

    Flight flightDetails(positionStart, positionEnd, cruiseAltitude, cruiseSpeed);

    flightData.push_back(flightDetails);
 
    float displacementX = positionEnd.x - positionStart.x;
    float displacementY = positionEnd.y - positionStart.y;

    float distanceTo = sqrt(displacementX * displacementX + displacementY * displacementY);

    std::cout << "Details: \nFlight start position: (" << positionStart.x << ", " << positionStart.y << ")\n" << 
                          "Flight end position: (" << positionEnd.x << ", " << positionEnd.y << ")\n" << 
                          "Flight displacement: (" << displacementX << ", " << displacementY << ")\n" <<
                          "Flight distance to: " << distanceTo << std::endl; 


    for (const Flight& flight : flightData) {
    Vector2 start = flight.getStartPosition();
    Vector2 destination = flight.getDestinationPosition();

    std::cout << "Start position: ("
              << start.x << ", " << start.y << ")\n";

    std::cout << "Destination position: ("
              << destination.x << ", " << destination.y << ")\n";

    std::cout << "Cruise speed: "
              << flight.getCruiseSpeed() << '\n';

    std::cout << "Cruise altitude: "
              << flight.getCruiseAltitude() << '\n';
}

    return 0;
}