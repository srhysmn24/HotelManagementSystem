#include <iostream>
#include <iomanip> // setw();
#include <string.h> // strcmp(), toupper()
#include <stdlib.h> // system("cls") - clearing the screen
#include <unistd.h> //sleep(second);
#include <conio.h> // getch() - PAUSE, press ENTER to continue
using namespace std;
void homePage();
//----------------------------------------------------------------------------- ADMINISTRATOR PROTOTYPE BELOW
void admin();
void adminMenu();
void printTotSale();
void printAverage();
void showAllInfo();
//----------------------------------------------------------------------------- GUEST PROTOTYPE BELOW
void guest();
void budget();
void honeymoon();
void family();
void suites();
//----------------------------------------------------------------------------- RECEIPT
void receipt(string,double,string,string);
void room_Type (string,double);
void pack_Type (string,double,string);
void howToPay(char , double);
// PAYMENT TYPE
void payment(double);
void cash (double);
void creditCard (double);
void touchNGo(double);
void boost (double);
void paypal (double);
void debit(double);
//global variables below
double totalSales = 0, average = 0,price = 0, count = 0;
char chosenPack,chosenRoom,codePack,proceed,name[40],fonNum[20];
int paymentType, chosenDays,budg = 0, hMoon = 0, fam = 0, suite = 0,ePack = 0, fPack = 0, gPack = 0;;

int main() {
  
  char progress;
  
	homePage();
	x:
	cout << "\tNeed to CONTINUE? "<<endl;
	cout << "\tPress Y if yes...";
	cin >> progress;
	
	if (toupper(progress)=='Y'){
	  homePage();
	  goto x;
  }
  else{
    system("cls");
    cout <<"\nPROGRAM TERMINATED SUCCESSFULLY!";
    exit(0);
  }
 
	
return 0;
}

void homePage() { //DONE
	char choose, proceed, yes;
	system("cls");

	cout<<"+----------------------------------------+"<<endl;
	cout<<"|HOME PAGE: WELCOME TO BLUEMOON HOTEL    |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"|1. Administrator [A]                    |"<<endl;
	cout<<"|2. Guest         [G]                    |"<<endl;
	cout<<"|3. CLOSE Program [X]                    |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"Choose Login As: ";
	cin>> choose;
	if (choose == '1' || toupper(choose) == 'A' ){
		admin();
	}
	else if (choose == '2' || toupper(choose) == 'G'){
		guest();
  }
	else if (choose == '3' || toupper(choose) == 'X') {
		cout<<"Are you sure you want to CLOSE the Program?\nPress [X]: ";
		cin>> yes;
		if (toupper(yes) == 'X'){
		  system("cls");
		}
		else{
			homePage();
    }
	}
	else{
		homePage();
  }

}
//----------------------------------------------------------------------------- ADMINISTRATOR DEFINITION BELOW
void admin() { //DONE
	char adminCode[20];
	int attempt = 0, countDown = 2;
	
	x:
	  
	system("cls");

  cout<<"+----------------------------------------+"<<endl;;
	cout<<"|      Logging In As Administrator       |"<<endl;
	cout<<"+----------------------------------------+"<<endl;;
	cout<<"Enter 4 admin code : ";
	cin>> adminCode;
	

	if (strcmp(adminCode , "4321") == 0){
	  adminMenu();
  }
  else {
    attempt ++;
    if(attempt < 3){
       cout<<"Wrong code. "<<countDown<<" attempt left!"<<endl;
       cout<<"Press ENTER to try again."<<endl;
       getch();
       countDown--;
       goto x;
    }
    else {
       cout << "\nThree attempts failed.";
      cout<<"\nYou will be redirected to the HOME PAGE."<<endl;
      sleep(2);
      homePage();
    }
  }

}
void adminMenu() {
	system("cls");
	int menu;
	char reselect;
	//do {
	cout<<"+------------------------------+"<<endl;
	cout<<"|WELCOME TO ADMINISTRATION MENU|"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|1. Check Total Sale           |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|2. Check Average Sale         |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|3. Show all Information       |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|4. Back to HOME PAGE          |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"Choose Menu: ";
	cin>> menu;
	if (menu == 1)
		printTotSale();
	else if (menu == 2)
		printAverage();
	else if (menu == 3)
	  	showAllInfo();
	else if (menu == 4)
		homePage();
	else {
		cout<<"\nInvalid Input!"<<endl;
		cout<<"Press ENTER to continue";
		getch();
		adminMenu();
	}

}

