class Solution {
  public:
    int spanningTree(int V,vector<vector<int>>&edges) {

        vector<vector<pair<int,int>>>adj(V);

        for (auto&e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int>vis(V,0);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int wt=it.first;
            int node=it.second;

            if (vis[node])continue;

            vis[node]=1;
            sum+=wt;

            for (auto &nbr:adj[node]) {
                int adjNode=nbr.first;
                int edgeWt=nbr.second;

                if (!vis[adjNode]) {
                    pq.push({edgeWt,adjNode});
                }
            }
        }

        return sum;
    }
};
