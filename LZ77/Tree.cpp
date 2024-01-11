#pragma once
#include <bits/stdc++.h>
#include "Tree.h"


Tree::Tree(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size - 1, {0, -1});
    sz.assign(2 * size - 1, 1);
    for (int i = size - 2; i>= 0; --i)
        sz[i] = sz[2 * i + 1] + sz[2 * i + 2];
}

void Tree::set(int s, int d, int idx) {
    idx += size - 1;
    tree[idx] = {s, d};
}

void Tree::set(int s, int d, int l, int r) {
    l += size - 1;
    r += size - 1;
    std::vector<int> a;
    set(size - 1, 2 * size - 1, 0, l, r, a);
    int S = 0;
    for (int x : a) {
        tree[x] = {s, d};
        s += sz[x];
        d -= sz[x];
    }
}

void Tree::set(int lx, int rx, int x, int l, int r, std::vector<int>& a) {
    push(x, lx, rx);
    if (lx >= r || l >= rx) return;
    if (l <= lx && rx <= r) {
        a.push_back(x);
        return;
    }
    int m = (lx + rx) / 2;
    set(lx, m, 2 * x + 1, l, r, a);
    set(m, rx, 2 * x + 2, l, r, a);
}

void Tree::push(int x, int lx, int rx) {
    if (lx == rx - 1) return;
    auto[s, d] = tree[x];
    if (d != -1) {
        tree[2 * x + 1] = {s, d};
        tree[2 * x + 2] = {s + (rx - lx) / 2, d - (rx - lx) / 2};
        tree[x] = {s, -1};
    }
}

std::pair<int, int> Tree::get(int idx) {
    idx += size - 1;
    int l = size - 1, r = 2 * size - 1;
    int x = 0;
    while (l < r - 1) {
        push(x, l, r);
        int m = (l + r) / 2;
        if (idx < m) {
            x = 2 * x + 1;
            r = m;
        } else {
            x = 2 * x + 2;
            l = m;
        }
    }
    return tree[x];
}
