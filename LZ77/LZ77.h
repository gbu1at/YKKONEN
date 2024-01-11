#pragma once
#include <bits/stdc++.h>
#include "../YKKONEN/H/Node.h"


template <typename T>
struct LZ77 {
    Node<T>* root = new Node<T>();
    T t;
    LZ77() {}
    std::vector<std::pair<int, int>> build();
    std::string compress(const T& _data_);
};