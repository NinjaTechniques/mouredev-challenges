"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const readlineSync = __importStar(require("readline-sync"));
function fibonacci(finalValue) {
    let a = 0;
    let b = 1;
    let accumulated = 0;
    for (let i = 1; i < finalValue; i++) {
        if (i == 1) {
            console.log(a);
        }
        if (i == 2) {
            console.log(b);
        }
        accumulated = a + b;
        console.log(`${accumulated}, `);
        a = b;
        b = accumulated;
    }
}
function main() {
    console.log("\n\n");
    const finalValue = readlineSync.questionInt("Enter a number: ");
    console.log("\n");
    fibonacci(finalValue);
    console.log("\n\n");
}
main();
//# sourceMappingURL=index.js.map