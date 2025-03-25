import java.io.*;
import java.util.ArrayList;
import java.util.regex.Pattern;

class LibraryManager {
    private final ArrayList<Book> books = new ArrayList<>();
    private static final String BOOK_ID_REGEX = "^[FNS][MH][PD]\\d{4}$";


    public void inputBooks() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            System.out.print("Nhập Book ID (F/N/S cho thể loại, M/H cho ca, P/D cho định dạng, 4 chữ số): ");
            String bookID = reader.readLine();

            if (!Pattern.matches(BOOK_ID_REGEX, bookID)) {
                System.out.println("Book ID không hợp lệ. Vui lòng nhập lại.");
                continue;
            }

            System.out.print("Nhập tên sách: ");
            String title = reader.readLine();

            System.out.print("Nhập tên tác giả: ");
            String author = reader.readLine();

            books.add(new Book(bookID, title, author));

            System.out.print("Bạn có muốn thêm sách khác không? (y/n): ");
            String choice = reader.readLine();
            if (!choice.equalsIgnoreCase("y")) break;
        }
    }


    public int countBooksByAuthor(String authorName) {
        int count = 0;
        for (Book book : books) {
            if (book.getAuthor().equalsIgnoreCase(authorName)) {
                count++;
            }
        }
        return count;
    }


    public void serializeBooks(String filename) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(filename))) {
            oos.writeObject(books);
            System.out.println("Danh sách sách đã được ghi vào file " + filename);
        } catch (IOException e) {
            System.out.println("Lỗi khi ghi file: " + e.getMessage());
        }
    }


    public void deserializeBooks(String filename) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(filename))) {
            ArrayList<Book> deserializedBooks = (ArrayList<Book>) ois.readObject();
            System.out.println("Danh sách sách đọc từ file:");
            for (Book book : deserializedBooks) {
                System.out.println(book);
            }
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Lỗi khi đọc file: " + e.getMessage());
        }
    }
}

