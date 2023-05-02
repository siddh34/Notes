import java.time.Duration;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Calculate implements Runnable {
    public String num;

    Calculate(String number) {
        this.num = number;
    }

    public int duplex(char[] arr) {
        if (arr.length == 1) {
            return (arr[0] - '0') * (arr[0] - '0');
        } else if (arr.length == 2) {
            return 2 * (arr[0] - '0') * (arr[1] - '0');
        } else if (arr.length == 3) {
            return 2 * (arr[0] - '0') * (arr[2] - '0') + (arr[1] - '0') * (arr[1] - '0');
        } else if (arr.length == 4) {
            return 2 * (arr[0] - '0') * (arr[3] - '0') + 2 * (arr[1] - '0') * (arr[2] - '0');
        } else if (arr.length == 5) {
            return 2 * (arr[0] - '0') * (arr[4] - '0') + 2 * (arr[1] - '0') * (arr[3] - '0') + (arr[2] - '0') * (arr[2] - '0');
        } else if (arr.length == 6) {
            return 2 * (arr[0] - '0') * (arr[5] - '0') + 2 * (arr[1] - '0') * (arr[4] - '0')
                    + 2 * (arr[2] - '0') * (arr[3] - '0');
        } else if (arr.length == 7) {
            return 2 * (arr[0] - '0') * (arr[6] - '0') + 2 * (arr[1] - '0') * (arr[5] - '0')
                    + 2 * (arr[2] - '0') * (arr[4] - '0') + (arr[3] - '0') * (arr[3] - '0');
        }
        return -1;
    }

    @Override
    public void run() {
        List<Integer> record = new ArrayList<Integer>();
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= this.num.length(); i++) {
            String nstr = this.num.substring(0, i);
            record.add(duplex(nstr.toCharArray()));
        }

        for (int i = this.num.length() - 1; i >= 0; i--) {
            sb.append(this.num.charAt(i));
        }

        for (int i = this.num.length() - 1; i > 0; i--) {
            String nstr = sb.substring(0, i);
            record.add(duplex(nstr.toCharArray()));
        }

        // getting squares
        for (int i = record.size() - 1; i > 0; i--) {
            String s1 = record.get(i).toString();
            String s2 = record.get(i - 1).toString();
            String s11;
            String s12;

            if (s1.length() > 1) {
                s11 = s1.substring(s1.length() - 1, s1.length());
                s12 = s1.substring(0, s1.length() - 1);

                record.set(i - 1, Integer.parseInt(s2) + Integer.parseInt(s12));
                record.set(i, Integer.parseInt(s11));
            }
        }

        sb = new StringBuilder();

        for (int i = 0; i < record.size(); i++) {
            sb.append(record.get(i).toString());
        }

        System.out.println(sb);
    }

    public static void main(String[] args) {
        int numberofthread = 5;
        List<Thread> threads = new ArrayList<Thread>();
        for (int i = 0; i < numberofthread; i++) {
            Thread t1 = new Thread();
            t1.start();
            threads.add(t1);
            if(threads.size() % 5 == 0){
                waitForThreads(threads);
            }
        }
    }

    private static void waitForThreads(List<Thread> threads) {
        for (Thread thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        threads.clear();
    }

}

public class VedicSquares {
    public List<Integer> Xrecord = new ArrayList<Integer>();

    public int duplex(char[] arr) {
        if (arr.length == 1) {
            return (arr[0] - '0') * (arr[0] - '0');
        } else if (arr.length == 2) {
            return 2 * (arr[0] - '0') * (arr[1] - '0');
        } else if (arr.length == 3) {
            return 2 * (arr[0] - '0') * (arr[2] - '0') + (arr[1] - '0') * (arr[1] - '0');
        } else if (arr.length == 4) {
            return 2 * (arr[0] - '0') * (arr[3] - '0') + 2 * (arr[1] - '0') * (arr[2] - '0');
        } else if (arr.length == 5) {
            return 2 * (arr[0] - '0') * (arr[4] - '0') + 2 * (arr[1] - '0') * (arr[3] - '0') + (arr[2] - '0') * (arr[2] - '0');
        } else if (arr.length == 6) {
            return 2 * (arr[0] - '0') * (arr[5] - '0') + 2 * (arr[1] - '0') * (arr[4] - '0')
                    + 2 * (arr[2] - '0') * (arr[3] - '0');
        } else if (arr.length == 7) {
            return 2 * (arr[0] - '0') * (arr[6] - '0') + 2 * (arr[1] - '0') * (arr[5] - '0')
                    + 2 * (arr[2] - '0') * (arr[4] - '0') + (arr[3] - '0') * (arr[3] - '0');
        }
        return -1;
    }

    public void process(String str) {
        List<Integer> record = new ArrayList<Integer>();
        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= str.length(); i++) {
            String nstr = str.substring(0, i);
            record.add(duplex(nstr.toCharArray()));
        }

        for (int i = str.length() - 1; i >= 0; i--) {
            sb.append(str.charAt(i));
        }

        for (int i = str.length() - 1; i > 0; i--) {
            String nstr = sb.substring(0, i);
            record.add(duplex(nstr.toCharArray()));
        }

        // getting squares
        for (int i = record.size() - 1; i > 0; i--) {
            String s1 = record.get(i).toString();
            String s2 = record.get(i - 1).toString();
            String s11;
            String s12;

            if (s1.length() > 1) {
                s11 = s1.substring(s1.length() - 1, s1.length());
                s12 = s1.substring(0, s1.length() - 1);

                record.set(i - 1, Integer.parseInt(s2) + Integer.parseInt(s12));
                record.set(i, Integer.parseInt(s11));
            }
        }

        sb = new StringBuilder();

        for (int i = 0; i < record.size(); i++) {
            sb.append(record.get(i).toString());
        }

        System.out.println(sb);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();


        while ((--T) >= 0) {
            // Your code below
            String number = sc.next();
            
            System.out.println("Enter 1 for non concurrent algorithm");
            System.out.println("Enter 2 for concurrent algorithm");
            
            int choice = sc.nextInt();
            
            Instant start = Instant.now();

            if (choice == 1) {
                VedicSquares vs = new VedicSquares();
                vs.process(number);
            } else {
                Calculate c1 = new Calculate(number);
                c1.run();
            } 

            Instant end = Instant.now();
            Duration timeElapsed = Duration.between(start, end);
            System.out.println("Time taken: "+ timeElapsed.toNanos() +" nano seconds");
            System.out.println("Time taken: "+ timeElapsed.toMillis() +" milli seconds");
            System.out.println("Time taken: "+ timeElapsed.toSeconds() +"  seconds");
        }

        sc.close();
    }
}
