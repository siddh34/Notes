class A {
    // It gets memory only once because of static
    // public static A obj; // returns null
    public static A obj = new A(); // returns obj
    public static A getInstance() {
        // if object is null then return new object else it will return previous instance
        if(obj == null){
            System.out.println("Object doesn't exist so created a new instance");
            return new A();
        }
        System.out.println("Object does exist so created return the object");
        return obj;
    }
}

class Singleton{
    public static void main(String[] args) {
        A.getInstance();
    }
}