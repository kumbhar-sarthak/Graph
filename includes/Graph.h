/*
 *
 * #GraphUtil.h
 * @brief Header file for graph utilities,  providing classes and functions for creating and manipulating graphs.
 *
 */

#ifndef GRAPHUTIL_H
#define GRAPHUTIL_H

#include <vector>
#include <iostream>
#include <queue>
#include "Edge.h"

typedef std::vector<std::vector<Edge>> GraphList;

namespace graph
{

	GraphList list; // creating Instance

	void createGraph(int v) // function to create the graph using vertex count
	{
		if (v < 0)
			std::cout << "Vertex count should be correct = 0 - 100";

		list = GraphList(v);
	}

	void addEdge(int s, int d, int w = 0) //  creating the graph with source and distination
	{
		if (s < 0 || s >= list.size())
		{
			std::cout << "The source is not valid" << std::endl;
		}
		list[s].emplace_back(s, d, w);
	}

	void displayGraph()
	{
		std::cout<<" "<<"Below is the Graph representation from source to destination"<<" "<<std::endl;
		std::cout<<std::endl;
		int length = list.size();
		for (int i = 0; i < length; i++)
		{

			std::cout << i << " " << ':' << " ";
			for (auto &j : list[i])
			{
				std::cout << "(" << j.getDestination() << ", weight: " << j.getWeight() << ") ";
			}
			std::cout << std::endl;
		}
	}

	namespace Travel
	{
		void BFS(int startNode)
		{
			std::cout<<" "<<"Graph Breath first search"<<" "<<std::endl;
			std::cout<<std::endl;
			
			if (startNode < 0 || startNode >= list.size())
				std::cout << "Starting node is wrong please enter correct node !!" << std::endl;
			int size = list.size();
			std::vector<bool> visited(size, false);
			std::queue<int> q;

			q.push(startNode);
			visited[startNode] = true;

			while (!q.empty())
			{
				int current = q.front();
				q.pop();
				std::cout << current << " ";

				for (auto &node : list[current])
				{
					int neighbor = node.getDestination();
					if (!visited[neighbor])
					{
						q.push(neighbor);
						visited[neighbor] = true;
					}
				}
			}
			std::cout << std::endl;
		}
	}

}

#endif
