#include <iostream>

#include "ActiveDocument.h"

ActiveDocument::ActiveDocument(const int Index) : m_index(Index)
{
    std::cout << "Create new ActiveDocument " << m_index << "\n";
};

std::unique_ptr<IDocument> ActiveDocument::CreateDocument(const int Index)
{
    return std::make_unique<ActiveDocument>(Index);
}

void ActiveDocument::CreatePrimitive(const Color color, const Form form)
{
    const auto Index{m_count++};
    std::cout << "Add new Primitive " << Index << " to m_primitives map\n";
    m_primitives[Index] = std::make_unique<Primitive>(Index, color, form);
}

void ActiveDocument::RemovePrimitive(const int Index)
{
    // TODO: error handling access to a non-existent index
    std::cout << "Remove primitive " << Index << "\n";
    m_primitives.erase(Index);
}

void ActiveDocument::PrintPrimitiveProperty(const int Index) const
{
    // TODO: error handling access to a non-existent index
    m_primitives.at(Index)->PrintProperties();
}

void ActiveDocument::PrintAllPrimitives() const
{
    std::cout << "\n******** Document " << GetIndex() << " ********\n";
    for (const auto& primitive : m_primitives)
    {
        primitive.second->PrintProperties();
    }
    std::cout << "****** end Document " << GetIndex() << " ******\n\n";
}

int ActiveDocument::GetPrimitivesCount() const
{
    return m_primitives.size();
}

int ActiveDocument::GetIndex() const
{
    return m_index;
}

void ActiveDocument::SetAsVisible()
{
    std::cout << "Set document " << GetIndex() << " as visible\n";
    m_isActive = true;
}

void ActiveDocument::SetAsInvisible()
{
    std::cout << "Set document " << GetIndex() << " as invisible\n";
    m_isActive = false;
}
