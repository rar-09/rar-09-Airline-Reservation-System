#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//addressing the Functions
void type(); void titles();
void lowTitle(); void BPass();
void passenger(); void takenseat();
void ecoColLimit(); void replaceO();

 //Variables
   string seatRes[3][18];
   char side[3]= {'D','C','A'};
   string lastName,firstName;
   char booking[10]; char row;
   int column,menu,seatType;
   int con3 = 2; int con2 = 1;
   int con1 = 0;
   int seatEcoplus = 6; int seatEco = 44;

int *seatType2 = &seatType;


int main()
{

    for(int x=0; x<3; x++){//2dArrayDeclaration
        for(int y=0; y<18;y++){
                seatRes[x][y]="A";
}
 }
    seatRes[0][17]+="  |D";
    seatRes[1][17]+="  |C";
    seatRes[2][17]+="  |A";
     seatRes[1][17]+="\n"; //not applicable seats
     seatRes[0][0]="N";
     seatRes[0][1]="N";
     seatRes[1][0]="N";
     seatRes[1][1]="N";


while (true){//The loop

     titles();
    for(int x=0; x<3; x++){
            cout<< "\n" <<side[x] << "|";
        for(int y=0; y<18;y++){
            cout << "  ";
            cout << seatRes[x][y];
}
 }
    lowTitle();
     cout << "\nReservation System Menu"<< endl<< "[1] Economy Plus"<< endl;
     cout << "[2] Economy"<< endl<< "Type chosen menu: ";
        cin>> seatType;


switch(seatType){
case 1://ecoPlus PATH
    passenger();
    cout << "Enter Chosen Menu: ";
        cin >> menu;
seatEcoplus--;

    if(menu == 1){//random Pick ECO PLUS
        srand(time(NULL));
            int randRow = rand() % 3;
                row = side[randRow];


                if(row == 'A'){
                        row = 'A';
                    int choiceCol[2]={1,18};
                    int randCol = rand()%2;
                    column = choiceCol[randCol];
                    BPass();
                    row = con3;
                     takenseat();
                    replaceO();


                } else if(row == 'C'){
                        row = 'C';
                    int choiceCol[2]={3,18};
                    int randCol = rand()%2;
                     column = choiceCol[randCol];
                    BPass();
                     row = con2;
                    takenseat();
                    replaceO();

                }
                    else if(row == 'D'){
                            row = 'D';
                    int choiceCol[2]={3,18};
                    int randCol = rand()%2;
                     column = choiceCol[randCol];
                    BPass();
                     row = con1;
                    takenseat();
                    replaceO();
                    }
         break;
        }

      else if(menu == 2){//manual pick ECO PLUS
        cout <<"------------- Manual Pick -------------"<<endl;
        cout << "Enter Row[A, C, D]: ";
            cin >> row;

                if(row != 'D' && row !='C' && row != 'A'){
                    cout << "Invalid Row!"<< endl;
                    break;
            }
            if(row == 'A'){
                cout << "Enter Column[1 & 18]: ";
            cin >> column;
             if(column != 1 && column != 18 ){
                    cout << "Invalid Column!"<< endl;
                        break;}
                        BPass();
                        row=con3;
                        takenseat();
                        replaceO();

                        break;

            } else if(row == 'C'){
                cout << "Enter Column[3 & 18]: ";
            cin >> column;
            if(column != 3 && column != 18 ){
                    cout << "Invalid Column!"<< endl;
                        break;
}                    BPass();
                    row=con2;
                    takenseat();
                    replaceO();

              break;

              } else if(row == 'D'){
                cout << "Enter Column[3 & 18]: ";
            cin >> column;
            if(column != 3 && column != 18 ){
                    cout << "Invalid Column!"<< endl;
                        break;
                        BPass();
}
                    row=con1;
                    takenseat();
                    replaceO();
}

              break;

      } else{
            cout<< "Invalid Menu!"<< endl;
        }

case 2://economy
    passenger();

     cout << "Enter Chosen Menu: ";
        cin >> menu;
seatEco--;
                srand(time(NULL));
     if(menu == 1){//random pick FOR ECONOMY
                int randRow = rand() % 3;
                row = side[randRow];

            if(row == 'A'){
                    row = 'A';
                int ColChoice[16]={2,3,4,5,6,7,8,9,10,11,
                                    19,20,21,22,23,24};
                   int ColRand= rand()%16;
                   column = ColChoice[ColRand];
                    BPass();
                   row = con3;
                   takenseat();
                    replaceO();
break;

            } else if(row == 'C') {
                row = 'C';
                int ColChoice[14]={4,5,6,7,8,9,10,11,
                                    19,20,21,22,23,24};
                    int ColRand= rand()%14;
                   column = ColChoice[ColRand];
                    BPass();
                   row = con2;
                   takenseat();
                    replaceO();
break;

            }else if(row == 'D') {
                row = 'D';
                int ColChoice[14]={4,5,6,7,8,9,10,11,
                                    19,20,21,22,23,24};
                    int ColRand= rand()%14;
                   column = ColChoice[ColRand];
                    BPass();
                   row = con1;
                   takenseat();
                    replaceO();

break;

            }


     }

     else if(menu == 2){ //Manual pick ECONOMY
        cout <<"------------- Manual Pick -------------"<<endl;
        cout << "Enter Row[A, C, D]: ";
            cin >> row;
            if(row != 'A' && row != 'C' && row != 'D'){
                cout << "Invalid Row!"<< endl;
                break;
        }
            if(row == 'A'){
                cout << "Enter Column[2 - 11 and 19-24]: ";
                    cin >> column;
                    BPass();
                    row = con3;
                    takenseat();
                replaceO();
                    if((column <= 1 || column <= 18) && (column >= 10 || column >= 23)){
                    cout << "Invalid Column!"<< endl;
                break;
                }

            }else if (row == 'C'){
                cout << "Enter Column[4 - 11 and 19-24]: ";
                    cin >> column;
                    BPass();
                    row = con2;
                    takenseat();
                    replaceO();
                ecoColLimit();
                    break;

                }else if(row == 'D'){
                    cout << "Enter Column[4 - 11 and 19-24]: ";
                    cin >> column;
                    BPass();
                    row = con1;
                    takenseat();
                    replaceO();
                   ecoColLimit();
                    break;
                    }

               } else{
            cout << "\nInvalid Input!\n\n";
             break;
            }

default:
    cout << "Invalid Seat Type!";
    break;

if(seatEco == 0 && seatEcoplus == 0){ //when the seats are full
    cout << "All passengers are on-board!";
    cout << "Next flight will leave in 3 hours.";
}
}

}
 }


