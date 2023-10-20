package practiceproblem1;

import java.util.ArrayList;
import java.util.Scanner;

public class Main { 
	ArrayList<mahasiswa> datamahasiswa = new ArrayList<>();
	
	private void createmahasiswa() {
		// TODO Auto-generated method stub
		String nama;
		int umur;
		String nim;
		
		System.out.println("Nama: ");
		nama = scan.nextLine();
		
		System.out.println("Umur: ");
		umur = scan.nextInt();scan.nextLine();
		System.out.println("Nim: ");
		nim = scan.nextLine();
		
		datamahasiswa.add(new mahasiswa(nama, umur, nim));
	}
	
	Scanner scan = new Scanner(System.in);
	
	public void mainMenu() {
		int input;
		do {
			System.out.println("1. Create Mahasiswa");
			
			System.out.println("2. Print All");

			System.out.println("3. Exit");
			System.out.print(">> ");
			
			input = scan.nextInt(); scan.nextLine();
			switch(input) {
			case 1:
				createmahasiswa();
				break;
			case 2:
				printmahasiswa();
				break;
			case 3: 
				System.exit(0);
			}
		
		}while(input <= 3 && input >= 1 || input > 3 || input < 1);
	}
	
	public void printmahasiswa(){
		for(mahasiswa ms : datamahasiswa){
			System.out.println(ms.getNama() + "-" + ms.getUmur() + "-" + ms.getNim());
		}
		scan.nextLine();
		System.out.println("Press enter to continue................");
	}
	
	



//	System.out.println("Nama: ");
//	
//	System.out.println("Umur: ");
//	
//	
//	System.out.println("Nim: ");
//	
//	input = scan.nextInt();
//	
//	switch(input) {
//	case 1:
//		
//	}
	
	
	public Main() {
		mainMenu();
	}

	public static void main(String[] args) {
		new Main();
	}

}
