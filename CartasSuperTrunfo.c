#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4]; // Ex: "A01", inclui o '\0' no final
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct Carta cartas[2];

    for (int i = 0; i < 2; i++) {
        printf("\nCadastro da Carta %d:\n", i + 1);

        printf("Estado (letra de A a H): ");
        scanf(" %c", &cartas[i].estado);  // Espaço antes de %c para ignorar \n pendente

        printf("Código da Carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);  // Lê até o \n (nome com espaços)

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    // Exibe as cartas
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %d\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
    }

    return 0;
}
