#include "cases.h"

int main()
{
    try
    {
        // First case
        MapWithCustomAllocatorCase();

        // Second case
        CustomContainerCase();
    }
    catch (const std::bad_alloc&)
    {
        std::cerr << "Exception: trying to allocate memory \
for more than <?> elements\n";
    }
    catch (...)
    {
        std::cerr << "Unexpected exception catch\n";
    }

    return 0;
}
