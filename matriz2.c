#include<stdio.h>
#include<stdlib.h>
#include"minhalib.h"

int main() {
  // Limapando o terminal.
  system("clear");

  // Declarando variáveis privadas 
  int meuArray[5] = {2, 5, 6, 9, 1};
  int tamanho = sizeof(meuArray) / sizeof(meuArray[0]);

  // Chamando as funcões da 'minhalib' para imprimir o array e modificá-lo
  imprimirArrays(meuArray, tamanho, "teste");
  modificarArrays(meuArray, tamanho);
  imprimirArrays(meuArray, tamanho, "teste");
  
  return 0;
}