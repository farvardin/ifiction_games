Adaptation et traduction de la bibliothèque PunyInform (version 1.9) en français.

Version 0.9.5-bêta  
Lionel Ange, 2020-2021.  
Licence Creative Commons BY-SA 4.0 (CC BY-SA 4.0)  
https://creativecommons.org/licenses/by-sa/4.0/deed.fr  

Site personnel : https://micro-ifictions.com/

**PunyInform** est une bibliothèque écrite en Inform 6, par Johan Berntsson et Fredrik Ramsberg, permettant de créer des jeux d’aventure textuels – ou fictions interactives –, en utilisant la machine virtuelle Z-machine. Ces jeux sont jouables sur des ordinateurs 8-bit ainsi que sur des plateformes récentes.

Le fichier source du jeu doit être encodé en UTF-8. La première ligne du fichier doit contenir l’option : **!% -Cu**

**Les articles**  
La propriété *article* d’un objet a été modifiée pour être compatible avec la langue française. Elle doit être initialisée avec l’une des constantes suivantes en fonction du genre et du nombre de l’objet (ne pas mettre de propriété *article* pour un nom propre) :  
```
ARTICLE_UNE      la/une pomme  
ARTICLE_UN       le/un dé  
ARTICLE_DES      les/des pommes  
ARTICLE_DE_LA    la/de la confiture  
ARTICLE_DU       le/du sucre  
ARTICLE_UNE_     l’/une orange  
ARTICLE_UN_      l’/un œuf  
ARTICLE_DE_L     l’/de l'eau
```
Les attributs de l'objet doivent être correctement initialisés en fonction du genre et du nombre : *proper; female; pluralname*.
```
    Object pomme "pomme"
    with
        name 'pomme',
        article ARTICLE_UNE
    has edible female;
```

**Les pronoms**  
La gestion des pronoms a été simplifiée par rapport à la bibliothèque standard 6.12 ; seuls les pronoms situés avant le verbe sont admis :  
– Le/la/les/l’ prendre ;  
– Le/la/les/l’ lui/leur donner ;  
– Lui/leur donner la pomme ;  
– Le/la/les/l’ donner à Julia.  

Le/la/les/l’ concernent les objets inanimés ; lui/leur, les objets ayant l’attribut *animate*.  
L’attribut *neuter*, associé à un objet, permet d’attribuer les pronoms le/la/les/l’ aux objets animés ou inanimés.

La forme impérative n’est pas supportée : « Julia, prends la pomme ». Cela n’a pas de sens avec des verbes à l’infinitif.

La constante **OPTIONAL_TALK_TO** permet d’activer la grammaire du verbe *parler à qqn* sans la nécessité d’avoir en complément un sujet de conversation.

**Les accents**  
*Version 3* :  
La saisie du joueur ainsi que les mots du dictionnaire ne doivent pas être accentués (verbes, noms des objets, etc.)  
*Version 5-8* :   
Si la constante **AVEC_ACCENTS** est définie, la saisie du joueur doit obligatoirement être accentuée ainsi que tous les mots du dictionnaire.  
Si la constante **AVEC_ACCENTS** n'est pas définie, la saisie du joueur ainsi que les mots du dictionnaire ne doivent pas être accentués (comme pour la version 3)

Lors d'une saisie sans accents (v3, v5-8), la constante **DE_A_JOUER** permet d’éviter, dans la mesure du possible, un conflit avec la préposition « **de** ». Seul l'objet dé au singulier, et non suivi d’un adjectif, est géré ; il est possible d'adapter le code pour un usage particulier. L’objet « dé à jouer » doit être nommé « **'dj'** » dans sa propriété **name**.

```
    Object de_6 "dé"
    with
        name 'dj',
        article ARTICLE_UN
    has;
```
**Documentation**  
https://github.com/johanberntsson/PunyInform/tree/master/documentation  
http://www.inform-fiction.org/index.html

**Dépôts**  
Bibliothèque originale en anglais :  
https://github.com/johanberntsson/PunyInform  
Traduction de la bibliothèque en français :  
https://gitlab.com/auraes/punyinformfr

**Crédits**  
PunyInform a été conçu et réalisé par Johan Berntsson et Fredrik Ramsberg. Le codage a été réalisé par Johan Berntsson, Fredrik Ramsberg, Pablo Martinez et Tomas Öberg. Inclus du code de la bibliothèque standard Inform 6, par Graham Nelson.  
La traduction et l’adaptation en français ont été réalisées par Lionel Ange.

