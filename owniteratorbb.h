#ifndef OWNITERATORBB_H
#define OWNITERATORBB_H

#include <boost/iterator_adaptors.hpp>

class OwnContainerBBI;

template<typename ValueType>
class OwnIteratorBB: public boost::iterator_facade<
        OwnIteratorBB<ValueType>,
        ValueType,
        boost::single_pass_traversal_tag
        >
{
    friend class OwnContainerBBI;
    friend class boost::iterator_core_access;
private:
    OwnIteratorBB(ValueType* p);
public:
    OwnIteratorBB(const OwnIteratorBB& it);
private:
    bool equal(OwnIteratorBB const& it) const;
    void increment();
    typename OwnIteratorBB::reference dereference() const;

    ValueType* p;
};

template<typename ValueType>
OwnIteratorBB<ValueType>::OwnIteratorBB(ValueType *p) :
    p(p)
{

}

template<typename ValueType>
OwnIteratorBB<ValueType>::OwnIteratorBB(const OwnIteratorBB &it) :
    p(it.p)
{

}

template<typename ValueType>
bool OwnIteratorBB<ValueType>::equal(const OwnIteratorBB &it) const
{
    return p == it.p;
}

template<typename ValueType>
void OwnIteratorBB<ValueType>::increment()
{
    ++p;
}

template<typename ValueType>
typename OwnIteratorBB<ValueType>::reference OwnIteratorBB<ValueType>::dereference() const
{
    return *p;
}

#endif // OWNITERATORBB_H
