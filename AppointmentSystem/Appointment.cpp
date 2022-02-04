#include "Appointment.hpp"

Appointment::Appointment(int id, std::string name, int age, std::string dateOfBirth, int position, char gender)
{
    this->id = id;
    this->name = name;
    this->age = age;
    this->dateOfBirth = dateOfBirth;
    this->position = position;
    this->gender = gender;
}

int Appointment::getID() { return this->id; }
std::string Appointment::getName() { return this->name; }
int Appointment::getAge() { return this->age; }
std::string Appointment::getDOB() { return this->dateOfBirth; }
int Appointment::getPosition() { return this->position; }
char Appointment::getGender() { return this->gender; }