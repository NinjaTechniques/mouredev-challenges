let message: string = "Hello World"
message = "Welcome to TypeScript" 

console.log(message)
message = "Bye World"
console.log(message)

/* Data Types JavaScript:
number
string
boolean
null
undefined
object
function

Data Types TypeScript:
!Evitar el uso de "any"
unknown
never
arrays
tuplas
enums
*/
console.log(typeof [1, 2, 3]) //El array es un tipo de dato "object"

/*No es necesario decirle a TS el tipo de dato cuando se inicializa la variable
- En caso de solo declarar la variable, el tipo de dato por defecto es "any", entonces,
 si debe de ponerse el tipo.*/
let extinctionDinosaurs: number = 76_000_000 //Es mas legible separar los millones de esta manera.
let dinosursFavorite: string = "Tyrannosaurus"
let extints: boolean = true

/*
No es necesario declarar el tipo de dato de la variable, ya que es "any",
ya que de nada serviria entonces usar TypeScript, mejor usamos JavaScript
*/
let myVariable
myVariable = 10
myVariable = false

/*
* Any: Cualquier tipo de dato
! Any IGNORA el tipado de TypeScript
? Con any ya no reconoce, por ejemplo, las funciones del string "Leidy" (se quita el autocompletado)
*/
//let anyValue: any = "Leidy"
//anyValue.gdfsadfasdfasdfas -> No te dice el ERROR (PELIGRO)


/*
* Unknown
=> Es como decir, "no se que tipo de dato es".
=> No puedes usar propiedades que no sabemos si existen, porque no sabemos el tipo.
*/
let unknownValue: unknown = "Leidy"
//unknownValue.asdfa -> Menciona como ERROR






/*
* Functions
*/
function add (a: number, b: number) { return a + b }

/*Forma 1 de tipar un objeto en una funcion

 => Hay que tener cuidado con hacer esto {name: string, age: number} porque esa forma no es compatible con JavaScript, pues lo que hace es decir que "name" se cambie de nombre a "string" y "age" se renombra a "number". Entonces, no esta tipando sus tipos, estas cambiando el nombre del atributo.
*/
function greet ({name, age}: { name: string, age: number }) {
    console.log( `Hello, my name is ${name} and I am ${age} years old.`)
}
   
/*Forma 2 de tipar un objeto en una funcion*/

function greet2 (person: { name: string, age: number }) {
    const { name, age } = person
    console.log( `Hello, my name is ${name} and I am ${age} years old.`)
}


/*Forma 3 de tipar un objeto en una funcion*/
//Recibe un Arrow Function como argumento
//!Hay que evita el tipado con "FUNCTION" ya que es el ANY de las funciones
const sayHiFromFunction = (fn: (name: string) => void) => {
    fn("Leidy")
}

const myFunction = (name: string) => {
    console.log(`Hello, my name is ${name}`)
}

sayHiFromFunction(myFunction)

/*Tpar las Arrow Functions*/
const sum = (a: number, b: number): number => {
    return a + b
}

const substract = (a: number, b: number) => {
    return a - b
}


//* NEVER: Funciones que nunca van a devolver nada, es decir, que nunca va a terminar de ejecutarse.
function throwError(message: string): never {
    throw new Error(message)
}



let animals: string[] = ["cat", "dog", "chicken"]
let checks: boolean[] = []
let numbers: Array<number> = [1, 2, 3]

//Map en JS: Permite iterar un arreglo y asignarles una funcion
//animals.map(x => x.) => El autocompletado sugiere metodos del tipo de dato que se use.

//* Inferencia de funciones anonimas segun el contexto
const avengers = ["Spidey", "Hulk", "Hawkeye"]

avengers.forEach(avenger => { // Infiere el tipo de dato y te recomienda el autocompletado
    console.log(avenger.toUpperCase())
})

avengers.forEach(
    function(avenger) { //Infiere el tipo de dato y te recomienda el autocompletado
        console.log(avenger.toUpperCase())
    }
)


/*
* Tuplas
    -> En JS no existen tuplas, pero en TypeScript si.
    -> Las tuplas nos permiten guardar datos siempre y cuando esten definidos.
*/
let tupla: [number, string[], boolean] = [
    1, 
    ["Jazmin", "Melanie", "Leidy"],
    true,
]

/*
El compilador de TS no detecta que esto es un error,
ya que recordemos que debemos definir el tipo de dato en la tupla,
si esta como  number, string[], boolean y agregamos 10, entonces, deberia de ser
number | string[] | boolean | number
*/
//tupla.push(10)










/*
*Enums
 -> En JS no existen enums, pero en TypeScript si.
 -> Los enums nos permiten definir una serie de valores constantes.
 -> Se debe usar PascalCase
 -> Por defecto, los valores son numericos small = 0, medium = 1, etc., pero se puede modificar
*/
enum Sizes { Small = "s", Medium = "m", Large = "l", ExtraLarge = "xl"}
let mySize: Sizes = Sizes.ExtraLarge
console.log(mySize)

/*Se debe usar en gran medida el "const" para poder optimizar el codigo de JavaScript,
esto sucede cuando la variable, por ejemplo, "state" recibe un valor de un enum. 

En caso contrario, los valores del enum no se reflejaran en el archivo JS.
*/
const enum LoadingState {Idle, Loading, Success, Error}
const state = LoadingState.Success








