//mujeeb ahmed 20I-0611 csd
//mujeeb ahmed 20I-0611 csd
#ifndef Header_h
#define Header_h

#include<fstream>
#include<string>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <limits>
#include <stdlib.h>
#include <ctime>
#include<string>

//static variables declared that are used to store the amount of stamps sold
static int stamp5;
static int stamp10;
static int stamp20;
static int stamp50;
static int stamp100;
static int stamps1;


static double stampcost;

using namespace std;





class GPO {


protected:
	string gpoadmin;
	string passgpo;


public:
	void GPOadmin() {
		string checkgpo = "mir mujeeb";
		string checkpass = "pass";

		gpoadmin = "l";
		int pco = 0;
		string pname;
		int pcode;
		string pcity;



		//signup process for gpo admin
		cout << "kindly input your name : " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, gpoadmin);
		cout << endl;
		cout << "kindly input your password : " << endl;
		cin >> passgpo;

		cout << endl;
		cout << "gpoadmin:" << gpoadmin << endl;
		if (checkgpo == gpoadmin) {
			if (checkpass == passgpo) {
				//if password correct then menu displayed for gpo priveliges
				cout << "login successfull : " << endl;
				cout << "please enter 1 to add new postal worker : " << endl;
				cout << "enter 2 to add new admin for the system  : " << endl;
				cout << "enter 3 to view postman details : " << endl;
				cout << "enter 4 to view admin details : " << endl;
				cout << "enter 5 to delete a postal worker: " << endl;
				cout << "enter 6 to delete a admin : " << endl;
				cin >> pco;
				//add new postal worker
				if (pco == 1) {
					ofstream write;
					write.open("postalworker.dat", ios::app);
					if (write) {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "enter postal worker name : " << endl;
						getline(cin, pname);
						cout << "enter postal worker ID : " << endl;
						cin >> pcode;
						cout << "enter city in which postal worker works : " << endl;
						cin >> pcity;
					}
					write << "name: " << pname << endl;
					write << "ID: " << pcode << endl;
					write << "city: " << pcity << endl;
					write << "-----" << endl;
					write.close();

				}
				//add new admin 
				else if (pco == 2) {
					string adname;
					int adID;
					string adpassword;
					ofstream write;
					write.open("admin.dat", ios::app);
					if (write) {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "enteradmin name : " << endl;
						getline(cin, adname);
						cout << "enter admin password : " << endl;
						cin >> adpassword;
						cout << "input admin ID: " << endl;
						cin >> adID;

					}
					write << "name: " << adname << endl;
					write << "ID: " << adID << endl;
					write << "password: " << adpassword << endl;
					write << "-----" << endl;
					write.close();


				}
				//postman details
				else if (pco == 3) {
					string line;
					ifstream read;
					read.open("postalworker.dat");
					while (!read.eof()) {
						getline(read, line);
						cout << line << endl;
					}
					read.close();
				}
				//admin details
				else if (pco == 4) {
					string line;
					ifstream read;
					read.open("admin.dat");
					while (!read.eof()) {
						getline(read, line);
						cout << line << endl;
					}
					read.close();


				}
				//deleting a postal worker
				else if (pco == 5) {
					string dname;
					int did;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "enter postal worker name " << endl;
					getline(cin, dname);
					cout << "input postal worker ID:" << endl;
					cin >> did;

					dname = "name: " + dname;
					string temp = to_string(did);
					temp = "ID : " + temp;
					ifstream read;
					read.open("postalworker.dat");

					ofstream write;
					write.open("temp.dat");

					string line;

					while (!read.eof()) {
						getline(read, line);
						if (line == dname) {
							while (line != "-----") {
								getline(read, line);
								// cout << "line: " << line << endl;
							}
							if (line == "-----") {
								getline(read, line);
							}
						}
						// cout << "writing line: " << line << endl;
						write << line << endl;
					}

					read.close();
					write.close();

					remove("postalworker.dat");
					rename("temp.dat", "postalworker.dat");

					cout << endl << "\t\t\t\t\t" << "admin removed successfully:" << endl;
					cout << endl;


				}
				//deleting an admin
				else if (pco == 6) {
					string dname;
					int did;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << "enter admin name:  " << endl;
					getline(cin, dname);
					cout << "input admin ID:  " << endl;
					cin >> did;

					dname = "name: " + dname;
					string temp = to_string(did);
					temp = "ID : " + temp;
					ifstream read;
					read.open("admin.dat");

					ofstream write;
					write.open("temp.dat");

					string line;

					while (!read.eof()) {
						getline(read, line);
						if (line == dname) {
							while (line != "-----") {
								getline(read, line);
								// cout << "line: " << line << endl;
							}
							if (line == "-----") {
								getline(read, line);
							}
						}
						// cout << "writing line: " << line << endl;
						write << line << endl;
					}

					read.close();
					write.close();

					remove("admin.dat");
					rename("temp.dat", "admin.dat");

					cout << endl << "\t\t\t\t\t" << "admin removed successfully:" << endl;
					cout << endl;

				}


			}
		}

	}

};



