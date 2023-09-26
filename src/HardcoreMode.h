#pragma once

#include "Player.h" // Include the Player.h header

class HardcoreModeModule : public Module
{
public:
    void OnCharacterDeath(Player* player, const char* causeOfDeath);
    void SendDeathMessage(Player* player, const char* causeOfDeath);
};

extern HardcoreModeModule* g_HardcoreModeModule;
