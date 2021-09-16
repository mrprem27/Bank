#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Loan
{
private:
    int id;
    int p;
    float r;
    string date;
    int t;
    double intrest;

public:
    Loan(int p, float r, int t, string date)
    {
        this->p = p;
        this->r = r;
        this->t = t;
        this->date = date;
        this->intrest = p * r * t / 100;
    }
    void getDetails()
    {
        cout << "Date         : " << date << endl;
        cout << "Amount       : " << p << endl;
        cout << "Intrest Rate : " << r << endl;
        cout << "Time         : " << t << endl;
        cout << "Intrest      : " << intrest << endl;
    }
    ~Loan()
    {
    }
};
class Balance
{
private:
    long limit;
    double curr_bal;
    vector<pair<string, pair<bool, double>>> last_5_transactions;

public:
    void withdrawl(float amt, string date)
    {
        if (amt <= curr_bal)
        {
            curr_bal -= amt;
            if (last_5_transactions.size() < 5)
                last_5_transactions.push_back({date, {false, amt}});
            else
            {
                last_5_transactions.erase(last_5_transactions.begin());
                last_5_transactions.push_back({date, {false, amt}});
            }
            cout << "Remaining balance is :Rs. " << curr_bal << endl;
        }
        else
            cout << "insufficent Balance" << endl;
    }
    Balance()
    {
        limit = 100000;
        curr_bal = 0;
    }
    ~Balance()
    {
    }
    void deposit(float amt, string date)
    {
        if (amt + curr_bal <= limit)
        {
            curr_bal += amt;
            if (last_5_transactions.size() < 5)
                last_5_transactions.push_back({date, {true, amt}});
            else
            {
                last_5_transactions.erase(last_5_transactions.begin());
                last_5_transactions.push_back({date, {true, amt}});
            }
            cout << "Current balance is:Rs." << curr_bal << endl;
        }
        else
            cout << "Limit exceeded" << endl;
    }
    void last_5_trans()
    {
        for (auto ele : last_5_transactions)
        {
            string type = ele.second.first ? "Deposit\t" : "Withdrawl";
            cout << ele.first << "\t" << type << "\tRs." << ele.second.second << endl;
        }
    }
    void balance()
    {
        cout << "Your current Balance is:Rs. " << curr_bal << " and limit of your account is :Rs. " << limit << endl;
    }
};
class Person
{
protected:
    string name;
    char sex;
    string address;
    string dob;

public:
    Person(string name, string address, char sex, string dob)
    {
        this->name = name;
        this->sex = sex;
        this->address = address;
        this->dob = dob;
    }
    void getDetailsPerson()
    {
        cout << "Name    : " << name << endl;
        cout << "Sex     : " << sex << endl;
        cout << "Address : " << address << endl;
        cout << "dob     : " << dob << endl;
    }
    Person(string name, string address, char sex)
    {
        this->name = name;
        this->sex = sex;
        this->address = address;
        this->dob = "null";
    }
    ~Person()
    {
    }
};
class Account : private Person
{
private:
    string acc_no;
    string date;
    char type;
    string contact_no;
    string pass;
    vector<Person> nominee;
    Balance bal;
    vector<Loan> loan;

public:
    Account(string date, char type, string name, string address, char sex, string dob, string contact_no, string acc_no, string pass) : Person(name, address, sex, dob)
    {
        this->date = date;
        this->type = type;
        this->contact_no = contact_no;
        this->pass = pass;
        this->acc_no = acc_no;
    }
    ~Account()
    {
    }
    string get_Acc_no()
    {
        return acc_no;
    }
    char get_type()
    {
        return type;
    }
    bool ckeck_Acc_pass(string pass)
    {
        return this->pass == pass;
    }
    void data()
    {
        cout << "Details of Your Account" << endl;
        cout << "Account Number  : " << acc_no << endl;
        cout << "Name            : " << name << endl;
        cout << "Sex M/F/O       : " << sex << endl;
        cout << "Account opening : " << date << endl;
        cout << "Type S/C        : " << type << endl;
        cout << "DoB dd/mm/yyyy  : " << dob << endl;
        cout << "Contact number  : " << contact_no << endl;
        cout << "Address         : " << address << endl;
    }
    void getLoan(int p, float r, int t, string date)
    {
        loan.push_back(Loan(p, r, t, date));
        cout << "Loan Accepted!!" << endl;
    }
    void getLoanDeatils()
    {
        int i = 0;
        for (auto ele : loan)
        {
            cout << ++i << " : " << endl;
            ele.getDetails();
            cout << endl;
        }
    }
    void withdrawlAmt(float amt, string date)
    {
        bal.withdrawl(amt, date);
    }
    void depositAmt(float amt, string date)
    {
        bal.deposit(amt, date);
    }
    void getLastfivetrans()
    {
        bal.last_5_trans();
    }
    void getBalance()
    {
        bal.balance();
    }
    void addNominee(Person x)
    {
        nominee.push_back(x);
        cout << "Nominee Added to your account" << endl;
    }
    void deatailsNominee()
    {
        for (auto ele : nominee)
        {
            ele.getDetailsPerson();
            cout << endl;
        }
    }
    void updateName(string name)
    {
        this->name = name;
        cout << "Changes Saved!!" << endl;
    }
    void updateDOB(string dob)
    {
        this->dob = dob;
        cout << "Changes Saved!!" << endl;
    }
    void updateCN(string contact_no)
    {
        this->contact_no = contact_no;
        cout << "Changes Saved!!" << endl;
    }
    void updatepass(string pass)
    {
        this->pass = pass;
        cout << "Changes Saved!!" << endl;
    }
    void updateaddress(string address)
    {
        this->address = address;
        cout << "Changes Saved!!" << endl;
    }
};
class Costumer
{
    string name;
    string acc_no;
    string pass;

public:
    Costumer(string name, string acc_no, string pass)
    {
        this->name = name;
        this->acc_no = acc_no;
        this->pass = pass;
    }
};
class Bank
{
private:
    queue<Account> recent_acoounts;
    vector<Account> accounts;
    long long new_num;
    vector<Costumer> list;

protected:
    long account_count(char type)
    {
        if (type != 'S' || type != 'C')
        {
            cout << "Account type error";
            return 0;
        }
        int c = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            if (type == accounts[i].get_type())
                c++;
        }
        return c;
    }

