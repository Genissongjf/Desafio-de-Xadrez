#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

// Estrutura para representar o tabuleiro de xadrez
char board[BOARD_SIZE][BOARD_SIZE];

// Função para inicializar o tabuleiro
void initializeBoard() {
    char initialBoard[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    memcpy(board, initialBoard, sizeof(initialBoard));
}

// Função para exibir o tabuleiro
void printBoard() {
    printf("  a b c d e f g h\n");
    printf("  ---------------\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", 8 - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para converter a posição de notação algébrica para índices de matriz
void convertNotationToIndex(char *notation, int *row, int *col) {
    *col = notation[0] - 'a';
    *row = 8 - (notation[1] - '0');
}

// Função para mover a peça
int movePiece(char *from, char *to) {
    int fromRow, fromCol, toRow, toCol;
    convertNotationToIndex(from, &fromRow, &fromCol);
    convertNotationToIndex(to, &toRow, &toCol);

    if (board[fromRow][fromCol] == ' ') {
        printf("Não há peça na posição de origem.\n");
        return 0;
    }

    // Realiza o movimento
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';

    return 1;
}

// Função principal para o jogo
int main() {
    char from[3], to[3];
    int gameOver = 0;

    initializeBoard();
    printBoard();

    while (!gameOver) {
        printf("Digite seu movimento (ex: e2 e4): ");
        scanf("%s %s", from, to);

        if (!movePiece(from, to)) {
            printf("Movimento inválido. Tente novamente.\n");
        } else {
            printBoard();
                }
    }

    return 0;
}
