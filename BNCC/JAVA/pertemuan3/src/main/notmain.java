package main;

import java.util.ArrayList;
import java.util.Scanner;

public class notmain {
	ArrayList<String> itemList = new ArrayList<>();
	Scanner scan = new Scanner(System.in);
	int choice = 0;
	
	public notmain() {
		
		do {
			System.out.println("Aplikasi Gudang");
			System.out.println("---------------");
			System.out.println("1. Tambah barang");
			System.out.println("2. Display Barang");
			System.out.println("3. Update Barang");
			System.out.println("4. Delete Barang");
			System.out.println("5. Exit");
			System.out.print(">> ");
			choice = scan.nextInt();
			scan.nextLine();
			switch (choice) {
			case 1: {
				System.out.println("Masukkan nama barang: ");
				String barang = scan.nextLine();
				itemList.add(barang);
				System.out.println("Barang berhasil dimasukkan\n");
				break;
			}
            case 2: {
                display();
                System.out.println("\n");

                break;
            }
            case 3: {
            	display();
            	
            	System.out.println("\n");
            	System.out.println("Masukkan nomor barang yang ingin di update: ");
            	int nomor = scan.nextInt();
            	scan.nextLine();
            	
            	System.out.println("Masukkan barang baru: ");
            	String barangBaru = scan.nextLine();
            	
            	itemList.set(nomor, barangBaru);            	
            	
            	break;
            }
            case 4: {
            	System.out.println("Daftar barang dalam gudang\n");
            	
            	for (int i = 0; i < itemList.size(); i++) {
            		System.out.println(itemList.get(i));
            	}
            	
            	System.out.println("\n");
            	
            	System.out.println("Masukkan nomor barang yang ingin di delete: ");
            	int nomor2 = scan.nextInt();
            	scan.nextLine();
            	
            	itemList.remove(nomor2 - 1);
            	System.out.println("Item berhasil di delete");
            	break;
            }
            // Add a case for option 3 if needed
         }
			//Ulang selama choice 1 - 4
		} while(choice < 5 && choice > 0);
	}
	
	public void display() {
		System.out.println("Daftar barang dalam gudang\n");

        for (int i = 0; i < itemList.size(); i++) {
            System.out.println(itemList.get(i));
        }
	}

	public static void main(String[] args) {
		new notmain();

	}
}
