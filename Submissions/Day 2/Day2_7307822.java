import java.util.ArrayList;

public class Day2_7307822 {

    // 1-7307822-Ashna Nizar

    //Question A -WAF that returns a new list with all integers that are prime numbers

    public static ArrayList<Integer> primeNumbers(int[] nums) {

        ArrayList<Integer> primes=new ArrayList<Integer>(); //List to store prime numbers
        boolean isprime;
        for (int i : nums) { 
            isprime = true;
            for (int j = 2; j <= i / 2; j++) {  //for loop to check if it has any factors from 2 till i/2

                if (i % j == 0) {
                    isprime = false;
                    break;
                }
            }
            if (isprime) {
                primes.add(i); //if isprime is still true add the element to the primes list
            }
        }
        return primes;

    }


    public static void main(String[] args) {

        int[] arr = {10, 7, 53, 31};
        ArrayList<Integer> primeList=primeNumbers(arr);
        for(int i:primeList){
            System.out.println(i);
        }


    }

}

