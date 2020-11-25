#include "Html.hpp"

Html::Encoder& Html::Encoder::operator<<(const std::string &arg)
{
    std::for_each(arg.begin(), arg.end(), [=](char ch){
        m_encodedString << EncodeSymbol(ch);
    });

    return *this;
}

Html::Encoder::operator std::string() const
{
    return m_encodedString;
}

std::string Html::Encoder::EncodeSymbol(char ch)
{
    auto it = HTML_ENTITIES_MAP.find(ch);

    if (it == HTML_ENTITIES_MAP.end())
    {
        return Strings::Concatenator() << ch;
    }

    return Html::HTML_ENTITY_BEGINS + it->second + HTML_ENTITY_ENDS;

}
