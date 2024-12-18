#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    private:

    public:
        Knight(char col, vector<int> pos);
        string getDisplayChar();
        vector<vector<int>> validDestinations(Piece* board[8][8]);
};

#endif
