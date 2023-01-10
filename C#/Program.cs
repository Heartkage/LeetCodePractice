using System;
using System.Collections.Generic;
using Uitilities;
using Uitilities.Number;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            TestTree test = new TestTree();
            var heads = test.GenerateTestCase(2, 0);
            for(int i = 0; i < heads.Count; i++){
                test.PrintPreOrderTree(heads[i]);
            }
            Solution100 s = new Solution100();
            Console.WriteLine("Ans: " + s.IsSameTree(heads[0], heads[1]));
        }
    }
}
