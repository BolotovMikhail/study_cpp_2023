#ifndef PRIMITIVE_IPRIMITIVE_H
#define PRIMITIVE_IPRIMITIVE_H

struct IPrimitive
{
    virtual void PrintProperties() const = 0;
    virtual ~IPrimitive() = default;
};

#endif // PRIMITIVE_IPRIMITIVE_H
