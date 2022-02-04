#include "Application.cpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc < 3)
        {
            throw std::invalid_argument("Invalid credentials!!");
        }

        Application application = Application();

        application.start();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
