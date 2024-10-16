#pragma once
#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include "LinkedList/SingleLinkedList.h"

namespace Player
{
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
		LinkedList::SingleLinkedList* single_linked_list;
		SnakeState current_snake_state;
		InputState current_input_state;

		void createLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void delayedUpdate();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
		void spawnSnake();
		void respawnSnake();
		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}