package main;

import java.util.Random;
import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	Scanner scan = new Scanner(System.in);
	Random rand = new Random();
	
	//Constructor
	public Main() {
		//1. Print Format
//		int value = 20;
//		System.out.printf("Value: %d\n", value);
		//2. Print line
//		System.out.println("Value: " + value);
		//3. Print
//		System.out.print("Hello");
//		int angka;
//		System.out.print("Masukkan Angka: ");
//		angka = scan.nextInt();
//		scan.nextLine();
//		System.out.println("Angka: " + angka);
		
		//Data Type: Primitive And Non Primitive
		//Primitive
		// Integer -> Bilangan Bulat
		// Character -> Huruf
		// Boolean -> Validasi
		// Float -> Bilangan Desimal
		// Double -> Bilangan Desimal (Size Lebih Besar)
		// Non Primitive
		// (S)tring -> Kalimat
		// (I)nteger -> Angka Wrapper
		// (C)haracter -> Huruf Wrapper
		// (D)ouble -> Bilangan Desimal Wrapper
		
//		String kalimat = "Halo";
		// equals -> Validation Of Two String
//		System.out.println(kalimat.equals("Hello"));
		//Length -> Validation Of Size String
//		System.out.println(kalimat.length("Hello"));
	
		//Convert Data Type
//		int angka;
//		double angkaBerkoma = 10.2;
//		angka = (int)angkaBerkoma;
	
	//String To Integer Or Integer To String
//		String s = "2000";
//		int angka = Integer.parseInt(s);
//		System.out.println(angka);
	
//		int angka = 2000;
//		String s = Integer.toString(angka);
//		System.out.println(s);
//		
//		char huruf = 'A';
//		int ascii = huruf;
//		System.out.println(ascii);
		
//		String kalimat;
//		kalimat = scan.next();
//		System.out.println(kalimat);
//		
//		mainMenu();
		
		//ARRAY
//		System.out.println("Array");
//		int[] arr = new int[3];
//		System.out.println("Size : " + arr.length);
//		System.out.println(arr[0]);
//		
//		System.out.println("");
//		
//		System.out.println("list");
//		// Java Collection (Vector/Array List)
//		Vector<Integer> list = new Vector<>();
//		// Add Element
//		list.add(10);
//		list.add(2000);
//		list.add(30000);
//		System.out.println("Size : " + list.size());
//		//Get Index
//		System.out.println(list.get(0));
//	
//		// Delete Index
//		list.remove(1);
//		System.out.println("");
//		System.out.println("New Size : " + list.size());
//		
//		//Print All Element
//		System.out.println(list);
//		
//		//Print All Element Using For Loop
//		for(int i = 0; i < list.size(); i++) {
//			System.out.println(list.get(i));
//		}
		
//		int angkaRandom = rand.nextInt(20 - 10 + 1) + 10;
//		System.out.println();
		
		//Generate ID (ID[0-9][0-9][0-9])
//		String id = String.format("ID%d%d%d", rand.nextInt(10), rand.nextInt(10), rand.nextInt(10));
//		System.out.println(id);

		Vector<Vector<Object>> tableList = new Vector<Vector<Object>>();
		
		Vector<Object> list = new Vector<>();
		list.add("Budi");
		list.add(2000);
		
		tableList.add(list);
//		list.removeAllElements();
		
		Vector<Object> list2 = new Vector<>();
		list2.add("Andi");
		list2.add(1000);
		
		tableList.add(list2);
		
		System.out.println(tableList.get(0));
		
		for(int i = 0; i < tableList.size(); i++) {
			Vector<Object> list = new Vector<>();
			list.add("Budi");
			list.add(1000);
			System.out.println(i);
			System.out.println(tableList.get(i));
		}
		for(int i = 0; i < tableList.size(); i++) {
			System.out.println(i);
			System.out.println(tableList.get(i));
		}

		
		
	
	}
		
	void admin() {
		
		int input = -1;
		do {
			System.out.println("1.Insert\n2.Delete\n3.Back");//display menu
			input = scan.nextInt();
			scan.nextLine();
			
			switch(input) {
			case 1:
					break;
			}
			
		}while(input != 3); //0 ini diganti dengan exit
	}
		void customer() {
			
			int input = -1;
			
			do {
				System.out.println("1.Buy\n2.Back\n");//display menu
				input = scan.nextInt();
				scan.nextLine();
				
				switch(input) {
				case 1:
						break;
				}
				
			}while(input != 2); //0 ini diganti dengan exit
		}
	
	void mainMenu() {
		int input = -1;
		do {
			System.out.println("1. Admin\n2. Customer\n3. Exit");//display menu
			input = scan.nextInt();
			scan.nextLine();
			
			switch(input) {
			case 1:
				admin();
					break;
			case 2:
				customer();
					break;
			}
			
		}while(input != 3); //0 ini diganti dengan exit
	}
	
	void template() {
		int input = -1;
		do {
			System.out.println("");//display menu
			scan.nextInt();
			scan.nextLine();
			
			switch(input) {
			case 1:
				
					break;
			}
			
		}while(input != 0); //0 ini diganti dengan exit
	}
	//Starting Point
	public static void main(String[] args) {
		new Main();
	}

}
