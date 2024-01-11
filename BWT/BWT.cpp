#pragma once
#include <bits/stdc++.h>
#include "BWT.h"
#include "../YKKONEN/CPP/Ykkonen.cpp"


std::string vectorToString(const std::vector<int>& a) {
    std::string b; b.resize(a.size());
    for (int i = 0; i < a.size(); ++i) b[i] = a[i];
    return b;
}

std::vector<int> stringToVector(const std::string& a) {
    std::vector<int> b(a.size());
    for (int i = 0; i < a.size(); ++i) b[i] = a[i];
    return b;
}


int BWT::dfs(Node* v, std::vector<int>& result, int&k, bool flag, int rank, int maxRank) {
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


BWT::BWT(const std::vector<int>& t) {
    init(t);
}

BWT::BWT(const std::string& t) {
    init(stringToVector(t));
}

void BWT::init(const std::vector<int>& t) {
    this->t = t;
    std::vector<int> doubleT(2 * t.size());
    for (int i = 0; i < t.size(); ++i)
        doubleT[i] = doubleT[i + t.size()] = t[i];
    ykkonen.reInit(doubleT);
}

std::pair<std::vector<int>, int> BWT::coderVector() {
    std::vector<int> result;
    int k;
    dfs(ykkonen.root, result, k, true, 0, t.size());
    return {result, k};
}

std::pair<std::string, int> BWT::coderString() {
    auto[result, k] = coderVector();
    return {vectorToString(result), k};
}

std::string decoder(const std::string& lastColumn, int k) {
    return vectorToString(decoder(stringToVector(lastColumn), k));
}

std::vector<int> decoder(const std::vector<int>& lastColumn, int k) {
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

    std::vector<int> result(size);
    for (int i = size - 1; i >= 0; --i) {
        result[i] = lastColumn[k];
        int letter = lastColumn[k];
        k = p[k] + q[letter];
    }
    return result;
}
