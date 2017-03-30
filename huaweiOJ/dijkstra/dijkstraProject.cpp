// dijkstraProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "dijkstraProject.h"

int lineDistance[MAX_OUT_EDGE][MAX_OUT_EDGE];

int main()
{
	lineDistance[0][1] = 6;
	lineDistance[0][2] = 3;
	lineDistance[1][0] = 6;
	lineDistance[1][2] = 2;
	lineDistance[1][3] = 5;
	lineDistance[2][0] = 3;
	lineDistance[2][1] = 2;
	lineDistance[2][3] = 3;
	lineDistance[3][1] = 5;
	lineDistance[3][2] = 3;

	Dijkstra work;
	work.initLineGraph();
	int startNode, endNode;
	while (cin >> startNode >> endNode) {
		cout << work.dijkstra(startNode, endNode) << endl;
	}
    return 0;
}

int Dijkstra::dijkstra(int startNode, int endNode) {

	priority_queue<HeapNode> nodeQueue;
	nodeQueue.push(HeapNode(0, startNode));
	done.reset();
	fill(distance, distance + MAX_OUT_EDGE, INT_MAX);
	distance[startNode] = 0;

	while (!nodeQueue.empty()) {
		HeapNode curNode = nodeQueue.top();
		nodeQueue.pop();
		int curNodeNumber = curNode.nodeNumber;
		if (done[curNodeNumber]) continue;
		for (unsigned int i = 0; i < lineGraph[curNodeNumber].size(); i++) {
			int toNodeNumber = lineGraph[curNodeNumber][i];
			if (distance[toNodeNumber] > distance[curNodeNumber]
				+ lineDistance[curNodeNumber][toNodeNumber]) {
				distance[toNodeNumber] = distance[curNodeNumber] + lineDistance[curNodeNumber][toNodeNumber];
				nodeQueue.push(HeapNode(distance[toNodeNumber], toNodeNumber));
			}
		}
		done[curNodeNumber] = true;
		if (done[endNode]) {
			return distance[endNode];
		}
	}
	return distance[endNode];
}

void Dijkstra::initLineGraph() {
	vector<int> vec;
	for (int i = 0; i < MAX_OUT_EDGE; i++) {
		vec.clear();
		for (int j = 0; j < MAX_OUT_EDGE; j++) {
			if (lineDistance[i][j] == 0) {
				continue;
			} else {
				vec.push_back(j);
			}
		}
		lineGraph[i] = vec;
	}
}

