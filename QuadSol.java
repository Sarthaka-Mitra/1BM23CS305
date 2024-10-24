import java.util.Scanner;

class QuadSol
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter coefficients a, b, c: ");
	float a,b,c;
        a = sc.nextFloat();
        b = sc.nextFloat();
        c = sc.nextFloat();
        
        float r1,r2, dis;
	dis = b * b - 4 * a * c;
        if (discriminant < 0) 
            System.out.println("No real solution");
         else {
            r1 = (-b + Math.sqrt(discriminant)) / (2 * a);
            r2 = (-b - Math.sqrt(discriminant)) / (2 * a);
            System.out.println("Root 1: " + r1);
            System.out.println("Root 2: " + r2);
        }
    }
}
