#include "Geometry.h"

#include <algorithm>
#include <cmath>

float distanceBetween(Vector2 firstPoint, Vector2 secondPoint) {
    float distanceX = secondPoint.x - firstPoint.x;
    float distanceY = secondPoint.y - firstPoint.y;

    return std::sqrt(distanceX * distanceX + distanceY * distanceY);
}

float distanceFromPointToSegment(
    Vector2 point,
    Vector2 segmentStart,
    Vector2 segmentEnd
) {
    float segmentX = segmentEnd.x - segmentStart.x;
    float segmentY = segmentEnd.y - segmentStart.y;

    float segmentLengthSquared = segmentX * segmentX + segmentY * segmentY;

    if (segmentLengthSquared == 0.0f) {
        return distanceBetween(point, segmentStart);
    }

    float pointX = point.x - segmentStart.x;
    float pointY = point.y - segmentStart.y;

    float projection = (pointX * segmentX + pointY * segmentY) / segmentLengthSquared;
    projection = std::clamp(projection, 0.0f, 1.0f);

    Vector2 closestPoint = {
        segmentStart.x + projection * segmentX,
        segmentStart.y + projection * segmentY
    };

    return distanceBetween(point, closestPoint);
}

bool segmentIntersectsCircle(
    Vector2 segmentStart,
    Vector2 segmentEnd,
    Vector2 circleCentre,
    float circleRadius
) {
    float distanceToRoute = distanceFromPointToSegment(
        circleCentre,
        segmentStart,
        segmentEnd
    );

    return distanceToRoute <= circleRadius;
}
