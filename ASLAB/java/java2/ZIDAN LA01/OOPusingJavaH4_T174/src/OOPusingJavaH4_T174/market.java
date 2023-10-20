package OOPusingJavaH4_T174;

public class market extends Main{
	private String username;
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	
	public void marketMenu(){
		try {
			int input;
			do {
				System.out.println("        Hello,"+this.username+"\r\n" + 
						"        =====================\r\n" + 
						"        1. Add Product to Cart\r\n" + 
						"        2. Product List\r\n" + 
						"        3. Your Cart\r\n" + 
						"        4. Checkout\r\n" + 
						"        5. Logout"); 
				System.out.print("        >> ");
				input = scan.nextInt();
				switch(input) {
				case 1:
					
					break;
				case 2:
					
				
				}
			}while(input <= 3 && input >= 1 || input > 3 || input < 1);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
