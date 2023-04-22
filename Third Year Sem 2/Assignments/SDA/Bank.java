// This is assignment 4

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

class BankAccount {
    int accountNumber;
    int balance;

    public BankAccount(int accountNumber) {
        System.out.println("*** Bank Account constructor");
        this.accountNumber = accountNumber;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public int getBalance() {
        return balance;
    }

    public void debit(int amount) {
        System.out.println("*** BankAccount.debit()");
        balance -= amount;
    }

    public void credit(int amount) {
        System.out.println("*** BankAccount.credit()");
        balance += amount;
    }
}

class BankExceptions extends Exception{
    public BankExceptions(String message){
        super(message);
    }

    public static void lowBalanceException(int amount1, int transferAmount) throws Exception{
        if(amount1-transferAmount < 0){
            throw new BankExceptions("Insufficient funds");
        }
    }
}

class Bank {
    static Map<Integer, Object> bankAccounts = new HashMap<Integer, Object>();
    
    //logging logger
    private static final Logger LOGGER = Logger.getLogger(Bank.class.getName()); 
    
    public static void transfer(BankAccount from, BankAccount to, int amount){
        LOGGER.log(Level.SEVERE,"Transfer Value: "+amount+" Amount in from account before transfer: "+from.getBalance()+" Amount in to account before: "+to.getBalance());
        from.debit(amount);
        to.credit(amount);
        LOGGER.log(Level.SEVERE,"Transfer Value: "+amount+" Amount in from account After transfer: "+from.getBalance()+" Amount in to account after transfer: "+to.getBalance());
    }

    public static void main(String[] args) throws Exception{
        System.out.println("This is a simple dempstration if logging used for  exception handling & keeping records");
        Scanner sc = new Scanner(System.in);
        System.out.println("***Creating account 1");
        BankAccount acc1 = new BankAccount(1);
        System.out.print("Enter Amount to be credited in account 1: ");
        int a1 = sc.nextInt();
        acc1.credit(a1);
        bankAccounts.put(acc1.getAccountNumber(), acc1);
        
        System.out.println("***Creating account 2");
        BankAccount acc2 = new BankAccount(2);
        System.out.print("Enter Amount to be credited in account 2: ");
        int a2 = sc.nextInt();
        acc2.credit(a2);
        bankAccounts.put(acc2.getAccountNumber(), acc2);


        System.out.println("***Balance acount 1: " + acc1.getBalance());
        System.out.println("***Balance acount 2: " + acc2.getBalance());

        // Transfer some money
        System.out.println("***Enter Transfer amount from account 1 to account 2");
        int t = sc.nextInt();
        try{
            BankExceptions.lowBalanceException(acc1.getBalance(),t);
        }
        catch(BankExceptions e){
            System.out.println(e.getMessage());
            System.exit(-1);
        }

        transfer(acc1, acc2, t);

        System.out.println("***Balance acount 1: " + acc1.getBalance());
        System.out.println("***Balance acount 2: " + acc2.getBalance());

        sc.close();
    }
}