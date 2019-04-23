/**
 * @file sstring.hpp
 * @brief Lib com funções para trabalhar com strings e radix tree
 * 
 * @warning Lib feita em c++14
 * @todo Verificar o código e debugar, terminar de implementar
 * @bug Ainda não compilando e debugado
 * @copyright © Pedro Augusto Campos Dos Santos -- 2018.
*/

#pragma once

#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>

//http://www.cplusplus.com/reference/algorithm/
//http://www.cplusplus.com/reference/cstring/strchr/

using namespace std;

int stringDiff(string a, string b){
    /**
     * @brief Calculate the pos to diff between them
     * @param string a - WORD A
     * @param string b - WORD B
     * @return Position to difference between them
     * @note E.G. (Cadeado,Cadeira) -> return 4;
     */
    int pos = -1, stop=min_element(a.size(),b.size());
    for(int i=0; i<stop; i++){
        if(a[i]!=b[i])
            return pos;
        pos=i;
    }
    return pos;
}
bool stringCmp(string a, string b){
    /**
     * @brief Order function that verifies if (c < ca) or (cA < cO)
     * @param string a - Word A
     * @param string b - Word B
     * @return Comparation (c<ca) or [(cA<cO) or (cA=cA)]
     */
    int aux=stringDiff(a,b);
    if(a.size()<b.size() || a.size()>b.size())
        return (a.size()<b.size());
    else
        return a[aux]<=b[aux];
}
string stringTrunc(string& a, string& b){
    /**
     * @brief Trunc two functions, modifies b
     * @param string a - base string
     * @param string b - string with same preffix
     * @return The difference for the first string
     * @note E.G. (Cadeira,Cadeado) --> (Cade, ado) and return eira
     */
    int pos = stringDiff(a,b);
    
    string aux;
    copy(a.begin()+pos, a.end(), aux);
    
    a.erase(a.begin()+pos,a.end());
    b.erase(b.begin(),b.begin()+pos);

    return aux;
}

class Node{
private:
    string nword;
    Node* left,*right;
public:
    Node(){left=right=nullptr;}
    Node(string _nword){nword=_nword;left=right=nullptr;}
    ~Node(){}
};


class radixTree:Node{
private:
    Node* header;
public:
    radixTree(){header==nullptr;}

    void insert(string nword){
        if(header==nullptr)
            header=new Node(nword);
        else{
            Node *lnode, *rnode;
            lnode=header.left;
            rnode=header.right;
            
            string auxword;
            int sDiff=stringDiff(header.nword, nword);
            copy(nword.begin()+sDiff, nword.end(), auxword);
            
            if(lnode==nullptr) lnode=new Node(auxword);

            
        }

        auto it = find(header.begin(),header.end(), nword);
        if(it == header.end())
            header.push_back(nword);
        else{
            int aux = stringDiff(*it, nword);

        }
    }
};