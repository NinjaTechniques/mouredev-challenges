/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */

fun main (args: Array<String>) {
    println("\n")

    fun sortWord (value: String) : String = value.toCharArray().sorted().joinToString("")
    
    /*
    espo nja
    resu lt

    amor
    moor
    */
    fun isAnagram (word1: String, word2: String) : Boolean {
        val sortedWord1 = sortWord(word1)
        val sortedWord2 = sortWord(word2)
        var flag: Boolean = true

        var j: Int = sortedWord1.length - 1
        var mid:Int = (sortedWord1.length / 2).toInt()
        
        for (i in 0..mid) {
            if (sortedWord1.get(i) != sortedWord2.get(i) || sortedWord1.get(j) != sortedWord2.get(j)) {
                flag = false
                break
            }
            j--
        }
        
        return flag
    }

    print("Enter the first word: ")
    val word1 = readLine() ?: ""
    print("\nEnter the second word: ")
    val word2 = readLine() ?: ""

    println("\n")
    if (isAnagram(word1, word2)) {
        println("$word1 and $word2 are anagrams")
    }
    else{ 
        println("$word1 and $word2 are not anagrams")
    }
}