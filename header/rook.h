#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
    public:
        
        Rook(char col, vector<int> pos);
        vector<vector<int>> validDestinations(Piece* board[8][8]) override;
        string getDisplayChar() override;
};

#endif
