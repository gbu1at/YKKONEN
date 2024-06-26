#pragma once
#include <bits/stdc++.h>
#include "../H/Ykkonen.h"
#include "Node.cpp"
#include "Edge.cpp"


template <typename T>
void Ykkonen<T>::build() {
    Node<T>* activeNode = root;
    Edge<T> activeEdge;
    int deepEdge = 0;

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
                    }
                    break;
                }
                activeNode->createSuffixEnd(nextLetter, i, &t);
                if (activeNode == root) break;
                activeNode = activeNode->suffixLink;
            } else {
                if (activeEdge.get(deepEdge) == nextLetter) {
                    deepEdge++;
                    if (activeEdge.len() == deepEdge) {
                        activeNode = activeEdge.to;
                        deepEdge = 0;
                    }
                    break;
                }
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
    }
}


template <typename T>
Ykkonen<T>::Ykkonen(const T& _data_) {
    this->t = _data_;
    this->t.push_back(INT_MAX);
    build();
}

template <typename T>
void Ykkonen<T>::reInit(const T& _data_) {
    this->t = _data_;
    this->t.push_back(INT_MAX);
    build();
}

template <typename T>
bool Ykkonen<T>::find(const T& _data_) {
    Node<T>* activeNode = root;
    Edge<T> activeEdge;
    int deepEdge = 0;
    for (int letter : _data_) {
        if (deepEdge == 0) {
            if (!activeNode->find(letter)) return false;
            activeEdge = activeNode->get(letter);
            deepEdge++;
        } else {
            if (activeEdge.get(deepEdge) != letter) return false;
            deepEdge++;
        }
        if (activeEdge.len() == deepEdge) {
            deepEdge = 0;
            activeNode = activeEdge.to;
        }
    }
    return true;
}
