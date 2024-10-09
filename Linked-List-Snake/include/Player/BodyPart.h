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

	public:
		BodyPart();
		~BodyPart();

		void initialize();
		void update();
		void render();
	};
}