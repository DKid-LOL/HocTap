using System;
using System.Collections.Generic;

namespace LibraryManagement
{
    abstract class Library
    {
        protected List<string> books = new List<string>();

        public abstract void AddBook(string bookName);
        public abstract void ListBooks();
        public abstract void SearchBook(string bookName);
        public abstract void RemoveBook(string bookName);
    }

    class LibraryManager : Library
    {
        public override void AddBook(string bookName)
        {
            books.Add(bookName);
            Console.WriteLine("Book added successfully.");
        }

        public override void ListBooks()
        {
            Console.WriteLine("Books in the library:");
            foreach (var book in books)
            {
                Console.WriteLine(book);
            }
        }

        public override void SearchBook(string bookName)
        {
            if (books.Contains(bookName))
            {
                Console.WriteLine("Book found.");
            }
            else
            {
                Console.WriteLine("Book not found.");
            }
        }

        public override void RemoveBook(string bookName)
        {
            if (books.Remove(bookName))
            {
                Console.WriteLine("Book removed successfully.");
            }
            else
            {
                Console.WriteLine("Book not found.");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            LibraryManager libraryManager = new LibraryManager();

            while (true)
            {
                Console.WriteLine("Library Management System");
                Console.WriteLine("1. Add Library");
                Console.WriteLine("2. List Books");
                Console.WriteLine("3. Search Book");
                Console.WriteLine("4. Remove Book");
                Console.WriteLine("5. Exit");
                Console.Write("Select an option: ");
                string choice = Console.ReadLine();

                switch (choice)
                {
                    case "1":
                        Console.Write("Enter book name: ");
                        string bookName = Console.ReadLine();
                        libraryManager.AddBook(bookName);
                        break;
                    case "2":
                        libraryManager.ListBooks();
                        break;
                    case "3":
                        Console.Write("Enter book name to search: ");
                        string searchName = Console.ReadLine();
                        libraryManager.SearchBook(searchName);
                        break;
                    case "4":
                        Console.Write("Enter book name to remove: ");
                        string removeName = Console.ReadLine();
                        libraryManager.RemoveBook(removeName);
                        break;
                    case "5":
                        return;
                    default:
                        Console.WriteLine("Invalid option. Please try again.");
                        break;
                }
            }
        }
    }
}
