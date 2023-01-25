# Unit 3 Design Pattern

    1. General repeatable pattern
    2. Not mandatory to always implement design pattern
    3. They are generic, simple,  well tested, resuable and object oriented in nature
    4. We need to pick the right pattern for our project as there are 23 design patterns
    5. It requires communicating object that includes name, abstract and key aspects and focuses on OOC Problems (Object Oriented Concepts)

The *Gang of four* (GOF)

* Four authors Erich Gamma, Richard Helm,  Ralph Johnson and John V publish a book Design Pattern - Elements of reusable Object Oriented Software
* There design pattern are categorised. These are known as *gang of four*.

The *Design pattern* can be **Categorised** as follows:

![Img 8](./Images/Design%20Patterns.jpg)

    1. Creational Design Patterns
        a. provides a way to create objects while hiding the creational logic rather than instantiating objects yourself directly
        b. It gives more flexibility
        c. It can be furthur categorized as singleton, builder, prototype, factory
    2. Structual Design Patterns
        a. These design patterns concern class and object composition
        b. Those design patterns are about organizing classes and objects to a larger structure
        c. It uses Inheritance between classes
        d. Furthur divided as Bridge, Adapter
    3. Behavioral Design Pattern
        a. Concerned with communication between objects
        b. Example chain of responsibilty, Command, Interpreter, Iterator, Mediator, Memento etc

The **Creational Design Pattern* Type

1. Prototype Design pattern

        a. Here we are cloning the existing object instead of creating a new instance
        b. We can customized it 
        c. We can add or remove objects at runtime

        Example:

    ![Img 9](./Images/prototype.jpg)

    ![Img 10](./Images/prototype2.jpg)

    The **Advantage**:

        a. We can add or delete object at runtime

2. Builder Design

        a. It helps us build complex java object in an easy and readable manner
        b. It is used when we want to hide internal complex structure from external entities which use interface to create object
        c. It separates object construction from its representation
        d. It has 3 major parts
            i. Product (This is the actual object that we are trying to construct)
            ii. Builder (Builds complex part)
            iii. Executor (Executes complex part)
    Example

    ![img 10](./Images/builder.jpg)

3. Factory Design Pattern

        a. Define an interface or abs class for creating an object but let the subclasses decide which class to instantiate
        b. The main purpose is to return objects at runtime
        c. Helps us to separate the object creation code from the one which is using it.
        d. Reuses the same memory

    Example

    ![img 11](./Images/factoryDesign.jpg)

4. Abstract Factory Design Pattern

        a. Similar to Factory Design Pattern
        b. Add another level of abstraction layer to factory design pattern
        c. It creates factory of factory i.e super factory

    Example

    ![img 12](./Images/AbsFactory.jpg)
