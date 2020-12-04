#pragma once

#include "../../../src/Command/ICommand.hpp"

namespace CommandHistoryTests
{
    class MockCommand : public ICommand
    {
    public:
        MockCommand(
            const std::string &id,
            std::vector<std::string> &callStack,
            std::vector<std::string> &disposeStack
        )
        : m_id(id), m_callStack(callStack), m_disposeStack(disposeStack) {}

        void Execute(IDocument &document) override;

        void Revert(IDocument &document) override;

        void Dispose() override;

    private:
        std::string m_id;
        std::vector<std::string> & m_callStack;
        std::vector<std::string> & m_disposeStack;
    };
}