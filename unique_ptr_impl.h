template <typename T>
unique_ptr<T>::unique_ptr(T* ptr)
:m_ptr(ptr)
{}

template <typename T>
unique_ptr<T>::unique_ptr(const unique_ptr<T>& ptr)
:m_ptr(ptr.m_ptr)
{}

template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr<T>&& ptr) noexcept {
    m_ptr = ptr.m_ptr;
    ptr.m_ptr = nullptr;
}

template <typename T>
unique_ptr<T>::~unique_ptr() {
    delete m_ptr;
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& ptr) noexcept {
    if (this != &ptr) {
        delete m_ptr;
        m_ptr = ptr.m_ptr;
        ptr.m_ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& unique_ptr<T>::operator*() const {
    return *m_ptr;
}

template <typename T>
T* unique_ptr<T>::operator->() const {
    return m_ptr;
}

template <typename T>
T* unique_ptr<T>::release() {
    T* released = m_ptr;
    m_ptr = nullptr;
    return released;
}