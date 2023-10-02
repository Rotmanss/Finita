#include "NFA.h"


void NFA::addTransition(State* from, State* to, char input)
{
    from->transitions[input].push_back(to);
}


bool NFA::accepts(State* start, std::string input) const
{
    std::vector<State*> currentStates = { start };
    for (char symbol : input)
    {
        std::vector<State*> nextStates;
        for (State* state : currentStates)
        {
            auto it = state->transitions.find(symbol);
            if (it != state->transitions.end())
                nextStates.insert(nextStates.end(), it->second.begin(), it->second.end());
        }
        currentStates = nextStates;
    }

    for (State* state : currentStates)
    {
        if (state->isFinal)
            return true;
    }

    return false;
}
