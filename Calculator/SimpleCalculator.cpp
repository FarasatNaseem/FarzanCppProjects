#include "SimpleCalculator.hpp"

float SimpleCalculator::add(float valueOne, float valueTwo)
{
    return valueOne + valueTwo;
}

float SimpleCalculator::subtract(float valueOne, float valueTwo)
{
    return valueOne - valueTwo;
}

float SimpleCalculator::mutiply(float valueOne, float valueTwo)
{
    return valueOne * valueTwo;
}

float SimpleCalculator::divide(float valueOne, float valueTwo)
{
    if (valueTwo == 0)
    {
        throw std::invalid_argument("\nCannot divided by zero!");
    }

    return (float)(valueOne / valueTwo);
}

float SimpleCalculator::calculatePower(float base, float power)
{
    float result = 1;

    while (power != 0)
    {
        result *= base;

        --power;
    }

    return result;
}

float SimpleCalculator::calculateSquareRoot(float value)
{
    return std::sqrt(value);
}

float SimpleCalculator::calculateFactorial(float value)
{
    float result = value;

    for (int i = 1; i < value; i++)
    {
        result = result * (value - i);
    }

    return result;
}

float SimpleCalculator::calculateExponential(float power)
{
    const float base = 2.718;

    float result = 1;

    while (power != 0)
    {
        result *= base;

        --power;
    }

    return result;
}