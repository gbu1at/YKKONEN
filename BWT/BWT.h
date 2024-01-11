#pragma once
#include <bits/stdc++.h>
#include "../YKKONEN/CPP/Node.cpp"
#include "../YKKONEN/CPP/Ykkonen.cpp"

template <typename T>
struct BWT {
    Node<T>* root;
    T t;
    BWT(const T& t);
    std::pair<T, int> coder();
    int dfs(Node<T>* v, T& result, int& k, bool flag, int rank, int maxRank);
    Ykkonen<T> ykkonen;
};

template <typename T>
T decoder(const T& _data_, int k);
