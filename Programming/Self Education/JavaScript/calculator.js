'use strict';
let calculator = {
    read() {
        this.a = +prompt("Insert a value of a",0);
        this.b = +prompt("Insert a value of b",0);                                                                                          
    },
    sum() {
        return this.a + this.b;
    },
    mul() {
        return this.a * this.b;
    }
}

calculator.read();
alert( calculator.sum() );
alert( calculator.mul() );