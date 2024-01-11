#pragma once
#include <bits/stdc++.h>
#include "Node.h"
struct Node;

struct Edge {
    Node* to;
    Node* from;
    int l; int r;
    std::vector<int>* t;
    Edge();
    Edge(Node* from, Node* to, int l, int r, std::vector<int>* t);
    int get(int idx);
    int len();
    Node* cut(int lenght);
    int firstLetter();
};