fun main (args: Array<String>) {
    /*Definir variables (define variables)
        - Kotlin tiene inferencia de tipos
    */
    var number: Int
    var value = 30
    var element: Int = 50

    number = 210
    println("Number $number")
    println("Value $value")
    println("Element $element\n")

    /*.get es para obtener el valor de una posicion de una cadena*/
    var text: String = "Welcome to Kotlin by Jetbrains"
    println("Text: $text")
    println("Length: ${text.length}")
    println("Position 5: ${text.get(5)}\n")

    /*Switch - Condicionales multiples*/
    var age = 14
    when (age) {
        in 0..12 -> println("Child")
        in 13..17 -> println("Young adult")
        18 -> println("Adult")
        else -> println("Old")
    }
    println("\n")

    /*Arrays*/
    var array = arrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    var names = arrayOf("Luz", "Melanie", "Anabell", "Zamira", "Camila")

    names[4] = "Jazmin"
    println("Array[3]: ${array[1]}")
    println("Names[2]: ${names[1]}")
    println("Names[4]: ${names[4]}\n")

    var counter = 0
    while (true) {
        if (counter == names.size) { break }

        println("$counter - ${names[counter]}")
        counter++
    }
    println("\n")

    /*Lists, Arrays and Maps*/
    val numbers: List<Int> = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val mutableList: MutableList<String> = mutableListOf("a", "b", "c", "e")
    val array2 = intArrayOf(9, 14, 32, 43, 54, 65, 76, 87, 98)


    for(n in numbers) { print("$n ") } 
    println()
    mutableList.add("f")
    mutableList.add("g")
    for(m in mutableList) { print("$m ") }
    println()
    for(i in array2) { print("$i ") }
    println()
    val ages: Map<String, Int> = mapOf("Luz" to 21, "Melanie" to 22, "Anabell" to 23, "Zamira" to 24, "Camila" to 25)
    
    /* 
    ages.forEach { (_, age) ->
        println("$age: ")
    }
    */
    ages.forEach { (name, age) ->
        println("$name: $age")
    }

    println("\n")
    /*Uso de "val"
        => No se puede reasignar, es decir, es inmutable
        => Espera siempre tener un valor en "tiempo de ejecucion"
        => "const" es mas estricto y necesita tener el valor de la variable inmutable desde "tiempo de compilacion"
    */
    val character: String = "Itadori"
    println("Character: $character\n")

    var x = 91.3213
    var y: Int = x.toInt() //Conversion de tipo explicita
    println("X: $x")
    println("Y: $y\n")

    /*Smart Cast
     => Al realizar una comprobacion de tipo, Kotlin "recuerda" el tipo y lo trata de esa forma
    */
    fun smartCast(value: Any) {
        if (value is String) {
            // Aquí, "value" se comporta automáticamente como String
            println("Length: ${value.length}\n") // Puedes usar métodos de String directamente
        }
        
        if (value is Int) {
            // Aquí, "value" se comporta como Int
            println("Value: ${value + 2}\n") // Puedes realizar operaciones de Int
        }
    }

    smartCast("Hello")

    /*Casting o conversion segura*/
    val obj1: Any = "Hola"
    val str1: String = obj1 as String

    /*Unsafe cast operator (Casting no seguro)
        => El responsable de que la conversion sea segura y correcta es el desarrollador

        =>Bypassing del Sistema de Tipos: Al usar "as", estás diciéndole al compilador que confíe en ti, incluso si no puede verificar la seguridad de la conversión.
    */
    val obj2: Int? = null

    //as? intenta hacer la conversión, pero devuelve null si no es posible, en lugar de lanzar una excepción.
    val str2: String? = obj2 as String? // str será null, no lanza excepción
    println("str: $str1")
    println("str: $str2\n\n")

    /*Loops*/
    for (i in 1..10) {
        print("$i ")
    }

    print("\n")
    val fruits = listOf("apple", "banana", "orange")
    for (fruit in fruits) {
        print("$fruit ")
    }
    print("\n")
    fruits.forEach { fruit ->
        print("$fruit ")
    }

    print("\n")
    for (i in 5 downTo 1) {
        print("$i ")
    }

    print("\n")
    for (i in 1..10 step 2) {
        print("$i ")
    }
    
    var nombreNullable: String? = null
    println(nombreNullable?.length) // Safe call

    val longitud = nombreNullable?.length ?: 0 //Elvis operator (?:)
    println(longitud) 
    
    /*=> Convierte cualquier valor nullable a su versión no nullable.
    => Esencialmente, le dice al compilador: "Estoy 100% seguro de que este valor no es null".*/
    println(nombreNullable!!.length) // Non-null assertion (cuidado)

    print("\n\n")
}