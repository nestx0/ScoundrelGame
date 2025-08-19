#include "../includes/player.hpp"
#include "../includes/deck.hpp"
#include <vector>

#ifndef GAME_H
#define GAME_H 

class Game{
private:
    Player _player;
    Deck _deck;
    bool _gameOver;
    std::vector<Card> _currentCards;

public:
    Game(const Player &player, const Deck &deck);

    //Player getPlayer() const;
    Deck getDeck() const;
    bool getState() const;

    void run() const;
    void displayRoom() const;
    void startRoom();
    void playTurn();
    bool floorCompleted() const;
};

#endif