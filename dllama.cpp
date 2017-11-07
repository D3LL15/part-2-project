/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dllama.cpp
 * Author: dan
 * 
 * Created on 07 November 2017, 16:54
 */

#include <cstdlib>
#include <iostream>

#include "include/llama.h"
#include "dllama.h"

using namespace std;

ll_writable_graph* graph;
ll_database database;

dllama::dllama() {
    cout << "starting test\n";
    
    //open database
    
    char* database_directory = (char*) alloca(16);
    strcpy(database_directory, "db");
    
    database = ll_database(database_directory);
    graph = database.graph();
    
    // Load the graph

    ll_file_loaders loaders;
    char graph_location[] = "/home/dan/NetBeansProjects/Part2Project/graph.net";
    ll_file_loader* loader = loaders.loader_for(graph_location);
    if (loader == NULL) {
            fprintf(stderr, "Error: Unsupported input file type\n");
            return;
    }
    
    ll_loader_config loader_config;
    loader->load_direct(graph, graph_location, &loader_config);
    
    /*node_t src = graph->pick_random_node();
    node_t tgt = graph->pick_random_node();
    node_t temp = graph->pick_random_node();

    graph->add_edge(src,tgt);
    graph->add_edge(tgt,temp);
    graph->add_edge(src,temp);

    //ll_mlcsr_ro_graph myrograph = graph.ro_graph;
   
    
    for (std::unordered_map<std::string, LL_CSR*>::const_iterator csrs_iterator = graph->ro_graph().csrs().begin(); 
            csrs_iterator != graph->ro_graph().csrs().end(); 
            csrs_iterator ++)
    {
        cout << csrs_iterator->first << "\n";
        cout << csrs_iterator->second << "\n";
    }
    
    cout << "num levels " << graph->num_levels() << "\n";*/
}

dllama::~dllama() {
}

void dllama::get_snapshots() {
    cout << "starting test\n";
    
    //open database
    
    char* database_directory = (char*) alloca(16);
    strcpy(database_directory, "db");
    
    ll_database database(database_directory);
    graph = database.graph();
    
    // Load the graph

    ll_file_loaders loaders;
    char graph_location[] = "/home/dan/NetBeansProjects/Part2Project/graph.net";
    ll_file_loader* loader = loaders.loader_for(graph_location);
    if (loader == NULL) {
            fprintf(stderr, "Error: Unsupported input file type\n");
            return;
    }
    
    ll_loader_config loader_config;
    loader->load_direct(graph, graph_location, &loader_config);
    
    node_t src = graph->pick_random_node();
    node_t tgt = graph->pick_random_node();
    node_t temp = graph->pick_random_node();

    graph->add_edge(src,tgt);
    graph->add_edge(tgt,temp);
    graph->add_edge(src,temp);

    //ll_mlcsr_ro_graph myrograph = graph.ro_graph;
   
    
    for (std::unordered_map<std::string, LL_CSR*>::const_iterator csrs_iterator = graph->ro_graph().csrs().begin(); 
            csrs_iterator != graph->ro_graph().csrs().end(); 
            csrs_iterator ++)
    {
        cout << csrs_iterator->first << "\n";
        cout << csrs_iterator->second << "\n";
    }
    
    cout << "num levels " << graph->num_levels() << "\n";
}

void dllama::test_llama() {
    node_t src = graph->pick_random_node();
    node_t tgt = graph->pick_random_node();
    node_t temp = graph->pick_random_node();
    
    graph->add_edge(src,tgt);
    graph->add_edge(tgt,temp);
    graph->add_edge(src,temp);

    //ll_mlcsr_ro_graph myrograph = graph.ro_graph;
   
    
    for (std::unordered_map<std::string, LL_CSR*>::const_iterator csrs_iterator = graph->ro_graph().csrs().begin(); 
            csrs_iterator != graph->ro_graph().csrs().end(); 
            csrs_iterator ++)
    {
        cout << csrs_iterator->first << "\n";
        cout << csrs_iterator->second << "\n";
    }
    
    cout << "num levels " << graph->num_levels() << "\n";
}

