#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Chess_Board.h"
#include "Game_Manager.h"
using namespace std;

class File_Manager
{
    private:

    public:
        void SaveData(string fileName);
        void LoadData(string fileName);
};

#endif
