#ifndef OWNCONTAINER_H
#define OWNCONTAINER_H

#include "owniterator.h"

#include <memory>

class OwnContainer
{
public:
    OwnContainer(std::initializer_list<unsigned int> values);
private:
    std::unique_ptr<unsigned int[]> data;
};

#endif // OWNCONTAINER_H
