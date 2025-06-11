#ifndef _PATH_HPP_
#define _PATH_HPP_

#include "graph.hpp"
#include "queue.hpp"

/**
 * @brief Class implementing Dijkstra's shortest path algorithm
 */
class path {
private:
    graph* gr;    ///< Pointer to graph
    queue* qu;    ///< Pointer to queue
    int* dist;    ///< Array of shortest distances
    int* pred;    ///< Array of predecessors

public:
    /**
     * @brief Constructor
     * @param g Pointer to graph
     * @param q Pointer to queue
     */
    path(graph* g, queue* q);

    /**
     * @brief Destructor
     */
    ~path();

    /**
     * @brief Finds shortest paths from source vertex
     * @param src Source vertex
     */
    void shortest_path(int src);

    /**
     * @brief Prints shortest path between vertices
     * @param src Source vertex
     * @param dest Destination vertex
     */
    void print_path(int src, int dest);

    /**
     * @brief Gets shortest distance to vertex
     * @param dest Destination vertex
     * @return Shortest distance
     */
    int get_distance(int dest);
};

#endif // _PATH_HPP_ 