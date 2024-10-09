#pragma once
#include "BodyPart.h"

struct Node
{
	Player::BodyPart body_part;
	Node* next = nullptr;
};