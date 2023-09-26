#ifndef HARDCOREMODE_H
#define HARDCOREMODE_H

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
