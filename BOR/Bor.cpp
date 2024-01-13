#pragma once
#include <bits/stdc++.h>
#include "Bor.h"
#include "NodeBor.cpp"


void Bor::add(const std::string& _data_) {
    NodeBor* active = root;
    for (int i = 0; i < _data_.size(); ++i) {
        if (active->findChild(_data_[i])) active = active->get(_data_[i]);
        else active = active->createChild(_data_[i]);
    }
    active->stop = true;
}

std::string Bor::generator(int start, const std::string& _data_) {
    std::string result;
    NodeBor* active = root;
    for (int i = start; i < _data_.size(); ++i) {
        assert(active->findChild(_data_[i]));
        active = active->get(_data_[i]);
        result.push_back(_data_[i]);
        if (active->stop) break;
    }
    return result;
}
