#include "stdafx.h"
#include "Controller.h"

// Calculate the shot speed to hit the target, given the following information.
//   tankPos: the position from which the bullet will be fired, in pixels relative to the top left corner of the screen
//   enemyPos: the target position to hit, in pixels relative to the top left corner of the screen
//   shotAngleRadians: the angle of the shot, in radians from horizontal (positive angles are upwards)
//   gravity: the acceleration due to gravity in pixels/second^2 (positive is downwards)
//   wind: the acceleration due to wind in pixels/second^2 (positive is rightwards)
float Controller::calculateShotSpeed(const Vector2& tankPos, const Vector2& enemyPos, float shotAngleRadians, float gravity, float wind)
{
    Vector2 s = enemyPos - tankPos;
    
	// Task 1
    if (!c_canHandleHeightDifference && !c_canHandleWind)
    {
        return sqrtf(gravity * s.x / sinf(2 * shotAngleRadians));
    }
    
    // Task 2
    else if (c_canHandleHeightDifference && !c_canHandleWind)
    {
        return sqrtf(gravity * s.x * s.x
                     / (s.x * sinf(2*shotAngleRadians) + s.y * (cosf(2*shotAngleRadians) + 1)));
    }
    
    // Task 3
    else if (c_canHandleWind)
    {
        float alpha = (gravity * s.x - wind * s.y) / (gravity * cosf(shotAngleRadians) + wind * sinf(shotAngleRadians));
        return sqrtf(gravity * alpha * alpha
                     / (2 * (alpha * sinf(shotAngleRadians) + s.y)));
    }
    
    return 0;
}

// Calculate the shot angle to hit the target, given the following information.
//   tankPos: the position from which the bullet will be fired, in pixels relative to the top left corner of the screen
//   enemyPos: the target position to hit, in pixels relative to the top left corner of the screen
//   shotSpeed: the speed of the shot, in pixels per second
//   gravity: the acceleration due to gravity in pixels/second^2 (positive is downwards)
//   wind: the acceleration due to wind in pixels/second^2 (positive is rightwards)
float Controller::calculateShotAngle(const Vector2& tankPos, const Vector2& enemyPos, float shotSpeed, float gravity, float wind)
{
    Vector2 s = enemyPos - tankPos;

    // Task 4
    float a = gravity * s.x * s.x / (2 * shotSpeed * shotSpeed);
    float b = s.x;
    float c = a - s.y;
    
    // Can change this sign to get the other solution
    //                v
    return -atanf((-b + sqrtf(b*b - 4*a*c)) / (2*a));
}

