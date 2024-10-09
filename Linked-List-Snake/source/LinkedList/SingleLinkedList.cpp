#include "LinkedList/SingleLinkedList.h"


namespace LinkedList
{
	using namespace Player;

	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Player::Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void SingleLinkedList::render()
	{
		Node* cur_node = head_node;

		while (cur_node != nullptr) 
		{   
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
	}

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

	sf::Vector2i SingleLinkedList::getNewNodePosition(Node* reference_node)
	{
		Direction reference_direction = reference_node->body_part.getDirection();
		sf::Vector2i reference_position = reference_node->body_part.getPosition();

		switch (reference_direction)
		{
		case Direction::UP:
			return sf::Vector2i(reference_position.x, reference_position.y - 1);
			break;
		case Direction::DOWN:
			return sf::Vector2i(reference_position.x, reference_position.y + 1);
			break;
		case Direction::LEFT:
			return sf::Vector2i(reference_position.x + 1, reference_position.y);
			break;
		case Direction::RIGHT:
			return sf::Vector2i(reference_position.x - 1, reference_position.y);
			break;
		}

		return default_position;
	}

	void SingleLinkedList::insertNodeAtTail() 
	{
		Node* new_node = createNode();
		Node* cur_node = head_node;

		if (cur_node == nullptr) 
		{   
			head_node = new_node;
			new_node->body_part.initialize(node_width, node_height, default_position, default_direction);
			return;
		}

		while (cur_node->next != nullptr) 
		{
			cur_node = cur_node->next;
		}

		cur_node->next = new_node;
		new_node->body_part.initialize(node_width, node_height, getNewNodePosition(cur_node), cur_node->body_part.getDirection());
	}
}