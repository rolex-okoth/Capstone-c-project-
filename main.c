#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


#define MAX_BUSES 6
#define ROWS 4
#define COLS 12


struct{
    int ID_num;
    char name[14];
    char gender[14];
    char dep_location[20];
    char destination[20];
    char row_and_col [5];
    char time[8];
    char date[12];
}booking;


typedef struct {
    int busId;
    int row;
    int col;
    time_t timestamp;
} Booking1;


void initializeSystem();
void displayBusSchedules();
void login();
void bookSeat(int busId);
void cancelBooking(int busId);
void viewAllBookings(int busId);
void canceled_tickets();
void classified_booking_hist();
void loadBookingData();


FILE *bookings;
FILE *file;
FILE *buslist;
FILE *canceled_ticket;
FILE *ticket_print;


int busSchedules[MAX_BUSES][2];  // Bus schedules: [busId, availableSeats]
Booking1 bookings1[MAX_BUSES][ROWS][COLS];  // Bookings for each bus and seat

void initializeSystem()
{
    for (int i = 0; i < MAX_BUSES; i++) {
        busSchedules[i][0] = i + 1; // Bus ID
        busSchedules[i][1] = ROWS * COLS; // All seats initially available
    }
}

void displayBusSchedules()
{
    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
    printf("\n\t\t\t\t\t********************Bus Schedules************************\n");

    printf("\n----------------------------------------------------\n");
    printf("   **Buses Routes Available In The System....:");
    printf("\n----------------------------------------------------\n");
    buslist= fopen("add_bus.txt","r");
    char filecontent1[1000];
    if(buslist !=NULL){
        while(fgets(filecontent1,1000,buslist)){
        printf("%s",filecontent1);
    }
    }else{
        printf("There Is No Such File");
    }

    fclose(buslist);
    printf("\n\n\n");
    printf("\t     Bus ID   Available Seats\n");
    for (int i = 0; i < MAX_BUSES; i++) {
        printf("\t\t %d \t %d\n", busSchedules[i][0], busSchedules[i][1]);
    }
    getch();
}

