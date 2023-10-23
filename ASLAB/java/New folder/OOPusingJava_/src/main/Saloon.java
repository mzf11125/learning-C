package main;

public class Saloon {
	protected String username;
	protected int money;  
	protected int score;
	public Saloon(String username, int money, int score) {
		super();
		this.username = username;
		this.money = money;
		this.score = score;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public int getMoney() {
		return money;
	}
	public void setMoney(int money) {
		this.money = money;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}
}
