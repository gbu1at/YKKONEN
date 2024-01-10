#pragma once
#include <bits/stdc++.h>
#include "H/Edge.h"


struct Node {
    std::map<int, Edge> children;
    Node* suffixLink;
    int rank;
    Node();
    bool find(int letter);
    Edge get(int letter);
    void createSuffixEnd(int letter, int left, std::vector<int>* t);
    void changeChild(int letter, const Edge& e);
};