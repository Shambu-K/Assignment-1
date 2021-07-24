#ifndef _FALCON_H
#define _FALCON_H
#include "AI/AI.h"
#include <utility>
#include <deque>

using mini = std::pair<int, std::pair<unsigned, unsigned>>;
using move = std::pair<unsigned, unsigned>;
using moves = std::vector<std::pair<unsigned int,unsigned int>>;

class ai
{
public:
    // Public methods. Methods for interacting with the AI and its different
    // components.
    move  evaluateMove();
    void  setAiColor(piece color);
    void  setCurrentGame(OthelloBoard newGame);
    piece getAiColor() const;
    int getSearchDepth(OthelloBoard _game);
    void  setSearchDepth(unsigned int searchDepth);
    
private:
    // The alphabeta algorithm with alpha-beta prunings.
    mini alphaBeta(OthelloBoard node,
                   int depth,
                   bool maximizingPlayer,
                   piece maximizingColor,
                   int alpha,
                   int beta,
                   move moveMade,
                   bool lateGame);

    // Heurisitc valuing functions.
    int heuristicValue(OthelloBoard _game, piece maximizingColor);
    int mobilityTester(OthelloBoard _game, piece maximizingColor);
    int cornerTester(OthelloBoard _game, piece maximizingColor);
    int fieldTester(OthelloBoard _game, piece maximizingColor);
    int tileWeight(unsigned int x, unsigned int y, OthelloBoard _game, piece maximizingColor);


    // Other private methods.
    piece reverseColor(piece color) ;
    mini  makeMini(int value, unsigned int x, unsigned int y) const;
  

private:
    // Ai local field variables.
    OthelloBoard     _currentGame{};
    piece    _aiColor{ piece::WHITE };
    unsigned _moveCount{ 0 };
    unsigned _searchDepth{ 7 };
};




#endif