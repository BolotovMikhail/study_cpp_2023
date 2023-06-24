#include "EditorModel.h"

#include <iostream>

EditorModel::EditorModel()
{
    m_editorView = std::make_unique<EditorView>();
}

std::unique_ptr<IModel> EditorModel::CreateModel()
{
    return std::make_unique<EditorModel>();
}

IDocument* EditorModel::AddActiveDocument()
{
    const auto Index{m_count++};
    std::cout << "Add new Document " << Index << " to m_activeDocuments map\n";
    m_activeDocuments[Index] = ActiveDocument::CreateDocument(Index);
    m_visibleDocument = GetDocument(Index);

    return m_visibleDocument;
}

IDocument* EditorModel::AddActiveDocument(std::unique_ptr<IDocument> document)
{
    const auto Index{document->GetIndex()};
    std::cout << "Add existing Document " << Index << " to m_activeDocuments map\n";
    m_activeDocuments[Index] = std::move(document);
    m_visibleDocument = GetDocument(Index);

    return m_visibleDocument;
}

void EditorModel::RemoveActiveDocument(const int Index)
{
    // TODO: error handling access to a non-existent index
    std::cout << "Remove active document " << Index << "\n";
    m_activeDocuments.erase(Index);
}

IView* EditorModel::GetView()
{
    return m_editorView.get();
}

int EditorModel::GetDocumentsCount() const
{
    return m_activeDocuments.size();
}

IDocument* EditorModel::GetDocument(const int Index)
{
    // TODO: error handling access to a non-existent index
    return m_activeDocuments.at(Index).get();
}

IDocument* EditorModel::GetDocument()
{
    if(m_activeDocuments.empty())
    {
        std::cout << "No open document\n";
        return nullptr;
    }

    auto lastDocument = m_activeDocuments.end();
    --lastDocument;
    return lastDocument->second.get();
}

IDocument* EditorModel::GetVisibleDocument()
{
    return m_visibleDocument;
}
