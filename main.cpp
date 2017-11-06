/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dan
 *
 * Created on 29 October 2017, 15:42
 */

#include <cstdlib>
#include <iostream>
#include "include/llama.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "hello\n";
    
    //open database
    
    char* database_directory = (char*) alloca(16);
    strcpy(database_directory, "db");
    
    ll_database database(database_directory);
    ll_writable_graph& graph = *database.graph();
    
    
    // Load the graph

    ll_file_loaders loaders;
    char graph_location[] = "/home/dan/NetBeansProjects/Part2Project/graph.net";
    ll_file_loader* loader = loaders.loader_for(graph_location);
    if (loader == NULL) {
            fprintf(stderr, "Error: Unsupported input file type\n");
            return 1;
    }
    
    ll_loader_config loader_config;
    loader->load_direct(&graph, graph_location, &loader_config);
    
    node_t src = graph.pick_random_node();
    node_t tgt = graph.pick_random_node();
    node_t temp = graph.pick_random_node();

    /*graph.add_edge(src,tgt);
    graph.add_edge(tgt,temp);
    graph.add_edge(src,temp);*/

    //ll_mlcsr_ro_graph myrograph = graph.ro_graph;

    cout << graph.ro_graph().csrs().begin()->first << "\n";
    


    cout << "num levels" << graph.num_levels() << "\n";
    
    return 0;
}

