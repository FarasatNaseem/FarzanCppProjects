#include <vector>
#include "InputReader.cpp"
// #include "Appointment.cpp"
#include "Validator.cpp"
#include <iostream>

class Application
{
private:
    InputReader inputReader;
    std::vector<Appointment> appointments;
    Validator validator;
    void printMainMenu();
    void printAllRecords();
    void printByAge();
    void printByGenderCount();
    int countByGender(char genderToCount);
    int countByAge(int age);
public:
    void start();
};