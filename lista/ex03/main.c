#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

double calcularDistancia(const Ponto ponto1, const Ponto ponto2) {
    double diffX = ponto2.x - ponto1.x;
    double diffY = ponto2.y - ponto1.y;
    return diffX * diffX + diffY * diffY;
}

double calcularInclinacao(const Ponto ponto1, const Ponto ponto2) {
    double diffX = ponto2.x - ponto1.x;
    if (diffX == 0) {
        return 0; 
    }
    double diffY = ponto2.y - ponto1.y;
    return diffY / diffX;
}

int main() {
    Ponto ponto1 = {0, 0};
    Ponto ponto2 = {3, 4};

    double distanciaQuadrada = calcularDistancia(ponto1, ponto2);
    double inclinacao = calcularInclinacao(ponto1, ponto2);

    printf("Distancia ao quadrado entre os pontos: %.2f\n", distanciaQuadrada);
    printf("Inclinacao da reta: %.2f\n", inclinacao);

    return 0;
}



