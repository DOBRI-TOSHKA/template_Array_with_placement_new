#ifndef ARRAY_WITH_PLACEMENT_NEW
#define ARRAY_WITH_PLACEMENT_NEW

/*
 * Placement new.
 * Данный оператор не выделяет память, а получает своим аргументом адрес
 * на уже выделенную каким-либо образом память (например, на стеке или через malloc()).
 * Происходит размещение (инициализация) объекта путём вызова конструктора,
 * и объект создается в памяти по указанному адресу. Часто такой метод применяют,
 * когда у класса нет конструктора по умолчанию или недоступен оператор присванивания
 * и при этом нужно создать массив объектов.
 *
 * */

/*
 * explicit конструктор
 * Ключевое слово explicit запрещает автоматическое конвертирования конструктора *
 * Например:
 *
 * class MyClass {
 *   int i;
 * public:
 *   explicit MyClass(int j)
 *     {i = j;}
 *   // ...
 * };
 *
 * MyClass ob2 = 10;    //ERROR
 * MyClass ob2(10);     //OK ;)
 *
 * */

#include <cstddef>
#include <iostream>

template<class T>
class Array{

public:

    Array();

    explicit Array(size_t size, const T& value = T());

    Array(Array const &ob);

    Array &operator=(Array const &ob);

    T &operator[](size_t i);    

    const T& operator[](size_t i) const;

    size_t getsize() const;

    void append(const T &value = T());
    void replace(const size_t index, const T &value = T());
    void insert(const size_t index, const T &value = T());

    ~Array();

private:
    size_t size;
    size_t capacity;
    T* arr;
};

template<class T>
Array<T>::Array(size_t size_, const T& value):size(size_),
                                              capacity(size_),
                                              arr(static_cast<T*>(operator new[](size_*sizeof(T))))
{
    for(size_t i = 0; i < size; ++i)  new (arr+i) T(value);
}

template<class T>
Array<T>::Array():size(0),
                  capacity(0),
                  arr(nullptr)
{
}

template<class T>
Array<T>::Array(Array const &ob){

    size = ob.size();
    arr = reinterpret_cast<T*>(operator new[](size * sizeof(T)));
    for(size_t i = 0; i < size; ++i) new(arr+i) T(ob[i]);
}

template<class T>
Array<T> &Array<T>::operator=(Array const &ob){

    if(this!=&ob){

        this->~Array();
        size = ob.size();

        arr = reinterpret_cast<T*>(operator new[](size * sizeof(T)));

        for(size_t i = 0; i < size; ++i) new(arr+i) T(ob[i]);

        return *this;
    }
    return *this;
}

template<class T>
T &Array<T>::operator[](size_t i){

    if(i >= 0 && i < size) return arr[i];
    throw -1;
}

template<class T>
const T& Array<T>::operator[](size_t i) const{

    if(i >= 0 && i < size) return arr[i];
    throw -1;
}

template<class T>
size_t Array<T>::getsize() const{

    return size;
}

template<class T>
void Array<T>::append(const T &value){

    if(size < capacity){
        new(arr + size) T(value);
        ++size;
        return;
    }

    else{

        capacity = 2 * capacity +1;
        T *arr_tmp = static_cast<T*>(operator new[](capacity * sizeof(T)));

        for(size_t i = 0; i < size; ++i){

            new(arr_tmp + i) T(arr[i]);
        }

        new(arr_tmp + size) T(value);

        this->~Array();
        arr = arr_tmp;

        ++size;
    }
}

template<class T>
void Array<T>::replace(const size_t index, const T &value)
{
    if(index < 0 || index >= size){
        return;
    }

    else{
        new(arr + index) T(value);
    }
}

template<class T>
void Array<T>::insert(const size_t index, const T &value)
{
    if(index < 0 || index >= size){
        return;
    }
    else if(size < capacity){

        for(size_t i = size - 1; i >= index; --i){
            new(arr + i + 1) T(arr[i]);
        }
        new(arr + index) T(value);
        ++size;
    }
    else{

        capacity = 2 * capacity +1;
        T *arr_tmp = static_cast<T*>(operator new[](capacity * sizeof(T)));

        for(size_t i = size - 1; i >= index; --i){

            new(arr + i + 1) T(arr[i]);
        }

        new(arr_tmp + index) T(value);

        this->~Array();
        arr = arr_tmp;

        ++size;
    }
}

template<class T>
Array<T>::~Array(){

    for(size_t i=0;i < size;i++) this->arr[i].~T();
    operator delete[](arr);
}

#endif
