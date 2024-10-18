#pragma once
#include "LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;
		float node_width;
		float node_height;
		int linked_list_size;
		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		Direction getReverseDirection(Direction reference_direction);
		int findMiddleNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();

		sf::Vector2i getNewNodePosition(Node* reference_node);
		void insertNodeAtHead();
		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void shiftNodesAfterRemoval(Node* cur_node);
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeNodeAtTail();
		void removeAllNodes();
		void removeNodeAt(int index);
		void removeNodeAtMiddle();
		void removeNodeAtIndex(int index);
		void removeHalfNodes();
		std::vector<sf::Vector2i> getNodesPositionList();
		Node* getHeadNode();
		Node* findNodeAtIndex(int index);
		Player::Direction reverse();
		void reverseNodeDirections();
	};
}