public:
    long account_count()
    {
        return accounts.size();
    }

    string open(string date, char type, string name, string address, char sex, string dob, string contact_no, string pass)
    {
        accounts.push_back(Account(date, type, name, address, sex, dob, contact_no, to_string(++new_num), pass));
        return to_string(new_num);
    }
    void close(string acc_no_todelete)
    {
        long count = accounts.size();
        for (int i = 0; i < count; i++)
        {
            if (accounts[i].get_Acc_no() == acc_no_todelete)
            {
                accounts[i].~Account();
                cout << "Account deleted!!" << endl;
                accounts.erase(accounts.begin() + i);
            }
        }
        if (count == accounts.size())
            cout << "Account not Found!!" << endl;
    }
    Bank()
    {
        new_num = 0;
        cout << "Bank opened!!" << endl;
    }
    ~Bank()
    {
        cout << "Bank closed!!";
    }
    Account get_services(string name, string acc_no, string pass)
    {
        Account ret = find_acc(acc_no, pass);
        list.push_back(Costumer(name, acc_no, pass));
        return ret;
    }
    Account find_acc(string acc_no, string pass)
    {
        long count = accounts.size();
        for (int i = 0; i < count; i++)
        {
            if (accounts[i].get_Acc_no() == acc_no && accounts[i].ckeck_Acc_pass(pass))
                return accounts[i];
        }
        cout << "Wrong Credentials!!" << endl;
        exit(1);
    }
};
class Only_Employess : public Bank
{
    Only_Employess() { cout << "ggg"; }
};

