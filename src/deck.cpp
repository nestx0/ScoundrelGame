#include "../includes/deck.hpp"
#include "../includes/card.hpp"
#include <algorithm>
#include <chrono>
#include <queue>
#include <random>

const Suit ALL_SUITS[4] = {Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades};
const Rank ALL_RANKS[13] = {Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six,
                            Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King};

Deck::Deck()
{
    for (const auto suit : ALL_SUITS)
    {
        for (const auto rank : ALL_RANKS)
        {
            std::shared_ptr<CardBehavior> behavior = nullptr;
            if (rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King || rank == Rank::Ace)
            {
                if (suit == Suit::Hearts)
                    behavior = std::make_shared<MerchantBehavior>();
                else if (suit == Suit::Diamonds)
                    behavior = std::make_shared<BlacksmithBehavior>();
            }
            _deck.push_front(Card(rank, suit, behavior));
        }
    }
    shuffle();
};
void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(_deck.begin(), _deck.end(), g);
}
Card Deck::draw()
{
    Card front = _deck.front();
    _deck.pop_front();
    return front;
}
void Deck::addCardBack(const Card &card)
{
    _deck.push_back(card);
}
bool Deck::isEmpty() const
{
    return _deck.empty();
}