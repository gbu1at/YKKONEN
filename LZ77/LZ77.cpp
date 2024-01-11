#pragma once
#include <bits/stdc++.h>
#include "LZ77.h"
#include "../YKKONEN/CPP/Node.cpp"
#include "../YKKONEN/CPP/Edge.cpp"
#include "Tree.cpp"



template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template <typename T>
std::vector<std::pair<int, int>> LZ77<T>::build() {
    Node<T>* activeNode = root;
    Edge<T> activeEdge;
    int rank = 0, last_idx = -1;
    int deepEdge = 0;
    Tree maxSuffix(t.size());

    for (int i = 0; i < t.size(); ++i) {

        Node<T>* prefSuffix = nullptr;
        int nextLetter = t[i]; 
        while (true) {
            if (deepEdge == 0) {
                if (activeNode->find(nextLetter)) {
                    activeEdge = activeNode->get(nextLetter);
                    deepEdge++;
                    if (activeEdge.len() == deepEdge) {
                        activeNode = activeEdge.to;
                        deepEdge = 0;
                        last_idx = i;
                    }
                    rank++;
                    break;
                }
                activeNode->createSuffixEnd(nextLetter, i, &t);
                if (activeNode == root) break;
                activeNode = activeNode->suffixLink;
                rank--;
            } else {
                if (activeEdge.get(deepEdge) == nextLetter) {
                    deepEdge++;
                    if (activeEdge.len() == deepEdge) {
                        activeNode = activeEdge.to;
                        deepEdge = 0;
                        last_idx = i;
                    }
                    rank++;
                    break;
                }
                rank--;
                Node<T>* newNode = activeEdge.cut(deepEdge);
                newNode->createSuffixEnd(nextLetter, i, &t);
                if (prefSuffix != nullptr) prefSuffix->suffixLink = newNode;
                prefSuffix = newNode;
                int firstIndexEdge = activeEdge.l;
                if (activeNode == root) {
                    firstIndexEdge++;
                    deepEdge--;
                } else activeNode = activeNode->suffixLink;
                activeEdge = activeNode->get(t[firstIndexEdge]);

                while (deepEdge > 0 && deepEdge >= activeNode->get(t[firstIndexEdge]).len()) {
                    activeEdge = activeNode->get(t[firstIndexEdge]);
                    deepEdge -= activeEdge.len();
                    firstIndexEdge += activeEdge.len();
                    activeNode = activeEdge.to;
                }
                if (deepEdge == 0) {
                    prefSuffix->suffixLink = activeNode;
                    prefSuffix = activeNode;
                } else activeEdge = activeNode->get(t[firstIndexEdge]);
            }
        }
        if (activeNode == root && deepEdge == 0) {
            maxSuffix.set(i, 0, i);
        } else {
            int d = rank;
            int start = (deepEdge == 0) ? last_idx : activeEdge.l + deepEdge - 1;
            maxSuffix.set(start - d + 1, d, i - d + 1, i + 1);
        }
    }
    std::vector<std::pair<int, int>> a(t.size() - 1);
    for (int i = 0; i < a.size(); ++i)
        a[i] = maxSuffix.get(i);
    return a;
}


template <typename T>
std::string LZ77<T>::compress(const T& _data_) {
    this->t = _data_;
    this->t.push_back(INT_MAX);
    std::vector<std::pair<int, int>> a = build();
    std::string res = "";
    int i = 0;
    while (i < _data_.size()) {
        auto[start, d] = a[i];
        if (start == i || d <= 4) {
            res += _data_[i];
            i++;
        } else {
            res += "(" + toString(start) + " " + toString(d) + ")";
            i += d;
        }
    }
    return res;
}



std::string decoder(std::string code) {
    std::string result;
    int i = 0;
    while (i < code.size()) {
        if (code[i] != '(') {
            result += code[i];
            i++;
        } else {
            std::string start;
            i++;
            while (code[i] != ' ') {
                start += code[i]; i++;
            }
            i++;
            std::string d;
            while (code[i] != ')') {
                d += code[i]; i++;
            }
            int startInt = stoi(start);
            int dInt = stoi(d);
            i++;

            for (int _ = startInt; _ < startInt + dInt; ++_)
                result += result[_];
        }
    }
    return result;
}