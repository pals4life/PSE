#include "Car.h"

const double Car::fgkMaxAcceleration = 8.0;
const double Car::fgkMinAcceleration = -2.0;

const double Car::fgkMinSpeed = 0.0;
const double Car::fgkMaxSpeed = 150.0;

const double Car::fgkVehicleLength = 3;

Car::Car(const std::string& license, double pos, double velocity) : IVehicle(license, pos, velocity) {}

void Car::move(const IVehicle* const next, double speedLimit)
{
    fPosition += fVelocity;
    fVelocity += fAcceleration;

    if(next == NULL)
    {
        fAcceleration = fgkMaxAcceleration;                                                 // if nobody is ahead, go max acceleration
    }
    else
    {
        double ideal  = 0.75 * fVelocity + next->getVehicleLength() + 2;                    // ideal following distance = 3/4 speed + 2 meters extra
        double actual = next->getPosition() - next->getVehicleLength() - fPosition;         // distance between 2 vehicles
        fAcceleration = 0.5 * (actual - ideal);                                             // take the average
    }

    if(fVelocity > speedLimit) fAcceleration = fVelocity - speedLimit;                      // if above speed limit, slow down (occurs when changing roads)
    double minAcceleration = std::max(fVelocity, fgkMinAcceleration);                       // determine min acceleration, to prevent negative speed
    double maxAcceleration = std::min(speedLimit - fVelocity, fgkMaxAcceleration);          // determine max acceleration, to prevent from going too fast

    fAcceleration = std::min(std::max(fAcceleration, minAcceleration), maxAcceleration);    // clamp the acceleration
}

double Car::getVehicleLength() const
{
    return fgkVehicleLength;
}

EVehicleType Car::getType() const
{
    return kCar;
}

double Car::getMaxAcceleration() const
{
    return fgkMaxAcceleration;
}

double Car::getMinAcceleration() const
{
    return fgkMinAcceleration;
}

double Car::getMinVelocity() const
{
    return fgkMinSpeed;
}

double Car::getMaxVelocity() const
{
    return fgkMaxSpeed;
}





