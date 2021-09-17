package Bank;

public class Loan {
    private final
    int p;
    float r;
    String date;
    int t;
    double interest;

    public
    Loan(int p, float r, int t, String date)
    {
        this.p = p;
        this.r = r;
        this.t = t;
        this.date = date;
        this.interest = p * r * t / 100;
    }
    void getDetails()
    {
        System.out.println("Date         : "+date);
        System.out.println("Amount       : "+p);
        System.out.println("Interest Rate : "+r);
        System.out.println("Time         : "+t);
        System.out.println("Interest      : "+ interest);
    }
}
