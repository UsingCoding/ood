#include "ResizeImageCommand.hpp"

ResizeImageCommand::ResizeImageCommand(
        const std::shared_ptr<IImage> &image,
        int newWidth,
        int newHeight
) :
        m_image(image),
        m_newWidth(newWidth),
        m_newHeight(newHeight),
        m_oldHeight(image->GetHeight()),
        m_oldWidth(image->GetWidth())
{}

void ResizeImageCommand::Execute(IDocument &document)
{
    m_image->Resize(m_newWidth, m_newHeight);
}

void ResizeImageCommand::Revert(IDocument &document)
{
    m_image->Resize(m_oldWidth, m_oldHeight);
}

void ResizeImageCommand::Dispose()
{

}
