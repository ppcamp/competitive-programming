#include <iostream>
#define PESO_MAX 15
#define QUANT_ITENS 5

using namespace std;

int mochila_repeat(int* pesos, int* valores)
{
    // Valor máximo alcançavel por uma mochila de w quilos
    int k[PESO_MAX + 1];

    // Inicializa pesos
    for(int i = 0; i < PESO_MAX+1; i++)
        k[i] = 0;

    // Verifica para cada peso
    for(int w = 1; w < PESO_MAX+1; w++)
    {
        for(int j = 0; j < QUANT_ITENS; j++)
        {
            if(pesos[j] <= w)
            {
                if(k[w - pesos[j]] + valores[j] > k[w])
                    k[w] = k[w - pesos[j]] + valores[j];
            }
        }
    }

    cout << "Matriz de PD" << endl;
    for(int i = 0; i < PESO_MAX+1; i++)
        cout << k[i] << " ";
    cout << endl;

    return k[PESO_MAX];
}

int mochila_norepeat(int* pesos, int* valores)
{
    int k[PESO_MAX+1][QUANT_ITENS+1];

    // Inicializa matriz de PD
    for(int w = 0; w <= PESO_MAX; w++)
        k[w][0] = 0;
    for(int j = 0; j <= QUANT_ITENS; j++)
        k[0][j] = 0;

    // Percorrendo
    // Como a matriz começa a ter dados em 1, precisamos subtrair 1
    // quando utilizarmos os vetores pesos e valores
    for(int j = 1; j <= QUANT_ITENS; j++)
    {
        for(int w = 1; w <= PESO_MAX; w++)
        {
            if(pesos[j-1] > w)
                k[w][j] = k[w][j-1];
            else
            {
                if((k[w - pesos[j-1]][j - 1] + valores[j - 1]) > k[w][j-1])
                    k[w][j] = k[w - pesos[j-1]][j - 1] + valores[j - 1];
                else
                    k[w][j] = k[w][j-1];
            }
        }
    }

    cout << endl;
    for(int i = 0; i <= PESO_MAX; i++)
    {
        for(int j = 0; j <= QUANT_ITENS; j++)
            cout << k[i][j] << " ";
        cout << endl;
    }
    cout << endl;cout << endl;
    return k[PESO_MAX][QUANT_ITENS];
}


int main()
{
    int pesos[] = {12, 2, 1, 4, 1};
    int valores[] = {4, 2, 1, 10, 2};

    cout << "Mochila com repeticao: " << endl;
    cout << "Valor maximo: R$ " << mochila_repeat(pesos, valores) << endl << endl;

    cout << "Mochila sem repeticao: " << endl;
    cout << "Valor maximo: R$ " << mochila_norepeat(pesos, valores) << endl;
}
