#include "ListCommandHandler.hpp"
#include <iostream>

void ListCommandHandler::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{

}

void ListCommandHandler::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    *output << "Title: " << m_document->GetTitle() << std::endl;

    for (int i = 0; i < m_document->GetItemsCount(); ++i)
    {
        auto item = m_document->GetItem(i);

        *output << i << ". ";

        if (item.GetImage() != nullptr)
        {
            *output << "Image: "
            << item.GetImage()->GetWidth() << ' '
            << item.GetImage()->GetHeight() << ' '
            << item.GetImage()->GetPath() << std::endl;
        }
        else if (item.GetParagraph() != nullptr)
        {
            *output << "Paragraph: "
            << item.GetParagraph()->GetText() << std::endl;
        }
        else
        {
            *output << "Unknown type of document item";
        }
    }
}
