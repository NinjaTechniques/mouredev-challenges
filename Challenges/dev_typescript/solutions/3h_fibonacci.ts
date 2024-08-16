import * as readlineSync from 'readline-sync';

function fibonacci (finalValue: number) {
    let a = 0
    let b = 1
    let accumulated = 0

    for (let i = 1; i < finalValue; i++) {
        if (i == 1) { console.log(a) }
        if (i == 2) { console.log(b) }

        accumulated = a + b
        console.log(`${accumulated}, `)

        a = b
        b = accumulated
    }
}

function main (){
    console.log("\n\n")

    const finalValue = readlineSync.questionInt("Enter a number: ")
    console.log("\n")
    fibonacci(finalValue)

    console.log("\n\n")
}
main() // Call the main function