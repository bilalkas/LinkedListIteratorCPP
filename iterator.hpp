#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <class T>
class Iterator {

    private:

    public:

    virtual bool hasNext() = 0;
    virtual const T next() = 0;
};

#endif


