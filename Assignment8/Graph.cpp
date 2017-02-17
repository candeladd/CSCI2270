#include "Graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph::addEdge(string v1, string v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    //adjVertex av2;
                    //av2.v = &vertices[i];
                    //av2.weight = weight;
                    //vertices[i].visited= true;
                    //vertices[j].visited = true;
                    //vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = n;
        v.districtId = -1;
        vertices.push_back(v);

    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<< vertices[i].districtId << ":" <<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name;
                if (j!= vertices[i].adj.size()-1)
                {
                    cout <<"***";
                }
        }
        cout<<endl;
    }

}

void Graph::createVector(char *filename)
{
    string token;
    ifstream infile;
    infile.open(filename);


    int counter = 0;
    int column = 0;
    while (getline(infile, token))
    {

        stringstream ss;
        ss<<token;
        string value;

        column = 0;

        while(getline(ss, value, ','))
        {
            if (counter == 0 && value[0] >= 65 && value[0] <= 90)
            {
                addVertex(value);
            }

            else if (counter >= 1 && column >=1 && stoi(value) >= 1 )
            {
                addEdge(vertices[counter-1].name, vertices[column-1].name, stoi(value));
            }
            column++;
        }
        counter++;
    }
    infile.close();
}

void Graph::getDistrict()
{
    int counter=0;
    int distnum =0;
    while (counter !=vertices.size())
    {
        queue<vertex*> bfq;
        vertex v;
        int i = 0;

        if (vertices[counter].visited ==false)
        {
            distnum =distnum+1;

            vertices[counter].visited = true;
            vertices[counter].districtId =distnum;
            bfq.push(&vertices[counter]);
        }

        while (!bfq.empty()) {
            v = *bfq.front();
            bfq.pop();
            for(i=0;i<v.adj.size();i++) {
                if (v.adj[i].v->visited==false) {
                    v.adj[i].v->visited = true;
                    v.adj[i].v->districtId = distnum;
                    bfq.push(v.adj[i].v);

                }

            }
        }
        counter++;
    }
}

bool Graph::compareDistrictId(string userinput2, string userinput3)
{
    bool path = false;
    for ( int i=0; i<vertices.size();i++)
    {
        if (vertices[i].name == userinput2)
        {
            for (int j=0; j<vertices.size();j++)
            {
                if (vertices[j].name == userinput3)
                {
                    if (vertices[i].districtId == vertices[j].districtId)
                    {
                        path = true;
                    }
                }
            }
        }

    }
    return path;
}
bool Graph::findVertex(string input1)
{
    bool cheese = false;
   for ( int i=0; i<vertices.size();i++)
    {
         if (vertices[i].name == input1)
        {
            cheese = true;
        }
    }
    return cheese;
}

void Graph::shortestPath(string input1, string input2)
{
    vertex *s;
    queueVertex Qv;
    std::queue<vertex*> Q;
    for (std::vector<vertex>::size_type i=0; i != vertices.size(); i++)
    {
        if (vertices[i].name == input1){

            s=&vertices[i];
            s->visited = true;
            s->previous = NULL;
            Qv.distance = 0;

            Q.push(&vertices[i]);
        }
        else
        {
            vertices[i].visited = false;
            vertices[i].previous = NULL;
        }
    }
    if (s->districtId < 0)
    {
        s->visited=false;
        cout << "Please identify the districts before checking distances" << endl;
    }
    else{
        while(!Q.empty()){
            vertex *u =Q.front();
            for (std::vector<adjVertex>::size_type j = 0; j!= u->adj.size(); j++)
            {
                if (u->adj[j].v->visited == false)
                {
                    vertex *v =u->adj[j].v;
                    v->previous = u;
                    v->visited = true;

                    if (v->name == input2)
                    {
                        while (v!=NULL)
                        {
                            Qv.path.push_back(v);
                            Qv.distance++;
                            v=v->previous;
                        }
                        Qv.distance-=1;
                        cout << Qv.distance <<",";
                      for (int i= Qv.path.size()-1; i>0;i--)
                    {

                        cout << Qv.path[i]->name << ",";


                    }

                        cout<< Qv.path[0]->name <<endl;


                    }
                    else
                    {
                        Q.push(v);
                    }

                }
            }
           Q.pop();
        }
    }
}

void Graph::shortestDistance(string input1, string input2)
{
    vector<string> visited;
    vector<vertex*> solved;
    vertex *dest;
    vertex* mini;
    vertex* s;

    for (std::vector<vertex>::size_type i=0; i != vertices.size(); i++)
    {

        vertices[i].visited = false;
        vertices[i].previous = NULL;
        vertices[i].distance = INT_MAX;

        if (vertices[i].name == input1){

            vertices[i].visited = true;
            s= &vertices[i];
            s->previous = NULL;
            s->distance = 0;
            solved.push_back(s);

        }
        else if (vertices[i].name == input2)
        {
            dest = &vertices[i];
            dest->visited = false;

        }

    }
    if (s->districtId < 0)
    {
        s->visited = false;
        cout << "Please identify the districts before checking distances" << endl;
    }
    else{
            while(dest->visited == false)
            {

                int miniDist= INT_MAX;

                for (int i = 0; i< solved.size(); i++)
                {

                    vertex *u =solved[i];
                    for (int j=0; j<u->adj.size();j++)
                    {
                        vertex *v = u->adj[j].v;
                        if (v->visited == false)
                        {
                            if (u->adj[j].weight + u->distance < miniDist)
                            {

                                miniDist = u->adj[j].weight +u->distance;
                                mini = u->adj[j].v;
                                mini->distance = miniDist;
                                mini->previous = u;

                            }

                        }
                    }
                }

                 solved.push_back(mini);
                 mini->visited = true;
            }

            vertex *n1 = dest;
            cout << mini->distance<<",";
            while (n1 != NULL)
            {

                visited.push_back(n1->name);
                n1=n1->previous;

            }

            for (int i= visited.size()-1; i>0;i--)
            {
                cout << visited[i] << ",";

            }
            cout << visited[0] << endl;

    }
}
