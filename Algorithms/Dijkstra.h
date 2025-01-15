/*
 * Dijkstra's Algorithm for Shortest Path Finding
 * 
 * This implementation of Dijkstra's algorithm finds the shortest path from a source node to all other nodes
 * in a weighted graph. The graph is represented as an adjacency list where each node points to its neighbors
 * along with the corresponding edge weights.
 *
 * The algorithm maintains a set of "visited" nodes, and iteratively selects the node with the smallest tentative
 * distance from the source that has not yet been visited. The tentative distances to each neighboring node are
 * then updated based on the current node's distance and the edge weights. This process continues until all nodes 
 * are visited or the destination node's shortest path has been found.
 *
 * Time Complexity: O((V + E) log V), where V is the number of vertices and E is the number of edges.
 * Space Complexity: O(V), where V is the number of vertices (due to storing distances, visited nodes, etc.)
 *
 * Algorithm Steps:
 * 1. Initialize the distance to the source node as 0 and to all other nodes as infinity.
 * 2. Set all nodes as unvisited and create a priority queue (or min-heap) to store the current nodes with their distances.
 * 3. While there are unvisited nodes:
 *    a. Extract the node with the smallest distance from the priority queue.
 *    b. Update the tentative distances of its neighbors based on the current node's distance.
 *    c. Mark the current node as visited.
 * 4. Once all nodes are visited or the destination node is reached, the shortest path distances are determined.
*/

#ifndef ALGORITHMS_DIJSKTRA_ALGORITHM_H
#define ALGORITHMS_DIJSKTRA_ALGORITHM_H


#include <vector>
#include <queue>
#include <limits>
#include <climits>
#include "../includes/Edge.h"
#include "../includes/Graph.h"


class Dijkstra {
private:
    
    std::vector<std::vector<Edge>> adj = graph::list; // Adjacency list

public:

    // Dijkstra's algorithm to find the shortest path from source to all other vertices
    std::vector<int> shortestPath(int src) {
        std::vector<int> dist(adj.size(), INT_MAX);  // Distance from source to each vertex
        dist[src] = 0;

        // Priority queue to store vertices with their distances
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> pq;
        pq.push({0, src});  // {distance, vertex}

        while (!pq.empty()) {
            int u = pq.top().second;
            int uDist = pq.top().first;
            pq.pop();

            // If current distance is greater than already found distance, skip it
            if (uDist > dist[u]) {
                continue;
            }

            // Traverse all adjacent vertices of u
            for (auto& edge : adj[u]) {
                int v = edge.getDestination();
                int weight = edge.getWeight();

                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    // Utility to print the shortest distances from the source
    void run(int src) {
        std::cout<<"Dijkstra Algo"<<std::endl;
        std::vector<int> dist = shortestPath(src);
        std::cout << "Shortest distances from vertex " << src << ":\n";
        for (int i = 0; i < adj.size(); ++i) {
            std::cout << "Vertex " << i << ": ";
            if (dist[i] == INT_MAX) {
                std::cout << "INFINITY\n";
            } else {
                std::cout << dist[i] << "\n";
            }
        }
    }

};


#endif //ALGORITHMS_DIJSKTRA_ALGORITHM_H