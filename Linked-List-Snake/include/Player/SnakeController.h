#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"
#include "LinkedListLib/LinkedList.h"
#include "Food/FoodType.h"
#include "Level/LevelConfig.h"

namespace Player
{
	using namespace Level;
	using namespace Food;
	using namespace LinkedListLib;

	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING

	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;
		float elapsed_duration;
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;
		float restart_counter;
		int player_score;
		LinkedListLib::LinkedList* linked_list;
		SnakeState current_snake_state;
		InputState current_input_state;

		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void processBodyCollision();
		void processElementsCollision();
		void processFoodCollision();
		void OnFoodCollected(Food::FoodType food_type);
		void handleRestart();
		void reset();
		void delayedUpdate();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void initializeLinkedList();
		void update();
		void render();
		void createLinkedList(LinkedListType level_type);
		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		bool isSnakeDead();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
		int getPlayerScore();
		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();
	};
}