//#include <bits/stdc++.h>
//
//#include "InputTokenizer.h"
//#include "NFABuilder.h"
//#include "NFA2DFA.h"
//
//#define pb push_back
//#define mp make_pair
//#define f first
//#define s second
//
//#define MAX_STATE 1000
//#define MAX_INPUT 250
//using namespace std;
//int N,M,D; //no of states and input size
//bool finalst[MAX_STATE]; // boolean to flag final NFA states
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
//
//void NFA2DFA()
//{
//    D=1;
//    //node 0 in NFA is the start node in the DFA states
//    DFA_states.pb(new DFA_state);
//    DFA_states[0]->NFA2DFA_states[0]=1;
//    epsilonClosure(0,DFA_states[0]->NFA2DFA_states);// all nodes in the epsilon closure of the start node are included in the first DFA state
//    // check if the first state is an accepting one
//    int pr=10000000,indx=-1;
//    for(int i=0;i<N+10;i++)
//        if(DFA_states[0]->NFA2DFA_states[i]==1&&finalNodesA.find(i)!=finalNodesA.end())// if any NFA node in the composed DFA first state is an accepting state
//        {
//            //find the most priority final state
//            if(priorities[finalNodesA[i]]<pr)
//            {
//                pr=priorities[finalNodesA[i]];
//                indx=i;
//            }
//        }
//    // if the first DFA state contains NFA final states, set this DFA state to be a final one
//    if(indx!=-1)
//    {
//        DFA_states[0]->finalState=true;
//        DFA_finalStates.pb(0);
//        finalst[0]=1;
//        DFA_states[0]->finalDFA_name=finalNodesA[indx];
//        DFA_states[0]->prio=pr;
//    }
//    unmarked_DFA_states.push(0);
//    while(!unmarked_DFA_states.empty())
//    {
//        int x=unmarked_DFA_states.top();
//        unmarked_DFA_states.pop();
//        //for all possiple input except the epsilon
//        for(int i=1;i<=M;i++)
//        {
//            //move state "x" to input i and store the result in DFA_states[x]->transitions[i]
//            NFA_move(DFA_states[x]->NFA2DFA_states,i,DFA_states[x]->transitions[i]);
//            //combine each state with its epsilon closure
//            epsilonClosure(DFA_states[x]->transitions[i],DFA_states[x]->transitions[i]);
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
//                for(int k=0;k<N+10;k++)
//                    if(DFA_states[D]->NFA2DFA_states[k]==1&&finalNodesA.find(k)!=finalNodesA.end())
//                    {
//                        if(priorities[finalNodesA[k]]<pr)
//                        {
//                            pr=priorities[finalNodesA[k]];
//                            indx=k;
//                        }
//                    }
//                if(indx!=-1)
//                {
//                    DFA_states[D]->finalState=true;
//                    DFA_finalStates.pb(D);
//                    finalst[D]=1;
//                    DFA_states[D]->finalDFA_name=finalNodesA[indx];
//                    DFA_states[D]->prio=pr;
//                }
//                unmarked_DFA_states.push(D);
//                D++;
//            }
//        }
//    }
//}
//
//
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
//                if(minTable[i][nodes[cmp][j]]||minTable[nodes[cmp][j]][i])
//                {
//                    flag=1;
//                    break;
//                }
//            }
//            if(!flag)
//                dfs(cmp,i);
//        }
//    }
//}
//int cmp=0;
//void minimize()
//{
//    // accepting states can't be grouped with non-accepting states
//    for(int i=0;i<D;i++)
//        for(int j=0;j<D;j++)
//        {
//            if(finalst[i]!=finalst[j])
//            {
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
////    for(int i=0;i<D;i++)minTable[i][i]=1;
//    for(int i=0;i<D;i++)
//        if(!visited[i])
//            dfs(cmp++,i);
//}
//// change from one representation of the graph to another one
//void graphToNFA(vector<vector<pair<int,char> > > *g,std::map<int,std::string> finalNodesA)
//{
//    N=g->size();
//    NFA_states=new NFA_state[N+10];
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<(*g)[i].size();j++)
//        {
//            int from =i,input=(*g)[i][j].s,to=(*g)[i][j].f;
//            for(int k=0;k<MAX_STATE;k++)
//            {
//                if(NFA_states[from].transitions[input][k]==to)break;
//                if(NFA_states[from].transitions[input][k]==-1)
//                {
//                    NFA_states[from].transitions[input][k]=to;
//                    break;
//                }
//            }
//        }
//    }
//}
//set<int>minimized_final;
//vector<pair<int,pair<string,int> > >Minimized_accepted_names_prio;//node name priority
//int main()
//{
//    InputTokenizer inpTok;
//    inpTok.parseFile("input.txt");
//    inpTok.printContents();
//    NFABuilder nfaBuilder (inpTok);
//    graphToNFA(nfaBuilder.buildFinal(),nfaBuilder.finalNodesA);
//    finalNodesA=nfaBuilder.finalNodesA;
//    priorities=nfaBuilder.priorities;
//    M=128;
//    NFA2DFA();
//    cout<<D<<" hhh "<<M<<endl;
////    for(int i=0;i<DFA_finalStates.size();i++)
////        cout<<DFA_states[DFA_finalStates[i]]->finalDFA_name<<endl;
//    minimize();
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
//    cout<<"DFA final states size = "<<DFA_finalStates.size()<<endl;
//    for(int i=0;i<cmp;i++)
//    {
//        int pr=10000000;
//        string s="";
//        for(int j=0;j<nodes[i].size();j++)
//        {
//            if(find(DFA_finalStates.begin(),DFA_finalStates.end(),nodes[i][j])!=DFA_finalStates.end() && DFA_states[nodes[i][j]]->prio < pr )
//            {
//                pr=DFA_states[nodes[i][j]]->prio;
//                s =DFA_states[nodes[i][j]]->finalDFA_name;
//            }
//        }
//        if(pr!=10000000)
//        {
//            cout<<pr<<" "<<s<<endl;
//            Minimized_accepted_names_prio.pb(mp(i,mp(s,pr)));
//        }
//    }
////    for(int i=0;i<DFA_finalStates.size();i++)
////    {
////        if(minimized_final.find(component[DFA_finalStates[i]])==minimized_final.end())
////        {
//////            cout<<"i : "<<DFA_finalStates[i]<<" "<<DFA_states[DFA_finalStates[i]]->finalState<<endl;
////            minimized_final.insert(component[DFA_finalStates[i]]);
////            Minimized_accepted_names_prio.pb(mp(component[DFA_finalStates[i]],mp(DFA_states[DFA_finalStates[i]]->finalDFA_name,DFA_states[DFA_finalStates[i]]->prio)));
////        }
////    }
//    cout<<"minimized final states size = "<<Minimized_accepted_names_prio.size()<<endl;
//    for(auto it=Minimized_accepted_names_prio.begin();it!=Minimized_accepted_names_prio.end();it++)
//        cout<<(*it).f<<" "<<(*it).s.f<<" "<<(*it).s.s<<endl;
//
//
//    return 0;
//}
//
//
////void test()
////{
////    // read NFA
////    cin>>N;
////    M=10;
////    NFA_states=new NFA_state[N+10];
////    int f;
////    cin>>f;
////    for(int i=0;i<f;i++)
////    {
////        int x;
////        cin>>x;
////        NFA_finalStates.insert(x);
////    }
////    int t;
////    cin>>t;
////    while(t--)
////    {
////        int from,input,n,to;
////        cin>>from>>input>>n;
////        for(int i=0;i<n;i++)
////        {
////            cin>>to;
////            NFA_states[from].transitions[input][i]=to;
////        }
////    }
////    NFA2DFA();
////    // write DFA
////    cout<<D<<" "<<M<<endl<<DFA_finalStates.size();
////    for(auto it=DFA_finalStates.begin();it!=DFA_finalStates.end();it++)
////        cout<<" "<<*it;
////    cout<<endl;
////    for(int i=0;i<D;i++)
////        for(int j=1;j<=M;j++)
////            cout<<i<<" "<<j<<" "<<DFA_states[i]->Transitions[j]<<endl;
////}
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
