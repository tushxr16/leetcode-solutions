class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<String>();
        Integer sz = target.length, cnt = 1;
        for(Integer i=0;i<sz;i++){
            if(target[i]!=cnt){
                i--;
                ans.add("Push");
                ans.add("Pop");
            }else{
                ans.add("Push");
            }
            cnt++;
        }
        return ans;
    }
}