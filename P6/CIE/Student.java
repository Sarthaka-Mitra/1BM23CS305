package CIE;


public class Student {
	String name, usn;
	int sem;
	public String[] Courses = {"23CS3PCOOJ", "23CS3PCDBM", "23CS3PCDST", "23MA3BSSDM", "23CS3ESCOA"};

	public Student(String name, String usn, int sem) {
		this.name = name;
		this.usn = usn;
		this.sem = sem;
	}

	public void display(){
		System.out.println("Name:" + name +
				   "\nUSN:" + usn +
				   "\nSemester:" + sem);	
	}


}