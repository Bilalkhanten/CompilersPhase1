//#include <iostream>
//#include <fstream>
//#include "InputTokenizer.h"
//#include "NFABuilder.h"
//#include "outputParser.h"
//#include "DFABuilder.h"
//
//using namespace std;
//
//void testParser();
//void printGraphFile(char * outFile, aGraph * g1);
//void printGraphFile2(char * outFile, aGraph * g1, std::map<int,std::string> mp);
//void printGraphFile3(char * outFile, aGraph * g1, std::map<int,std::string> mp);
//void printFinalFile(char * outFile, std::map<int,std::string> finalNodesA);
//
//int main()
//{
//    InputTokenizer inpTok;
//    inpTok.parseFile("input.txt");
//    inpTok.printContents();
//    NFABuilder nfaBuilder (inpTok);
////    nfaBuilder.build();
////    nfaBuilder.test();
//    aGraph * g1 = nfaBuilder.buildFinal();
////    printGraphFile("output.txt",g1);
//    printGraphFile2("json.txt",g1,nfaBuilder.finalNodesA);
////    printFinalFile("final.txt",nfaBuilder.finalNodesA);
////    testParser();
//
//    DFABuilder dfaBuilder (&nfaBuilder);
//    cout << "Hello world! AHLAAAN" << endl;
//    return 0;
//}
//
//void testParser()
//{
////    outputParser op;
//}
//void printGraphFile(char * outFile, aGraph * g1)
//{
//    ofstream of (outFile);
//    of <<g1->size()<<endl;
//    for(int i =0 ; i < g1->size() ;i++)
//    {
//        for (int j = 0 ; j < (*g1)[i].size() ; j++ )
//        {
//            char x = (*g1)[i][j].second;
//            if(x == 0)
//            {
//                x = 5;
//            }
//            of<<i << " " << (*g1)[i][j].first << " "<<(char)x <<endl;
//        }
//
//    }
//}
//
//void printGraphFile2(char * outFile, aGraph * g1, std::map<int,std::string> mp)
//{
//    ofstream of (outFile);
//    of<<"{"<<endl;
//    for(int i =0 ; i < g1->size() ;i++)
//    {
//        if(i ==0)
//            of<<"\""<<i<<"\" : {";
//        else
//            of<<",\n\""<<i<<"\" : {";
//        for (int j = 0 ; j < (*g1)[i].size() ; j++ )
//        {
//            char x = (*g1)[i][j].second;
//            if(x == 0)
//            {
//                of<<(j==0?"":", ")<<"\"\" : "<< (*g1)[i][j].first ;
//
//            }else{
//                of<< (j==0?"":", ")<<"\"" <<(char)x <<"\" : "<< (*g1)[i][j].first ;
//            }
//        }
//        if(mp.find(i) != mp.end())
//        {
//            of<<((*g1)[i].size() > 0? ",":"")<<"\"ACCEPT\" : \""<<mp[i]<<"\"";
//        }
//        of<<"}";
//
//    }
//    of<<"\n}"<<endl;
//}
//
//void printGraphFile3(char * outFile, aGraph * g1, std::map<int,std::string> mp)
//{
//    ofstream of (outFile);
//    of<<"{"<<endl;
//    of<<"\"states\":[\n";
//    for(int i = 0 ; i < g1->size() ; i++)
//    {
//        if(i >0)
//        {
//            cout<<"\""<<i<<"\"";
//        }else
//        {
//            cout<<","<<endl<<"\""<<i<<"\""<<endl;
//        }
//    }
//    cout<<"],"<<endl;
//    cout<<"\"transitions\": ["<<endl;
//    for(int i =0 ; i < g1->size() ;i++)
//    {
//        for (int j = 0 ; j < (*g1)[i].size() ; j++ )
//        {
//            cout<<"{\"symbol\": ";
//            char x = (*g1)[i][j].second;
//            if(x == 0)
//            {
//                of<<(j==0?"":", ")<<"\"\" : "<< (*g1)[i][j].first ;
//
//            }else{
//                of<< (j==0?"":", ")<<"\"" <<(char)x <<"\" : "<< (*g1)[i][j].first ;
//            }
//        }
//    }
//    of<<"\n}"<<endl;
//}
//
//void printFinalFile(char * outFile, std::map<int,std::string> mp)
//{
//    ofstream of (outFile);
//    of << mp.size();
//    for( std::map<int,std::string>::iterator it = mp.begin() ; it != mp.end() ; it++)
//    {
//        of << it->first << " " << it->second <<endl;
//    }
//}
