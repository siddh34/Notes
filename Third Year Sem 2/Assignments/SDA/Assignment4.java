import java.util.HashMap;
import java.util.Map;

// import org.jboss.aop.joinpoint.ConstructorInvocation;
// import org.jboss.aop.joinpoint.FieldWriteInvocation;
// import org.jboss.aop.joinpoint.MethodInvocation;

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

class Bank {
    static Map<Integer, Object> bankAccounts = new HashMap<Integer, Object>();

    public static void transfer(BankAccount from, BankAccount to, int amount) {
        from.debit(amount);
        to.credit(amount);
    }

    public static void main(String[] args) {
        System.out.println("*** Creating account 1");
        BankAccount acc1 = new BankAccount(1);
        acc1.credit(150);
        bankAccounts.put(acc1.getAccountNumber(), acc1);

        System.out.println("*** Creating account 2");
        BankAccount acc2 = new BankAccount(2);
        acc2.credit(230);
        bankAccounts.put(acc2.getAccountNumber(), acc2);

        System.out.println("*** Balance acount 1: " + acc1.getBalance());
        System.out.println("*** Balance acount 2: " + acc2.getBalance());

        // Transfer some money
        System.out.println("*** Transfer 50 from account 1 to account 2");
        transfer(acc1, acc2, 50);

        System.out.println("*** Balance acount 1: " + acc1.getBalance());
        System.out.println("*** Balance acount 2: " + acc2.getBalance());
    }
}

// class LoggingAspect {
//     public Object log(ConstructorInvocation invocation) throws Throwable {
//         try {
//             System.out.println("C: Creating BankAccount using constructor " + invocation.getConstructor());
//             System.out.println("C: Account number: " + invocation.getArguments()[0]);
//             return invocation.invokeNext();
//         } finally {
//             System.out.println("C: Done");
//         }
//     }

//     public Object log(MethodInvocation invocation) throws Throwable {
//         try {
//             System.out.println("M: Calling method " + invocation.getMethod().getName());
//             System.out.println("M: Amount " + invocation.getArguments()[0]);
//             return invocation.invokeNext();
//         } finally {
//             System.out.println("M: Done");
//         }
//     }

//     public Object log(FieldWriteInvocation invocation) throws Throwable {
//         BankAccount account = (BankAccount) invocation.getTargetObject();
//         System.out.println("F: setting field " + invocation.getField().getName() + " for BankAccount "
//                 + account.getAccountNumber());
//         System.out.println("F: Field old value " + account.getBalance());
//         System.out.println("F: New value will be " + invocation.getValue());
//         try {
//             return invocation.invokeNext();
//         } finally {
//             System.out.println("F: Field new value " + account.getBalance());
//             System.out.println("F: Done");
//         }
//     }
// }