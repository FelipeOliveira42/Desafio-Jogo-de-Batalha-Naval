#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para exibir o tabuleiro com navios e habilidades
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("~ "); // Água
            else if (tabuleiro[i][j] == 3) printf("# "); // Navio
            else if (tabuleiro[i][j] == 5) printf("* "); // Área de habilidade
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0; 
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0; 
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal descendente (\)
int posicionarNavioDiagonalDesc(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0; 
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonal ascendente (/)
int posicionarNavioDiagonalAsc(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha - (TAM_NAVIO - 1) < 0 || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; 
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha - i][coluna + i] != 0) return 0; 
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha - i][coluna + i] = 3;
    }
    return 1;
}

// Função para criar área de habilidade em cone (5x5)
void aplicarHabilidadeCone(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemLinha, int origemColuna) {
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    // Construção da forma de cone usando condicionais
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Aplicar no tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - 2; 
            int colTab = origemColuna + j - 2;
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colTab >= 0 && colTab < TAM_TABULEIRO) {
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                    tabuleiro[linhaTab][colTab] = 5; // Marca área de habilidade
            }
        }
    }
}

// Função para criar área de habilidade em cruz (5x5)
void aplicarHabilidadeCruz(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemLinha, int origemColuna) {
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == 2 || j == 2) cruz[i][j] = 1; // Linhas e colunas centrais
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - 2; 
            int colTab = origemColuna + j - 2;
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colTab >= 0 && colTab < TAM_TABULEIRO) {
                if (cruz[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                    tabuleiro[linhaTab][colTab] = 5;
            }
        }
    }
}

// Função para criar área de habilidade em octaedro (5x5 losango)
void aplicarHabilidadeOctaedro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int origemLinha, int origemColuna) {
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {0};

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i + j >= 2 && j - i <= 2 && i - j <= 2 && i + j <= 6) {
                octaedro[i][j] = 1; // Losango central
            }
        }
    }

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + i - 2; 
            int colTab = origemColuna + j - 2;
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colTab >= 0 && colTab < TAM_TABULEIRO) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                    tabuleiro[linhaTab][colTab] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios
    posicionarNavioHorizontal(tabuleiro, 1, 2);
    posicionarNavioVertical(tabuleiro, 4, 6);
    posicionarNavioDiagonalDesc(tabuleiro, 0, 0);
    posicionarNavioDiagonalAsc(tabuleiro, 9, 1);

    // Aplica habilidades
    aplicarHabilidadeCone(tabuleiro, 2, 7);
    aplicarHabilidadeCruz(tabuleiro, 5, 3);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibe tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
