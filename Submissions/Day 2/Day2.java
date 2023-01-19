//Day2-7754292-Nuraiman
//Question B

import java.util.Scanner;

public class Day2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	Scanner sc = new Scanner(System.in);
	
	System.out.println("WELCOME TO THE GAME OF MAD LIBS");
	
	System.out.println("In total there are 18 inputs to be entered by the user. Hope you have fun!");
	
	
	System.out.println("\n1) Enter boy or girl");
	String gender = sc.next();
	
	System.out.println("2) Enter a name");
	String name1 = sc.next();
	
	System.out.println("3) Enter a friends name");
	String name2 = sc.next();
	
	System.out.println("4) Enter a type of public transport");
	String transport = sc.next();
	
	System.out.println("5) Enter a food you eat for breakfast");
	String food = sc.next();
	
	System.out.println("6) Enter an emotion");
	String emotion = sc.next();
	
	System.out.println("7) Enter the name of a restaurant");
	String restaurant = sc.next();
	
	System.out.println("8) Enter the name of a meal");
	String meal1 = sc.next();
	
	System.out.println("9) Enter a choice of drink");
	String drink1 = sc.next();
	
	System.out.println("10) Enter the name of the 2nd meal");
	String meal2 = sc.next();
	
	System.out.println("11) Enter the name of the 2nd drink");
	String drink2 = sc.next();
	
	System.out.println("12) Enter the name of a dessert");
	String dessert = sc.next();
	
	
	System.out.println("13) Enter a type of penalty for not having enough money to pay for food (2 words-verb + noun)");
	String penalty = sc.next();
	String penalty2 = sc.next();
	
	System.out.println("14) Enter what you usually see in school");
	String people = sc.next();

	
	
	
	
	Scanner sc2 = new Scanner (System.in);
	
	System.out.println("15) Enter an amount of money");
	int money = sc2.nextInt();
	
	System.out.println("16) Enter a number (time-hours)");
	int time = sc2.nextInt();
	
	System.out.println("17) Enter a random number");
	int n = sc2.nextInt();
	
	System.out.println("18) Enter a number (time-mins)");
	int i = sc2.nextInt();
	
	
	
	
	System.out.println("Once upon a time, there was a " + gender +  " named " + name1 + " and he had a friend named " + name2 + " who was his roommate. "
			+ "\n        They were headed to school like any other day and decided to use the " + transport + " as it was raining heavily. " + 
			"\n Before going out, they decided to eat out even though they already ate " +  food  + " at home, as " + name1 +" sensed that his friend was " + emotion + " hearing " + name2 + "'s stomach grumble. "
					+ "\n They decided to  stop by " + restaurant + " to buy some food."+  name1 + " ordered " + meal1 + " with " + drink1 + " while "  + name2  + " ordered " + meal2 + " with " + drink2 + ". "
							+ name2 + " suggested getting dessert as a second round as he was still hungry and so they ordered " + dessert +  ". \n The bill came and they were astonished! They were short by " + money + " dhs-what had they ordered? The cashier gave them one choice. "
									+ " And that was to " + penalty + " " + penalty2 + ".\n And so with no other option they did.... They realised they had spent " +  time + " hours at the restaurant and rushed to the metro as their classes starts at 8:30. "
											+ "\n To " + name1 +  "'s realisation he had forgotten his nol card at home - another tragedy befalled upon them. "
													+ "\n They had no time to lose, neither the money to use and so they contemplated on their options. "
													+ "\n Thats when " + name2 + " realised  - he could fit " + name1 + " into his backpack and no one would know - after all their stop was " +  n + " stations away- internet city. "
															+ "\n Luck was on their side this time as their  plan worked out as they reached school with " +  i +  " minutes to go spare before class started, though drenched in the rain. "
																	+ " \n But - to their devastation the school was eerily quiet, no sight of teachers nor " + people + ". \nThey stood infront of the school doors taken aback.\n The realisation hit them slow but hard- today was a weekend and they could have slept in. The end.");
	
	
}}
