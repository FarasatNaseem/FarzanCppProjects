#include "InputReader.hpp"

int InputReader::readChoice()
{
    int choice;

    std::cout << " \nEnter your choice: ";
    std::cin >> choice;

    return choice;
}

int InputReader::readID()
{
    int id;

    std::cout << " \nEnter Id (number): ";
    std::cin >> id;

    return id;
}

std::string InputReader::readName()
{
    std::string name;

    while (true)
    {
        try
        {
            std::cout << " \nEnter Name (20 characters): ";
            std::cin.ignore(80, '\n');
            getline(std::cin, name);

            if (name.size() > 20)
            {
                throw std::invalid_argument("Name length cannot be greater then 20");
            }

            break;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return name;
}

int InputReader::readAge()
{
    int age;

    std::cout << " \nEnter Age (number): ";
    std::cin >> age;

    return age;
}

std::string InputReader::readDOB()
{
    std::string dateOfBirth;

    std::cout << " \nEnter DOB (dd-mm-yyyy): ";
    std::cin.ignore(80, '\n');
    getline(std::cin, dateOfBirth);

    dateOfBirth.erase(remove(dateOfBirth.begin(), dateOfBirth.end(), '-'), dateOfBirth.end()); // to remove all - from date. final date string will be 31Oct2000

    return dateOfBirth;
}

int InputReader::readPosition()
{
    int position;

    std::cout << " \nEnter Position (number): ";
    std::cin >> position;

    return position;
}

char InputReader::readGender()
{
    char gender;

    std::cout << " \nEnter Gender (M/F): ";
    std::cin >> gender;

    return gender;
}