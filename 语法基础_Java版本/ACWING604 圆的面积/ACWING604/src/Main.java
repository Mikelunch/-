import java.util.*;
import java.io.*;

public class Main{ //重点掌握在JAVA中规范化输出
    public static void main(String args[]) throws Exception{
        final double PI = 3.14159;
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        sc.close();
        System.out.print("A=");
        //System.out.printf("%.4f",(r * r * 3.14159));//第一种 控制输出格式
        //System.out.format("%.4f", (r * r * PI)); //第二种控制个数输出
        String num = String.format("%.4f",r * r * PI); //第三种 转换成字符串
        System.out.print(num);
    }
}
