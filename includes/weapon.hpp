#include "../includes/card.hpp"
#include <memory>
#include <stack>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon{
private:
    std::unique_ptr<Card> _weapon;
    int _maxDurability, _reducedDamage;
    std::stack<Card> _enemiesDefeated;

public:
    Weapon();
    Weapon(const Card &card);

    Card getCard() const;
    int getMaxDurability() const;
    int getReducedDamage() const;
    void setMaxDurability(const Card &other);
    bool hasValue() const;

    bool anyEnemiesDefeated() const;
    bool isAbleToDefend(const Card &card) const;
    void updateDurability(const Card &face); // In case of encountering a diamond face card with enemies defeated
    void upgradeReducedDamage(const Card &face); // In case of encountering a diamod face car / ace w/o defeated enemies
    void addEnemyDefeated(const Card& enemy);
};



#endif