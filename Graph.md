## Disjoint Set - UnionFind
### Table of contents
1. [Graph Valid Tree](#validTreeGraph)
2. [Number of Provinces](#provinces)
3. [The Earliest Moment When Everyone Become Friends](#earliest)


### Graph Valid Tree <a name="validTreeGraph"></a>
##### You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph. Return true if the edges of the given graph make up a valid tree, and false otherwise.
###### Sample example : Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]] Output: true
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
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else{
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
        
    }
    public boolean isConnected(int x, int y){
        return find(x) == find(y);
    }
}

class Solution {
    public boolean validTree(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        for(int i = 0; i < edges.length; i++){
            if(uf.isConnected(edges[i][0], edges[i][1]))
                return false;
            uf.union(edges[i][0], edges[i][1]);
        }
        return (uf.count == 1);
    }
}
```
---
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
---
### The Earliest Moment When Everyone Become Friends <a name="earliest"></a>
##### Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.
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
    
    public boolean isConnected(int x, int y){
        return find(x) == find(y);
    }

}
// sort the array wrt to logs' timestamp, then iterate the array till all the nodes gets connected i.e count becomes n-1
//ignore the edges if nodes are already connected.
class Solution {
    public int earliestAcq(int[][] logs, int n) {
        UnionFind uf = new UnionFind(n);
        Arrays.sort(logs, Comparator.comparingInt(o -> o[0]));
        int m = logs.length;
        int count = 0;
        int i;
        for(i = 0; i < m && count != n-1; i++){
            int u = logs[i][1];
            int v = logs[i][2];
            if(!uf.isConnected(u,v)){
                uf.union(u,v);
                count++;
            }
        }
        if(count == n-1){
            return logs[i-1][0];
        }else return -1;
    }
}
```
