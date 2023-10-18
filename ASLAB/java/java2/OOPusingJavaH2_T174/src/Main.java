
import java.lang.String;
import java.util.Scanner;
//import java.io.BufferedWriter; 
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.File;

public class Main {
	private char[][] maze;
	int width, height;
	public Scanner s = new Scanner(System.in);
	public Main() {
		mainMenu();
		s.close();
	}
	
	
	public void editMaze() {
        int choice = 0;

        do {
            System.out.println("Edit Maze Page");
            System.out.println("1. View Maze");
            System.out.println("2. Create New Maze");
            System.out.println("3. Edit Current Maze");
            System.out.println("4. Save And Exit");
            System.out.print("Input [1-4]: ");

            if (s.hasNextInt()) {
                choice = s.nextInt();

                switch (choice) {
                    case 1:
//                        viewMaze();
                        break;
                    case 2:
//                        createNewMaze();
                        break;
                    case 3:
//                        editCurrentMaze();
                        break;
                    case 4:
//                        saveMaze("maze.txt");
                        return;
                    default:
                        break;
                }
            } else {
                continue;
            }
        } while (choice < 1 || choice > 4);
    }
	
	public void traceMaze() {
		readFile();
	}
	
//	public 
	public void readFile() {

		try {
			File file = new File("src/maze.txt");
			Scanner fscan = new Scanner(file);
			
			System.out.println("Clear current maze layout? [y/n] (case sensitive): ");
			String input = s.next(); 
			
			switch (input) {
            case "y":
                break;
            case "n":
                System.exit(0); 
                }
			width = fscan.nextInt();
			System.out.println();
            height = fscan.nextInt();
			for (int i = 0; i < height; i++) {
	               String line = fscan.next();
	               maze[i] = line.toCharArray();
	           }
			fscan.close();
		} catch (Exception e) {}
		
	}
	
	public void writeFile() {

		try {

			String path = "src/maze.txt";
			
			FileWriter fw = new FileWriter(path, true);

			PrintWriter pw = new PrintWriter(fw);

			pw.printf("%d %d\n", width, height);
			
			 for (int i = 0; i < height; i++) {
	                pw.println(new String(maze[i]));
	         }

	            pw.close();
	            System.out.println("Maze saved successfully");
	        } catch (Exception e) {

		}
	}
	
	public void Exit() {
        System.exit(0);
    }
	
	public void mainMenu() {
		int input;
		do {
			System.out.println("1. Admin\n"
					+ "2. Customer\n"
					+ "3. Exit");
			input = s.nextInt();
			s.nextLine();
			
			switch(input) {
			case 1:
					editMaze();
					break;
			case 2:
					traceMaze();
					break;
			case 3: 
					Exit();
					break;
			}
		}while(input != 3); 
	}
	
	public static void main(String[] args) {
		new Main();
	}

}
