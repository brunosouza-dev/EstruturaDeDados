#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *entrada = fopen("/Users/brunosouza/Documents/Universidade/EstruturaDados/output/DadosEntrada.csv", "r");
    FILE *saida = fopen("SituacaoFinal.csv", "w");

    if (entrada == NULL) {
        printf("Erro ao abrir a entrada.\n");
        return 1;
    } else if (saida == NULL) {
      printf("Erro ao abrir a saida.\n");
        return 1;
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        // Separando os dados da linha
        char *nome, *telefone, *curso, *nota1, *nota2;
        nome = strtok(linha, ",");
        telefone = strtok(NULL, ",");
        curso = strtok(NULL, ",");
        nota1 = strtok(NULL, ",");
        nota2 = strtok(NULL, ",");

        // Verificando se todos os campos foram lidos corretamente
        if (nome == NULL || telefone == NULL || curso == NULL || nota1 == NULL || nota2 == NULL) {
            printf("Erro ao ler os dados da linha.\n");
            continue;
        }

        // Convertendo as notas para valores numéricos
        float nota1_val = atof(nota1);
        float nota2_val = atof(nota2);

        // Calculando a nota média
        float nota_media = (nota1_val + nota2_val) / 2.0;

        // Determinando a situação do aluno
        const char *situacao = (nota_media >= 7.0) ? "APROVADO" : "REPROVADO";

        // Escrevendo os resultados no arquivo de saída
        fprintf(saida, "%s, %.2f, %s\n", nome, nota_media, situacao);
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}