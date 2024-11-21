import CIE.*;
import SEE.*;
import java.util.Scanner;


class Main {
	public static void main(String xx[]){
		Scanner sm = new Scanner(System.in).useDelimiter("\n");

		System.out.println("Enter the number of students:");
		int n = sm.nextInt();

		CIE.Internals Itls[] = new CIE.Internals[n];
		SEE.Externals Exls[] = new SEE.Externals[n];

		for(int i = 0; i < n; i++){
			System.out.println("Enter name:");
			String name = sm.next();

			System.out.println("Enter USN:");
			String USN = sm.next();


			System.out.println("Enter marks for CIE 1:");

			short cie1[] = new short[5];
			short cie2[] = new short[5];


			for(int j = 0; j<5;j++)
				cie1[j] = sm.nextShort();

			System.out.println("Enter marks for CIE 2:");
			
			for(int j = 0; j<5;j++)
				cie2[j] = sm.nextShort();


			System.out.println("Enter SEE Marks:");

			short see[] = new short[5];

			for(int j = 0; j<5;j++)
				see[j] = sm.nextShort();
			
			Itls[i] = new CIE.Internals(name, USN, 3, cie1, cie2);
			Itls[i].display();

			System.out.println("");

			Exls[i] = new SEE.Externals(name, USN, 3, see);
			Exls[i].display(Itls[i]);

			System.out.println("");
		}
	}

}
