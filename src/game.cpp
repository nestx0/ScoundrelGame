#include "../includes/game.hpp"
#include <iostream>

Game::Game(const Player &player, const Deck &deck)
{
    _player = player;
    _deck = deck;
    _gameOver = false;
    _alreadyHealed = false;
    _ableToFlee = true;
    _floorCompleted = false;
}
Deck Game::getDeck() const
{
    return _deck;
}
bool Game::getState() const
{
    return _gameOver;
}
void Game::displayCurrentCards() const
{
    for (int i = 0; i < _currentCards.size(); i++)
    {
        std::cout << _currentCards[i].toString() << "   ";
    }
}
void Game::displayRoom() const
{
    std::cout << "========== FLOOR " << _player.getFloors() + 1 << " ==========" << std::endl;
    displayCurrentCards();
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Healthpoints: " << _player.getHP() << std::endl;
    std::cout << "Weapon: ";
    if (_player.getWeapon())
    {
        std::cout << _player.getWeapon()->getCard().toString();
    }
    else
    {
        std::cout << "null";
    }
    std::cout << std::endl;
}
void Game::startRoom()
{
    _alreadyHealed = false;
    for (int i = _currentCards.size(); i < 4; i++)
    {
        _currentCards.push_back(_deck.draw());
    }
}
Card Game::chooseCard()
{
    int option;
    std::cout << "Choose your option" << std::endl;
    std::cin >> option;

    if (option > 0 && option <= _currentCards.size())
    {
        Card chosen(_currentCards[option - 1]);
        _currentCards.erase(_currentCards.begin() + option - 1);
        return chosen;
    }
    else
    {
        throw std::invalid_argument("Not an choosable playing card");
    }
}
void Game::handleCard(const Card &card)
{
    switch (card.getSuit())
    {
    case Suit::Hearts:
        if (_alreadyHealed == true)
            break;
        else
        {
            _player.recoverHP(card);
            _alreadyHealed = true;
            break;
        }
    case Suit::Diamonds:
        _player.changeWeapon(card);
        break;
    case Suit::Clubs:
    case Suit::Spades:
        handleDamage(card);
        break;
    default:
        break;
    }
}

void Game::handleDamage(const Card &card)
{

    char option;

    if (_player.getWeapon() != nullptr)
    {
        std::cout << "Do you want to defend? (Y/N)" << std::endl;
        std::cin >> option;
        if (option == 'Y')
        {
            _player.defeatWithWeapon(card);
        }
        else
        {
            _player.takeDamage(card);
        }
    }
    else
    {
        _player.takeDamage(card);
    }

    if (_player.getHP() <= 0)
    {
        _gameOver = true;
    }
}
void Game::handleSpecialCard(const Card &card)
{
    auto behavior = card.getBehavior();
    if (behavior)
    {
        behavior->applyEffect(_player, card);
    }
}

bool Game::floorCompleted()
{
    if (_currentCards.size() <= 1 && !_deck.isEmpty())
    {
        _floorCompleted = true;
    }
    else if (_currentCards.size() > 1)
    {
        _floorCompleted = false;
    }
    else
    {
        if (_currentCards.size() == 0)
        {
            _floorCompleted = true;
            _gameOver = true;
            _gameWon = true;
        }
    }
    return _floorCompleted;
}

void Game::flee()
{
    if (_ableToFlee)
    {
        for (int i = 0; i < _currentCards.size(); i++)
        {
            _deck.addCardBack(_currentCards[i]);
        }
        _currentCards.clear();
        _ableToFlee = false;
    }
}

bool Game::askForFlee() const
{
    if (_ableToFlee)
    {
        char o;
        std::cout << "Want to flee? (Y/N)" << std::endl;
        std::cin >> o;
        if (o == 'Y')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void Game::run()
{

    Card option;
    char o;

    while (!_gameOver)
    {
        startRoom();
        while (!floorCompleted())
        {
            if (askForFlee())
                flee();
            else
            {
                option = chooseCard();
                if (option.getBehavior())
                {
                    handleSpecialCard(option);
                }
                else
                {
                    handleCard(option);
                }
            }
        }
    }
}