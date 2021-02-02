using System;
using System.Collections.Generic;
using Uitilities;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // BasicCalculator calculator = new BasicCalculator();
            // double value = calculator.Calculate("5+8");
            // Console.WriteLine($"Value: {value}");

            // CurrencyExchange exchanger = new CurrencyExchange();
            // List<int> coins = new List<int>();
            // coins.Add(1000);
            // coins.Add(2000);
            // coins.Add(10000);
            // coins.Add(150000);
            // coins.Add(50000);
            // coins.Add(500000);
            // coins.Add(1500000);

            // Dictionary<int, int> coinOwn = new Dictionary<int, int>();
            // coinOwn.Add(1000, 356);
            // coinOwn.Add(2000, 605);
            // coinOwn.Add(10000, 50);
            // coinOwn.Add(150000, 22);

            // Dictionary<int, int> answers = new Dictionary<int, int>();
            // exchanger.ExchangeExceed(coins, coinOwn, 3004702-7661, ref answers);
            // foreach(var data in answers)
            // {
            //     Console.WriteLine($"Choosing {data.Key}: {data.Value} amount");
            // }

            long a = 36545480;
        
            Console.WriteLine($"Before: {a.InStandard()}");
            Console.WriteLine($"After: {a.ToKMBP()}");
            Console.WriteLine($"After: {((int)a).ToTime()}");
        }
    }
}
