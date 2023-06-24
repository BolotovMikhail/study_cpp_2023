#ifndef CONTROLLER_EDITOR_CONTROLLER_H
#define CONTROLLER_EDITOR_CONTROLLER_H

#include "IController.h"
#include "EditorModel.h"

struct EditorController : IController
{
    EditorController();

    static std::unique_ptr<IController> CreateController();

    void CreateNewDocument() override;
    void ImportDocument(std::unique_ptr<IDocument> document) override;
    void ExportDocument() override;
    void CreateGraphicsPrimitive(const Color color, const Form form) override;
    void RemoveGraphicsPrimitive(const int Index) override;

    ~EditorController();

private:
    std::unique_ptr<IModel> m_editorModel;
    IView* m_editorView;
    IDocument* m_visibleDocument{nullptr};
};

#endif // CONTROLLER_EDITOR_CONTROLLER_H
