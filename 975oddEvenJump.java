import java.util.*;
class Solution {
    public int oddEvenJumps(int[] arr) {
        int count = 0;
        int n = arr.length;
        Boolean[] odd = new Boolean[n];
        Boolean[] evn = new Boolean[n];
        Arrays.fill(odd, false);
        Arrays.fill(evn, false);
        odd[n-1] = evn[n-1] = true;
        TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
        tm.put(arr[n-1], n-1);
        for(int i = n-2; i >= 0; i--){
            int v = arr[i];
            if(tm.containsKey(v)){
                evn[i] = odd[tm.get(v)];
                odd[i] = evn[tm.get(v)];
            }else{
                Integer pL = tm.lowerKey(v);
                Integer nH = tm.higherKey(v);
                if(pL != null) evn[i] = odd[tm.get(pL)];
                if(nH != null) odd[i] = evn[tm.get(nH)];
            }
            tm.put(v, i);
        }
        for(int i = 0; i < n; i++) if(odd[i] == true) count++;
        return count;
    }
}