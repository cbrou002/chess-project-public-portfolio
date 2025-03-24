#include "../header/Game_Manager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>

using namespace std;
using testing::UnorderedElementsAreArray;

TEST(Checkmate, stairMate){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    EXPECT_TRUE(game.isCheckMate());
}

TEST(Checkmate, stairMateStop){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 3;
    pos.at(0) = 3;
    game.chessboard.addPiece(pos, 'r', 'w');
    EXPECT_FALSE(game.isCheckMate());
}

TEST(Checkmate, stairMateTooClose){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(1);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    EXPECT_FALSE(game.isCheckMate());
}

TEST(Checkmate, onlyStopAlsoCreatesCheck){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 2;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 5;
    pos.at(0) = 7;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 4;
    game.chessboard.addPiece(pos, 'b', 'b');
    
    EXPECT_TRUE(game.isCheckMate());
}

TEST(Checkmate, pawnStop){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 3;
    game.chessboard.addPiece(pos, 'p', 'w');
    pos.at(1) = 7;
    pos.at(0) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 7;
    pos.at(0) = 2;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 5;
    pos.at(0) = 7;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 4;
    game.chessboard.addPiece(pos, 'b', 'b');
    EXPECT_FALSE(game.isCheckMate());
}
TEST(ValidDestinations, BishopNearCenter)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'b', 'w');
   pos.at(0) = 2;
   pos.at(1) = 3;
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 6;
   pos.at(1) = 1;
   myBoard.addPiece(pos, 'p', 'w');
   pos.at(0) = 1;
   pos.at(1) = 6;
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 6;
   pos.at(1) = 7;
   myBoard.addPiece(pos, 'p', 'w');
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,5},{5,6},{2,5},{1,6},{2,3},{4,3},{5,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, BishopNearEdge)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(1);
   myBoard.addPiece(pos, 'b', 'w');
   pos.at(0) = 2;
   pos.at(1) = 0;
   myBoard.addPiece(pos, 'b', 'b');
   pos.at(0) = 0;
   pos.at(1) = 4;
   myBoard.addPiece(pos, 'p', 'w');
   Bishop* myBishop = dynamic_cast<Bishop*>(myBoard.board[3][1]);
   vector<vector<int>> allMoves = myBishop->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,2},{5,3},{6,4},{7,5},{2,2},{1,3},{2,0},{4,0}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, RookNearCenter)
{
    Chess_Board myBoard = Chess_Board();
    vector<int> pos;
    pos.push_back(3);
    pos.push_back(4);
    myBoard.addPiece(pos, 'r', 'w');
    pos.at(0) = 1;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');
    pos.at(0) = 3;
    pos.at(1) = 0;
    myBoard.addPiece(pos, 'p', 'w');
    pos.at(0) = 7;
    pos.at(1) = 4;
    myBoard.addPiece(pos, 'p', 'b');
    pos.at(0) = 3;
    pos.at(1) = 5;
    myBoard.addPiece(pos, 'p', 'w');
    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[3][4]);
    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
    vector<vector<int>> matcher = {{2,4},{1,4},{4,4},{5,4},{6,4},{7,4},{3,3},{3,2},{3,1}};
    EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, RookAtEdge)
{
    Chess_Board myBoard = Chess_Board();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    myBoard.addPiece(pos, 'r', 'w');
    pos.at(0) = 7;
    pos.at(1) = 0;
    myBoard.addPiece(pos, 'p', 'w');
    pos.at(0) = 0;
    pos.at(1) = 7;
    myBoard.addPiece(pos, 'p', 'b');
    Rook* myRook = dynamic_cast<Rook*>(myBoard.board[0][0]);
    vector<vector<int>> allMoves = myRook->validDestinations(myBoard.board);
    vector<vector<int>> matcher = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7}};
    EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}


TEST(Stalemate, QueenCorner){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(0) = 1;
    pos.at(1) = 2;
    game.chessboard.addPiece(pos, 'q', 'b');
    EXPECT_TRUE(game.isStalemate());
}

