package main;

import java.io.InputStream;
import java.util.Scanner;

public class Main {

	public static int nomor = 5;
	//Global variable
	int a = 10;
	
	static Scanner scan = new Scanner(System.in);
	
	public Main() {
		
//		System.out.println("Hello world!");
//		primitive data
//		int whatisthis = angkabulat%10;
		int angkabulat = 5;
		double angkadesimal = 3.1415;
		char karakter = 'a';
		boolean kondisi = 10 == 8;
//		System.out.println(whatisthis);
		
		//Wrapper class
		Integer wrapInt;
		Double wrapDouble;
		Character wrapChar;
		Boolean wrapBool;
		formulir();

		
//		System.out.println(kondisi);
//		System.out.println(angkadesimal);
//		System.out.println(kondisi);
//		System.out.println(angkabulat + "%-10" + angkadesimal);
//		saya ubah;
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

}
