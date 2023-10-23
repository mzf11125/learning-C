package javah6;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {


	public Main() throws Exception{
		//Aplikasi kalkulator
		Scanner scan = new Scanner(System.in);
		int a = 0, b = 0;
		try {
			a = scan.nextInt();
			scan.nextLine();		
			b = scan.nextInt();
			scan.nextLine();
			
			System.out.println(a + " / " + b + " = " + a/b);
		} catch (InputMismatchException r) {
			// TODO Auto-generated catch block
//			e.printStackTrace();
			}catch (ArithmeticException e) {
				System.out.println("A numbere cannot be divided!");
		}finally {
			System.out.println("Done");
		}
		
		if(a<5) {
			throw new ArithmeticException("A thidak boleh lebih kecil darpiada lima");
		}
//		close(scan);
		func1();

		
//		String s = null;
//		int[] arr  =  new int[10];
//		arr[11] = 1;		
	}
	
	public void func1() throws Exception{
		System.out.println(1/0);
		
	}
	
	


	public static void main(String[] args) {
		try {
			new Main();
		} catch (Exception e) {
			// TODO Auto-generated catch block
//			e.printStackTrace();
		}
	}

}

//Runtime exception
//Exception
//Exception handling
//Try 
