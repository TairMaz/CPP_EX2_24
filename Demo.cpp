//tairmazriv@gmail.com
//id: 209188382

/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.

    cout<<"g1:"<< endl<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout<<"g3 = g1 + g2:"<< endl<<g3;           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 += g2; // Add the two graphs together into g1.
    cout<<"g1 after addition:"<< endl<<g1;          // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
    
    cout<<"+g1:"<< endl<<(+g1);          // + unari, Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 -= g2; // Subtraction of the two graphs into g1.
    cout<<"g1 after Subtraction:"<< endl<<g1;          // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    
    ariel::Graph g4 = g1 - g2; // Subtraction of the two graphs.
    cout<<"g4 = g1 - g2:"<< endl<<g4;           // Should print the matrix of the graph: [0, 0, -1], [0, 0, -1], [-1, -1, 0]
    
    cout<<"-g1:"<< endl<<(-g1);          // - unari, Should print the matrix of the graph: [0, -1, 0], [-1, 0, -1], [0, -1, 0]

    g1 *= -2;        // Multiply the graph by -2.
    cout<<"g1 *= -2:"<<endl<<g1; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    cout<<"g1 /= -2:"<<endl<<g1; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    ariel::Graph g5 = g1 * g2; // Multiply the two graphs together.
    cout<<"g5 = g1 * g2"<<endl<<g5;           // Should print the multiplication of the matrices of g1 and g2: [1, 0, 2], [1, 3, 1], [1, 0, 2]

    // 4x4 matrix
    vector<vector<int>> graph6 = {
        {0, 1, 1, 0},
        {1, 0, 0, -6},
        {0, 0, 2, 0},
        {2, 0, 0, 3}};
    ariel::Graph g6;
    g6.loadGraph(graph6);


    cout<<"g4 == g1? "<<(g4 == g1)<<endl; // Should print 1 (true)
    
    cout<<"g1 != g2? "<<(g1 != g2)<<endl; // Should print 1 (true)

    cout<<"g5 < g1? "<<(g5 < g1)<<endl; // Should print 0 (false)

    cout<<"g3 <= g2? "<<(g3 <= g2)<<endl; // Should print 1 (true)

    cout<<"g6 > g5? "<<(g6 > g5)<<endl; // Should print 1 (true)

    cout<<"g1 >= g2? "<<(g1 >= g2)<<endl; // Should print 0 (false)

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "Invalid multiplication: graphs not the same size"
    }
}