#include "../includes/player.hpp"
#include "../includes/deck.hpp"
#include <vector>

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Player _player;
    Deck _deck;
    bool _gameOver, _alreadyHealed, _ableToFlee, _floorCompleted, _gameWon;
    std::vector<Card> _currentCards;

public:
    Game();
    Game(const Player &player, const Deck &deck);

    // Player getPlayer() const;
    /*
     * @brief Gets the current deck
     */
    Deck getDeck() const;
    /*
     * @brief Gets the state of the game, if it's over or not
     */
    bool getState() const;
    /*
     * @brief Runs the game, it will be changed
     */
    void run();
    /*
     * @brief Logic for the player to escape from the current room
     */
    void flee();
    /*
     * @brief Shows everything in the room, it will be changed
     */
    void displayRoom() const;
    /*
     * @brief Shows only the current cards
     */
    void displayCurrentCards() const;
    /*
     * @brief Creates a new room
     */
    void startRoom();
    /*
     * @brief Asks the player if they want to run away
     */
    bool askForFlee() const;
    /*
     * @brief Checks if the current floor is finished
     */
    bool floorCompleted();
    /*
     * @brief Gets the chosen card by the player
     */
    Card chooseCard();
    /*
     * @brief Decides what to do when a given card is chosen
     */
    void handleCard(const Card &card);
    /*
     * @brief Decides what to do if its a special card
     */
    void handleSpecialCard(const Card &card);
    /*
     * @brief Used to take damage and calculate the game state
     */
    void handleDamage(const Card &card);
};

#endif