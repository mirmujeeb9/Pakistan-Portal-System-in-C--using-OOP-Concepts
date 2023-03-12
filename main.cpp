//mujeeb ahmed csd 20I-0611

#include<iostream>
#include<iomanip>
#include"Header.h"



int main() {




	//	UrgentMailService b(250,"karachi","karachi",150);
	int one = 1;
	int choice = 0;
	//console

	while (choice != 5) {
		cout << setw(75) << "___________________________________" << endl;

		cout << setw(75) << "Welcome To Pakistan Postal System " << endl;
		cout << endl;
		cout << "enter 1 to sign in " << endl;
		cout << "enter 2 to sing up for new customer :" << endl;
		cout << "enter 3 for admin" << endl;
		cout << "enter 4 for GPO admin : " << endl;
		cout << "enter 5 to exit : " << endl;
		cout << setw(60);
		cin >> choice;

		//base class
		//other classes created through parent class Menu
		Menu testing;
		testing.newMenu(choice);

	}
	//	admin n;
	//	n.C.rts();
	//	PostOffice b();
	//	b.viewpostaloffice();









}