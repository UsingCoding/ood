#pragma once

#include <vector>

#include <Application/Input/IInput.hpp>
#include <Application/Input/AbstractInput/AbstractInput.hpp>

namespace Common::Console
{
    class ArgvInput : public AbstractInput
    {
    public:
        ArgvInput(int argc, char const *argv[]);

        void Parse() override;

    private:
        std::unique_ptr<std::vector<std::string>> m_tokens;
    };
}



