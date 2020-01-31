package springdemo;

public class CricketCoach implements Coach {

	private FortuneService fortuneService;
	private String emailAddress;
	private String team;
	
	public CricketCoach() {
		System.out.println("CricketCoach : No Args Constructor");
	}
	
	@Override
	public String getDailyWorkout() {
		return "Practice fast bowling for 15 minute";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

	// setter method
	public void setFortuneService(FortuneService fortuneService) {
		this.fortuneService = fortuneService;
	}
	
	public void setEmailAddress(String emailAddress) {
		this.emailAddress = emailAddress;
	}
	
	public void setTeam(String team) {
		this.team = team;
	}
	
	public void getTeamAndEmailAddress() {
		System.out.println("Email : " + this.emailAddress);
		System.out.println("Team : " + this.team);
	}
}
