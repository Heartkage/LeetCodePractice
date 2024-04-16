#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;

class Solution {
    map<int, vector<int> > UnionFind(vector<vector<int> >& pairs, int totalLength)
    {
        int *group = new int[totalLength];

        for(int i = 0; i < totalLength; i++)
            group[i] = i;
        
        for(int i = 0; i < pairs.size(); i++)
        {
            int f = pairs[i][0];
            int s = pairs[i][1];

            int firstLast = f;
            int secondLast = s;
            while(firstLast != group[firstLast])
                firstLast = group[firstLast];
            while(secondLast != group[secondLast])
                secondLast = group[secondLast];
            if(firstLast == secondLast)
                continue;

            //cout << "First: " << f << ", Second: " << s << endl;
            int current = s; 
            int next;
            do
            {
                next = group[current];
                group[current] = f;
                current = next;
            } while(current != group[current]);
            group[current] = f;

            //for(int i = 0; i < totalLength; i++)
            //    cout << i << " ";
            //cout << endl;
            //for(int i = 0; i < totalLength; i++)
            //    cout << group[i] << " ";
            //cout << endl;
            //cout << endl;
        }

        map<int, vector<int> > output;
        for(int i = 0; i < totalLength; i++)
        {
            int current = i;
            while(current != group[current])
                current = group[current];

            if(output.find(current) != output.end())
                output[current].push_back(i);
            else
            {
                vector<int> group;
                group.push_back(i);
                output.insert(pair<int, vector<int> >(current, group));
            }
        }

        return output;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int> >& pairs) {
        map<int, vector<int> > pairMap = UnionFind(pairs, s.length());
        map<int, vector<int> >::iterator it;
        for(it = pairMap.begin(); it != pairMap.end(); it++)
        {
            vector<int> group = it->second;
            sort(group.begin(), group.end());
            
            string temp;
            for(int i = 0; i < group.size(); i++)
            {
                //cout << "Group[" << i << "] = " << group[i] << ": " << s[group[i]] << endl;
                temp.append(s, group[i], 1);
            }
            //cout << endl;

            sort(temp.begin(), temp.end());
            for(int i = 0; i < group.size(); i++)
                s[group[i]] = temp[i];
        }

        return s;
    }
};

int main(void)
{
    Solution s;

    vector<vector<int> > input;
    vector<int> set1;
    set1.push_back(2);
    set1.push_back(4);
    input.push_back(set1);
    set1.clear();


    set1.push_back(5);
    set1.push_back(7);
    input.push_back(set1);
    set1.clear();

    set1.push_back(1);
    set1.push_back(0);
    input.push_back(set1);
    set1.clear();

    set1.push_back(0);
    set1.push_back(0);
    input.push_back(set1);
    set1.clear();
    
    set1.push_back(4);
    set1.push_back(7);
    input.push_back(set1);
    set1.clear();

    set1.push_back(0);
    set1.push_back(3);
    input.push_back(set1);
    set1.clear();

    set1.push_back(4);
    set1.push_back(1);
    input.push_back(set1);
    set1.clear();

    set1.push_back(1);
    set1.push_back(3);
    input.push_back(set1);
    set1.clear();

    //fqtvkfkt
    cout << s.smallestStringWithSwaps("fqtvkfkt", input) << endl;

    return 0;
}