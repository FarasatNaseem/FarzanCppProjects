#include <iostream>
#include <vector>
#include "Appointment.cpp"

class Validator
{
public:
    bool isIDAlreadyExists(int id, std::vector<Appointment> appointments);
    bool isPositionAlreadyReserved(int position, std::vector<Appointment> appointments);
};