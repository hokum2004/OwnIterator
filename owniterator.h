#ifndef OWNITERATOR_H
#define OWNITERATOR_H

#include <iterator>
#include <initializer_list>

class OwnContainer;

template<typename ValueType>
class OwnIterator: public std::iterator<std::input_iterator_tag, ValueType>
{
    friend class OwnContainer;
private:
    OwnIterator(ValueType* p);
public:
    OwnIterator(const OwnIterator &it);

    bool operator!=(OwnIterator const& other) const;
    bool operator==(OwnIterator const& other) const; //need for BOOST_FOREACH
    typename OwnIterator::reference operator*() const;
    OwnIterator& operator++();
private:
    ValueType* p;
};

template<typename ValueType>
OwnIterator<ValueType>::OwnIterator(ValueType *p) :
    p(p)
{

}

template<typename ValueType>
OwnIterator<ValueType>::OwnIterator(const OwnIterator& it) :
    p(it.p)
{

}

template<typename ValueType>
bool OwnIterator<ValueType>::operator!=(OwnIterator const& other) const
{
    return p != other.p;
}

template<typename ValueType>
bool OwnIterator<ValueType>::operator==(OwnIterator const& other) const
{
    return p == other.p;
}

template<typename ValueType>
typename OwnIterator<ValueType>::reference OwnIterator<ValueType>::operator*() const
{
    return *p;
}

template<typename ValueType>
OwnIterator<ValueType> &OwnIterator<ValueType>::operator++()
{
    ++p;
    return *this;
}

#endif // OWNITERATOR_H
