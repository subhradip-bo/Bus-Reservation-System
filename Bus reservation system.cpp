#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Call_Class
{
	public:
		string date, rv[100][100];
		int s;
		long tik[100];
		void intro();
		void choose(long t[100], string res[100][100], int size);
		void call(int ch);
};

class Accept_Info
{
	public:
		void accept(int s, string dt);
};

class Passenger
{
  public:
    int age;
    long num;
    string nm, sex, mail;
};

class Bill
{
  private:
    double tt;
  protected:
    double amount;
	public:
		Bill()
		{
			tt = 0.0;
			amount = 0.0;
			double &ref = amount;
		}
		~Bill()
		{
		}
};

class Ticket: public Passenger, public Bill
{
  public:
    long ticket[100];
    string date, tm;
};

class Destination: public Ticket
{
  public:
    string dest, bus, dur;
};

class Payment
{
  public:
    string bankName[5] = {"HDFC Bank","ICICI Bank","State Bank of India","Axis Bank","Bank of Baroda"};
    string cardType[2] = {"Credit Card","Debit Card"};
    void makePayment();
    int& countDigit(long& no);
};

class Show_Ticket
{
  public:
    void showInfo(long t[100], string r[100][100], int size);
};

class Reservation:public Destination
{
  public:
    int s, ch;
    double total;
    Payment py;
    Call_Class cc;
    Show_Ticket st;
    string reserve[100][100];
    Reservation(int x, string dt);
    void A1();
    void B2();
    void B3();
    void C4();
    void C5();
    void D6();
    void D7();
    void K8();
    void P9();
    void S10();
    void accept(int f);
    void TicketInfo();
};

class Cancellation
{
  public:
    void take(long t[100], string r[100][100], int size);
    void cancel(long no, int i, long tk[100], string res[100][100], int size);
};

class Know_BO
{
  public:
    void show(long t[100], string r[100][100]);
};

class Know_YB
{
  public:
    void info(long (&t)[100], string (&r)[100][100]);
};

class Date
{
	private:
		int* ptr;
		Date()
		{
			ptr = new int;
			*ptr = 0;
		}
		Date(const Date &d)
		{
			ptr = new int;
			*ptr = *d.ptr;
		}
		friend class Call_Class;
		friend void Reservation::TicketInfo();
		friend class Payment;
	public:
		bool check(string dt)
		{
			Ticket tt[9];
			if((stoi(dt.substr(3, 4)) == 1 || stoi(dt.substr(3, 4)) == 3 || stoi(dt.substr(3, 4)) == 5 || stoi(dt.substr(3, 4)) == 7 || stoi(dt.substr(3, 4)) == 8 || stoi(dt.substr(3, 4)) == 10 || stoi(dt.substr(3, 4)) == 12) && stoi(dt.substr(0, 2)) > 31)
				return false;
			if((stoi(dt.substr(3, 4)) == 4 || stoi(dt.substr(3, 4)) == 6 || stoi(dt.substr(3, 4)) == 9 || stoi(dt.substr(3, 4)) == 11) && stoi(dt.substr(0, 2)) > 31)
				return false;
			if(stoi(dt.substr(3, 4)) == 2 && (stoi(dt.substr(6, 9)) % 4) == 0 && stoi(dt.substr(0, 2)) > 29)
				return false;
			if(stoi(dt.substr(3, 4)) == 2 && (stoi(dt.substr(6, 9)) % 4) != 0 && stoi(dt.substr(0, 2)) > 28)
				return false;
			if(stoi(dt.substr(3, 4)) > 12)
				return false;
			if(stoi(dt.substr(6, 9)) < 2022)
				return false;
			if(dt.substr(6, 9) == "2022" && stoi(dt.substr(3, 4)) < 4)
				return false;
			if(dt.substr(6, 9) == "2022" && stoi(dt.substr(3, 4)) == 4 && stoi(dt.substr(0, 2)) <= 24)
				return false;
			return true;
		}
};

void Call_Class::intro()
//Method to show the welcoming grretings to the user
{
		cout << "Made By: Tishyo Saha, Subhradip Bodhak" << endl << endl;
    cout << "Welcome to YellowBus! Kolkata's no. 1 and most trusted bus reservation site! Travel esily to any part of West Bengal." << endl;
    cout << "Using YellowBus for first time? Use code FIRST to get an extra discount of 50% !!" << endl;
    //Calling choose(long, String)
    choose(tik, rv, 0);
}

