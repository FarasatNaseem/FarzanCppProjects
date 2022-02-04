#include "Application.hpp"

void Application::start()
{
    while (true)
    {
        // print main menu of the application
        this->printMainMenu();

        // reading choice from user.
        int choice = this->inputReader.readChoice();

        // if choice is 0 then application will be closed.
        if (choice == 0)
        {
            std::cout << "\nThanks for using our application. See you next time and stay healthy\n\n";

            break; // Application ending by entering 0.
        }
        else if (choice == 1) // if choise is 1 then user will be able to enter new appointment data.
        {
            // reading user id
            int id = this->inputReader.readID();

            // first of all its checked, if id already exists or not.
            if (!validator.isIDAlreadyExists(id, this->appointments))
            {
                // reading user name.
                std::string name = this->inputReader.readName();

                // reading user age.
                int age = this->inputReader.readAge();

                // reading user date of birth.
                std::string dataOfBirth = this->inputReader.readDOB();

                // reading position.
                int position = this->inputReader.readPosition();

                // then position will be checked, if position is not reserved yet then it will be taken by user.
                if (!validator.isPositionAlreadyReserved(position, this->appointments))
                {
                    // reading user gender.
                    char gender = this->inputReader.readGender();

                    // at the end storing new appointment in a vector.
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
            // printing all appoinements record.
            this->printAllRecords();
        }
        else if (choice == 3)
        {
            // printing user by age.
            this->printByAge();
        }
        else if (choice == 4)
        {
            // printing total number of male and female.
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

// 2
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

// 3
void Application::printByGenderCount()
{
    int totalMale = this->countByGender('M');
    int totalFemale = this->countByGender('F');

    std::cout << "\n **** **** Printing All Records By Gender **** ****\n";

    std::cout << "Number of Male: " << totalMale << std::endl;
    std::cout << "Number of Female: " << totalFemale << std::endl;
}

// In order to implement the function. printByAge(), following functions are implemented.

std::vector<int> Application::getPersonsAge()
{
    std::vector<int> personsAge;

    for (int i = 0; i < this->appointments.size(); i++)
    {
        personsAge.push_back(this->appointments[i].getAge());
    }

    return personsAge;
}

int Application::getMaxAge(std::vector<int> personsAge)
{
    int max, min;

    max = personsAge[0];
    min = personsAge[0];

    for (int i = 0; i < personsAge.size(); i++)
    {
        if (max < personsAge[i])
        {
            max = personsAge[i];
        }
        else if (min > personsAge[i])
        {
            min = personsAge[i];
        }
    }

    return max;
}

int Application::countByAge(int age)
{
    int counter = 0;

    for (int i = 0; i < this->appointments.size(); i++)
    {
        if (this->appointments[i].getAge() == age)
        {
            counter++;
        }
    }

    return counter;
}

// 4
void Application::printByAge()
{
    std::vector<int> personsAge = this->getPersonsAge();

    int maxAge = this->getMaxAge(personsAge);

    int ageOfPerson = maxAge;

    std::cout << "\n **** **** Printing All Records By Gender **** ****\n";

    std::cout << "Persons more then " << maxAge << ": 0";

    for (int i = 0; i < maxAge; i++)
    {
        int totalPersonOfSameAge = this->countByAge(ageOfPerson);

        if (totalPersonOfSameAge != 0)
        {
            std::cout << "\nPersons of age " << ageOfPerson << ": " << totalPersonOfSameAge;
        }

        ageOfPerson--;
    }
}