package main;

public class Main {

	private final int MAX_HEALTH = 100;	
	
	public Main() {
		
		MAX_HEALTH = 50;
		
		System.out.println("Hello Wolrd!");
		Manusia orang1 = new Manusia("John Doe", 26, "Laki-laki");
		
//		orang1.nama = "John Doe";
//		orang1.umur = 26;
//		orang1.gender = "Laki-laki";
		orang1.setNama("Rainer");
		System.out.println(orang1.getNama());
		
		Mahasiswa mahasiswa1 = new Mahasiswa("Rainer", 19, 21323182,"Laki-laki");
		mahasiswa1.perkenalanDiri();
		
		//Final variable
		final double pi = 3.14;
		pi = 0;
	
	}
		
	public static void main(String[] args) {
		new Main();
	}

}
