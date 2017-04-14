#!/bin/sh
## test.sh for  in /home/samy.aitouakli/livecoding/graph
## 
## Made by Samy Aitouakli
## Login   <samy.aitouakli@epitech.net>
## 
## Started on  Wed Apr 12 17:52:10 2017 Samy Aitouakli
## Last update Wed Apr 12 17:57:49 2017 Samy Aitouakli
##

i=0;

echo -ne "$1\n";
echo -ne "$2\n";
echo -ne "./sprites/pictures/textures.png\n"

while [ $i -lt $(($1 * $2)) ]
do
    echo -ne "\\0$(($RANDOM % 3)) \\0$(($RANDOM % 3))\n";
    i=$(($i  +1));
    done;
