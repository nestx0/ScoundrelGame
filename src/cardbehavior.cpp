#include "../includes/cardbehavior.hpp"
#include "../includes/player.hpp"

void BlacksmithBehavior::applyEffect(Player &player, const Card &card)
{

    if (player.getWeapon() != nullptr)
    {
        if (player.getWeapon()->anyEnemiesDefeated())
        {
            player.getWeapon()->updateDurability(card);
        }
        else
        {
            player.getWeapon()->upgradeReducedDamage(card);
        }
    }
}
void MerchantBehavior::applyEffect(Player &player, const Card &card)
{
    player.recoverHP(player.getWeapon()->getCard());
    player.changeWeapon(card); // We pass a non-posible weapon to set it to nullptr
}