class PostOffice {
protected:
	string officeaddress;
	string officecity;
	int officecode;
	string off;


public:
	PostOffice() {

	}
	//function to view postal office data
	void viewpostaloffice() {
		string line;
		ifstream read;
		read.open("PostalOffice.dat");

		while (!read.eof()) {
			getline(read, line);
			cout << line << endl;


		}


		read.close();

	}

	//edit a postal office details
	void editpostaloffice() {
		ofstream write;
		write.open("PostalOffice.dat", ios::app);
		if (write) {
			cout << "Kindly input postal office city" << endl;
			getline(cin, officecity);
			cout << "kindly postal office address " << endl;
			getline(cin, officeaddress);
			cout << "kindly input postal office code :" << endl;
			cin >> officecode;

		}
		write << "City: " << officecity << endl;
		write << "Address: " << officeaddress << endl;
		write << "Postal Code: " << officecode << endl;


		write.close();
	}



};



// class of postal worker
class PostalWorker {
protected:
	int IDPostalWorker;

public:

	void setIDPostalWorker(int IDPostalWorker) {
		this->IDPostalWorker = IDPostalWorker;
	}

	int getIDPostalWorker() {
		return IDPostalWorker;
	}


};


//clerk class
class Clerk
{
protected:
	int IDClerk;

public:
	void setIDClerk(int IDClerk) {
		this->IDClerk = IDClerk;
	}
	int getIDClerk() {
		return IDClerk;
	}


};


class Postman {
protected:
	int IDPostman;

public:
	void setIDPostman(int IDPostman) {
		this->IDPostman = IDPostman;
	}
	int getIDPostman() {
		return IDPostman;
	}

};

class AccountOfficer {
protected:
	double totalcost;



public:





};

class Payment {
protected:
	double totalcost;

public:
	Payment(double weight, string city) {
		totalcost = 0;
	}
	//			void generatepayment(double weight,string receivercity){
	//				if (weight)
	//			}

};

//class adress to hold the address and city of sender and receiver
class Address {
protected:
	string senderaddress;
	string receiveraddress;
	string sendercity;
	string receivercity;

public:
	//setter and getters
	void setsenderaddress(string senderaddress) {
		this->senderaddress = senderaddress;
	}
	void setreceiveraddress(string receiveraddress) {
		this->receiveraddress = receiveraddress;
	}
	void setreceivercity(string receivercity) {
		this->receivercity = receivercity;

	}
};

//class customer ineriting data from postal worker class and address
class Customer :public PostalWorker, public Address
{
public:
	int IDcustomer;
	string sendername;
	string receivername;
	double weightparcel;
	double shippingtime;
	int sendercontact;
	int receivercontact;
	Address* adre;
	string sendercity;
	string receivercity;
	double parcelvalue;

public:
	Customer() {


	}
	//aggregation
	Customer(Address* adre) {
		this->adre = adre;
	}

	//setting customer details
	void setCustomer(int IDcustomer, string sendername, string receivername, double weightparcel, double shippingtime, int sendercontact, int receivercontact) {
		this->IDcustomer = IDcustomer;
		this->sendername = sendername;
		this->receivername = receivername;
		this->weightparcel = weightparcel;
		this->shippingtime = shippingtime;
		this->sendercontact = sendercontact;
		this->receivercontact = receivercontact;
	}

