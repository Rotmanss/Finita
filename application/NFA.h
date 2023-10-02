#pragma once

#include "State.h"


class NFA
{
public:
    bool accepts(State* start, std::string input) const;
    void addTransition(State* from, State* to, char input);

    NFA()
    {
    }
private:

};
