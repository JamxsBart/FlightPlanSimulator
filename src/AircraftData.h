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
};