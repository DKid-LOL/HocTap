public class BankTransactionDemo {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(0);


        DepositThread depositThread = new DepositThread(account);
        WithdrawThread withdrawThread = new WithdrawThread(account);

        depositThread.start();
        withdrawThread.start();
    }
}