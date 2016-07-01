#!/usr/bin/ruby
require 'optparse'

$answer = 1 + rand(10)

options = {game: nil}
parser = OptionParser.new do |opts|
  opts.banner = "Usage: guessing_game [options]\n" +
                "Run with no args to generate a randomn number."

  opts.on('-g', '--game', 'Game') do 
    options[:game] = true 
  end 

  opts.on('-h', '--help', 'Displays Help') do
    puts opts
    exit
  end
end

parser.parse!

def game 
  puts "Welcome to the guessing game\n"
  puts "Please guess a number between 1 and 10"

  num = gets.to_i
  while num != $answer
    if num < $answer 
      puts "too small"
      num = gets.to_i
    elsif num > $answer
      puts "too big"
      num = gets.to_i
    else
      puts 'That was weird' 
      num = gets.to_i
    end 
  end

  puts 'Correct' 
end


def generate
  puts "Random number: #{$answer}"
  puts "Hint: type - game - for some fun"
end


if options[:game]
  game
else
  generate
end
