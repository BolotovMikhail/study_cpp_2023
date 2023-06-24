#include <iostream>

#include "Primitive.h"

Primitive::Primitive(const int Index, const Color color, const Form form) :
    m_index(Index), m_color(color), m_form(form)
{
    std::cout << "Create primitive " << m_index << " with [Color " << \
        static_cast<std::underlying_type<Color>::type>(m_color) << \
        ", Form " << static_cast<std::underlying_type<Form>::type>(m_form) << "]\n";
};

void Primitive::PrintProperties() const
{
    std::cout << "Primitive " << m_index << " has properties: [Color " << \
        static_cast<std::underlying_type<Color>::type>(m_color) << \
        ", Form " << static_cast<std::underlying_type<Form>::type>(m_form) << "]\n";
}
