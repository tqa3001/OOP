# Object-oriented design
OOD is a part of the OOP process. Reduces redundancy, improves reusability, facilitates collaboration.
Expectation: A near-perfect solution to the given problem that covers all the edge cases.
OOD interview vs SD interview? One requires you to define relationship between classes, the other one requires you to specify what data structures to use, what API to expose to customers, etc.
- OOD interviews probe into the candidate's communication ability. Can he or she stay calm and grasp the essence of relationships without verbose information? Can he or she reason the decisions with fluency? So a typical OOD interview is full of communication, both talking and coding.

## Builing blocks
- Objects: Things with *a state* and *behaviors*.
- Classes: Blueprints for objects with *attributes -> state*  and *methods -> behaviors*. 

## The 4 pillars revisited with examples
1. Encapsulation
- Bind methods with data that they operates on -> a single unit called a *class*.
- Good practice: Make all attributes private, implement public setters & getters.
- Benefits: 
  + Classes are simpler to modify and maintain.
  + Which data member we wish to keep hidden or accessible can be specified.
  + We choose which variables are read-only and write-only (increases flexibility).

2. Inheritance
- IS-A relationship that allows extending features.
- Create a new *derived class* from a *base class*.
- Modes of inheritance: public, private, protected?
- Benefits: Extensibility + reusability.
- Related: Open-close principle.

3. Abstraction
- Hide complex implementation.
- How? The class itself provide an interface. A button to turn up the volume, we don't care about its underlying mechanism.

4. Polymorphism
- Taking many forms (e.g overloading operators, vertical polymorphism where many classes share an interface)
- 2 types:
  + Dynamic polymorphism: method overriding -> **resolved at compile-time, name + arguments + return values are the same**
  + Static polymorphism: method overloading, operator overloading -> **resolved at runtime, same name + different arguments/return**
  (so kinda like within a class vs between parent/child classes?)


### Data hiding
- Masking a class's internal operations, let things interact with it through an interface.
- The goal: Prevent modification of the orginal content of a class. 
How? Encapsulation + Abstraction.

### Encapsulation vs abstration
- Encapsulation: Restrict access to data through get&setters
- Abstraction: Hide implementation through interfaces and abstract classes.

## Object-oriented analysis and design (OOAD): A part of the SDLC
- Observe system (gather requirements) -> Determine objects -> Establish relationship between objects -> Model + build the design.

### UML: things, relationships, diagrams
- Things: structural, behavioral, grouping, or annotation.
Structural: classes, objects, interfaces, use cases, actor, components, nodes
Behavioral: system's interactions & functions -> activity diagrams, interaction diagrams

- Diagrams:
**Use case diagram**: 
Why? Helps understanding high level requirements by visualizing the flow of use cases.
  + Primary actors (users) on the left
  + Secondary actors (needs to be triggered by primary actors) on the right.
  + Use cases: actors -> use cases -> child use cases (extend, include,...)

**Class diagrams**:
Map directly with OO languages. Represent the systems' structure.
  + Classes: Box [ title | attributes | method ]
  + <<interface>>, <<abstract>>: no attributes, <<enumeration>>: no methods, <<annotation>>.
  Access modifiers: +, #, -

[Association]
Class association: single level, multilevel inheritance; hierachical inheritance; multiple inheritance; hybird?????
  + Arrow "extends". 
Object association: composition, aggregation.
  + Composition: room is composed of windows, doors, which can't exist without the room. **strong relationship**.
  + Aggregation: furniture is not an inherent part of a room, can be move elsewhere, can exist independent of room. **weak relationship**.
Associations can be unidirectional or bidirectional, can be n-ary (like ER diagram).

[Dependency]
- A needs B for its implementation (e.g B is passed as an argument to a method of A) => Dashed arrow.

**Sequence diagram**: Flow of how things interact
- Each object -> a column (lifetime) starting with a box with the object's name and ends when destroyed (a message)
- Object during its lifetime -> send + receive messages (create, destroy, return, anything), encapsulated in an `activation bar`
e.g 
A      B
|      |
ii->f()ii
ii     ii
ii<-return
|      |

