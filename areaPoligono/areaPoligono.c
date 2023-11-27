#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

// Definindo uma estrutura para representar um ponto no plano 2D.
typedef struct {
    double x;
    double y;
} Ponto;

// Função para calcular a área de um triângulo formado por três pontos.
double calcularAreaTriangulo(Ponto a, Ponto b, Ponto c) {
    // Exibindo os pontos do triângulo que está sendo calculado
    printf("[CALCULO DA AREA DO TRIANGULO] Calculando a area do triangulo formado pelos pontos: A(%lf, %lf), B(%lf, %lf), C(%lf, %lf)\n", a.x, a.y, b.x, b.y, c.x, c.y);
    
    // Calculando o determinante para a área do triângulo
    double det = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    double area = fabs(det / 2.0); // Calculando a área e assegurando que seja positiva (fabs)
    
    // Exibindo a área do triângulo calculado
    printf("    [CALCULO DA AREA DO TRIANGULO] Area do triangulo: %lf\n", area);
    return area;
}

// Função para calcular a área de um polígono dividindo-o em triângulos.
double calcularAreaPoligono(Ponto pontos[], int n) {
    // Iniciando o cálculo da área do polígono
    printf("[CALCULO DA AREA DO POLIGONO] Iniciando o calculo da area do poligono\n");
    double areaTotal = 0.0; 
    
    // Iterando sobre os pontos do polígono para formar triângulos
    for (int i = 1; i < n - 1; i++) {
        // Calculando a área do triângulo e somando à área total
        double areaTriangulo = calcularAreaTriangulo(pontos[0], pontos[i], pontos[i + 1]);
        areaTotal += areaTriangulo;
        
        // Exibindo a área parcial após adicionar cada triângulo
        printf("    [CALCULO DA AREA DO POLIGONO] Area parcial apos adicionar triangulo %d: %lf\n", i, areaTotal);
    }
    
    // Exibindo a área total do polígono
    printf("[CALCULO DA AREA DO POLIGONO] Area total do poligono: %lf\n", areaTotal);
    return areaTotal;
}

// Função principal do programa
int main() {
    // Iniciando o programa
    printf("[MAIN] Iniciando o programa\n");

    // Abrindo o arquivo que contém os pontos do polígono
    FILE *file = fopen("./areaPoligono.txt", "r");
    if (file == NULL) { // Verificando se o arquivo foi aberto com sucesso
        perror("[ERRO] Falha ao abrir o arquivo");
        return 1;
    }

    int n; // Variável para armazenar o número de pontos do polígono
    // Lendo o número de pontos do arquivo
    if (fscanf(file, "%d", &n) != 1) {
        fprintf(stderr, "[ERRO] Falha ao ler o número de pontos do arquivo\n");
        fclose(file);
        return 1;
    }

    // Alocando memória para armazenar os pontos do polígono
    Ponto *pontos = malloc(n * sizeof(Ponto));
    if (pontos == NULL) { // Verificando se a memória foi alocada com sucesso
        perror("[ERRO] Falha na alocação de memória");
        fclose(file);
        return 1;
    }

    // Lendo as coordenadas de cada ponto do arquivo
    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%lf %lf", &pontos[i].x, &pontos[i].y) != 2) {
            fprintf(stderr, "[ERRO] Falha ao ler as coordenadas do ponto %d\n", i);
            free(pontos);
            fclose(file);
            return 1;
        }
    }

    // Calculando a área do polígono
    double area = calcularAreaPoligono(pontos, n);
    printf("[RESULTADO] Area do poligono: %lf\n", area);

    // Liberando a memória alocada e fechando o arquivo
    free(pontos);
    fclose(file);

    printf("[MAIN] Finalizando o programa\n");
    return 0;
}