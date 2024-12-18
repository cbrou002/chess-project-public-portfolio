#include "../header/Chess_Board.h"
#include "../header/piece.h"
#include "../header/knight.h"
#include "../header/rook.h"
#include "../header/pawn.h"
#include "../header/queen.h"
#include "../header/king.h"
#include "../header/bishop.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Chess_Board::Chess_Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }
}

void Chess_Board::addPiece(vector<int> position, char piece, char color) {
    int row = position.at(0);
    int column = position.at(1);
    if (piece == 'b')
        board[row][column] = new Bishop(color, position);
    else if (piece == 'p')
        board[row][column] = new Pawn(color, position);
    else if (piece == 'k')
        board[row][column] = new King(color, position);
    else if (piece == 'q')
        board[row][column] = new Queen(color, position);
    else if (piece == 'n')
        board[row][column] = new Knight(color, position);
    else if (piece == 'r')
        board[row][column] = new Rook(color, position);
}

void Chess_Board::initBoard(){
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    for (int i = 0; i < 8; i++){
        pos.at(1) = i;
        pos.at(0) = 1;
        addPiece(pos, 'p', 'w');
        pos.at(0) = 6;
        addPiece(pos, 'p', 'b');
        if (i == 0 || i == 7){
            pos.at(0) = 0;
            addPiece(pos, 'r', 'w');
            pos.at(0) = 7;
            addPiece(pos, 'r', 'b');
        }
        else if (i == 1 || i == 6){
            pos.at(0) = 0;
            addPiece(pos, 'n', 'w');
            pos.at(0) = 7;
            addPiece(pos, 'n', 'b');
        }
        else if (i == 2 || i == 5){
            pos.at(0) = 0;
            addPiece(pos, 'b', 'w');
            pos.at(0) = 7;
            addPiece(pos, 'b', 'b');
        }
        else if (i == 3){
            pos.at(0) = 0;
            addPiece(pos, 'q', 'w');
            pos.at(0) = 7;
            addPiece(pos, 'q', 'b');
        }
        else if (i == 4){
            pos.at(0) = 0;
            addPiece(pos, 'k', 'w');
            pos.at(0) = 7;
            addPiece(pos, 'k', 'b');
        }
    }
}

Chess_Board::~Chess_Board() {
    // Deallocate the dynamically allocated Piece objects
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr)
                delete board[i][j];
        }
    }
}

void Chess_Board::display(){
    for (int i = 7; i >= 0; i--) {
        cout<< i+1 << ' ';
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr) {
                cout<< board[i][j]->getDisplayChar() << ' ';
            } 
            else {
                if (i%2 && !(j%2))
                    cout << "■ ";
                else if(j%2 && !(i%2))
                    cout << "■ ";
                else
                    cout << "□ ";
            }
        }
        cout << endl;
    }
    cout << "  a b c d e f g h"<<endl;
}

Piece* Chess_Board::findKing(char color){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr && dynamic_cast<King*>(board[i][j]) != nullptr && board[i][j]->color == color)
                return board[i][j];
        }
    }
    return nullptr;
}
