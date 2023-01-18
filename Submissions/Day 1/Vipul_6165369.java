//Day 1 - 6165369 - Vipul Vikraman
//Question B - Worst Hello World program

import java.util.ArrayList;
import java.util.Collections;

public class Vipul_6165369 {
    public static void main(String[] args) {

        //There is a VERY small chance that this code will eventually print "Hello World"
        //It is possible: https://i.imgur.com/bs4Oqeo.jpg

        boolean HelloWorldPrinted = false;
        while (!HelloWorldPrinted){

            //First create an array of all alphabet characters (including capitalized) and the space character
            char[] alphabet = new char[53];
            alphabet[0] = 'a';
            alphabet[1] = 'b';
            alphabet[2] = 'c';
            alphabet[3] = 'd';
            alphabet[4] = 'e';
            alphabet[5] = 'f';
            alphabet[6] = 'g';
            alphabet[7] = 'h';
            alphabet[8] = 'i';
            alphabet[9] = 'j';
            alphabet[10] = 'k';
            alphabet[11] = 'l';
            alphabet[12] = 'm';
            alphabet[13] = 'n';
            alphabet[14] = 'o';
            alphabet[15] = 'p';
            alphabet[16] = 'q';
            alphabet[17] = 'r';
            alphabet[18] = 's';
            alphabet[19] = 't';
            alphabet[20] = 'u';
            alphabet[21] = 'v';
            alphabet[22] = 'w';
            alphabet[23] = 'x';
            alphabet[24] = 'y';
            alphabet[25] = 'z';
            alphabet[26] = 'A';
            alphabet[27] = 'B';
            alphabet[28] = 'C';
            alphabet[29] = 'D';
            alphabet[30] = 'E';
            alphabet[31] = 'F';
            alphabet[32] = 'G';
            alphabet[33] = 'H';
            alphabet[34] = 'I';
            alphabet[35] = 'J';
            alphabet[36] = 'K';
            alphabet[37] = 'L';
            alphabet[38] = 'M';
            alphabet[39] = 'N';
            alphabet[40] = 'O';
            alphabet[41] = 'P';
            alphabet[42] = 'Q';
            alphabet[43] = 'R';
            alphabet[44] = 'S';
            alphabet[45] = 'T';
            alphabet[46] = 'U';
            alphabet[47] = 'V';
            alphabet[48] = 'W';
            alphabet[49] = 'X';
            alphabet[50] = 'Y';
            alphabet[51] = 'Z';
            alphabet[52] = ' ';

            //Using the alphabet array, find the letters needed to create "Hello World"
            ArrayList<Character> characters = new ArrayList<>();
            boolean SpaceFound = false;
            boolean HFound = false;
            boolean eFound = false;
            boolean lFound = false;
            boolean oFound = false;
            boolean WFound = false;
            boolean rFound = false;
            boolean dFound = false;

            while (!HFound && !eFound && !lFound && !oFound && !SpaceFound && !WFound && !rFound && !dFound){
                for (char i : alphabet){
                    if (i == ' ' && !SpaceFound) {
                        characters.add(i);
                        SpaceFound = true;
                    }
                    if (i == 'H' && !HFound) {
                        characters.add(i);
                        HFound = true;
                    }
                    if (i == 'e' && !eFound) {
                        characters.add(i);
                        eFound = true;
                    }
                    if (i == 'l' && !lFound) {
                        characters.add(i);
                        characters.add(i);
                        characters.add(i);
                        lFound = true;
                    }
                    if (i == 'o' && !oFound) {
                        characters.add(i);
                        characters.add(i);
                        oFound = true;
                    }
                    if (i == 'W' && !WFound) {
                        characters.add(i);
                        WFound = true;
                    }
                    if (i == 'r' && !rFound) {
                        characters.add(i);
                        rFound = true;
                    }
                    if (i == 'd' && !dFound) {
                        characters.add(i);
                        dFound = true;
                    }
                }
            }

            //Create an array of integers 0-10 that can be shuffled
            ArrayList<Integer> random = new ArrayList<>();
            random.add(0);
            random.add(1);
            random.add(2);
            random.add(3);
            random.add(4);
            random.add(5);
            random.add(6);
            random.add(7);
            random.add(8);
            random.add(9);
            random.add(10);
            Collections.shuffle(random);

            //Use the shuffled array to build the "Hello World" string 
            String Hello_World = "";
            for (Integer n : random){
                Hello_World = Hello_World + characters.get(random.get(n));
            }

            //If successful (very unlikely), the loop will end
            System.out.println(Hello_World);
            if (Hello_World.equals("Hello World")){
                HelloWorldPrinted = true;
                System.out.println("You are either very lucky or extremely patient");
            }
        }
    }
}