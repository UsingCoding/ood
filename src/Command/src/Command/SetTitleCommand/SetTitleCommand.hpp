#pragma once

#include "../ICommand.hpp"

class SetTitleCommand : public ICommand
{
public:
    SetTitleCommand(const std::string &newTitle, const std::string &oldTitle);

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    std::string m_newTitle;
    std::string m_oldTitle;
};
