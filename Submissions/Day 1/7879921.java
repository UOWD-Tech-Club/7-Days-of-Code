// Author: 7879921

public class Q1A {
    public static void main(String[] args) {
        int [] arr = {1,2,3,4,5,6,7,8,9,10};
        Q1A i = new Q1A();
        System.out.println(i.sumEvennumbers(arr));

    }

    public int sumEvennumbers(int [] arr){
        int sum = 0;
        for(int num :arr){
            if(num%2 == 0){
                sum += num;
            }
        }
        return sum;
    }
}