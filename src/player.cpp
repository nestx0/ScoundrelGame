#include "../includes/card.hpp"
#include "../includes/weapon.hpp"
#include "../includes/player.hpp"
#include <assert.h>
#include <iostream>

int Player::getHP() const
{
    return _healthPoints;
}
int Player::getFloors() const
{
    return _floorsCompleted;
}
Weapon* Player::getWeapon() const
{
    return _weapon.get();
}

void Player::recoverHP(const Card &card)
{
    if (card.getValue() > 1 && card.getValue() < 11 && (card.getSuit() == Suit::Hearts || card.getSuit() == Suit::Diamonds))
    {
        _healthPoints += card.getValue();
    }
    if (_healthPoints > 20)
    {
        _healthPoints = 20;
    }
}

void Player::addFloorCompleted()
{
    _floorsCompleted++;
}
void Player::changeWeapon(const Card &card)
{
    if (card.getSuit() != Suit::Diamonds)
        _weapon = nullptr;
    else
        _weapon = std::make_unique<Weapon>(card);
}

void Player::defeatWithWeapon(const Card &card)
{
    if (_weapon->hasValue())
    {
        _weapon->addEnemyDefeated(card);
        _weapon->setMaxDurability(card);
    }
}

Player &Player::operator=(const Player &other)
{

    if (this != &other)
    {
        _healthPoints = other.getHP();
        _floorsCompleted = other.getFloors();
        if (other.getWeapon())
            _weapon = std::make_unique<Weapon>(other.getWeapon()->getCard());
        else
            _weapon = nullptr;
    }

    return *this;
}
void Player::takeDamage(const Card &card)
{
    _healthPoints -= card.getValue();
}