#pragma once
#include <bits/stdc++.h>
#include "Edge.h"

template <typename T>
struct Edge;

template <typename T>
struct Node {
    std::map<int, Edge<T>> children;
    Node* suffixLink;
    bool find(int letter);
    Edge<T> get(int letter);
    void createSuffixEnd(int letter, int left, T* t);
    void changeChild(int letter, const Edge<T>& e);

};