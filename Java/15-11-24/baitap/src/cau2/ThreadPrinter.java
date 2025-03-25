package cau2;

public class ThreadPrinter extends Thread {
    private Data data;

    public ThreadPrinter(Data data) {
        this.data = data;
    }

    @Override
    public void run() {
        String reversed;
        while ((reversed = data.getReversedString()) != null) {
            System.out.println("Chuỗi đã đảo ngược: " + reversed);
        }
    }
}