TEST(Stalemate, checkmate){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(4);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    pos.at(1) = 1;
    pos.at(0) = 1;
    game.chessboard.addPiece(pos, 'r', 'b');
    EXPECT_FALSE(game.isStalemate());
}

TEST(Stalemate, QueenCornerAnotherPiece){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(0) = 1;
    pos.at(1) = 2;
    game.chessboard.addPiece(pos, 'q', 'b');
    pos.at(1) = 7;
    game.chessboard.addPiece(pos, 'p', 'w');
    EXPECT_FALSE(game.isStalemate());
}

TEST(Stalemate, pinnedPiece){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(0) = 1;
    pos.at(1) = 2;
    game.chessboard.addPiece(pos, 'q', 'b');
    pos.at(0) = 3;
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'b', 'w');
    pos.at(0) = 7;
    pos.at(1) = 0;
    game.chessboard.addPiece(pos, 'r', 'b');
    EXPECT_TRUE(game.isStalemate());
}

TEST(Stalemate, blockedPawn){
    Game_Manager game = Game_Manager();
    vector<int> pos;
    pos.push_back(0);
    pos.push_back(0);
    game.chessboard.addPiece(pos, 'k', 'w');
    pos.at(0) = 1;
    pos.at(1) = 2;
    game.chessboard.addPiece(pos, 'q', 'b');
    pos.at(0) = 4;
    pos.at(1) = 4;
    game.chessboard.addPiece(pos, 'p', 'w');
    pos.at(0) = 5;
    pos.at(1) = 4;
    game.chessboard.addPiece(pos, 'p', 'b');
    EXPECT_TRUE(game.isStalemate());
}

TEST(Castle, KingSideWhite)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,7}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][7];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({0,6}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({0,5}));
    EXPECT_TRUE(game.chessboard.board[0][4] == nullptr);
    EXPECT_TRUE(game.chessboard.board[0][7] == nullptr);
    EXPECT_FALSE(game.isWhiteTurn);
}
TEST(Castle, KingSideBlack) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,7}, 'r', 'b');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][7];
    vector<vector<int>> move = {{7,4},{7,6}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({7,6}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({7,5}));
    EXPECT_TRUE(game.chessboard.board[7][4] == nullptr);
    EXPECT_TRUE(game.chessboard.board[7][7] == nullptr);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, QueenSideWhite)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,0}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][0];
    vector<vector<int>> move = {{0,4},{0,2}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({0,2}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({0,3}));
    EXPECT_TRUE(game.chessboard.board[0][4] == nullptr);
    EXPECT_TRUE(game.chessboard.board[0][0] == nullptr);
    EXPECT_FALSE(game.isWhiteTurn);
}
TEST(Castle, QueenSideBlack)
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,0}, 'r', 'b');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][0];
    vector<vector<int>> move = {{7,4},{7,2}};
    ASSERT_TRUE(game.castle(move));
    EXPECT_THAT(king->position, testing::UnorderedElementsAreArray<vector<int>>({7,2}));
    EXPECT_THAT(rook->position, testing::UnorderedElementsAreArray<vector<int>>({7,3}));
    EXPECT_TRUE(game.chessboard.board[7][4] == nullptr);
    EXPECT_TRUE(game.chessboard.board[7][0] == nullptr);
    EXPECT_TRUE(game.isWhiteTurn);
}

