#pragma once

#include "../ICommand.hpp"

class ReplaceTextCommand : public ICommand
{
public:
    ReplaceTextCommand(const std::shared_ptr<IParagraph> &paragraph, const std::string &newText);

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    std::shared_ptr<IParagraph> m_paragraph;
    std::string m_newText;
    std::string m_oldText;
};
