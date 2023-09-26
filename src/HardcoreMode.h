#ifndef HARDCOREMODE_H
#define HARDCOREMODE_H

#include "Module.h" // Include the Module.h header
#include "Player.h" // Include the Player.h header

class HardcoreModeModule : public Module
{
public:
    HardcoreModeModule();
    virtual ~HardcoreModeModule();

    // Add your module-specific members and functions here

    // Override necessary Module functions
    virtual void OnInstall() override;
    virtual void OnUpdate(uint32 diff) override;
    virtual void OnConfigLoad(const ConfigEntry* /*entry*/) override;

    // Add the original member functions
    void OnCharacterDeath(Player* player, const char* causeOfDeath);
    void SendDeathMessage(Player* player, const char* causeOfDeath);
};

#endif // HARDCOREMODE_H