void Call_Class::choose(long t[100], string res[100][100], int size)
//Method to get user's choice
{
		s = size;
		cout << endl;
    copy(&res[0][0], &res[0][0]+100*100, &rv[0][0]);
    copy(t, t+100, tik);
    cout << "What do you want to do?" << endl;
    cout << endl;
    cout << "1. Reserve seats..." << endl;
    cout << "2. Check Ticket details..." << endl;
    cout << "3. Cancel your seats..." << endl;
    cout << "4. Know your bus operator..." << endl;
    cout << "5. Know more about YellowBus..." << endl;
    cout << "0. Exit..." << endl;
    cout << endl;
    cout << "Enter your choice please: ";
    int c;
    cin >> c;
    cout << endl;
    bool valid = false;
    if(c == 1)
    {
				Date* dt = new Date();
        cout << "Please enter the number of seats you want to book: ";
        cin >> s;
        cout << "Please enter the date of your journey(dd/mm/yyyy): ";
				do
				{
        		cin >> date;
						if(dt->check(date) == false)
							cout << "Invalid input, try again: ";
				}
				while(dt->check(date) == false);
    }
    //Calling call(int)
    call(c);
}

void Call_Class::call(int ch)
//Method to call methods according to user's choice
{
    //Creating object of Accept_Info, Know_BO, Know_YB, Reservation, Show_Ticket and Cancellation classes
    Accept_Info ai;
    Know_BO kb;
    Know_YB ky;
    Reservation rs(s, date);
    Show_Ticket st;
    Cancellation cn;
    switch(ch)
    {
        case 1:
        //Calling accept(long, String) of Accept_Info class
        ai.accept(s, date);
        break;
        case 2:
        //Calling showInfo(long, String) of Show_Ticket class
        Show_Ticket st2;
        st2.showInfo(tik, rv, s);
        break;
        case 3:
        //Calling take(long, String) of Cancellation class
        cn.take(tik, rv, s);
        break;
        case 4:
        //Calling show(long, String) of Know_BO class
        kb.show(tik, rv);
        break;
        case 5:
        //Calling info(long, String) of Know_YB class
        ky.info(tik, rv);
        break;
        case 0:
        //Exiting from the program
        exit(0);
        break;
        default:
        cout << "We didn't get you, please try again!" << endl;
        //Calling choose(long, String)
        choose(tik, rv, s);
    }
}

void Accept_Info::accept(int s, string dt)
{
    cout << endl;
    cout << "Showing available destinations:" << endl;
    cout << endl;
    cout << "1.  Asansol" << endl;
    cout << "2.  Bakkhali" << endl;
    cout << "3.  Bankura" << endl;
    cout << "4.  Chandipur" << endl;
    cout << "5.  Chittaranjan" << endl;
    cout << "6.  Digha" << endl;
    cout << "7.  Durgapur" << endl;
    cout << "8.  Krishnanagar" << endl;
    cout << "9.  Purulia" << endl;
    cout << "10. Siliguri" << endl;
    cout << endl;
    cout << "Can't find your destination on the list? Click 0 and hit enter to exit. Come back in a day or two and we hope you'll find your place on the list!!" << endl;
    cout << "Please select your destination and enter your choice below: ";
    int ch;
    cin >> ch;
    cout << endl;
    //Creating object of Reservation class
    Reservation rv(s, dt);
    switch(ch)
    {
        case 1:
        //Calling A1() of Reservation class
        rv.A1();
        break;
        case 2:
        //Calling B2() of Reservation class
        rv.B2();
        break;
        case 3:
        //Calling B3() of Reservation class
        rv.B3();
        break;
        case 4:
        //Calling C4() of Reservation class
        rv.C4();
        break;
        case 5:
        //Calling C5() of Reservation class
        rv.C5();
        break;
        case 6:
        //Calling D6() of Reservation class
        rv.D6();
        break;
        case 7:
        //Calling D7() of Reservation class
        rv.D7();
        break;
        case 8:
        //Calling K8() of Reservation class
        rv.K8();
        break;
        case 9:
        //Calling P9() of Reservation class
        rv.P9();
        break;
        case 10:
        //Calling S10() of Reservation class
        rv.S10();
        break;
        case 0:
        //Exiting from the program
        exit(0);
        break;
        default:
        cout << "Invalid Input, please try again!" << endl;
        //Calling accept(int, String)
        accept(s, dt);
    }
}

