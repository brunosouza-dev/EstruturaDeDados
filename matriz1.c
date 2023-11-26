#include<stdio.h>
#include<stdlib.h>

int main() {
  system("clear");

  int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };

  int soma = 0, i, j;

  printf("Elemento da 2ª linha e 3ª Coluna: %d\n", matriz[1][2]);

  for (i = 0; i < 2; i++)
    for (j = 0; j < 3; j++)
      soma += matriz[i][j];

    printf("A soma dos elementos da matriz é: %d\n", soma);
  
  return 0;
}