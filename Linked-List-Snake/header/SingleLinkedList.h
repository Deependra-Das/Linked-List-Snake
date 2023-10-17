#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/Node.h"
#include <vector>

class Node;
enum class Direction;

class SingleLinkedList
{
private:
	Node* head_node;

	float node_width;
	float node_height;

	sf::Vector2i default_position;
	Direction default_direction;

	Node* createNode();
	sf::Vector2i getNewNodePosition(Node* reference_node);

	void updateNodes(Direction directionToSet);

public:
	SingleLinkedList();
	~SingleLinkedList();

	void initialize(float width, float height, sf::Vector2i position, Direction direction);
	void update(Direction direction);
	void render();

	void insertNodeAtTail();
	void removeNodeAtTail();
	void removeAllNodes();

	bool handleNodeCollision();
	Node* getHeadNode();

	std::vector<sf::Vector2i> getNodesPositionList();
};