/*
* Objects
*/
const myObject: {name: string, age: number, size: Sizes} = {
    name: "Jazmin",
    age: 25,
    size: Sizes.Medium,
}
myObject.name = "Melanie"


//Aplicamos a "password" que sea opcional
const myObject2: {id: number, readonly username: string, password?: string} = {
    id: 1,
    username: "leidy_11",
}
myObject2.id = 2
//myObject2.username = "Jazmin" => No se puede reasignar, ya que se puso como readonly

type Address = {
    numberAddress: number,
    street: string,
    city: string
}

type Person = {
    readonly person_id: number
    name: string,
    lastname: string,
    age: number,
    email: string,
    address?: Address
}

const myObjet3: Person = {
    person_id: 1,
    name: "Jazmin",
    lastname: "Gonzalez",
    age: 25,
    email: "jazmin@me.com",
    address: {
        numberAddress: 123,
        street: "Calle falsa 123",
        city: "NY"
    }
}
// myObjet3.person_id = 2 => No se puede reasignar, ya que se puso como readonly

const arrayPerson: Person[] = []


//*Type Alias
type Hero = {
    name: string,
    age: number,
}

let hero: Hero  = {
    name: "Spiderman",
    age: 25
}

function createHero (hero: Hero): Hero{
    const {name, age} = hero
    return {name, age}
}

const thor = createHero({name: "Thor", age: 1000})


//*Optional Properties
//BACKTICK: ALT + 96
type HeroId = `${string}-${string}-${string}-${string}-${string}`

//*Union Types
type HeroPowerScale = "local" | "planetary" | "galactic" | "universal"
//const enableAnimationDuration: boolean | number = 200 

type HeroBasicInfo = {
    name: string,
    age: number,
}

type HeroProperties = {
    readonly id?: HeroId
    isActive?: boolean
    powerScale?: HeroPowerScale
}

//* Intersection Types
type Hero2 = HeroBasicInfo & HeroProperties

let hero2: Hero2  = {
    name: "Ironman",
    age: 25
}

function createHero2 (input: HeroBasicInfo): Hero2 {
    const {name, age} = input
    return {
        id: crypto.randomUUID(), 
        name, 
        age, 
        isActive: true
    }
}

const hulk = createHero2({name: "Hulk", age: 5_000_000})
console.log(hulk.isActive) // -> true
hulk.id?.toString() // -> undefined or number / Pregunta si existe antes de continuar
hulk.powerScale = "galactic"

/* -> No se puede reasignar, ya que se puso como readonly
- El valor no se puso INMUTABLE, si no que mientras se desarrolla, lanza el error.
- En JS el valor si se puede reasignar, pero en TS no.
*/
//hulk.id = 20 

//* Template Union Types
type HexadecimalColor = `#${string}`
//const color: HexadecimalColor = "0030ff" => Error
const color2: HexadecimalColor = "#ff0030"


//* Type Indexing
type CharacterProperties = {
    isActive: boolean,
    address: {
        planet: string,
        city: string
    }
}

const addressCharacter: CharacterProperties["address"] = {
    planet: "Earth",
    city: "New York"
}

//* Type From Value

const address = {
    planet: "Earth",
    city: "London"
}

type AddressCity = typeof address //Typeof: extraer el tipo de un objeto, funciones, etc.

const addressTwitch: AddressCity = {
    planet: "Mars",
    city: "San Francisco"
}

//* Type From Function Return
function createAddress (){
    return {
        planet: "Mars",
        city: "Berlin"
    }
}

type AddressCity2 = ReturnType<typeof createAddress> // Recupera tipos de la funcion 


//* Arrays
const languages: string[] = [] // Array solo para strings
languages.push("TypeScript")
languages.push("JavaScript")
languages.push("Python")

/*
const container: string[] | number[] = [1, 2, 3, 4, 5, 6, 7] // Array solo de strings o solo de numbers
container.push(8)
container.push(9)
*/

const container: string[] | number[] = ["TypeScript", "JavaScript"] // Array solo de strings o solo de numbers
container.push("Java")
container.push("C#")

const arrayMultiValue: (string | number)[] = []
arrayMultiValue.push("C++")
arrayMultiValue.push(1)
arrayMultiValue.push("Go")
arrayMultiValue.push(14)
//arrayMultiValue.push(true) -> ERROR


//* Matrices or Array Multi-Dimensional
/* Juego del gato
[
    ["x", "o", "x"],
    ["o", "x", "o"],
    ["x", "", "o"]
]
*/

//Usando Union Types
type CellValue = "x" | "o" | ""

//Using TUPLA: Es un arreglo que tiene una longitud fija o limite
type GameBoard = [
    [CellValue, CellValue, CellValue],
    [CellValue, CellValue, CellValue],
    [CellValue, CellValue, CellValue]
]

const board: GameBoard = [
    ["x", "o", "x"],
    ["o", "x", "o"],
    ["x", "", "o"]
]

type RGB = [number, number, number]
const rgb: RGB = [255, 255, 255]
//const rgb: RGB = [255, 255, 255, "f"] -> Error