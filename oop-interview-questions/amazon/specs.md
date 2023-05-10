# Question: Design Amazon

# Approach
- Summarize Amazon's core functionality
- Identify Amazon's extra features that the interviewer might want me to design
- Identify objects, objects' methods, relationship between objects, paying attention to:
+ Inheritance vs composition
+ Where I can decouple things

# Step 1: Core features
- Authentication: login, logout, signup, edit
  User details: 
    + Name
    + Username
    + Email 
    + Password
    + Payment details:
      - Physical Address
      - Payment method 
      - Card information (extra layer of protection)
- Maintain a cart of current items for the user
- Browse items: 
  User navigates an UI with a list of items
  Search feature: ...
  User can click on that item -> View details:
    + Basic: Item name, ID, Provider, Price
    + Extra: ...
    There should be a "Add to cart button" 
  User can view cart, which has options
  Remove from cart
  Payment:
    + if payment details complete:
        Prompt for edit payment details before payment (print out details to confirm)
        -> Prompt for final confirmation
        -> Perform transaction
    + else
        Request to fill in missing details


Login -> User -> Item, Item, ... -> view cart -> remove item
          |  add to Crt ^                     -> buy -> complete & confirm details -> Transact
          |------------------------------------------------------------------------------

# Step 2: Identify objects & methods
1. Item(name, price)
2. Payment(Item item, counter, time)
3. Cart(vector<Item> item)
4. User(username, password, vector<Payment> history, Cart)
5. PaymentProcessor(result: Payment)
+ makePayment(user, method)
6. Controller
7. Server

UI: menu like 
- view Item
- view Cart
- add Item to cart
- remove Item from cart
- make payment

TODO:
- c++ webserver
-> support concurrency how
- search feature?