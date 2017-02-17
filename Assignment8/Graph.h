#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include<queue>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
    bool visited;
    int districtId;
    vertex *previous;
    int distance;


};

struct queueVertex{
    int distance;   //number of edges on path
    std::vector<vertex*> path;   //vertices on the path
};

class Graph
{
    public:
        Graph();
        ~Graph();

        void createVector(char *filename);
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void displayEdges();
        bool compareDistrictId(std::string userinput2, std::string userinput3);
        void getDistrict();
        void shortestPath(std::string input1, std::string input2);
        void shortestDistance(std::string input1, std::string input2);
        bool findVertex(std::string input1);
    protected:
    private:
        //vector<edge> edges;
        std::vector<vertex> vertices;


};

#endif // GRAPH_H
