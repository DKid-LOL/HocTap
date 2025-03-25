using System;
using System.Collections.Generic;
using System.Text;

abstract class Product
{
    public string? Name { get; set; }
    public int Price { get; set; }
    public virtual void Display()
    {
        Console.WriteLine($"Name: {Name}, Price: {Price}");
    }
}

class Phone : Product
{
    public string? Brand { get; set; }
    public override void Display()
    {
        Console.WriteLine($"Phone - Name: {Name}, Price: {Price}, Brand: {Brand}");
    }
}

class TV : Product
{
    public int ScreenSize { get; set; }
    public override void Display()
    {
        Console.WriteLine($"TV - Name: {Name}, Price: {Price}, Screen Size: {ScreenSize} inches");
    }
}

class Laptop : Product
{
    public string? Processor { get; set; }
    public override void Display()
    {
        Console.WriteLine($"Laptop - Name: {Name}, Price: {Price}, Processor: {Processor}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        List<Product> products = new List<Product>
            {
                new Phone { Name = "iPhone 99", Price = 99999, Brand = "Apple" },
                new Phone { Name = "Samsung Note 20 Ultra 5G", Price = 99999, Brand = "Samsung" },
                new TV { Name = "Samsung TV", Price = 9999, ScreenSize = 55 },
                new TV { Name = "LG TV", Price = 9999, ScreenSize = 55 },
                new Laptop { Name = "MacBook NoPro", Price = 9999, Processor = "M1" },
                new Laptop { Name = "Asus", Price = 9999, Processor = "" }
            };

        foreach (var product in products)
        {
            product.Display();
        }
    }
}

