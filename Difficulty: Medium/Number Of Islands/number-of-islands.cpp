// User function Template for C++
class Solution {
  public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        if (u != v) {
            if (rank[u] < rank[v]) parent[u] = v;
            else if (rank[v] < rank[u]) parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> parent(n*m);
        vector<int> rank(n*m,0);
        for(int i=0;i<n*m;i++)parent[i]=i;
        vector<vector<int>> matrix(n,vector<int>(m,0));
        
        vector<int> res;
        int noi=0;
        vector<int> rows={1,-1,0,0};
        vector<int> cols={0,0,1,-1};
        
        for(auto &op:operators){
            int r=op[0];
            int c=op[1];
            if(matrix[r][c]==1){
                res.push_back(noi);
                continue;
            }
            matrix[r][c]=1;
            noi++;
            int node=r*m+c;
            
            for(int i=0;i<4;i++){
                int nr=r+rows[i];
                int nc=c+cols[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && matrix[nr][nc]==1){
                    int adjNode=nr*m+nc;
                    if(findParent(node,parent)!=findParent(adjNode,parent)){
                        unionSets(node,adjNode,parent,rank);
                        noi--;   
                    }
                }
            }
            res.push_back(noi);
        }
        return res;
    }
};
