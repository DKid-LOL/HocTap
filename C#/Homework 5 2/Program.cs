using System;

namespace PaymentSystem
{
    public interface IPayment
    {
        void ProcessPayment();
        void PrintPaymentInfo();
    }

    public abstract class Payment : IPayment
    {
        public string PaymentType { get; set; }
        public decimal Amount { get; set; }

        public Payment(string paymentType, decimal amount)
        {
            PaymentType = paymentType;
            Amount = amount;
        }

        public abstract void ProcessPayment();

        public void PrintPaymentInfo()
        {
            Console.WriteLine($"Payment Type: {PaymentType}, Amount: {Amount}");
        }
    }

    public class CreditCardPayment : Payment
    {
        public string CardNumber { get; set; }

        public CreditCardPayment(decimal amount, string cardNumber)
            : base("Credit Card", amount)
        {
            CardNumber = cardNumber;
        }

        public override void ProcessPayment()
        {
            Console.WriteLine("Processing credit card payment...");
        }
    }

    public class EWalletPayment : Payment
    {
        public string WalletId { get; set; }

        public EWalletPayment(decimal amount, string walletId)
            : base("E-Wallet", amount)
        {
            WalletId = walletId;
        }

        public override void ProcessPayment()
        {
            Console.WriteLine("Processing e-wallet payment...");
        }
    }

    public class DirectPayment : Payment
    {
        public DirectPayment(decimal amount)
            : base("Direct Payment", amount)
        {
        }

        public override void ProcessPayment()
        {
            Console.WriteLine("Processing direct payment...");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Payment creditCardPayment = new CreditCardPayment(100.0m, "1234-5678-9012-3456");
            Payment eWalletPayment = new EWalletPayment(200.0m, "wallet123");
            Payment directPayment = new DirectPayment(300.0m);

            creditCardPayment.PrintPaymentInfo();
            eWalletPayment.PrintPaymentInfo();
            directPayment.PrintPaymentInfo();
        }
    }
}
