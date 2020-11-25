#include <Strings.hpp>
#include <Arrays.hpp>
#include <Html.hpp>
#include "HtmlDocumentConverter.hpp"

std::string HtmlDocumentConverter::Convert(const IDocument &document)
{
    std::vector<std::string> elements;

    for (int i = 0; i < document.GetItemsCount(); ++i)
    {
        auto item = document.GetItem(i);

        if (item.GetImage() != nullptr)
        {
            elements.push_back(ConvertImage(item.GetImage()));
        }
        else if (item.GetParagraph() != nullptr)
        {
            elements.push_back(ConvertParagraph(item.GetParagraph()));
        }
        else
        {
            throw std::logic_error("Unknown element type encountered in document");
        }
    }

    return Html::Encoder() << Strings::Concatenator() <<
    "<!DOCTYPE html>\n"
    "<html lang=\"\">\n"
    "<head>\n"
    "    <meta charset=\"UTF-8\">\n"
    "    <title>" << document.GetTitle() <<"</title>\n"
    "</head>\n"
    "<body>\n" <<
    Arrays::Join(elements.begin(), elements.end(), "\n") <<
    "</body>\n"
    "</html>";
}

std::string HtmlDocumentConverter::ConvertImage(const std::shared_ptr<const IImage> &image) const
{
    return Strings::Concatenator() <<
    "<img src=\"" << image->GetPath() << "\" height=\"" << image->GetHeight() << "\" width=\"" << image->GetWidth() << "\" />\n";
}

std::string HtmlDocumentConverter::ConvertParagraph(const std::shared_ptr<const IParagraph> &paragraph) const
{
    return Strings::Concatenator() <<
    "<p>\n"
    "  " << paragraph->GetText() << "\n"
    "<p>\n"
    ;
}
