package auth;

public class logout extends Authmain{

	protected String username;
	protected String password;
	
	public logout(String username, String password) {
		super(username, password);
		this.username = username;
		this.password = password;
	}

	
}
