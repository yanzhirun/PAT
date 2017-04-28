void init_single_source(Graph* G, int s)
{
    for(int i=0; i<G->n; ++i)
    {
        d[i]=INF;
        pre[i] = -1;
    }
    d[s] = 0;
}

void relax(int u, int v, Graph* G)
{
    if(d[v]>d[u]+G->w[u][v])
    {
        d[v] = d[u] + G->w[u][v];
        pre[v] = u;
    }
}

