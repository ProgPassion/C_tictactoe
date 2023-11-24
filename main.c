#include <stdlib.h>
#include <stdio.h>

void printField(char field[3][3]) {
        printf("    1   2   3\n");
        printf("   --- --- ---\n");
        printf("  |   |   |   |\n");
        printf("1 | %c | %c | %c |\n", field[0][0], field[0][1], field[0][2]);
        printf("  |   |   |   |\n");
        printf("   --- --- --- \n");
        printf("  |   |   |   |\n");
        printf("2 | %c | %c | %c |\n", field[1][0], field[1][1], field[1][2]);
        printf("  |   |   |   |\n");
        printf("   --- --- --- \n");
        printf("  |   |   |   |\n");
        printf("3 | %c | %c | %c |\n", field[2][0], field[2][1], field[2][2]);
        printf("  |   |   |   |\n");
        printf("   --- --- ---\n");
        printf("\n\n");
}

void printPlayerMsg(int *x, int *y, char player) {
        printf("Lojtari %c, vendosni numrin e koordinates x te kuadratit: ", player);
        scanf("%d", x);
        printf("Lojtari %c, vendosni numrin e koordinates y te kuadratit: ", player);
        scanf("%d", y);
}

int writeField(int x, int y, char player, char field[3][3]) {
        if(field[x][y] == ' ') {
                field[x][y] = player;
                return 1;
        }
        return 0;
}

void printWinner(char winner) {
        if(winner == ' ') {
                printf("Nuk ka fitues, loja mbaroj barazim!\n");
        }
        else {
                printf("Lojtari %c eshte fituesi.\n", winner);
        }
}

int checkGameOver(char field[3][3]) {
        for(int i = 0; i < 3; i++) {
                if(field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != ' ') {
                        return 1;
                }
                
        }

        for(int i = 0; i < 3; i++) {
                if(field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != ' ') {
                        return 1;
                }
                
        }

        if ((field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] != ' ') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] != ' ')) {
                return 1;  
        }

        return 0;
}

int checkIfNoEmptyBoxRemained(char field[3][3]) {
        for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if(field[i][j] == ' ') {
                        return 0;
                    }    
                }
        }

        return 1;
}

int main() {

        int xCoor, yCoor;
        int turn = 1;
        char player = 'x';
        char winner = ' ';
        char field[3][3] = {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}
        };

        while(1) {
                system("clear");
                if(checkIfNoEmptyBoxRemained(field)) {
                        break;
                }
                if(turn % 2 == 1) {
                        player = 'x';
                }
                else {
                        player = 'o';
                }
                printField(field);
                printPlayerMsg(&xCoor, &yCoor, player);
                if(writeField(xCoor - 1, yCoor - 1, player, field)) {
                        turn++;
                }
                if(checkGameOver(field)) {
                        winner = player;
                        break;
                }
        }
        system("clear");
        printField(field);
        printWinner(winner);
}


