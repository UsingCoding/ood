#pragma once

#include "../AbstractController/AbstractController.hpp"
#include "../../Resource/FileResourceRepository/IFileResourceRepository.hpp"

class InsertImageController : public AbstractController
{
public:
    InsertImageController(
        std::shared_ptr<ICommandsHistory> &commandsHistory,
        std::unique_ptr<IDocument> &document,
        std::unique_ptr<IFileResourceRepository> & fileResourceRepo
        )
    : AbstractController(commandsHistory, document), m_fileResourceRepo(fileResourceRepo) {}

    void ConfigureInputDefinition(std::unique_ptr<Common::Console::IInputDefinition> &definition) override;

    void Handle(Common::Console::IInput &input, Common::Console::IOutput &output) override;

private:
    std::unique_ptr<IFileResourceRepository> & m_fileResourceRepo;
};
