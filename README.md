# mod-custom-races-pta
 **Brute forcing custom race compatibility with CoA's Path to Ascension. Intended for use with AFK-Realm.**

## What It Does
A decent few of the Path to Ascension tutorial quests are locked to the vanilla races available in WotLK. This script detects the race mask on these quests and flips it to `0` in the worldserver's memory, which allows anyone to accept and complete the quests. It does so when the first player (or bot, basically any non-NPC entity) enters the server for the first time, each time, thus avoiding the need to edit either `mod-path-to-ascension` or `mod-custom-races`.

## Known Quirks
- Some quest helper addons, such as Questie-X, may label all instances of a quest (such as obtaining Novice mount riding) as available at once, as it can't availability-match the quests to any specific race. You're still only able to finish the quest once. Once you do, you can hold Shift and right-click the quest icon on the zone map to hide it.

## Credits
- Ascension devs
- Conquest of AzerothCore devs
- Aspollon for [AFK Realm](https://github.com/aspollon/AFK-Realm)
- Google Gemini, because I've barely touched C++ beyond my Introduction To course in over 20 years