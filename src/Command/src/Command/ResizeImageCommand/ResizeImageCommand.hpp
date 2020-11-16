#pragma once

#include "../ICommand.hpp"

class ResizeImageCommand : public ICommand
{
public:
    ResizeImageCommand(const std::shared_ptr<IImage> &image, int newWidth, int newHeight);

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    std::shared_ptr<IImage> m_image;
    int m_newWidth;
    int m_newHeight;
    int m_oldWidth;
    int m_oldHeight;
};
