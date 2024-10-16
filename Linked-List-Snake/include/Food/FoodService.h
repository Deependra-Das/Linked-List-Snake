#pragma once
#include <SFML/System/Vector2.hpp>
#include <random>
#include <vector>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:

		FoodItem* current_food_item;
		std::default_random_engine random_engine;
		std::random_device random_device;

		const float spawn_duration = 4.f;
		float elapsed_duration;
		FoodSpawningStatus current_spawning_status;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		void handleFoodSpawning();
		void updateElapsedDuration();
		sf::Vector2i getRandomPosition();
		void destroyFood();
		void reset();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void stopFoodSpawning();
		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i getValidSpawnPosition();
		FoodType getRandomFoodType();
	};
}