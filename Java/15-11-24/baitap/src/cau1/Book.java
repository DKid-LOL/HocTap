package cau1;

import java.io.Serializable;

public class Book implements Serializable {
    private String ISBN;
    private String title;
    private String author;
    private double price;

    // Constructor mặc định
    public Book() {}

    // Constructor với tham số
    public Book(String ISBN, String title, String author, double price) {
        this.ISBN = ISBN;
        this.title = title;
        this.author = author;
        this.price = price;
    }

    // Getter và Setter
    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    // Override phương thức toString()
    @Override
    public String toString() {
        return "Book{" +
                "ISBN='" + ISBN + '\'' +
                ", Title='" + title + '\'' +
                ", Author='" + author + '\'' +
                ", Price=" + price +
                '}';
    }
}