TEST(Castle, KingSideWhiteKingMoved)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,7}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    king->hasMoved = true;
    Piece* rook = game.chessboard.board[0][7];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.chessboard.board[0][7] == rook);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, KingSideBlackKingMoved)
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,7}, 'r', 'b');
    Piece* king = game.chessboard.board[7][4];
    king->hasMoved = true;
    Piece* rook = game.chessboard.board[7][7];
    vector<vector<int>> move = {{7,4},{7,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_TRUE(game.chessboard.board[7][7] == rook);
    EXPECT_FALSE(game.isWhiteTurn);
}
TEST(Castle, QueenSideWhiteKingMoved)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,0}, 'r', 'w');
    Piece* king = game.chessboard.board[0][4];
    king->hasMoved = true;
    Piece* rook = game.chessboard.board[0][0];
    vector<vector<int>> move = {{0,4},{0,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.chessboard.board[0][0] == rook);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, QueenSideBlackKingMoved) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,0}, 'r', 'b');
    Piece* king = game.chessboard.board[7][4];
    king->hasMoved = true;
    Piece* rook = game.chessboard.board[7][0];
    vector<vector<int>> move = {{7,4},{7,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_TRUE(game.chessboard.board[7][0] == rook);
    EXPECT_FALSE(game.isWhiteTurn);
}

TEST(Castle, KingSideWhiteNoRook)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    Piece* king = game.chessboard.board[0][4];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, KingSideBlackNoRook) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    Piece* king = game.chessboard.board[7][4];
    vector<vector<int>> move = {{7,4},{7,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_FALSE(game.isWhiteTurn);
}
TEST(Castle, QueenSideWhiteNoRook)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    Piece* king = game.chessboard.board[0][4];
    vector<vector<int>> move = {{0,4},{0,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, QueenSideBlackNoRook) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    Piece* king = game.chessboard.board[7][4];
    vector<vector<int>> move = {{7,4},{7,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_FALSE(game.isWhiteTurn);
}

TEST(Castle, KingSideWhitePieceBetween)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,7}, 'r', 'w');
    game.chessboard.addPiece({0,5}, 'n', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][7];
    Piece* knight = game.chessboard.board[0][5];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.chessboard.board[0][7] == rook);
    EXPECT_TRUE(game.chessboard.board[0][5] == knight);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, KingSideBlackPieceBetween) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,7}, 'r', 'b');
    game.chessboard.addPiece({7,6}, 'n', 'b');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][7];
    Piece* knight = game.chessboard.board[7][6];
    vector<vector<int>> move = {{7,4},{7,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_TRUE(game.chessboard.board[7][7] == rook);
    EXPECT_TRUE(game.chessboard.board[7][6] == knight);
    EXPECT_FALSE(game.isWhiteTurn);
}
TEST(Castle, QueenSideWhitePieceBetween)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,0}, 'r', 'w');
    game.chessboard.addPiece({0,1}, 'n', 'w');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][0];
    Piece* knight = game.chessboard.board[0][1];
    vector<vector<int>> move = {{0,4},{0,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.chessboard.board[0][0] == rook);
    EXPECT_TRUE(game.chessboard.board[0][1] == knight);
    EXPECT_TRUE(game.isWhiteTurn);
}
TEST(Castle, QueenSideBlackPieceBetween) 
{
    Game_Manager game = Game_Manager();
    game.isWhiteTurn = false;
    game.chessboard.addPiece({7,4}, 'k', 'b');
    game.chessboard.addPiece({7,0}, 'r', 'b');
    game.chessboard.addPiece({7,3}, 'n', 'b');
    Piece* king = game.chessboard.board[7][4];
    Piece* rook = game.chessboard.board[7][0];
    Piece* knight = game.chessboard.board[7][3];
    vector<vector<int>> move = {{7,4},{7,2}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[7][4] == king);
    EXPECT_TRUE(game.chessboard.board[7][0] == rook);
    EXPECT_TRUE(game.chessboard.board[7][3] == knight);
    EXPECT_FALSE(game.isWhiteTurn);
}

TEST(Castle, PathInCheck)
{
    Game_Manager game = Game_Manager();
    game.chessboard.addPiece({0,4}, 'k', 'w');
    game.chessboard.addPiece({0,7}, 'r', 'w');
    game.chessboard.addPiece({2,5}, 'r', 'b');
    Piece* king = game.chessboard.board[0][4];
    Piece* rook = game.chessboard.board[0][7];
    Piece* blackRook = game.chessboard.board[2][5];
    vector<vector<int>> move = {{0,4},{0,6}};
    ASSERT_FALSE(game.castle(move));
    EXPECT_TRUE(game.chessboard.board[0][4] == king);
    EXPECT_TRUE(game.chessboard.board[0][7] == rook);
    EXPECT_TRUE(game.chessboard.board[2][5] == blackRook);
}

