#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // bilhões de reais
    int pontosTuristicos;
};

int main() {
    struct Carta cartas[2];
    float densidade[2], pibPerCapita[2], superPoder[2];

    for (int i = 0; i < 2; i++) {
        printf("\nCadastro da Carta %d:\n", i + 1);

        do {
            printf("Estado (letra de A a H): ");
            scanf(" %c", &cartas[i].estado);
        } while (cartas[i].estado < 'A' || cartas[i].estado > 'H');

        printf("Código da Carta (ex: A01): ");
        scanf("%3s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("População: ");
        scanf("%lu", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhões de reais): ");
        scanf("%f", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos
        densidade[i] = cartas[i].populacao / cartas[i].area;
        pibPerCapita[i] = (cartas[i].pib * 1e9f) / cartas[i].populacao;
        superPoder[i] = (float)cartas[i].populacao + cartas[i].area + 
                        (cartas[i].pib * 1e9f) + (float)cartas[i].pontosTuristicos + 
                        pibPerCapita[i] + (1.0f / densidade[i]);
    }

    // Exibe os dados
    for (int i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Código: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].nomeCidade);
        printf("População: %lu\n", cartas[i].populacao);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de reais\n", cartas[i].pib);
        printf("Número de Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km²\n", densidade[i]);
        printf("PIB per Capita: %.2f reais\n", pibPerCapita[i]);
        printf("Super Poder: %.2f\n", superPoder[i]);
    }

    // Comparações
    printf("\n\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", cartas[0].populacao > cartas[1].populacao);
    printf("Área: Carta 1 venceu (%d)\n", cartas[0].area > cartas[1].area);
    printf("PIB: Carta 1 venceu (%d)\n", cartas[0].pib > cartas[1].pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", cartas[0].pontosTuristicos > cartas[1].pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade[0] < densidade[1]);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita[0] > pibPerCapita[1]);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder[0] > superPoder[1]);

    return 0;
}