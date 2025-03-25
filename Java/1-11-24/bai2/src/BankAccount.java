import java.util.Random;

class BankAccount {
    private int balance;

    public BankAccount(int initialBalance) {
        this.balance = initialBalance;
    }


    public synchronized void deposit(int amount) {
        balance += amount;
        System.out.println("Thread 1 nạp " + amount + " VND, số dư hiện tại là " + balance + " VND.");
        notify();
    }


    public synchronized void withdraw(int amount) {

        while (balance < amount) {
            System.out.println("Thread 2 cố gắng rút " + amount + " VND, nhưng số dư không đủ. Chờ nạp thêm...");
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        balance -= amount;
        System.out.println("Thread 2 rút " + amount + " VND, số dư hiện tại là " + balance + " VND.");
    }


    public int getBalance() {
        return balance;
    }
}

// Luồng nạp
class DepositThread extends Thread {
    private final BankAccount account;
    private final Random random = new Random();

    public DepositThread(BankAccount account) {
        this.account = account;
    }

    @Override
    public void run() {
        while (true) {
            int amount = 100 + random.nextInt(901); // Số tiền ngẫu nhiên từ 100 đến 1000
            account.deposit(amount);
            try {
                Thread.sleep(3000); // Tạm dừng 3 giây
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}

// Luồng rút
class WithdrawThread extends Thread {
    private final BankAccount account;
    private final Random random = new Random();

    public WithdrawThread(BankAccount account) {
        this.account = account;
    }

    @Override
    public void run() {
        while (true) {
            int amount = 100 + random.nextInt(401); // Số tiền ngẫu nhiên từ 100 đến 500
            account.withdraw(amount);
            try {
                Thread.sleep(4000); // Tạm dừng 4 giây
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                break;
            }
        }
    }
}