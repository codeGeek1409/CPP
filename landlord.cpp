#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<exception>
#include<vector>
using namespace std;

/**
 * @brief: displays dynamics of landlords networth over time
 * @author: Lalatendu
 * @todo: define landlord, tenant, randomize input, display
 * data in months interval
*/
class Landlord;
class Tenants {
	friend class Landlord;
	const char* name;
	int roommates, roomNo;
	double arrears, rent, advance;
	void pay();
	void vaccate();
	void rent_review();
};
class Date {
	short day, month, year;
public:
	Date() { day = 1; month = 1; year = 2022; };
	void print_date() {
		switch (month) {
		case 1:
			cout << "Jan";break;
		case 2:
			cout << "Feb";break;
		case 3:
			cout << "Mar";break;
		case 4:
			cout << "Apr";break;
		case 5:
			cout << "May";break;
		case 6:
			cout << "Jun";break;
		case 7:
			cout << "Jul";break;
		case 8:
			cout << "Aug";break;
		case 9:
			cout << "Sep";break;
		case 10:
			cout << "Oct";break;
		case 11:
			cout << "Nov";break;
		case 12:
			cout << "Dec";break;
		default:
			cout << "error occured.";
		}
		cout << ", " << year << endl;
	}
	void pass_month() {
		if (month <= 12) month++;
		else { month = 1;year++; }
	}
};
class Landlord {
	vector<int> rooms;
	int headcount;
	vector<Tenants> _register;
	Date date;
	double waterbill, electbill, taxes, maintenance, baddebts;
	double dues;
	int occupants, experience;
	const char* name;
	double rent_rd, rent_rcvbl, advances, hike_rate;
	void pay_dues(){
		int luck=rand() % 100;
		if(luck<10) {
			float ratio=0.5;
			rent_rd-=(waterbill*ratio+electbill*ratio+taxes*ratio+maintenance*ratio);
			dues+=(waterbill*(1-ratio)+electbill*(1-ratio)+taxes*(1-ratio)+maintenance*(1-ratio));
			waterbill=electbill=taxes=maintenance=0;
		}else if(luck < 50){
			float ratio=0.25;
			rent_rd-=(waterbill*ratio+electbill*ratio+taxes*ratio+maintenance*ratio);
			dues+=(waterbill*(1-ratio)+electbill*(1-ratio)+taxes*(1-ratio)+maintenance*(1-ratio));
			waterbill=electbill=taxes=maintenance=0;
		}else{
			float ratio=0.1;
			rent_rd-=(waterbill*ratio+electbill*ratio+taxes*ratio+maintenance*ratio);
			dues+=(waterbill*(1-ratio)+electbill*(1-ratio)+taxes*(1-ratio)+maintenance*(1-ratio));
			waterbill=electbill=taxes=maintenance=0;
		}
	};
	void collect_rent(){
		for(int i=0;i<_register.size();i++) {
			int luck=rand()%500;
			if(luck % 12 == 0)
			rent_rd+=_register[i].rent;
			else if(luck % 8 == 0) {
				rent_rd+=_register[i].rent*0.85;
				rent_rcvbl+=_register[i].rent*0.15;
				_register[i].arrears=_register[i].rent*0.15;
			}else if(luck % 11== 0) {
				_register[i].advance=_register[i].rent*3;
				advances=_register[i].advance;
				rent_rd+=_register[i].rent*0.5;
				rent_rcvbl+=_register[i].rent*0.5;
				_register[i].arrears=_register[i].rent*0.5;
			}
			else {
				rent_rd+=_register[i].rent*0.9;
				rent_rcvbl+=_register[i].rent*0.1;
				_register[i].arrears=_register[i].rent*0.1;
			}
		}
	}
	void kick_tenant(int room);
public:
	Landlord(const char* s = "unknown"):name(s) {
		cout << "New landlord: " << name << endl;
		headcount = waterbill = electbill = taxes = maintenance = baddebts = dues =
			occupants = experience = rent_rcvbl = rent_rd = advances = hike_rate = 0;
		for(int i=0;i<=rand()%500;i++) rooms.push_back(rand()%5 * 100 + i);
	};
	void print_stat() {
		cout << "***** " << "Books of " << name << " *****\n  FOR THE MONTH ";
		date.print_date();
		cout << endl;
		cout << "****  OCCUPANCY  ****" << endl;
		cout << "Rooms: " << occupants << '/'<< rooms.size() << "\tHeadcount: " << headcount << endl;
		cout << "Names: ";
		for(int i=0; i<_register.size();i++) {
			if(i%5==0 && i>0) cout << endl;
			cout << _register[i].name << '(' << _register[i].roomNo << ") ";
		}
		cout << endl << endl;

		cout << "****  EXPENSES  ****" << endl;
		cout << "Electric Bill: " << electbill << "\tWater bill: " << waterbill << endl;
		cout << "Maintenance: " << maintenance << "\tBad Debts: " << baddebts << "\tArrears: " << dues << endl << endl;

		cout << "****  INCOME  ****" << endl;
		cout << "Rent Received: " << rent_rd << "\tRent Receivable: " << rent_rcvbl << endl;
		cout << "Profit YTD: ";
		if (rent_rd + rent_rcvbl != 0)
			cout <<  (rent_rd + rent_rcvbl - electbill + waterbill + maintenance + baddebts) /
			(rent_rcvbl + rent_rd) * 100 << endl;
		else cout << 0 << endl;
		cout << endl << endl;
	};
	void fast_forward() {
		experience++;
		date.pass_month();
		waterbill=rand()%500 * occupants;
		electbill=rand()%300 * occupants;
		taxes=rand() % 100 * occupants;
		maintenance=rand() % 200 * occupants;
		baddebts=(rent_rcvbl > 1000) ? rand()%100:0;
		if(!baddebts) rent_rcvbl-=baddebts;
		collect_rent();
		print_stat();
		pay_dues();
		// print_stat();
	};
	void add_tenant(const char* name) {
		Tenants o;
		o.name = name;
		o.roommates = (rand() % 5);
		o.arrears = o.rent = o.advance = 0;
		o.rent = rand() % 10 * 1000;
		headcount += o.roommates;
		o.roomNo = rooms[occupants];
		_register.push_back(o);
		occupants++;
	};
};
int main() {
	Landlord lala = "Lala";
	lala.add_tenant("Papu");
	lala.add_tenant("Sibu");
	lala.print_stat();
	lala.fast_forward();
	lala.add_tenant("Kalu");
	lala.add_tenant("Jignesh");
	lala.fast_forward();
	lala.add_tenant("Pintu");
	lala.fast_forward();
	lala.add_tenant("Papdu");
	lala.add_tenant("Sibdu");
	lala.print_stat();
	lala.fast_forward();
	lala.add_tenant("Papu");
	lala.add_tenant("Sibu");
	lala.add_tenant("Papu");
	lala.add_tenant("Sibu");
	lala.add_tenant("Papu");
	lala.add_tenant("Sibu");
	lala.fast_forward();
	return 0;
}