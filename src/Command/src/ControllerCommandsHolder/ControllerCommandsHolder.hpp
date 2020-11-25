#pragma once

#include "IControllerCommandsHolder.hpp"

class ControllerCommandsHolder : public IControllerCommandsHolder
{
public:
    ControllerType Get(const std::string &command) override;

    bool Has(const std::string &command) override;

    std::string GetCommandByControllerType(ControllerType controllerType) override;

private:
    const std::map<std::string, ControllerType> m_commandControllerMap = {
        std::make_pair("SetTitle", ControllerType::SET_TITLE),
        std::make_pair("List", ControllerType::LIST),
        std::make_pair("InsertParagraph", ControllerType::INSERT_PARAGRAPH),
        std::make_pair("ReplaceText", ControllerType::REPLACE_TEXT),
        std::make_pair("Undo", ControllerType::UNDO),
        std::make_pair("Redo", ControllerType::REDO),
        std::make_pair("InsertImage", ControllerType::INSERT_IMAGE),
        std::make_pair("ResizeImage", ControllerType::RESIZE_IMAGE),
        std::make_pair("Save", ControllerType::SAVE_DOCUMENT),
        std::make_pair("DeleteItem", ControllerType::DELETE_ITEM),
        std::make_pair("Help", ControllerType::HELP),
    };
};

