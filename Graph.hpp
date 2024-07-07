//tairmazriv@gmail.com
//id: 209188382

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
using namespace std;

namespace ariel {
    class Graph {

    public:
        vector<vector<int>> Matrix;

        size_t size() const;

        void loadGraph(const vector<vector<int>>& matrix);

        void printGraph();

        string toString() const;

        friend ostream& operator<<(ostream& os, const Graph& g);

        friend Graph operator+(const Graph& g1, const Graph& g2);
        Graph& operator+=(const Graph& other);
        Graph operator+() const;

        friend Graph operator-(const Graph& g1, const Graph& g2);
        Graph& operator-=(const Graph& other);
        Graph operator-() const;

        Graph operator++(int); // Postfix increment
        Graph& operator++();   // Prefix increment
        Graph operator--(int); // Postfix decrement
        Graph& operator--();   // Prefix decrement

        friend Graph operator*(const Graph& g1, const Graph& g2);
        Graph& operator*=(int num);
        Graph& operator/=(int num);

        int edges() const;

        friend bool operator==(const Graph& g1, const Graph& g2);
        friend bool operator!=(const Graph& g1, const Graph& g2);
        friend bool operator<=(const Graph& g1, const Graph& g2);
        friend bool operator>=(const Graph& g1, const Graph& g2);
        friend bool operator<(const Graph& g1, const Graph& g2);
        friend bool operator>(const Graph& g1, const Graph& g2);

    };
}

#endif // GRAPH_HPP