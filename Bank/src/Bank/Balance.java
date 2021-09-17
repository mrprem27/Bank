package Bank;

import java.util.Vector;
class balList{
    String date;
    boolean type;
    float amount;
    balList(String date,boolean type,float amount){
        this.date=date;
        this.type=type;
        this.amount=amount;
    }
}
public class Balance {
    private
    final long limit;
    double curr_bal;
    Vector <balList> last_5_transactions = new  Vector <>();

    public
    Balance()
    {
        limit = 100000;
        curr_bal = 0;
    }
    void withdrawal(float amt, String date)
    {
        if (amt <= curr_bal)
        {
            curr_bal -= amt;
            if (last_5_transactions.size() >= 5)
                last_5_transactions.remove(0);
            last_5_transactions.add(new balList(date,false,amt));
            System.out.println("Remaining balance is :Rs. " + curr_bal);
        }
        else
            System.out.println("insufficient Balance");
    }
    void deposit(float amt, String date)
    {
        if (amt + curr_bal <= limit)
        {
            curr_bal += amt;
            if (last_5_transactions.size() >= 5)
                last_5_transactions.remove(0);
            last_5_transactions.add(new balList(date,false,amt));
            System.out.println("Current balance is:Rs." + curr_bal);
        }
        else
            System.out.println("Limit exceeded");
    }
    void last_5_trans()
    {
        for (balList ele : last_5_transactions)
        {
            String type = ele.type ? "Deposit\t" : "Withdrawal";
            System.out.println(ele.date + "\t" + type + "\tRs." + ele.amount);
        }
    }
    void balance()
    {
        System.out.println("Your current Balance is:Rs. " + curr_bal + " and limit of your account is :Rs. " + limit);
    }
}
