#ifndef CONTROLLER_ICONTROLLER_H
#define CONTROLLER_ICONTROLLER_H

#include "data/document/IDocument.h"
#include "data/primitive/IPrimitive.h"
#include "properties.h"

#include <memory>

struct IController
{
    virtual void CreateNewDocument() = 0;
    virtual void ImportDocument(std::unique_ptr<IDocument> document) = 0;
    virtual void ExportDocument() = 0;
    virtual void CreateGraphicsPrimitive(const Color color, const Form form) = 0;
    virtual void RemoveGraphicsPrimitive(const int Index) = 0;
    virtual ~IController() = default;
};

#endif // CONTROLLER_ICONTROLLER_H
