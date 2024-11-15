package CIE;

public class Internals extends Student {
	public short[] I1 = new short[5];
	public short[] I2 = new short[5];



	public Internals (String name, String usn, int sem, short marks1[], short marks2[]) {
		super(name, usn, sem);

		for (int i = 0; i < 5; i++){
			I1[i]=marks1[i];
			I2[i]=marks2[i];
		}
	}

	public void display(){
		for (int i = 0;i<30;i++)System.out.print("-"); 
			System.out.print("MARKS CARD");
		for (int i = 0;i<30;i++)System.out.print("-"); 

		System.out.println();	

		super.display();
		for (int i = 0; i < 5; i++)
			System.out.println(Courses[i] + ":\t " + I1[i] + "/50" + "\t " + I2[i] + "/50");	
		System.out.println();			
		for (int i = 0;i<70;i++)System.out.print("-"); 
	}	
}
