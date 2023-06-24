#ifndef VIEW_IVIEW_H
#define VIEW_IVIEW_H

#include "data/document/IDocument.h"

struct IView
{
    virtual void OpenDocument(IDocument* document) = 0;
    virtual void UpdateDocument(IDocument* document) = 0;
    virtual void CloseDocument(IDocument* document) = 0;
    virtual ~IView() = default;
};

#endif // VIEW_IVIEW_H
