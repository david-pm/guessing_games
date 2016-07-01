#!/bin/bash

rand=$RANDOM
const=$((1 + rand % 100))
yellow="\033[33;40m"
none="\033[0m"

function game {
  echo -e $yellow"Welcome to the guessing game!"$none
  echo
  echo "Please guess a number between 1 and 100"

  read num
  while [[ -z "$num" || ("$num" -lt 1 || "$num" -gt 100) ]]; do
    read -p "Please pick a number from 1-100 " num
  done

  while [[ "$num" -ne "$const" ]]; do
    if [[ $num -lt $const ]]
    then
      read -p "Too small, try again " num
    elif [[ $num -gt $cont ]]
    then
      read -p "Too big, try again " num
    else
      read -p "That was weird, you'd better try again " num
    fi
  done

  echo "You guessed: $num"
  echo "The number was: $const"
}

function generate {
  echo "Random number: $rand"
  echo -e "Hint: type "$yellow$0 " game"$none" for some fun"
}

if [[ $1 =~ game|Game|GAME ]]; then
  game
else
  generate
fi
