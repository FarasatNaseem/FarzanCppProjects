#include <iostream>

class Appointment
{
private:
    int id;
    std::string name;
    int age;
    std::string dateOfBirth;
    int position;
    char gender;

public:
    Appointment(int id, std::string name, int age, std::string dateOfBirth, int position, char gender);

    int getID();
    std::string getName();
    int getAge();
    std::string getDOB();
    int getPosition();
    char getGender();
};
