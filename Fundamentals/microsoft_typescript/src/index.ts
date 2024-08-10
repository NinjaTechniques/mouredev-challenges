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


//* NEVER: Funciones que nunca van a devolver nada
function throwError(message: string): never {
    throw new Error(message)
}



let animals: string[] = ["cat", "dog", "chicken"]
let checks: boolean[] = []
let numbers: Array<number> = [1, 2, 3]

//Map en JS: Permite iterar un arreglo y asignarles una funcion
//animals.map(x => x.) => El autocompletado sugiere metodos del tipo de dato que se use.






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