package cau2;

public class Data {
    private String[] data = {"Hello", "Good", "Bad", "Bye", "Happy", "Sad", "Speed"};
    private String reversedString;
    private boolean isProcessed = false;

    // Lấy chuỗi từ mảng dựa trên chỉ số
    public synchronized String getString(int index) {
        if (index >= data.length) {
            return null;
        }
        return data[index];
    }

    // Lưu chuỗi đã đảo ngược
    public synchronized void setReversedString(String reversed) {
        while (isProcessed) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        this.reversedString = reversed;
        isProcessed = true;
        notifyAll();
    }

    // Lấy chuỗi đã đảo ngược
    public synchronized String getReversedString() {
        while (!isProcessed) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        isProcessed = false;
        notifyAll();
        return reversedString;
    }
}

