#pragma once

#include "graphNode.h"

class GraphNode;

struct edge {

    GraphNode *source;
    GraphNode *destination;
    int weight;
	
};