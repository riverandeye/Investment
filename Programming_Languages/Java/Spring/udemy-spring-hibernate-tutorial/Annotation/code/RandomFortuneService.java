package annotation;

import java.util.Random;

import org.springframework.stereotype.Component;

@Component
public class RandomFortuneService implements FortuneService {

	private String[] data = {
			"You are lovely!",
			"You are Miserable!",
			"You will Die Soon",
	};
	
	private Random myRandom = new Random();
	
	@Override
	public String getFortune() {
		return data[myRandom.nextInt(data.length)];
	}

}
