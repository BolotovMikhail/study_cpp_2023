#ifndef DOCUMENT_ACTIVE_DOCUMENT_H
#define DOCUMENT_ACTIVE_DOCUMENT_H

#include "IDocument.h"
#include "data/primitive/Primitive.h"

#include <memory>
#include <map>

struct ActiveDocument : IDocument
{
    ActiveDocument(const int Index);

    static std::unique_ptr<IDocument> CreateDocument(const int Index);

    void CreatePrimitive(const Color color, const Form form) override;
    void RemovePrimitive(const int Index) override;
    void PrintPrimitiveProperty(const int Index) const override;
    void PrintAllPrimitives() const override;
    int GetPrimitivesCount() const override;
    int GetIndex() const override;

    void SetAsVisible() override;
    void SetAsInvisible() override;

    ~ActiveDocument() = default;
private:
    std::map<int, std::unique_ptr<IPrimitive>> m_primitives;
    int m_count{0};
    int m_index{-1};
    bool m_isActive{false};
};

#endif // DOCUMENT_ACTIVE_DOCUMENT_H
