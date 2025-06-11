#include "queue.hpp"
#include <climits>

queue::queue() {
    visited = NULL;
    priority = NULL;
}

queue::~queue() {
    // Clean up visited list
    while(visited) {
        list* temp = visited;
        visited = visited->next;
        delete temp;
    }
    
    // Clean up priority list
    while(priority) {
        list* temp = priority;
        priority = priority->next;
        delete temp;
    }
}

void queue::prepend_priority(int n, int p) {
    list* temp = new list;
    temp->dist_to_source = p;
    temp->node = n;
    temp->next = priority;
    priority = temp;
}

void queue::prepend_visited(int n, int p) {
    list* temp = new list;
    temp->dist_to_source = p;
    temp->node = n;
    temp->next = visited;
    visited = temp;
}

int queue::priority_size() {
    list* temp = priority;
    int size = 0;
    while(temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

bool queue::sorted() {
    if (!priority || !priority->next) return true;
    
    list* temp = priority;
    while(temp->next != NULL) {
        if(temp->dist_to_source > temp->next->dist_to_source) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void queue::sort_by_priority() {
    if (!priority || !priority->next) return;
    
    bool swapped;
    do {
        swapped = false;
        list* temp = priority;
        while (temp->next != NULL) {
            if (temp->dist_to_source > temp->next->dist_to_source) {
                // Swap values instead of nodes
                int tempDist = temp->dist_to_source;
                int tempNode = temp->node;
                temp->dist_to_source = temp->next->dist_to_source;
                temp->node = temp->next->node;
                temp->next->dist_to_source = tempDist;
                temp->next->node = tempNode;
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void queue::remove_first_priority() {
    if (!priority) return;
    list* temp = priority;
    priority = priority->next;
    delete temp;
}

int queue::priority_min_node() {
    if (!priority) return -1;
    
    list* temp = priority;
    int min_dist = temp->dist_to_source;
    int min_node = temp->node;
    
    while(temp != NULL) {
        if(temp->dist_to_source < min_dist) {
            min_dist = temp->dist_to_source;
            min_node = temp->node;
        }
        temp = temp->next;
    }
    return min_node;
}

int queue::get_visited_priority() {
    return (visited) ? visited->dist_to_source : 0;
}

int queue::get_priority_priority() {
    return (priority) ? priority->dist_to_source : 0;
}

bool queue::not_in_queue(int n) {
    list* temp = priority;
    while (temp != NULL) {
        if (n == temp->node) return false;
        temp = temp->next;
    }
    return true;
}

bool queue::is_visited(int n) {
    list* temp = visited;
    while (temp != NULL) {
        if (n == temp->node) return true;
        temp = temp->next;
    }
    return false;
}

int queue::node_priority(int n) {
    list* temp = priority;
    while (temp != NULL) {
        if (n == temp->node) return temp->dist_to_source;
        temp = temp->next;
    }
    return INT_MAX;  // Return INT_MAX if node not found
}

void queue::update_priority(int n, int p) {
    list* temp = priority;
    while(temp != NULL) {
        if(temp->node == n) {
            temp->dist_to_source = p;
            break;
        }
        temp = temp->next;
    }
    sort_by_priority();
}

std::ostream& operator<<(std::ostream& out, queue& q) {
    queue* temp = new queue;
    *temp = q;
    queue* temp2 = new queue;
    *temp2 = q;
    queue* temp3 = new queue;
    *temp3 = q;

    out << "priority queue:";
    while(((temp->priority)) != NULL) {
        out << "--" << (temp->priority)->dist_to_source;
        temp->priority = temp->priority->next;
    }
    out << "\n";
    out << "priority node :";
    while(((temp3->priority)) != NULL) {
        out << "--" << (temp3->priority)->node;
        temp3->priority = temp3->priority->next;
    }
    out << "\n";
    out << "visited queue:";
    while(((temp->visited)) != NULL) {
        out << "--" << (temp->visited)->node;
        temp->visited = temp->visited->next;
    }
    out << "\n";
    out << "priority visited:";
    while(((temp2->visited)) != NULL) {
        out << "--" << (temp2->visited)->dist_to_source;
        temp2->visited = temp2->visited->next;
    }
    out << "\n";

    delete temp;
    delete temp2;
    delete temp3;
    return out;
} 