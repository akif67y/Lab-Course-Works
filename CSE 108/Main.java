import java.util.Random;
class Account {

    private int number;
    private String customer;
    private double balance;
    // you are not allowed to add any more class variables here

    // you are not allowed to write any other constructor
    public Account(int number, String customer, double balance) {
        this.number = number;
        this.customer = customer;
        this.balance = balance;
    }
    public double getBalance(){
        return balance;
    }
     public String getCustomer(){
        return customer;
    }
    public int getNumber(){
        return number;
    }
    public void setBalance(double d){
        balance = d;
    }
    public void setNumber(int n){
        number = n;
    }
    public void setcustomer(String a){
         customer = a;
    }


    // add your code here
}


 class Branch {

    private int id;
    private String name;
    private static Branch [] branch = new Branch[20];
    private static int branchcount ;
    private Account []  accounts;
    private int accountCount;
    // add your code here
    // there can be at most 20 branches  

     // you are not allowed to write any other constructor
    public Branch(int id, String name) {

        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        branch[branchcount++] = this;
        // add your code here
    }

    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }
   
    public double getBranchBalance(){
        double sum = 0;
        for(int i = 0; i < accountCount; i++){
            sum += accounts[i].getBalance();
        }
        return sum;
    }
    public Account getMinBalanceAccount(){
        double min = accounts[0].getBalance();
        int indx = 0;
        for(int i = 1; i < accountCount; i++){
            if(accounts[i].getBalance()< min){
                min = accounts[i].getBalance();
                indx = i;
            }
        }
        return accounts[indx];

    }
    public static void transferBalance(Account a, Account b, float balance){
        a.setBalance(a.getBalance() - balance);
        b.setBalance(b.getBalance() + balance);
    }
    public void printbranch(){
        System.out.println("Branch Id" + id + " Branch Name " + name);
       
         for(int i = 0; i < accountCount; i++){
            System.out.println("Account no"+ accounts[i].getNumber()+ ", Account name" + accounts[i].getCustomer() +", Balance: "+ accounts[i].getBalance());
         }
    }
    public static void printAllBranchesInfo(){
        for(int i = 0; i < branchcount; i++){
            branch[i].printbranch();
        }
    }


    // add your code here

}



public class Main {
    public static void main(String[] args) {
          Account a [] = new Account[6];
        Random r = new Random();
        for (int i = 0; i < 6; i++)
        {
            a[i] = new Account(i+1, "ACC" + (i+1), 10000 * r.nextDouble());
        }
        Branch b [] = new Branch[2];
        for (int i = 0; i < 2; i++) {
            b[i] = new Branch(i+1, "BR" + (i+1));
        }
        b[0].addAccount(a[0]); // add the Account to this Branch
        b[0].addAccount(a[1]); // add the Account to this Branch
        b[1].addAccount(a[2]); // add the Account to this Branch
        b[1].addAccount(a[3]); // add the Account to this Branch
        b[1].addAccount(a[4]); // add the Account to this Branch
        b[1].addAccount(a[5]); // add the Account to this Branch
        System.out.println(b[0].getBranchBalance()); // prints the total Balance of this Branch
        System.out.println(b[1].getBranchBalance()); // prints the total Balance of this Branch
        System.out.println(b[0].getMinBalanceAccount().getCustomer()); // prints the name of the Account with lowest Balance in this Branch
        System.out.println(b[1].getMinBalanceAccount().getCustomer()); // prints the name of the Account with lowest Balance in this Branch
        Branch.transferBalance(a[4], a[3], 100); // transfer 100 from balance of Account a[4] to Account a[3] 
        Branch.printAllBranchesInfo(); // prints all branches info as follows (this is just a sample, you can't hardcode this output)
        /*Branch Id: 1, Branch Name: BR1
        Account Number: 1, Customer Name: ACC1, Balance: actual balance
        Account Number: 2, Customer Name: ACC2, Balance: actual balance
        Branch Id: 2, Branch Name: BR2
        Account Number: 3, Customer Name: ACC3, Balance: actual balance
        Account Number: 4, Customer Name: ACC4, Balance: actual balance
        Account Number: 5, Customer Name: ACC5, Balance: actual balance
        Account Number: 6, Customer Name: ACC6, Balance: actual balance*/
    }
}