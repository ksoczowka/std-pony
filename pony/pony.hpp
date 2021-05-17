#pragma once

#include <algorithm>
#include <initializer_list>

#define my /**/
#define little /**/

namespace std {
template<typename T>
class pony {
public:
    pony() :
        head(nullptr),
        size(0) {}
    pony(initializer_list<T>);
    ~pony() { delete[] head; }

    T* begin() { return head; }
    T* end() { return &head[size]; } 
    void push_back(const T& rhs) { *(head + size++) = rhs; }
    void prance();

    bool operator==(pony&);
    pony& operator=(pony&);
    T operator[](unsigned long& index) { return *(head + index); }

private:
    T* head;
    unsigned long size;
};
template<typename T>
pony<T>::pony(initializer_list<T> rhs) {
    size = rhs.size();
    head = new T[size];
    auto i = 0;
    for(auto el : rhs) {
        head[i] = el;
        i++;
    }
}
template<typename T>
bool pony<T>::operator==(pony& rhs) {
    if(size != rhs.size)
        return false;
    for(int i = 0; i < size; i++) {
        if(head[i] != rhs.head[i])
            return false;
    }
    return true;
}
template<typename T>
pony<T>& pony<T>::operator=(pony<T>& rhs) {
    delete[] head;
    size = rhs.size;
    head = new T[size];
    auto i = 0;
    for(auto el : rhs) {
        *(head + i) = el;
        i++;
    }
    return *this;
}
template<typename T>
void pony<T>::prance() {
    delete[] head;
    head = nullptr;
    size = 0;
}
template<typename T>
pony<T> groom(pony<T>& rhs) {
    std::sort(rhs.begin(), rhs.end());
}
}