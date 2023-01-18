//Day 1 - 7754292 - Nuraiman Hisham
//Question A

package TechClub;

public class sevenDayChallenge {
	
	
	public static int getEvenSum(int [] arr) {
		int sum=0;
		for(int i=0;i<arr.length;i++) {
			if(arr[i]%2==0) {
				sum=sum+arr[i];
			}
		}	
     return sum;	
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

//Question A: Write a function that takes returns sum of all even numbers in the list/array.	
		
		int [] arr = {1,2,3,4,5,6,7,8,9,10};
		int sum=getEvenSum(arr);
		System.out.println("Sum of Even Numbers = " + sum);

}}



