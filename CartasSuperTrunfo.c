#include <stdio.h>

// Estrutura de uma carta Super Trunfo
typedef struct {
    char nome[50];
    double populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
    double super_poder;
} Carta;

// Função para calcular densidade populacional
double calcular_densidade(double populacao, double area) {
    if (area == 0) return 0;
    return populacao / area;
}

// Função para calcular PIB per capita
double calcular_pib_per_capita(double pib, double populacao) {
    if (populacao == 0) return 0;
    return pib / populacao;
}

// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta) {
    printf("Digite o nome da carta: ");
    scanf(" %[^\n]", carta->nome);

    printf("Populacao: ");
    scanf("%lf", &carta->populacao);

    printf("Area (em km²): ");
    scanf("%lf", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Cálculos automáticos
    carta->densidade_populacional = calcular_densidade(carta->populacao, carta->area);
    carta->pib_per_capita = calcular_pib_per_capita(carta->pib, carta->populacao);
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta c) {
    printf("\n--- Carta: %s ---\n", c.nome);
    printf("População: %.2lf\n", c.populacao);
    printf("Área: %.2lf km²\n", c.area);
    printf("PIB: %.2lf bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c.densidade_populacional);
    printf("PIB per Capita: %.2lf\n", c.pib_per_capita);
}

// Função para comparar cartas
void comparar_cartas(Carta c1, Carta c2) {
    printf("\n--- Comparação de Cartas ---\n");

    printf("População: %s\n", (c1.populacao > c2.populacao) ? c1.nome : c2.nome);
    printf("Área: %s\n", (c1.area > c2.area) ? c1.nome : c2.nome);
    printf("PIB: %s\n", (c1.pib > c2.pib) ? c1.nome : c2.nome);
    printf("Pontos Turísticos: %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.nome : c2.nome);
    printf("Densidade Populacional: %s\n", (c1.densidade_populacional > c2.densidade_populacional) ? c1.nome : c2.nome);
    printf("PIB per Capita: %s\n", (c1.pib_per_capita > c2.pib_per_capita) ? c1.nome : c2.nome);
}

// Função que calcula um "super poder" (soma ponderada dos atributos)
double calcular_super_poder(Carta c) {
    // Simples soma dos atributos normalizados para fins de comparação
    return c.populacao + c.area + c.pib + c.pontos_turisticos +
           c.densidade_populacional + c.pib_per_capita;
}

void comparar_super_poder(Carta c1, Carta c2) {
    c1.super_poder = calcular_super_poder(c1);
    c2.super_poder = calcular_super_poder(c2);

    printf("\n--- Super Poder ---\n");
    printf("%s: %.2lf\n", c1.nome, c1.super_poder);
    printf("%s: %.2lf\n", c2.nome, c2.super_poder);

    if (c1.super_poder > c2.super_poder) {
        printf(">>> Vencedora: %s (Super Poder)\n", c1.nome);
    } else if (c2.super_poder > c1.super_poder) {
        printf(">>> Vencedora: %s (Super Poder)\n", c2.nome);
    } else {
        printf(">>> Empate no Super Poder!\n");
    }
}

int main() {
    Carta carta1, carta2;

    printf("=== Cadastro da Carta 1 ===\n");
    cadastrar_carta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    cadastrar_carta(&carta2);

    exibir_carta(carta1);
    exibir_carta(carta2);

    comparar_cartas(carta1, carta2);
    comparar_super_poder(carta1, carta2);

    return 0;
}

