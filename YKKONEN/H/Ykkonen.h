#pragma once
#include <bits/stdc++.h>
#include "Node.h"


template <typename T>
struct Ykkonen {
    Node<T>* root = new Node<T>();
    T t;
    Ykkonen() {}
    Ykkonen(const T& _data_);
    void build();
    void reInit(const T& _data_);
    bool find(const T& _data);
};