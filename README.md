# Katsy projektit
Project 1

Lähdekoodi project 1 warmup to C and unix programming
https://github.com/Tissinapa/Katsy-projektit/blob/main/reverse.c

Ohjelma ajetaan käskyllä ./reverse.exe tiedosto
Nyt ohjelma lukee tiedoston linkitettyyn listaan, tulostaa tiedoston sisällön näytölle. 
Tämän jälkeen ohjelma kääntää linkitetyn listan ympäri ja tulostaa tiedoston sisällön uudestaan, mutta päinvastaisessa järjestyksessä.

Project 2 Unix utilities

Lähdekoodi project 2 my-cat
https://github.com/Tissinapa/Katsy-projektit/blob/main/my-cat.c

Ohjelma on käännetty komennolla gcc my-cat.c -o my-cat.exe std=c99 -Wall

Ohjelma ajetaan käskyllä ./my-cat jokinTiedosto

Ohjelma tulostaa tiedoston sisällön näytölle

Ohjelma ei täysin noudata tehtävänantoa. Virheenäkäsittelyssä ohjelma tulostaa näytölle "wcat: cannot open file"
Ohjelmaa oli helpompi testata koska testeissä vaadittiin edellä mainittua lausetta, muuten testit eivät olisi menneet läpi.

Lähdekoodi project 2 my-grep
https://github.com/Tissinapa/Katsy-projektit/blob/main/wgrep.c

Ohjelma on käännetty komennolla gcc -o wgrep wgrep.c -Wall -Werror

Ohjelma ajetaan käskyllä ./wgrep hakutermi tiedosto

Ohjelma ei täysin noudata moodlen tehtävän antoa vaan oli helpompi saada testit suoritettua kun noudatti projektissa annetun repon ohjeita.

Project 3 Unix shell

Lähdekoodi project 3 Unix shell
https://github.com/Tissinapa/Katsy-projektit/blob/main/wish.c

Ohjelma käännetty gcc wish.c -o wish.exe -std=c99 -Wall

Ohjelmaa ajetaan joko ./wish.exe tiedostoJossaOnKomento tai ./wish.exe jolloin ohjelma tulostaa wish> näytölle jolloin on valmis ottamaan käskyjä vastaa.

Ohjelma on vajavainen ja toimii ainakin käskyillä ls, pwd, cd, exit ja mkdir muista käskyistä en mene vannomaan toimiiko vaiko ei joten käytä ohjelmaa turvallisessa ympäristössä. 


Tekijä Akseli Hulkkonen
