#include <string>
#include <map>
#include <algorithm>
#include "Strings.hpp"

namespace Html
{
    static const char HTML_ENTITY_BEGINS = '&';
    static const char HTML_ENTITY_ENDS = ';';

    static const std::string DOUBLE_QUOTE = "quot";
    static const std::string APOSTROPHE = "apos";
    static const std::string MARK_LESS = "lt";
    static const std::string MARK_GREATER = "gt";
    static const std::string AMPERSAND = "amp";

    static std::map<char, std::string> HTML_ENTITIES_MAP = {
            { '"', DOUBLE_QUOTE },
            { '`', APOSTROPHE },
            { '<', MARK_LESS },
            { '>', MARK_GREATER },
            { '&', AMPERSAND }
    };

    class Encoder
    {
    public:
        Encoder& operator<< (const std::string & arg);

        operator std::string() const;

    private:
        std::string EncodeSymbol(char ch);

        Strings::Concatenator m_encodedString;
    };
}