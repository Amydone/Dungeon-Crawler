#include "headers/logic.h"
#include "headers/map.h"


int gameInitialize(void) {

F_levels* level;

void* map;

level = findFiles();
    
    if (level == nullptr)
    {
        std::cout << ERR_findFiles << std::endl;

        return 1;
    }
    
    map = loadLevel(level);

        if (map == nullptr)
        {
            std::cout << ERR_loadMap << std::endl;

            return 1;
        }

    //TODO game cycle
    while (true)
    {
        /* Need get key press [wasd] and make delay approximately 1000ms between pressing 
         * May be need create a function like a checkBounds(Player& player); and execute this from another thread
         * And same with AI
         *
         */
        getDirection();
        
        

    }
   
return 0;

}
