#include "headers/logic.h"
#include "headers/map.h"

char** loadLevel(F_levels* maps) {

std::string str_read;

coord map_coord;

for (unsigned short int i = 0; i < MAX_LEVELS; i++)
{
	std::ifstream level;
	int check_x[4], check_y[4];
	int val1, val2;

	size_t length = 0;

	level.open(maps->level[i]);

	if (level.is_open())
	{
		char read[4];

		level.seekg(0, std::ios::beg);

		for (unsigned short i = 0; i < 4; i++, length++)
		{
			level.get(read[i]);

			if (read[i] == '\n')
			{
				read[i] = '\0';
				break;
			}

		}

		//TODO fix return values	
		switch (length)
		{
		case 1:
			std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Incorrect size of map" << std::endl;
			return nullptr;
			break;

		case 2:
			check_x[0] = (int)read[0] - 0x30;
			check_y[0] = (int)read[1] - 0x30;

			if (*check_x > MAX_SIZE_MAP)
			{
				std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Size of X > 10" << std::endl;
				return nullptr;
			}
			else
			{
				if (*check_y > MAX_SIZE_MAP)
				{
					std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Size of Y > 10" << std::endl;
					return nullptr;
				}
				else
				{
					map_coord.x = check_x[0];
					map_coord.y = check_y[0];

				}

			}
			break;

		case 3:
			check_x[0] = (int)read[0] - 0x30;
			check_x[1] = (int)read[1] - 0x30;

			check_y[0] = (int)read[1] - 0x30;
			check_y[1] = (int)read[2] - 0x30;

			if (*check_x > MAX_SIZE_MAP)
			{
				if (*check_y > MAX_SIZE_MAP)
				{
					std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Size of X or Y > 10" << std::endl;
				}
				else
				{
					map_coord.y += check_y[0];
					map_coord.y *= 10;
					map_coord.y += check_y[1];

					map_coord.x += check_x[0];

				}

			}
			else
			{
				map_coord.x = check_x[0];
				map_coord.x *= 10;
				map_coord.x += check_x[1];

				map_coord.y = check_y[1];

			}
			break;

		case 4:
			check_x[0] = (int)read[0] - 0x30;
			check_x[1] = (int)read[1] - 0x30;

			check_y[0] = (int)read[2] - 0x30;
			check_y[1] = (int)read[3] - 0x30;

			if (*check_x > MAX_SIZE_MAP)
			{
				std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Size of X > 10" << std::endl;
				return nullptr;
			}
			else
			{

				if (*check_y > MAX_SIZE_MAP)
				{
					std::cout << "[-] Error in file [" << maps->level[i] << "]\n" << "[-] Size of Y > 10" << std::endl;
					return nullptr;
				}
				else
				{
					map_coord.x = check_x[0];
					map_coord.x *= 10;
					map_coord.x += check_x[1];

					map_coord.y = check_y[0];
					map_coord.y *= 10;
					map_coord.y += check_y[1];
				}

			}
			break;

		default:
			return nullptr;
			break;
		}

		std::cout << read << std::endl;

		std::this_thread::sleep_for(std::chrono::seconds(2));

	}

}
	char dungeon[3][3] = {}; 

	return (char**)dungeon;

}