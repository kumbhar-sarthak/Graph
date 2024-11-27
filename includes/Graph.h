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

// creating edge
class Edge
{
	int source;
	int destination;

public:
	Edge(int s, int d)
	{
		source = s;
		destination = d;
	}

	// source getter
	int getSource() const
	{
		return source;
	}
	// dist getter
	int getDist() const
	{
		return destination;
	}
};

typedef std::vector<std::vector<Edge>> Graphlist;

namespace graph
{

	Graphlist list; // creating Instance

	void createGraph(int v) // function to create the graph using vertex count
	{
		if (v < 0)
			std::cout << "Vertex count should be correct = 0 - 100";

		list = Graphlist(v);
	}

	void addEdge(int s, int d) //  creating the graph with source and distination
	{
		if (s < 0 || s >= list.size())
		{
			std::cout << "The source is not valid" << std::endl;
		}
		list[s].emplace_back(s, d);
	}

	void displayGraph()
	{
		int length = list.size();
		for (int i = 0; i < length; i++)
		{

			std::cout << i << " " << ':' << " ";
			for (auto &j : list[i])
			{
				std::cout << j.getDist() << " ";
			}
			std::cout << std::endl;
		}
	}

}

#endif
