import java.util.Scanner;

class SharedData {
    private boolean printOdd = true;  // Biến kiểm tra trạng thái in số lẻ

    public synchronized void printOdd(int number) {
        while (!printOdd) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("Luồng lẻ: " + number);
        printOdd = false;
        notify();
    }

    public synchronized void printEven(int number) {
        while (printOdd) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        System.out.println("Luồng chẵn: " + number);
        printOdd = true;
        notify();
    }
}

class OddThread extends Thread {
    private final SharedData sharedData;
    private final int n;

    public OddThread(SharedData sharedData, int n) {
        this.sharedData = sharedData;
        this.n = n;
    }

    @Override
    public void run() {
        for (int i = 1; i <= n; i += 2) {
            sharedData.printOdd(i);
        }
    }
}

class EvenThread extends Thread {
    private final SharedData sharedData;
    private final int n;

    public EvenThread(SharedData sharedData, int n) {
        this.sharedData = sharedData;
        this.n = n;
    }

    @Override
    public void run() {
        for (int i = 0; i <= n; i += 2) {
            sharedData.printEven(i);
        }
    }
}