#pragma once

#include <string>
#include "IParagraph.hpp"

class Paragraph : public IParagraph
{
public:
    Paragraph(const std::string &text);

    std::string GetText() const override;

    void SetText(const std::string &text) override;

private:
    std::string m_text;
};
