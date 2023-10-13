#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

enum class ButtonState
{
	PRESSED,
	HELD,
	RELEASED,
};

class EventService
{
private:
	sf::Event game_event;
	sf::RenderWindow* game_window;

	ButtonState left_mouse_button_state;
	ButtonState right_mouse_button_state;

	bool isGameWindowOpen();
	bool gameWindowWasClosed();
	bool hasQuitGame();
	bool isKeyboardEvent();
	void updateButtonsState();
	void updateLeftMouseButtonState();
	void updateRightMouseButtonState();

public:
	EventService();
	~EventService();

	void initialize();
	void update();
	void processEvents();

	bool pressedEscapeKey();
	bool pressedUpKey();
	bool pressedDownKey();
	bool pressedLeftKey();
	bool pressedRightKey();
	bool pressedLeftMouseButton();
	bool pressedRightMouseButton();
};