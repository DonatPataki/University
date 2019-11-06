#include <cxxabi.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/shm.h>
#include <unistd.h>

template<typename T>
    struct CustomAlloc 
    {
        using size_type = size_t;
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;
        using difference_type = ptrdiff_t;
        Arena& arena;
        CustomAlloc (Arena& arena):arena(arena){}
        int nn {0};
        pointer allocate (size_type n){
        ++arena.nnn;
        ++nn;
        int s;
        char* p=abi::__cxa_demangle(typeid (T).name(), 0, 0, &s);
        std::cout << "Allocating "
                    << n << " objects of "
                    << n*sizeof(T)
                    << " bytes"
                    << typeid (T).name() << "=" << p
                    << " hivasok szama " << nn
                    << " hivasok szama " << arena.nnn
                    << std::endl;
        free(p);
        char *q = arena.q;
        std::cout << "q " << static_cast <const void *> ( q) << std::endl;
        arena.q += n*sizeof(T);
        return reinterpret_cast<T*>(q);
    }
    void deallocate (pointer p, size_type n){
    }
    };
