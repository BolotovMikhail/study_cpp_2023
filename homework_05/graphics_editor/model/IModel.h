#ifndef MODEL_IMODEL_H
#define MODEL_IMODEL_H

#include "data/document/IDocument.h"
#include "IView.h"
#include <memory>

struct IModel
{
    virtual IDocument* AddActiveDocument() = 0;
    virtual IDocument* AddActiveDocument(std::unique_ptr<IDocument> document) = 0;
    virtual void RemoveActiveDocument(const int Index) = 0;
    virtual IView* GetView() = 0;
    virtual int GetDocumentsCount() const = 0;
    virtual IDocument* GetDocument(const int Index) = 0;
    virtual IDocument* GetDocument() = 0;
    virtual IDocument* GetVisibleDocument() = 0;

    virtual ~IModel() = default;
};

#endif // MODEL_IMODEL_H
