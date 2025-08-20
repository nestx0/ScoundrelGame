#include "../includes/game.hpp"
#include <iostream>

Game::Game(const Player &player, const Deck &deck){
    _player = player;
    _deck = deck;
    _gameOver = false;
    _alreadyHealed = false;
}
Deck Game::getDeck() const{
    return _deck;
}
bool Game::getState() const{
    return _gameOver;
}
void Game::displayCurrentCards() const{
    for(int i = 0; i < _currentCards.size(); i++){
        std::cout << _currentCards[i].toString() << "   "; 
    }
}
void Game::displayRoom() const{
    std::cout << "========== FLOOR " << _player.getFloors() + 1 << " ==========" << std::endl;
    displayCurrentCards();
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Healthpoints: " << _player.getHP() << std::endl;
    std::cout << "Weapon: ";
    if(_player.getWeapon()){
        std::cout << _player.getWeapon()->getCard().toString();
    }
    else{
        std::cout << "null";
    }
    std::cout << std::endl;
}
void Game::startRoom(){
    _alreadyHealed = false;
    for(int i = _currentCards.size(); i < 4; i++){
        _currentCards.push_back(_deck.draw());
    }
}
Card Game::chooseCard() const{
    int option;
    std::cout << "Choose your option" << std::endl;
    std::cin >> option;

    if(option > 0 && option <= _currentCards.size()){
        return _currentCards[option];
    }
    else{
        throw std::invalid_argument("Not an choosable playing card");
    }
}
void Game::handleCard(const Card &card){
    switch (card.getSuit())
    {
    case Suit::Hearts:
        if(_alreadyHealed == true)
            break;
        else{
            _player.recoverHP(card);
            _alreadyHealed = true;
            break;
        }
    case Suit::Diamonds:
        _player.changeWeapon(card);
        break;
    case Suit::Clubs:
        handleDamage(card);
        break;
    case Suit::Spades:
        handleDamage(card);
        break;
    default:
        break;
    }
}

void Game::handleDamage(const Card &card){

    char option;

    if(_player.getWeapon() != nullptr){
        std::cout << "Do you want to defend? (Y/N)" << std::endl;
        std::cin >> option;
        if(option == 'Y'){
            _player.defeatWithWeapon(card);
        }
        else{
            _player.takeDamage(card);
        }
    }
    else{
        _player.takeDamage(card);
    }
}
void Game::handleSpecialCard(const Card &card){
    auto behavior = card.getBehavior();
    if(behavior){
        behavior->applyEffect(_player, card);
    }
}