	void status() {

	}
	//composition of payment
	void costing(double weight, string sendercity) {
		Payment p(weight, sendercity);

	}
	friend void neworder();


};

class Invoice {




};


void setaddress(int address) {


}


class UrgentMailService
{
protected:
	double weight;
	string city;
	string send;
	string receive;
	double value;
	double weightcheck;
	int stamps;
	double totalcost;


public:
	double gettotal() {
		return totalcost;
	}
	UrgentMailService() {

	}
	//parametrized constructor to generate a new order in this category
	UrgentMailService(double weight, string sendercity, string receivercity, double parcelvalue)
	{
		this->weight = weight;
		this->city = city;
		send = sendercity;
		receive = receivercity;
		value = parcelvalue;
		totalcost = 0;


		stamps = 0;

		//values and pricing according to cirt and value
		if (sendercity == receivercity) {
			if (this->weight <= 250) {
				totalcost += 51;
			}
			else if (this->weight <= 500 && this->weight > 250) {
				totalcost += 64;
			}
			else if (this->weight > 500) {

				weightcheck -= 500;
				totalcost += 64;
				weightcheck = (weightcheck / 500) * 26;
				totalcost += weightcheck;
			}
		}

		if (sendercity != receivercity) {
			if (this->weight <= 250) {
				totalcost += 86;
			}
			else if (this->weight <= 500 && this->weight > 250) {
				totalcost += 132;
			}
			else if (this->weight > 500) {

				weightcheck = weightcheck - 500;
				totalcost += 132;
				weightcheck = (weightcheck / 500) * 43;
				totalcost += weightcheck;
			}
		}

		//t0 calulate stamps cost;
		if (sendercity == receivercity) {
			if (this->weight <= 250) {
				if (value < 100) {

					stamp5 += 1;
					stampcost = 5;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 100 && value < 200) {
					stamp10 += 1;
					stampcost = 10;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 200 && value < 500) {
					stamp20 += 1;
					stampcost = 20;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 500 && value < 1000) {
					stamp50 += 1;
					stampcost = 50;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 1000) {
					stamp100 += 1;
					stampcost = 100;
					stamps + 1;
					totalcost += stampcost;
				}
			}
			else if (this->weight <= 500 && this->weight > 250) {

				if (value <= 100) {
					stamp5 += 1;
					stampcost = 5;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 100 && value < 200) {
					stamp10 += 1;
					stampcost = 10;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 200 && value < 1000) {
					stamp50 += 1;
					stampcost = 50;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value >= 1000) {
					stamp100 += 1;
					stampcost = 100;
					stamps += 1;
					totalcost += stampcost;
				}

			}
			else if (this->weight > 500 && this->weight < 1000) {
				if (value < 100) {
					stamp5 += 1;
					stampcost = 5;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 100 && value < 200) {
					stamp10 += 1;
					stampcost = 10;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 200 && value < 500) {
					stamp20 += 1;
					stampcost = 20;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 500 && value < 1000) {
					stamp50 += 1;
					stampcost = 50;
					stamps += 1;
					totalcost += stampcost;
				}
			}
			else if (this->weight > 1000) {
				stamp100 += 1;
				stampcost = 100;
				stamps += 1;
				totalcost += 100;
			}

		}

		// to calculate stamps if city is not same
		if (sendercity != receivercity) {
			if (this->weight <= 250) {
				if (value < 50) {
					stamp5 += 1;
					stampcost = 5;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 100 && value < 150) {
					stamp10 += 1;
					stampcost = 10;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 150 && value < 250) {
					stamp20 += 1;
					stampcost = 20;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 250 && value < 500) {
					stamp50 += 1;
					stampcost = 50;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 500) {
					stamp100 += 1;
					stampcost = 100;
					stamps += 1;
					totalcost += stampcost;
				}

			}
			else if (this->weight > 250 && this->weight < 500) {
				if (value < 50) {
					stamp10 += 1;
					stampcost = 10;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 50 && value < 200) {
					stamp20 += 1;
					stampcost = 20;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 200 && value < 500) {
					stamp50 += 1;
					stampcost = 50;
					stamps += 1;
					totalcost += stampcost;
				}
				else if (value > 500 && value < 1000) {
					stamp100 += 1;
					stampcost = 100;
					stamps += 1;
					totalcost += stampcost;
				}
			}

			else if (this->weight > 500 && this->weight < 1000) {
				stamp50 += 1;
				stampcost = 50;
				stamps += 1;
				totalcost += stampcost;
			}
			else if (this->weight > 1000) {
				stamp100 += 1;
				stampcost = 100;
				stamps += 1;
				totalcost += stampcost;
			}

		}


		//writing the data into filing system
		ofstream write;
		write.open("urgentstamps.dat", ios::app);

		write << stampcost << endl;
		write << "total stamps: " << stamps << endl;

		write << "total cost:  " << totalcost << endl;
		write << "5rs stamp sold are: " << stamp5 << endl;
		write << "10rs stamps sold are : " << stamp10 << endl;
		write << "20rs stamps sold are : " << stamp20 << endl;
		write << "50rs stamps sold are : " << stamp50 << endl;
		write << "100rs stamps sold are : " << stamp100 << endl;


		write.close();

		cout << "Parcel successfully registered : " << endl;
		cout << "your total cost is : " << totalcost << endl;
		cout << "Stamp cost is : " << stampcost << endl;




	}



};

