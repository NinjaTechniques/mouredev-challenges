/*
 * Escribe un programa que se encargue de comprobar si un número es o no primo.
 * Hecho esto, imprime los números primos entre 1 y 100.
 */

 fun isPrime(listPrimes: MutableList<Int>, unstrikedValue: Int): Int {
    
    var index: Int = listPrimes.indexOf(unstrikedValue)
    val subListPrimes: MutableList<Int> = mutableListOf() // Se puede modificar pero no se puede reasignar con otra lista nueva.
    listPrimes.forEach { prime -> subListPrimes.add(prime) }
    
    for(number in subListPrimes.subList(index + 1, listPrimes.size)) { // [ >
        if (number % unstrikedValue == 0) {
            listPrimes.remove(number)
        }
    }

    return listPrimes[index + 1]
 }

fun cribaEratostenes (min: Int, max: Int): MutableList<Int> {
    //lateinit var primes: MutableList<Int>

    var primes: MutableList<Int> = mutableListOf()
    for(i in min..max) { if (i == 1) { continue }; primes.add(i) }

    var i = primes[0]
    while (true) {
        i = isPrime(primes, i)
        if (i > Math.sqrt(max.toDouble()).toInt()) { break }
    }

    return primes
}

fun printResults(){
    val min: Int = 1
    var max: Int

    println("The min value is: $min")
    while(true){
        print("Enter the max value: ")
        max = readLine()?.toIntOrNull() ?: 0
        if(max > 0 && max > min) { println("\n"); break }
    }
    
    val primes: MutableList<Int> = cribaEratostenes(min, max)
    print("1, ") 
    primes.forEach { number ->
        print("$number, ") 
    }
}

fun main (args: Array<String>) {
    println("\n\n")
    printResults()

    println("\n\n")
}