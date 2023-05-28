# Bus_Ticket_Management_System
This code implements a simple bus ticket booking system using C++. Here's a summary of how it works:

1. The code defines a class `bus_ticket` that encapsulates various functions and data members related to the ticket booking system.

2. The `bus_ticket` class contains member functions like `menu`, `administrator`, `customer`, `add`, `edit`, `remv`, `list`, and `receipt`.

3. The `menu` function displays a menu to the user, prompting them to choose between being an administrator or a customer or to exit the program. Depending on the choice, it calls the corresponding function.

4. The `administrator` function provides options for the administrator, such as buying a ticket, modifying a ticket, canceling a ticket, or returning to the main menu. Depending on the choice, it calls the corresponding functions.

5. The `customer` function provides options for the customer, such as buying a ticket or returning to the main menu. Depending on the choice, it calls the corresponding functions.

6. The `add` function allows the administrator to add a new ticket to the database. It takes input for NID, train name, location, destination, ticket price, and VAT, and stores the ticket information in a file named "database.txt".

7. The `edit` function allows the administrator to edit an existing ticket. It prompts for the NID, searches for the corresponding ticket in the file, and allows the administrator to modify the ticket information. The modified information is then stored back in the file.

8. The `remv` function allows the administrator to cancel a ticket. It prompts for the NID, searches for the corresponding ticket in the file, removes it from the file, and updates the file accordingly.

9. The `list` function reads the ticket information from the file and displays it to the user.

10. The `receipt` function calculates the total bill for the customer. It prompts the user to enter the NID and quantity of tickets they want to buy. It then reads the ticket information from the file, calculates the total amount including VAT for each ticket, and displays the receipt with the total amount.

11. The `main` function creates an object of the `bus_ticket` class and calls the `menu` function to start the program.

Overall, the code provides a simple interface for customers to buy tickets and for administrators to manage the ticket database.