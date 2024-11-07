import java.util.Scanner;
class Account {
	String acc_name;
	ìnt  acc_no;
	boolean if_curract, if_saving;
	long balance;
	
	static	Scanner sm = new Scanner(System.in);

	class Account(String name, int no, long bal) {
		acc_name = name;
		acc_no = no;
		balance = bal;
	}

	void check(){
		System.out.println("Are you holding a savings account?: ");
		if_saving = sm.nextBoolean();
		System.out.println("Are you holding a current account?: ");
		if_curract = sm.nextBoolean();
	}


	void deposit(){
		System.out.println("Enter amount to be added");
		long new = sm.nextLong();
		balance += new;
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
	
	class Curr_Act(String name, int no, long bal) {
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
	
	class Save_Acct(String name, int no, long bal, float interest) {
		super(name, no,bal);
		cmp_int = interest;
		balance *= (1+cmp_int);
		if_savings = true;
	}

	void dep_int(){
		int flag = 1;
		while (flag) {
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
	Scanner sc = new Scanner(System.in);

	//Creating a current account AND savings account
	
	
		
