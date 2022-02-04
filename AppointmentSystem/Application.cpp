#include "Application.hpp"

void Application::start()
{
    while (true)
    {
        this->printMainMenu();

        int choice = this->inputReader.readChoice();

        if (choice == 0)
        {
            break; // Application ending by entering 0.
        }
        else if (choice == 1)
        {
            int id = this->inputReader.readID();

            if (!validator.isIDAlreadyExists(id, this->appointments))
            {
                std::string name = this->inputReader.readName();

                int age = this->inputReader.readAge();

                std::string dataOfBirth = this->inputReader.readDOB();

                int position = this->inputReader.readPosition();

                if (!validator.isPositionAlreadyReserved(position, this->appointments))
                {
                    char gender = this->inputReader.readGender();

                    this->appointments.push_back(Appointment(id, name, age, dataOfBirth, position, gender));
                }
                else
                {
                    std::cout << "\nThis position is already reserved\n";
                }
            }
            else
            {
                std::cout << "\nID alreay exists\n";
            }
        }
        else if (choice == 2)
        {
            this->printAllRecords();
        }
        else if (choice == 3)
        {
            this->printByAge();
        }
        else if (choice == 4)
        {
            this->printByGenderCount();
        }
        else
        {
            std::cout << "Invalid selection" << std::endl;
        }
    }
}

void Application::printMainMenu()
{
    std::cout << "\n ----------------Program Menu------------\n";
    std::cout << " 1: Input Records\n";
    std::cout << " 2: Print All Records\n";
    std::cout << " 3: Print by Age\n";
    std::cout << " 4: Print by Gender count\n";
    std::cout << " 0: To exit\n";
}

void Application::printAllRecords()
{
    std::cout << "\n **** **** Printing All Records **** ****";

    if (this->appointments.size() == 0)
    {
        std::cout << "\n No record found" << std::endl;
    }
    else
    {
        std::cout << "\n total number of persons: " << this->appointments.size() << std::endl;

        for (int i = 0; i < this->appointments.size(); i++)
        {
            std::cout << "Id: " << this->appointments[i].getID() << "  Name: " << this->appointments[i].getName()
                      << "  Age: " << this->appointments[i].getAge() << "  DOB: " << this->appointments[i].getDOB()
                      << "  Position: " << this->appointments[i].getPosition() << "  Gender: " << this->appointments[i].getGender() << std::endl;
        }
    }
}

int Application::countByGender(char genderToCount)
{
    int counter = 0;

    for (int i = 0; i < this->appointments.size(); i++)
    {
        if (this->appointments[i].getGender() == genderToCount)
        {
            counter++;
        }
    }

    return counter;
}

void Application::printByGenderCount()
{
    int totalMale = this->countByGender('M');
    int totalFemale = this->countByGender('F');

    std::cout << "\n **** **** Printing All Records By Gender **** ****";

    std::cout << "Number of Male: " << totalMale << std::endl;
    std::cout << "Number of Female: " << totalFemale << std::endl;
}

int Application::countByAge(int age)
{
    int counter = 0;

    for (int i = 0; i < this->appointments.size(); i++)
    {
        // if (this->appointments[i].getGender() == genderToCount)
        {
            counter++;
        }
    }

    return counter;
}

void Application::printByAge()
{
    // To get max value from vector. this function is in header <algorithm> which is given by c++ community.
    // auto maxAgePersonAppointment = *std::max_element(std::begin(this->appointments), std::end(this->appointments));

    // int personAbove50 = this->countByAge(50);
}