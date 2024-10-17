#pragma once
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include "UI/UIElement/ImageView.h"

namespace Player
{
	class BodyPart
	{
	private:
		UI::UIElement::ImageView* bodypart_image;
		sf::Vector2i grid_position;
		Direction direction;
		float bodypart_width;
		float bodypart_height;

		void createBodyPartImage();
		void initializeBodyPartImage();
		sf::Vector2f getBodyPartScreenPosition();
		float getRotationAngle();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionRight();
		sf::Vector2i getNextPositionLeft();
		void setPosition(sf::Vector2i position);
		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void render();

		void updatePosition();
		Direction getDirection();
		void setDirection(Direction new_direction);
		sf::Vector2i getPosition();
		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();
	};
}