//this class deals with regualr mail
class RegularMailService {
protected:
	double weight;
	string city;
	double totalcost;
	string send;
	string receive;
	double value;
	double weightcheck;
	int stamps;



public:

	RegularMailService() {

	}
	//this takes the user input and then generates a new order
	RegularMailService(double weight, string sendercity, string receivercity, double parcelvalue)
	{
		this->weight = weight;
		this->city = city;
		send = sendercity;
		receive = receivercity;
		value = parcelvalue;

		stamps = 0;
		totalcost = 0;


		//this is to calculate to the amount according to weight in kilogtams
		if (this->weight <= 1) {
			totalcost += 100;
		}
		else if (this->weight <= 3 && this->weight > 1) {
			totalcost += 175;
		}
		else if (this->weight <= 5 && this->weight > 3) {

			totalcost += 250;

		}
		else if (this->weight <= 10 && this->weight > 5) {
			totalcost += 375;
		}
		else if (this->weight <= 15 && this->weight > 10) {
			totalcost += 500;
		}
		else if (this->weight <= 20 && this->weight > 15) {
			totalcost += 625;
		}
		else if (this->weight <= 25 && this->weight > 20) {
			totalcost += 750;
		}
		else if (this->weight <= 30 && this->weight > 25) {
			totalcost += 875;
		}




		//t0 calulate stamps cost;
		if (this->weight >= 0 && this->weight < 1) {
			if (value >= 100 && value < 200) {
				stamp5 += 1;
				stamps += 1;
				stampcost = 5;
				totalcost += stampcost;
			}
			else if (value >= 200 && value < 400) {
				stamp10 += 1;
				stamps += 1;
				stampcost = 10;
				totalcost += stampcost;


			}
			else if (value >= 400 && value < 800) {
				stamp20 += 1;
				stamps += 1;
				stampcost = 20;
				totalcost += stampcost;
			}
			else if (value >= 800 && value < 1000) {
				stamp50 += 1;
				stamps += 1;
				stampcost = 50;
				totalcost += stampcost;

			}
			else if (value >= 1000) {
				stamp100 += 1;
				stamps += 1;
				stampcost = 100;
				totalcost += stampcost;
			}


		}
		else if (this->weight >= 1 && this->weight < 3) {
			if (value > 80 && value < 180) {
				stamp5 += 1;
				stampcost = 5;
				stamps += 1;
				totalcost += stampcost;

			}
			else if (value >= 180 && value < 360) {
				stamp10 += 1;
				stampcost = 10;
				stamps += 1;
				totalcost += stampcost;

			}
			else if (value >= 360 && value < 500) {
				stamp20 += 1;
				stampcost = 20;
				stamps += 1;
				totalcost += stampcost;

			}
			else if (value >= 500 && value < 600) {
				stamp50 += 1;
				stampcost = 50;
				stamps += 1;
				totalcost += stampcost;
			}
			else if (value >= 600) {
				stamp100 += 1;
				stampcost = 100;
				stamps += 1;
				totalcost += stampcost;
			}


		}
		else if (this->weight >= 3 && this->weight <= 5) {
			if (value >= 60 && value < 160) {
				stamp5 += 1;
				stampcost = 5;
				stamps += 1;
				totalcost += stampcost;

			}
			else if (value >= 160 && value < 300) {
				stamp10 += 1;
				stampcost = 10;
				stamps += 1;
				totalcost += stampcost;
			}
			else if (value >= 300 && value < 500) {
				stamp20 += 1;
				stampcost = 20;
				stamps += 1;
				totalcost += stampcost;
			}
			else if (value >= 500 && value < 800) {
				stamp50 += 1;
				stampcost = 50;
				stamps += 1;
				totalcost += stampcost;
			}
			else if (value >= 800) {
				stamp100 += 1;
				stampcost = 100;
				stamps += 1;
				totalcost += stampcost;
			}

		}
		else if (weight > 5) {
			if (value >= 1)
			{
				stamp100 += 1;
				stampcost = 100;
				stamps += 1;
				totalcost += stampcost;
			}
		}


		//this below program is to write the total stamps collection and costing in file 
		ofstream write;
		if (write) {
			cout << "file is open" << endl;
		}
		else {
			cout << "file is not open" << endl;
		}
		write.open("regularstamps.dat", ios::app);

		write << stampcost << endl;
		write << "total stamps: " << stamps << endl;

		write << "total cost:  " << totalcost << endl;
		write << "5rs stamp sold are: " << stamp5 << endl;
		write << "10rs stamps sold are : " << stamp10 << endl;
		write << "20rs stamps sold are : " << stamp20 << endl;
		write << "50rs stamps sold are : " << stamp50 << endl;
		write << "100rs stamps sold are : " << stamp100 << endl;


		write.close();

		cout << "Parcel successfully registered : " << endl;
		cout << "your total cost is : " << totalcost << endl;
		cout << "Stamp cost is : " << stampcost << endl;

		/*
		ofstream write;
		write.open("regularstamps.dat", ios::app);

		write << "total stamps: " << stamps << endl;
		write << "stamp cost: " << stampcost << endl;
		write << "total cost:  " << totalcost << endl;
		write << "5rs stamp sold are: " << stamp5 << endl;
		write << "10rs stamps sold are : " << stamp10 << endl;
		write << "20rs stamps sold are : " << stamp20 << endl;
		write << "50rs stamps sold are : " << stamp50 << endl;
		write << "100rs stamps sold are : " << stamp100 << endl;

		write.close();

		cout << "Parcel successfully registered : " << endl;
		cout << "your total cost is : " << totalcost << endl;

		*/


	}

