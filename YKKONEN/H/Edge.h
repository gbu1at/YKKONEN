#pragma once
#include <bits/stdc++.h>
#include "Node.h"

template <typename T>
struct Node;

template <typename T>
struct Edge {
    Node<T>* to;
    Node<T>* from;
    int l; int r;
    T* t;
    Edge();
    Edge(Node<T>* from, Node<T>* to, int l, int r, T* t);
    int get(int idx);
    int len();
    Node<T>* cut(int lenght);
    int firstLetter();
};