package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
			logic lol = new logic();

			while (true) {
			    System.out.println("===== PT ChipiChapa Menu =====");
			    System.out.println("1. Insert Data Karyawan");
			    System.out.println("2. View Data Karyawan");
			    System.out.println("3. Update Data Karyawan");
			    System.out.println("4. Delete Data Karyawan");
			    System.out.println("5. Keluar");
			    System.out.print("Pilih menu: ");

			    int choice = input.nextInt();
			    input.nextLine();

			    switch (choice) {
			        case 1:
			            lol.insertDataKaryawan();
			            break;
			        case 2:
			            lol.viewDataKaryawan();
			            break;
			        case 3:
			            lol.updateDataKaryawan();
			            break;
			        case 4:
			            lol.deleteDataKaryawan();
			            break;
			        case 5:
			            System.out.println("Terima kasih telah menggunakan layanan PT ChipiChapa.");
			            System.exit(0);
			        default:
			            System.out.println("Pilihan tidak valid. Silakan pilih menu yang tersedia.");
			    }
			}
		}
    }
}