void login()
{
    int i=0, j=0;
    char ch;
    char admin[12] = "JOYCE";
    char pass[12]= "pass";
    do{
        system("cls");
        printf("\n\n\t\t\t\t===============================USER LOGIN=============================\n\n\n\n");
        printf("\n**ENTER YOUR PASSWORD:\n      ");
          while((ch= getch())!=13){
          pass[i]=ch;
          printf(".");
          i++;
            }
            pass[i] = '\0';
            i = 0;
            if(strcmp(pass,"pass")==0){
                printf("\n\n\t**WELCOME %s ,LOGIN SUCCESFUL\n",admin);
                printf("press any key");
                getch();
                break;
            }
            else
            {
                printf("\n\n\t**WRONG PASSWORD TRY AGAIN\n");
                getch();
                j++;
            }
    }while(j <=2 );
    if(j > 2){
        printf("==========================*SYSTEM BLOCKED, PLEASE RESTART!!!=============================");
        getch();
        exit(0);
    }
}
void bookSeat(int busId)
{
    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");

 system("cls");
    int route_num;
    int distance,price =2,total_price;
    do{
        system("cls");
        printf("\n\n-------------------------------------------\n");
        printf("\t**Book Seat**");
        printf("\n--------------------------------------------\n\n");

        printf(" \n1: Nairobi to Thika..");
        printf(" \n2: Meru to Nairobi..");
        printf(" \n3: Thika to Nakuru..");
        printf(" \n4: kisumu to Nairobi..");
        printf(" \n5: Embu to Murang'a..");
        printf(" \n6: Nyeri to Nairobi..");
        printf(" \n7: EXIT");
        printf("\n\nEnter your choice::");
        scanf("%d",&route_num);
        switch (route_num)
        {
        case 1:
            system("cls");
            printf("=================================================\n");
            printf("\tNairobi To Thika ");
            printf("\n=================================================\n\n\n");
            distance = 50;//KM
            total_price = price * distance;//2sh per KM
        break;
        case 2:
            system("cls");
            printf("===============================================\n");
            printf("\tMeru To Nairobi ");
            printf("\n==================================================\n\n\n");
            distance = 230;//KM
            total_price = price * distance;//2sh per KM
        break;
        case 3:
            system("cls");
            printf("================================================\n");
            printf("\tThika to Nakuru");
            printf("\n=================================================\n\n\n");
            distance = 200;//KM
            total_price = price * distance;//2sh per KM
        break;
        case 4:
            system("cls");
            printf("=================================================\n");
            printf("\tkisumu to Nairobi ");
            printf("\n=================================================\n\n\n");
            distance = 355;//KM
            total_price = price * distance;//2sh per KM
        break;
        case 5:
             system("cls");
            printf("=================================================\n");
            printf("\tEmbu to Murang'a ");
            printf("\n=================================================\n\n\n");
            distance = 55;//KM
            total_price = price * distance;//2sh per KM
        break;
        case 6:
            system("cls");
            printf("=================================================\n");
            printf("\tNyeri to Nairobi ");
            printf("\n=================================================\n\n\n");
            distance = 210;//KM
            total_price = price * distance;//2sh per KM
        break;
        default:
            system("cls");
            printf("\n\n\t BYEEE.....:-");
            getch();
            return;
        }
        bookings= fopen("booking_hist.txt","a+");
        printf("                Enter The Passenger ID Number::");
        scanf("%d",&booking.ID_num);
        printf("              Enter  Name..(one name only...):: ");
        scanf("%s",booking.name);
        printf("                                Enter  gender:: ");
        scanf("%s",&booking.gender);
        printf("                    Enter  Departure Location:: ");
        scanf("%s",booking.dep_location);
        printf("                           Enter  Destination:: ");
        scanf("%s",booking.destination);
        printf("                        Enter  Departure time:: ");
        scanf("%s",booking.time);
        printf("                           Enter Booking Date::");
        scanf("%s",booking.date);

        fprintf(bookings,"\n%d %s %s from %s to %s at %s on %s",booking.ID_num, booking.name, booking.gender, booking.dep_location, booking.destination, booking.time, booking.date);
        printf("\n\n=====================================================================total amount is %d Ksh ==================================",total_price);

        fclose(bookings);

        int row, col;
        printf("\n\n\tEnter row (1-%d) and column (1-%d) to book: ", ROWS, COLS);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        printf("\n\n\tInvalid seat selection.\n");
        getch();
        return;
        }

        if (busSchedules[busId - 1][1] == 0) {
        printf("\n\n\tNo available seats for this bus.\n");
        getch();
        return;
        }

        if (bookings1[busId - 1][row - 1][col - 1].timestamp != 0) {
        printf("\n\n\tSeat is already booked.\n");
        getch();
        return;
        }

        bookings1[busId - 1][row - 1][col - 1].busId = busId;
        bookings1[busId - 1][row - 1][col - 1].row = row;
        bookings1[busId - 1][row - 1][col - 1].col = col;
        bookings1[busId - 1][row - 1][col - 1].timestamp = time(NULL);
        busSchedules[busId - 1][1]--;

        file = fopen("booking_data.txt", "a+");
        if (file == NULL) {
        printf("\n\n\tError opening the file for writing.\n");
        return;
        }

        for (int i = 0; i < MAX_BUSES; i++) {
            for (int row = 0; row < ROWS; row++) {
                for (int col = 0; col < COLS; col++) {
                    if (bookings1[i][row][col].timestamp != 0) {
                        fprintf(file, "%d %d %d %ld\n", i + 1, row + 1, col + 1, bookings1[i][row][col].timestamp);
                    }
                }
            }
        }

        fclose(file);

        printf("\n\n\n\t    ********BOOKING SUCCESSFUL HAVE A NICE AND SAFE ONE :-) *********  ");

        getch();

    }while(route_num !=7);{
    system("cls");
    printf("\t\t\n\nBYEE....:-");

    ticket_print = fopen("print_ticket","w");
    fprintf(ticket_print,"\n::%d \n::%s \n%s \nfrom::%s \nto::%s \nat::%s \non%s::",booking.ID_num, booking.name, booking.gender, booking.dep_location, booking.destination, booking.time, booking.date);
    printf("\n\n=====================================================================total amount is %d Ksh ==================================",total_price);


    fclose(ticket_print);
    printf("print ticket successful");
    return;
    }

}


