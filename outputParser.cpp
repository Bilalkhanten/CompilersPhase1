#include "outputParser.h"
#include <fstream>
#include <iostream>
using namespace std;

outputParser::outputParser(aGraph * g1, std::map<int,std::string> * fs)
{
    g = g1;
    finalStates = fs;
}
void outputParser::match(char * path)
{
    ifstream inFile (path);
    string line;
    while(inFile >> line){
        int node = 0, lastMatched = -1, lastInd = -1,ind = 0;
        while(node < g->size() )
        {
            if(ind == line.size())
            {
                //reached end of string
                if(lastMatched == -1 && lastInd != ind-1)
                {
                    //if could not match end of string
                    cout<<"error: end of string coultdn't be matched"<<endl;
                    return;
                }
                else if(lastInd == ind -1)
                {
                    //if no more characters to parse
                    return;
                }
                else
                {
                    //return to the last final state
                    cout<<(*finalStates)[lastMatched]<<endl;
                    lastMatched = -1;
                    ind = lastInd+1;
                    node = 0;
                }
            }
            int toNode = findEdge(node,line[ind]);
            if(toNode == -1)
            {
                if(lastMatched == -1)
                {
                    cout<<"error"<<endl;
                    return;
                }
                //no transition matching this state
                cout<<(*finalStates)[lastMatched]<<endl;
                lastMatched = -1;
                ind = lastInd+1;
                node = 0;
            }
            else if(finalStates->find(toNode) != finalStates->end())
            {
                lastMatched = toNode;
                lastInd = ind;
                node = toNode;
                ind++;
            }
            else
            {
                node = toNode;
                ind++;
            }
        }
    }
}
int outputParser::findEdge(int node, char ch)
{
    for(int i = 0;  i < (*g)[node].size(); i++)
    {
        if((*g)[node][i].second == ch)
        {
            return (*g)[node][i].first;
        }
    }
    return -1;
}
outputParser::~outputParser()
{
    //dtor
}
