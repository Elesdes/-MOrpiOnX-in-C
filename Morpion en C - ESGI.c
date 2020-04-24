#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char matrix[3][3];
char player1;
char player2;
int i;
int j;
int score1;
int score2;

void matrixInit() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrix[i][j] = ' ';
        }
    }
}

int win() {
    if (((matrix[0][0] == 'X') && matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]) ||
        ((matrix[1][0] == 'X') && matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]) ||
        ((matrix[2][0] == 'X') && matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]) ||
        ((matrix[0][0] == 'X') && matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) ||
        ((matrix[0][1] == 'X') && matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) ||
        ((matrix[0][2] == 'X') && matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) ||
        ((matrix[0][2] == 'X') && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) ||
        ((matrix[0][0] == 'X') && matrix[0][0] == matrix[1][1] && matrix[1][0] == matrix[2][2])) {
        printf("Le joueur X gagne");
        return 1;
    } else if (((matrix[0][0] == 'O') && matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2]) ||
               ((matrix[1][0] == 'O') && matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2]) ||
               ((matrix[2][0] == 'O') && matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2]) ||
               ((matrix[0][0] == 'O') && matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0]) ||
               ((matrix[0][1] == 'O') && matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1]) ||
               ((matrix[0][2] == 'O') && matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2]) ||
               ((matrix[0][2] == 'O') && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) ||
               ((matrix[0][0] == 'O') && matrix[0][0] == matrix[1][1] && matrix[1][0] == matrix[2][2])) {
        printf("Le joueur O gagne");
        return 1;
    } else {
        return 0;
    }
}

void printMatrix() {
    printf("\n\n\n");
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    printf("+-+-+-+\n");
    printf("\n\n\n");
}

int rockPaperScissors() {
    int p1;
    int p2;
    int winner;
    printf("\nDecidons qui commence avec un pierre-papier-ciseau\n"
           "1 = Pierre\n2 = Papier\n3 = Ciseaux\n\n%c : ", player1);
    scanf("%d", &p1);
    printf("%c :", player2);
    scanf("%d", &p2);
    while (p1 == p2 || p1 < 1 || p1 > 3 || p2 < 1 || p2 > 3) {
        if (p1 < 1 || p1 > 3 || p2 < 1 || p2 > 3) {
            printf("Nombre invalide, veuillez reessayer %c\n", player1);
            scanf("%d", &p1);
            printf("%c :", player2);
            scanf("%d", &p2);
        } else {
            printf("\nEgalite, encore !\n\n%c :", player1);
            scanf("%d", &p1);
            printf("%c :", player2);
            scanf("%d", &p2);
        }
    }
    if (p1 == 2 && p2 == 1) {
        printf("%c commence !!", player1);
        winner = 1;
    } else if (p1 == 1 && p2 == 2) {
        printf("%c commence !!", player2);
        winner = 2;
    } else if (p1 == 1 && p2 == 3) {
        printf("%c commence !!", player1);
        winner = 1;
    } else if (p1 == 3 && p2 == 1) {
        printf("%c commence !!", player2);
        winner = 2;
    } else if (p1 == 3 && p2 == 2) {
        printf("%c commence !!", player1);
        winner = 1;
    } else if (p1 == 2 && p2 == 3) {
        printf("%c commence !!", player2);
        winner = 2;
    }
    return winner;
}

void game(int who, int turn, int party, char starter_) {

    int winner;
    winner = 0;
    int row;
    int column;

    while (winner != 1) {
        if ((turn + party) % 2 == who) {
            printf("\nJoueur 1, choisissez une colonne entre 1 et 3 pour placer votre pion");
            scanf("%d", &column);
            printf("\nJoueur 1, choisissez une ligne entre 1 et 3 pour placer votre pion");
            scanf("%d", &row);

            while ((row > 3 || row < 1) || (column > 3 || column < 1)) {
                printf("\nT'es con ou bien ?\n\nUn nombre entre 1 et 3 pour la colonne :");
                scanf("%d", &column);
                printf("Un nombre entre 1 et 3 pour la ligne :");
                scanf("%d", &row);
            }

            matrix[row - 1][column - 1] = starter_;
            winner = win();
            score1 += win();
            printMatrix();
            turn++;
        } else {
            printf("\nJoueur 2, choisissez une colonne entre 1 et 3 pour placer votre pion");
            scanf("%d", &column);
            printf("\nJoueur 2, choisissez une ligne entre 1 et 3 pour placer votre pion");
            scanf("%d", &row);

            while ((row > 3 || row < 1) || (column > 3 || column < 1) || matrix[row - 1][column - 1] != ' ') {
                printf("\nAllez on réessaie\n\nUn nombre entre 1 et 3 pour la colonne :");
                scanf("%d", &column);
                printf("Un nombre entre 1 et 3 pour la ligne :");
                scanf("%d", &row);
            }

            if (starter_ == 'X') {
                matrix[row - 1][column - 1] = 'O';
            } else {
                matrix[row - 1][column - 1] = 'X';
            }

            winner = win();
            score2 += win();
            printMatrix();
            turn++;
        }
    }

}

