package SEE;

import CIE.*;

public class Externals extends CIE.Student {
	short[] E_marks = new short[5];

	public Externals (String name, String usn, int sem, short marks[]) {
		super(name, usn, sem);

		for (int i = 0; i < 5; i++){
			E_marks[i]=marks[i];
		}
	}
	
	void calculate(CIE.Internals i1) {
		for (int i = 0; i < 5; i++)
			E_marks[i] = (short) ((E_marks[i]/2) + (i1.I1[i] + i1.I2[i])/2);
	}

	public void display(CIE.Internals i1){
		calculate(i1);

		for (int i = 0;i<30;i++)System.out.print("-"); 
			System.out.print("MARKS CARD");
		for (int i = 0;i<30;i++)System.out.print("-"); 

		System.out.println();	

		super.display();
		for (int i = 0; i < 5; i++)
			System.out.println(Courses[i] + ":\t " + E_marks[i] + "/100");	
		System.out.println();			
		for (int i = 0;i<70;i++)System.out.print("-"); 
	}	
}
