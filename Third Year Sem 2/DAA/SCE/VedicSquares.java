import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Calculate extends Thread{
    public String num;
    Calculate(String number){
        this.num = number;
    }

    @Override
    public void run() {

        VedicSquares vs = new VedicSquares();

        vs.process(num);
    }
}

public class VedicSquares {
    public int duplex(char[] arr){
        if(arr.length == 1){
            return (arr[0] - '0')*(arr[0] - '0');
        }
        else if(arr.length == 2){
            return 2*(arr[0] - '0')*(arr[1] - '0');
        }
        else if(arr.length == 3){
            return 2*(arr[0] - '0')*(arr[2] - '0') + (arr[1] - '0')*(arr[1] - '0');
        }
        else if(arr.length == 4){
            return 2*(arr[0] - '0')*(arr[3] - '0') + 2*(arr[1] - '0')*(arr[2] - '0');
        }
        else if(arr.length == 5){
            return 2*(arr[0] - '0')*(arr[3] - '0') + 2*(arr[1] - '0')*(arr[2] - '0');
        }
        return -1;
    }

    public void process(String str){
        List<Integer> record = new ArrayList<Integer>();
        StringBuilder sb = new StringBuilder();

        for(int i = 1; i <= str.length(); i++){
            String nstr = str.substring(0, i);
            record.add(duplex(nstr.toCharArray()));
        }

        for(int i = str.length() - 1; i >= 0; i--){
            sb.append(str.charAt(i));
        }

        for(int i = str.length() - 1; i > 0; i--){
            String nstr = sb.substring(0,i);
            record.add(duplex(nstr.toCharArray()));
        }

        // getting squares
        for(int i = record.size() - 1; i > 0; i--){
            String s1 = record.get(i).toString();
            String s2 = record.get(i - 1).toString();
            String s11;
            String s12;
            
            if(s1.length() > 1){
                s11 = s1.substring(s1.length() - 1,s1.length());
                s12 = s1.substring(0,s1.length() - 1);
                
                record.set(i - 1,Integer.parseInt(s2) + Integer.parseInt(s12));
                record.set(i,Integer.parseInt(s11));
            }
        }

        sb = new StringBuilder();

        for(int i = 0; i < record.size(); i++){
            sb.append(record.get(i).toString());
        }

        System.out.println(sb);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        
        while((--T) >= 0){
            String number = sc.next();

            System.out.println("Enter 1 for non concurrent algorithm");
            System.out.println("Enter 2 for concurrent algorithm");

            int choice = sc.nextInt();

            if(choice == 1){
                VedicSquares vs = new VedicSquares();
                vs.process(number);
            }
            else{
                Calculate Cl = new Calculate(number);
                Cl.run();
            }
        }
        
        sc.close();
    }
}
