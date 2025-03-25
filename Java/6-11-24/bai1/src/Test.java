import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        LibraryManager libraryManager = new LibraryManager();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            for (int i = 0; i < 5; i++) {
                System.out.println("Nhập thông tin sách thứ " + (i + 1) + ":");

                System.out.print("ID: ");
                String id = reader.readLine();

                String bookTitle;
                while (true) {
                    System.out.print("Tên sách: ");
                    bookTitle = reader.readLine();
                    if (bookTitle.length() >= 5) break;
                    else System.out.println("Tên sách phải có ít nhất 5 ký tự.");
                }

                System.out.print("Tác giả: ");
                String author = reader.readLine();

                int publishedYear;
                while (true) {
                    System.out.print("Năm xuất bản: ");
                    try {
                        publishedYear = Integer.parseInt(reader.readLine());
                        if (publishedYear > 1900) break;
                        else System.out.println("Năm xuất bản phải lớn hơn 1900.");
                    } catch (NumberFormatException e) {
                        System.out.println("Năm xuất bản phải là số nguyên.");
                    }
                }

                System.out.print("Thể loại (nhập các thể loại cách nhau bởi dấu phẩy): ");
                String genreInput = reader.readLine();
                List<String> genre = List.of(genreInput.split(", "));

                Book book = new Book(id, bookTitle, author, publishedYear, genre);
                libraryManager.addBook(book);
            }


            libraryManager.saveToFile("library_data.txt");


            libraryManager.loadFromFile("library_data.txt");
            System.out.println("Danh sách sách trong thư viện:");
            libraryManager.displayBooks();


            System.out.print("Nhập từ khóa tìm kiếm (theo tên sách hoặc tác giả): ");
            String keyword = reader.readLine();
            libraryManager.searchBook(keyword);

        } catch (IOException e) {
            System.out.println("Lỗi khi nhập dữ liệu: " + e.getMessage());
        }
    }
}
