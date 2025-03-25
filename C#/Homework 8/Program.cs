using System;
using System.Collections.Generic;
using System.Linq;

public interface IInventory
{
    void AddProduct(Product product);
    void UpdateProduct(string productCode, int quantity, decimal price);
    void RemoveProduct(string productCode);
    void DisplayAllProducts();
    Product SearchProductByName(string productName);
    Product SearchProductByCode(string productCode);
    decimal CalculateTotalInventoryValue();
}

public abstract class InventoryBase : IInventory
{
    protected List<Product> products = new List<Product>();

    public abstract void AddProduct(Product product);
    public abstract void UpdateProduct(string productCode, int quantity, decimal price);
    public abstract void RemoveProduct(string productCode);
    public abstract void DisplayAllProducts();
    public abstract Product SearchProductByName(string productName);
    public abstract Product SearchProductByCode(string productCode);
    public abstract decimal CalculateTotalInventoryValue();
}

public class Inventory : InventoryBase
{
    public override void AddProduct(Product product)
    {
        products.Add(product);
    }

    public override void UpdateProduct(string productCode, int quantity, decimal price)
    {
        var product = products.FirstOrDefault(p => p.Code == productCode);
        if (product != null)
        {
            product.Quantity = quantity;
            product.Price = price;
        }
    }

    public override void RemoveProduct(string productCode)
    {
        var product = products.FirstOrDefault(p => p.Code == productCode);
        if (product != null)
        {
            products.Remove(product);
        }
    }

    public override void DisplayAllProducts()
    {
        foreach (var product in products)
        {
            Console.WriteLine($"Name: {product.Name}, Code: {product.Code}, Quantity: {product.Quantity}, Price: {product.Price}");
        }
    }

    public override Product SearchProductByName(string productName)
    {
        return products.FirstOrDefault(p => p.Name.Equals(productName, StringComparison.OrdinalIgnoreCase));
    }

    public override Product SearchProductByCode(string productCode)
    {
        return products.FirstOrDefault(p => p.Code.Equals(productCode, StringComparison.OrdinalIgnoreCase));
    }

    public override decimal CalculateTotalInventoryValue()
    {
        return products.Sum(p => p.Quantity * p.Price);
    }
}

public class Product
{
    public string Name { get; set; }
    public string Code { get; set; }
    public int Quantity { get; set; }
    public decimal Price { get; set; }
}

class Program
{
    static void Main(string[] args)
    {
        IInventory inventory = new Inventory();

        inventory.AddProduct(new Product { Name = "Product1", Code = "P001", Quantity = 10, Price = 100 });
        inventory.AddProduct(new Product { Name = "Product2", Code = "P002", Quantity = 5, Price = 200 });

        inventory.DisplayAllProducts();

        inventory.UpdateProduct("P001", 15, 150);

        inventory.DisplayAllProducts();

        var product = inventory.SearchProductByName("Product1");
        Console.WriteLine($"Found Product: {product.Name}, Code: {product.Code}, Quantity: {product.Quantity}, Price: {product.Price}");

        var totalValue = inventory.CalculateTotalInventoryValue();
        Console.WriteLine($"Total Inventory Value: {totalValue}");

        inventory.RemoveProduct("P002");

        inventory.DisplayAllProducts();
    }
}
