#pragma once

#include "Module.h" // Include the Module.h header

class HardcoreModeModule : public Module
{
public:
    void OnCharacterDeath(Player* player, const char* causeOfDeath);
    void SendDeathMessage(Player* player, const char* causeOfDeath);
};

extern HardcoreModeModule* g_HardcoreModeModule;
