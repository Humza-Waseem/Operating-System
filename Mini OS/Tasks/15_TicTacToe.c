#include <stdio.h>

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char current_marker;
int current_player;

void draw_board() {
    printf("\n   %c   |   %c   |   %c   \n", board[0][0], board[0][1], board[0][2]);
    printf("-------|-------|-------\n");
    printf("   %c   |   %c   |   %c   \n", board[1][0], board[1][1], board[1][2]);
    printf("-------|-------|-------\n");
    printf("   %c   |   %c   |   %c   \n\n", board[2][0], board[2][1], board[2][2]);
}

int win_check() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int position_available(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
        return 1;
    else
        return 0;
}

void player_turn() {
    int choice;
    printf("Player %d, enter a number: ", current_player);
    scanf("%d", &choice);

    if (position_available(choice)) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        board[row][col] = current_marker;
    } else {
        printf("That position is not available. Try again.\n");
        player_turn();
    }
}

void switch_player_and_marker() {
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    if (current_player == 1)
        current_player = 2;
    else
        current_player = 1;
}

int main() {
    int i;
    printf("Tic Tac Toe\n");

    current_player = 1;
    current_marker = 'X';

    for (i = 0; i < 9; i++) {
        draw_board();
        player_turn();
        if (win_check()) {
            printf("Congratulations! Player %d wins!\n", current_player);
            return 0;
        }
        switch_player_and_marker();
    }

    printf("It's a tie!\n");
    return 0;
}
