#include "game_state.h"

std::ostream& operator<<(std::ostream& os, const GameState& gameState)
{
    bool won = false;
    bool lost = false;

    if (gameState.won.has_value() && gameState.won.value())
        won = true;
    if (gameState.lost.has_value() && gameState.lost.value())
        lost = true;

    os << "won=" << won << ", lost=" << lost;
    os << ", score=" << gameState.score;

    return os;
}
