import java.util.Scanner;
abstract class Shape {
	int l1, l2;
	double area;

	abstract void printArea();
}

class Rectangle extends Shape {
	Rectangle(int l, int b) {
		l1=l;
		l2=b;
	}

	void printArea() {
		area = l1*l2;
		System.out.println("Area of rectangle = " + (int) area);
	}
}


class Triangle extends Shape {
	Triangle(int b, int h) {
		l1=b;
		l2=h;
	}

	void printArea() {
		area = 0.5*l1*l2;
		System.out.println("Area of triangle  = " +  area);
	}
}

class Circle extends Shape {
	Circle(int r) {
		l1=r;
		l2=0;
	}

	void printArea() {
		area = 3.14*l1*l1;
		System.out.println("Area of circle = " +  area);
	}
}

class Area {
	public static void main(String arg[]) {
		Scanner sm = new Scanner(System.in);
		System.out.println("Enter values for rectangle:");
		int a = sm.nextInt();
		int b = sm.nextInt();
		Rectangle rect = new Rectangle(a,b);
		System.out.println("Enter values for triangle:");
		a = sm.nextInt();
		b = sm.nextInt();
		Triangle tri = new Triangle(a,b);
		System.out.println("Enter values for circle:");
		a = sm.nextInt();
		Circle cir = new Circle(a);
		rect.printArea();
		tri.printArea();
		cir.printArea();
	}
}

