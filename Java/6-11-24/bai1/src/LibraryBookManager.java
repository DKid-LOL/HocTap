import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class LibraryBookManager {
    private final Map<String, Integer> genreCountMap = new HashMap<>();
    private int totalBooks = 0;


    public LibraryBookManager() {
        genreCountMap.put("Tiểu thuyết", 10);
        genreCountMap.put("Khoa học", 7);
        genreCountMap.put("Văn học", 12);
    }


    public synchronized void incrementGenreCount(String genre) {
        int count = genreCountMap.getOrDefault(genre, 0) + 1;
        genreCountMap.put(genre, count);
        totalBooks++;
        System.out.println("Thể loại: " + genre + ", Số lượng: " + count);
    }


    public synchronized void displayTotalBooks() {
        System.out.println("Tổng số sách hiện có: " + totalBooks);
    }


    class GenreUpdaterThread extends Thread {
        private final String[] genres = {"Tiểu thuyết", "Khoa học", "Văn học"};
        private final Random random = new Random();

        @Override
        public void run() {
            while (true) {
                String genre = genres[random.nextInt(genres.length)];
                incrementGenreCount(genre);
                try {
                    Thread.sleep(1000);  // Tạm dừng 1 giây
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        }
    }


    class TotalBooksDisplayThread extends Thread {
        @Override
        public void run() {
            while (true) {
                displayTotalBooks();
                try {
                    Thread.sleep(1000);  // Tạm dừng 1 giây
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        }
    }

    public static void main(String[] args) {
        LibraryBookManager manager = new LibraryBookManager();


        GenreUpdaterThread genreUpdater = manager.new GenreUpdaterThread();
        TotalBooksDisplayThread totalBooksDisplay = manager.new TotalBooksDisplayThread();

        genreUpdater.start();
        totalBooksDisplay.start();
    }
}
