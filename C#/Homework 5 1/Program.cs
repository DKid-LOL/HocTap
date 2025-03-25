using System;
using System.Collections.Generic;

namespace ProductApp
{
    public interface IProduct
    {
        int Id { get; set; }
        string SKU { get; set; }
        string Name { get; set; }
        decimal Price { get; set; }
        void DisplayInfo();
    }

    public abstract class Product : IProduct
    {
        public int Id { get; set; }
        public string SKU { get; set; }
        public string Name { get; set; }
        public decimal Price { get; set; }

        public abstract void DisplayInfo();
    }

    public class Electronic : Product
    {
        public override void DisplayInfo()
        {
            Console.WriteLine($"Electronic Product - Id: {Id}, SKU: {SKU}, Name: {Name}, Price: {Price}");
        }
    }

    public class Furniture : Product
    {
        public override void DisplayInfo()
        {
            Console.WriteLine($"Furniture Product - Id: {Id}, SKU: {SKU}, Name: {Name}, Price: {Price}");
        }
    }

    public class Clothing : Product
    {
        public override void DisplayInfo()
        {
            Console.WriteLine($"Clothing Product - Id: {Id}, SKU: {SKU}, Name: {Name}, Price: {Price}");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<IProduct> products = new List<IProduct>
            {
                new Electronic { Id = 1, SKU = "E001", Name = "Laptop", Price = 1000.00m },
                new Furniture { Id = 2, SKU = "F001", Name = "Chair", Price = 150.00m },
                new Clothing { Id = 3, SKU = "C001", Name = "T-Shirt", Price = 20.00m }
            };

            foreach (var product in products)
            {
                product.DisplayInfo();
            }
        }
    }
}
