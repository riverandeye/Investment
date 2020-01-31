package springdemo;
 
import java.util.logging.ConsoleHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
 
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
 
public class MyLoggerConfig {
 
	private String rootLoggerLevel;
	private String printedLoggerLevel;
	
	public void setRootLoggerLevel(String rootLoggerLevel) {
		this.rootLoggerLevel = rootLoggerLevel;
	}
 
	public void setPrintedLoggerLevel(String printedLoggerLevel) {
		this.printedLoggerLevel = printedLoggerLevel;
	}
 
	public void initLogger() {
 
		// parse levels
		Level rootLevel = Level.parse(rootLoggerLevel);
		Level printedLevel = Level.parse(printedLoggerLevel);
		
		// get logger for app context
		Logger applicationContextLogger = Logger.getLogger(AnnotationConfigApplicationContext.class.getName());
 
		// get parent logger
		Logger loggerParent = applicationContextLogger.getParent();
 
		// set root logging level
		loggerParent.setLevel(rootLevel);
		
		// set up console handler
		ConsoleHandler consoleHandler = new ConsoleHandler();
		consoleHandler.setLevel(printedLevel);
		consoleHandler.setFormatter(new SimpleFormatter());
		
		// add handler to the logger
		loggerParent.addHandler(consoleHandler);
	}
	
}