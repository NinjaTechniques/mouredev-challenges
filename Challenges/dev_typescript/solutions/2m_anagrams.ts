import * as readlineSync from 'readline-sync';

/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */

function isAnagram (word1: string, word2: string) :  boolean  {
    word1 = word1.split("").sort().join("")
    word2 = word2.split("").sort().join("")

    let j: number = word1.length - 1
    let mid: number = Math.floor(word1.length / 2)

    for (let i = 0; i < mid; i++) {
        if (word1[i] != word2[i] || word1[j] != word2[j]) {
            return false
        }
        j--
    }
    return true
}


function main (){
    console.log("\n\n")
    const word1 = readlineSync.question("Enter a word 1: ")
    const word2 = readlineSync.question("Enter a word 2: ")

    if (isAnagram(word1, word2)) {
        console.log(`"${word1}" and "${word2}" are anagrams`)
    }
    else{
        console.log(`"${word1}" and "${word2}" are not anagrams`)
    }

    console.log("\n\n")
}

main() // Call the main function