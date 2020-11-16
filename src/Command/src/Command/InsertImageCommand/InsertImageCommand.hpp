#pragma once

#include "../ICommand.hpp"
#include "../../Resource/FileResource.hpp"
#include "../../Resource/FileResourceRepository/IFileResourceRepository.hpp"

class InsertImageCommand : public ICommand
{
public:
    InsertImageCommand(
        std::shared_ptr<FileResource> file,
        std::unique_ptr<IFileResourceRepository> & fileResourceRepo,
        int width,
        int height,
        const std::optional<size_t> &position
    ) :
        m_file(file),
        m_fileResourceRepo(fileResourceRepo),
        m_width(width),
        m_height(height),
        m_position(position)
    {}

    void Execute(IDocument &document) override;

    void Revert(IDocument &document) override;

    void Dispose() override;

private:
    std::shared_ptr<FileResource> m_file;
    std::unique_ptr<IFileResourceRepository> & m_fileResourceRepo;
    int m_width;
    int m_height;
    std::optional<size_t> m_position;
    std::shared_ptr<IImage> m_image;
};
