#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string.h>
#include <vector>

#define ALFABETO 356

struct NoTrie
{
    struct NoTrie *filhos[ALFABETO];    
    bool EOW;
};

class Trie
{
    public:
        Trie();
        Trie(  std::vector<std::string> );
        ~Trie();

        void insere( std::string );
        bool buscaS( std::string );

        std::vector<std::string> buscaP( std::string );

    private:
        struct NoTrie *root;

        std::vector<std::string> varreTrie( struct NoTrie *, std::string );

};

#endif