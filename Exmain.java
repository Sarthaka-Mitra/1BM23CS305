import java.util.Scanner;

class WrongAge extends Exception {
	int error;

	WrongAge(int x) {
		error = x;
	}

	public String toString(){
		if (error == 1)
			return "Age cannot be a negative number";
		else if (error == 2)
			return "Son's age cannot be greater than father's age";
		else
			return "Unknown Error";
	}
}



class Father{
	int age;

	Father(int x) throws WrongAge {
		if(x < 0)
			throw new WrongAge(1);
		age = x;
	}
}

class Son extends Father {
	int age2;

	Son(int x, int y) throws WrongAge {
		super(x);

		if (y < 0)
			throw new WrongAge(1);
		if (y > x)
			throw new WrongAge(2);

		age2 = y;
	}
}

class Exmain{
	public static void main(String arg[]){
		Scanner sm = new Scanner(System.in);

		System.out.println("Enter the age of father and son respectively:");
		int f = sm.nextInt();
		int s = sm.nextInt();

		try {
			Father f1 = new Father(f);
			
			try {
				Son s1 = new Son(f, s);
							}
			catch (WrongAge a)
			{System.out.println(a);}
		}
		catch (WrongAge e)
		{System.out.println(e);}
	}

}
