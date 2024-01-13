#ifndef IINTERFACE_H
#define IINTERFACE_H

#include <stdint.h>
#include <string>
#include <map>
#include <list>

class IInterface{
public:
    IInterface() = default;
    IInterface& operator=(const IInterface&) = delete;
    IInterface(const IInterface&) = delete;
public:
    virtual ~IInterface(){}
};

using String = std::string;

template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>>
using Map = std::map<_Key, _Tp, _Compare>;

template <typename T>
using List = std::list<T>;

#endif // IINTERFACE_H
