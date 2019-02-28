//============================================================================
// @name        : Road.cpp
// @author      : Mano Marichal
// @date        : 27.02.19
// @version     :
// @copyright   : Project Software Engineering - BA1 Informatica - Mano Marichal - University of Antwerp
// @description :
//============================================================================
#include "Road.h"


Road::Road(const std::string& name, Road* next, double length, double speedLimit)
{
    fName = name;
    fNextRoad = next;

    fRoadLength = length;
    fSpeedLimit = speedLimit;
}

void Road::update()
{
    for(int i = 0; i < fVehicles.size() - 1; i++)
    {
        fVehicles[i]->move(fVehicles[i+1]);
    }
    if(fNextRoad == NULL) fVehicles.front()->move(NULL);
    else fVehicles.front()->move(fNextRoad->getBackVehicle());
}

void Road::enqueue(IVehicle* const vehicle)
{
    fVehicles.push_back(vehicle);
}

void Road::dequeue()
{
    fVehicles.pop_front();
}

bool Road::isEmpty()
{
    return fVehicles.empty();
}

IVehicle* const Road::getBackVehicle() const
{
    return fVehicles.back();
}



Road* const Road::getNextRoad() const
{
    return fNextRoad;
}

double Road::getRoadLength() const
{
    return fRoadLength;
}

double Road::getSpeedLimit() const
{
    return fSpeedLimit;
}

const std::string &Road::getName() const
{
    return fName;
}



