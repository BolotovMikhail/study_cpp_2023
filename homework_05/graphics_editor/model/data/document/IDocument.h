#ifndef DOCUMENT_IDOCUMENT_H
#define DOCUMENT_IDOCUMENT_H

#include "properties.h"

struct IDocument
{
    virtual void CreatePrimitive(const Color color, const Form form) = 0;
    virtual void RemovePrimitive(const int Index) = 0;

    virtual void PrintPrimitiveProperty(const int Index) const = 0;
    virtual void PrintAllPrimitives() const = 0;
    virtual int GetPrimitivesCount() const = 0;
    virtual int GetIndex() const = 0;

    virtual void SetAsVisible() = 0;
    virtual void SetAsInvisible() = 0;

    virtual ~IDocument() = default;
};

#endif // DOCUMENT_IDOCUMENT_H
