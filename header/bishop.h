#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
    private:

    public:
        Bishop(char col, vector<int> pos);
        vector<vector<int>> validDestinations(Piece* board[8][8]) override;
        string getDisplayChar() override;
};

#endif