void cancelBooking(int busId)
{
    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");

    printf("\n\t\t\t\t********************cancel ticket************************\n");
    canceled_ticket= fopen("canceled.txt","a+");

    printf("                Enter The Passenger ID Number::");
    scanf("%d",&booking.ID_num);
    printf("           Enter  Name..(one name only...):: ");
    scanf("%s",booking.name);
    printf("                                Enter  gender:: ");
    scanf("%s",&booking.gender);
    printf("                    Enter  Departure Location:: ");
    scanf("%s",booking.dep_location);
    printf("                           Enter  Destination:: ");
    scanf("%s",booking.destination);
    printf("                            Enter cancel time::");
    scanf("%s",booking.time);
    printf("                            Enter Cancel Date::");
    scanf("%s",booking.date);

    fprintf(canceled_ticket,"\n%d %s %s from %s to %s at %s on %s",booking.ID_num, booking.name, booking.gender, booking.dep_location, booking.destination, booking.time, booking.date);

    fclose(canceled_ticket);

    int row, col;
    printf("\n\n\tEnter row (1-%d) and column (1-%d) to cancel booking: ", ROWS, COLS);
    scanf("%d %d", &row, &col);

    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        printf("\n\n\tInvalid seat selection.\n");
        getch();
        return;
    }

    if (bookings1[busId - 1][row - 1][col - 1].timestamp == 0) {
        printf("\n\n\tNo booking found for this seat.\n");
        getch();
        return;
    }

    bookings1[busId - 1][row - 1][col - 1].timestamp = 0;
    busSchedules[busId - 1][1]++;

    printf("\n\n\tBooking canceled successfully!\n");
    getch();
}

void viewAllBookings(int busId)
{
    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");

    printf("\n-----------------------------------------------");
    printf("\n\tAll bookings for Bus %d:\n", busId);
    printf("-----------------------------------------------\n\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (bookings1[busId - 1][row][col].timestamp != 0) {
                printf("\n\t\t>>Seat %d-%d, Booking Time: %s", row + 1, col + 1, ctime(&bookings1[busId - 1][row][col].timestamp));
            }
        }
    }
    getch();
}

