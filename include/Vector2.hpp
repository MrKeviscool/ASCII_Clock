#pragma once

template<typename T>
struct Vector2{
    T x,y;
    Vector2(const T x, const T y);
};

template<typename T>
Vector2<T>::Vector2(const T x, const T y) : x(x), y(y){};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
