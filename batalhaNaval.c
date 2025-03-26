#include <stdio.h>
#include <stdbool.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Constantes para representar o tabuleiro
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int x, int y, int tamanho, bool vertical, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se está dentro dos limites do tabuleiro
    if (vertical) {
        if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y + tamanho - 1 >= TAMANHO_TABULEIRO) {
            return false;
        }
    } else {
        if (x < 0 || x + tamanho - 1 >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) {
            return false;
        }
    }
    
    // Verifica se não há sobreposição com outros navios
    if (vertical) {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != AGUA) {
                return false;
            }
        }
    } else {
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != AGUA) {
                return false;
            }
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, bool vertical) {
    if (vertical) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[x][y + i] = NAVIO;
        }
    } else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[x + i][y] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n\n");
    
    // Imprime números das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Imprime linhas do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água, 3 = Navio\n");
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    
    printf("Batalha Naval - Posicionamento de Navios\n");
    
    // Posiciona o navio horizontal
    int navioHorizontalX = 2, navioHorizontalY = 3;
    bool navioHorizontalVertical = false;
    
    // Valida a posição do navio horizontal
    if (!posicaoValida(navioHorizontalX, navioHorizontalY, TAMANHO_NAVIO, navioHorizontalVertical, tabuleiro)) {
        printf("Posição inválida para o navio horizontal!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navioHorizontalX, navioHorizontalY, navioHorizontalVertical);
    
    // Posiciona o navio vertical
    int navioVerticalX = 5, navioVerticalY = 7;
    bool navioVerticalVertical = true;
    
    // Valida a posição do navio vertical
    if (!posicaoValida(navioVerticalX, navioVerticalY, TAMANHO_NAVIO, navioVerticalVertical, tabuleiro)) {
        printf("Posição inválida para o navio vertical!\n");
        return 1;
    }
    posicionarNavio(tabuleiro, navioVerticalX, navioVerticalY, navioVerticalVertical);
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}