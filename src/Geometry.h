#pragma once

#include "Flight.h"

float distanceBetween(Vector2 firstPoint, Vector2 secondPoint);

float distanceFromPointToSegment(
    Vector2 point,
    Vector2 segmentStart,
    Vector2 segmentEnd
);

bool segmentIntersectsCircle(
    Vector2 segmentStart,
    Vector2 segmentEnd,
    Vector2 circleCentre,
    float circleRadius
);