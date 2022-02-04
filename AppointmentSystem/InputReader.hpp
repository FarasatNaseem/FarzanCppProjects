#include <iostream>
#include <string>
#include <algorithm>


class InputReader
{
private:
    /* data */

public:
    int readChoice();
    int readID();
    std::string readName();
    int readAge();
    std::string readDOB();
    int readPosition();
    char readGender();
};