void printTotSale() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"|   TOTAL SALE PAGE    |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Total Sale: "<< totalSales <<endl;
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
void printAverage() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"|     AVERAGE PAGE     |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Average sale: "<< average <<" per person" <<endl;
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
void showAllInfo() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"| SHOW ALL INFORMATION |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Total sale: "<< totalSales <<endl;
	cout<<"Average sale: "<< average <<endl;
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
//-------------------------------------------------------------------------------------------------------------------- GUEST DEFINITION BELOW
void guest() {

	system("cls"); 

	char code, codePack, proceed, other;
	int days;
	double total = 0, price,costPack = 0, totalAll = 0;

	cin.ignore(1024,'\n'); // to flush out remaining characters

	cout<<"+----------------------------------+"<<endl;
	cout<<"|       WELCOME TO GUEST PAGE      |"<<endl;
	cout<<"+----------------------------------+"<<endl;
	cout<<"Please enter your name: " ;
	cin.getline(name,20);
	cout<<"Enter your phone number: ";
	cin.getline(fonNum,20);

	count++; // counting number of customer

	system("cls");

	cout<<"+--------------------------------+"<<endl;
	cout<<"  Hi "<<setw(5)<<name <<"!  "<<endl;
	cout<<"+------+------------+------------+"<<endl;
	cout<<"| CODE | MENU       | PRICE (RM) |"<<endl;
	cout<<"+------+------------+------------+"<<endl;
 	cout<<"|  A   | BUDGET     |    75.O0   |"<<endl;
	cout<<"|  B   | HONEYMOON  |   250.00   |"<<endl;
	cout<<"|  C   | FAMILY     |   450.00   |"<<endl;
	cout<<"|  D   | SUITE      |   600.00   |"<<endl;
	cout<<"+------+-------------------------+"<<endl;
	cout<<"|  X   | Back to HOME PAGE       |"<<endl;
	cout<<"+--------------------------------+"<<endl;

	cout<<"Enter code: ";
	cin>> code;

	if (toupper(code) != 'A' && toupper(code) != 'B' && toupper(code) != 'C' && toupper(code) != 'D'){
		homePage();
  }

	chosenRoom = toupper(code);

	if (toupper(code) == 'A') {
		budget();
	}
	else if (toupper(code) == 'B') {
		honeymoon();
	}
	else if (toupper(code) == 'C') {
		family();
	}
	else if (toupper(code) == 'D') {
		suites();
	}

	system("cls");
}

void budget() //done
	{
  int days = 0,price = 0,costPack = 0;
	cout<<"Days: ";
	cin>>days;
	chosenDays = days;

	cout<<"Do you want an EXTRAPACKAGE (Y/N) : ";
	cin>> proceed;
	if (toupper(proceed) == 'Y'){
	  x:
    system("CLS");
		cout<<"----------------------------------------------"<<endl;
		cout<<"|CODE  |  PACKAGE                |  PRICE(RM) |"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"|E     |  BREAKFAST              |    30.0    |"<<endl;
		cout<<"|F     |  SUNSET VIEW DINNER     |    45.0    |"<<endl;
		cout<<"|G     |  CANDLE LIGHT DINNER    |    65.0    |"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Enter code of the package : ";
		cin>>codePack;

    if (toupper(codePack)=='E'||toupper(codePack)=='F'|| toupper(codePack)=='G'){

			if(toupper(codePack)=='E'){
				costPack = 30.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='F'){
				costPack = 45.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='G'){
				costPack = 65.0;
				chosenPack = codePack;
      }
      
    }
		else{
			cout<<"Invalid code"<<endl;
      goto x;
		}
  
  }
  else {
    costPack = 0;
    chosenPack = 'X';
  }

	price = 75.00 * days + costPack;
	cout<<"PRESS ENTER TO CONTNUE";
	getch();
	payment (price);
}

