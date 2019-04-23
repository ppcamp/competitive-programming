#include <cstdio>
#include <string.h>

int maximum_weight_set(int *vet, int siz)
{
    int memo[siz+1]; // vetor de PD
    memset(memo, 0, sizeof memo); // Inicialização (opcional)

    // Casos base (como em uma recursão)
    memo[0] = 0;
    memo[1] = vet[0];

    // Apenas percorremos vetor (tempo linear)
    for(int i = 2; i <= siz; i++)
    {
        // Testamos qual das uas opções seguir
        if(memo[i-1] > memo[i-2]+vet[i-1])
            memo[i] = memo[i-1];
        else
            memo[i] = memo[i-2]+vet[i-1];
    }

    return memo[siz];
}

int main()
{
    // Tnte encontrar de cabeça!
    int path[] = {1, 4, 5, 4, 1, 10, 12, 3, 2, 1};
    printf("Max weight: %d", maximum_weight_set(path, 10));
    return 0;
}
