import java.util.Scanner;
class Account {
	String acc_name;
	int  acc_no;
	boolean if_curract, if_saving;
	long balance;
	
	static	Scanner sm = new Scanner(System.in);

	Account(String name, int no, long bal) {
		acc_name = name;
		acc_no = no;
		balance = bal;
	}

	/*void check(){
		System.out.println("Are you holding a savings account?: ");
		if_saving = sm.nextBoolean();
		System.out.println("Are you holding a current account?: ");
		if_curract = sm.nextBoolean();
	}*/


	void deposit(){
		System.out.println("Enter amount to be added");
		long nw = sm.nextLong();
		balance += nw;
	}

	void disp(){
		System.out.println("Name: "+ acc_name +
				   "\nAccount number: " + acc_no +
				   "\nSaving Account status: " + if_saving + 
				   "\nCurrent Account status: " + if_curract + 
				   "\nBalance: " + balance);
	}
}

class Curr_Acct extends Account {
	
	Curr_Acct(String name, int no, long bal) {
		super(name, no, bal);
		service_charges();
		if_curract = true;
	}

	
	
	void service_charges(){
		if (balance <= 1000) {
			System.out.println("Service charge imposed");
			balance -= 150;
		}			
	}
	
	void cheque_book() {
		System.out.println("Enter the amount to send:");
		long amt = sm.nextLong();
		if (amt > balance){
			System.out.println("Amount entered exceeds the balance in account.");
			cheque_book();
			return;
		}
		else{
			System.out.println("Amount deducted.");
			balance -= amt;
			service_charges();
			return;
		}
	}
}

class Sav_Acct extends Account {
	float cmp_int;
	
	Sav_Acct(String name, int no, long bal) { //float interest) {
		super(name, no,bal);
		//cmp_int = interest;
		//balance *= (1+cmp_int);
		if_saving = true;
	}

	void dep_int(){
		int flag = 1;
		while (flag==1) {
			System.out.println("Enter the compound interest (value between 0 and 1): ");
			cmp_int = sm.nextFloat();


			if (cmp_int > 1 || cmp_int < 0){
				System.out.println("Invalid value, please enter again");
				continue;
			}
			else{ 
				balance *= (1+cmp_int);
				flag = 0;
			}
		}
	}
	
	
	void withdraw(){
		System.out.println("Enter the amount to withdraw from account:");
		long amt = sm.nextLong();
		if (amt > balance){
			System.out.println("Amount withdrawn exceeds the balance present: " + balance);	
			withdraw();
		}
		else{
			balance -= amt;
			System.out.println("Amount deducted. \nNew balance: " + balance);
		}

	}
}

class Bank {
	static Scanner sc = new Scanner(System.in);

	//Creating a current account AND savings account
	
	public static void main(String main[]) {
		System.out.println("Enter your name:");
		String name = sc.next();
		
		System.out.println("Enter your Bank Account number:");
		int no = sc.nextInt();
		
		System.out.println("Enter the amount to be entered:");
		long amt = sc.nextLong();
		Curr_Acct a1 = new Curr_Acct(name, no, amt);

		Sav_Acct a2 = new Sav_Acct(name, no, amt);
		
		a1.disp();
		a1.deposit();
	
		a1.cheque_book();
		a1.disp();
	 

		a1.cheque_book();
		a1.disp();
		//end of Current account activities

		a2.disp();

		a2.deposit();
		a2.dep_int();
		
		a2.disp();
		a2.withdraw();
		
		a2.disp();
		//end of Savings account activities
	}
}

