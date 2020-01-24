import java.util.*;
import java.lang.*;
import java.io.*;

class Singleton {
	/*
	  1. If the instance variable was not static, a new object would be created everytime.
	  2. For safety we’d also make the constructor private to ensure the class could not be created externally via new.
	 */
	private static Singleton instance = null;
	private Singleton() {
		
	}
	public static Singleton getInstance() {
		if(instance == null) {
			instance = new Singleton();
		}
		return instance;
	}
}

public class Main {
	public static void main (String[] args) {
		Singleton x = Singleton.getInstance();
        	Singleton y = Singleton.getInstance();
	}
}
