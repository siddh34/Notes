# Lecture 6

The *Creational Design Pattern* Type

1. Singleton Design Pattern

        a. private constructor
        b. Instance private
        c. Global Method

    Example

        Public static Singleton getInstance(){
            if(instance == null){
                instance = new Singleton();
                return instance;
                }
            }

    ![Img 13](./Images/singleton.jpg)

2. Object pool

    ![Img 14](./Images/reusable.jpg)

The *Structural Design* Patterns

1. Adapter

        a. Adapter is between two objects
        b. Alternate from of class creation is possible
        c. The pattern converts the incompatible interface of a class into another interface that client requires

    ![Img 15](./Images/adapter.jpg)

2. Decorator

        a. Used to extend the functionality of the base class
        b. It offers wrapper to existing class
        c. Example In pizza class toppings can be added
        d. It does not affects the behaviour of  other objects in the class
