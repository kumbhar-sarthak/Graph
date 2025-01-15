/*
 * @brief -
 *   Bellman-Ford algorithm is used to find the shortest path from a source vertex to all other vertices *   in  a weighted graph.it can handle negative weights but not negative weight cycles.
 *   The algorithm works by relaxing edges repeatedly and for each vertex, it keeps track of the
 *   shortest distance from the source vertex.
 *   The algorithm runs in O(V*E) time complexity where V is the number of vertices and E is the number
 *   of edges in the graph.
 *   The algorithm can be used to detect negative weight cycles in the graph.
 *   Use Case: Distance vector routing algorithm, Traffic engineering, Network routing protocols.
*/


#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>
#include <limits>
#include "../includes/Edge.h"
#include "../includes/Graph.h"

class BellmanFord {

private:

  std::vector<std::vector<Edge>> adj = graph::list;
  int s = adj.size();
  std::vector<int> dist;

public:
  BellmanFord() : dist(s, std::numeric_limits<int>::max()) {} // constructor
  
  // function to find the shortest path from source to all other vertices
  std::vector<int> bellmanFord(int start) {
    std::vector<int> temp(s, std::numeric_limits<int>::max());
    temp[start] = 0;
    for (int i = 0; i < s - 1; i++) {
      for (int j = 0; j < s; j++) {
        for (auto &edge : adj[j]) {
          if (temp[j] + edge.getWeight() < temp[edge.getDestination()]) {
            temp[edge.getDestination()] = temp[j] + edge.getWeight();
          }
        }
      }
    }

    return temp;
  }

  // function call to check negative weight cycle
  void checkForNegativeWeightCycle() {
    for (int j = 0; j < s; j++) {
      for (const auto &edge : adj[j]) {
        int source = j;
        int destination = edge.getDestination();
        int weight = edge.getWeight();
        if (dist[source] != std::numeric_limits<int>::max() && dist[source] + weight < dist[destination]) {
          std::cout << "Graph contains negative weight cycle" << std::endl;
          return;
        }
      }
    }
  }
  

  void printDistances(int src) {

    dist = bellmanFord(src);

    std::cout<< "Bellman Ford Algo"<<std::endl;
    for (int i = 0; i < s; i++) {
      std::cout << "Distance from " << i << " is " << dist[i] << std::endl;
    }
  }


};

#endif // BELLMANFORD_H