Reservation::Reservation(int x, string dt)
{
    s = x;
    ch = num = 0;
    date = dt;
}
void Reservation::A1()
{
    string oper[] = {"SBSTC", "Greenline", "Shyamoli Paribahan"};
    double rate[] = {3.8, 4.6, 4.3};
    string depart[] = {"15:30", "18:10", "19:20"};
    int seat[] = {7, 16, 15};
    int fare[] = {185, 425, 420};
    string type[] = {"Non-A/C", "A/C", "A/C"};
    dest = "Asansol";
    dur = "3.5 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            A1();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        A1();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::B2()
{
    cout << "Oops! Looks like there are no trips available on the day! Check again later!" << endl;
}
void Reservation::B3()
{
    string oper[] = {"SBSTC", "Arya Travels"};
    double rate[] = {1.9, 4.8};
    string depart[] = {"16:35", "16:15"};
    int seat[] = {49, 19};
    int fare[] = {195, 400};
    string type[] = {"Non-A/C", "A/C"};
    dest = "Bankura";
    dur = "4.0 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            B3();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        B3();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::C4()
{
    string oper[] = {"SBSTC", "SBSTC", "Shyamoli Paribahan"};
    double rate[] = {3.5, 3.2, 4.0};
    string depart[] = {"09:00", "12:00", "07:20"};
    int seat[] = {27, 20, 15};
    int fare[] = {96, 100, 355};
    string type[] = {"Non-A/C", "Non-A/C", "A/C"};
    dest = "Chandipur";
    dur = "6.75 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            C4();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        C4();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::C5()
{
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    cout << "1. Shyamoli Paribahan " << " 4.5  " << "   23:00   " << "  14   " << " 130  " << "    A/C" << endl;
    if(s > 14)
    {
        cout << endl;
        cout << "No operators have adequate seats. We are exiting you. Come again after a day or two and we hope you will get the no. of seats you require!!" << endl;
        cout << "Hit 0 to exit!" << endl;
        int z;
        cin >> z;
        exit(0);
    }
    else
    {
        cout << endl;
        cout << "Enter your choice(Hit 0 to exit): ";
        do
        //Checking if choice of bus operator is valid
        {
            cin >> ch;
            if(ch != 1 && ch != 0)
            {
                cout << endl;
                cout << "Invalid choice, please try again!!" << endl;
                C5();
            }
            if(ch == 0)
                exit(0);
        }
        while(ch != 1 && ch != 0);
        cout << endl;
        bus = "Shyamoli Paribahan";
        tm = "23:00";
        dest = "Chittaranjan";
        dur = "4.5 hrs.";
        accept(130);
    }
}
void Reservation::D6()
{
    string oper[] = {"WBTC", "Parameswar Travels", "Snemita Paribahan"};
    double rate[] = {4.0, 3.6, 3.5};
    string depart[] = {"15:15", "23:45", "23:20"};
    int seat[] = {28, 31, 15};
    int fare[] = {145, 300, 400};
    string type[] = {"Non-A/C", "A/C", "A/C"};
    dest = "Digha";
    dur = "5.5 hrs";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            D6();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        D6();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::D7()
{
    string oper[] = {"SBSTC", "SBSTC"};
    double rate[] = {4.6, 4.0};
    string depart[] = {"16:00", "18:00"};
    int seat[] = {25, 35};
    int fare[] = {155, 150};
    string type[] = {"Non-A/C", "Non-A/C"};
    dest = "Durgapur";
    dur = "4.0 hrs";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            D7();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        D7();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::K8()
{
    string oper[] = {"WBTC", "Shyamoli Paribahan"};
    double rate[] = {3.8, 3.0};
    string depart[] = {"17:00", "07:00"};
    int seat[] = {30, 41};
    int fare[] = {210, 270};
    string type[] = {"A/C", "A/C"};
    dest = "Krishnanagar";
    dur = "2.5 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            K8();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        K8();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::P9()
{
    string oper[] = {"WBTC", "SBSTC"};
    double rate[] = {3.8, 3.3};
    string depart[] = {"15:00", "03:00"};
    int seat[] = {35, 41};
    int fare[] = {595, 250};
    string type[] = {"A/C", "Non-A/C"};
    dest = "Purulia";
    dur = "7.5 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            P9();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        P9();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::S10()
{
    string oper[] = {"Poulomi Paribahan", "Aitiama Airwing", "Night Queen"};
    double rate[] = {4.3, 4.0, 3.9};
    string depart[] = {"18:45", "18:45", "18:00"};
    int seat[] = {2, 8, 2};
    int fare[] = {1050, 1200, 1000};
    string type[] = {"A/C", "A/C", "A/C"};
    dest = "Siliguri";
    dur = "11.5 hrs.";
    cout << "   Operator           " << " Rate " << " Departure " << " Seats " << " Fare " << "   Type " << endl;
    int len = sizeof(oper)/sizeof(oper[0]);
    for(int i = 0; i < len; i++)
    //Displaying the list of details
    {
        cout << (i + 1) << ". " << oper[i];
        for(int j = 1; j <= 19 - oper[i].size(); j++)
            cout << " ";
        cout << " " << rate[i] << " " << "    " << depart[i] << "  " << "    " << seat[i] << "  " << "  " << fare[i] << "    " << type[i];
        cout << endl;
    }
    cout << endl;
    cout << "Please enter your choice below(Hit 0 to exit): ";
    do
    //Checking if choice of bus operator is valid
    {
        cin >> ch;
        if(ch < 0 || ch > len)
        {
            cout << endl;
            cout << "Invalid choice, please try again!!" << endl;
            S10();
        }
        if(ch == 0)
            exit(0);
    }
    while(ch < 0 || ch > len);
    cout << endl;
    if(s > seat[ch - 1])
    {
        cout << "You need more seats than available. Please try another operator" << endl;
        cout << endl;
        S10();
    }
    bus = oper[ch - 1];
    tm = depart[ch - 1];
    accept(fare[ch - 1]);
}
void Reservation::accept(int f)
{
    for(int i = 0; i < s; i++)
    {
        int fr = f;
        cout << "Please type the of name passenger " << (i + 1) << ": ";
        cin >> nm;
        cout << "Please type sex(M/F) of passenger " << (i + 1) << ": ";
        do
        //Checking if choice of sex is valid
        {
            cin >> sex;
            if(!(sex == "M" || sex == "F"))
                cout << "Invalid input, please type again: ";
        }
        while(!(sex == "M" || sex == "F"));
        cout << "Enter age of passenger: ";
        cin >> age;
        cout << endl;
        if(age < 12)
            fr = fr / 2;
        total = total + fr;
        reserve[i][0] = nm;
        reserve[i][1] = to_string(age);
        reserve[i][2] = dest;
        reserve[i][3] = date;
        reserve[i][4] = tm;
        reserve[i][5] = dur;
        reserve[i][6] = bus;
        reserve[i][7] = sex;
        reserve[i][8] = (to_string(rand() % 52 + 1)).substr(0, 1);
        ticket[i] = i + 2000;
        cout << "Your ticket no. is: " << ticket[i] << endl;
        cout << endl;
    }
    cout << "Enter phone number: ";
    do
    //Checking if the phone no. of user entered is valid
    {
        cin >> num;
        if(num < 1000000000 || num > 9999999999)
        {
            cout << endl;
            cout << "Invalid phone number, please enter again: ";
        }
    }
    while(num < 1000000000 || num > 9999999999);
    cout << "Enter email id: ";
		cin.clear();
		do
    //Checking if the email id of user entered is valid
    {
				cin >> mail;
        if(!(mail.ends_with("@gmail.com") || mail.ends_with("@yahoo.com") || mail.ends_with("@rediff.com") || mail.ends_with("@outlook.com") || mail.ends_with("@aol.com")))
            cout << "Invalid input, please try again: ";
    }
    while(!(mail.ends_with("@gmail.com") || mail.ends_with("@yahoo.com") || mail.ends_with("@rediff.com") || mail.ends_with("@outlook.com") || mail.ends_with("@aol.com")));
		cout << endl;
    cout << "Got a code? Apply it to get extra discount!!" << endl;
    cout << "Enter your code(Hit enter to proceed): ";
    string code;
		cin.clear();
    cin >> code;
    if(!(code == "FIRST"))
        cout << "Invalid code!! Proceeding to payment!" << endl;
    cout << endl;
    cout << "Total ticket fare           : Rs. " << total << endl;
    if(code == "FIRST")
        total = total / 2;
    cout << "Fare after discount(if any) : Rs. " << total << endl;
    cout << "G.S.T.                      : Rs. " << (12.0/100.0 * total) << endl;
    //Calculating the total amount to be paid by user
    total = total + (12.0/100.0 * total);
    cout << "Amount to be paid           : Rs. " << (int)total << endl;
    py.makePayment();
    cout << "Thank you for using our YellowBus!! We hope you enjoy the journey! Don't forget to use YellowBus for your future trips :D!" << endl << endl;
    TicketInfo();
}
void Reservation::TicketInfo()
{
    cout << "Do you want to check your ticket information? (Yes/No): ";
    string c;
    cin >> c;
    if(c == "Yes")
    {
        st.showInfo(ticket, reserve, s);
    }
    else if(c == "No")
    {
        int n1;
        cout << "Do you want to go to previous menu? (Yes/No): ";
        do
        //Checking if user choice is valid
        {
            n1 = 0;
            cin >> c;
            if(c == "Yes")
            {
                cc.choose(ticket, reserve, s);
            }
            else if(c == "No")
            {
                exit(0);
            }
            else
            {
                cout << "We didn't get you, please try again!" << endl;
                n1++;
            }
        }
        while(n1 != 0);
    }
    else
    {
        cout << "We didn't get you, please try again!!" << endl;
        TicketInfo();
    }
}

void Payment::makePayment()
//Method to accept inputs and complete payment process
{
    string date;
    long cardNo, cvvNo, bank, card;
    cout << endl;
    cout << "Choose your ATM card type." << endl;
    cout << endl;
    for (int i = 0; i < 2; i++)
        cout << i+1 << ":" << cardType[i] << endl;
    cout << endl;
    do
    //Checking if card type entered is valid
    {
        cout << "Enter your card type: ";
        cin >> card;
        if(card <= 0 || card > 2)
        {
            cout << endl;
            cout << "Sorry you have given a wrong choice. Please enter your card type again";
        }
        cout << endl;
    }
    while(card <= 0 || card > 2);
    cout << "Choose your bank." << endl;
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << (i+1) << ":" << bankName[i] << endl;
    cout << endl;
    do
    //Checking if bank name entered is valid
    {
        cout << "Enter your bank name: ";
        cin >> bank;
        if (bank <= 0 || bank > 5)
        {
            cout << endl;
            cout << "Sorry you have given a wrong choice. Please enter your bank name again: ";
        }
        cout << endl;
    }
    while(bank <= 0 || bank > 5);
		Date* dt = new Date();
    cout << "Enter your 16-digit card number: ";
    cin.clear();
    cin >> cardNo;
    cout << "Enter the expiry date in dd/mm/yyyy format: ";
		cin.clear();
		do
		{
				cin >> date;
				if(dt->check(date) == false)
					cout << "Invalid input, try again: ";
		}
		while(dt->check(date) == false);
    do
    //Checking if cvv no. entered is valid
    {
        cout << "Enter the 3-digit cvv number: ";
        cin.clear();
        cin >> cvvNo;
        if (countDigit(cvvNo) != 3)
        {
            cout << endl;
            cout << "Sorry wrong input. Please try again: ";
        }
        cout << endl;
    }
    while(countDigit(cvvNo) != 3);
    cout << "Your transaction has taken place. Thank you for choosing our site." << endl;
    cout << "Your ticket details will be sent to your email id and a SMS will be sent to your mobile." << endl;
}

int& Payment::countDigit(long& no)
//Method to count no. of digits present in a given no.
{
    long x = no;
    int count = 0;
    while(x > 0)
    {
        count++;
        x /= 10;
    }
		int &c = count;
    return c;
}

void Show_Ticket::showInfo(long t[100], string r[100][100], int size)
//Method show the details
{
    cout << "For checking your ticket details enter your ticket number: ";
    long ti;
    cin >> ti;
    Call_Class cc;
    int c = 0;
    for (int i = 0; i < size; i++)
    //Showing details according to the ticket number entered
    {
        if (ti == t[i])
        {
            cout << endl;
            cout << "Ticket Number: " << t[i] << endl;
            cout << "Name         : " << r[i][0] << endl;
            cout << "Sex          : " << r[i][7] << endl;
            cout << "Age          : " << r[i][1] << endl;
            cout << "Destination  : " << r[i][2] << endl;
            cout << "Date         : " << r[i][3] << endl;
            cout << "Departure    : " << r[i][4] << endl;
            cout << "Duration     : " << r[i][5] << endl;
            cout << "Bus Operator : " << r[i][6] << endl;
            cout << "Seat No      : " << r[i][8] << endl;
            break;
        }
        c++;
    }
    if(c == size)
    {
        cout << endl;
        cout << "This ticket number does not have any reservation!" << endl;
    }
    string op; int n, n1;
    cout << endl;
    cout << "Do you want to check details of more tickets? (Yes/No): ";
    do
    //Checking if user choice is valid
    {
        n = 0;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.clear();
        getline(cin, op);
        if(op == "Yes")
        {
            showInfo(t, r, size);
        }
        else if(op == "No")
        {
            cout << "Do you want to go to previous menu? (Yes/No): ";
            do
            //Checking if user choice is valid
            {
                n1 = 0;
                //cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.clear();
                getline(cin,op);
                if(op == "Yes")
                {
                    cc.choose(t, r, size);
                }
                else if(op == "No")
                {
                    exit(0);
                }
                else
                {
                    cout << "We didn't get you, please try again!" << endl;
                    n1++;
                }
            }
            while(n1 != 0);
        }
        else
        {
            cout << endl;
            cout << "We didn't get you, please try again!" << endl;
            n++;
        }
    }
    while(n != 0);
}

void Cancellation::take(long t[100], string r[100][100], int size)
//Method to cancel reservation
{
    int c = 0;
    cout << "Enter your the number of the ticket which you want to cancel: ";
    long n;
    cin >> n;
    for(int i = 0; i < size; i++)
    //Cancelling reservation according to ticket no. entered by the user
    {
        if(t[i] == n)
        {
            t[i] = 0;
            cout << "Your reservation has been cancelled!" << endl;
            cancel(n, i, t, r, size);
        }
        else
        {
            c++;
        }
    }
    if(c == size)
    {
        int i = 0;
        cout << endl;
        cout << "There are no reservation for this ticket number." << endl;
        cancel(n, i, t, r, size);
    }
}

void Cancellation::cancel(long no, int i, long tk[100], string res[100][100], int size)
//Method to know what user wants to do next
{
    Call_Class cc;
    string op; int n, n1;
    cout << endl;
    cout << "Do you want to cancel more tickets? (Yes/No): ";
    do
    //Checking if user choice is valid
    {
        n = 0;
				//cin.clear();
        cin >> op;
        if(op == "Yes")
        {
            take(tk, res, size);
        }
        else if(op == "No")
        {
            cout << "Do you want to go to previous menu? (Yes/No): ";
            do
            //Checking if user choice is valid
            {
                n1 = 0;
								//cin.clear();
                cin >> op;
                if(op == "Yes")
                {
                    cc.choose(tk, res, size);
                }
                else if(op == "No")
                {
                    exit(0);
                }
                else
                {
                    cout << "We didn't get you, please try again!" << endl;
                    n1++;
                }
            }
            while(n1 != 0);
        }
        else
        {
            cout << endl;
            cout << "We didn't get you, please try again!" << endl;
            n++;
        }
    }
    while(n != 0);
}

void Know_BO::show(long t[100], string r[100][100])
//Displaying amenities present in each bus
{
    int n, n1;
    cout << endl;
    cout << "Choose your Bus Operator:" << endl;
    cout << endl;
    cout << "1.  West Bengal Transport Corporation(WBTC)" << endl;
    cout << "2.  South Bengal State Transport Corporation(SBSTC)" << endl;
    cout << "3.  Shyamoli Paribahan Pvt. Ltd." << endl;
    cout << "4.  Snemita Paribahan" << endl;
    cout << "5.  Night Queen" << endl;
    cout << "6.  Greenline" << endl;
    cout << "7.  Arya Travels" << endl;
    cout << "8.  Parameswar Travels" << endl;
    cout << "9.  Bijoyatra Travels" << endl;
    cout << "10. Poulomi Paribahan" << endl;
    cout << "11. Aitiama Airwing" << endl;
    cout << "0.  Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    int ch;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin >> ch;
    cout << endl;
    switch(ch)
    {
        case 1:
        cout << "Amenities:" << endl;
        cout << "1. Emergency Exit" << endl;
        break;
        case 2:
        cout << "Amenities:" << endl;
        cout << "---" << endl;
        break;
        case 3:
        cout << "Amenities:" << endl;
        cout << "1. Water Bottle" << endl;
        cout << "2. Snacks" << endl;
        cout << "3. Music/MP3" << endl;
        cout << "4. Emergency Exit" << endl;
        break;
        case 4:
        cout << "Amenities:" << endl;
        cout << "1. Wifi" << endl;
        cout << "2. Water Bottle" << endl;
        cout << "3. Charging Point" << endl;
        break;
        case 5:
        cout << "Amenities:" << endl;
        cout << "1. Water Bottle" << endl;
        cout << "2. Charging Pont" << endl;
        cout << "3. Movie" << endl;
        cout << "4. Reading Light" << endl;
        cout << "5. Emergency Exit" << endl;
        cout << "6. Central T.V." << endl;
        break;
        case 6:
        cout << "Amenities:" << endl;
        cout << "1. Wifi" << endl;
        cout << "2. Water Bottle" << endl;
        cout << "3. Charging Point" << endl;
        cout << "4. Emergency Exit" << endl;
        cout << "5. Reading Light" << endl;
        break;
        case 7:
        cout << "Amenities:" << endl;
        cout << "1. Water Bottle" << endl;
        cout << "2. Charging Point" << endl;
        cout << "3. Emergency Exit" << endl;
        break;
        case 8:
        cout << "Amenities:" << endl;
        cout << "1. Water Bottle" << endl;
        cout << "2. Snacks" << endl;
        cout << "3. Charging Point" << endl;
        cout << "4. Emergency Exit" << endl;
        break;
        case 9:
        cout << "Amenities:" << endl;
        cout << "1. Wifi" << endl;
        cout << "2. Water Bottle" << endl;
        cout << "3. Snacks" << endl;
        cout << "4. Charging Point" << endl;
        cout << "5. Music/MP3" << endl;
        cout << "6. Emergency Exit" << endl;
        break;
        case 10:
        cout << "Amenities:" << endl;
        cout << "1. Water Bottle" << endl;
        cout << "2. Emergency Exit" << endl;
        break;
        case 11:
        cout << "Amenities:" << endl;
        cout << "1. Wifi" << endl;
        cout << "2. Water Bottle" << endl;
        cout << "3. Reading Light" << endl;
        cout << "4. Emergency Exit" << endl;
        break;
        case 0:
        exit(0);
        break;
        default:
        cout << "We didn't get you, please try again!" << endl;
        show(t, r);
    }
    cout << "Do you want check details of more operators? (Yes/No): ";
    do
    //Checking if user choice is valid
    {
        n1 = 0;
        string op;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> op;
        if(op == "Yes")
        {
            show(t, r);
        }
        else if(op == "No")
        {
            cout << endl;
            cout << "Do you want to go back to previous menu? (Yes/No): ";
            do
            //Checking if user choice is valid
            {
                n = 0;
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> op;
                if(op == "Yes")
                {
                    Call_Class cc;
                    cc.choose(t, r, 0);
                }
                else if(op == "No")
                {
                    exit(0);
                }
                else
                {
                    cout << "We didn't get you, please try again!" << endl;
                    n++;
                }
            }
            while(n != 0);
        }
        else
        {
            cout << "We didn't get you, please try again!" << endl;
            n1++;
        }
    }
    while(n1 != 0);
}

void Know_YB::info(long (&t)[100], string (&r)[100][100])
//Displaying about Yellow Bus
{
    int n;
    cout << "YellowBus is Kolkata's most trusted and used bus booking site." << endl;
    cout << endl;
    cout << "Why use YellowBus?" << endl;
    cout << endl;
    cout << "Yellow Bus shows you the ratings of the buses so that you can easily compare and" << endl;
    cout << "choose the bus which is perfect for you and your family! It shows you the ticket" << endl;
    cout << "fare of each bus too. Moreover it let's you check the amenities available in the" << endl;
    cout << "bus you are booking your seats. YellowBus offers you codes too which can get you" << endl;
    cout << "additional discounts on your ticket fares." << endl;
    cout << endl;
    cout << "Do you want to go to the previous menu? (Yes/No)" << endl;
    do
    //Checking if user choic is valid
    {
        n = 0;
        string op;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> op;
        if(op == "Yes")
        {
            Call_Class cc;
            cc.choose(t, r, 0);
        }
        else if(op == "No")
            exit(0);
        else
        {
            cout << "We didn't get you, please try again!" << endl;
            n++;
        }
    }
    while(n != 0);
}

int main()
{
	Call_Class cc;
	cc.intro();
	return 0;
}
