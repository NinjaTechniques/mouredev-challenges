import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.IOException;

public class App {
    
    //* Challenge: 4
    private static void eliminateMultiples (List<Integer> list, int uncheckedValue, int index){
        //Eliminacion mientras iteramos
        list = list.subList(index + 1, list.size()); // [ >
        Iterator<Integer> itr = list.iterator();
        int value = 0;

        while (itr.hasNext()) {
            value = itr.next();
            if (value % uncheckedValue == 0) { itr.remove(); }
        }
    }

    private static void fillValues (List<Integer> list, int min, int max){
        for (int i = min; i <= max; i++) { list.add(i); }
    }

    private static List<Integer> cribaEratostenes (int min, int max) {
        List<Integer> numbers = new LinkedList<>();
        fillValues(numbers, min, max);

        int index = 0;
        int uncheckedValue = numbers.get(index);
        int maximumIteration = (int)Math.sqrt(Double.valueOf(max));

        while (uncheckedValue <= maximumIteration) {
            eliminateMultiples(numbers, uncheckedValue, index);
            index++;
            uncheckedValue = numbers.get(index);
        }
        return numbers;
    }

    private static void showPrimes(List<Integer> list){
        for (Integer value: list) {
            System.out.print(value + ", ");
        }
    }

    private static boolean isDataValid (int min, int max) {
        final int ERROR = 1;
        boolean flag = true;

        if (min == ERROR) { flag = false;}
        if (min <= 0 || max <= 0) { flag = false;}
        if (min == max) { flag = false;}
        if (min > max) { flag = false; }

        if (flag == false) { System.out.println("Invalid data");}
        return flag;
    }

    private static void client2(){

        try (BufferedReader input = new BufferedReader(new InputStreamReader(System.in))){
            int min = 0, max = 0;

            /*
             * Si el valor de "min" es 1, ocurre que la funcion eliminateMultiples(),
             * elimine todos los multiplos de 1 y cuando se quiere seguir recorriendo en 
             * el bucle While de la funcion "cribaEratostenes()" el siguiente valor del indice aparte de "1"
             * no existe, ya que todos son multiplos de 1 y fueron eliminados, dejando el size de 
             * la lista con 1 solo elemento, pero con ERROR al intentar acceder a una posicion siguiente
             * que no existe.
             * 
             -> Inicia: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
             -> Elimina: [2, 3, 4, 5, 6, 7, 8, 9, 10]
             -> Queda: [1]
            */

            do {
                System.out.print("Enter the min number: "); //Always min = 2
                min = Integer.parseInt(input.readLine());
    
                System.out.print("Enter the max number: ");
                max = Integer.parseInt(input.readLine());
                System.out.println();
            }while(isDataValid(min, max) == false);

            System.out.println();
            showPrimes(cribaEratostenes(min, max));

        } catch (Exception e) {
           e.printStackTrace();
        }
    }

    
    //* Challenge: 2
    private static String sortAlphabetically (String word){
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            return new String(chars); 
    }
    
    private static Boolean isAnagram(String word1, String word2) {
        if(word1.equals(word2)) { return false; }
        word1 = sortAlphabetically(word1.toLowerCase()); //Se crea un nuevo String para no modificar el original
        word2 = sortAlphabetically(word2.toLowerCase());

        int lenght = word1.length() % 2 == 0 ? word1.length() / 2 : (word1.length() / 2) + 1;
        int j = word1.length() - 1;
        boolean flag = true;

        for (int i = 0; i < lenght / 2; i++) {
            if (word1.charAt(i) != word2.charAt(i) || word1.charAt(j) != word2.charAt(j)) {
                flag = false;
                break;
            }
            j--;
        }

        return flag;
    }
    
    private static void client1(){
        try (BufferedReader input = new BufferedReader(new InputStreamReader(System.in))) {
            System.out.print("Enter the first word: ");
            String word1 = input.readLine();
            System.out.print("Enter the second word: ");
            String word2 = input.readLine();

            if (isAnagram(word1, word2)) { System.out.println("The words are anagrams");}
            else { System.out.println("The words are not anagrams");}
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("\n");
        client2();

        System.out.println("\n\n");
    }
}