void canceled_tickets()
{
    system("cls");

   int i=0, j=0;
    char ch;
    char admin[12] = "JOYCE";
    char pass[12]= "cancel";
 do{
        system("cls");
        printf("\n\t\t\t\t-------------------------------------------------------------------------------------\t");
        printf("\n\t\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
        printf("\t\t\t\t-------------------------------------------------------------------------------------\t\n\n");
        printf("\n\n\t\t\t\t        ========================CLASSFIED DATA ACCESS========================\n\n\n\n");
        printf("\n\n\n**ENTER YOUR PASSWORD:\n      ");
        while((ch= getch())!=13){
            pass[i]=ch;
            printf(".");
            i++;
        }

        pass[i] = '\0';
        i = 0;

        if(strcmp(pass,"cancel")==0){
            printf("\n\n\t**WELCOME %s ,ACCESS GRANTED!!**\n",admin);
            printf("press any key");
            getch();
            break;
        }
        else{
            printf("\n\n\t**WRONG PASSWORD TRY AGAIN\n");
            getch();
            j++;
        }

    }while(j <=2 );
    if(j > 2){
        printf("==========================*SYSTEM BLOCKED, ACCESS DENIED!!!=============================");
        getch();
        exit(0);
    }
    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
    printf("\n\t\t\t\t********************canceled tickets************************\n\n\n\n");
    canceled_ticket= fopen("canceled.txt","r");
    char bookingcontent[5000];
    if(canceled_ticket !=NULL){
        while(fgets(bookingcontent,5000,canceled_ticket)){
            printf("%s",bookingcontent);
        }
    }else{
        printf("no such file found");
    }

    printf("\n\n\n\npress any key to opt out.....");

    fclose(canceled_ticket);

    getch();

}

void classified_booking_hist()
{
    int i=0, j=0;
    char ch;
    char admin[12] = "JOYCE";
    char pass[12]= "classified";
 do{
        system("cls");
        printf("\n\t\t\t\t-------------------------------------------------------------------------------------\t");
        printf("\n\t\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
        printf("\t\t\t\t-------------------------------------------------------------------------------------\t\n\n");
        printf("\n\n\t\t\t\t        ========================CLASSFIED DATA ACCESS========================\n\n\n\n");
        printf("\n\n\n**ENTER YOUR PASSWORD:\n      ");
        while((ch= getch())!=13){
            pass[i]=ch;
            printf(".");
            i++;
        }

        pass[i] = '\0';
        i = 0;

        if(strcmp(pass,"classified")==0){
            printf("\n\n\t**WELCOME %s ,ACCESS GRANTED!!**\n",admin);
            printf("press any key");
            getch();
            break;
        }
        else{
            printf("\n\n\t**WRONG PASSWORD TRY AGAIN\n");
            getch();
            j++;
        }

    }while(j <=2 );
    if(j > 2){
        printf("==========================*SYSTEM BLOCKED, ACCESS DENIED!!!=============================");
        getch();
        exit(0);
    }

    system("cls");
    printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
    printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
    printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
    printf("\n\t\t\t\t********************Classified Booking Data************************\n");
    bookings= fopen("booking_hist.txt","r");
    char bookingcontent[5000];
    if(bookings !=NULL){
        while(fgets(bookingcontent,5000,bookings)){
            printf("%s",bookingcontent);
        }
    }else{
        printf("no such file found");
    }

    printf("\n\n\n\npress any key to opt out.....");

    fclose(bookings);
    getch();
}

void loadBookingData()
{
    FILE *file = fopen("booking_data.txt", "r");
    if (file == NULL) {
        printf("No booking data found.\n");
        return;
    }

    int busId, row, col;
    time_t timestamp;

    while (fscanf(file, "%d %d %d %ld\n", &busId, &row, &col, &timestamp) == 4) {
        if (busId >= 1 && busId <= MAX_BUSES && row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
            bookings1[busId - 1][row - 1][col - 1].busId = busId;
            bookings1[busId - 1][row - 1][col - 1].row = row;
            bookings1[busId - 1][row - 1][col - 1].col = col;
            bookings1[busId - 1][row - 1][col - 1].timestamp = timestamp;
            busSchedules[busId - 1][1]--;
        }
    }

    fclose(file);
}

int main() {

    int option;

    initializeSystem();
    loadBookingData();

        system("cls");
        printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
        printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
        printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
        login();
    do{
        system("cls");
        printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
        printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
        printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
        printf("\n\t\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t\t***ENTER YOUR CHOICE TO ACCESS::                    \n");
        printf("\t\t\t\t\t-------------------------------------------\n");
        printf("\t\t\t\t\t 1: Add Bus Schedule 	  \n");
        printf("\t\t\t\t\t 2: Delete Bus Schedule  \n");
        printf("\t\t\t\t\t 3: View All Bus  \n");
        printf("\t\t\t\t\t 4: Book Seat	  \n");
        printf("\t\t\t\t\t 5: Cancel Booking	  \n");
        printf("\t\t\t\t\t 6: View Booking History		  \n");
        printf("\t\t\t\t\t 7: View Classified Booking History	  \n");
        printf("\t\t\t\t\t 8: View Canceled Tickets		          \n");
        printf("\t\t\t\t\t 9: EXIT\n");
        printf("\t\t\t\t\t-------------------------------------------\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:{
            // Add a bus schedule
            system("cls");
            printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
            printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
            printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
            int busId, availableSeats;
            printf("Enter Bus ID: ");
            scanf("%d", &busId);
            printf("Enter Available Seats: ");
            scanf("%d", &availableSeats);

            if (busId >= 1 && busId <= MAX_BUSES) {
                busSchedules[busId - 1][0] = busId;
                busSchedules[busId - 1][1] = availableSeats;
                printf("\n\n\n\n******Bus schedule added successfully.******\n");
                getch();
            } else {
                printf("Invalid Bus ID.\n");
                getch();
            }
        break;
        }
        case 2:{
            // Delete a bus schedule
            system("cls");
            printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
            printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
            printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
            int busId;
            printf("Enter Bus ID to delete: ");
            scanf("%d", &busId);

            if (busId >= 1 && busId <= MAX_BUSES) {
                busSchedules[busId - 1][0] = 0;
                busSchedules[busId - 1][1] = 0;
                printf("\n\n\n\n*******Bus schedule deleted successfully.**********\n");
                getch();
            } else {
                printf("\n\n\n\tInvalid Bus ID.\n");
                getch();
            }
        break;
        }
        case 3:{
            // View all buses
            displayBusSchedules();
            break;
        }
        case 4:{
            // Book a seat
            system("cls");
            int busId;
            buslist= fopen("add_bus.txt","r");
            char filecontent1[1000];
            if(buslist !=NULL){
                while(fgets(filecontent1,1000,buslist)){
                    printf("%s",filecontent1);
                }
            }else{
                printf("There Is No Such File");
            }

            fclose(buslist);

            printf("\n\n\n\tEnter Bus ID (1-%d): ", MAX_BUSES);
            scanf("%d", &busId);

            if (busId >= 1 && busId <= MAX_BUSES) {
                bookSeat(busId);
            } else {
                printf("Invalid Bus ID.\n");
            }
            break;
        }
        case 5:{
            // Cancel booking
            system("cls");
            int busId;
            printf("\n\t\t\t-------------------------------------------------------------------------------------\t");
            printf("\n\t\t\t\t\t\t***GYTOR BUS RESERVATION SYSTEM***\t\t\t\t\n");
            printf("\t\t\t-------------------------------------------------------------------------------------\t\n\n");
            buslist= fopen("add_bus.txt","r");
            char filecontent1[1000];
            if(buslist !=NULL){
                while(fgets(filecontent1,1000,buslist)){
                    printf("%s",filecontent1);
                }
            }else{
                printf("There Is No Such File");
            }

            fclose(buslist);
            printf("\n\n\n\t\tEnter The Choice That was Passenger's Journey Plan (1-%d):: ", MAX_BUSES);
            scanf("%d", &busId);

            if (busId >= 1 && busId <= MAX_BUSES) {
                cancelBooking(busId);
            } else {
                printf("Invalid Bus ID.\n");
            }
            break;
        }
        case 6:{
            // View all bookings for a bus
            int busId;
            printf("Enter Bus ID (1-%d): ", MAX_BUSES);
            scanf("%d", &busId);

            if (busId >= 1 && busId <= MAX_BUSES) {
                viewAllBookings(busId);
            } else {
                printf("Invalid Bus ID.\n");
            }
            break;
        }
        case 7:{
            classified_booking_hist();
            break;
        }
        case 8:{
            canceled_tickets();
            break;
        }
        }
        if (option != 9) {
            printf("Invalid option.\n");
        }
    } while (option != 9);

    return 0;
}
