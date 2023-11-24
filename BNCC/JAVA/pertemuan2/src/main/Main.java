package main;

import java.util.Random;
import java.util.Scanner;

public class Main {

	public Main() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		stringManipulation();
		mathFunction();
	}
	
	
	public static void mathFunction() {
		//math.sqrt --> akar kuadrat
		double akar = Math.sqrt(5.5);
		System.out.println(akar);
		
		
		//Math.pow(--> pangkat
		double pangkat = Math.pow(4, 2);
		System.out.println(pangkat);
		
		//Math.cell --> membulatkan ke atas
		double ceil = Math.ceil(3.45);
		System.out.println(ceil);
		
		//Math.floor --> Membulatkan ke bawah
		double floor = Math.floor(3.45);
		System.out.println(floor);
		
		//Math.round --> Membulatkan biasa
		double round = Math.round(3.45);
		System.out.println(round);
		
		//Math.rin --> mereturn angka bulat yang terdekat
		double rint = Math.rint(3.45);
		System.out.println(rint);
		
		//Trigonometri
		double radian = Math.toRadians(30);
		
		double sin = Math.sin(radian);
		System.out.println(sin);
		
		double cos = Math.cos(radian);
		System.out.println(cos);
		
		double tan = Math.tan(radian);
		System.out.println(tan);
		
		//Math.random --> Return angka random dari 0.0 - 1.0
		double rand = Math.random();
		System.out.println("random (0.0 - 20.0): " + rand);
		
		//Angka random dari 0 - 20
		double rand2 = Math.random() * 20;
		System.out.println("angka random (0 - 20): " + rand2);
		
		//Angka random dari 5 - 20 (angka kali dikurang angka minimum)
		double rand3 = Math.random() * 15 + 5;
		System.out.println("angka random (0 - 20): " + rand3);
		
		//Angka bulat dari 5 - 20
		int rand4 = (int)(Math.random() * 16 + 5);//Angka kali + 1
		System.out.println("angka bulat random (5 - 15): " + rand4); //Buletin ke bawah
		
		Random random = new Random();//Using library
		System.out.println(random.nextInt(20));
		
	}
	
	public static void stringManipulation () {
		String string = "BNCC, Java!";
		//str.length() --> Mengembalikan panjang karakter dari string
		System.out.println(string.length());
		
		if(string.length() > 10) {
			System.out.println("String lebih panjang dari 10");
		}
		
		//str.startsWith() --> Mengecek dimulai dengan prefix spesifik
		System.out.println(string.startsWith("BNCC ,"));
		
		if (string.startsWith("BNCC , "))	{
			System.out.println("String valid");
		}
		
		//str.ednsWith() --> Cek for end
		System.out.println(string.endsWith("@gmail.com"));
		
		if (string.endsWith("@gmail.com")) {
			System.out.println("Email is valid");
		}
		else {
			System.out.println("Email is invalid");
		}
		
		
		//str.equals --> mengecek apakah string sama
		System.out.println(string.equals("BNCC, Java!"));
		
		Scanner scan = new Scanner(System.in);
		
		String rasa;
		do {
			System.out.println("Masukkan rasa ice cream (Vanilla / Coklat: )");
			rasa = scan.nextLine();
		} while (!(rasa.equals("Vanilla") || rasa.equals("Coklat")));
		
		
		//str.lowercase --> Change string to lowercase
		System.out.println(string.toLowerCase());
		
		//str.uppercase --> Change string to uppercase
		System.out.println(string.toUpperCase());
		
		//str.contains --> check if a string contains. Char sequence / string spesifik
		System.out.println(string.contains("c, J"));
		
		if (string.contains(" ")) {
			System.out.println("String ada spasi");
		}
		
		//str.concat() --> Menggabungkan string akhir dari string awal
		System.out.println(string.concat(" F").concat(" 2023"));//For bigger string
		System.out.println(string + " F" + " 2023");//Easier to read
		
		
		//str.substring --> Mengambil beberapa karakter spesifik dari string
		System.out.println(string.substring(6));
		System.out.println(string.substring(0, 4));

		
	}
}
