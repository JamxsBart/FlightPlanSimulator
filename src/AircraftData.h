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