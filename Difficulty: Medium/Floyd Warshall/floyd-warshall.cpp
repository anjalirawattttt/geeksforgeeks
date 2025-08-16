// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // i==j dist->0
        //i->j edge exists dist->weight
        // else dist->1e8
        int V=dist.size();
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][k]!=1e8 && dist[k][j]!=1e8){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);     
                    }
                }
            }
        }
    }
};