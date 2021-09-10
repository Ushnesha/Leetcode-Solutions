## Disjoint Set - UnionFind
### Table of contents
1. [Number of Provinces](#provinces)


### Number of Provinces <a name="provinces"></a>
##### You are given an n x n matrix isConnected where isConnected[i]\[j] = 1 if the ith city and the jth city are directly connected, and isConnected[i]\[j] = 0 otherwise. Return the total number of provinces.
###### Sample example : Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]] Output: 2
| Data Structure | Language | Time Complexity (Find) | Time Complexity (Union) | Space Complexity |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| Disjoint Set | Java | O(logN) | O(logN) | O(n) |
```java
class UnionFind{
    int root[];
    int rank[];
    int count;
    public UnionFind(int size){
        root = new int[size];
        rank = new int[size];
        count = size;
        for(int i = 0; i < size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    public int find(int x){
        if(x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    
    public void union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY])
                //make rootx as the root of rooty
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                //make rooty as the root of rootx
                root[rootX] = rootY;
            else{
                //make rootx as the root of rooty
                root[rootY] = rootX;
                //increase rank of the rootx
                rank[rootX] += 1;
            }
            count--;
        }
    }
    
    public int getCount(){
        return count;
    }

}
class Solution {
    //initially all nodes are itself a province i.e count = total number of nodes
    //then after each union of nodes, the number of province gets decreased as size of province gets increased
    //finally when all the nodes are connected to their respective province, the count will give the total number of provinces
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        UnionFind prov = new UnionFind(n);
        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1)
                    prov.union(i,j);
            }
        }
        return prov.getCount();
    }
}
```
