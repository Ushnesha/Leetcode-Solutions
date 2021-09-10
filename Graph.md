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
class Solution {
    
    public int find(int parent[], int x){
        if(parent[x] == -1)
            return x;
        return find(parent, parent[x]);
    }
    
    public void union(int parent[], int x, int y){
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        if(rootX != rootY)
            parent[rootY] = rootX;
    }
    // initially the parent array has all -1 values,
    //after union of the nodes which are connected, only parent array elements of root nodes are -1, rest have their respective root node
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int parent[] = new int[n];
        Arrays.fill(parent, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i != j) && (isConnected[i][j] == 1))
                    union(parent,i,j);
            }
        }
        int count = 0;
        for(int i : parent){
            if(i == -1) count++;
        }
        return count;
    }
}
```
