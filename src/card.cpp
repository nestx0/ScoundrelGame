#include "../includes/card.hpp"

Suit Card::getSuit() const{
    return _suit;
}
Rank Card::getRank() const{
    return _rank;
}
int Card::getValue() const{
    switch (_rank)
    {
        case Rank::Ace: return 14;
        case Rank::Two: return 2;
        case Rank::Three: return 3;
        case Rank::Four: return 4;
        case Rank::Five: return 5;
        case Rank::Six: return 6;
        case Rank::Seven: return 7;
        case Rank::Eight: return 8;
        case Rank::Nine: return 9;
        case Rank::Ten: return 10;
        case Rank::Jack: return 11;
        case Rank::Queen: return 12;
        case Rank::King: return 13;
        default: return 0;
    }
}

bool Card::operator<(const Card &other) const{
    return this->getValue() < other.getValue();
}

std::shared_ptr<CardBehavior> Card::getBehavior() const{
    return _behavior;
}

std::string Card::toString() const{
    return rankToString(_rank) + " " + suitToString(_suit);
}


std::string rankToString(Rank _rank){
    switch (_rank)
    {
    case Rank::Ace: return "A";
    case Rank::Two: return "2";
    case Rank::Three: return "3";
    case Rank::Four: return "4";
    case Rank::Five: return "5";
    case Rank::Six: return "6";
    case Rank::Seven: return "7";
    case Rank::Eight: return "8";
    case Rank::Nine: return "9";
    case Rank::Ten: return "10";
    case Rank::Jack: return "J";
    case Rank::Queen: return "Q";
    case Rank::King: return "K";
    default: return "?";
    }
}
std::string suitToString(Suit _suit){
    switch(_suit) {
        case Suit::Hearts:   return "\u2665"; // ♥
        case Suit::Spades:   return "\u2660"; // ♠
        case Suit::Clubs:    return "\u2663"; // ♣
        case Suit::Diamonds: return "\u2666"; // ♦
        default: return "?";
    }
}
