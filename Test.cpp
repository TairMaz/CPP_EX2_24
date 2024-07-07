//tairmazriv@gmail.com
//id: 209188382

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph expedcted_g3;
    expedcted_g3.loadGraph(expectedGraph);
    CHECK(g3.toString() == expedcted_g3.toString());

    g2 += g1;
    CHECK(g2.toString() == expedcted_g3.toString());

    g3 =+ g1;
    CHECK(g3.toString() == g1.toString());

}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {-3, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {-1, 0, 2},
        {1, -2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {2, 0, -1},
        {-4, 3, 0}};
    ariel::Graph expedcted_g3;
    expedcted_g3.loadGraph(expectedGraph);
    CHECK(g3.toString() == expedcted_g3.toString());

    g1 -= g2;
    CHECK(g1.toString() == expedcted_g3.toString());

    vector<vector<int>> expectedGraph2 = {
        {0, -1, -1},
        {1, 0, -2},
        {-1, 2, 0}};
    expedcted_g3.loadGraph(expectedGraph2);
    g3 = -g2;
    CHECK(g3.toString() == expedcted_g3.toString());
}

TEST_CASE("Test graph Increase and decrease")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 2, -2}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 2, -2}};
    g2.loadGraph(graph2);
    
    vector<vector<int>> expectedGraph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 3, -1}};
    ariel::Graph expedcted_g1;
    expedcted_g1.loadGraph(expectedGraph);

    CHECK((++g1).toString() == expedcted_g1.toString());   //prefix increasment

    CHECK((--g1).toString() == g2.toString());             //prefix decreasment

    CHECK((g1++).toString() == g2.toString());             //postfix increasment

    CHECK((g1--).toString() == expedcted_g1.toString());   //postfix decreasment

    CHECK(g1.toString() == g2.toString());
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {3, 4, 2},
        {1, 0, -5}};
    g3.loadGraph(graph3);

    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph4 = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    ariel::Graph expedcted_g4;
    expedcted_g4.loadGraph(expectedGraph4);
    CHECK(g4.toString() == expedcted_g4.toString());

    ariel::Graph g5 = g2 * g3;
    vector<vector<int>> expectedGraph5 = {
        {4, 4, -3},
        {2, 1, -10},
        {6, 9, 4}};
    ariel::Graph expedcted_g5;
    expedcted_g5.loadGraph(expectedGraph5);
    CHECK(g5.toString() == expedcted_g5.toString());

    g2 *= -2;
    vector<vector<int>> expectedGraph2 = {
        {0, -2, -2},
        {-2, 0, -4},
        {-2, -4, 0}};
    ariel::Graph expedcted_g2;
    expedcted_g2.loadGraph(expectedGraph2);
    CHECK(g2.toString() == expedcted_g2.toString());

    g2 /= -2;
    vector<vector<int>> expectedGraph22 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph expedcted_g22;
    expedcted_g22.loadGraph(expectedGraph22);
    CHECK(g2.toString() == expedcted_g22.toString());
}

TEST_CASE("Test graphs Comparisons")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 2, -2}};
    g1.loadGraph(graph);

    ariel::Graph g11;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 2, -2}};
    g11.loadGraph(graph1);
    
    vector<vector<int>> graph2 = {
        {-1, 2, 0},
        {2, 0, 1},
        {3, 0, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph2);

    vector<vector<int>> graph3 = {
        {-6, 2, 0},
        {2, 4, -1},
        {0, 3, 0}};
    ariel::Graph g3;
    g3.loadGraph(graph3);

    vector<vector<int>> graph4 = {
        {0, 2, 0, 5},
        {2, 0, 0, -4},
        {0, 3, 0, 0},
        {0, -1, 0, 0}};
    ariel::Graph g4;
    g4.loadGraph(graph4);

    CHECK((g1 == g11) == 1);
    CHECK((g4 != g3) == 1); 
    CHECK((g1 < g2) == 0); 
    CHECK((g2 < g3) == 1);
    CHECK((g1 <= g2) == 1); 
    CHECK((g4 > g3) == 1);
    CHECK((g4 < g2) == 0);
    CHECK((g1 >= g4) == 0);






}

TEST_CASE("Invalid operations")
{
    // load a not square matrix
    ariel::Graph g1;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
     CHECK_THROWS(g1.loadGraph(weightedGraph));

    ariel::Graph g2;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph);

    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);

    CHECK_THROWS(g5 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}