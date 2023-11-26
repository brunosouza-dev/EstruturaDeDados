#include<stdio.h>

struct Pessoa {
  char nome[20];
  int idade;
};

// Nesta func, a passagem de parâmetros se da por referência
void modificarIdadePessoa(struct Pessoa *p) {
  // Ao passar parâmetro por referência ao inves do 'p.idade' usamos o operador '->'
  p->idade += 1;
}

int main() {
  struct Pessoa X = {"João", 25};
  modificarIdadePessoa(&X);

  printf("Nome: %s\n", X.nome);
  printf("Idade: %d\n", X.idade);
}