public class Day1_7307822 {

    // 1-7307822-Ashna Nizar


        //Question A - Function that returns sum of all even numbers in an array
        public static int sumOfEven(int[] arr) {
            int sum = 0;

            for (int i : arr) { //for loop to go through array
                sum += i % 2 == 0 ? i : 0; //adding i to the sum if i%2 ==0, else adding 0 to the sum
            }
            return sum;
        }


        public static void main(String[] args) {

            //Sum of all even elements in an array
            int[] arr = {100, 167, 54, 32};
            System.out.println(sumOfEven(arr));


        }
    }


