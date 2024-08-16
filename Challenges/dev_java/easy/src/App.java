import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.IOException;

public class App {


    //* Challenge: 1
    private static void fizzbuzz(){
        try (BufferedReader input = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter the min number: ");
            int min = Integer.parseInt(input.readLine());
            System.out.print("Enter the max number: ");
            int max = Integer.parseInt(input.readLine());
            System.out.println();

            for (int i = min; i <= max; i++) {
                if (i % 3 == 0 && i % 5 == 0) { System.out.println("fizzbuzz"); }
                else if (i % 3 == 0) { System.out.println("fizz"); }
                else if (i % 5 == 0 ) { System.out.println("buzz"); }
                else { System.out.println(i);}
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("\n");

        fizzbuzz();
        System.out.println("\n\n");
    }
}
