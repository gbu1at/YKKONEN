#pragma once
#include <bits/stdc++.h>


struct Tree {
    std::vector<std::pair<int, int>> tree;
    std::vector<int> sz;
    int size;
    Tree(int n);
    void set(int s, int d, int idx);
    void set(int s, int d, int l, int r);
    void set(int lx, int rx, int x, int l, int r, std::vector<int>& a);
    void push(int x, int lx, int rx);
    std::pair<int, int> get(int idx);
};
