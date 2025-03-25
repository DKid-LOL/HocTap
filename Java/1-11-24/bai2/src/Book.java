import java.io.*;

class Book implements Serializable {
    private static final long serialVersionUID = 1L;
    private String bookID;
    private String title;
    private String author;


    public Book() {}


    public Book(String bookID, String title, String author) {
        this.bookID = bookID;
        this.title = title;
        this.author = author;
    }


    public String getBookID() {
        return bookID;
    }

    public void setBookID(String bookID) {
        this.bookID = bookID;
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


    @Override
    public String toString() {
        return "Book ID: " + bookID + ", Title: " + title + ", Author: " + author;
    }
}


