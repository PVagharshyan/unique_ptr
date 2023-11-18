#include <iostream>

template <typename T>

class unique_ptr {
public:
    explicit unique_ptr(T*);
    unique_ptr(const unique_ptr&);
    unique_ptr(unique_ptr&&) noexcept;
    ~unique_ptr();

    unique_ptr& operator=(unique_ptr&& ptr) noexcept;

    T& operator*() const;

    T* operator->() const;

    T* release();
private:
    T* m_ptr;
};

#include "unique_ptr_impl.h"
