#ifndef __JJALLOC__
#define __JJALLOC__

#include <climits>  //for UNIT_MAX
#include <cstddef>  //ptrdiff_t,size_t
#include <cstdlib>  //for exit()
#include <iostream> //for cerr
#include <new>      //for placement new.

namespace JJ {
// TODO: What is the role of the secend param
template <class T> inline T *_allocate(ptrdiff_t size, T *) {
    std::set_new_handler(0);
    // NOTE: https://cplusplus.com/reference/new/operator%20new/?kw=operator+new
    T *tmp = (T *)(::operator new((size_t)(size * sizeof(T))));
    if (tmp == 0) {
        std::cerr << "out of memory" << std::endl;
        exit(1);
    }
    return tmp;
}

template <class T> inline void _deallocate(T *buffer) {
    // NOTE: https://cplusplus.com/reference/new/operator%20delete/
    ::operator delete(buffer);
}

template <class T1, class T2> inline void _construct(T1 *p, const T2 &value) {
    new (p) T1(value); // placement new. invoke ctor of T1
}

template <class T> inline void _destory(T *ptr) { ptr->~T(); }

template <class T> class allocator {
  public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_referemce;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    // rebind allocator of type U
    template <class U> struct rebind {
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void *hint = 0) {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) { _deallocate(p); }

    void construct(pointer p, const T &value) { _construct(p, value); }

    void destroy(pointer p) { _destory(p); }

    pointer address(reference x) { return (pointer)&x; }

    const_pointer const_adress(const_referemce x) { return (const_pointer)&x; }

    size_type max_size() const { return size_type(UINT_MAX / sizeof(T)); }
};
} // namespace JJ
#endif //__JJALLOC__