char gridChar(int i) {
    switch (i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

void draw(int b[9]) {
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", gridChar(b[0]), gridChar(b[1]), gridChar(b[2]));
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", gridChar(b[3]), gridChar(b[4]), gridChar(b[5]));
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", gridChar(b[6]), gridChar(b[7]), gridChar(b[8]));
    printf("+-+-+-+\n");
}

int win_(const int board[9]) {
    unsigned wins[8][3] = {{0, 1, 2},
                           {3, 4, 5},
                           {6, 7, 8},
                           {0, 3, 6},
                           {1, 4, 7},
                           {2, 5, 8},
                           {0, 4, 8},
                           {2, 4, 6}};
    int i;
    for (i = 0; i < 8; ++i) {
        if (board[wins[i][0]] != 0 &&
            (board[wins[i][0]] == board[wins[i][1]] &&
             board[wins[i][0]] == board[wins[i][2]])) {
            return board[wins[i][2]];
        }
    }
    return 0;
}

int minimax(int board[9], int player) {

    int winner = win(board);
    if (winner != 0) return winner * player;

    int move = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; ++i) {
        if (board[i] == 0) {
            board[i] = player;
            int thisScore = -minimax(board, player * -1);
            if (thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;
        }
    }
    if (move == -1) return 0;
    return score;
}

void computerMove(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for (i = 0; i < 9; ++i) {
        if (board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if (tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    board[move] = 1;
}

void playerMove(int board[9]) {
    int move = 0;
    do {
        printf("\nPlacement ? ([0..8]): ");
        scanf("%d", &move);
        printf("\n");
    } while (move >= 9 || (move < 0 && board[move] != 0));
    board[move] = -1;
}

int playerVSIA() {
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    printf("Skynet : O, Vous : X\nJouer (1)et ou (2)eme ? ");
    int player = 0;
    scanf("%d", &player);
    printf("\n");
    unsigned turn;
    for (turn = 0; turn < 9 && win_(board) == 0; ++turn) {
        if ((turn + player) % 2 == 0)
            computerMove(board);
        else {
            draw(board);
            playerMove(board);
        }
    }
    switch (win_(board)) {
        case 0:
            printf("Egalite.\n");
            break;
        case 1:
            draw(board);
            printf("Tu as perdu.\n");
            break;
        case -1:
            printf("Tu as gagne ! Incroyable !\n");
            break;
    }
}

int playerVSPlayer() {
    char starter;
    int start;
    int nbTurn;
    int nbParty;
    nbTurn = 1;
    nbParty = 1;
    player1 = 'X';
    player2 = 'O';
    matrixInit();
    printMatrix();
    start = rockPaperScissors() % 2;
    if (start == 1) {
        starter = 'O';
    } else {
        starter = 'X';
    }
    game(start, nbTurn, nbParty, starter);
    return 0;
}

void scorePrinting() {
    printf("Score des X : %d  --  Score des O : %d\n", score1, score2);
}

int main() {
    int menu;

    printf("=================== Menu ===================\n");
    printf("1 - Lancer une partie en mode 1 vs 1\n");
    printf("2 - Lancer une partie en mode 1 vs IA\n");
    printf("3 - Visionner les scores de la derniere partie\n");
    printf("4 - Quitter\n");
    printf("============================================\n");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            playerVSPlayer();
            main();
        case 2:
            playerVSIA();
            main();
        case 3:
            scorePrinting();
            main();
        default:
            break;
    }
    printf("A bientot !");
    return 0;
}
