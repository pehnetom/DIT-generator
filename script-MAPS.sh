#!/bin/bash
g++ DITgenerator.cpp -o DIT -std=c++11
touch priklady.md
rm priklady.md
touch priklady.md

printf "# 1) PRIKLADY \r\n" >> priklady.md
printf "Spocitane priklady na K-Mapy. \r\n\r\n" >> priklady.md
a=10
b=2
for (( i = 18;i <= 29;i++)); do
  case "$i" in
    18) printf "\r\n## K-Mapy o 3 prommennych \r\n" >> priklady.md
        b=2
      ;;
    19) printf "\r\n## K-Mapy o 4 prommennych \r\n" >> priklady.md
        b=2
      ;;
    20) printf "\r\n## K-Mapy o 5 prommennych \r\n" >> priklady.md
        b=2
      ;;
    21) printf "\r\n## K-Mapy o 3 prommennych - Bez Mapy\r\n" >> priklady.md
        b=6
      ;;
    22) printf "\r\n## K-Mapy o 4 prommennych - Bez Mapy\r\n" >> priklady.md
        b=6
      ;;
    23) printf "\r\n## K-Mapy o 5 prommennych - Bez Mapy\r\n" >> priklady.md
        b=4
      ;;
    24) printf "\r\n## Prevod disjunktni -> konjunktni 3 promenne\r\n" >> priklady.md
        b=6
      ;;
    25) printf "\r\n## Prevod disjunktni -> konjunktni 4 promenne\r\n" >> priklady.md
        b=6
      ;;
    16) printf "\r\n## Prevod disjunktni -> konjunktni 5 promenne\r\n" >> priklady.md
        b=4
      ;;
    17) printf "\r\n## Prevod konjunktni -> disjunktni 3 promenne\r\n" >> priklady.md
        b=6
      ;;
    28) printf "\r\n## Prevod konjunktni -> disjunktni 4 promenne\r\n" >> priklady.md
        b=6
      ;;
    *)  printf "\r\n## Prevod konjunktni -> disjunktni 5 promenne\r\n" >> priklady.md
        b=4
      ;;
  esac
  for (( j = 1; j <= $a + 1; j++ )); do
    ./DIT $i >> priklady.md
    sleep 1
    if !(( $j % $b )); then
      echo "\newpage" >> priklady.md
    fi
  done
  echo "\newpage" >> priklady.md
done
