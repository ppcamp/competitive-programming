#include "trie.h"

struct NoTrie *nullNo(void)
{
    struct NoTrie *null = new NoTrie;

    null->EOW = false;

    memset(null->filhos, 0, sizeof(null->filhos) );

    return null;
}


Trie::Trie()
    :root(nullNo())
{
}

Trie::Trie(  std::vector<std::string> keys)
    :root(nullNo())
{
    double size = keys.size(), processed = 0;

    printf("included: 0.0000%c\n",(char)37);
    for (int i=0; i<size; i++)
    {
        insere(keys[i]);
        printf("included: %3.4f%c\n", ((++processed)/size)*100,(char)37 );
    }
}

Trie::~Trie()
{
}

void Trie::insere( std::string k)
{
    struct NoTrie *aux = this->root;

    for(auto i:k)
    {
        int id = (int)i+100;
        
        if(!aux->filhos[id])
            aux->filhos[id] = nullNo();
        
        aux = aux->filhos[id];
    }

    aux->EOW = true;
}

bool Trie::buscaS( std::string k)
{
    struct NoTrie *aux = this->root;

    for (auto i:k)
    {
        int id = (int)i+100;
        
        if (!aux->filhos[id])
            return false;
        
        aux = aux->filhos[id];
    }
 
    return ( (aux != NULL && aux->EOW)? true : false );
}

std::vector<std::string> Trie::buscaP( std::string k)
{
    struct NoTrie *aux = this->root;

    for (auto i:k)
    {
        int id = (int)i+100;

        if (!aux->filhos[id])
            return std::vector<std::string>();

        aux = aux->filhos[id];
    }
    
    return ( (aux==NULL)? std::vector<std::string>() : varreTrie(aux, k) );
}

std::vector<std::string> Trie::varreTrie(struct NoTrie *root, std::string k)
{
    std::vector<std::string>aux, saida;

    if(root->EOW)
        saida.push_back(k);
    
    for(int i=0; i<ALFABETO ; i++)
    {
        if(root->filhos[i])
        {
            aux = varreTrie(root->filhos[i], k+(char)(i-100));

            if(aux!=std::vector<std::string>())
                saida.insert(saida.end(), aux.begin(), aux.end());
        }
    }

    return saida;
}