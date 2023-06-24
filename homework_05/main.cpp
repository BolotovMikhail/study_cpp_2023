#include <iostream>

#include "EditorController.h"

namespace user {
auto editorController = EditorController::CreateController();

inline void ClickCreateNewDocumentButton()
{
    std::cout << "\n[user] ClickCreateNewDocumentButton\n";
    editorController->CreateNewDocument();
    std::cout << "---------------------\n";
}

inline void ClickImportDocumentFromFileButton()
{
    std::cout << "\n[user] ClickImportDocumentFromFileButton\n";
    constexpr auto ExtermalIndex{100};
    auto externalDocument = ActiveDocument::CreateDocument(ExtermalIndex);
    editorController->ImportDocument(std::move(externalDocument));
    std::cout << "---------------------\n";
}

inline void ClickExportDocumentToFileButton()
{
    // TODO: only currently visible document are exported
    std::cout << "\n[user] ClickExportDocumentToFileButton\n";
    editorController->ExportDocument();
    std::cout << "---------------------\n";
}

inline void ClickCreateGraphicsPrimitive(const Color color, const Form form)
{
    std::cout << "\n[user] ClickCreateGraphicsPrimitive\n";
    editorController->CreateGraphicsPrimitive(color, form);
    std::cout << "---------------------\n";
}

inline void ClickRemoveGraphicsPrimitive()
{
    std::cout << "\n[user] ClickRemoveGraphicsPrimitive\n";
    // TODO: no primitives indexes getting method yet
    editorController->RemoveGraphicsPrimitive(0);
    std::cout << "---------------------\n";
}
} // namespace user

int main()
{
    std::cout << "===== Start session =====\n";

    user::ClickCreateNewDocumentButton();
    user::ClickImportDocumentFromFileButton();
    user::ClickExportDocumentToFileButton();
    user::ClickCreateGraphicsPrimitive(Color::GREEN, Form::SQUARE);
    user::ClickCreateGraphicsPrimitive(Color::RED, Form::CIRCLE);
    user::ClickRemoveGraphicsPrimitive();

    std::cout << "===== End session =====\n";

    return 0;
}