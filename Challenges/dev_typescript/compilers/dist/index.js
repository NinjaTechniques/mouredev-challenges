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
function isAnagram(word1, word2) {
    word1 = word1.split("").sort().join("");
    word2 = word2.split("").sort().join("");
    let j = word1.length - 1;
    let mid = Math.floor(word1.length / 2);
    for (let i = 0; i < mid; i++) {
        if (word1[i] != word2[i] || word1[j] != word2[j]) {
            return false;
        }
        j--;
    }
    return true;
}
function main() {
    console.log("\n\n");
    const word1 = readlineSync.question("Enter a word 1: ");
    const word2 = readlineSync.question("Enter a word 2: ");
    if (isAnagram(word1, word2)) {
        console.log(`"${word1}" and "${word2}" are anagrams`);
    }
    else {
        console.log(`"${word1}" and "${word2}" are not anagrams`);
    }
    console.log("\n\n");
}
main();
//# sourceMappingURL=index.js.map