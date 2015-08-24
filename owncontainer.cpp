#include "owncontainer.h"

#include <algorithm>

OwnContainer::OwnContainer(std::initializer_list<unsigned int> values) :
    data(new unsigned int[values.size()])
{
    std::copy(values.begin(), values.end(), data.get());
}

