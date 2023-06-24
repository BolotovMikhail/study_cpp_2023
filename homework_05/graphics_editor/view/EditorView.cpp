#include "EditorView.h"

#include <iostream>

EditorView::EditorView() { }

void EditorView::OpenDocument(IDocument* document)
{
    std::cout << "[View]: Open document " << document->GetIndex() << "\n";
    document->PrintAllPrimitives();
}

void EditorView::UpdateDocument(IDocument* document)
{
    std::cout << "[View]: Update document " << document->GetIndex() << "\n";
    document->PrintAllPrimitives();
}

void EditorView::CloseDocument(IDocument* document)
{
    std::cout << "[View]: Close document " << document->GetIndex() << "\n";
}
