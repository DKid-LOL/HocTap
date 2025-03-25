import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LibraryApp {
    public static void main(String[] args) throws IOException {
        LibraryManager libraryManager = new LibraryManager();


        libraryManager.inputBooks();


        libraryManager.serializeBooks("library_books.ser");


        libraryManager.deserializeBooks("library_books.ser");


        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Nhập tên tác giả để đếm số sách: ");
        String authorName = reader.readLine();
        int count = libraryManager.countBooksByAuthor(authorName);
        System.out.println("Số sách của tác giả " + authorName + ": " + count);
    }
}