## SOLID
Q: Why is being tightly coupled bad? 
A: One changed class affect all of its dependents -> harder to scale and extend. This even reduce testibility and harder to debug (less maintainability).

How to address? SOLID. Reduces tight coupling (makes everything better), also reduces code's complexity (more maintainable + understandable), makes code modular (hence more testable)

### Single responsibility principle
Each class -> only one functionality of the system.
- Everything in a class should be related to one goal.
Violation example: `Item` class also has `render()` method. "Item" should only **have 1 reason to change**. If you want to change rendering, now
you also have to change the class -> Create: `ItemRenderer : Item` (in a sense this can be view as the delegation of tasks)

### Open-closed principle
Software components should be open for extension and closed for modification (e.g. one module shouldn't be able to change the implementation of another module).
- How? Inheritance. Interfaces are also examples of OCP.
- Important question: **What happens if the business grow?** => Code need to adapt, more classes, more requirements => **Some methods have to be updated, but we don't want to hard code edit** because that would violates OCP.
- Huge: Transitive dependency violates OCP (my current amazon ripoff code).

### Liskov substitution principle
Object of a superclass should be replacable with an object of the subclass without breaking the system.
Examples of this being violated?
- Say there's a `Vehicle` class with method `startEngine()`, two subclass of `Vehicles` which are `Car` and `Bicycle` which also implements `startEngine()`. What's the problem here?
- Right, Bicycles don't have an engine! But when coding maybe bicycle is an extended feature, so before that you thought vehicles are dealing with those with engines -> oof!
- The tension here is that we can't fully avoid violating this principle, since we **can't predict all requirements**, but **not thinking whether an abstraction is trully mapping to reality** (hmm... does all vehicles start its engine in some way?) will definitely lead to that.
- Avoid unnecessary generalizations.

### Interface segregation principle
Make client-specific interfaces. Avoid exposing methods that subclasses won't use.
- For example, a class `Tree` with methods `growFruits()` and `growsFlowers()`, with subclasses `AppleTree` and `MilkwoodPine` that implements the two methods => again, not mapping to reality because milkwood pines don't grow fruits.
- Solution: Create `TreeWithFruits : Tree` and `MilkwoodPine : TreeWithFruits`.
Note: **The most violated principle**.
Note2: If there's less inheritance -> less chance of getting a ISP violation. 
Note3: ISP vs LSP: Small distinction. 
  + Violation of LSP: A : B, B implements method f of A that just doesn't make sense for B.
  + Violation of ISP: A : B, A has method f which B is exposed to, not conflicted with (like in the case of LSP), yet will never call.

### Dependency inversion principle
Depend upon abstraction, not concretion.
- Think about interaction between modules as abstract concepts.
- Example: `Headmaster` class is composed of `Teacher`, `Assistant`, and `Helper`. 
=> There's no abstraction, `Headermaster` is depending on the actual concrete staff types, which if you think about it, makes it harder to extend later on. What if `Headmaster` now requires a `Supervisee` instead of a `Helper`? You don't want to remove `Helper` because that would violate LSP. In fact, why did we have to **enforce that the faculty is consist of the above 3 classes**? It would be better if we can make the faculty abstract, and have `Headmaster` depend on that abstract class. So to improve this model, create `AbstractFaculty` and a `FacultyImpl` composed of `Teacher`, `Assistant`, `Helper`.

### Some thoughts
Note: To write good code, have **just the right amount** of abstraction, not too little to violate DIP, not too much to violate ISP.
Note2: OCP is the hardest one, since it requires looking into the future.
Note3: Don't be a follower. Reddit: There has been over-generalized code base with high "code beauty" index that are straight up unmaintainable.
Note4: Since transitional dependency violates OCP and inheriting an implementation violates DIP, enforcing strict dogmatic SOLID means the model would be a bipartite graph between abstract classes and their concrete implementations. This might have implications. **More reading is needed on how much SOLID to apply, and what are the other rules for designing clean code that matters more.**

## Design patterns
Pay close attention to: Motivation + Trade-offs
4 types:
- Creational: Factory, Singleton, Builder, Constructor, Prototype,...
=> Allow flexibility in choosing which object to create.
- Structural: Facade, Bridge, Adapter, Decorator,...
=> Allow change in structure to affect other parts minimally.
- Behavioral: Observer, Strategy, Command, Mediator, CoR, Memento,...
=> Streamline communication between objects.
- Architectural: MVC, MVVM, MVP,...
=> Solving software architecture problems.

### Creational
1. Factory:
- Context: Many classes, and the class to choose needs to be specified everytime in lots of places.
- Example: You first have a class, business grows, you need same structure of class but somewhat different, but code is coupled to the first class -> exponential refactoring. **Use when classes required cannot be anticipated beforehand, objects have shared similarity, when object construction is complex.**
- Solution:
  + First, add an abstract class that holds the essense of the classes you are creating.
  + Then, a `Factory` classes that delegates the object creation task to two subclasses `createA` and `createB`.

2. Constructor: The C++ constructor.

3. Singleton: Cannot have more than **one** instance.
- Context: **databases, loggers, stores, single sources of truth.**
- Solution: Make default constructor private, delete copy and move constructors, implement a `getInstance()` method that returns a static instance of the class.
- Issue: The above is not thread-safe.

4. Builder: Factory but with more customization. Still that base object, multiple implementation. But implementation can now be broken down to different steps, each step can be implemented differently. 
- Context: **highly customizable classes + hide construction details in even further by breaking it down to smaller chunks** (e.g. game items, game characters, user settings,...) but i'm skeptical of when this is actually needed.
- Solution: Say the construction of class `A` requires constructing smaller parts `X, Y, Z` => `Builder : AbstractBuilder` classes which specify blueprints on how to construct `X`, `Y`, and `Z`, and a `Director` class that has-a `Builder` attribute that depends on the input, select the builder and use the builder's methods for constructing each part`.

5. Prototype: JS's prototype inheritance.
6. Abstract

### Structural
1. Decorator
- Context: When you want to wrap a class to add a set of defined features for it (e.g. Logging, Errorhalding, Printing runtime,...) without changing its base code.
- In Python, there is @decorator. 
- Create a `DecoratorX : X` class with a constructor `Decorator(X source) : wrapee(source)` that delegates all tasks to its `wrappee` and also implements/override extra features.

2. Facade:
- When there is so much complexity that the client (maybe other developers) does not need to see. So, like a DLL, we create a Facade exposing endpoints to services and hide behind it all the complex implemetation.
- Facade doesn't have to be a virtual class. View it like a menu.
- Only point to note here is that sometimes it might be helpful to implements a `Facade` that contains an `AdditionalFacade` to make the facade interface less polluted.
- Use to **structure a system into layers, each with a facade** by requiring layers to only communicate through facades. Similar to the **Mediator pattern**.

3. Adapter:
- A class `A` deals with a class `B`. Business requirements -> now we must also be able to operate `A` that deals with `C`, and it would be too costly to create `A_2` that deals with `C`. Instead, convert to `B` to `C` by creating `BAdapter : C` with constructor `BAdapter(B)`.
- When? Like above, when code reuse is needed, or when we want old APIs to work with new APIs.

4. Bridge:
- You have an app with GUI that runs on an OS (Or a remote and a device).
- Business grows => Temper extending GUI and extending range of supported OS.
- How to not write n^2 implementations? Have a bridge in the middle.
- More generally, we have an abstraction (high level control, like the GUI) and an implementation (the app working in a certain OS environment), and link these two. So:
Create a class `abstraction` with methods which represent the app's features and an attribute `implementation` of the abstract class `AbstractImplementation` and write the implementation in `ConcreteImplementation`. Then calls to `abstraction` can be redirected to calls to `implementation` (e.g. `T Abstraction::buyitem() { return implementation.buyItem(); }`)
- This also allows changing implementation **at runtime**, allowing your garage remote to work with the aircon or something like that.
- Recap: Allow dividing business logic/huge classes into hierachies that can be developed independently. A bridge between an abstraction hierachy and an implementation hierachy will allow abstraction to delegate its calls to implementation hierachy (which might invokes even lower hierachies). Push to an extreme, we can let `implementation` be a **facade**.

5. Composite:
- Basically create a tree-like hierachy of objects.
- Context: HTML DOM, File systems.
- Create a `Client` that depends on an abstract class `AbstractComponent`, and create `Leaf : AbstractComponent` that implements `f` and `Composite : AbstractComponent` that implements `f`, `addChild`, `removeChild`, and `getChildren`.

### Behavioral patterns
1. Chain of responsibility
- You have a HTTP request. Before you process this request, you need to apply several checks. Business requirement grows causing more checks to be added, and eventually keeping a bunch of if else become unmanagable. Splitting into methods of the same class cause the class to be too big. 
- So instead, create a `Handler` abstract class with a `handle()` method and a `setNext()`, and different `HandlerImpl : Handler` that implements each check and set the next check in the chain.
- Examples: expressjs middlewares, combine with the composite structural pattern to pass some event upstream in the DOM tree.

2. Command
- Decouples the objects sending requests from objects executing requests. 
- Somewht similar to chain of responsibility. You have an object with too many methods for dealing with request, worse is that later on when the app grows, thsee methods can't be used in other places. Think about it, you can save ctrl-c info from any class, why does it have to be bound to some editor class?
- Create abstract class `Command` with different implementations: `CutCommand : Command`, `CopyCommand : Command`, `UndoCommand : Command`,... all with an attribute `editor: Editor&`, a class `CommandHistory` to save history and support `UndoCommand`, and an `Application` class consist of `Invoker` objects, each of which has a `command: Command` and an `invoke()` method. Now you can replace `Application` with anything that uses `Invoker`s. 
- Great example: A text editor.

3. Iterator

4. Mediator
- We saw with the **Bridge** design pattern that when classes grow, the relationship between two objects can become more complex very fast.
- We are interested in a different kind of growth: Growth in the number of classes. Each class must inherently interract with exiting classes in the system. This can get really bad, say if a class have to interract with all the classes before it, you can't write n^2 methods.
- The solution is to view each class as both a receiver and sender of messages, and have a class in the middle of everything to control the flow of messages.
- Example: Different components of a dashboard like `Notifications`, `Server`, `Chat` => Create a `Mediator` that contains all these components through aggregation and add a `mediator: Mediator&` to each component, now each component only need to communicate to the `Mediator` which will then propagate requests to other components for each independent component to synchronize changes.

5. Observer
- `Publisher` wants to send news updates (maybe by adding to `Customer`'s inbox of messages) to a bunch of `Customer`, how to?
- You can use composition by creating a `std::vector<Customer*>` (gotta use pointers, it is what it is) for `Publisher`, and create a `Publisher::emit()` method that loops through each registered customer (gotta implement `register()` and `unregister()` methods too) and do a `Customer::update()`.

6. Strategy
- `Kitchen` want to cook in different ways without using a bunch of if-else conditions, and also allows extension in the future.
- Create a `CookingStrategy` abstract class, implements a bunch of subclass `CookingStrategyImpl : CookingStrategy` and add method `Kitchen::cook(strategy: CookingStrategy)` (loose coupling).

7. Memento
- How to save state? (e.g. Text editor undo, now to think of it creating a text editor is a great project!)
https://refactoring.guru/design-patterns/memento 

8. Template
- Say you have two classes performing two similar tasks but with some differences. Sure, you can create an abstract class or what not to reuse some methods, but maybe there is some atomic method that is lengthy but not entirely similar so you still have to write twice. But you realized that the two methods have a lot of duplicate code, how to factor that out?
- Split it into seperate methods which are parts of the whole algorithms. But don't put it in the original class, that would violate SRP. Create an `Algorithm` class with these `step1()`, `step2()`,... methods, and a `template()` method that describes how to match these steps (kinda like a `Director` in the **builder** structural pattern), and of course, add `algorithm: Algorithm` to the orignal class and add implementations `AlgorithmImpl1 : Algorithm`, `AlgorithmImpl2 : Algorithm`.

9. Visitor: 
- Seperate algorithms from objects
- One of the most complex (and least popular)
- For more: https://refactoring.guru/design-patterns/visitor 
