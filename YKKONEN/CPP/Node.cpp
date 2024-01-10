#pragma once
#include <bits/stdc++.h>
#include "H/Edge.h"
#include "H/Node.h"


Node::Node() {

}

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
}

void Node::changeChild(int letter, const Edge& e) {
    children[letter] = e;
}
