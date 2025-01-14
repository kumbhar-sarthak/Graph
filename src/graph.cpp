/*
 *
 * @brief - creating the usecase of GraphUtil, clear and reusable code snippet 
 *
 * */


#include<iostream>
#include "../includes/Graph.h"
#include "../Algorithms/Dijkstra.h"
#include "../Algorithms/BellmanFord.h"

std::pair<std::pair<int,int>,std::pair<int,int>> getValues()
{
	int i,j,w;
	int dict;
									//  s d w dict
	// user format like 0 1 2  0
	std::cin>>i>>j>>w>>dict;

	std::cout<<std::endl;
	return {{i,j},{w,dict}};
}

int main()
{
	int v,e;

	std::pair<std::pair<int,int>,std::pair<int,int>> p;

	std::cout<<"Enter the vertex"<<std::endl;
	std::cin>>v;

	std::cout<<"Enter the Edge count"<<std::endl;
	std::cin>>e;

	graph::createGraph(v);

	
	// addEdge function take the source and destionation with weight if applicable and the direction of the edge is directed(0) or undirected(1)
	std::cout<<"Now Graph is created add the edges like - addEdge(source,destination,weight(optional),direction(0/1))"<<std::endl;


  // geting the user input for sorce and destination and weight and direction
	for (int i = 0; i < e; i++)
	{
		p = getValues();
		graph::addEdge(p.first.first,p.first.second,p.second.first,p.second.second);
	}
	
	graph::displayGraph();
	graph::Travel::BFS(0);
	graph::Travel::DFS(0);

	Dijkstra d;

	d.printShortestPaths(0);

	BellmanFord b;

	b.bellmanFord(0);

	b.printDistances();

}
