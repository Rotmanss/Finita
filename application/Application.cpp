#include "NFA.h"


int main()
{
    State* start = new State();
    State* s1 = new State();
    State* s2 = new State(true);
    State* s3 = new State(true);
    State* s4 = new State(true);

    NFA automat = NFA();

    automat.addTransition(start, s1, 'a');
    automat.addTransition(s1, s2, 'b');
    automat.addTransition(s2, s1, 'a');
    automat.addTransition(s2, s3, 'c');
    automat.addTransition(s3, s3, 'c');
    automat.addTransition(start, s4, 'd');
    automat.addTransition(s4, s4, 'd');

    std::cout << automat.accepts(start, "ab") << std::endl;
    std::cout << automat.accepts(start, "ababab") << std::endl;
    std::cout << automat.accepts(start, "abc") << std::endl;
    std::cout << automat.accepts(start, "ac") << std::endl;
    std::cout << automat.accepts(start, "a") << std::endl;
    std::cout << automat.accepts(start, "b") << std::endl;
    std::cout << automat.accepts(start, "c") << std::endl;
    std::cout << automat.accepts(start, "ddd") << std::endl;

    delete s4;
    delete s3;
    delete s2;
    delete s1;
    delete start;

    return 0;
}