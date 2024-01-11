#pragma once
#include <bits/stdc++.h>
#include "Edge.cpp"


template <typename T>
bool Node<T>::find(int letter) {
    return (children.find(letter) != children.end());
}

template <typename T>
Edge<T> Node<T>::get(int letter) {
    assert(find(letter));
    return children[letter];
}

template <typename T>
void Node<T>::createSuffixEnd(int letter, int left, T* t) {
    Node* newNode = new Node();
    Edge newEdge = Edge(this, newNode, left, (*t).size() - 1, t);
    children[letter] = newEdge;
}

template <typename T>
void Node<T>::changeChild(int letter, const Edge<T>& e) {
    children[letter] = e;
}
