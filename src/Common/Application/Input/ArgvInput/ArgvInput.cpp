#include "ArgvInput.hpp"

using namespace Common::Console;

ArgvInput::ArgvInput(int argc, const char **argv)
{
    m_tokens = std::make_unique<std::vector<std::string>>();

    for (int i = 0; i < argc; ++i)
    {
        m_tokens->push_back(argv[i]);
    }
}

void ArgvInput::Parse()
{

}
