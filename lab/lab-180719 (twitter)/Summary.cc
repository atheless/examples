void add(graph& g, int u, int v, float w, bool d) {
    if (d)
        add_arc(g, u, v, w);
    else
        add_edge(g, u, v, w);
}

graph g_build(bool d, bool w) {
    ifstream file("graph");
    file >> n;
    file.close();
    graph G = new_graph(n); 
    int v1,v2;

    if (w) { 
        float w;
        while (g >> v1 >> v2 >> w){
            add(G, v1, v2, w, d); 
        }
    } else { 
        while (g >> v1 >> v2) {
            add(G, v1, v2, 1.0, d); 
        }
    }

   return G;
}





