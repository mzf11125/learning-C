package main;


import java.util.Scanner;
import java.

public class variables {
	Scanner scan = new Scanner(System.in);
	protected String name;
	protected String surname;
	protected String reginumber;
	protected String position;
	protected int startyear;
    protected double salary;
	public variables(String name, String surname, String reginumber, String position, int startyear, double salary) {
		super();
		this.name = name;
		this.surname = surname;
		this.reginumber = reginumber;
		this.position = position;
		this.startyear = startyear;
		this.salary = salary;
	}






  
	 
    
    
    
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getSurname() {
		return surname;
	}





	public void setSurname(String surname) {
		this.surname = surname;
	}





	public String getReginumber() {
		return reginumber;
	}





	public void setReginumber(String reginumber) {
		this.reginumber = reginumber;
	}





	public String getPosition() {
		return position;
	}





	public void setPosition(String position) {
		this.position = position;
	}





	public int getStartyear() {
		return startyear;
	}





	public void setStartyear(int startyear) {
		this.startyear = startyear;
	}





	public double getSalary() {
		return salary;
	}





	public void setSalary(double salary) {
		this.salary = salary;
	}





	public variables() {
		// TODO Auto-generated constructor stub
		

	}

}
