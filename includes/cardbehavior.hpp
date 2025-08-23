
#ifndef CARDBEHAVIOR_H
#define CARDBEHAVIOR_H

class Card;
class Player;

class CardBehavior
{
public:
    virtual void applyEffect(Player &player, const Card &card) = 0;
    virtual ~CardBehavior() = default;
};
class BlacksmithBehavior : public CardBehavior
{
public:
    void applyEffect(Player &player, const Card &card) override;
};
class MerchantBehavior : public CardBehavior
{
public:
    void applyEffect(Player &player, const Card &card) override;
};

#endif
