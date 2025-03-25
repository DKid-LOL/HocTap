import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class LibraryManager {
    private List<Book> books = new ArrayList<>();


    public void addBook(Book book) {
        books.add(book);
    }


    public void saveToFile(String filename) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
            oos.writeObject(books);
            System.out.println("Lưu thành công vào file " + filename);
        } catch (IOException e) {
            System.out.println("Lỗi khi lưu file: " + e.getMessage());
        }
    }


    public void loadFromFile(String filename) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {
            books = (List<Book>) ois.readObject();
            System.out.println("Đọc thành công từ file " + filename);
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi khi đọc file: " + e.getMessage());
        }
    }


    public void displayBooks() {
        for (Book book : books) {
            System.out.println(book);
        }
    }


    public void searchBook(String keyword) {
        boolean found = false;
        for (Book book : books) {
            if (book.getBookTitle().contains(keyword) || book.getAuthor().contains(keyword)) {
                System.out.println(book);
                found = true;
            }
        }
        if (!found) {
            System.out.println("KHÔNG TÌM THẤY");
        }
    }
}
