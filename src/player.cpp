#include "../includes/card.hpp"
#include "../includes/weapon.hpp"
#include "../includes/player.hpp"
#include <assert.h>

int Player::getHP() const{
    return _healthPoints;
}
int Player::getFloors() const{
    return _floorsCompleted;
}
Weapon* Player::getWeapon() const{
    assert(_weapon->hasValue());
    return _weapon.get();
}

void Player::recoverHP(const Card &card){
    if(card.getValue() > 1 && card.getValue() < 11 && card.getSuit() == Suit::Hearts){
        _healthPoints += card.getValue();
    }
    if(_healthPoints > 20){
        _healthPoints = 20;
    }
}

void Player::addFloorCompleted(){
    _floorsCompleted++;
}
void Player::changeWeapon(const Card &card){
    _weapon = std::make_unique<Weapon>(card);
}

void Player::defeatWithWeapon(const Card &card){
    if(_weapon->hasValue()){
        _weapon->addEnemyDefeated(card);
        _weapon->setMaxDurability(card);
    }
}