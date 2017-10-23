#!/bin/bash
g++ DITgenerator.cpp -o DIT -std=c++11
touch priklady.md
rm priklady.md
touch priklady.md

printf "# 1) PRIKLADY \r\n" >> priklady.md
printf "Spocitane priklady na K-Mapy. \r\n\r\n" >> priklady.md
for (( i = 31;i <= 33;i++)); do
  case "$i" in
    31) printf "\r\n## K-Mapy o 3 prommennych \r\n" >> priklady.md
        b=20
      ;;
    32) printf "\r\n## K-Mapy o 4 prommennych \r\n" >> priklady.md
        b=50
      ;;
    33) printf "\r\n## K-Mapy o 5 prommennych \r\n" >> priklady.md
        b=100
      ;;
    *)  printf "\r\n## K-Mapy o 5 prommennych \r\n" >> priklady.md
        b=100
      ;;
  esac
    ./DIT $i $b >> priklady.md
    echo "\newpage" >> priklady.md
done
