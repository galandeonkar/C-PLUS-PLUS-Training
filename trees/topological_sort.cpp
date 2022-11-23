#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    cout<<"Enter number of edges and vertices: ";
    int n,m; //n:vertices, m:edges
    cin>>n>>m;
    int count = 0;

    //adjacency list
    vector<vector<int>> adj_list(n); //adjacency list
    vector <int> indeg(n,0);
    vector <int> adj(n,0); //vector of size n with all val 0
    cout<<"\nEnter edges (u,v) pairs: "<<endl;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v; //u --> v
        adj.push_back(v);
        indeg[v]++;
    }
    queue <int> pq;
    for (int i=0;i<n;i++)
    {
        if (indeg[i]==0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        count++;   
        int x = pq.front(); 
        pq.pop();
        cout <<x<<" ";
        // x --> v
        for (auto it:adj) 
        {
            indeg[it]--;
            if (indeg[it]==0)
                pq.push(it);
        }
    }
}