	//function to get total value 
	double gettotal2() {
		return totalcost;

	}



};



class Order {
protected:
	int Orderno;

	//Composition done to deduce new order
	Invoice I;
	string add;
	Address a;
	int parceltype;
	Customer C;
	string add1;



public:
	Order() {

	}
	void newOrder() {
		//user input for new order
		cout << "kindly provide following information for new parcel sending: " << endl;
		cout << "kindly enter sender name : " << endl;
		cin >> C.sendername;
		cout << "kindly input receiver name: " << endl;
		cin >> C.receivername;
		cout << "kindly input weight of the parcel in KG if to be sent through regular service and in Grams if to be sent through urgent service " << endl;
		cin >> C.weightparcel;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly input sender city : " << endl;
		cin >> C.sendercity;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly input receiver city : " << endl;
		cin >> C.receivercity;
		cout << "kindly input sender address :" << endl;
		getline(cin, add);
		a.setsenderaddress(add);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly input receiver address : " << endl;
		getline(cin, add);
		a.setreceiveraddress(add1);
		cout << "input sender number : " << endl;
		cin >> C.sendercontact;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "input receiver contact number :" << endl;
		cin >> C.receivercontact;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly input 1 if parcel to be sent through urgent service or input 2 if parcel to be sent through normal service " << endl;
		cin >> parceltype;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly enter monetary value of parcel :" << endl;
		cin >> C.parcelvalue;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "parcel succesfully registered : " << endl;
		srand((unsigned)time(0));
		int result = 100 + (rand() % 1000);
		cout << "your parcel id is : " << result << endl;

		//sorting of mails based on city
		if (C.receivercity == "karachi" || C.receivercity == "Karachi") {
			ofstream write;
			write.open("karachisort.dat", ios::app);
			write << "parcel id: " << result << endl;
			write << "status: parcel sent from postal office to destination:  " << endl;
			write << "sender contact: " << C.sendercontact << endl;
			write << "receiver contact: " << C.receivercontact << endl;
			write << "-----" << endl;
			write.close();

		}
		else if (C.receivercity == "islamabad" || C.receivercity == "Islamabad") {
			ofstream write;
			write.open("islamabadsort.dat", ios::app);
			write << "parcel id: " << result << endl;
			write << "status: parcel sent from postal office to destination:  " << endl;
			write << "sender contact: " << C.sendercontact << endl;
			write << "receiver contact: " << C.receivercontact << endl;
			write << "-----" << endl;
			write.close();

		}
		else if (C.receivercity == "lahore" || C.receivercity == "Lahore") {
			ofstream write;
			write.open("lahoresort.dat", ios::app);

			write << "parcel id: " << result << endl;
			write << "status: parcel sent from postal office to destination:  " << endl;
			write << "sender contact: " << C.sendercontact << endl;
			write << "receiver contact: " << C.receivercontact << endl;
			write << "-----" << endl;
			write.close();

		}




		//going to other classes for order generattion depending upon the type of mail
		if (parceltype == 1) {
			UrgentMailService U(C.weightparcel, C.sendercity, C.receivercity, C.parcelvalue);
		}
		if (parceltype == 2) {
			RegularMailService R(C.weightparcel, C.sendercity, C.receivercity, C.parcelvalue);
		}






	}

};



