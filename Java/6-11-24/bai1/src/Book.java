import java.io.Serializable;
import java.util.List;

public class Book implements Serializable {
    private static final long serialVersionUID = 1L;
    private String id;
    private String bookTitle;
    private String author;
    private int publishedYear;
    private List<String> genre;


    public Book(String id, String bookTitle, String author, int publishedYear, List<String> genre) {
        this.id = id;
        this.bookTitle = bookTitle;
        this.author = author;
        this.publishedYear = publishedYear;
        this.genre = genre;
    }


    public String getId() {
        return id;
    }

    public String getBookTitle() {
        return bookTitle;
    }

    public String getAuthor() {
        return author;
    }

    public int getPublishedYear() {
        return publishedYear;
    }

    public List<String> getGenre() {
        return genre;
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Tên sách: " + bookTitle + ", Tác giả: " + author +
                ", Năm xuất bản: " + publishedYear + ", Thể loại: " + String.join(", ", genre);
    }
}
