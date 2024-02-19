package main;
import java.util.Scanner;

public class Main {

	public static int nomor = 5;
	// Global variable
	int a = 10;

	static Scanner scan = new Scanner(System.in);

	public Main() {

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
