

#ifndef ALGORITHMS_FLOYD_WARSHALL_H
#define ALGORITHMS_FLOYD_WARSHALL_H

#include <vector>
#include <limits>
#include "../includes/Graph.h"
#include "../includes/Edge.h"


class FloydWarshall {
  private:
    std::vector<std::vector<Edge>> adj = graph::list; // Adjacency matrix
    std::vector<std::vector<int>> dist; // Distance matrix
  public:
    
    FloydWarshall() : dist(adj.size(), std::vector<int>(adj.size(), std::numeric_limits<int>::max())) {}
    

    std::vector<std::vector<int>> run(){

      std::vector<std::vector<int>> temp(adj.size(), std::vector<int>(adj.size(), std::numeric_limits<int>::max()));

      for(int i = 0 ; i < adj.size(); i++){
        temp[i][i] = 0;
      }

      for(int i = 0; i < adj.size(); i++){
        for(auto &edge : adj[i]){
          temp[i][edge.getDestination()] = edge.getWeight();
        }
      }
      
      for (int i = 0; i < adj.size(); i++)
      {
        for (int j = 0; j < adj.size(); j++)
        {
          for (int k = 0; k < adj.size(); k++)
          {
            if(temp[j][i] != std::numeric_limits<int>::max() && temp[i][k] != std::numeric_limits<int>::max() && temp[j][i] + temp[i][k] < temp[j][k])
            {
              temp[j][k] = temp[j][i] + temp[i][k];
            }
          }
        }
      }

      return temp;
    }

    void Run() {

      dist = run();

      std::cout<< "Floyd Warshall Algo"<<std::endl;
      for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj.size(); j++) {
          if(dist[i][j] != std::numeric_limits<int>::max()){
            std::cout << "Distance from " << i << " to " << j << " is " << dist[i][j] << std::endl;
          }
        }
      }
    }
    
};


#endif //ALGORITHMS_FLOYD_WARSHALL_H