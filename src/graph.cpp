/*
 *
 * @brief - creating the usecase of GraphUtil, clear and reusable code snippet 
 *
 * */


#include<iostream>
#include "Graph.h"

std::pair<int,int> getValues(int v)
{
	int i,j;

	std::cin>>i>>j;
	std::cout<<std::endl;
	return {i,j};
}

int main()
{
	int v;
	std::pair<int,int> p;

	std::cout<<"Enter the vertex"<<std::endl;
	std::cin>>v;

	graph::createGraph(v);


	std::cout<<"Enter the source and detination like - 0 1"<<std::endl;

    // geting the user input for sorce and destination
	for (int i = 0; i < v; i++)
	{
		p = getValues(v);
		graph::addEdge(p.first,p.second);
	}
	
	graph::displayGraph();

}
