#pragma once

#include <vector>
#include <queue>
#include <bitset>
#include <iostream>
using namespace std;

#define MAX_OUT_EDGE 100

class HeapNode {
public:
	int distanceEstimate;
	int nodeNumber;
	HeapNode(int parm1, int parm2) : distanceEstimate(parm1), nodeNumber(parm2) {}
	bool operator < (const HeapNode& rhs) const {
		return distanceEstimate > rhs.distanceEstimate;
	}
};

class Dijkstra {
public:
	vector<int> lineGraph[MAX_OUT_EDGE];
	bitset<MAX_OUT_EDGE> done;
	int distance[MAX_OUT_EDGE];

	int dijkstra(int startNode, int endNode); //返回两点之间的最短距离
	void initLineGraph();
};
