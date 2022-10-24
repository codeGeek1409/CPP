#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<exception>
using namespace std;

/**
 * @brief: displays dynamics of landlords networth over time
 * @author: Lalatendu
 * @todo: define landlord, tenant, randomize input, display 
 * data in months interval
*/
class Landlord{
	const char *name;
	int rooms;// scope for data struct
	double maintenance;
	double rent_rcvbl;
	double rent_inc;
	int experience;
	int occupancy;
	double elect_bill;
	int increment_rate;
	public:
	friend class Tenant;
	Landlord(const char* s):name(s){
		cout << name << " is in business.\n";
	};
};
class Tenant{
	const char* name;
	int room_no;
	double rent;
	double elect;
	int occupants;
	double rent_payable;
	double arrears;
	public:
	Tenant(const char* s):name(s){
	};
	void pay(); // scope for overloading
};
int main(int argc, char*argv[]){
	int i=0;
	while(i++<5) cout << '*';
	cout << "BOOKS OF LALA SETH"; i=0;
	while(i++<5) cout << '*'; cout << endl;
	new Landlord("Lala");
	new Tenant("dobu");
	return 0;
}