class stamp {


public:
	void issueticket();
};

static double tota;

class admin :public UrgentMailService, public RegularMailService
{
protected:


public:
	admin() :UrgentMailService(), RegularMailService()
	{
		tota = 0;
		adminsign();

	}
	//friend function declare to calculate the total stamps generated
	friend void gettotal();
	friend void gettotal2();
	void valtot() {
		tota = gettotal() + gettotal2();
		cout << "the total sale done today is : " << tota;
	}

	// fucntion to view the monetary details of today
	void viewreports() {
		string line;
		cout << "in urgent category : " << endl;
		//reading details from file
		ifstream read;
		read.open("urgentstamps.dat");
		while (!read.eof()) {
			getline(read, line);
			cout << line << endl;

		}

		read.close();
		cout << endl;
		cout << endl;
		cout << "in regular category: " << endl;
		ifstream rea;
		rea.open("regularstamps.dat");
		while (!rea.eof()) {
			getline(rea, line);
			cout << line << endl;
		}
		rea.close();
		cout << endl;
		cout << endl;
		valtot();



	}

	//admin menu function for various admin previliges
	void adminmenu() {
		int choicee = 0;
		cout << "welcome admin : " << endl;
		cout << "press 1 to view reports :" << endl;
		cout << "press 2 to view postal workers : " << endl;
		cout << "press 3 to change status of parcel : " << endl;
		cin >> choicee;
		if (choicee == 1) {
			viewreports();
		}
		else if (choicee == 2) {
			string line;
			ifstream read;
			read.open("postalworkers.dat");

			while (!read.eof()) {
				getline(read, line);
				cout << line << endl;


			}


			read.close();

		}
		else if (choicee == 3) {
			string dest;
			string line;

			int pid;
			string status;
			int sent = 0;
			string s;
			string line1;
			string line2;
			string line3;
			string line4;
			cout << "enter destination city : " << endl;
			cin >> dest;
			//changing status based on city and parcel id 
			if (dest == "karachi") {
				cout << "input parcel id : " << endl;
				cin >> pid;
				string temp1 = to_string(pid);
				srand((unsigned)time(0));
				int result = 1 + (rand() % 2);
				int time = 1 + (rand() % 12);
				if (result == 1) {
					s = "status: received by the receiver";
				}
				else if (result == 2) {
					s = "status: sent one time to sender but not received ";
					int again = 1 + (rand() % 2);
					if (again == 2) {
						s = "status: shipment sent two times but not receied by the receiver ";
					}
					else if (again == 1) {
						s = "status: shipment received by the receiver at seccond attempt ";
					}
				}
				temp1 = "parcel id: " + temp1;

				//creation of temp file and then removing the contents from original file line by line
				ifstream read;
				read.open("karachisort.dat");

				ofstream write;
				write.open("temp.dat");

				cin.ignore(numeric_limits<streamsize>::max(), '\n');




				while (!read.eof()) {
					getline(read, line);
					if (line == temp1) {
						while (line != "-----") {
							getline(read, line);


							// cout << "line: " << line << endl;
						}
						if (line == "-----") {
							getline(read, line);
						}
					}
					// cout << "writing line: " << line << endl;
					write << line << endl;


					write << temp1 << endl;
					write << s << endl;
					write << "sender contact: 033121" << endl;
					write << "receiver contact: 031212" << endl;
					write << "-----" << endl;


					read.close();
					write.close();

					remove("karachisort.dat");
					rename("temp.dat", "karachisort.dat");

					cout << endl << "\t\t\t\t\t" << "status successfully changed : " << endl;
					cout << endl;


				}



			}
			//changing status based on city and parcel id 

			else if (dest == "lahore" || dest == "Lahore") {

				cout << "input parcel id : " << endl;
				cin >> pid;
				string temp1 = to_string(pid);
				srand((unsigned)time(0));
				int result = 1 + (rand() % 2);
				int time = 1 + (rand() % 12);
				if (result == 1) {
					s = "status: received by the receiver";
				}
				else if (result == 2) {
					s = "status: sent one time to sender but not received ";
					int again = 1 + (rand() % 2);
					if (again == 2) {
						s = "status: shipment sent two times but not receied by the receiver ";
					}
					else if (again == 1) {
						s = "status: shipment received by the receiver at seccond attempt ";
					}
				}
				temp1 = "parcel id: " + temp1;

				ifstream read;
				read.open("lahoresort.dat");

				ofstream write;
				write.open("temp.dat");

				cin.ignore(numeric_limits<streamsize>::max(), '\n');




				while (!read.eof()) {
					getline(read, line);
					if (line == temp1) {
						while (line != "-----") {
							getline(read, line);


							// cout << "line: " << line << endl;
						}
						if (line == "-----") {
							getline(read, line);
						}
					}
					// cout << "writing line: " << line << endl;
					write << line << endl;


					write << temp1 << endl;
					write << s << endl;
					write << "sender contact: 033121" << endl;
					write << "receiver contact: 031212" << endl;
					write << "-----" << endl;


					read.close();
					write.close();

					remove("lahoresort.dat");
					rename("temp.dat", "lahoresort.dat");

					cout << endl << "\t\t\t\t\t" << "status successfully changed : " << endl;
					cout << endl;


				}


			}




			//changing status based on city and parcel id 

			else if (dest == "islamabad" || dest == "Islamabad") {
				cout << "input parcel id : " << endl;
				cin >> pid;
				string temp1 = to_string(pid);
				srand((unsigned)time(0));
				int result = 1 + (rand() % 2);
				int time = 1 + (rand() % 12);
				if (result == 1) {
					s = "status: received by the receiver";
				}
				else if (result == 2) {
					s = "status: sent one time to sender but not received ";
					int again = 1 + (rand() % 2);
					if (again == 2) {
						s = "status: shipment sent two times but not receied by the receiver ";
					}
					else if (again == 1) {
						s = "status: shipment received by the receiver at seccond attempt ";
					}
				}
				temp1 = "parcel id: " + temp1;

				ifstream read;
				read.open("islamabadsort.dat");

				ofstream write;
				write.open("temp.dat");

				cin.ignore(numeric_limits<streamsize>::max(), '\n');




				while (!read.eof()) {
					getline(read, line);
					if (line == temp1) {
						while (line != "-----") {
							getline(read, line);


							// cout << "line: " << line << endl;
						}
						if (line == "-----") {
							getline(read, line);
						}
					}
					// cout << "writing line: " << line << endl;
					write << line << endl;


					write << temp1 << endl;
					write << s << endl;
					write << "sender contact: 033121" << endl;
					write << "receiver contact: 031212" << endl;
					write << "-----" << endl;


					read.close();
					write.close();

					remove("islamabadsort.dat");
					rename("temp.dat", "islamabadsort.dat");

					cout << endl << "\t\t\t\t\t" << "status successfully changed : " << endl;
					cout << endl;


				}



			}
		}


	}
	void adminsign() {
		string line;
		string usercheck;
		string passcheck;

		cout << "kindly input your name : " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(cin, usercheck);
		cout << "kindly input you password : " << endl;
		cin >> passcheck;

		usercheck = "name: " + usercheck;
		passcheck = "password: " + passcheck;

		ifstream read;
		read.open("admin.dat");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!read.eof()) {
			getline(read, line);

			if (line == usercheck) {
				getline(read, line);
				getline(read, line);
				cout << line << endl;
				if (line == passcheck) {
					cout << "Login Successful" << endl;
					adminmenu();

					return;
				}
				else {
					cout << "Password does not match" << endl;
					return;
				}
			}
		}
		read.close();


	}

};

