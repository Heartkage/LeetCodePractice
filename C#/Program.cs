using System;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            BasicCalculator calculator = new BasicCalculator();
            double value = calculator.Calculate("5+8");
            Console.WriteLine($"Value: {value}");
        }
    }
}
