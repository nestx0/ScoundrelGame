#include "../includes/cardbehavior.hpp"
#include <string>
#include <memory>

#ifndef CARDS_H
#define CARDS_H

enum class Suit
{
    Hearts,
    Spades,
    Clubs,
    Diamonds
};
enum class Rank
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

class Card
{

private:
    Rank _rank;
    Suit _suit;
    std::shared_ptr<CardBehavior> _behavior;

public:
    Card(Rank r, Suit s) : _rank(r), _suit(s), _behavior(nullptr) {}; // Parameter Constructor
    Card() : _rank(Rank::Five), _suit(Suit::Spades), _behavior(nullptr) {};
    Card(const Card &other) : _rank(other.getRank()), _suit(other.getSuit()), _behavior(other.getBehavior()) {};

    Suit getSuit() const;
    Rank getRank() const;
    int getValue() const;
    std::shared_ptr<CardBehavior> getBehavior() const;

    void setBehavior(std::shared_ptr<CardBehavior> behavior);
    std::string toString() const;

    bool operator<(const Card &other) const;
};

std::string rankToString(Rank _rank);
std::string suitToString(Suit _suit);

#endif