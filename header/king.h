#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        King(char col, vector<int> pos);
        string getDisplayChar();
        vector<vector<int>> validDestinations(Piece* board[8][8]) override;
        bool inCheck(Piece* board[8][8]);
};

#endif
