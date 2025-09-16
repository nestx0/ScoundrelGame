#include "card.hpp"
#include <queue>

#ifndef DECK_H
#define DECK_H

class Deck
{
private:
    std::deque<Card> _deck;

public:
    Deck(); // Default Constructor

    void shuffle();
    Card at(int index) const;
    int size() const;
    Card draw();
    void addCardBack(const Card &card);
    bool isEmpty() const;
};

#endif