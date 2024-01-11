#pragma once
#include <bits/stdc++.h>
#include "BWT.h"
#include "../YKKONEN/CPP/Ykkonen.cpp"

template <typename T>
int BWT<T>::dfs(Node<T>* v, T& result, int&k, bool flag, int rank, int maxRank) {
    if (v->children.empty()) return (rank > maxRank + 1);
    int c = 0;
    for (auto&[_, edge] : v->children) {
        
        bool localFlag = flag;
        for (int i = 0; i < std::min(edge.len(), maxRank - rank); ++i)
            if (edge.get(i) != t[rank + i]) 
                localFlag = false;
        
        int c_ = dfs(edge.to, result, k, localFlag, rank + edge.len(), maxRank);
        
        if (rank < maxRank && rank + edge.len() >= maxRank) {
            int letter = edge.get(maxRank - rank - 1);
            if (localFlag) k = result.size();
            for (int i = 0; i < c_; ++i) result.push_back(letter);
        }
        c += c_;
    }
    return c;
}

template <typename T>
BWT<T>::BWT(const T& t) {
    this->t = t;
    T doubleT; doubleT.resize(2 * t.size());
    for (int i = 0; i < t.size(); ++i)
        doubleT[i] = doubleT[i + t.size()] = t[i];
    ykkonen.reInit(doubleT);
}

template <typename T>
std::pair<T, int> BWT<T>::coder() {
    T result;
    int k;
    dfs(ykkonen.root, result, k, true, 0, t.size());
    return {result, k};
}

template <typename T>
T decoder(const T& lastColumn, int k) {
    int size = lastColumn.size();
    std::vector<int> p(size);
    std::map<int, int> q;
    std::map<int, int> lastIndexLetter;

    for (int i = 0; i < size; ++i) {
        int letter = lastColumn[i];
        q[letter] += 1;
        if (lastIndexLetter.find(letter) != lastIndexLetter.end())
            p[i] += p[lastIndexLetter[letter]] + 1;
        lastIndexLetter[letter] = i;
    }

    int sum = 0;
    for (auto&[key, val] : q) {
        sum += val;
        q[key] = sum - val;
    }

    T result; result.resize(size);
    for (int i = size - 1; i >= 0; --i) {
        result[i] = lastColumn[k];
        int letter = lastColumn[k];
        k = p[k] + q[letter];
    }
    return result;
}
