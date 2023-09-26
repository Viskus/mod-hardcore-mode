#include "HardcoreMode.h"
#include "Player.h"
#include "Log.h"
#include "Config.h" // Include the Config.h header

HardcoreModeModule* g_HardcoreModeModule;

void HardcoreModeModule::OnCharacterDeath(Player* player, const char* causeOfDeath)
{
    if (player)
    {
        // Check if the module is enabled in the configuration file.
        if (!sConfigMgr->GetBoolDefault("HardcoreMode.Enabled", true))
        {
            // The module is disabled, so we do nothing.
            return;
        }

        // Implement your permanent death logic here.
        // For example, you can delete the character's data from the database.
        // Make sure to log the event for reference.
        sLog->out("Character %s has died permanently due to %s.", player->GetName(), causeOfDeath);

        // Send a server-wide death message.
        SendDeathMessage(player, causeOfDeath);

        // Prevent the character from resurrecting.
        player->GetSession()->SendNotification("You are dead and cannot resurrect.");

        // Set the character as a ghost forever.
        player->SetUInt32Value(UNIT_FIELD_HEALTH, 0); // Set health to 0
        player->SetUInt32Value(UNIT_FIELD_STAT0, 0); // Set all stats to 0
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DEAD); // Set the dead flag

        // Optional: Teleport the character to a ghost-only area.
        // player->TeleportTo(/* Coordinates of a ghost-only area */);
    }
}

void HardcoreModeModule::SendDeathMessage(Player* player, const char* causeOfDeath)
{
    if (!player)
        return;

    // Create the server-wide death message.
    std::string deathMessage = player->GetName();
    deathMessage += " has just died due to ";
    deathMessage += causeOfDeath;

    // Iterate through online players and send the death message to each one.
    for (auto& onlinePlayer : sObjectMgr->GetPlayers())
    {
        if (onlinePlayer && onlinePlayer->IsInWorld())
        {
            onlinePlayer->GetSession()->SendNotification(deathMessage.c_str());
        }
    }
}

extern "C" void OnServerStart()
{
    g_HardcoreModeModule = new HardcoreModeModule();
}

extern "C" void OnServerStop()
{
    delete g_HardcoreModeModule;
}
