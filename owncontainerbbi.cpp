#include "owncontainerbbi.h"

#include <algorithm>

OwnContainerBBI::OwnContainerBBI(std::initializer_list<int> values) :
    size(values.size()),
    data(new int[size])
{
    std::copy(values.begin(), values.end(), data.get());
}

OwnContainerBBI::iterator OwnContainerBBI::begin()
{
    return iterator(data.get());
}

OwnContainerBBI::iterator OwnContainerBBI::end()
{
    return iterator(data.get() + size);
}

OwnContainerBBI::const_iterator OwnContainerBBI::begin() const
{
    return const_iterator(data.get());
}

OwnContainerBBI::const_iterator OwnContainerBBI::end() const
{
    return const_iterator(data.get() + size);
}

