
#ifndef INCLUDES_EDGE_H
#define INCLUDES_EDGE_H


#include<iostream>


class Edge{
    private:
        int source;
        int destination;
        int weight; // optional to create weighted graphs
    
    public:

        Edge(int s,int d) : source(s),destination(d) {}

        Edge(int s,int d,int w) : source(s),destination(d),weight(w){}

        int getSource() const{
            return source;
        }

        int getDestination() const{
            return destination;
        }

        int getWeight() const{
            return weight;
        }
};

#endif  // INCLUDES_EDGE_H
