#pragma once

#include "../ICommand.hpp"

class InsertParagraphCommand : public ICommand
{
public:
    InsertParagraphCommand(const std::optional<size_t> &position, const std::string &text): m_position(position), m_text(text) {}

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    std::optional<size_t> m_position;
    std::string m_text;
    std::shared_ptr<IParagraph> m_paragraph;
};
