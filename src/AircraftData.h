enum class AircraftState {
    OFF,
    TAKINGOFF,
    FLYING,
    LANDING,
    LANDED
};

class AircraftData {

   private:
    Vector2 velocity;
    AircraftState state;
    Vector2 currentPosition;

   public:
    AircraftData(Vector2 currentPosition) 
    :   velocity{ 0.0f, 0.0f },
        state(AircraftState::OFF),
        currentPosition(currentPosition)
    {}

    AircraftData() = default;

    void update(float deltaTime, const Flight& flight) {
    switch (state) {
        case AircraftState::OFF:
            break;

        case AircraftState::TAKINGOFF:
            state = AircraftState::FLYING;
            break;

        case AircraftState::FLYING:
{
            Vector2 destination = flight.getDestinationPosition();

            currentPosition.x += velocity.x * deltaTime;
            currentPosition.y += velocity.y * deltaTime;

            if ((velocity.x > 0.0f &&
                 currentPosition.x >= destination.x) ||
                (velocity.x < 0.0f &&
                 currentPosition.x <= destination.x))
            {
                currentPosition.x = destination.x;
            }

            if ((velocity.y > 0.0f &&
                 currentPosition.y >= destination.y) ||
                (velocity.y < 0.0f &&
                 currentPosition.y <= destination.y))
            {
                currentPosition.y = destination.y;
            }

            if (currentPosition.x == destination.x &&
                currentPosition.y == destination.y)
            {
                std::cout << "\nDestination reached!";

                state = AircraftState::LANDING;
            }

            break;
        }

        case AircraftState::LANDING:
            std::cout << "\nAircraft is landing";
            state = AircraftState::LANDED;
            break;

        case AircraftState::LANDED:
            std::cout << "\nAircraft has landed.";
            state = AircraftState::OFF;
            std::cout << "\nAircraft is now OFF.";
            break;
    }
}

    void setVelocity(const Vector2& velocity) {
        this->velocity = velocity;
    }

    void setState(AircraftState newState)
    {
        this->state = newState;
    }

    void setCurrentPosition(const Vector2& currentPosition) {
        this->currentPosition = currentPosition;
    }

    Vector2 getVelocity() const {
    return velocity;
    }

    AircraftState getState() const {
    return state;
    }
    
    Vector2 getCurrentPosition() const {
    return currentPosition;
    }

    void startAircraft() {
        if (state == AircraftState::OFF) {
                state = AircraftState::TAKINGOFF;
                std::cout << "\nAircraft is taking off";
                state = AircraftState::FLYING;
                std::cout << "\nAircraft is flying";
        }
    }


};