TEST(ValidDestinations, QueenCenter)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'q', 'w');
   Queen* myQueen = dynamic_cast<Queen*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myQueen->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,5},{5,6},{6,7},{2,3},{1,2},{0,1},{4,3},{5,2},{6,1},
   {7,0},{2,5},{1,6},{0,7},{3,0},{3,1},{3,2},{3,3},{3,5},{3,6},{3,7},{0,4},{1,4},{2,4},{4,4},{5,4},{6,4},{7,4}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, QueenPieceInWay)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'q', 'w');
   pos.at(0)=4;
   pos.at(1)=3;
   myBoard.addPiece(pos,'p','w');
   Queen* myQueen = dynamic_cast<Queen*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myQueen->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{4,5},{5,6},{6,7},{2,3},{1,2},{0,1},
   /*{4,3},{5,2},{6,1},{7,0}, 
   (these spaces are no longer valid from previous test)*/
   {2,5},{1,6},{0,7},{3,0},{3,1},{3,2},
   {3,3},{3,5},{3,6},{3,7},{0,4},{1,4},{2,4},{4,4},{5,4},{6,4},{7,4}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, KingCenter)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'k', 'w');
   King* myKing = dynamic_cast<King*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myKing->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{2,3},{2,4},{2,5},{3,3},{3,5},{4,3},{4,4},{4,5}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, KingPieceInWay)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'k', 'w');
   pos.at(0)=4;
   pos.at(1)=3;
   myBoard.addPiece(pos,'p','w');   
   King* myKing = dynamic_cast<King*>(myBoard.board[3][4]);
   vector<vector<int>> allMoves = myKing->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{2,3},{2,4},{2,5},{3,3},{3,5},/*{4,3},*/{4,4},{4,5}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(Check, inCheck)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'k', 'w');
   pos.at(0)=4;
   pos.at(1)=3;
   myBoard.addPiece(pos,'q','b');   
   King* myKing = dynamic_cast<King*>(myBoard.board[3][4]);
   EXPECT_TRUE(myKing->inCheck(myBoard.board));
}
TEST(Check, notCheck)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(4);
   myBoard.addPiece(pos, 'k', 'w');
   pos.at(0)=5;
   pos.at(1)=5;
   myBoard.addPiece(pos,'q','b');   //this piece cant check king
   King* myKing = dynamic_cast<King*>(myBoard.board[3][4]);
   EXPECT_FALSE(myKing->inCheck(myBoard.board));
}
TEST(ValidDestinations, whitePawn)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(1);
   pos.push_back(1);
   myBoard.addPiece(pos, 'p', 'w');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[1][1]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{3,1},{2,1}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, blackPawn)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(6);
   pos.push_back(6);
   myBoard.addPiece(pos, 'p', 'b');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[6][6]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{5,6},{4,6}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, whitePawnMoved)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(1);
   pos.push_back(1);
   myBoard.addPiece(pos, 'p', 'w');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[1][1]);
   myPawn->hasMoved = true;
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{2,1}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, blackPawnMoved)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(6);
   pos.push_back(6);
   myBoard.addPiece(pos, 'p', 'b');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[6][6]);
   myPawn->hasMoved = true;
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{5,6}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, whitePawnCapture)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(1);
   pos.push_back(1);
   myBoard.addPiece(pos, 'p', 'w');
   pos.at(0) = 2;
   pos.at(1) = 2;
   myBoard.addPiece(pos, 'p', 'b');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[1][1]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{3,1},{2,1},{2,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, blackPawnCapture)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(6);
   pos.push_back(6);
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 5;
   pos.at(1) = 7;
   myBoard.addPiece(pos, 'p', 'w');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[6][6]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{5,6},{4,6},{5,7}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, whitePawnBounds)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(7);
   pos.push_back(7);
   myBoard.addPiece(pos, 'p', 'w');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[7][7]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, blackPawnBounds)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(1);
   pos.push_back(0);
   myBoard.addPiece(pos, 'p', 'b');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[1][0]);
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{0,0}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, blackPawnCaptureAndMoved)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(6);
   pos.push_back(6);
   myBoard.addPiece(pos, 'p', 'b');
   pos.at(0) = 5;
   pos.at(1) = 7;
   myBoard.addPiece(pos, 'p', 'w');
   Pawn* myPawn = dynamic_cast<Pawn*>(myBoard.board[6][6]);
   myPawn->hasMoved = true;
   vector<vector<int>> allMoves = myPawn->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{5,6},{5,7}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}

