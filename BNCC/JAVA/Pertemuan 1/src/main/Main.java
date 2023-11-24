package main;

import java.io.InputStream;
import java.util.Scanner;

public class Main {

	public static int nomor = 5;
	// Global variable
	int a = 10;

	static Scanner scan = new Scanner(System.in);

	public Main() {

//		System.out.println("Hello world!");
//		primitive data
//		int whatisthis = angkabulat%10;
//		int angkabulat = 5;
//		double angkadesimal = 3.1415;
//		char karakter = 'a';
//		boolean kondisi = 10 == 8;
//		
//		long angkaLong = 9_000_000_000_000_000_000L;
//		
//		float angkaFloat = 3.1415F;
		
//		System.out.println(whatisthis);

		// Wrapper class
//		Integer wrapInt;
//		Double wrapDouble;
//		Character wrapChar;
//		Boolean wrapBool;
//		formulir();
		
//		System.out.println(kondisi);
//		System.out.println(angkadesimal);
//		System.out.println(kondisi);
//		System.out.println(angkabulat + "%-10" + angkadesimal);
//		saya ubah;
		
//		if(kondisi) {
//			System.out.println("Kondisi True");
//		}
//		else if(10 < 11) {
//			System.out.println("10 Kurang dari 11");
//		}
//		else{
//			System.out.println("kondisi false");
//		}
		
//		int choose = 0;
//		
//		System.out.println("Choose 1-3");
//		choose = scan.nextInt();
//		try {
//			switch (choose) {
//			case 1: {
//				
//				yield type;
//				
//				break;
//			}
//			case 2: {
//				
//				break;
//			}
//			default:
//				throw new IllegalArgumentException("Unexpected value: " + key);
//			}
//		} catch (Exception e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}

//		While loop
//		int i = 0;
//		while (i>10) {
//			System.out.print("While loop");
//			i++;
//		}
//		
//		int j = 0;
//		do {
//			System.out.println("Do While loop");
//			j++;
//		} while (j<10);
//		for(int k = 0; k < 10; k++) {
//			System.out.println("For loop");
//		}
		

		int choose = 0;
		System.out.println("Program cek angka");
		System.out.println("1. Input angka");
		System.out.println("2. Print hasil");
		System.out.println("3. Exit");
		choose = scan.nextInt();
		scan.nextLine();
		while (choose<=3 && choose >= 1) {
			try {
				switch (choose) {
				case 1: {
					System.out.println("Masukan angka genap");
					int angka = scan.nextInt();
					cekAngka();
					break;
				}
				case 2: {
					
					break;
				}
				case 3: {
					System.exit(0);
					break;
				}
				default:
					throw new IllegalArgumentException("Unexpected value: " + choose);
				}
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		new Main();

	}

	public void formulir() {
		System.out.print("Masukan nama mu: ");
		String nama = scan.nextLine();
		System.out.print("Masukan umur mu: ");
		int umur = scan.nextInt();
		scan.nextLine();
		System.out.println("Halo " + nama + ", selamat sepuh sudah berumur " + umur + " tahun");
	}

	public void methodA() {
		int a = 8;
		this.a = 5;
		methodB();
	}

	public void methodB() {
		a = 1;
	}
	
	public void cekAngka() {
		
		
	}
	
	

}