void honeymoon(){
	int days = 0,price = 0,costPack = 0;
	cout<<"Days: ";
	cin>>days;
	chosenDays = days;

	cout<<"Do you want an EXTRAPACKAGE (Y/N) : ";
	cin>> proceed;
	if (toupper(proceed) == 'Y'){
	  x:
    system("CLS");
		cout<<"----------------------------------------------"<<endl;
		cout<<"|CODE  |  PACKAGE                |  PRICE(RM) |"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"|E     |  BREAKFAST              |    30.0    |"<<endl;
		cout<<"|F     |  SUNSET VIEW DINNER     |    45.0    |"<<endl;
		cout<<"|G     |  CANDLE LIGHT DINNER    |    65.0    |"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Enter code of the package : ";
		cin>>codePack;

    if (toupper(codePack)=='E'||toupper(codePack)=='F'|| toupper(codePack)=='G'){

			if(toupper(codePack)=='E'){
				costPack = 30.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='F'){
				costPack = 45.0;
				chosenPack = codePack;
			}
			
			else if(toupper(codePack)=='G'){
				  costPack = 65.0;
				  chosenPack = codePack;
      }
    }
		else{
			cout<<"Invalid code"<<endl;
      goto x;
		}
  }
  else {
    costPack = 0;
    chosenPack = 'X';
  }
	price = 250.00 * days + costPack;
	cout<<"PRESS ENTER TO CONTNUE";
	getch();
	payment (price);
	}

void family()
	{
	 int days = 0,price = 0,costPack = 0;
	cout<<"Days: ";
	cin>>days;
	chosenDays = days;

	cout<<"Do you want an EXTRAPACKAGE (Y/N) : ";
	cin>> proceed;
	if (toupper(proceed) == 'Y'){
	  x:
    system("CLS");
		cout<<"----------------------------------------------"<<endl;
		cout<<"|CODE  |  PACKAGE                |  PRICE(RM) |"<<endl;
		cout<<"--------------------------------------------"<<endl;
		cout<<"|E     |  BREAKFAST              |    30.0    |"<<endl;
		cout<<"|F     |  SUNSET VIEW DINNER     |    45.0    |"<<endl;
		cout<<"|G     |  CANDLE LIGHT DINNER    |    65.0    |"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Enter code of the package : ";
		cin>>codePack;

    if (toupper(codePack)=='E'||toupper(codePack)=='F'|| toupper(codePack)=='G'){

			if(toupper(codePack)=='E'){
				costPack = 30.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='F'){
				costPack = 45.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='G'){
				costPack = 65.0;
				chosenPack = codePack;
      }
    }
		else{
			cout<<"Invalid code"<<endl;
      goto x;
		}
  }
  else {
    costPack = 0;
     chosenPack = 'X';
  }

		price = 450.00 * days + costPack;

		cout<<"PRESS ENTER TO CONTNUE";
		getch();
		payment (price);
	}

