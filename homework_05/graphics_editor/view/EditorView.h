#ifndef VIEW_EDITOR_VIEW_H
#define VIEW_EDITOR_VIEW_H

#include "IView.h"

struct EditorView : IView
{
    EditorView();
    void OpenDocument(IDocument* document) override;
    void UpdateDocument(IDocument* document) override;
    void CloseDocument(IDocument* document) override;

private:
};

#endif // VIEW_EDITOR_VIEW_H
