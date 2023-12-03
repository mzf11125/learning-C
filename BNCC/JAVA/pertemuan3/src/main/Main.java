//package main;
//
//import java.util.ArrayList;
//
////Array, array_list, vector
//
//
//public class Main {
//
//	public Main() {
//		//Static Array
//		
//		//Ways to declare array
//		//Cara 1
//		String[] makanan = {"Burger", "Hotdog", "Spaghetti", "Indomie", "Nasi Goreng"};
//		System.out.println(makanan.length);
//		
//		//cara 2
//		
//		String[] makanan2;
//		
//		makanan2 = new String[]{"Burger", "Hotdog", "Spaghetti", "Indomie", "Nasi Goreng"};
//		System.out.println(makanan2);
//		
//		//Cara 3
//		String[] makanan3 = new String[5];
//		makanan3[0] = "Burger"; 
//		makanan3[1] = "Hotdog"; 
//		makanan3[2] = "Spaghetti"; 
//		makanan3[3] = "Indomie"; 
//		makanan3[4] = "Nasi Goreng"; 
//
//		//print isi menggunakan for loop 
//		for (int i = 0; i < makanan3.length; i++) {
//			System.out.println(makanan3[i]);
//		}
//		
//		//Dynamic Array
//		
//		//Cara deklarasi arraylist
//		
//		
//		ArrayList<String> barang = new ArrayList<>();
//		
//		//Cara menambah item ke dalam array list
//		
//		barang.add("Lemari");
//		barang.add("Jendela"); //Sebelum update
//		
//		System.out.println(barang);
//		
//		//Mengubah value
//		
//		barang.set(0, "Kursi");
//		System.out.println(barang); // setelah update
//		
////		cara mengambil value dari arraylist
//		
//		System.out.println(barang.get(2));
//		System.out.println(barang);//Sebelum di hapus
//		
//		
//		//Cara mengapus value
//		barang.remove(barang.size()-1);
//		System.out.println(barang);//Setelah di remove
//		
//		
//		System.out.println(barang);//Sebelum di clear
//		//Clear barang
//		barang.clear();
//		System.out.println(barang);//barang setelah di clear
//		
//
//		
//		
//	}
//
//	public static void main(String[] args) {
//		new Main();
//
//	}
//
//}
