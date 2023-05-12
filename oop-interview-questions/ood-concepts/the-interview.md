# The OOD interview

## The task
- Interviewer gives problem statement.
- Candidate **decipher** the problem statement with questions.
- Candidate figure out classes and relationships, ensuring the design is, first **workable**, then **adaptable**.

## The approach

### Gather requirements
**First 10 minutes**
- Questions -> Gather requirements. Keyword: Well-defined.
- Ask what are the constraints. 
- Important: Ask for the level of detail that they require. **Am I expected to implement the solution or give a structural overview? If implement, is it high level or a class in detail?**.
- Use the requirements to guide your decisions:
  + In identifying use cases. 
  + Making the system as simple as possible without compromising requirements.
    (Also mean ignoring attributes and methods that do not meet this goal).
    (But mentioning them might be a good idea, like after the whole system is out, add a disclaimer listing
    all the shortcomings or something).
  + In scalability accomodation (abstract everything isn't always good, so ask if we are expecting certain features to be scalable -> at least have a baseline, then for things outside of that baseline we should also consider scalability but with moderation).

- What they are looking for:
  + Proficiency at collecting requirements.
  + **Effectively scoping down** the problem.
  + Execution: Can you design in 30-45 minutes based on your given requirements?

- What should I ask?
  Idk so far I have some ideas
  + Users: Who they are, what are looking for?
  + Scale?: How many users are we dealing with?  
  + Priority?: Speed? Maintainability? All?

### Model the problem
- Identify use cases is crucial. Try to engage the interviewer. See if something is missing and what is unnecessary.
- Think out loud.
- Probably won't be asked to use the actual use case diagram, but drawing something similar to that might help. (What are the alternatives? A use case per line?)

### Establish classes and their relationships
- First, list objects that play some role in the system.
Q: What if I find out some objects aren't necessary?
- Second, work out attributes (n) and operations (v) for each object. **We haven't started with classes yet**.
- Third, map out the relationship between objects. What does this entail?
  + A high level diagram (class diagram, quasi) is ESSENTIAL.
  + Is-a and Has-a relationships (inheritance, composition, aggregation)
  + Point of if you are using an abstract class or an interface.
  (There's a difference: 
    1. A has interface B does not creates a "is-a" relationship - an interface does have to belong in the tree of inheritance.
    2. An abstract class can have implementation and state. Interfaces cannot.
  ).
  + Do not use multiple inheritance.
  + Take into consideration: **maintainability, modular code, testibility, SOLID, the future**.
  Especially **the future (scalability, extensibility)**.
  Use these to justify your design decisions (including the choice of **design patterns**).

- Design approach: use bottom-up. **Identify the smallest components, and use them as the base to design larger components**.

### Activities and flows
- From use cases, we have activities. Hence, now that we have a model mapped out, the interviewer might ask us to describe the flow of some activities. So you need to draw some sort of flaw chart. UML can help here.
- Sequence diagram: Actors -> Columns representing objects -> actions and blocks and messages.
- Activity diagram: I haven't learned this one yet.
**TODO:**  Learn how to half-draw these diagrams (no need to follow all the rules).

### Get Coding
- From the start you need to ask if you are required to implement. This will have you bank your time and avoid over-modelling. But there are also multiple level of code detail. **Maybe they will require a high level implementation of the system or a detail implementation of some classes**. Also ask if they require **workable** code (do I need to compile).
- Priority: 
  + Abstract classes and interfaces. (Highest implementation level)
  + 