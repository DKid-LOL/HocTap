using System;
using System.Collections.Generic;
using System.Linq;

namespace Homework_10
{
    public interface ILibraryOperations
    {
        void AddBook(Book book);
        void UpdateBook(string bookId, string newName, int newQuantity);
        void RemoveBook(string bookId);
        void DisplayBooks();
        Book SearchBookByName(string name);
        Book SearchBookById(string bookId);
        List<Book> SearchBooksByAuthor(string author);
        int GetTotalBooks();
        Dictionary<string, int> GetBooksCountByGenre();
    }

    public abstract class Book
    {
        public string Name { get; set; }
        public string BookId { get; set; }
        public string Author { get; set; }
        public string Genre { get; set; }
        public int Quantity { get; set; }

        protected Book(string name, string bookId, string author, string genre, int quantity)
        {
            Name = name;
            BookId = bookId;
            Author = author;
            Genre = genre;
            Quantity = quantity;
        }
    }

    public class LibraryBook : Book
    {
        public LibraryBook(string name, string bookId, string author, string genre, int quantity)
            : base(name, bookId, author, genre, quantity)
        {
        }
    }

    public class Library : ILibraryOperations
    {
        private List<Book> books = new List<Book>();

        public void AddBook(Book book)
        {
            books.Add(book);
        }

        public void UpdateBook(string bookId, string newName, int newQuantity)
        {
            var book = books.FirstOrDefault(b => b.BookId == bookId);
            if (book != null)
            {
                book.Name = newName;
                book.Quantity = newQuantity;
            }
        }

        public void RemoveBook(string bookId)
        {
            var book = books.FirstOrDefault(b => b.BookId == bookId);
            if (book != null)
            {
                books.Remove(book);
            }
        }

        public void DisplayBooks()
        {
            foreach (var book in books)
            {
                Console.WriteLine($"Name: {book.Name}, ID: {book.BookId}, Author: {book.Author}, Genre: {book.Genre}, Quantity: {book.Quantity}");
            }
        }

        public Book SearchBookByName(string name)
        {
            return books.FirstOrDefault(b => b.Name.Equals(name, StringComparison.OrdinalIgnoreCase));
        }

        public Book SearchBookById(string bookId)
        {
            return books.FirstOrDefault(b => b.BookId == bookId);
        }

        public List<Book> SearchBooksByAuthor(string author)
        {
            return books.Where(b => b.Author.Equals(author, StringComparison.OrdinalIgnoreCase)).ToList();
        }

        public int GetTotalBooks()
        {
            return books.Sum(b => b.Quantity);
        }

        public Dictionary<string, int> GetBooksCountByGenre()
        {
            return books.GroupBy(b => b.Genre)
                        .ToDictionary(g => g.Key, g => g.Sum(b => b.Quantity));
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Library library = new Library();

            library.AddBook(new LibraryBook("Book1", "ID1", "Author1", "Genre1", 10));
            library.AddBook(new LibraryBook("Book2", "ID2", "Author2", "Genre2", 5));

            library.DisplayBooks();

            library.UpdateBook("ID1", "UpdatedBook1", 15);

            library.DisplayBooks();

            library.RemoveBook("ID2");

            library.DisplayBooks();

            var book = library.SearchBookByName("UpdatedBook1");
            Console.WriteLine($"Found book: {book.Name}");

            Console.WriteLine($"Total books: {library.GetTotalBooks()}");

            var booksCountByGenre = library.GetBooksCountByGenre();
            foreach (var genre in booksCountByGenre)
            {
                Console.WriteLine($"Genre: {genre.Key}, Count: {genre.Value}");
            }
        }
    }
}
