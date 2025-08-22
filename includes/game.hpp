#include "../includes/player.hpp"
#include "../includes/deck.hpp"
#include <vector>

#ifndef GAME_H
#define GAME_H 

class Game{
private:
    Player _player;
    Deck _deck;
    bool _gameOver, _alreadyHealed, _ableToFlee;
    std::vector<Card> _currentCards;

public:
    Game(const Player &player, const Deck &deck);

    //Player getPlayer() const;
    Deck getDeck() const;
    bool getState() const;

    void run();
    void flee();
    void displayRoom() const;
    void displayCurrentCards() const;
    void startRoom();
    bool floorCompleted() const;
    Card chooseCard() const;

    void handleCard(const Card &card);
    void handleSpecialCard(const Card &card);
    void handleDamage(const Card &card);
};

#endif