TEST(ValidDestinations, Knight)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(3);
   pos.push_back(3);
   myBoard.addPiece(pos, 'n', 'w');
   Knight* myKnight = dynamic_cast<Knight*>(myBoard.board[3][3]);
   vector<vector<int>> allMoves = myKnight->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{5,4},{5,2},{1,4},{1,2},{4,5},{4,1},{2,5},{2,1}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, KnightCorner)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(0);
   pos.push_back(0);
   myBoard.addPiece(pos, 'n', 'b');
   Knight* myKnight = dynamic_cast<Knight*>(myBoard.board[0][0]);
   vector<vector<int>> allMoves = myKnight->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{2,1},{1,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(ValidDestinations, KnightEdge)
{
   Chess_Board myBoard = Chess_Board();
   vector<int> pos;
   pos.push_back(4);
   pos.push_back(0);
   myBoard.addPiece(pos, 'n', 'b');
   Knight* myKnight = dynamic_cast<Knight*>(myBoard.board[4][0]);
   vector<vector<int>> allMoves = myKnight->validDestinations(myBoard.board);
   vector<vector<int>> matcher = {{6,1},{5,2},{2,1},{3,2}};
   EXPECT_THAT(allMoves, testing::UnorderedElementsAreArray<vector<vector<int>>>(matcher));
}
TEST(GetDisplayChar, WhiteKnight)
{
    Knight myKnight = Knight('w', {0,0});
    EXPECT_EQ(myKnight.getDisplayChar(), "♞");
}  
TEST(GetDisplayChar, BlackKnight)
{
    Knight myKnight = Knight('b', {0,0});
    EXPECT_EQ(myKnight.getDisplayChar(), "♘");
}
TEST(GetDisplayChar, WhitePawn)
{
    Pawn myPawn = Pawn('w', {0,0});
    EXPECT_EQ(myPawn.getDisplayChar(), "♟︎");
}  
TEST(GetDisplayChar, BlackPawn)
{
    Pawn myPawn = Pawn('b', {0,0});
    EXPECT_EQ(myPawn.getDisplayChar(), "♙");
}
TEST(GetDisplayChar, WhiteBishop)
{
    Bishop myBishop = Bishop('w', {0,0});
    EXPECT_EQ(myBishop.getDisplayChar(), "♝");
}  
TEST(GetDisplayChar, BlackBishop)
{
    Bishop myBishop = Bishop('b', {0,0});
    EXPECT_EQ(myBishop.getDisplayChar(), "♗");
}
TEST(GetDisplayChar, WhiteRook)
{
    Rook myRook = Rook('w', {0,0});
    EXPECT_EQ(myRook.getDisplayChar(), "♜");
}  
TEST(GetDisplayChar, BlackRook)
{
    Rook myRook = Rook('b', {0,0});
    EXPECT_EQ(myRook.getDisplayChar(), "♖");
}    
TEST(GetDisplayChar, WhiteKing)
{
    King king = King('w', {0,0});
    EXPECT_EQ(king.getDisplayChar(), "♚");
}
TEST(GetDisplayChar, BlackKing)
{
    King king = King('b', {0,0});
    EXPECT_EQ(king.getDisplayChar(), "♔");
}
TEST(GetDisplayChar, WhiteQueen)
{
    Queen queen = Queen('w', {0,0});
    EXPECT_EQ(queen.getDisplayChar(), "♛");
}
TEST(GetDisplayChar, BlackQueen)
{
    Queen queen = Queen('b', {0,0});
    EXPECT_EQ(queen.getDisplayChar(), "♕");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
