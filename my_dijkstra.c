data min_Path(data_long dist[], bool MST_set[], data const d){
    data_long min = WEIGHT_MAX;
    data min_index = 0;
    P("Trying to find Bug 11\n");
    for (int i = 0; i < d; ++i) {
        if (MST_set[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    P("Trying to find Bug 12\n");
    return min_index;
}

void dijkstra(data_long ** graph, data const d, data_long dist[]){
    bool SPT_set[d];
    P("Trying to find Bug 7\n");
    for (int i = 0; i < d; ++i) {
        dist[i] = WEIGHT_MAX;
        SPT_set[i] = false;
    }
    P("Trying to find Bug 8\n");
    dist[0] = 0;
    for (int count = 0; count < d - 1; count++) {
        int i = min_Path(dist, SPT_set, d);
        SPT_set[i] = true;
        P("Trying to find Bug 9 - for loop\n");
        for (int j = 0; j < d; ++j) {
            if(SPT_set[j] == false && graph[i][j] != 0 && (i != j) &&
            dist[i] != WEIGHT_MAX && dist[i] + graph[i][j] < dist[j] ) {
                dist[j] = dist[i] + graph[i][j];
                P("Trying to find Bug 10\n");
            }
        }
    }
}