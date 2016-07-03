#!/usr/bin/node

// `npm install prompt`
var prompt = require('prompt');

var args = process.argv.slice(2);
var randomNumber = Math.floor(Math.random() * 10) + 1;

function game() {
  console.log("Welcome to the guessing game!");
  console.log("Enter a guess between 1-10");

  prompt.start();
  getInput();
}

function getInput() {
  prompt.get(['guess'], function (err, result) {
    var input = Number(result.guess);
    if (input == randomNumber) {
      console.log("You guessed it!");
    } else {
      if (input < randomNumber)
        console.log("Too small!");
      else if (input > randomNumber)
        console.log("Too big!");
      else
        console.log("Keep guessing! Pick a number from 1-10");
      getInput();
    }
  });
}

function generate() {
  console.log("You're randomn number is: " + randomNumber);
  console.log("Try entering './guessing_game game' for some real fun");
}

if (args.length && args[0] == 'game')
  game();
else
  generate();
