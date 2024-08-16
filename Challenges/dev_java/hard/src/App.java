import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.IOException;

public class App {


    //* Challenge: 3
    private static void fibonacci(int quantityValues){
        long a = 0;
        long b = 1;
        long sum = 0;

        for (int i = 0; i <= quantityValues; i++) {
            System.out.print("Fib(" + i + "): ");
            if (i == 0) { System.out.print(a + "\n"); continue;}
            else if (i == 1) { System.out.print(b + "\n"); continue; }

            sum = a + b;
            System.out.print(sum + "\n");

            a = b;
            b = sum;
        }
    }

    private static void fibonacciRecursive(long a, long b, int quantityValues) {
        long sum = Math.abs(a + b); 

        //Base Case
        if (quantityValues < 0) { return; }

        System.out.println(sum); 
        quantityValues--;
        fibonacciRecursive(b, sum, quantityValues);
    }

    private static void fibonacciRecursive(int quantityValues) { //sobrecarga
        final long a = -1;
        final long b = 1;
        fibonacciRecursive(a, b, quantityValues);
    }

    private static void client1(){
        try (BufferedReader input = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter the quantity values: ");
            int quantityValues = Integer.parseInt(input.readLine());
            System.out.println("\n");
            fibonacci(quantityValues);
            //fibonacciRecursive(quantityValues);

        }catch(Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("\n");
        client1();

        System.out.println("\n\n");
    }
}
