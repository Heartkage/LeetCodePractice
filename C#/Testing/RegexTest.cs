using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Collections;
public class RegexTest
{
    public Dictionary<string, List<int>> FindAllAppearStrings(IList<string> _wordList, string _s, out bool possible)
    {
        possible = true;
        Dictionary<string, List<int>> answer = new Dictionary<string, List<int>>();
        for(int i = 0; i < _wordList.Count; i++)
        {
            string pattern = string.Format($"({_wordList[i]})");
            Regex rx = new Regex(pattern, RegexOptions.Compiled);
            MatchCollection matches = rx.Matches(_s);
            if(matches.Count > 0)
            {
                foreach(Match m in matches)
                {
                    Console.WriteLine("The Word ({0}) appears at {1}.", m.Value, m.Index);
                    if(!answer.ContainsKey(m.Value))
                    {
                        List<int> indexList = new List<int>();
                        answer.Add(m.Value, indexList);
                    }

                    answer[m.Value].Add(m.Index);
                }
            }
            else
            {
                possible = false;
                break;
            }
        }

        

        return answer;
    }
}