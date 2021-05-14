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
    void push_back(T); //todo

    bool operator==(pony&);
    pony& operator=(pony&); //todo
    T operator[](unsigned long index) { return *(head + index); }

private:
    T* head;
    unsigned long size;
};
template<typename T>
pony<T>::pony(initializer_list<T> l) {
    size = l.size();
    head = new T[size];
    auto i = 0;
    for(auto el : l) {
        head[i] = el;
        i++;
    }
}
template<typename T>
bool pony<T>::operator==(pony& other) {
    if(size != other.size)
        return false;
    for(int i = 0; i < size; i++) {
        if(head[i] != other.head[i])
            return false;
    }
    return true;
}
template<typename T>
pony<T>& pony<T>::operator=(pony<T>& other) {
    delete[] head;
    size = other.size;
    head = new T[size];
    auto i = 0;
    for(auto el : other) {
        *(head + i) = el;
        i++;
    }
    return *this;
}
}