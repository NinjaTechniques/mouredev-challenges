namespace csharp_sintax{
    /*Herencia by Hector de Leon: https://www.youtube.com/watch?v=j8sxDnr7nPY*/
    class Sale {
        public decimal Total { get; set; }
        public decimal _some; //Atributo privado por convencion

        public Sale (decimal total) {
            this.Total = total;
        }

        public string GetInfo(){
            return $"Total: {this.Total}";
        }
    }


    class Program {
        static void Main(string[] args) {
            Console.WriteLine("\n");

            Sale sale = new Sale(100);
            Console.WriteLine(sale.GetInfo());

            Console.WriteLine("\n");
        }
    }
}