#include "Validator.hpp"

bool Validator::isIDAlreadyExists(int id, std::vector<Appointment> appointments)
{
    for (int i = 0; i < appointments.size(); i++)
    {
        if (id == appointments[i].getID())
        {
            return true;
        }
    }

    return false;
}


bool Validator::isPositionAlreadyReserved(int position, std::vector<Appointment> appointments)
{
    for (int i = 0; i < appointments.size(); i++)
    {
        if (position == appointments[i].getPosition())
        {
            return true;
        }
    }

    return false;
}