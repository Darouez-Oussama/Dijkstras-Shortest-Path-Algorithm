#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>

/**
 * @brief Structure for linked list nodes in priority queue
 */
struct list {
    int node;            ///< Vertex number
    int dist_to_source;  ///< Distance from source
    list* next;          ///< Pointer to next node
};

/**
 * @brief Priority queue class for Dijkstra's algorithm
 */
class queue {
protected:
    list* visited;   ///< List of visited vertices
    list* priority;  ///< Priority queue of vertices

public:
    /**
     * @brief Default constructor
     */
    queue();

    /**
     * @brief Destructor
     */
    ~queue();

    /**
     * @brief Adds node to priority queue
     * @param n Node number
     * @param p Priority (distance)
     */
    void prepend_priority(int n, int p);

    /**
     * @brief Adds node to visited list
     * @param n Node number
     * @param p Final distance
     */
    void prepend_visited(int n, int p);

    /**
     * @brief Gets size of priority queue
     * @return Number of nodes in priority queue
     */
    int priority_size();

    /**
     * @brief Checks if priority queue is sorted
     * @return true if sorted, false otherwise
     */
    bool sorted();

    /**
     * @brief Sorts priority queue by distance
     */
    void sort_by_priority();

    /**
     * @brief Removes first node from priority queue
     */
    void remove_first_priority();

    /**
     * @brief Gets node with minimum distance
     * @return Node number with minimum distance
     */
    int priority_min_node();

    /**
     * @brief Gets distance of most recently visited node
     * @return Distance of last visited node
     */
    int get_visited_priority();

    /**
     * @brief Gets distance of first node in priority queue
     * @return Distance of first priority node
     */
    int get_priority_priority();

    /**
     * @brief Checks if node is not in priority queue
     * @param n Node number
     * @return true if not in queue, false otherwise
     */
    bool not_in_queue(int n);

    /**
     * @brief Gets current priority of a node
     * @param n Node number
     * @return Current distance of node
     */
    int node_priority(int n);

    /**
     * @brief Checks if node has been visited
     * @param n Node number
     * @return true if visited, false otherwise
     */
    bool is_visited(int n);

    /**
     * @brief Updates priority of a node
     * @param n Node number
     * @param p New priority
     */
    void update_priority(int n, int p);

    /**
     * @brief Stream insertion operator for queue
     */
    friend std::ostream& operator<<(std::ostream& out, queue& q);
};

#endif // _QUEUE_HPP_ 