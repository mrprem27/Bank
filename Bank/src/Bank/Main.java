package Bank;
/*class Only_Employees : public Bank
        {
        Only_Employees() { System.out.println("ggg"; }
        };*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Bank bank = new Bank();
        Scanner sc = new Scanner(System.in);
        System.out.println("Hello!! Welcome to Security Bank Services");
        System.out.println();
        int choice;
        while (true) {
            System.out.println();
            System.out.println("1.New Costumer\n2.Existing Costumer");
            System.out.println("0.Exit");
            choice = sc.nextInt();
            if (choice == 0)
                break;
            switch (choice) {
                case 1 -> {
                    String date, name, address, dob, contact_no, pass;
                    char type, sex;
                    System.out.println("Enter details to create new Account");
                    System.out.println();
                    System.out.println("Enter your name");
                    sc.next();
                    name = sc.nextLine();
                    System.out.println("Enter sex M/F/O");
                    sex = sc.next().charAt(0);
                    System.out.println("Enter date dd/mm/yyyy");
                    date = sc.next();
                    sc.next();
                    System.out.println("Enter address");
                    address = sc.nextLine();
                    System.out.println("Enter DoB dd/mm/yyyy");
                    dob = sc.next();
                    System.out.println("Enter contact number");
                    contact_no = sc.next();
                    System.out.println("Enter type S/C");
                    type = sc.next().charAt(0);
                    System.out.println("Enter password");
                    pass = sc.next();
                    System.out.println("Your account number is " + bank.open(date, type, name, address, sex, dob, contact_no, pass));
                }
                case 2 -> {
                    String acc_no, pass, name;
                    sc.next();
                    System.out.println("Enter details to continue");
                    System.out.println();
                    System.out.println("Enter your name");
                    name = sc.nextLine();
                    System.out.println("Enter Account number");
                    acc_no = sc.next();
                    System.out.println("Enter password");
                    pass = sc.next();
                    System.out.println(name + " " + acc_no + " " + pass);
                    Account account = bank.get_services(name, acc_no, pass);
                    System.out.println();
                    while (true) {
                        System.out.println();
                        System.out.println("Enter Your Choice for the Operation!!");
                        System.out.println("1.Loan");
                        System.out.println("2.Balance");
                        System.out.println("3.Nominee");
                        System.out.println("4.Show my details");
                        System.out.println("5.Update my details");
                        System.out.println("0.Exit");
                        choice = sc.nextInt();
                        if (choice == 0)
                            break;
                        switch (choice) {
                            case 1 -> {
                                while (true) {
                                    System.out.println();
                                    System.out.println("Enter Your Choice for the Operation!!");
                                    System.out.println("1.Get Loan");
                                    System.out.println("2.Get Loan Details");
                                    System.out.println("0.Exit");
                                    choice = sc.nextInt();
                                    if (choice == 0)
                                        break;
                                    switch (choice) {
                                        case 1: {
                                            int p, t;
                                            float r;
                                            String date;
                                            System.out.println("Enter Principal amount");
                                            p = sc.nextInt();
                                            System.out.println("Enter Time");
                                            t = sc.nextInt();
                                            System.out.println("Enter Interest Rate");
                                            r = sc.nextFloat();
                                            System.out.println("Enter Date");
                                            date = sc.next();
                                            account.getLoan(p, r, t, date);
                                            break;
                                        }
                                        case 2:
                                            account.getLoanDetails();
                                        default:
                                            System.out.println("Enter valid option!!");
                                            break;
                                    }
                                }
                            }
                            case 2 -> {
                                while (true) {
                                    System.out.println();
                                    System.out.println("Enter Your Choice for the Operation!!");
                                    System.out.println("1.Get Balance and limit");
                                    System.out.println("2.Last 5 Transactions");
                                    System.out.println("3.Withdrawal");
                                    System.out.println("4.Deposit");
                                    System.out.println("0.Exit");
                                    choice = sc.nextInt();
                                    if (choice == 0)
                                        break;
                                    switch (choice) {
                                        case 1 -> account.getBalance();
                                        case 2 -> account.getLastFiveTrans();
                                        case 3 -> {
                                            String date;
                                            float amt;
                                            System.out.println("Enter Amount");
                                            amt = sc.nextInt();
                                            System.out.println("Enter Date");
                                            date = sc.next();
                                            account.withdrawalAmt(amt, date);
                                        }
                                        case 4 -> {
                                            String date;
                                            float amt;
                                            System.out.println("Enter Amount");
                                            amt = sc.nextInt();
                                            System.out.println("Enter Date");
                                            date = sc.next();
                                            account.depositAmt(amt, date);
                                        }
                                        default -> System.out.println("Enter a valid Option!!");
                                    }
                                }
                            }
                            case 3 -> {
                                while (true) {
                                    System.out.println();
                                    System.out.println("Enter Your Choice for the Operation!!");
                                    System.out.println("1.Add Nominee");
                                    System.out.println("2.Get Nominee Details");
                                    System.out.println("0.Exit");
                                    choice = sc.nextInt();
                                    if (choice == 0)
                                        break;
                                    switch (choice) {
                                        case 1 -> {
                                            String address, dob;
                                            char sex;
                                            sc.next();
                                            System.out.println("Enter details to add Nominee to your Account");
                                            System.out.println();
                                            System.out.println("Enter your name");
                                            sc.nextLine();
                                            System.out.println("Enter sex M/F/O");
                                            sex = sc.next().charAt(0);
                                            sc.next();
                                            System.out.println("Enter address");
                                            address = sc.nextLine();
                                            System.out.println("Enter DoB dd/mm/yyyy");
                                            dob = sc.next();
                                            account.addNominee(new Person(name, address, sex, dob));
                                        }
                                        case 2 -> account.detailsNominee();
                                        default -> System.out.println("Enter valid option!!");
                                    }
                                }
                            }
                            case 4 -> account.data();
                            case 5 -> {
                                System.out.println("Enter Your Choice for the Upgrading!!");
                                System.out.println("1.Name");
                                System.out.println("2.Address");
                                System.out.println("3.DoB dd/mm/yyyy");
                                System.out.println("4.Contact number");
                                System.out.println("5.Password");
                                System.out.println("0.Exit");
                                choice = sc.nextInt();
                                switch (choice) {
                                    case 1: {
                                        sc.next();
                                        System.out.println("Enter your Name");
                                        name = sc.nextLine();
                                        account.updateName(name);
                                        break;
                                    }
                                    case 2: {
                                        String dob;
                                        System.out.println("Enter DoB dd/mm/yyyy");
                                        dob = sc.next();
                                        account.updateDOB(dob);
                                        break;
                                    }
                                    case 3: {
                                        String address;
                                        System.out.println("Enter address");
                                        sc.next();
                                        address = sc.nextLine();
                                        account.updateAddress(address);
                                        break;
                                    }
                                    case 4: {
                                        String contact_no;
                                        System.out.println("Enter contact number");
                                        contact_no = sc.next();
                                        account.updateCN(contact_no);
                                        break;
                                    }
                                    case 5: {
                                        System.out.println("Enter password");
                                        pass = sc.next();
                                        account.updatePass(pass);
                                        break;
                                    }
                                    default:
                                        break;
                                }
                            }
                            default -> System.out.println("Enter valid option!!");
                        }
                    }
                }
                default -> System.out.println("Enter valid option!!");
            }
        }
        System.out.println(bank.account_count());
    }
}

/*Balance(char type)
// {
//     if (type == 'S')
//         limit = 1000000;
//     else
//         limit = 10000000;
//     curr_bal = 0;
// }
}*/