int main()
{
    Bank *bank = new Bank();
    cout << "Hello!! Welcome to Surity Bank Services" << endl;
    cout << endl;
    int choice;
    while (true)
    {
        cout << endl;
        cout << "1.New Costumer\n2.Existing Costumer" << endl;
        cout << "0.Exit" << endl;
        cin >> choice;
        if (choice == 0)
            break;
        switch (choice)
        {
        case 1:
        {
            string date, name, address, dob, contact_no, pass;
            char type, sex;
            cout << "Enter details to create new Account" << endl;
            cout << endl;
            cout << "Enter your name" << endl;
            getchar();
            getline(cin, name);
            cout << "Enter sex M/F/O" << endl;
            cin >> sex;
            cout << "Enter date dd/mm/yyyy" << endl;
            cin >> date;
            getchar();
            cout << "Enter address" << endl;
            getline(cin, address);
            cout << "Enter DoB dd/mm/yyyy" << endl;
            cin >> dob;
            cout << "Enter contact number" << endl;
            cin >> contact_no;
            cout << "Enter type S/C" << endl;
            cin >> type;
            cout << "Enter password" << endl;
            cin >> pass;
            cout << "Your account number is " << bank->open(date, type, name, address, sex, dob, contact_no, pass) << endl;
            break;
        }
        case 2:
        {
            string acc_no, pass, name;
            getchar();
            cout << "Enter details to continue" << endl;
            cout << endl;
            cout << "Enter your name" << endl;
            getline(cin, name);
            cout << "Enter Account number" << endl;
            cin >> acc_no;
            cout << "Enter password" << endl;
            cin >> pass;
            cout << name << " " << acc_no << " " << pass << endl;
            Account account = bank->get_services(name, acc_no, pass);
            cout << endl;
            while (true)
            {
                cout << endl;
                cout << "Enter Your Choice for the Operation!!" << endl;
                cout << "1.Loan" << endl;
                cout << "2.Balance" << endl;
                cout << "3.Nominee" << endl;
                cout << "4.Show my details" << endl;
                cout << "5.Update my details" << endl;
                cout << "0.Exit" << endl;
                cin >> choice;
                if (choice == 0)
                    break;
                switch (choice)
                {
                case 1:
                {
                    while (true)
                    {
                        cout << endl;
                        cout << "Enter Your Choice for the Operation!!" << endl;
                        cout << "1.Get Loan" << endl;
                        cout << "2.Get Loan Details" << endl;
                        cout << "0.Exit" << endl;
                        cin >> choice;
                        if (choice == 0)
                            break;
                        switch (choice)
                        {
                        case 1:
                        {
                            int p, t;
                            float r;
                            string date;
                            getchar();
                            cout << "Enter Principal amount" << endl;
                            cin >> p;
                            cout << "Enter Time" << endl;
                            cin >> t;
                            cout << "Enter Intrest Rate" << endl;
                            cin >> r;
                            cout << "Enter Date" << endl;
                            cin >> date;
                            account.getLoan(p, r, t, date);
                            break;
                        }
                        case 2:
                            account.getLoanDeatils();
                        default:
                            cout << "Enter valid option!!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    while (true)
                    {
                        cout << endl;
                        cout << "Enter Your Choice for the Operation!!" << endl;
                        cout << "1.Get Balance and limit" << endl;
                        cout << "2.Last 5 Transactions" << endl;
                        cout << "3.Withdrawl" << endl;
                        cout << "4.Deposit" << endl;
                        cout << "0.Exit" << endl;
                        cin >> choice;
                        if (choice == 0)
                            break;
                        switch (choice)
                        {
                        case 1:
                            account.getBalance();
                            break;
                        case 2:
                        {
                            account.getLastfivetrans();
                            break;
                        }
                        case 3:
                        {
                            string date;
                            float amt;
                            cout << "Enter Amount" << endl;
                            cin >> amt;
                            cout << "Enter Date" << endl;
                            cin >> date;
                            account.withdrawlAmt(amt, date);
                            break;
                        }
                        case 4:
                        {
                            string date;
                            float amt;
                            cout << "Enter Amount" << endl;
                            cin >> amt;
                            cout << "Enter Date" << endl;
                            cin >> date;
                            account.depositAmt(amt, date);
                            break;
                        }
                        default:
                            cout << "Enter a valid Option!!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 3:
                {
                    while (true)
                    {
                        cout << endl;
                        cout << "Enter Your Choice for the Operation!!" << endl;
                        cout << "1.Add Nominee" << endl;
                        cout << "2.Get Nominiee Details" << endl;
                        cout << "0.Exit" << endl;
                        cin >> choice;
                        if (choice == 0)
                            break;
                        switch (choice)
                        {
                        case 1:
                        {
                            string name, address, dob;
                            char sex;
                            getchar();
                            cout << "Enter details to add Nominee to your Account" << endl;
                            cout << endl;
                            cout << "Enter your name" << endl;
                            getline(cin, name);
                            cout << "Enter sex M/F/O" << endl;
                            cin >> sex;
                            getchar();
                            cout << "Enter address" << endl;
                            getline(cin, address);
                            cout << "Enter DoB dd/mm/yyyy" << endl;
                            cin >> dob;
                            account.addNominee(Person(name, address, sex, dob));
                            break;
                        }
                        case 2:
                            account.deatailsNominee();
                            break;
                        default:
                            cout << "Enter valid option!!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 4:
                {
                    account.data();
                    break;
                }
                case 5:
                {
                    cout << "Enter Your Choice for the Upgradion!!" << endl;
                    cout << "1.Name" << endl;
                    cout << "2.Address" << endl;
                    cout << "3.DoB dd/mm/yyyy" << endl;
                    cout << "4.Contact number" << endl;
                    cout << "5.Password" << endl;
                    cout << "0.Exit" << endl;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        getchar();
                        string name;
                        cout << "Enter your Name" << endl;
                        getline(cin, name);
                        account.updateName(name);
                        break;
                    }
                    case 2:
                    {
                        string dob;
                        cout << "Enter DoB dd/mm/yyyy" << endl;
                        cin >> dob;
                        account.updateDOB(dob);
                        break;
                    }
                    case 3:
                    {
                        string address;
                        cout << "Enter address" << endl;
                        getchar();
                        getline(cin, address);
                        account.updateaddress(address);
                        break;
                    }
                    case 4:
                    {
                        string contact_no;
                        cout << "Enter contact number" << endl;
                        cin >> contact_no;
                        account.updateCN(contact_no);
                        break;
                    }
                    case 5:
                    {
                        string pass;
                        cout << "Enter password" << endl;
                        cin >> pass;
                        account.updatepass(pass);
                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    cout << "Enter valid option!!" << endl;
                    break;
                }
            }
            break;
        }
        default:
            cout << "Enter valid option!!" << endl;
            break;
        }
    }
    cout << bank->account_count();
}

// Balance(char type)
// {
//     if (type == 'S')
//         limit = 1000000;
//     else
//         limit = 10000000;
//     curr_bal = 0;
// }