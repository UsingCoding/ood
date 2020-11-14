#include "ListController.hpp"
#include <iostream>
#include <Strings.hpp>

void ListController::ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition)
{

}

void ListController::Handle(Common::Console::IInput &input, Common::Console::IOutput &output)
{
    Strings::Concatenator concatenator;

    concatenator << "Title: " << m_document->GetTitle() << '\n';

    for (int i = 0; i < m_document->GetItemsCount(); ++i)
    {
        auto item = m_document->GetItem(i);

        concatenator << i << ". ";

        if (item.GetImage() != nullptr)
        {
            concatenator << "Image: "
            << item.GetImage()->GetWidth() << ' '
            << item.GetImage()->GetHeight() << ' '
            << item.GetImage()->GetPath() << '\n';
        }
        else if (item.GetParagraph() != nullptr)
        {
            concatenator << "Paragraph: "
            << item.GetParagraph()->GetText() << '\n';
        }
        else
        {
            concatenator << "Unknown type of document item";
        }
    }

    *output << (std::string) concatenator;
}
