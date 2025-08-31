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

    int getHP() const;
    int getFloors() const;
    Weapon *getWeapon() const;

    void recoverHP(const Card &card);
    void addFloorCompleted();
    void changeWeapon(const Card &card);

    void defeatWithWeapon(const Card &card);
    void takeDamage(int damage);

    Player &operator=(const Player &other);
};