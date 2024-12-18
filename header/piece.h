#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>
using namespace std;

class Piece
{
    public:
        char color;
        vector<int> position;
        bool hasMoved;

        virtual vector<vector<int>> validDestinations(Piece* board[8][8]) = 0;
        virtual string getDisplayChar() = 0;
};

#endif