//FUNCTIONS
void titles(){//guides for the array or seats
    cout  << "\n****************Airline Reservation System********************\n\n";
      cout <<"   Seat Availability: Economy Plus= "<< seatEcoplus << " Economy = "<< seatEco;
        cout << "\n\n"<< "  " ;
for(int k=1; k<12;k++){
        cout << "  "<< k<< "";
}for(int h=18; h<25;h++){
    cout << " ";
        cout << h;}
    cout <<"\n------------------------------";
        cout << "------------------------------";

}


void lowTitle(){//legend + line seperator

cout <<"\n------------------------------";
    cout << "------------------------------" << endl;

cout<<"\nLegend: A = Available O = Occupied N = Not Applicable" << endl;
cout << "***********************************************************"<< endl;

}


void type(){//for passenger info to be functionable
if(*seatType2 == 1){
    cout << " Economy Plus";
}
else if(*seatType2 == 2){
    cout << " Economy";
}
}

void BPass(){ //printing boarding pass

cout << "-------------------------- BOARDING PASS --------------------------"<<endl;
         cout << "SEAT TYPE:";
          type(); cout<<endl;
           cout << "SEAT NUMBER: "<<row<<column<<endl;
            cout << "\nBooking Number: " << booking << endl;
             cout << "Passenger Last Name: "<< lastName << endl;
              cout << "Passenger First Name: "<< firstName <<endl;

}


void passenger(){// passenger info

       cout <<"\n*************ENTER PASSENGER DETAILS**************";
        cout << "\nSEAT TYPE:";
        type();cout << "\nEnter Booking Number:";
        cin>> booking;
    cout << "Enter Passenger Last Name: ";
        cin.ignore();
        getline(cin,lastName);
    cout << "Enter Passenger First Name: ";
        getline(cin,firstName);
    cout <<endl;
    cout <<"********************************************************"<<endl;
    cout << "Economy Seat Assignment"<<endl;
    cout << "[1] Random Pick"<<endl;
    cout << "[2] Manual Pick"<<endl;

   }

void takenseat(){// if the seat are taken print error msg

    if(seatRes[row][column - 1] == "O" || seatRes[row][column - 7] == "O"){
                    cout << "\nSeat is Already Taken! Please choose again\n";
                    }

            char full;
    if(seatRes[0][4] == "O" && seatRes[0][10] == "O" &&
       seatRes[1][4] == "O" && seatRes[1][10] == "O" &&
       seatRes[2][0] == "O" && seatRes[2][10] == "O"){
    cout << "Economy Seats are full!\n Change to Economy? [Y]Yes/[N]No";
        cin >> full;
     if(full == 'Y'){
        seatType= 2;

    } else if(full == 'N'){
        cout << "Thank you! Next flight will leave in 3 hours.";

}}
}


void ecoColLimit(){ //limit for column in economy
    if(column < 4 || column < 11 && column > 19 || column > 24){
                    cout << "Invalid Column!"<< endl;
                    }
}




void replaceO(){// Replacing the seats with O
    if(column > 11){
        seatRes[row][column - 7] = "O";}
    else{
    seatRes[row][column-1]="O";
                                }
}



