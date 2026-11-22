#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "../../mod-path-to-ascension/src/PathToAscension.h"
#include <mutex>

class CustomRacesPTAPlayerScript : public PlayerScript
{
public:
    CustomRacesPTAPlayerScript() : PlayerScript("CustomRacesPTAPlayerScript") { }

    void OnPlayerLogin(Player* /*player*/) override
    {
        static std::once_flag flag;
        if (!PathToAscension::IsLoaded())
            return;

        std::call_once(flag, []()
        {
            auto& tutorials = const_cast<std::map<uint32, PathToAscension::Tutorial>&>(
                PathToAscension::GetCatalog().Tutorials());

            uint32 updated = 0;
            for (auto& [id, tutorial] : tutorials)
            {
                if (tutorial.fields[PathToAscension::TutorialField::RaceMask] != 0)
                {
                    tutorial.fields[PathToAscension::TutorialField::RaceMask] = 0;
                    ++updated;
                }
            }

            LOG_INFO("module", "mod-custom-races-pta: Cleared RaceMask on {} Path to Ascension tutorials.", updated);
        });
    }
};

void Addmod_custom_races_ptaScripts()
{
    new CustomRacesPTAPlayerScript();
}
