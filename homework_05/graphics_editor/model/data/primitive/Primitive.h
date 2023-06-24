#ifndef PRIMITIVE_PRIMITIVE_H
#define PRIMITIVE_PRIMITIVE_H

#include "IPrimitive.h"
#include "properties.h"

struct Primitive : IPrimitive
{
    Primitive(const int Index, const Color color, const Form form);

    void PrintProperties() const override;

private:
    Color m_color;
    Form m_form;
    int m_index;
};

#endif // PRIMITIVE_PRIMITIVE_H
