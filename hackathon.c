/* In this code, we have made a menu driven program and defined particular functions for different sets of work.
In this program, you can book a ticket for the concert and a unique Ticket ID will be generated. 
The unique Ticket ID can also be used to check if the ticket is valid or not.
 Also you can check if the ticket has already been used or not. 
 A sample size of 100 has been taken for the number of people who can attend the concert.
  An Array Data structure has been used*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Defining a structure to store the tickets
struct Ticket {  
    int id; // unique ticket ID
    char name[100];
    int age;
    char mobile_num[10];
    int valid; // A flag used for indicating if the ticket is valid
    int used; // To check if the ticket is already used
};

struct Ticket tickets[100]; // array of tickets
int total_tickets=0; // Defining the number of tickets sold

// Function to generate a unique ticket ID
int generate_id() 
{
    srand(time(NULL)); //Generating a Random Number
    return rand()%100000000; // return a random number between 0 and 99999999
}

// Function to book a ticket
void book()
{
int ticket_id;
if (total_tickets<100) { // generate a unique ticket ID
  ticket_id = generate_id();      
  //A check to see if the ticket ID is already generated before
        for (int i = 0; i<total_tickets; i++){
            if (tickets[i].id == ticket_id) {
                // To generate a new Ticket ID, if the generated ID is already taken
                ticket_id = generate_id();
                i = -1; // start checking from the beginning again
            }
        }
        
        // For adding the ticket to the array structure
        tickets[total_tickets].id = ticket_id;
        tickets[total_tickets].valid = 1; // To set the ticket as valid
        
        //For adding the name, age and Roll number
        printf("Enter Name of attendant:");
        scanf("%s", tickets[total_tickets].name);
        printf("Enter Age of attendant:");
        scanf("%d", &tickets[total_tickets].age);
        printf("Enter Mobile Number of attendant:");
        scanf("%s", tickets[total_tickets].mobile_num);
        total_tickets++; 
        printf("Ticket booked successfully!\n");
        printf("Ticket ID:%d\n", ticket_id);
} 
else{
  printf("Sorry, all tickets have been sold out.\n");
  }
}

// Function to check if a ticket is valid
void validate() 
{
    int id;
    printf("Enter ticket ID: ");
    scanf(" %d", &id);
    for (int i = 0; i<total_tickets; i++) {
        if (tickets[i].id == id) {
            if (tickets[i].used) {
                printf("Ticket has been already used.\n");
            } else {
                tickets[i].used=1;
                printf("Your Ticket is valid. Please Enjoy the Show.\n");
            }
            return;
        }
    }
    printf("Your Ticket is invalid.\n");
}

// Function to display the number of people attending the concert
void display() 
{
    int count = 0;
    for (int i = 0; i<total_tickets; i++){
        if (tickets[i].valid){
            count++;
        }
    }
printf("Number of people attending the concert: %d\n", count);
}

void main() {
    int choice;
    do {
        printf("\n\n\n");
        printf("*************************MENU**********************************************\n");
        printf("*              >     1. Book a ticket                                     *\n");
        printf("*              >     2. Check ticket validity                             *\n");
        printf("*              >     3. Display number of people in concert               *\n");
        printf("*              >     4. Exit                                              *\n");
        printf("***************************************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", & choice);

                switch (choice) {
                case 1:
                        book();
                        break;
                case 2:
                        validate();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        printf("Exiting..... Have a nice day!\n");
                        break;
                default:
                        printf("Invalid choice. Please try again.\n");
                }
        } while (choice != 4);

        
}

/* Program made by 
Arnav Aditya(2210110189)
Arnav Jalan(2210110192)
Rachit Sen(2210110489)*/
