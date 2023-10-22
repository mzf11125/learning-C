package auth;

public class login extends Authmain{
	
	protected String username;
	protected String password;

	public login(String username, String password) {
		super(username, password);
		this.username = username;
		this.password = password;
	}
}
