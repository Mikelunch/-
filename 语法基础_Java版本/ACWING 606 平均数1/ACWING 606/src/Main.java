import java.io.*;
import java.util.*;

public class Main{
    public static void main(String args[]) throws Exception{
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double mean = a * 3.5 +  b * 7.5;
        mean /= 11;
        String numString = String.format("%.5f",mean);
        System.out.println("MEDIA = " + numString);
    }
}
