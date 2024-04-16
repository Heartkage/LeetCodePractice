using System.Collections;
using System.Collections.Generic;
public class Solution131 {
    bool IsPalindrome(ref string subString){
        var str = new string(subString.Reverse().ToArray());
        return str.CompareTo(subString) == 0;
    }
    private void RecursivePartition(IList<IList<string>> ans, IList<string> currentAns, ref string subString){
        if(subString.Length == 0){
            IList<string> result = new List<string>(currentAns);
            ans.Add(result);
            return;
        }

        for(int i = 0; i < subString.Length; i++){
            var subStr = subString.Substring(0, i+1);
            if(IsPalindrome(ref subStr)){
                currentAns.Add(subStr);
                var sub = subString.Substring(i+1);
                RecursivePartition(ans, currentAns, ref sub);
                currentAns.RemoveAt(currentAns.Count - 1);
            }
        }
    }

    public IList<IList<string>> Partition(string s) {
        IList<IList<string>> ans =  new List<IList<string>>();
        IList<string> currentAns = new List<string>();
        RecursivePartition(ans, currentAns, ref s);

        return ans;
    }
}