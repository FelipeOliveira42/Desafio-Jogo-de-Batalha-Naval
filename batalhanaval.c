#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0; // Sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; // Sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal descendente (\)
int posicionarNavioDiagonalDesc(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0; // Sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal ascendente (/)
int posicionarNavioDiagonalAsc(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha - (TAM_NAVIO - 1) < 0 || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha - i][coluna + i] != 0) return 0; // Sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = 3;
    }
    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas diretamente)
    int navio1_linha = 1, navio1_coluna = 2; // horizontal
    int navio2_linha = 4, navio2_coluna = 6; // vertical
    int navio3_linha = 0, navio3_coluna = 0; // diagonal descendente (\)
    int navio4_linha = 9, navio4_coluna = 1; // diagonal ascendente (/)

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, navio1_linha, navio1_coluna)) {
        printf("Falha ao posicionar navio horizontal.\n");
    }
    if (!posicionarNavioVertical(tabuleiro, navio2_linha, navio2_coluna)) {
        printf("Falha ao posicionar navio vertical.\n");
    }
    if (!posicionarNavioDiagonalDesc(tabuleiro, navio3_linha, navio3_coluna)) {
        printf("Falha ao posicionar navio diagonal descendente.\n");
    }
    if (!posicionarNavioDiagonalAsc(tabuleiro, navio4_linha, navio4_coluna)) {
        printf("Falha ao posicionar navio diagonal ascendente.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
