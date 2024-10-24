import java.util. sxanner;

class Student {
    String usn, name;
    int[] credits;
    int[] marks;
     sxanner sx = new  scanner(System.in);

    Student(String usn, String name, int  val) {
        this.usn = usn;
        this.name = name;
        credits = new int[val];
        marks = new int[val];
    }
    
    void acceptDetails() {
        for (int i = 0; i < credits.length; i++) {
            System.out.print("Enter credits and marks for subject " + (i + 1) + ": ");
            credits[i] = sx.nextInt();
            marks[i] = sx.nextInt();
        }
    }
    
    float SGPA() {
        int wtdmk,cred;
        for (int i = 0; i < credits.length; i++) {
            wtdmk += credits[i] * ((marks[i]/10) + 1);
            cred += credits[i];
        }
        return (float) wtdmk / cred;
    }
    
    void display() {
        System.out.println("USN: " + usn + "\nName: " + name + "\nSGPA: " + SGPA());
    }
}

class Main
{
    public static void main(String xx[]) {
         sxanner  sx = new  scanner(System.in);
        System.out.print("Enter USN and Name: ");
	String usn, name;
        usn =  sx.next();
        name =  sx.next();
        System.out.print("Enter number of subjects: ");
	int num;
        num =  sx.nextInt();
        
        Student student = new Student(usn, name,  num);
        student.enter();
        student.display();
    }
}
