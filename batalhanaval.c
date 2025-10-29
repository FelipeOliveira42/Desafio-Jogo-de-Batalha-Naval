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

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            printf("Erro: navio horizontal sobreposto!\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; // 3 representa navio
    }

    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe no tabuleiro
    if (linha + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            printf("Erro: navio vertical sobreposto!\n");
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; // 3 representa navio
    }

    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas diretamente)
    int navio1_linha = 2, navio1_coluna = 3; // horizontal
    int navio2_linha = 5, navio2_coluna = 7; // vertical

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, navio1_linha, navio1_coluna)) {
        printf("Falha ao posicionar navio 1.\n");
    }

    if (!posicionarNavioVertical(tabuleiro, navio2_linha, navio2_coluna)) {
        printf("Falha ao posicionar navio 2.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
