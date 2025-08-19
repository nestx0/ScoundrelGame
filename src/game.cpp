#include "../includes/game.hpp"
#include <iostream>

Game::Game(const Player &player, const Deck &deck){
    _player = player;
    _deck = deck;
    _gameOver = false;
}
Deck Game::getDeck() const{
    return _deck;
}
bool Game::getState() const{
    return _gameOver;
}
void Game::displayRoom() const{
    std::cout << "========== FLOOR " << _player.getFloors() + 1 << " ==========" << std::endl;
    for(int i = 0; i < _currentCards.size(); i++){
        std::cout << _currentCards[i].toString() << "   "; 
    }
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
    _currentCards.clear();
    for(int i = _currentCards.size(); i < 4; i++){
        _currentCards.push_back(_deck.draw());
    }
}
void Game::playTurn(){
    
}