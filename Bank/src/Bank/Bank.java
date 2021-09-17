package Bank;

import java.util.Objects;
import java.util.Vector;

public class Bank {
    private
    //queue<Account> recent_accounts
    Vector<Account> accounts=new Vector<>();
    long new_num;
    Vector<Costumer> list=new Vector<>();

    protected
    long account_count(char type)
    {
        if (type != 'S' && type != 'C')
        {
            System.out.println("Account type error");
            return 0;
        }
        int c = 0;
        for (Account account : accounts) {
            if (type == account.get_type())
                c++;
        }
        return c;
    }

    public
    long account_count()
    {
        return accounts.size();
    }

    String open(String date, char type, String name, String address, char sex, String dob, String contact_no, String pass)
    {
        accounts.add(new Account(date, type, name, address, sex, dob, contact_no, Long.toString(++new_num), pass));
        return Long.toString(new_num);
    }
    void close(String acc_no_delete)
    {
        long count = accounts.size();
        for (int i = 0; i < count; i++)
        {
            if (Objects.equals(accounts.get(i).get_Acc_no(), acc_no_delete))
            {
                System.out.println("Account deleted!!");
                accounts.remove(i);
            }
        }
        if (count == accounts.size())
            System.out.println("Account not Found!!");
    }
    Bank()
    {
        new_num = 0;
        System.out.println("Bank opened!!");
    }
    Account get_services(String name, String acc_no, String pass)
    {
        Account ret = find_acc(acc_no, pass);
        list.add(new Costumer(name, acc_no, pass));
        return ret;
    }
    Account find_acc(String acc_no, String pass)
    {
        for (Account account : accounts) {
            if (Objects.equals(account.get_Acc_no(), acc_no) && account.check_Acc_pass(pass))
                return account;
        }
        System.out.println("Wrong Credentials!!");
        return null;
    }
}
