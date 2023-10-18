package tutorial_2;
import java.util.function.*;
import java.util.Scanner;
import java.lang.String;

public class Main {
	//Function
	//Method
	//Recursive
	
	//File I/O

	// Constructor 
	
//	void printhello() {
////		main(args);
//		Scanner scan = new Scanner(System.in);
//		String s = scan.next();
//		System.out.println(s);
//	}
	//Constructor
	public Main() {
		System.out.println("Hello World!");
		printhelloworld();
		int result = max(3, 5);
		System.out.println(result);
		recursion(10);
		System.out.println("Aku udh slsai!");
		x = x + 20;
		System.out.println(x);
	}
	//1. Login
	//1.1 Home Page
	//1.2 Help page
	//2.Exit	
	int input = getInt(3,5);
	public int x = 20;
	public void printhelloworld() {
		System.out.println("Hello!");
	}
	
	public int max(int x, int y) {
		if (x>y) {
			return x;
		}
		else {
			return y;
		}
	}
	
	Scanner scanner = new Scanner(System.in);
	
//	DRY => Don't Repeat Yourself 
//	Kita mau input angka, inputnya itu di validasi, lalu di return
	public int getInt(int min, int max) {
		int output = min - 1;
		
		do{
			try {
				output = scanner.nextInt();
				scanner.nextLine();
			} catch (Exception e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
			}
		}
		while(output < min || output > min);
		
		
		return output;
	}
	
	public void recursion(int n) {
		n--;
		if(n>0) {
			System.out.println("Recursive!");
			recursion(n);
		}
//		recursion();
		
	}

	public static void main(String[] args) {
		new Main();

	}

}
