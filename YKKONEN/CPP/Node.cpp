#pragma once
#include <bits/stdc++.h>
#include "Edge.cpp"


bool Node::find(int letter) {
    return (children.find(letter) != children.end());
}

Edge Node::get(int letter) {
    assert(find(letter));
    return children[letter];
}

void Node::createSuffixEnd(int letter, int left, std::vector<int>* t) {
    Node* newNode = new Node();
    Edge newEdge = Edge(this, newNode, left, (*t).size() - 1, t);
    children[letter] = newEdge;
}

void Node::changeChild(int letter, const Edge& e) {
    children[letter] = e;
}
