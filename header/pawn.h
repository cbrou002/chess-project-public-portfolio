#ifndef PAWN_H
#define PAWN_H

#include "../header/piece.h"

class Pawn : public Piece
{
    private:
        
    public:
        Pawn(char col, vector<int> pos);
        string getDisplayChar();
        vector<vector<int>> validDestinations(Piece* board[8][8]);
};

#endif