void suites()
	{
	 int days = 0,price = 0,costPack = 0;
	cout<<"Days: ";
	cin>>days;
  chosenDays = days;

	cout<<"Do you want an EXTRAPACKAGE (Y/N) : ";
	cin>> proceed;
	if (toupper(proceed) == 'Y'){
	  x:
    system("CLS");
		cout<<"----------------------------------------------"<<endl;
		cout<<"|CODE  |  PACKAGE                |  PRICE(RM) |"<<endl;
		cout<<"|---------------------------------------------|"<<endl;
		cout<<"|E     |  BREAKFAST              |    30.0    |"<<endl;
		cout<<"|F     |  SUNSET VIEW DINNER     |    45.0    |"<<endl;
		cout<<"|G     |  CANDLE LIGHT DINNER    |    65.0    |"<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Enter code of the package : ";
		cin>>codePack;

    if (toupper(codePack)=='E'||toupper(codePack)=='F'|| toupper(codePack)=='G'){

			if(toupper(codePack)=='E'){
				costPack = 30.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='F'){
				costPack = 45.0;
				chosenPack = codePack;
			}
			else if(toupper(codePack)=='G'){
				costPack = 65.0;
				chosenPack = codePack;
      }
    }
		else{
			cout<<"Invalid code"<<endl;
      goto x;
		}
  }
  else {
    costPack = 0;
    chosenPack = 'X';
  }
	price = 600.00 * days + costPack;
	cout<<"PRESS ENTER TO CONTNUE";
	getch();
  payment(price);

}
void payment (double total){

  g:
  system ("cls");
  cout<<"+-------------------------------+"<<endl;
	cout<<"|Your total purchase is: " <<setw(5)<< fixed << setprecision(2) << total <<"|"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"|Choose your payment method     |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"|1. Cash                        |"<<endl;
	cout<<"|2. Credit Card (3% Discount)   |"<<endl;
	cout<<"|3. Touch-N-Go  (Charge 2%)     |"<<endl;
	cout<<"|4. Boost                       |"<<endl;
	cout<<"|5. Paypal                      |"<<endl;
	cout<<"|6. Debit Card                  |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"Your choice: ";
	cin>> paymentType;

	if (paymentType == 1)
		cash(total);
	else if (paymentType == 2)
		creditCard(total);
	else if (paymentType == 3)
		touchNGo(total);
	else if (paymentType == 4)
		boost(total);
	else if (paymentType == 5)
		paypal(total);
  else if (paymentType == 6)
		debit(total);
	else {
		cout<<"Invalid input. "<<endl;
		sleep (1);
		goto g;
	}
	

}
void cash (double total){
  
  char payType = '1';
  
  system ("cls");

  double pay = 0 , addedCash = 0 , balance = 0;
  
  cout << "\tCASH"<<endl;
  cout << "You have to pay : RM "<< fixed << setprecision(2) << total<<endl;
  cout << "Customer's CASH : RM ";
  cin >> pay;

  do {
    
    double balance = pay - total;
    if (balance >= 0 ){
      cout << "Balance : RM "<< fixed << setprecision(2)<< balance<<endl;
    }
    else if (balance < 0){
      cout << "Your CASH is not enough ."<<endl;
      cout << fixed << setprecision(2) << total;
      cout << "Your CASH paid is "<<balance<<". Please add more cash."<<endl;
      cout << "CASH added :";
      cin >> addedCash;
      pay += addedCash;
    }

  }while ( balance != 0);




  cout << "\n\nLoading Receipt";
  sleep (3);
  howToPay(payType , total);
}
void creditCard (double total){
  
  char payType = '2';
  
  total = total - (total*0.03);
  cout << "You have to pay RM "<< fixed << setprecision(2) << total << "."<<endl;
  cout << "SCAN HERE..."<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout << "Transaction done."<<endl;
  cout << "Please wait for your receipt."<<endl;
  sleep(2);
  howToPay(payType , total);
}
void touchNGo(double total){
  
  char payType = '3';
  
  total = total+ (total*0.02);
  cout << "You have to pay RM "<< fixed << setprecision(2) << total<< "."<<endl;
  cout << "SCAN HERE..."<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout << "Transaction done."<<endl;
  cout << "Please wait for your receipt."<<endl;
  sleep(2);
  howToPay(payType , total);


}
void boost (double total){
  
  char payType = '4';
  
  cout << "You have to pay RM "<< fixed << setprecision(2) << total << "."<<endl;
  cout << "SCAN QR CODE HERE..."<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout << "Transaction done."<<endl;
  cout << "Please wait for your receipt."<<endl;
  sleep(2);
  
  howToPay(payType , total);


}
void paypal (double total){
  
  char payType = '5';
  
  cout << "You have to pay RM "<< fixed << setprecision(2) << total << "."<<endl;
  cout << "SCAN QR CODE HERE..."<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout << "Transaction done."<<endl;
  cout << "Please wait for your receipt."<<endl;
  sleep(2);
  howToPay(payType , total);
}
void debit(double total){
  
  char payType = '6';
  
  cout << "You have to pay RM "<< fixed << setprecision(2) << total << "."<<endl;
  cout << "SCAN YOUR CARD HERE..."<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout <<"-"<<endl;
  sleep (1);
  cout << "Transaction done."<<endl;
  cout << "Please wait for your receipt."<<endl;
  sleep(2);
  
  howToPay(payType , total);

}

