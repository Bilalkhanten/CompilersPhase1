#include <iostream>
#include "NFABuilder.h"



int main()
{
    InputTokenizer inpTok;
    inpTok.parseFile("input.txt");

    NFABuilder nfa(inpTok);
    nfa.test();
    return 0;
}
