#include "card.hpp"
#include <queue>


#ifndef DECK_H
#define DECK_H

class Deck{
private:
    std::deque<Card> _deck;

public:
    Deck(); // Default Constructor

    void suffle();
    Card draw();
    void addCardBack(const Card &card);

};

#endif