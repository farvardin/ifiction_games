Version 1 of AideIF by Eric Forgeot begins here.


"Aide sur l'IF de façon générale."

Include Simple Chat by Mark Tilford.

To say simple chat zero option:
	say "ou 0 pour quitter[run paragraph on]".

[Include Simple Chat Fr by Eric Forgeot.]
Include Basic Screen Effects by Emily Short.


To say lire aide:
	say "Ceci est un jeu d[']aventure textuel.[line break]Veuillez taper vos instructions avec des mots simples. Par exemple 'descendre', 'aller au nord', 'fouiller objet' etc... [line break]Pour obtenir des indications supplémentaires, les commandes 'astuces', ou 'solution' pourront vous aider. De plus, la commande spéciale 'aide IF' vous renseignera un peu plus sur comment fonctionne un tel jeu d[']aventure, avec des exemples de commandes à taper.".

Understand "aide" as a mistake ("[lire aide]").

After printing the banner text, say "[italic type]Tapez « aide » pour obtenir des indications sur ce jeu.[roman type][paragraph break]".



StartAideIF, IntroAideIF, CommuniquerAideIF, HintsAideIF are chat nodes.

Report giving link to StartAideIF: say "Aide" instead.
Report giving text for StartAideIF: instead say "Ceci est une présentation des jeux d[']aventure textuels. Veuillez taper le numéro de la rubrique à visiter.".
Carry out finding responses to StartAideIF: link to IntroAideIF; link to CommuniquerAideIF; link to HintsAideIF.

Report giving link to IntroAideIF: say "Introduction" instead.
Report giving text for IntroAideIF: instead say "[lire IntroAideIF]".
Carry out finding responses to IntroAideIF: link to IntroAideIF; link to CommuniquerAideIF; link to HintsAideIF.

Report giving link to CommuniquerAideIF: say "Communiquer avec l[']histoire" instead.
Report giving text for CommuniquerAideIF: instead say "[lire CommuniquerAideIF]".
Carry out finding responses to CommuniquerAideIF: link to IntroAideIF; link to CommuniquerAideIF; link to HintsAideIF.

Report giving link to HintsAideIF: say "Astuces diverses, si vous êtes coincé" instead.
Report giving text for HintsAideIF: instead say "[lire HintsAideIF]".
Carry out finding responses to HintsAideIF: link to IntroAideIF; link to HintsAideIF; link to HintsAideIF.





Asking for helpIF is an action out of world.

Understand "aide IF" and "aideif" as asking for helpIF.

Carry out asking for helpIF:
     run a conversation from StartAideIF.
    

To say lire IntroAideIF:
	say "[bold type]Bienvenue dans le monde de la Fiction Interactive[roman type]
[line break]
Dans les romans de fictions interactives, vous contrôlez le personnage principal. Ses épreuves, et ses choix, sont les vôtres.[line break]
[line break]
Une aventure interactive vous raconte le début d'une histoire. Ensuite c'est à vous de décider ce que le personnage devra faire. Vous tapez des commandes pour les actions à accomplir, et l'histoire vous répond ce qui se passe ensuite. [line break]
[line break]
Une partie de votre rôle est d'aider ce personnage principal à surmonter des obstacles dans sa progression : résoudre des problèmes, étudier ce qui se passe dans l'histoire, découvrir des pistes pour atteindre de nouveaux endroits et objets. Cet aspect des fictions interactives se passe comme dans un jeu.[line break]
[line break]
Et une partie de votre rôle est de l'aider à prendre des décisions. Une fiction interactive peut avoir plusieurs fins, en fonction de vos choix. Cet aspect est comme dans un histoire, mais une histoire ouverte.[line break]
[line break]";
say "Si vous aimez les fictions interactives, vous en trouverez un grand nombre de disponibles, la plupart gratuites, mais en anglais, la communauté française étant plus réduite dans ce créneau. Il existe dans notre langue quelques quinzaines de jeux originaux récents, mais on peut également trouver d'anciens jeux jouables avec un émulateur. Ces jeux (français, anglais, allemands, espagnols, italiens, suédois... pour ceux qui comprennent également ces langues) sortent dans de nombreux styles différents, certains plus proche du jeu, d'autres plus proche de la narration, de l'histoire. Certains sont difficiles, d'autres plus simples ; certains sont sérieux et graves, d'autres plus amusants ou sur des thèmes légers. Et, comme pour les livres, les oeuvres de fictions interactives existent dans de nombreux genres : médiéval fantastique (heroic fantasy), mystère, horreur, science-fiction, amour, historique, surréaliste et vie de tous les jours.  [line break]
[line break]
[line break]
[line break]";

