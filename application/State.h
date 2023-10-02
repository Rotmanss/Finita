#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

struct State {
    std::unordered_map<char, std::vector<State*>> transitions;
    bool isFinal;

    State(bool isFinal = false)
        : isFinal(isFinal)
    {
    }
};
