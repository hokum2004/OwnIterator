#ifndef OWNCONTAINERBBI_H
#define OWNCONTAINERBBI_H

#include "owniteratorbb.h"

#include <memory>

class OwnContainerBBI
{
public:
    typedef OwnIteratorBB<int> iterator;
    typedef OwnIteratorBB<const int> const_iterator;

    OwnContainerBBI(std::initializer_list<int> values);

    iterator begin();
    iterator end();

    const_iterator begin() const;
    const_iterator end() const;
private:
    const size_t size;
    std::unique_ptr<int[]> data;
};

#endif // OWNCONTAINERBBI_H
