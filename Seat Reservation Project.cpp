#include<iostream>
using namespace std;

const int ROWS=12;
const int COLS=7;

const int FC_START=0;
const int FC_END=1;
const int BC_START=2;
const int BC_END=3;
const int EC_START=4;
const int EC_END=11;

const int FARE_FIRST=18000;
const int FARE_BUSINESS=14000;
const int FARE_ECONOMY=10000;

int checkAvailableSeats(int Seats[][7],int startRow,int endRow,int cols){
int count=0;
for(int r=startRow;r<=endRow;r++){
for(int c=0;c<cols;c++){
if(Seats[r][c]==0)
count++;
}
}
return count;
}

bool reserveSeats(int Seats[][7],int startRow,int endRow,int cols,int noOfSeats){
int booked=0;
for(int r=startRow;r<=endRow&&booked<noOfSeats;r++){
for(int c=0;c<cols&&booked<noOfSeats;c++){
if(Seats[r][c]==0){
Seats[r][c]=1;
booked++;
}
}
}
return(booked==noOfSeats);
}

bool bookFirstClass(int Seats[][7],int rows,int cols,int noOfSeats){
int available=checkAvailableSeats(Seats,FC_START,FC_END,cols);
if(noOfSeats<=0){
cout<<"Invalid number of seats."<<endl;
return false;
}
if(noOfSeats>available){
cout<<"Only "<<available<<" seat(s) available in First Class."<<endl;
return false;
}
reserveSeats(Seats,FC_START,FC_END,cols,noOfSeats);
cout<<"Booked "<<noOfSeats<<" First Class seat(s). Total Fare: Rs."<<noOfSeats*FARE_FIRST<<endl;
return true;
}

bool bookBusinessClass(int Seats[][7],int rows,int cols,int noOfSeats){
int available=checkAvailableSeats(Seats,BC_START,BC_END,cols);
if(noOfSeats<=0){
cout<<"Invalid number of seats."<<endl;
return false;
}
if(noOfSeats>available){
cout<<"Only "<<available<<" seat(s) available in Business Class."<<endl;
return false;
}
reserveSeats(Seats,BC_START,BC_END,cols,noOfSeats);
cout<<"Booked "<<noOfSeats<<" Business Class seat(s). Total Fare: Rs."<<noOfSeats*FARE_BUSINESS<<endl;
return true;
}

bool bookEconomyClass(int Seats[][7],int rows,int cols,int noOfSeats){
int available=checkAvailableSeats(Seats,EC_START,EC_END,cols);
if(noOfSeats<=0){
cout<<"Invalid number of seats."<<endl;
return false;
}
if(noOfSeats>available){
cout<<"Only "<<available<<" seat(s) available in Economy Class."<<endl;
return false;
}
reserveSeats(Seats,EC_START,EC_END,cols,noOfSeats);
cout<<"Booked "<<noOfSeats<<" Economy Class seat(s). Total Fare: Rs."<<noOfSeats*FARE_ECONOMY<<endl;
return true;
}

void getFare(){
cout<<"First Class Fare: Rs."<<FARE_FIRST<<" per seat"<<endl;
cout<<"Business Class Fare: Rs."<<FARE_BUSINESS<<" per seat"<<endl;
cout<<"Economy Class Fare: Rs."<<FARE_ECONOMY<<" per seat"<<endl;
}

void viewSeatingPlan(int Seats[][7],int rows,int cols){
cout<<"Seating Plan (O=Available X=Reserved)"<<endl;
cout<<"Seat:  1  2  3  4  5  6  7"<<endl;
for(int r=0;r<rows;r++){
if(r==FC_START) cout<<"[First Class]"<<endl;
if(r==BC_START) cout<<"[Business Class]"<<endl;
if(r==EC_START) cout<<"[Economy Class]"<<endl;
cout<<"Row "<<r+1<<"  ";
for(int c=0;c<cols;c++){
if(Seats[r][c]==0)
cout<<"O  ";
else
cout<<"X  ";
}
cout<<endl;
}
cout<<"First Class Available: "<<checkAvailableSeats(Seats,FC_START,FC_END,cols)<<endl;
cout<<"Business Class Available: "<<checkAvailableSeats(Seats,BC_START,BC_END,cols)<<endl;
cout<<"Economy Class Available: "<<checkAvailableSeats(Seats,EC_START,EC_END,cols)<<endl;
}

bool systemReset(int Seats[][7],int rows,int cols){
for(int r=0;r<rows;r++)
for(int c=0;c<cols;c++)
Seats[r][c]=0;
cout<<"System Reset. All seats are now available."<<endl;
return true;
}

int main(){
int Seats[ROWS][COLS]={0};
int choice;
bool result;
do{
cout<<"--------------------------------------------------"<<endl;
cout<<"   Welcome to Airplane Reservation System"<<endl;
cout<<"--------------------------------------------------"<<endl;
cout<<"1. Book First Class Seats"<<endl;
cout<<"2. Book Business Class Seats"<<endl;
cout<<"3. Book Economy Class Seats"<<endl;
cout<<"4. View Airplane Seating Plan"<<endl;
cout<<"5. View Fare(s)"<<endl;
cout<<"6. System Reset"<<endl;
cout<<"7. Exit from The Booking System"<<endl;
cout<<"--------------------------------------------------"<<endl;
cout<<"Enter your choice: ";
cin>>choice;
if(choice==1){
int n;
cout<<"Enter number of First Class seats to book: ";
cin>>n;
result=bookFirstClass(Seats,ROWS,COLS,n);
if(!result)
cout<<"Task was not completed successfully."<<endl;
}
else if(choice==2){
int n;
cout<<"Enter number of Business Class seats to book: ";
cin>>n;
result=bookBusinessClass(Seats,ROWS,COLS,n);
if(!result)
cout<<"Task was not completed successfully."<<endl;
}
else if(choice==3){
int n;
cout<<"Enter number of Economy Class seats to book: ";
cin>>n;
result=bookEconomyClass(Seats,ROWS,COLS,n);
if(!result)
cout<<"Task was not completed successfully."<<endl;
}
else if(choice==4){
viewSeatingPlan(Seats,ROWS,COLS);
}
else if(choice==5){
getFare();
}
else if(choice==6){
char confirm;
cout<<"Are you sure you want to reset? (y/n): ";
cin>>confirm;
if(confirm=='y'||confirm=='Y'){
result=systemReset(Seats,ROWS,COLS);
}
else{
cout<<"Reset cancelled."<<endl;
}
}
else if(choice==7){
cout<<"Goodbye!"<<endl;
}
else{
cout<<"Invalid choice."<<endl;
}
}while(choice!=7);

}
