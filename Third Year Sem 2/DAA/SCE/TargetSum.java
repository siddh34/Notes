// Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created. To create the sum, use any element of your array zero or more times. For example, array =[2,3,4 ]if  and your target sum is 10 , you might select[2,2,2,2,2]  [2,2,3,3] or [3,3,3,1] . In this case, you can arrive at exactly the target. It must return an integer that represents the sum nearest to without exceeding the target value

//package companyName;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Iterator;
import java.util.List;

public class TargetSum{
    public static int getTarget(HashSet<Integer> map,int target) {
        Iterator<Integer> it = map.iterator();
        boolean[] sum = new boolean[target + 1];
        Arrays.fill(sum,false);
        sum[0] = true;
        int a = 0;
        List<Integer> chosen = new ArrayList<Integer>();

        for(int i = 0; i <= target; i++) {
            it = map.iterator();
            while(it.hasNext()){
                a = it.next();
                if((i + a) <= target){
                    sum[i + a] = true;
                }
            }
        }

        for(int i = 0; i <= target; i++) {
            if(sum[i] == true){
                chosen.add(i);
            }
        }

        for(int i = 0; i < chosen.size(); i++) {
            System.out.print(chosen.get(i) + " ");
        }
        System.out.println();

        chosen.clear();

        for(int i = target; i >= 0; i--){
            if(sum[i] == true){
                return i;
            }
        }

        return target;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        HashSet<Integer> map = new HashSet<Integer>();

        while((--T) >= 0){
            int N = sc.nextInt();
            int target = sc.nextInt();
            
            for(int i = 0; i < N; i++){
                map.add(sc.nextInt());
            }

            System.out.println(getTarget(map, target));

            map.clear();
        }
        
        sc.close();
    }
}