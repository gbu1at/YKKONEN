#pragma once
#include <bits/stdc++.h>
#include "Edge.h"
#include "Node.h"


Edge::Edge() {}

Edge::Edge(Node* from, Node* to, int l, int r, std::vector<int>* t) {
    this->to = to;
    this->from = from;
    this->l = l;
    this->r = r;
    this->t = t;
}

int Edge::get(int idx) {
    assert(l + idx <= r);
    return (*t)[l + idx];
}

int Edge::len() {
    return r - l + 1;
}

Node* Edge::cut(int lenght) {
    assert((lenght > 0) && (l + lenght >= r));
    Node* newNode = new Node();
    Edge upEdge = Edge(from, newNode, l, l + lenght - 1, t);
    Edge downEdge = Edge(newNode, to, l + lenght, r, t);
    newNode->changeChild(get(lenght - 1), downEdge);
    from->changeChild(get(l), upEdge);
    return newNode;
}

int Edge::firstLetter() {
    return (*t)[l];
}
