#!/bin/bash
g++ DITgenerator.cpp -o DIT -std=c++11
touch priklady.md
rm priklady.md
touch priklady.md

printf "# 1) PRIKLADY \r\n" >> priklady.md
printf "Spocitane priklady na K-Mapy. \r\n\r\n" >> priklady.md
a=10
printf "\r\n## K-Mapy o 3 prommennych \r\n" >> priklady.md
for (( j = 0; j <= $a; j++ )); do
  ./DIT 18 >> priklady.md
  sleep 1
  ./DIT 18 >> priklady.md
  sleep 1
  ./DIT 18 >> priklady.md
  sleep 1
  echo "\newpage" >> priklady.md
done
printf "\r\n## K-Mapy o 4 prommennych \r\n" >> priklady.md
for (( j = 0; j <= $a; j++ )); do
  ./DIT 19 >> priklady.md
  sleep 1
  ./DIT 19 >> priklady.md
  sleep 1
  ./DIT 19 >> priklady.md
  sleep 1
  echo "\newpage" >> priklady.md
done
printf "\r\n## K-Mapy o 5 prommennych \r\n" >> priklady.md
a=14
for (( j = 0; j <= $a; j++ )); do
  ./DIT 20 >> priklady.md
  sleep 1
  ./DIT 20 >> priklady.md
  sleep 1
  echo "\newpage" >> priklady.md
done
