/*
 * Escribe un programa que muestre por consola (con un print) los
 * números de 1 a 100 (ambos incluidos y con un salto de línea entre
 * cada impresión), sustituyendo los siguientes:
 * - Múltiplos de 3 por la palabra "fizz".
 * - Múltiplos de 5 por la palabra "buzz".
 * - Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
 */

void main (){
  final int MAXVALUE = 100;

  for (int i = 1; i < MAXVALUE; i++) {
    if (mutiplesOfFive(i) && mutiplesOfThree(i)) {
      print("fizzbuzz");
    }
    else if (mutiplesOfThree(i)) {
      print("fizz");
    }
    else if (mutiplesOfFive(i)){
      print("buzz");
    }
    else {
      print(i);
    }
  }
}

bool mutiplesOfThree(int number){ return number % 3 == 0 ? true : false;}
bool mutiplesOfFive(int number){ return number % 5 == 0 ? true: false;}