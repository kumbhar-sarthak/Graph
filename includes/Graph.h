/*
 *
 * #GraphUtil.h
 * @brief Header file for graph utilities,  providing classes and functions for creating and manipulating graphs.
 *
 */

#ifndef INCLUDES_GRAPHUTIL_H
#define INCLUDES_GRAPHUTIL_H

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
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

	void addEdge(int s, int d, int w,int dict) //  creating the graph with source and distination
	{
		if (s < 0 || s >= list.size())
		{
			std::cout << "The source is not valid" << std::endl;
		}
		list[s].emplace_back(s, d, w);

		if(dict == 0) // if the graph is undirected then add the edge from destination to source
		{
			list[d].emplace_back(d, s, w);
		}
	}

	void removeEdge(int s, int d, int w, int dict) // removing the edge from source to destination
	{
		int check = 0;
		if (s < 0 || s >= list.size())
		{
			std::cout << "The source is not valid" << std::endl;
		}
		for (auto it = list[s].begin(); it != list[s].end(); it++)
		{
			if (it->getDestination() == d && it->getWeight() == w)
			{
				check = 1;
				list[s].erase(it);
				break;
			}
		}

		if(dict == 0) // if the graph is undirected then remove the edge from destination to source
		{
			for (auto it = list[d].begin(); it != list[d].end(); it++)
			{
				if (it->getDestination() == s && it->getWeight() == w)
				{
					check = 1;
					list[d].erase(it);
					break;
				}
			}
		}

		if(check == 1)
		{	
			std::cout<<std::endl;
			std::cout << "Edge removed successfully" << std::endl;
		}
		else
		{
			std::cout<<std::endl;
			std::cout << "Edge not found" << std::endl;
		}
	}

	void displayGraph()
	{
		std::cout << std::endl;
		std::cout << " " << "Below is the Graph representation from source to destination" << " " << std::endl;
		std::cout << std::endl;
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
			std::cout << std::endl;
			std::cout << " " <<"Graph Breath first search" << " " << std::endl;
			std::cout << std::endl;
			

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

    void DFS(int startNode){

			std::cout << std::endl;
			std::cout << " " <<"Graph Depth first search" << " " << std::endl;
			std::cout << std::endl;

			if (startNode < 0 || startNode >= list.size())
				std::cout << "Starting node is wrong please enter correct node !!" << std::endl;
				
			int size = list.size();
			std::vector<bool> visited(size, false);
			std::stack<int> s;

			s.push(startNode);
			visited[startNode] = true;

			while (!s.empty())
			{
				int current = s.top();
				s.pop();
				std::cout << current << " ";

				// for (auto &node : list[current])
				// {
				// 	int neighbor = node.getDestination();
				// 	if (!visited[neighbor])
				// 	{
				// 		s.push(neighbor);
				// 		visited[neighbor] = true;
				// 	}
				// }

				for (auto it = list[current].rbegin(); it != list[current].rend(); it++)
				{
					int neighbor = it->getDestination();
					if (!visited[neighbor])
					{
						s.push(neighbor);
						visited[neighbor] = true;
					}
				}
				
			}
			std::cout << std::endl;
		}



	}

}

#endif // INCLUDES_GRAPHUTIL_H
