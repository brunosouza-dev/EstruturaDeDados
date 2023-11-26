#include<stdio.h>
#include<stdlib.h>
#include"minhalib.h"

int main() {
  system("clear");

  int tamanho;

  printf("Digite o tamanho do vetor:");
  scanf("%d", &tamanho);

  int *meuArray = criarArray(tamanho);

  imprimirArrays(meuArray, tamanho, "Meu Vetor");

  // Liberando memória alocada para o array.
  free(meuArray);

  return 0;
}