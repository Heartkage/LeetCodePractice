using System.Collections;
using System.Collections.Generic;

public class Solution165 {
    public int CompareVersion(string version1, string version2) {
        string []splitStrings = version1.Split('.');
        string []splitStrings2 = version2.Split('.');
        int index = 0;
        while(index < splitStrings.Length || index < splitStrings2.Length)
        {
            int num1 = 0, num2 = 0;
            if(index < splitStrings.Length)
                int.TryParse(splitStrings[index], out num1);
            if(index < splitStrings2.Length)
                int.TryParse(splitStrings2[index], out num2);

            if(num1 != num2)
                return num1.CompareTo(num2);
            index++;
        }
        return 0;
    }
}