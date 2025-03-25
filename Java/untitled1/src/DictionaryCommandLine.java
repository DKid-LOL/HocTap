import java.util.Scanner;

public class DictionaryCommandLine {
    private static DictionaryManagement dictionaryManagement = new DictionaryManagement();
    private static Dictionary dictionary = new Dictionary(100);

    // Hàm nhập từ điển
    public static void dictionaryBasic() {
        dictionaryManagement.insertFromCommandline(dictionary);
        dictionaryManagement.showAllWords(dictionary);
    }

    // Hàm tìm kiếm từ trong từ điển
    public static void dictionarySearcher() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter search keyword: ");
        String searchKeyword = scanner.nextLine();
        dictionaryManagement.dictionarySearcher(dictionary, searchKeyword);
    }

    // Hàm để thêm từ mới
    public static void addWord() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter word in English: ");
        String wordTarget = scanner.nextLine();
        System.out.print("Enter word explanation in Vietnamese: ");
        String wordExplain = scanner.nextLine();
        dictionaryManagement.insertWord(dictionary, wordTarget, wordExplain);
    }

    // Hàm để sửa từ
    public static void updateWord() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter word to update: ");
        String oldWordTarget = scanner.nextLine();
        System.out.print("Enter new word in English: ");
        String newWordTarget = scanner.nextLine();
        System.out.print("Enter new explanation in Vietnamese: ");
        String newWordExplain = scanner.nextLine();
        dictionaryManagement.updateWord(dictionary, oldWordTarget, newWordTarget, newWordExplain);
    }

    // Hàm để xóa từ
    public static void deleteWord() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter word to delete: ");
        String wordTarget = scanner.nextLine();
        dictionaryManagement.deleteWord(dictionary, wordTarget);
    }

    // Hàm xuất từ điển ra tệp
    public static void exportDictionary() {
        dictionaryManagement.dictionaryExportToFile(dictionary);
    }

    // Hàm chạy chương trình chính
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("1. Add Word");
            System.out.println("2. Update Word");
            System.out.println("3. Delete Word");
            System.out.println("4. Search Word");
            System.out.println("5. Export Dictionary");
            System.out.println("6. Show All Words");
            System.out.println("7. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // Consume the newline character

            switch (choice) {
                case 1:
                    addWord();
                    break;
                case 2:
                    updateWord();
                    break;
                case 3:
                    deleteWord();
                    break;
                case 4:
                    dictionarySearcher();
                    break;
                case 5:
                    exportDictionary();
                    break;
                case 6:
                    dictionaryManagement.showAllWords(dictionary);
                    break;
                case 7:
                    System.out.println("Goodbye!");
                    return;
                default:
                    System.out.println("Invalid option, please try again.");
            }
        }
    }
}
