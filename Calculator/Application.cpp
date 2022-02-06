#include "Application.hpp"

void Application::renderText(std::string textToRender)
{
    std::cout << std::endl
              << textToRender;
}

void Application::renderMenu()
{
    this->renderText("Press 0 for exit.");
    this->renderText("Press 1 for addition");
    this->renderText("Press 2 for subtraction");
    this->renderText("Press 3 for multiplication");
    this->renderText("Press 4 for division");
    this->renderText("Press 5 for power calculation");
    this->renderText("Press 6 for square root");
    this->renderText("Press 7 for factorial calculation");
    this->renderText("Press 8 for exponential calculation\n\n\n\n");
}

void Application::run()
{
    bool isAppRunning = true;
    float result;
    float valueOne;
    float valueTwo;

    while (isAppRunning)
    {
        this->renderText("*** Which operation do you want to perform ***\n");

        this->renderMenu();

        this->renderText("Press option: ");
        int option = this->reader.readNumber();

        switch (option)
        {
        case 0:

            this->renderText("Thanks for using our simple calculator :D \n");

            isAppRunning = false;

            break;

        case 1:

            this->renderText("Enter number 1: ");
            valueOne = this->reader.readNumber();

            this->renderText("Enter number 2: ");
            valueTwo = this->reader.readNumber();

            result = this->calculator.add(valueOne, valueTwo);

            this->renderText("Addition result is " + std::to_string(result) + "\n");

            break;

        case 2:

            this->renderText("Enter number 1: ");
            valueOne = this->reader.readNumber();

            this->renderText("Enter number 2: ");
            valueTwo = this->reader.readNumber();

            result = this->calculator.subtract(valueOne, valueTwo);

            this->renderText("Subtraction result is " + std::to_string(result) + "\n");

            break;
        case 3:

            this->renderText("Enter number 1: ");
            valueOne = this->reader.readNumber();

            this->renderText("Enter number 2: ");
            valueTwo = this->reader.readNumber();

            result = this->calculator.mutiply(valueOne, valueTwo);

            this->renderText("Multiplication result is " + std::to_string(result) + "\n");

            break;
        case 4:

            try
            {
                this->renderText("Enter number 1: ");
                valueOne = this->reader.readNumber();

                this->renderText("Enter number 2: ");
                valueTwo = this->reader.readNumber();

                result = this->calculator.divide(valueOne, valueTwo);

                this->renderText("Division result is " + std::to_string(result) + "\n");
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            break;
        case 5:
            this->renderText("Enter base: ");
            valueOne = this->reader.readNumber();

            this->renderText("Enter power: ");
            valueTwo = this->reader.readNumber();

            result = this->calculator.calculatePower(valueOne, valueTwo);

            this->renderText("Result is " + std::to_string(result) + "\n");

            break;
        case 6:

            this->renderText("Enter value: ");
            valueOne = this->reader.readNumber();

            result = this->calculator.calculateSquareRoot(valueOne);

            this->renderText("Square root of " + std::to_string(valueOne) + " is " + std::to_string(result) + "\n");

            break;
        case 7:

            this->renderText("Enter value: ");
            valueOne = this->reader.readNumber();

            result = this->calculator.calculateFactorial(valueOne);

            this->renderText("Factorial of " + std::to_string(valueOne) + " is " + std::to_string(result) + "\n");

            break;
        case 8:

            this->renderText("Enter base: ");
            valueOne = this->reader.readNumber();

            result = this->calculator.calculateExponential(valueOne);

            this->renderText("e^" + std::to_string((int)valueOne) + " is " + std::to_string(result) + "\n");

            break;
        default:
            this->renderText("Invalid input\n");
            break;
        }
    }
}