#!/bin/bash
g++ DITgenerator.cpp -o DIT -std=c++11
touch vygenerovane_priklady.md
rm vygenerovane_priklady.md
touch vygenerovane_priklady.md
a=70
for (( i = 0; i <= 13; i++ )); do
  ./DIT $i $a >> vygenerovane_priklady.md
done

touch priklady.md
rm priklady.md
touch priklady.md
printf "# 1) PRIKLADY \r\n" >> priklady.md
printf "V prvni casti jsou neresene priklady, v druhe casti jsou priklady s resenim. \r\n\r\n" >> priklady.md
./DIT 16 vygenerovane_priklady.md >> priklady.md
printf "# 2) PRIKLADY S RESENIM \r\n" >> priklady.md
printf "V teto casti jsou priklady resene priklady z minule casti \r\n\r\n" >> priklady.md
cat vygenerovane_priklady.md >> priklady.md
rm vygenerovane_priklady.md
