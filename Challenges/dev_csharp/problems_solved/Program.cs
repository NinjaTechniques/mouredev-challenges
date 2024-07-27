using System;

namespace challenges_mouredev{
    public class FizzBuzz {  /*1-Easy*/
       public int MaxValue { get; set; }
       public int MinValue { get; set; }

       public FizzBuzz(int minValue, int maxValue) {
           this.MinValue = minValue;
           this.MaxValue = maxValue;
       }

       public void ShowNumbersOneToOneHundred(){
         for (int i = this.MinValue; i <= this.MaxValue; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                Console.WriteLine("fizzbuzz");
            }
            else if (i % 3 == 0){
                Console.WriteLine("fizz");
            }
            else if (i % 5 == 0){
                Console.WriteLine("buzz");
            }
            else {
                Console.WriteLine(i);
            }
         }
       }
    }

    public class Program {
        public static void Main(string[] args) {
            Console.WriteLine("\n");

            Console.Write("Enter the min number: ");
            int minValue = int.Parse(Console.ReadLine()); //ReadLine es con MAYUSCULA

            Console.Write("Enter the max number: ");
            int maxValue = int.Parse(Console.ReadLine());

            Console.WriteLine("\n");
            FizzBuzz fizzBuzz = new FizzBuzz(minValue, maxValue);
            fizzBuzz.ShowNumbersOneToOneHundred();


            Console.WriteLine("\n");
        }
    }

}