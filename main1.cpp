//#include <bits/stdc++.h>
//#include "InputTokenizer.h"
//#include "NFABuilder.h"
//#define pb push_back
//#define mp make_pair
//#define f first
//#define s second
//#define MAX_STATE 1000
//#define MAX_INPUT 250
//using namespace std;
//// representation of NFA state
//class NFA_state
//{
//    public:
//        int transitions[MAX_INPUT][MAX_STATE];
//        NFA_state()
//        {
//            for(int i=0;i<MAX_INPUT;i++)
//                for(int j=0;j<MAX_STATE;j++)
//                    transitions[i][j]=-1;
//        }
//}*NFA_states;
//// representation of DFA state
//struct DFA_state
//{
//    bool finalState;
//    string finalDFA_name;
//    bitset<MAX_STATE>NFA2DFA_states; // NFA states that is composed in one DFA state
//    bitset<MAX_STATE>transitions[MAX_INPUT]; // transition NFA states of this DFA state on input i=0,1,2, ... MAX_INPUT
//    int Transitions[MAX_INPUT];// (DFA) transition from current DFA state to -> Transitions[i] on input i where i=0,1,2, ... MAX_INPUT
//};
//
//set<int>NFA_finalStates;
//vector<int> DFA_finalStates;
//vector<DFA_state*> DFA_states;
//stack<int> unmarked_DFA_states;
//std::map<int,std::string> finalNodesA;
//std::map<std::string,int> priorities;
//int N,M,D; //no of states and input size
//
////set of NFA states reachable from NFA state "state" on epsilon transitions alone
////or closure(s) and save it in "closure"
//void epsilonClosure(int state,bitset<MAX_STATE> & closure)
//{
//    for(int i=0;i<N&&NFA_states[state].transitions[0][i]!=-1;i++)
//        if(closure[NFA_states[state].transitions[0][i]]==0)
//        {
//            closure[NFA_states[state].transitions[0][i]]=1;
//            epsilonClosure(NFA_states[state].transitions[0][i],closure);
//        }
//}
////set of NFA states reachable from some NFA state "state" in "T"
//// on epsilon transitions alone
//void epsilonClosure(bitset<MAX_STATE> T,bitset<MAX_STATE> & closure)
//{
//    for(int i=0;i<N;i++)
//        if(T[i]==1)
//            epsilonClosure(i,closure);
//}
//// returns a bitset representing the set of states the NFA could be in after moving
//// from state "from" on input symbol "input"
//void NFA_move(int from,int input,bitset<MAX_STATE> &b)
//{
//    for(int i=0;i<N&&NFA_states[from].transitions[input][i]!=-1;i++)
//        b[NFA_states[from].transitions[input][i]]=1;
//}
////set of NFA states to which there is a transition on input symbol "input" from some NFA state T[i] in T
//void NFA_move(bitset<MAX_STATE> T,int input,bitset<MAX_STATE> &b)
//{
//    for(int i=0;i<N;i++)
//        if(T[i]==1)
//        {
////            cout<<"i : "<<i<<endl;
//            NFA_move(i,input,b);
//        }
//}
//bool finalst[MAX_STATE];
//void NFA2DFA()
//{
//    D=1;
//    DFA_states.pb(new DFA_state);
//    DFA_states[0]->NFA2DFA_states[0]=1;
//    epsilonClosure(0,DFA_states[0]->NFA2DFA_states);
//    // check if the first state is an accepting one
//    int pr=10000000,indx=-1;
//    cout<<finalNodesA.size()<<" tr\n";
////    cout<<finalNodesA[0]<<" ramadan"<<endl;
//    for(int i=0;i<N;i++)
//        if(DFA_states[0]->NFA2DFA_states[i]==1&&finalNodesA.find(i)!=finalNodesA.end())
//        {
////            cout<<"h "<<i<<" "<<finalNodesA[i]<<endl;
//            if(priorities[finalNodesA[i]]<pr)
//            {
//                pr=priorities[finalNodesA[i]];
//                indx=i;
////                cout<<indx<<endl;
//            }
//        }
////    cout<<indx<<endl;
//    if(indx!=-1)
//    {
//        DFA_states[0]->finalState=true;
//        DFA_finalStates.pb(0);
//        finalst[0]=1;
//        DFA_states[0]->finalDFA_name=finalNodesA[indx];
////        cout<<DFA_states[0]->finalDFA_name<<endl;
//    }
//    unmarked_DFA_states.push(0);
//    while(!unmarked_DFA_states.empty())
//    {
//        int x=unmarked_DFA_states.top();
////        cout<<"X : "<<x<<endl;
//        unmarked_DFA_states.pop();
//        for(int i=1;i<=M;i++)
//        {
//            NFA_move(DFA_states[x]->NFA2DFA_states,i,DFA_states[x]->transitions[i]);
//            epsilonClosure(DFA_states[x]->transitions[i],DFA_states[x]->transitions[i]);
//
//
//            // check whether the state that we move to is a new DFA state or not
//            int j;
//            for(j=0;j<D;j++)
//                if(DFA_states[x]->transitions[i]==DFA_states[j]->NFA2DFA_states)
//                {
//                    DFA_states[x]->Transitions[i]=j;
//                    break;
//                }
//            if(j==D) // if not found in previous DFA states -> create new state
//            {
//                DFA_states[x]->Transitions[i]=D;
//                DFA_states.pb(new DFA_state);
//                DFA_states[D]->NFA2DFA_states=DFA_states[x]->transitions[i];
//                // check whether state D is an accepting state or not
//                int pr=10000000,indx=-1;
//                for(int j=0;j<N;j++)
//                    if(DFA_states[D]->NFA2DFA_states[j]==1&&finalNodesA.find(j)!=finalNodesA.end())
//                    {
//                        if(priorities[finalNodesA[i]]<pr)
//                        {
//                            pr=priorities[finalNodesA[i]];
//                            indx=i;
//                        }
//                    }
////                cout<<"indx : "<<indx<<endl;
//                if(indx!=-1)
//                {
//                    DFA_states[D]->finalState=true;
//                    DFA_finalStates.pb(D);
//                    finalst[D]=1;
//                    DFA_states[D]->finalDFA_name=finalNodesA[indx];
//                }
//                unmarked_DFA_states.push(D);
//                D++;
//            }
//        }
//    }
//}
//
//void test()
//{
//    // read NFA
//    cin>>N;
//    M=10;
//    NFA_states=new NFA_state[N+10];
//    int f;
//    cin>>f;
//    for(int i=0;i<f;i++)
//    {
//        int x;
//        cin>>x;
//        NFA_finalStates.insert(x);
//    }
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int from,input,n,to;
//        cin>>from>>input>>n;
//        for(int i=0;i<n;i++)
//        {
//            cin>>to;
//            NFA_states[from].transitions[input][i]=to;
//        }
//    }
//    NFA2DFA();
//    // write DFA
//    cout<<D<<" "<<M<<endl<<DFA_finalStates.size();
//    for(auto it=DFA_finalStates.begin();it!=DFA_finalStates.end();it++)
//        cout<<" "<<*it;
//    cout<<endl;
//    for(int i=0;i<D;i++)
//        for(int j=1;j<=M;j++)
//            cout<<i<<" "<<j<<" "<<DFA_states[i]->Transitions[j]<<endl;
//}
//bool minTable[MAX_STATE][MAX_STATE],temp[MAX_STATE][MAX_STATE];
//bool changed()
//{
//    bool f=false;
//    for(int i=0;i<D;i++)
//        for(int j=i+1;j<D;j++)
//        {
//            if(temp[i][j]!=minTable[i][j])
//                f=true;
//            temp[i][j]=minTable[i][j];
//        }
//    return f;
//}
//bool visited[MAX_STATE]; //boolean array for visited states
//int component[MAX_STATE]; // no of component that state i belongs to
//vector<int> nodes[MAX_STATE];
//void dfs(int cmp,int node)// connected component from 2D array (graph)
//{
//    visited[node]=true;
//    component[node]=cmp;
//    nodes[cmp].pb(node);
//    for(int i=0;i<D;i++)
//    {
//        if(i!=node&&!visited[i]&&minTable[node][i]==0)
//        {
//            int flag=0;
//            for(int j=0;j<nodes[cmp].size();j++)
//            {
////                cout<<i<<" "<<j<<endl;
//                if(minTable[i][nodes[cmp][j]]||minTable[nodes[cmp][j]][i])
//                {
//                    flag=1;
////                    cout<<"here"<<endl;
//                    break;
//                }
//            }
//            if(!flag)
//            {
////                cout<<cmp<<" "<<i<<" r"<<endl;
//                dfs(cmp,i);
//            }
//        }
//    }
//}
//int cmp=0;
//void minimize()
//{
//    // accepting states can't be grouped with non-accepting states
////    for(int i=0;i<D;i++)
////        cout<<finalst[i]<<" ";
////    cout<<endl;
//    for(int i=0;i<D;i++)
//        for(int j=i+1;j<D;j++)
//        {
//            if(finalst[i]!=finalst[j])
//            {
////                cout<<"here "<<i<<" "<<j<<endl;
//                minTable[i][j]=minTable[j][i]=1,temp[i][j]=temp[j][i]=1;
//            }
//        }
//    do
//    {
//        //test for each input and for all 2 states if it can be merged or not
//        for(int i=0;i<D;i++)
//            for(int j=i+1;j<D;j++)
//            {
//                if(!minTable[i][j])
//                {
//                    for(int k=1;k<=M;k++)
//                        {
//                            int t_i=DFA_states[i]->Transitions[k];
//                            int t_j=DFA_states[j]->Transitions[k];
//                            if(minTable[t_i][t_j])
//                                minTable[i][j]=minTable[j][i]=1;
//                        }
//                }
//            }
//    }while(changed());// stop when the table not changed
//    for(int i=0;i<D;i++)minTable[i][i]=1;
//    for(int i=0;i<D;i++)
//    {
//        if(!visited[i])
//        {
//            component[i]=cmp;
//            visited[i]=true;
//            dfs(cmp++,i);
//        }
//    }
//
//}
//void graphToNFA(vector<vector<pair<int,char> > > *g,std::map<int,std::string> finalNodesA)// change from one representation of the graph to another one
//{
//    N=g->size();
//    NFA_states=new NFA_state[N+10];
////    int f=finalNodesA.size();
////    for(auto it=finalNodesA.begin();it!=finalNodesA.end();it++)
////        NFA_finalStates.insert(*it);
//    for(int i=0;i<N;i++)
//    {
////        cout<<"here "<<(*g)[i].size()<<endl;
//        for(int j=0;j<(*g)[i].size();j++)
//        {
//            int from =i,input=(*g)[i][j].s,to=(*g)[i][j].f;
////            cout<<from<<" "<<to<<" "<<input<<" t"<<endl;
//            for(int k=0;k<MAX_STATE;k++)
//            {
//                if(NFA_states[from].transitions[input][k]==to)break;
////                cout<<NFA_states[from].transitions[input][k]<<" h"<<endl;
//                if(NFA_states[from].transitions[input][k]==-1)
//                {
////                    cout<<from<<" "<<to<<" "<<input<<" "<<k<<" t"<<endl;
//                    NFA_states[from].transitions[input][k]=to;
//                    break;
//                }
//            }
//        }
//    }
//    cout<<endl;
//}
//set<int>minimized_final;
//int main()
//{
////    test();
////    minimize();
////    for(int i=0;i<D;i++,cout<<endl)
////        for(int j=0;j<D;j++)
////            cout<<minTable[i][j]<<" ";
////    for(int i=0;i<D;i++)
////        cout<<component[i]<<" ";
//    InputTokenizer inpTok;
//    inpTok.parseFile("input.txt");
//    inpTok.printContents();
//    NFABuilder nfaBuilder (inpTok);
////    nfaBuilder.build();
////    nfaBuilder.test();
//    graphToNFA(nfaBuilder.buildFinal(),nfaBuilder.finalNodesA);
//    finalNodesA=nfaBuilder.finalNodesA;
////    cout<<finalNodesA.size()<<" tr\n";
//
//    priorities=nfaBuilder.priorities;
//    M=128;
//    NFA2DFA();
//    // write DFA
//    cout<<D<<" hhh "<<M<<endl<<DFA_finalStates.size()<<endl;
////    for(int i=0;i<D;i++,cout<<endl)
////    {
////        cout<<"i : "<<i<<endl;
////        for(int j=0;j<MAX_STATE;j++)
////        {
////            if(DFA_states[i]->NFA2DFA_states[j])
////            {
////                cout<<j<<" ";
////            }
////        }
////    }
////    for(auto it=DFA_finalStates.begin();it!=DFA_finalStates.end();it++)
////        cout<<" "<<*it;
////    cout<<endl;
////    for(int i=0;i<D;i++)
////        for(int j=1;j<=M;j++)
////            cout<<i<<" "<<j<<" "<<DFA_states[i]->Transitions[j]<<endl;
//
//
//    minimize();
////    for(int i=0;i<D;i++,cout<<endl)
////        for(int j=0;j<D;j++)
////        {
////            if(minTable[i][j])
////                cout<<i<<" "<<j<<endl;
////        }
////    for(int i=0;i<D;i++)
////        cout<<component[i]<<" ";
//    cout<<cmp<<endl;
//    for(int i=0;i<cmp;i++)
//    {
//        cout<<"component : "<<i<<endl;
//        for(int j=0;j<nodes[i].size();j++)
//        {
//            cout<<nodes[i][j]<<" ";
//        }
//        cout<<endl;
//    }
////    for(int i=0;i<nodes[6].size();i++)
////    {
////        for(int j=i+1;j<nodes[6].size();j++)
////        {
////            if(minTable[nodes[6][i]][nodes[6][j]])
////            {
////                cout<<"a7a ";
////            }
////        }
////    }
////    cout<<endl;
//    for(int i=0;i<DFA_finalStates.size();i++)
//    {
//        minimized_final.insert(component[DFA_finalStates[i]]);
//    }
//    cout<<minimized_final.size()<<endl;
//
//    return 0;
//}
///*
//11
//1 10
//10
//0 0 2 1 7
//1 0 2 2 4
//2 1 1 3
//3 0 1 6
//4 2 1 5
//5 0 1 6
//6 0 2 1 7
//7 1 1 8
//8 2 1 9
//9 2 1 10
//
//5 2
//0
//0 1 1
//0 2 2
//1 1 1
//1 2 3
//2 1 1
//2 2 2
//3 1 1
//3 2 4
//4 1 1
//4 2 2
//*/
//
//
///*
//4 2
//2 0 1
//4
//0 1 2 1 2
//1 1 2 1 2
//2 2 2 1 3
//3 1 2 1 2
//
//4 2
//3 0 1 3
//0 1 1
//0 2 2
//1 1 1
//1 2 3
//2 1 2
//2 2 2
//3 1 1
//3 2 2
//*/
//
//
///*
//10 2
//1 9
//9
//0 0 2 1 4
//1 1 1 2
//2 2 1 3
//3 0 1 9
//4 1 1 5
//5 0 2 4 6
//6 2 1 7
//7 0 2 6 8
//8 0 1 9
//*/
