#pragma once
#include <bits/stdc++.h>
#include "Edge.h"
struct Edge;

struct Node {
    std::map<int, Edge> children;
    Node* suffixLink;
    bool find(int letter);
    Edge get(int letter);
    void createSuffixEnd(int letter, int left, std::vector<int>* t);
    void changeChild(int letter, const Edge& e);

};