#include <bits/stdc++.h>
#include "NodeBor.h"

bool NodeBor::findChild(int value) {
    return (children.find(value) != children.end());
}

NodeBor* NodeBor::get(int value) {
    assert(findChild(value));
    return children[value];
}

NodeBor* NodeBor::createChild(int value) {
    NodeBor* newNode = new NodeBor();
    children[value] = newNode;
    return newNode;
}