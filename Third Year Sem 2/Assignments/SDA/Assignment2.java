import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ListOperations{

    private static ListOperations LO;
    private static List<Integer> storage = new ArrayList<Integer>(); // if object is null then return new object else it will return previous instance
    
    // prevents the object to be initialized by other class
    // private ListOperations(){};
    
    ListOperations(){

    }

    
    ListOperations(String decision){
        if(decision.equals("Y") || decision.equals("y")){
            LO = new ListOperations(); // returns object
        }
        ListOperations.getInstance();
    }

    public static ListOperations getInstance() {
        if(LO == null){
            System.out.println("Object doesn't exist so created a new instance");
            return new ListOperations();
        }
        System.out.println("Object does exist so return the object");        
        return LO;
    }

    public static void addToList(int num){
        storage.add(num);
    }

    public static void removeFromList(int num){
        if(storage.contains(num)){
            storage.remove(num);
        }
        else{
            System.out.println("Number does not exist");
        }
    }

    public static void printList(){
        for(int i: storage){
            System.out.print(i+" ");
        }
        System.out.println();
    }

    public static int size(){
        return storage.size();
    }

    public static boolean isEmpty(){
        return storage.isEmpty();
    }
}

public class Assignment2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // ListOperations L = new ListOperations();

        boolean loop = false;
        while (loop == false) {
            System.out.println("Do you want the instance of object?");
            String decision = sc.next();
            new ListOperations(decision);
            System.out.println("Enter you choices");
            System.out.println("What do you wanna do?");
            System.out.println("Press 1 to add to the list");
            System.out.println("Press 2 to remove from the list");
            System.out.println("Press 3 to print the list");
            System.out.println("Press 4 to get the size of list");
            System.out.println("Press 5 to get check whether the list is empty");
            int ch = sc.nextInt();
            switch(ch){
                case 1: 
                    ListOperations.addToList(sc.nextInt());
                    break;
                case 2:
                    ListOperations.removeFromList(sc.nextInt());
                    break;
                case 3:
                    ListOperations.printList();
                    break;
                case 4: 
                    System.out.println("Size of list : "+ ListOperations.size());
                    break;
                case 5:
                    System.out.println("Is list empty : "+ ListOperations.isEmpty());
                    break;
                default:
                    System.out.println("Wrong choice");
            }

            System.out.println("Do you want to continue?");
            String choice = sc.next();
            if(choice.toLowerCase().equals("y")){
                loop = false;
            }
            else{
                loop = true;
            }

        }

        sc.close();
    }
}
