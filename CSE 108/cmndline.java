import java.util.Scanner;
public class cmndline {
   public static void main(String[] args) {
    Scanner myobj = new Scanner(System.in);
    int n;
    n = myobj.nextInt();
    int []ara = new int[n];
    for(String val: args){
        int t = Integer.parseInt(val);
        System.out.print(t +"->");
    }
    System.out.println("NULL");
    
    for(int i = 0; i < n; i++){
        ara[i] = myobj.nextInt();
    }
    for(int i = 0; i < n; i++){
        System.out.print(ara[i] +"->");
    }
    myobj.close();

   } 
}
