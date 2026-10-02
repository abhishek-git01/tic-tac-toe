#include <iostream>
#include <ctime>
#include <cctype>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char player = 'X';
    char computer = 'O';
    char playAgain;

    srand(time(NULL));

    do {
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        bool running = true;

        drawBoard(spaces);

        while (running) {
            playerMove(spaces, player);
            drawBoard(spaces);

            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);

            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        playAgain = std::tolower(playAgain);

    } while (playAgain == 'y');

    std::cout << "Thanks for playing!!";

    return 0;
}

void drawBoard(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |   " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |   " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |   " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player) {
    int number;

    while (true) {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;

        if (number < 1 || number > 9) {
            std::cout << "Enter a valid number between 1 and 9.\n";
            continue;
        }

        number--;

        if (spaces[number] == ' ') {
            spaces[number] = player;
            break;
        } else {
            std::cout << "That spot is already occupied. Try again.\n";
        }
    }
}

void computerMove(char *spaces, char computer) {
    int number;

    while (true) {
        number = rand() % 9;

        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {

    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) {
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) {
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) {
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    } else {
        return false;
    }

    return true;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }

    std::cout << "IT'S A TIE!\n";
    return true;
}