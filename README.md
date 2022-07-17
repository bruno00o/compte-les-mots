# compte-les-mots
Compte le nombre d'occurences des mots dans un fichier texte

## Compilation

    make
    
## Exécution

    ./clm TEXTE [-a] [-n] [-s ou -p MOT] [-e ENTIER] [-test]
    
`TEXTE`est le nom du fichier (par exemple le fichier [test](textes/test.txt)
    
- `-a` : trie la réponse dans l'ordre lexicographique
- `-n` : trie la réponse selon le nombre d'occurences
- `-s MOT` : compte les occurences des mots qui suivent le mot MOT
- `-p MOT` : compte les occurences des mots qui précèdent le mot MOT
- `-e X` : compte les occurences des suites de X mots
- `-test` : permet de réaliser les tests

## Exemples

    ./clm textes/test.txt -a
    
```
deux : 3
deuxdeux : 1
trois : 1
un : 3
```

    ./clm textes/test.txt -n
    
```
deux : 3
un : 3
deuxdeux : 1
trois : 1
```

    ./clm textes/test.txt -s deux
    
```
deux : 2
deuxdeux : 1
```

⚠️ **ne prend pas en compte les majuscules**

    ./clm textes/test.txt -p deux
    
```
un : 1
deux : 2
```

    ./clm textes/test.txt -e 2
    
```
trois un : 1
un un : 1
un deux : 1
deux deux : 2
deux deuxdeux : 1
deuxdeux un : 1
```

Enfin, on peut utiliser plusieurs options :

    ./clm textes/test.txt -e 2 -n
    
```
deux deux : 2
deux deuxdeux : 1
deuxdeux un : 1
trois un : 1
un deux : 1
un un : 1
```