class User
{
protected:
	string username;
	string u_name;
	string email;
	string password;
	int cnic;

public:
	User() {

	}

	//function to signup new user
	void singup() {
		ofstream write;
		//writing data to file for better saving purpose
		write.open("Customer.dat", ios::app);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		if (write) {
			cout << "Kindly input your name";
			getline(cin, username);
			cout << "kindly input your email id " << endl;
			getline(cin, email);
			cout << "kindly input password:" << endl;
			getline(cin, password);
			cout << "kindly input your cnic number: " << endl;
			cin >> cnic;
			cout << "signup succesfull: " << endl;





		}
		write << "Name: " << username << endl;
		write << "email ID: " << email << endl;
		write << "Password: " << password << endl;
		write << "CNIC: " << cnic << endl;


		write.close();

	}

	//singup function for existing user
	void signin() {
		string line;
		string usercheck;
		string passcheck;
		cout << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "welcome to sign in menu: " << endl;
		cout << "kindly input your name " << endl;
		cin >> username;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "kindly input your password : " << endl;
		cin >> password;
		usercheck = "Name: " + username;
		passcheck = "Password: " + password;
		//reading details from file and confirming password
		ifstream read;
		read.open("Customer.dat");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		while (!read.eof()) {

			getline(read, line);

			if (line == usercheck) {
				getline(read, line);


				getline(read, line);

				if (line == passcheck) {
					cout << endl;
					int choice1 = 0;
					cout << "Login Successful" << endl;
					cout << "please enter 1 for new parcel to be sent : " << endl;
					cout << "please enter 2 to view parcel details : " << endl;
					cout << "please enter 3 to go to main menu : " << endl;
					cin >> choice1;
					if (choice1 == 1) {
						Order n;
						n.newOrder();
					}
					else if (choice1 == 2) {

					}

					return;
				}
				else {
					cout << "Password does not match" << endl;

					return;
				}
			}
		}
		read.close();

	}





};












//class SortingSection{
//	protected:
//		string city;
//		
//		public:
//			sorting(string city){
//				open.write()
//				if (city=="karachi"){
//					
//				}
//				
//				if (city=="lahore"){
//					
//				}
//				
//				if (city=="islamabad"){
//					
//				}
//			}
//		
//	
//};




class BouncedMails {
protected:

public:

};

class ReturnedMails {
protected:

public:

};

class Mails : public BouncedMails, public ReturnedMails
{


public:


};



class Menu {
protected:
	int choice;


public:
	Menu() {
	}
	//function to display the initial menu on console
	void newMenu(int choice) {
		this->choice = choice;

		//functionality based on user input from int main
		if (choice == 1) {
			User a;
			a.signin();
		}
		else if (choice == 2) {
			User a;
			a.singup();
		}
		else if (choice == 3) {
			admin a;

		}
		else if (choice == 4) {
			GPO j;
			j.GPOadmin();

		}
		else if (choice == 5) {
			static int c;

			return;
		}


	}


	//	public:	
	//	void menu(int choice){
	//		switch (choice){
	//			case 1:
	//		}
	//	}
};









#endif
