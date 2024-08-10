 /*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
 */
fun fibonacciWithLoops() {
    val minValue = 0
    val maxValue = 50
    var a: Long = 0L
    var b: Long = 1L
    var counter: Long

    for (i in minValue..maxValue) {
        if (i == 0) { println("Fib($i): $a"); continue }
        if (i == 1) { println("Fib($i): $b"); continue }

        counter = a + b
        println("Fib($i): $counter")

        a = b
        b = counter
    }
}

fun fibonacciWithRecursion(a: Long, b: Long, minValue: Int, maxValue: Int)  {
     //Step 1
    var a_ = a
    var b_ = b
    var counter: Long

    if (minValue == (maxValue + 1)) { return } // Validation 1

    if (minValue == 0) { println("Fib($minValue): $a_") } // Valitation 2
    else if (minValue == 1) { println("Fib($minValue): $b_"); }
    else {
        counter = a_ + b_
        println("Fib($minValue): ${counter}")

        a_ = b_
        b_ = counter
    }

    var minValue_ = minValue + 1
    fibonacciWithRecursion(a_, b_, minValue_, maxValue)
}

fun fibonacciWithRecursionUI(minValue: Int, maxValue: Int) {
    fibonacciWithRecursion(0L, 1L, minValue - 1, maxValue)
}

 fun main (args: Array<String>){
    println("\n\n")

    fibonacciWithLoops()
    //fibonacciWithRecursionUI(1, 50)

    println("\n\n")
}