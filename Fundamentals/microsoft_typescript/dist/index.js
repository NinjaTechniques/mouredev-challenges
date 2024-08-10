"use strict";
let message = "Hello World";
message = "Welcome to TypeScript";
console.log(message);
message = "Bye World";
console.log(message);
console.log(typeof [1, 2, 3]);
let extinctionDinosaurs = 76000000;
let dinosursFavorite = "Tyrannosaurus";
let extints = true;
let myVariable;
myVariable = 10;
myVariable = false;
let unknownValue = "Leidy";
function add(a, b) { return a + b; }
function greet({ name, age }) {
    console.log(`Hello, my name is ${name} and I am ${age} years old.`);
}
function greet2(person) {
    const { name, age } = person;
    console.log(`Hello, my name is ${name} and I am ${age} years old.`);
}
let animals = ["cat", "dog", "chicken"];
let checks = [];
let numbers = [1, 2, 3];
let tupla = [
    1,
    ["Jazmin", "Melanie", "Leidy"],
    true
];
var Sizes;
(function (Sizes) {
    Sizes["Small"] = "s";
    Sizes["Medium"] = "m";
    Sizes["Large"] = "l";
    Sizes["ExtraLarge"] = "xl";
})(Sizes || (Sizes = {}));
let mySize = Sizes.ExtraLarge;
console.log(mySize);
const state = 2;
const myObject = {
    name: "Jazmin",
    age: 25,
    size: Sizes.Medium
};
myObject.name = "Melanie";
const myObject2 = {
    id: 1,
    username: "leidy_11",
};
myObject2.id = 2;
const myObjet3 = {
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
};
const arrayPerson = [];
//# sourceMappingURL=index.js.map