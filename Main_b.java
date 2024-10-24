import java.util.Scanner;

class Book {
    String name, auth;
    float price;
    int pg_num;
    
    Book(String name, String auth, float price, int num) {
        this.name = name;
        this.auth = auth;
        this.price = price;
        pg_num = num;
    }
    
    public String toString() {
        return "Book Name: " + name + "\nAuthor: " + auth + "\n Price: " + price + "\nPages: " + pg_num;
    }
}

class Main_b {
    public static void main(String xx[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of books: ");
        int n = sc.nextInt();
        Book[] books = new Book[n];
	String name, auth;
	float price;
	int num;
        
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for book " + (i + 1) + ":");
            System.out.print("Name: ");
            name = sc.next();
            System.out.print("Author: ");
            auth = sc.next();
            System.out.print("Price: ");
            price = sc.nextFloat();
            System.out.print("Number of Pages: ");
            num = sc.nextInt();
            
            books[i] = new Book(name, auth, price, num);
        }
        
        for (int i = 0;i<n;i++) {
            System.out.println(books[i]);
        }
    }
}
