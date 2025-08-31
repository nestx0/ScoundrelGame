#include "../includes/weapon.hpp"
#include "../includes/card.hpp"
#include <iostream>
#include <vector>

Weapon::Weapon()
{
    _weapon = nullptr;
    _maxDurability = 15;
    _reducedDamage = 0;
};

Weapon::Weapon(const Card &card)
{
    if (card.getSuit() == Suit::Diamonds)
    {
        _weapon = std::make_unique<Card>(card);
        _maxDurability = 15;
        _reducedDamage = _weapon->getValue();
    }
    else
    {
        _weapon = nullptr;
        _maxDurability = 15;
        _reducedDamage = 0;
    }
};

std::stack<Card> Weapon::getEnemiesDefeated() const
{
    return _enemiesDefeated;
}
Card Weapon::getCard() const
{
    if (!_weapon)
    {
        throw std::runtime_error("Weapon has no card");
    }
    return *_weapon;
}
int Weapon::getMaxDurability() const
{
    return _maxDurability;
}
int Weapon::getReducedDamage() const
{
    return _reducedDamage;
}
void Weapon::setMaxDurability(const Card &other)
{
    if (hasValue())
        _maxDurability = other.getValue();
}
bool Weapon::isAbleToDefend(const Card &card) const
{
    return this->_maxDurability > card.getValue();
}
bool Weapon::anyEnemiesDefeated() const
{
    return !_enemiesDefeated.empty();
}
bool Weapon::hasValue() const
{
    return _weapon != nullptr;
}
void Weapon::updateDurability(const Card &face)
{
    if (anyEnemiesDefeated())
    {
        switch (face.getRank())
        {
        case Rank::Jack:
            _enemiesDefeated.pop();
            break;

        case Rank::Queen:
            for (int i = 0; i < 2 && anyEnemiesDefeated(); i++)
            {
                _enemiesDefeated.pop();
            }
            break;

        case Rank::King:
            for (int i = 0; i < 3 && anyEnemiesDefeated(); i++)
            {
                _enemiesDefeated.pop();
            }
            break;

        case Rank::Ace:
            for (int i = 0; i < 4 && anyEnemiesDefeated(); i++)
            {
                _enemiesDefeated.pop();
            }
            break;

        default:
            break;
        }
    }
}
void Weapon::upgradeReducedDamage(const Card &face)
{
    if (!anyEnemiesDefeated())
    {
        switch (face.getRank())
        {
        case Rank::Jack:
            _reducedDamage++;
            break;

        case Rank::Queen:
            _reducedDamage += 2;
            break;

        case Rank::King:
            _reducedDamage += 3;
            break;

        case Rank::Ace:
            _reducedDamage += 4;
            break;

        default:
            break;
        }
    }
}

void Weapon::addEnemyDefeated(const Card &enemy)
{
    _enemiesDefeated.push(enemy);
}
void Weapon::showEnemiesDefeated() const
{
    std::vector<Card> temp;
    for (int i = 0; i < _enemiesDefeated.size(); i++)
    {
        temp.push_back(_enemiesDefeated.top());
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        std::cout << temp[i].toString();
    }
}