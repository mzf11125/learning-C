package main;
import java.awt.Color;
import java.awt.Font;
import java.text.DecimalFormat;
import java.util.Scanner;

import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

/* JAVA PROGRAMMING EXERCISE:
 * An ABC company's standard work week is 40hours, any time that exceeds 
 * 40hours is considered overtime and employee's earn 1.5 times the hourly rate. 
 * Create a Java Application program named EmployeeSalaryCalculator
 * that will prompt the user to enter an employee ID, employee name, 
 * total number of hours work in a week and their hourly rate per hour in a
 * console window.
 * Your Program then compute and print the WEEKLY PAYROLL REPORT 
 * in Console Window (Column Format) with the following:
 * employee ID, employee name,hours worked, hourly rate, basic pay, 
 * number of hours overtime, overtime rate, overtime pay, and gross salary,  
 * Print also the Employee's PaySlip in a TextArea attached to a message dialog.
 */
public class Main {

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		JTextArea myArea = new JTextArea(15,15);
		DecimalFormat f = new DecimalFormat("P0,000.00");
		
		//Variable Declaration
		final int STANDARD_WORK=40;
		String empId;
		String empName;
		double hoursWorked;
		double hourlyRate;
		double basicPay=0;
		double overTime=0;
		double overTimeRate=0;
		double overTimePay=0;
		double grossSalary=0;
		
		//Input Statements
		System.out.print("Enter an Employee ID: ");
		empId = keyboard.nextLine();
		
		System.out.print("Enter an Employee Name: ");
		empName = keyboard.nextLine();
		
		System.out.print("Enter the no. of Hours Worked: ");
		hoursWorked = keyboard.nextDouble();
		
		System.out.print("Enter the Hourly Rate: ");
		hourlyRate = keyboard.nextDouble();
		
		//Process
		if(hoursWorked <= STANDARD_WORK) {
			
			basicPay = hoursWorked * hourlyRate;
			grossSalary = basicPay;
		}
		else {
			basicPay = STANDARD_WORK * hourlyRate;
			overTime = hoursWorked - STANDARD_WORK;
			overTimeRate = hourlyRate * 1.5;
			overTimePay = overTimeRate * overTime;
			grossSalary = basicPay + overTimePay;
		}
		
		
		//Print Payroll Report
		System.out.println();
		System.out.printf("%45s\n","ABC COMPANY");
		System.out.printf("%50s\n\n","WEEKLY PAYROLL REPORT");
		System.out.printf("%-8s%-12s%-8s%-6s%-6s%-8s%-11s%-11s%-11s\n", 
				"EmpID","EmpName","HWorked","HRate","OT","OTRate","OTPay","BasicPay",
				"GrossSalary");
		System.out.printf(
				"%-8S%-12S%-8.1f%-6.1f%-6.1f%-8.1fP%,-11.2fP%,-11.2fP%-,11.2f", 
					empId,empName,hoursWorked,hourlyRate,overTime,overTimeRate,
					overTimePay,basicPay,grossSalary);
		
	}//end of main

}//end of class