to say lire CommuniquerAideIF:
	say "[bold type]Communiquer avec l'histoire[roman type]
Vous contrôlez la fiction interactive en donnant à votre avatar dans l'histoire des commandes tapées au clavier, généralement une instruction à l'impératif.[line break]
[line break]
Les fictions interactives peuvent analyser et comprendre de nombreux verbes, ainsi que le nom des objets qui apparaissent dans l'histoire. La plupart de ce que vous taperez sera de la forme VERBE OBJET : une action à faire, et un objet sur lequel agir. En fonction de l'action, il pourra être approprié d'ajouter un complément avec un second objet : METTRE LE POISSON SUR LE PLAT par exemple.[line break]
[line break]";
say "Ce qui suit est un aperçu des types d'actions possibles dans une fiction interactive conventionnelle. Il faut quand même préciser que toutes les fictions interactives ne se conforment pas forcément à ces descriptions, vous pourrez rencontrer des histoires avec des formes très différentes pour décrire le monde.[line break]
[line break]";
say "[bold type][italic type]La vue et les autres sens.[roman type][line break]
Vous pouvez commencer à vous familiariser avec votre environnement. Dans beaucoup d'histoires vous recevrez une description des environs à chaque fois que vous entrerez dans une nouvelle pièce.[line break]
[line break]
Si vous voulez relire cette description, vous pouvez la voir de nouveau en tapant REGARDER (ou look, abréviation L). Vous pouvez également en apprendre un peu plus sur un objet en tapant, par exemple, EXAMINER LE FOSSÉ. (Comme vous utiliserez fréquemment cette commande EXAMINER, elle a été abrégée en X)[line break]
[line break]
La plupart des objets que vous trouvez dans une histoire peuvent être examinés, y compris vous-même. Vous pourrez également essayer vos autres sens : ECOUTER, SENTIR, TOUCHER et GOÛTER.[line break]
[line break]
[bold type]Se déplacer[roman type][line break]
Vous aurez rapidement envie d'explorer les environs. Généralement, pour bouger il suffit d'entrer la  direction : ALLER AU NORD par exemple, ou juste N.[line break]
Il est courant, même si ce n'est pas universel, de pouvoir utiliser les huit directions de la boussole, ainsi que DEDANS, DEHORS, MONTER (HAUT) et DESCENDRE (BAS). La « barre de statut » en haut de l'écran contient parfois des informations utiles à propos de l'endroit où vous vous trouvez.[line break]
[line break]
Bien entendu certaines histoires ne contiennent pas d'exploration, en ce cas vous pouvez découvrir que vous êtes bloqué dans une seule pièce, que l'histoire donne d'autres moyens pour se déplacer, ou que celle-ci ne parle pas du tout de « pièces ».[line break]
[line break]
[bold type]Utiliser les objets[roman type][line break]
Les objets que vous trouverez sont des moyens pour que les  événements arrivent. Beaucoup fonctionnent comme vous vous y attendez, par rapport à votre expérience de la vie de tous les jours, mais d'autres ont des propriétés spéciales uniques à l'histoire. La plupart se manipulent avec PRENDRE, LAISSER, METTRE SUR, ou METTRE DANS d'autres objets.[line break]
[line break]
Une fois que vous en aurez quelques uns, vous pourrez faire l'INVENTAIRE (abréviation I), et obtenir une liste des choses que vous portez. C'est souvent une bonne idée de garder tous les objets que vous pouvez trouver car ils pourraient servir plus tard.[line break]
[line break]
Il y a bien entendu beaucoup plus à faire avec les objets que les transporter d'une pièce à l'autre. Certains peuvent être portés, mangés, ouverts, déverrouillés et ainsi de suite. Les machines peuvent être allumées et éteintes. Des sujets d'étude peuvent être trouvés dans des livres et des travaux de référence.[line break]";
say "
La présence d'un objet signifie généralement que l'histoire va comprendre plus tard des tentatives pour l'utiliser : si on vous donne une pelle, cela veut dire qu'à un moment donné vous aurez sans doute besoin de CREUSER.[line break]
[line break]
[bold type]Rencontrer des gens[roman type][line break]
En plus des objets, vous pourrez découvrir d'autres personnages. Ils peuvent avoir toute sorte de rôles, certains sont ici pour que vous leur parliez, d'autres sont juste là pour pour gêner. Vous pouvez les EMBRASSER si vous ressentez de l'amitié, les ATTAQUER dans le cas contraire, et souvent DONNER et MONTRER des choses que vous transportez.[line break]
[line break]
Les méthodes de communication avec les autres personnages varient souvent grandement d'une histoire à l'autre. Généralement l'histoire donne des instructions à ce sujet si cela a un rôle important dans le jeu. Sinon il est souvent possible de QUESTIONNER quelqu'un AU SUJET de quelque chose, PARLER à quelqu'un de quelque chose, ou simplement PARLER à quelqu'un. La dernière solution peut produire un menu avec des phrases à choisir pour exprimer ses choix, ou bien débuter toute une série de conversation déjà établie en fonction de ce qui se passe dans l'histoire.[line break]
[line break]
Parfois une histoire peut comprendre des commandes plus abstraites (INSULTER une personne, SALUER une personne, etc), des instructions pour d'autres personnages (BOB, VA AU SUD), ou même des conversations plus libres (BOB, SALUT).[line break]
[line break]
[bold type]Démarrer, et arrêter[roman type][line break]
Quelques autres commandes vous permettent de gérer le jeu. À n'importe quel moment, vous pouvez SAUVER (ou sauvegarder) l'état du jeu, comme on pourrait mettre un signet dans un livre. Il n'y a pas de limite dans le nombre de parties sauvegardées, aussi faites-en autant que vous voulez. CHARGER va ouvrir une ancienne partie sauvegardée et vous permettra de la reprendre là où elle s'était arrêtée.[line break]
[line break]
Quand vous êtes prêt à arrêter de jouer, QUITTER terminera votre session de jeu.[line break]
[line break]";
say "
Si vous voulez garder une trace de ce que vous avez joué, vous pouvez taper TRANSCRIPTION n'importe quand et cela commencera un journal de ce qui vous arrive. N'oubliez pas de taper TRANSCRIPTION OFF à la fin, pour clore et enregistrer ce journal.[line break]
[line break]
Enfin, si vous avez essayé quelque chose dont vous n'aimez pas le résultat, vous pouvez ANNULER (undo) les dernières actions, même si c'était celles qui ont conduit à la fin du jeu.[line break]
[line break]
Autres mots utiles...[line break]
TOUT se réfère à tous les objets dans le champ de vision, ainsi PRENDRE TOUT va vous faire ramasser tous les objets transportables. (Attention, car parfois ce genre de commande peut gâcher le plaisir de jouer)[line break]
[line break]
ENCORE répète la dernière action réalisée.[line break]
[line break]
Les adverbes, qui ajoutent des précisions sur les actions (comme rapidement, doucement) ne sont généralement pas utiles dans le jeu, et ne seront pas compris par l'interpréteur.[line break]
[line break]
Vous n'avez normalement pas besoin de vous référer à des parties spécifiques du corps, ainsi on ne dira pas FRAPPER LA PORTE AVEC MON POING, mais juste FRAPPER LA PORTE.[line break]
[line break]
Si le jeu vous pose une question parce qu'il y a des mots ambigus, comme « précisez : le cheval blanc ou le cheval brun ? », vous pourrez répondre avec juste le nom que vous voulez, voire avec seulement l'adjectif ou la précision à apporter : ici BRUN ou CHEVAL BRUN pourra être une réponse correcte.[line break]
[line break]";

