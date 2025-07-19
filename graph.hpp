#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <cstdlib>
#include <cstdbool>

/**
 * @brief Class representing a weighted graph using adjacency matrix
 * 
 * This class implements a graph using two matrices:
 * - A boolean matrix for connections
 * - An integer matrix for edge weights
 */
class graph { 
public: 
    bool** g;  ///< Adjacency matrix for connections
    int** d;   ///< Matrix for edge weights
    int size;  ///< Number of vertices in the graph

public: 
    /**
     * @brief Helper function that returns true with 60% probability
     * @return bool True with 0.6 probability, false with 0.4 probability
     */
    bool prob();

    /**
     * @brief Default constructor
     */
    graph();

    /**
     * @brief Constructs a graph with specified number of vertices
     * @param s Number of vertices
     */
    graph(int s);

    /**
     * @brief Destructor
     */
    ~graph();

    /**
     * @brief Stream insertion operator for graph
     * @param out Output stream
     * @param g Graph to output
     * @return Reference to output stream
     */
    friend std::ostream& operator<<(std::ostream& out, const graph& g);

    /**
     * @brief Creates a deep copy of the graph
     * @return New graph object
     */
    graph equals();

    /**
     * @brief Checks if graph is connected
     * @return true if graph is connected, false otherwise
     */
    bool is_connected();

    /**
     * @brief Gets number of vertices
     * @return Number of vertices
     */
    int get_graph_size();

    /**
     * @brief Gets number of edges
     * @return Number of edges
     */
    int get_number_of_connected_nodes();

    /**
     * @brief Checks if two vertices are adjacent
     * @param n1 First vertex
     * @param n2 Second vertex
     * @return true if vertices are adjacent, false otherwise
     */
    bool adjacent(int n1, int n2);

    /**
     * @brief Gets array of neighboring vertices
     * @param n Vertex to find neighbors of
     * @return Array where index i contains i if connected, -1 if not
     */
    int* neghibours(int n);

    /**
     * @brief Adds edge between two vertices
     * @param n1 First vertex
     * @param n2 Second vertex
     */
    void add_edge(int n1, int n2);

    /**
     * @brief Deletes edge between two vertices
     * @param n1 First vertex
     * @param n2 Second vertex
     */
    void delete_edge(int n1, int n2);

    /**
     * @brief Gets weight of edge between vertices
     * @param n1 First vertex
     * @param n2 Second vertex
     * @return Edge weight
     */
    int get_edge_value(int n1, int n2);

    /**
     * @brief Sets weight of edge between vertices
     * @param n1 First vertex
     * @param n2 Second vertex
     * @param v New weight value
     */
    void set_edge_value(int n1, int n2, int v);
};

#endif // _GRAPH_HPP_