void receipt(string howpay,double priceTotal,string roomType,string packType){
  totalSales += priceTotal;
  average = totalSales/count;
  
  system("cls");
  cout<< endl;
	cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t|     BLUEMOON HOTEL RECEIPT          |"<<endl;
	cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t Thank You! Mr./Ms. "<< setw(13) << name<<endl;
  cout<<"\t Phone Number       "<< setw(13) << fonNum <<endl;
  cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t Room          "<< setw(18)<< roomType <<endl;
	cout<<"\t Pack          "<< setw(18)<< packType <<endl;
	cout<<"\t Day(s)        "<< setw(18) << chosenDays <<endl;
	cout<<"\t Total Payment         RM "<< setw(5) << fixed << setprecision(2) << priceTotal <<endl;
	cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t Payment Type :   "<< setw(6) << howpay <<endl;
	cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t|    Thank You For Staying With Us    |"<<endl;
	cout<<"\t+-------------------------------------+"<<endl;
	cout<<"\t|    H Y P E R B L O O M  SDN.BHD.    |"<<endl;
	cout<<"\t+-------------------------------------+"<<endl;
	
	cout << endl;
	
	cout<<"\tPress ENTER to close receipt."<<endl;
	getch();
	
}
void howToPay(char payType , double priceTotal){
  
  string howpay;

  if (payType == '1'){
     howpay= "Cash";
  }
  else if (payType == '2'){
     howpay= "Credit Card";
  }
  else if (payType == '3'){
     howpay= "Touch N Go";
  }
  else if (payType == '4'){
     howpay= "Boost";
  }
  else if (payType == '5'){
     howpay= "PayPal";
  }
  else if (payType == '6'){
     howpay= "Debit Card";
  }
  
  room_Type (howpay,priceTotal);


}
void room_Type(string howpay , double priceTotal){

  string roomType;

  if (toupper(chosenRoom)== 'A'){
     roomType= "Budget Room";
  }
  else if (toupper(chosenRoom) == 'B'){
     roomType= "HoneyMoon Room";
  }
  else if (toupper(chosenRoom)== 'C'){
     roomType= "Family Room";
  }
  else if (toupper(chosenRoom) == 'D'){
     roomType= "Suite Room";
  }
  pack_Type (howpay,priceTotal,roomType);

}
void pack_Type (string howpay, double priceTotal, string roomType ){
  string packType;
 
  if (toupper(chosenPack) == 'E'){
     packType= "Breakfast";
  }
  else if (toupper(chosenPack) == 'F'){
     packType= "Sunset View Dinner";
  }
  else if (toupper(chosenPack)== 'G'){
     packType= "Candle Light Dinner";
  }
  else if (toupper(chosenPack) == 'X'){
     packType = "No Pack Chosen";
  }
  receipt(howpay,priceTotal,roomType,packType);
}

 
  