to say lire HintsAideIF:
	say "[bold type]Si vous êtes coincé[roman type][line break]
	Certaines fictions interactives sont faciles à terminer, d'autres sont beaucoup plus difficiles. Si vous vous retrouvez avec un obstacle que vous ne pouvez pas surmonter, essayez de revenir sur ce que vous savez déjà. Regardez dans votre inventaire, et remémorez-vous les endroits déjà visités. Parfois le problème dans un lieu trouve sa résolution ailleurs.[line break]
[line break]
Soyez attentif et minutieux. Essayez de regarder derrière et en dessous des objets qui pourraient dissimuler d'autres choses. Soyez certain d'avoir ouvert tous les objets qui pourraient en contenir d'autres, et d'avoir été dans toutes les pièces que vous pouvez atteindre. [line break]
[line break]
Lisez le texte attentivement. Est-ce qu'il n'aurait pas suggéré certaines actions ? L'histoire contient souvent des indices à propos de ce que vous devrez faire ensuite.[line break]
[line break]
Soyez certain d'avoir lu toutes les instructions spécifiques ou les aides qui accompagnent le jeu. Beaucoup d'œuvres de fictions interactives contiennent des commandes spécifiques que l'on ne retrouve pas ailleurs, aussi cela vaut la peine d'être sûr que vous ne manquez aucune information essentielle au jeu. Considérez le type de jeu auquel vous jouez. Est-ce qu'il y aurait des règles qui s'appliqueraient dans ce monde et pas dans le nôtre ? Comment pourrez-vous tirer parti de la logique interne au jeu ?[line break]
[line break]
Comparez vos notes. Si vous pouvez trouver quelqu'un avec qui jouer, vous pourrez remarquer que cette collaboration rend les énigmes plus faciles à résoudre.[line break]
[line break]
Prenez une pause. Parfois la bonne idée viendra à vous tandis que vous ferez quelque chose d'autre.[line break]
[line break]
Reformulez. Si vous pensez être certain que l'action que vous tentez est la bonne, mais que l'histoire ne comprend pas votre demande, essayez de trouver une autre manière d'écrire les instructions.[line break]
[line break]
Essayez de taper AIDE ou HINTS au cours de l'histoire. Parfois on peut y trouver des conseils pour le joueur.[line break]
[line break]
Enfin, si vous ne pensez pas pouvoir vous en sortir sans aide extérieure, vous pouvez poster vos questions sur une liste de discussions existante, comme rec.games.int-fiction (anglais) ou le forum ifiction-fr (français), qui peuvent être atteint par ces adresse :[line break]
[line break]
http://groups.google.com/group/rec.games.int-fiction[line break]
http://ifiction.free.fr/[line break]
[line break]";
say "
[line break]
[line break]
Quelques interpréteurs courants [line break]
Zoom pour Macintosh : http://www.logicalshift.demon.co.uk/mac/zoom.html[line break]
Zoom pour Unix : http://www.logicalshift.demon.co.uk/unix/zoom/[line break]
Windows Frotz pour Windows : http://www.d.kinder.btinternet.co.uk/frotz.html[line break]
Gargoyle : http://ccxvii.net/gargoyle[line break]
Spatterlight : http://ccxvii.net/spatterlight/ [line break]
[line break]
[line break]
Un mot sur la technologie utilisée[line break]
La plupart des fictions interactives viennent sous forme de fichier d'histoire. Ces fichiers ne sont pas comme des fichiers de texte ou de musique : comme ils doivent interagir avec le joueur, ce sont des programmes. Plutôt que d'être conçus comme un programme limité à un système d'exploitation donné, ils sont fait pour tourner dans une machine virtuelle adaptée à la fiction interactive. L'avantage de cela est que le même fichier contenant l'histoire peut être lu sur n'importe quel type d'ordinateur, d'architecture ou de système (Macintosh, Pc Mswindows, Linux, *Bsd, Atari, Amiga, Beos, Riscos, Solaris, Pocket pc...), et que ce fichier d'histoire est tellement isolé de l'ordinateur hôte qu'il presque impossible d'y faire tenir des instructions mauvaises qui pourraient altérer d'autres fichiers ou l'ordinateur. (Cela ne s'est jamais vu jusqu'à présent.)[line break]
[line break]
Le désavantage à cela, c'est qu'un fichier d'histoire ne peut être utilisé qu'avec un programme appelé « interpréteur ». Mais une fois que vous aurez installé une fois pour toute un de ces interpréteurs, vous pourrez jouer une gamme étendue de jeux. Certains de ces interpréteurs peuvent également vous aider à organiser votre collection d'histoires et de garder trace de vos sauvegardes.[line break]
[line break]
Si vous avez une fiction interactive à jouer, vous avez probablement reçu avec un interpréteur, ou du moins des instructions pour en trouver un.[line break]
[line break]";
say "
Dans le cas contraire, vous pouvez en trouver sur internet. Il existe plusieurs machines et systèmes de fictions interactives, mais si vous avez ce guide, vous l'avez probablement eu avec un fichier pour le système Inform, qui est d'ailleurs un des seuls système pleinement compatible en français. Dans ce cas, le fichier en lui-même doit avoir une extension comme .z5, .z8, .zblorb, .blb ou .ulx. A l'heure actuelle nous pouvons citer ces interpréteurs pour Z-machine : Zoom (Mac OS X et Unix) de Andrew Hunder, et Frotz pour Windows de David Kinder. A noter également le multi-interpréteur Gargoyle (Linux / Windows) et Spatterlight (Mac OS X) de Tor Andressen, qui permet également de lire des jeux conçus avec un autre système qu'Inform (comme Tads, Hugo, Alan, Adrift...). Des interpréteurs pour des plateformes moins connues existent également, et il est même possible de jouer à des fictions interactives sur PDA ou téléphone, bien que cela puisse être plus long pour interagir avec l'histoire dans ces derniers cas.[line break]
[line break]
Lorsque vous prendrez un interpréteur, vous pourrez vérifier que celui-ci permet de lire également les fichiers dans un format appelé « blorb ». (BLORB, tout comme FROTZ, sont des mots inventés provenant d'ancien jeux commerciaux de fiction interactive.) Un fichier blorb peut également contenir non seulement l'histoire en elle-même, mais également une couverture ainsi que d'autres ressources, comme des sons et des images pour le jeu.[line break]
[line break]
Les interpréteurs Z-machine plus anciens ne permettent pas de profiter des fichiers blorb, aussi selon l'utilisation que vous en ferez, choisissez-en un qui soit adapté à votre cas.[line break]
[line break]";

To say lire CommandesAideIF:
	say "[bold type]Commandes usuelles[roman type]
[line break]
Tous ces mots ne sont pas forcément importants dans toutes les histoires : comme elles sont toutes sur différents sujets, elles utilisent généralement du vocabulaire différent. Une histoire peut avoir des instructions spéciales, et ouvrir des indications sur les nouvelles commandes en cours de jeu. Malgré tout, il y a un vocabulaire de base que la plupart des fictions interactives vont pouvoir comprendre, et connaitre ces commandes vous permettra de commencer à jouer à de nombreuses oeuvres.[line break]
(ndt : dans ces traductions des instructions anglaises, les accents n'ont pas été indiqué car parfois certains jeux ou interpréteurs ne savent pas les gérer correctement)[line break]";
say "acheter [bracket]quelque chose[close bracket][line break]
aide[line break]
aller [bracket]direction : n, s, e, o, nordouest, nord-ouest, nw, ne, sw, se, bas, haut etc...[close bracket][line break]
allumer [bracket]quelque chose[close bracket][line break]
attaquer [bracket]quelque chose[close bracket] ou [line break]
attendre (z)[line break]
boire [bracket]quelque chose[close bracket][line break]
bouger[line break]
bouger [bracket]quelque chose de porté[close bracket][line break]
bruler [bracket]quelque chose[close bracket][line break]
changer[line break]
charger[line break]
consulter [bracket]texte[close bracket] dans [bracket]quelque chose[close bracket][line break]
couper [bracket]quelque chose[close bracket][line break]
creuser [bracket]quelque chose[close bracket][line break]
decoller [bracket]quelque chose[close bracket][line break]
descendre [bracket]quelque chose[close bracket][line break]
désolé[line break]
deverrouiller [bracket]quelque chose[close bracket] avec [bracket]quelque chose[close bracket][line break]
donner [bracket]quelque chose[close bracket] à [bracket]quelqu'un[close bracket][line break]
dormir[line break]
ecouter[line break]
ecouter [bracket]quelqu'un[close bracket][line break]
embrasser [bracket]quelqu'un[close bracket][line break]
entrer [bracket]quelque chose / quelque part[close bracket][line break]
eteindre [bracket]quelque chose[close bracket][line break]
examiner (x) [bracket]quelque chose[close bracket][line break]
fermer [bracket]quelque chose[close bracket][line break]
fouiller [bracket]quelque chose[close bracket][line break]
frotter [bracket]quelque chose[close bracket][line break]
gouter [bracket]quelque chose[close bracket][line break]
grimper [bracket]quelque chose[close bracket] [line break]
inventaire (i)[line break]";
say "
laisser [bracket]quelque chose (de tenu)[close bracket][line break]
manger [bracket]quelque chose[close bracket][line break]
mettre [bracket]quelque chose (pour s'habiller)[close bracket][line break]
mettre [bracket]quelque chose[close bracket] dans [bracket]quelque chose[close bracket][line break]
mettre [bracket]quelque chose[close bracket] sur [bracket]quelque chose[close bracket][line break]
montrer [bracket]quelque chose[close bracket] à [bracket]quelqu'un[close bracket][line break]
nager[line break]
non[line break]
oui[line break]
ouvrir [bracket]quelque chose[close bracket][line break]
parler à [bracket]quelqu'un[close bracket][line break]
penser[line break]
pivoter [bracket]quelque chose[close bracket][line break]
placer [bracket]quelque chose[close bracket] avec [bracket]quelque chose[close bracket][line break]
pousser [bracket]quelque chose[close bracket][line break]
pousser [bracket]quelque chose[close bracket] vers [bracket]direction[close bracket][line break]
prendre [bracket]quelque chose[close bracket][line break]
prier[line break]
questionner [bracket]quelqu'un[close bracket] sur [bracket]quelque chose[close bracket][line break]
quitter [line break]
quitter (q)[line break]
raconter [bracket]quelque chose[close bracket] à [bracket]quelqu'un[close bracket][line break]
recommencer[line break]
regarder[line break]
regarder dans [bracket]quelque chose[close bracket][line break]
regarder sous [bracket]quelque chose[close bracket][line break]
remplir [bracket]quelque chose[close bracket][line break]
repondre[line break]
retirer [bracket]quelque chose (de porté)[close bracket][line break]
reveiller [bracket]quelqu'un[close bracket][line break]
s'assoir sur [bracket]quelque chose[close bracket][line break]
saluer[line break]
sauter[line break]
sauter par dessus [bracket]quelque chose[close bracket][line break]
sauver (sauvegarder)[line break]
score[line break]
se reveiller[line break]
sentier [bracket]quelque chose[close bracket][line break]
serrer [bracket]quelque chose[close bracket][line break]
souffler [bracket]quelque chose[close bracket][line break]
tirer [bracket]quelque chose[close bracket][line break]
toucher [bracket]quelque chose[close bracket][line break]
tourner [bracket]quelque chose[close bracket][line break]
transcription [bracket]on / off[close bracket][line break]
verrouiller [bracket]quelque chose[close bracket] avec [bracket]quelque chose[close bracket][line break]
[line break]
[line break]";


To say lire TranscriptSample:
say "
[bold type]Exemple de transcription[roman type]
[line break]
Voici un exemple de jeu avec une fiction interactive. Les commandes en gras précédées du signe > sont les instructions du joueur, les autres textes sont les réponses données par l'histoire. Cette transcription ne présente pas toutes les commandes possibles, mais permet d'en montrer quelques unes, et comment résoudre la problématique d'une histoire.[line break]
[line break]
Petit Gnome[line break]
Une aventure dans le jardin par Otto Grimwald[line break]
Release 1 / Serial number 061101 / Inform 7 build 3Z95 (I6/v6.31 lib 6/11N) [line break]
[line break]
Sur le toit[line break]
Après avoir effectué votre travail sur l'ensemble des bâtiments de cette petite ville provinciale, vous vous trouvez enfin sur le toit de la dernière des maisons à visiter.[line break]
[line break]
Vous pouvez voir une cheminée (qui est vide) et un traineau (qui est vide).[line break]
[line break]";
wait for any key;
say "> descendre [line break]
[line break]
Un beau jardin[line break]
Ce petit jardin propret vous fait penser au vôtre. Sans doute qu'il y a là quelques gnomes agiles qui viennent l'entretenir. Il continue à s'étendre, sur votre droite, à l'est. La maison se trouve au sud.[line break]
Vous pouvez voir une porte d'entrée.[line break]
[line break]
>ouvrir la porte[line break]
Cette porte est verrouillée.[line break]
>casser la porte[line break]
Voudriez-vous vous reconvertir dans le braquage ? Qu'en penserait votre femme ?[line break]
[line break]
>pousser la porte[line break]
Vous voyez une voiture de police qui passe par là. Votre attitude suspecte étonne les policiers qui vous arrêtent et vous mettent directement en prison.[line break]
[line break]
    *** Vous avez perdu ***[line break]
[line break]
Voulez-vous RECOMMENCER, CHARGER une partie sauvegardée ou quitter (QUIT) [line break]
[line break]";
say "
> annuler[line break]
Un beau jardin[line break]
[bracket]Action précédente annulée.[close bracket][line break]
[line break]
> aller à droite [line break]
[line break]
Le bout du jardin[line break]
Vous êtes près de la limite de la propriété. Au delà s'étendent les autres jardins du voisinage.[line break]
[line break]
Vous pouvez voir un gnome.[line break]
[line break]
> questionner le gnome au sujet de la maison [line break]
Le gnome vous regarde sans comprendre. Vous savez parler le langage gnome, mais celui-ci est resté si longtemps auprès des humains qu'il ne le connaît plus bien lui-même. Essayez de le questionner autrement ou sur un autre sujet.[line break]
[line break]
> faire peur au gnome [line break]
Il prend peur et se sauve en courant, laissant derrière lui une clé et une paire de chaussons.[line break]
[line break]
> prendre les chaussons et la clef [line break]
deux chaussons: Ok.[line break]
clef: Ok.[line break]
[line break]
> aller à l'ouest [line break]
[line break]
Un beau jardin[line break]
Ce petit jardin propret vous fait penser au vôtre. Sans doute qu'il y a là quelques gnomes agiles qui viennent l'entretenir. Il continue à s'étendre, sur votre droite, à l'est. La maison se trouve au sud.[line break]";
say "
[line break]
Vous pouvez voir une porte d'entrée.[line break]
[line break]
> ouvrir la porte avec la clef [line break]
Vous déverrouillez la porte d'entrée.[line break]
[line break]
> ouvrir la porte [line break]
Vous ouvrez la porte d'entrée.[line break]
[line break]
> entrer[line break]
Elle est déjà ouverte.[line break]
[line break]
Salon[line break]
C'est un joli salon.  Vous voyez la cheminée au fond de la pièce, un feu joyeux y brûle. [line break]
[line break]
Vous pouvez voir une porte d'entrée, des chenets, un feu et un vase.[line break]
[line break]
> prendre le vase [line break]
Ok.[line break]
[line break]
> éteindre le feu [line break]
Vous utilisez l'eau du vase pour éteindre le feu.[line break]
[line break]
Vous éteignez le feu.[line break]
[line break]
Votre score vient d'augmenter de un point.[line break]
[line break]";
say "
> mettre les chaussons sur les chenets [line break]
Ils ont dû oublier de le faire. Heureusement que vous êtes consciencieux et que vous le faite à leur place.[line break]
[line break]
Vous mettez deux chaussons sur des chenets.[line break]
[line break]
Votre score vient d'augmenter de un point.[line break]
[line break]
> sortir [line break]
[line break]
Un beau jardin[line break]
[line break]
> monter [line break]
Les montagnes au loin sont déjà auréolées des lueurs de l'aurore, vous êtes impatient de finir ce travail et de rentrer chez vous.[line break]
[line break]
Sur le toit[line break]
[line break]
Vous pouvez voir une cheminée (qui est vide) et un traineau (qui est vide).[line break]
[line break]
> prendre le cadeau [line break]
Ok.[line break]
[line break]
> mettre le cadeau dans la cheminée [line break]
Vous mettez le cadeau dans la cheminée.[line break]
[line break]
> entrer dans le traineau[line break]
Vous entrez dans le traineau.[line break]
[line break]
Vous avez enfin réussi à terminer votre tournée de cette année. Il est temps de rentrer chez vous.[line break]
[line break]
    *** Vous avez gagné ***[line break]
[line break]
[line break]";
say "
    [line break]
[bold type]Ressources annexes[roman type]
[line break]
[line break]
La plupart des fictions interactives qui sortent actuellement sont disponibles librement, ce qui veut dire que vous êtes autorisé à les télécharger et y jouer gratuitement et sans restriction sur n'importe quel ordinateur. [line break]
[line break]
[line break]
[line break]
[line break]
[line break]
Veuillez vous référer pour le moment au site http://ifiction.free.fr pour obtenir des liens vers diverses ressources en français et dans d'autres langues. Vous pourrez également obtenir des informations sur le processus de création de jeux si vous désirez en faire vous-même.[line break]
[line break]
[line break]
[line break]
[line break]
[line break]

Documentation originale écrite par Emily Short, traduction  de l'anglais et adaptation par Eric Forgeot[line break][line break]
[line break]".






AideIF ends here.

---- DOCUMENTATION ----

Section: 

	Rajoutez simplement cette extension pour inclure la commande "Aide IF" qui permettra d'indiquer un texte d'introduction aux fictions interactives. Ceci prendra environ 30 ko en plus dans votre jeu final.


Example: * Aide - Un exemple d'aide à include dans vos jeux.

	*: "Aide"

	Include French by Eric Forgeot.
	Use French Language.
	
	Include AideIF by Eric Forgeot.
	
	To say lire aide:
		say "Ceci est un jeu d[']aventure textuel.[line break]Pour obtenir des indications supplémentaires, les commandes 'astuces', ou 'solution' (non implémentées dans ce court exemple) pourront vous aider. De plus, la commande spéciale 'aide IF' vous renseignera un peu plus sur comment fonctionne un tel jeu d[']aventure, avec des exemples de commandes à taper. ".

	Understand "aide" as a mistake ("[lire aide]")

    After printing the banner text, say "[italic type]Tapez « aide » pour obtenir des indications sur ce jeu.[roman type][paragraph break]".



