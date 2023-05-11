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
  + Vilation of ISP: A : B, A has method f which B is exposed to, not conflicted with (like in the case of LSP), yet will never call.

### Dependency inversion principle
Depend upon abstraction, not concretion.
- Think about interaction between modules as abstract concepts.
- Example: `Headmaster` class is composed of `Teacher`, `Assistant`, and `Helper`. 
=> There's no abstraction, `Headermaster` is depending on the actual concrete staff types, which if you think about it, makes it harder to extend later on. What if `Headmaster` now requires a `Supervisee` instead of a `Helper`? You don't want to remove `Helper` because that would violate LSP. In fact, why did we have to **enforce that the faculty is consist of the above 3 classes**? It would be better if we can make the faculty abstract, and have `Headmaster` depend on that abstract class. So to improve this model, create `AbstractFaculty` and a `FacultyImpl` composed of `Teacher`, `Assistant`, `Helper`.

### Some thoughts
Note: To write good code, have **just the right amount** of abstraction, not too little to violate DIP, not too much to violate ISP.
Note2: OCP is the hardest one, since it requires looking into the future.

## Design patterns