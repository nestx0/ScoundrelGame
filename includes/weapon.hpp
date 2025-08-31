#include "../includes/card.hpp"
#include <memory>
#include <stack>

#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
private:
    std::unique_ptr<Card> _weapon;
    int _maxDurability, _reducedDamage;
    std::stack<Card> _enemiesDefeated;

public:
    /*
     * @brief Default Constructor
     */
    Weapon();

    /*
     * @brief Parameter Constructor
     * @param card The card needed to initialize the weapon
     */
    Weapon(const Card &card);

    /*
     * @brief Returns the card the weapon is using
     */
    Card getCard() const;
    /*
     * @brief Returns the max damage it has taken
     */
    int getMaxDurability() const;
    /*
     * @brief Returns the damage reduced the weapon is providing
     */
    int getReducedDamage() const;

    /*
     * @brief Returns the stack of enemies defeated
     */
    std::stack<Card> getEnemiesDefeated() const;
    /*
     * @brief Updates the max damage it has taken
     * @param The card used to set the damage
     */
    void setMaxDurability(const Card &other);
    /*
     * @brief Returns false in case _weapon is null
     */
    bool hasValue() const;
    /*
     * @brief Returns false if _enemiesDefeated is empty
     */
    bool anyEnemiesDefeated() const;
    /*
     * @brief Returns false if card passed is greater than _maxDurability
     */
    bool isAbleToDefend(const Card &card) const;
    /// In case of encountering a diamond face card with enemies defeated
    void updateDurability(const Card &face);
    /// In case of encountering a diamod face car / ace w/o defeated enemies
    void upgradeReducedDamage(const Card &face);
    /*
     * @brief Adds the card of the enemy to the stack of _enemiesDefeated
     */
    void addEnemyDefeated(const Card &enemy);

    void showEnemiesDefeated() const;
};

#endif