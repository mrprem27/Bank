package Bank;

import java.util.Objects;
import java.util.Vector;

public class Account extends Person{
    private
    final String acc_no;
    String date;
    char type;
    String contact_no;
    String pass;
    Vector<Person> nominee=new Vector<>();
    Balance bal;
    Vector<Loan> loan=new Vector<>();

    public

    Account(String date, char type, String name, String address, char sex, String dob, String contact_no, String acc_no, String pass)
    {
        super(name, address, sex, dob);
        this.date = date;
        this.type = type;
        this.contact_no = contact_no;
        this.pass = pass;
        this.acc_no = acc_no;
        this.bal=new Balance();
    }
    String get_Acc_no()
    {
        return acc_no;
    }
    char get_type()
    {
        return type;
    }
    boolean check_Acc_pass(String pass)
    {
        return Objects.equals(this.pass, pass);
    }
    void data()
    {
        System.out.println("Details of Your Account");
        System.out.println("Account Number  : " + acc_no);
        System.out.println("Name            : " + name);
        System.out.println("Sex M/F/O       : " + sex);
        System.out.println("Account opening : " + date);
        System.out.println("Type S/C        : " + type);
        System.out.println("DoB dd/mm/yyyy  : " + dob);
        System.out.println("Contact number  : " + contact_no);
        System.out.println("Address         : " + address);
    }
    void getLoan(int p, float r, int t, String date)
    {
        loan.add(new Loan(p, r, t, date));
        System.out.println("Loan Accepted!!");
    }
    void getLoanDetails()
    {
        int i = 0;
        for (Loan ele : loan)
        {
            System.out.println(++i + " : ");
            ele.getDetails();
            System.out.println();
        }
    }
    void withdrawalAmt(float amt, String date)
    {
        bal.withdrawal(amt, date);
    }
    void depositAmt(float amt, String date)
    {
        bal.deposit(amt, date);
    }
    void getLastFiveTrans()
    {
        bal.last_5_trans();
    }
    void getBalance()
    {
        bal.balance();
    }
    void addNominee(Person x)
    {
        nominee.add(x);
        System.out.println("Nominee Added to your account");
    }
    void detailsNominee()
    {
        for (Person ele : nominee)
        {
            ele.getDetailsPerson();
            System.out.println();
        }
    }
    void updateName(String name)
    {
        this.name = name;
        System.out.println("Changes Saved!!");
    }
    void updateDOB(String dob)
    {
        this.dob = dob;
        System.out.println("Changes Saved!!");
    }
    void updateCN(String contact_no)
    {
        this.contact_no = contact_no;
        System.out.println("Changes Saved!!");
    }
    void updatePass(String pass)
    {
        this.pass = pass;
        System.out.println("Changes Saved!!");
    }
    void updateAddress(String address)
    {
        this.address = address;
        System.out.println("Changes Saved!!");
    }
}
