#include "graph.hpp"
#include <ctime>

/**
 * @brief Implementation of graph class methods
 */

bool graph::prob() {
    return ((static_cast<double>(rand()%100)/100) < 0.6);
}

graph::graph() {
    size = 0;
    g = new bool*[size];
    d = new int*[size];
    for(int i = 0; i < size; i++) {
        g[i] = new bool[size];
        d[i] = new int[size];
    }
}

graph::graph(int s) {
    do {
        srand(time(0));
        size = s;
        g = new bool*[size];
        d = new int*[size];
        for(int a = 0; a < size; a++) {
            g[a] = new bool[size];
            d[a] = new int[size];
        }
        
        // Initialize adjacency and weight matrices
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(i == j) {
                    g[i][j] = 0;
                    d[i][j] = 0;
                }
                else {
                    g[i][j] = g[j][i] = prob();
                    if(g[i][j] == 1) 
                        d[i][j] = d[j][i] = (rand()%10)+1;
                    else 
                        d[i][j] = d[j][i] = 0;
                }
            }
        }
    } while (!is_connected());  // Ensure graph is connected
}

graph::~graph() {
    for(int i = 0; i < size; i++) {
        delete[] g[i];
        delete[] d[i];
    }
    delete[] g;
    delete[] d;
}

std::ostream& operator<<(std::ostream& out, const graph& gr) {
    for(int i = 0; i < gr.size; i++) {
        for(int j = 0; j < gr.size; j++) {
            out << gr.g[i][j] << "  ";
        }
        out << "\t\t\t";
        for(int k = 0; k < gr.size; k++) {
            out << gr.d[i][k] << "   ";
        }
        out << std::endl;
    }
    return out;
}

bool graph::is_connected() {
    bool* open = new bool[size];
    bool* closed = new bool[size];
    int old_size = 0, c_size = 0;
    
    for(int i = 0; i < size; i++) {
        open[i] = 0;
        closed[i] = 0;
    }
    
    open[0] = 1;
    while(c_size < size) {
        for(int i = 0; i < size; i++) {
            old_size = c_size;
            if(open[i] && closed[i] == 0) {
                closed[i] = 1;
                c_size++;
                for(int j = 0; j < size; j++) {
                    open[j] = open[j] || g[i][j];
                }
            }
        }
        if(old_size == c_size) {
            delete[] open;
            delete[] closed;
            return false;
        }
    }
    
    delete[] open;
    delete[] closed;
    return true;
}

int graph::V() {
    return size;
}

int graph::E() {
    int e = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            if(g[i][j] == 1) e++;
        }
    }
    return e;
}

bool graph::adjacent(int n1, int n2) {
    return g[n1][n2] == 1;
}

int* graph::neghibours(int n) {
    int* t = new int[size];
    for(int i = 0; i < size; i++) {
        t[i] = g[n][i] == 1 ? i : -1;
    }
    return t;
}

void graph::add_edge(int n1, int n2) {
    g[n1][n2] = g[n2][n1] = 1;
    if(n1 == n2) {
        d[n1][n2] = d[n2][n1] = 0;
    } else {
        d[n1][n2] = d[n2][n1] = (rand()%10)+1;
    }
}

void graph::delete_edge(int n1, int n2) {
    g[n1][n2] = g[n2][n1] = 0;
    d[n1][n2] = d[n2][n1] = 0;
}

int graph::get_edge_value(int n1, int n2) {
    return d[n1][n2];
}

void graph::set_edge_value(int n1, int n2, int v) {
    if(g[n1][n2] == 1) {
        d[n1][n2] = d[n2][n1] = v;
    }
}





