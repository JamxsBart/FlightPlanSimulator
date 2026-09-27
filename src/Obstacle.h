enum class ObstacleType {
    LIGHTWEATHER,
    MEDIUMWEATHER,
    HEAVYWEATHER,
    CLOSEDAIRSPACE,
    HEAVYWINDS
};

class Obstacle {

   private:
    ObstacleType obstacleType;
    Vector2 obstaclePosition;
    float obstacleRadius;

   public:
    Obstacle(ObstacleType obstacleType, Vector2 obstaclePosition, float obstacleRadius) 
    :   obstacleType(obstacleType),
        obstaclePosition(obstaclePosition),
        obstacleRadius(obstacleRadius)
    {}

    void setObstacleType(const ObstacleType& obstacleType) {
        this->obstacleType = obstacleType;
    }

    void setObstaclePosition(const Vector2& obstaclePosition) {
        this->obstaclePosition = obstaclePosition;
    }

    void setObstacleRadius(const float& obstacleRadius) {
        this->obstacleRadius = obstacleRadius;
    }

    ObstacleType getObstacleType() const {
        return obstacleType;
    }

    Vector2 getOstaclePosition() const {
        return obstaclePosition;
    }

    float getObstacleRadius() const {
        return obstacleRadius;
    }
};