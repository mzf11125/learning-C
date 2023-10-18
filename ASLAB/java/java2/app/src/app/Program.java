package app;
import java.lang.String;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.File;

public class Program {
	public Scanner s = new Scanner(System.in);
	public Program() {
		readFile();
		writeFile();
		s.close();
	}
	
	public void readFile() {

		try {
//			1.Kita buat referensi filenya dulu
			File file = new File("src/accounts.txt");
			Scanner fscan = new Scanner(file);
			while (fscan.hasNextLine()) {
				String data = fscan.nextLine();
				System.out.println(data);
			}
			fscan.close();
		} catch (Exception e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
		}
		
	}
	
	public void writeFile() {

		try {
//			1. Kita perlu path menuju file kita
			String path = "src/accounts.txt";
			
//			Untuk tulis file
			FileWriter fw = new FileWriter(path, true);
//			Untuk menulist file dalam beberapa file tertentu
			BufferedWriter bw = new BufferedWriter(fw);
//			Supaya kita bisa menggunakan printlmn() di dalam
			//FileWrite
			PrintWriter pw = new PrintWriter(bw);
			
			String username = "";
			String password = "";
			
			System.out.print("name: ");
			username = s.nextLine();
			
			System.out.print("Password: ");
			password = s.nextLine();
			
			pw.printf("%s#%s\n", username, password);
			pw.close();
			System.out.println("Account saved succesfully");
		} catch (Exception e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new Program();
	}

}

//Vector vs Arraylist
//Vector => Thread save - 2 path
//Vector > Array List
//Thread 
//Multi threading - Vector
//Simple - ArrayList
// Array list - not thread sav

