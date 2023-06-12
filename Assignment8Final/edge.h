#pragma once

#include "graphNode.h"

class graphNode;

struct edge {
	graphNode *source;
	graphNode *destination;
	int weight;
};