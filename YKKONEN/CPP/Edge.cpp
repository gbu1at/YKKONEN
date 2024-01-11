#pragma once
#include <bits/stdc++.h>
#include "../H/Edge.h"
#include "Node.cpp"

template <typename T>
Edge<T>::Edge() {}

template <typename T>
Edge<T>::Edge(Node<T>* from, Node<T>* to, int l, int r, T* t) {
    this->to = to;
    this->from = from;
    this->l = l;
    this->r = r;
    this->t = t;
}

template <typename T>
int Edge<T>::get(int idx) {
    assert(l + idx <= r);
    return (*t)[l + idx];
}

template <typename T>
int Edge<T>::len() {
    return r - l + 1;
}


template <typename T>
Node<T>* Edge<T>::cut(int lenght) {
    assert((lenght > 0) && (l + lenght <= r));
    Node<T>* newNode = new Node<T>();
    Edge<T> upEdge = Edge<T>(from, newNode, l, l + lenght - 1, t);
    Edge<T> downEdge = Edge<T>(newNode, to, l + lenght, r, t);
    newNode->changeChild(get(lenght), downEdge);
    from->changeChild(get(0), upEdge);
    return newNode;
}

template <typename T>
int Edge<T>::firstLetter() {
    return (*t)[l];
}
