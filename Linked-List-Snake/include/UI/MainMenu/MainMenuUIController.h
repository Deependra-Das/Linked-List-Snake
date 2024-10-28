#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/TextView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const sf::String game_title = "Snake 2D";

			const float text_top_offset = 100.f;
			const int font_size = 200;
			const sf::Color text_color = sf::Color::White;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float play_button_y_position = 500.f;
			const float instructions_button_y_position = 700.f;
			const float quit_button_y_position = 900.f;

			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;
			UIElement::TextView* title_text;
			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();
			void createText();
			void initializeText();
			void initializeBackgroundImage();
			void initializeButtons();
			void registerButtonCallback();

			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}