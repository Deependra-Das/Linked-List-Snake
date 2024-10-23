#pragma once
#include "Levelconfig.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_linked_list_type;

		void createLevelController();
		void spawnPlayer();
		void spawnLevelElements(LevelNumber level_to_load);
		void spawnFood();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();
		void createLevel(LinkedListType linked_list_type);
		LevelNumber getCurrentLevel();
		void setCurrentLevelNumber(LevelNumber level_to_load);
		float getCellWidth();
		float getCellHeight();
	};
}