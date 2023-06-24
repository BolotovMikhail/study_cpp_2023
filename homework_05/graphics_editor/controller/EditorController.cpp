#include "EditorController.h"

#include <iostream>

EditorController::EditorController() : m_editorModel(EditorModel::CreateModel())
{
    std::cout << "Create EditorController\n";
    m_editorView = m_editorModel->GetView();
    m_visibleDocument = m_editorModel->GetVisibleDocument();
}

std::unique_ptr<IController> EditorController::CreateController()
{
    return std::make_unique<EditorController>();
}

void EditorController::CreateNewDocument()
{
    if (m_visibleDocument)
    {
        m_visibleDocument->SetAsInvisible();
    }

    m_visibleDocument = m_editorModel->AddActiveDocument();
    m_visibleDocument->SetAsVisible();
    m_editorView->OpenDocument(m_visibleDocument);
}

void EditorController::ImportDocument(std::unique_ptr<IDocument> document)
{
    if (m_visibleDocument)
    {
        m_visibleDocument->SetAsInvisible();
    }

    m_visibleDocument = m_editorModel->AddActiveDocument(std::move(document));
    m_visibleDocument->SetAsVisible();
    m_editorView->OpenDocument(m_visibleDocument);
}

void EditorController::ExportDocument()
{
    if (!m_visibleDocument)
    {
        std::cout << "No document\n";
        return;
    }

    m_visibleDocument->SetAsInvisible();
    std::cout << "Save Document " << m_visibleDocument->GetIndex() << " to file\n";
    m_editorView->CloseDocument(m_visibleDocument);
    m_editorModel->RemoveActiveDocument(m_visibleDocument->GetIndex());

    m_visibleDocument = m_editorModel->GetDocument();
    m_visibleDocument->SetAsVisible();
    m_editorView->OpenDocument(m_visibleDocument);
}

void EditorController::CreateGraphicsPrimitive(const Color color, const Form form)
{
    if (!m_visibleDocument)
    {
        CreateNewDocument();
    }

    m_visibleDocument->CreatePrimitive(color, form);
    m_editorView->UpdateDocument(m_visibleDocument);
}

void EditorController::RemoveGraphicsPrimitive(const int Index)
{
    if (!m_visibleDocument)
    {
        std::cout << "Not found active document\n";
        return;
    }

    // TODO: in this implementation, there is no check for the existence of a primitive
    m_visibleDocument->RemovePrimitive(Index);
    m_editorView->UpdateDocument(m_visibleDocument);
}

EditorController::~EditorController()
{
    for (auto document{m_editorModel->GetDocument()}; document != nullptr; document = m_editorModel->GetDocument())
    {
        m_editorView->CloseDocument(document);
        m_editorModel->RemoveActiveDocument(document->GetIndex());
    }

    // TODO: implement saving open documents
}
