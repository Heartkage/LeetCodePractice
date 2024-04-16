using System;
using System.Collections.Generic;
using Uitilities;
using Uitilities.Number;

/*
    cd to C# folder -> dotnet run(in terminal)
*/

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Solved104();
        }

        static void Solve100(){
            TestTree test = new TestTree();
            var heads = test.GenerateTestCase(2, 0);
            for(int i = 0; i < heads.Count; i++){
                test.PrintPreOrderTree(heads[i]);
            }
            Solution100 s = new Solution100();
            Console.WriteLine("Ans: " + s.IsSameTree(heads[0], heads[1]));
        }
    
        static void Solved131(){
            Solution131 s = new Solution131();
            var res = s.Partition("aab");
            foreach(var list in res){
                foreach(var innerList in list){
                    Console.WriteLine(innerList);
                }
                Console.WriteLine("");
            }
        }

        static void Solved104(){
            TestTree test = new TestTree();
            var heads = test.GenerateTestCase(1, 9);
            test.PrintPreOrderTree(heads[0]);
            Console.WriteLine("----Start----");
            Solution104 s = new Solution104();
            Console.WriteLine(s.MaxDepth(heads[0]));
        }
    }
}
