#include <iostream>
#include <string>
#include "InputReader.cpp"
#include "SimpleCalculator.cpp"

class Application
{
private:
    InputReader reader;
    SimpleCalculator calculator;
    void renderText(std::string text);
    void renderMenu();

public:
    void run();
};