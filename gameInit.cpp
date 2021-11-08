#include "headers/logic.h"
#include "DungeonCrawler/DungeonCrawler/map.h"


int gameInitialize(void) {

F_levels* P;

P = findFiles();
    
    if (P == nullptr)
    {
        std::cout << ERR_findFiles << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(3));

        return 1;

    }
    else
/* For debug
    for (unsigned short int i = 0; i < MAX_LEVELS; i++)
    {
            std::cout << "[+] Level loaded: " << P->level[i] << std::endl;
    }
 */
    
    std::this_thread::sleep_for(std::chrono::seconds(3));

return 0;

}
