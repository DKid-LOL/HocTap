import java.util.Scanner;

public class OddEvenDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập số nguyên dương n: ");
        int n = scanner.nextInt();

        SharedData sharedData = new SharedData();
        OddThread oddThread = new OddThread(sharedData, n);
        EvenThread evenThread = new EvenThread(sharedData, n);

        oddThread.start();
        evenThread.start();
    }
}