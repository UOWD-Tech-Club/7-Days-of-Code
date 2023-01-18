public class ArrayListSum {
    
    static double sumarraylist(double arr[]){
        double sum = 0;
        
        for (Double double1 : arr) {
            if(double1%2==0){
                sum+=double1;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        double arrDouble[] ={1,23,4,52,6};
        System.out.println(sumarraylist(arrDouble));
    }
}
