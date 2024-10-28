#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Level/LevelService.h"
#include "Player/SnakeController.h"

namespace Player
{
	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;
		void createController();
		void destroy();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer(LinkedListType level_type);
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
		bool isPlayerDead();
	};

}