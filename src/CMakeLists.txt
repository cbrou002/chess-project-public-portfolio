add_executable(chess
    bishop.cpp
    Chess_Board.cpp
    File_Manager.cpp
    Game_Manager.cpp
    king.cpp
    knight.cpp
    pawn.cpp
    queen.cpp
    rook.cpp
    main.cpp
)

add_library(simpleLibrary
  bishop.cpp
  Chess_Board.cpp
  File_Manager.cpp
  Game_Manager.cpp
  king.cpp
  knight.cpp
  pawn.cpp
  queen.cpp
  rook.cpp 
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})
