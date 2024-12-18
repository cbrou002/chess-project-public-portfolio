#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
    public:
        Queen(char col, vector<int> pos);
        string getDisplayChar();
        vector<vector<int>> validDestinations(Piece* board[8][8]) override;
};

#endif
