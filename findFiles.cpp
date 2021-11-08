#include "headers/logic.h"
#include "DungeonCrawler/DungeonCrawler/map.h"

F_levels* findFiles(void) {


char level[] = "level1.txt";

F_levels* PFiles = new F_levels;

std::string fileName, fileExtension;
std::string pattern = level;

unsigned short int FileCounter = 0;


std::string path = std::filesystem::current_path().string(); 

while (FileCounter != MAX_LEVELS && PFiles != nullptr)
{
    for (auto count : std::filesystem::directory_iterator(path))
    {
        fileName = count.path().filename().string();
        fileExtension = count.path().filename().extension().string();

        if (!fileExtension.compare(".txt"))
        {

            if (!fileName.compare(pattern))
            {

                PFiles->level[FileCounter] = pattern;
                level[5]++;
                pattern = level;
                FileCounter++;

            }
            else
            for (unsigned short int i = 0, j = 1; i <= MAX_LEVELS; i++, j++)
            {
                if (fileName.compare(pattern))
                {
                    level[5] = j + 0x30;
                    pattern = level;
                }
                else
                {
                    PFiles->level[FileCounter] = pattern;
                    FileCounter++;

                }

            }

        }

    }

    if (FileCounter < MAX_LEVELS)
    {
        delete PFiles;
        PFiles = nullptr;
    }


}

    
return PFiles;

}
