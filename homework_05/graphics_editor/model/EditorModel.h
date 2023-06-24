#ifndef MODEL_EDITOR_MODEL_H
#define MODEL_EDITOR_MODEL_H

#include "IModel.h"
#include "EditorView.h"
#include "data/document/ActiveDocument.h"

#include <map>

struct EditorModel : IModel
{
    EditorModel();
    static std::unique_ptr<IModel> CreateModel();

    IDocument* AddActiveDocument() override;
    IDocument* AddActiveDocument(std::unique_ptr<IDocument> document) override;
    void RemoveActiveDocument(const int Index) override;
    IView* GetView() override;
    int GetDocumentsCount() const override;
    IDocument* GetDocument(const int Index) override;
    IDocument* GetDocument() override;
    IDocument* GetVisibleDocument() override;

private:
    std::unique_ptr<IView> m_editorView;
    std::map<int, std::unique_ptr<IDocument>> m_activeDocuments;
    IDocument* m_visibleDocument{nullptr};
    int m_count{0}; // TODO: not the best way to use indexes
};

#endif // MODEL_EDITOR_MODEL_H
