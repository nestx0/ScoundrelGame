#include "../includes/card.hpp"
#include "../includes/weapon.hpp"
#include <memory>

class Player
{
private:
    const int MAX_HP = 20;
    int _healthPoints, _floorsCompleted;
    std::unique_ptr<Weapon> _weapon;

public:
    Player() : _healthPoints(MAX_HP), _floorsCompleted(0), _weapon(std::make_unique<Weapon>()) {};
    /*
     * @brief Gets the current player's healthpoints
     */
    int getHP() const;
    /*
     * @brief Gets the number of floors completed by the player
     */
    int getFloors() const;
    /*
     * @brief Gets a pointer to the weapon the player is using
     */
    Weapon *getWeapon() const;
    /*
     * @brief Recovers healhpoints given any hearts card
     */
    void recoverHP(const Card &card);
    /*
     * @brief Adds 1 to the floors completed
     */
    void addFloorCompleted();
    /*
     * @brief Changes the current weapon to a new one, if it's not a diamond card, _weapon is set to nullptr
     */
    void changeWeapon(const Card &card);
    /*
     * @brief Logic for when the player decides to defend with their weapon
     */
    void defeatWithWeapon(const Card &card);
    /*
     * @brief Logic for when the player takes damage
     */
    void takeDamage(int damage);
    /*
     * @brief Operator to copy players, kind of unneeded
     */
    Player &operator=(const Player &other);
};