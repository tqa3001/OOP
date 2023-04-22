# Question: Design Amazon

# Approach
- Summarize Amazon's core functionality
- Identify Amazon's extra features that the interviewer might want me to design
- Identify objects, objects' methods, relationship between objects. 

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
0. UI: menu like 
1. User
- get, set, constructor for new user
- 
2. Item
3. Cart