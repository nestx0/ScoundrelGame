
#ifndef CARDS_H
#define CARDS_H

enum class Suit {Hearts, Spades, Clubs, Diamonds};
enum class Rank {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card{

private:
    Rank _rank;
    Suit _suit;
public:
    Card(Rank r, Suit s): _rank(r), _suit(s){}; //Parameter Constructor

    Suit getSuit() const;
    Rank getRank() const;
    int getValue() const;

    bool operator<(const Card &other) const;
        
};

#endif