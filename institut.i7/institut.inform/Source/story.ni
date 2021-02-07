"Sueurs froides à l'institut François-Marie Raoult" by "Otto Grimwald"

The story genre is "Speedif".   
The story creation year is 2008.

The story headline is "Une aventure".

The story description is "".

[
 http://fr.wikipedia.org/wiki/Breda_M1937 : une mitrailleuse lourde italienne
 http://fr.wikipedia.org/wiki/Kin%C3%A9toscope : un des premiers appareils de visualisation cinématographique 
 http://fr.wikipedia.org/wiki/Loi_de_Raoult : La pression de vapeur d'une solution idéale est dépendante de la pression partielle de chaque constituant et de leurs fractions molaires respectives.
 http://fr.wikipedia.org/wiki/Bonhomme_sept-heures : un personnage fictif maléfique
 http://fr.wikipedia.org/wiki/Sigogne ou http://fr.wikipedia.org/wiki/Cigogne : une ville ou un oiseau
]

Part 1 - Mise en place des options

Include French by Eric Forgeot.
Use French language.

[Include Boussole by Benjamin Roux.]
Include Basic Screen Effects by Emily Short.

Rule for deciding whether all includes scenery: it does not.

Use full-length room descriptions.
[The maximum score is 4.]
use no scoring.

Hinting is an action applying to nothing.
Understand "astuces" or "astuce" or "hint" or "hints" as hinting.

Carry out hinting:
	say "Dans ce jeu vous devez trouver un moyen de vous débarrassez du bonhomme sept-heure.[paragraph break]";
	if cigogne is in location, say "-> .";
	say "[line break]Il n[']y a pas d[']autres astuces pour le moment, mais vous pourrez réessayer cette commande dans un autre contexte pour découvrir de nouvelles suggestions.". 
	
To say lire aide:
	say "Version en développement. Une correction sera bientôt apportée avec beaucoup d'améliorations ! Les parties amusantes se feront APRÈS cette version !";
	say "";
	say "Pour avoir des indications supplémentaires veuillez taper 'astuces['], et pour la solution complète la commande est 'solution'.".

Helping is an action applying to nothing.

Understand "aide" or "info" or "information" or "informations" or "sos" as helping.

Carry out helping:
			say "[lire aide]".

Understand "credits" and "credit" as a mistake ("Première version réalisée en 3 heures et demi")

Understand "licence" and "auteur" as a mistake ("Cette histoire sous licence BSD-by a été réalisée par Eric Forgeot 2008 (c).")

Understand "solution" and "walkthrough" as a mistake ("ouvrir la porte/n/sud/sud/sud/x grille/nord/x grille/lire pancarte/escalader la grille/attaquer la cigogne/entrer dans le nid/x fusil/x breda/x kinetoscope/z/z/z/z/allumer mitrailleuse")


Casting xyzzy is an action applying to nothing.

Understand "xyzzy" as casting xyzzy.	

Carry out casting xyzzy: 
			say "[description du sort]".
		
To say description du sort:
		say "[one of].[stopping]".
		
To say (relevant time - a time) as 24h time: 
    let H be the hours part of relevant time; 
    let M be the minutes part of relevant time; 
    say "[H]:[if M is less than 10]0[end if][M]".

When play begins:
	change the time of day to 6:43 PM; 
	move sacoche to player;
	change the right hand status line to "Heure : [time of day as 24h time]".

A thing can be reachable. A thing is usually reachable.

Taking something not reachable is acting OutOfReach. Pushing or pulling or touching or rubbing or turning or tasting or smelling or searching or cutting or switching on or switching off or opening or closing or squeezing or burning or kissing or waving or entering something not reachable is acting OutOfReach.

Instead of acting OutOfReach:
	say "C[']est hors de portée.". 

A door is usually female. A door is seldom locked. 	

Understand the command "monter" as something new.
Understand "monter ->/à/a/au/en/vers/par/dans/sur/sous [something]" as climbing.
[Understand the command "monter" as climb.]


Part 2 - Le jeu et l[']histoire	

The dehors is a region. The dedans is a region. 

The Parc is a room in dehors. 
The institut is a room in dedans.
The musee is a room in dedans.
The loge is a room in dedans.

The nid is a container in parc.
The cigogne is a female animal in nid.

Some végétaux are backdrop in parc. Understand "branche" or "vegetation" or "vegetaux" or "vegetal" or "arbres" or "foret" or "arbre" or "fleurs" or "fleur" as végétaux. Instead of taking végétaux, say "Vous n[']êtes pas un vandale quand même, détruisant le travail des autres.".

The nid is not reachable. The description of nid is "[if player is not on toitReal]Un grand nid circulaire, de la taille d[']une roue de chariot, posé sur le toit du musée.[otherwise]Un grand nid circulaire, de la taille d[']une roue de chariot, posé sur un affaissement du toit du musée.[end if]".

The description of parc is "[one of]Le parc de l[']institut François-Marie Raoult, bien que réduit à sa plus simple expression, est régulièrement et consciencieusement entretenu par le gardien.[or]Le parc de l[']institut François-Marie Raoult.[stopping][if the player is not on toitReal] À l[']est se trouve l[']entrée du petit musée des anciennes technologies, tandis qu[']au nord il y a le bâtiment de l[']institut proprement dit, d[']où vous venez juste de sortir après une rude après-midi. La sortie se trouve au sud, près de la loge du concierge de l[']institut.[otherwise] Vous êtes actuellement sur le toit du musée.[end if]".

The Sortie is south from parc. The description of sortie is "La sortie au sud est bloquée par une barrière pendant la journée, et par une grille durant les heures de fermeture de l[']institut. Au nord se trouve le petit parc ainsi que l[']entrée de l[']institut. À l[']est il y a la loge du gardien.".

The grille is in sortie. The description of grille is "Zut ! Cet idiot de gardien est encore parti en avance, fermant la grille derrière lui !".

Instead of climbing grille:
	say "C[']est vraiment trop haut ici.".

[-- loge --]
The logeFake is female scenery in sortie. Understand "loge" as logeFake. The printed name of logeFake is "Loge". 

Instead of entering logeFake, try going east.
	
The Loge is east from sortie. The loge is inside from sortie. The printed name of loge is "Loge". The description of loge is "Un lieu délabré, digne des pires films d[']horreur : la peinture jaune sale des murs est complètement défraîchie, et des toiles d[']araignées immenses pendent du plafond.".

The peinture is female scenery in loge. Understand "murs" or "mur" as peinture.
Some toiles are female scenery in loge. Toiles are not reachable.

[-- institut -- ]
The institutFake is scenery in parc. Understand "institut" as institutFake. The printed name of institutFake is "institut".  

The printed name of institut is "Institut".  
The description of institut is "L[']institut François-Marie Raoult est un prestigieux centre de recherche dans le domaine de la linguistique et de la chimie. Après avoir passé ici votre thèse sur les consonnes affriquées post-alvéolaire voisées dans le Japonais à l[']ère Edo, vous avez décidé de continuer à travailler ici en tant que secrétaire de M. François-Sylvère de Freycinet, le président de l[']institut. Ce soir, vous êtes resté particulièrement tard...".

Instead of going nowhere when the player is in institut, say "Vous avez surtout envie de rentrer à cette heure-ci, en plus il n[']y a plus personne dans les locaux et l[']alarme risque de s[']armer très bientôt.".

[todo : faire player entre et  declenche alarme et fait venir la police ]

Instead of entering institutFake, try going north.
	
[The institut is north from parc.] The parc is outside from institut.

The toitFakeInstitut is female part of InstitutFake. The printed name of toitFakeInstitut is "toiture de institut". Understand "toiture" or "toiture institut" or "toiture de l'institut" or "toiture de institut" as toitFakeInstitut.

Instead of climbing toitFakeInstitut, say "Cela semble vraiment impossible, c[']est trop haut, et de toute façon la porte de l[']institut est encore ouverte.".


[-- musée --]
The museeFake is scenery in parc. Understand "musee" as museeFake. The printed name of museeFake is "musee". The description of museeFake is "Ce bâtiment détonnait un peu par rapport aux moulures raffinées de l[']institut à côté. Composé d[']un unique étage, les facades repeintes en violet foncé, il ressemblait plus à un café qu[']à une annexe de la prestigieuse université dont vous êtes l[']employé.".

Instead of entering museeFake, try going east.
	
[The musee is east from parc.] The parc is outside from musee. The printed name of musee is "Musée". 
The description of musee is "Même si ce n[']est pas très visible depuis l[']extérieur, ce musée a été aménagé dans une vieille grange, ou . Une petite ouverture permet d[']aller au sud.".

The loge is south from musee.

Instead of going outside from musee, say "La grille est également fermée de ce côté.".

To say la notice:
	say "La notice indique : ".

The Breda is female device inside musee. The printed name of Breda is "Breda M1937". Understand "Breda M1937" or "M1937" or "mitrailleuse" as Breda. The description of Breda is "[la notice][italic type]Une mitrailleuse lourde de l'armée italienne durant la Seconde Guerre mondiale. Elle souffrit de sa complexité et de sa munition faible.[roman type]".

Instead of switching on Breda:
	if croquemitaine is in location
		begin;
			say "Vous actionnez la mitrailleuse qui dans un crépitement sec vous débarrasse de ce monstre ! Vous trouvez ensuite la clé de la grille sur les restes de ce monstre, vous permettant de sortir et rentrer chez vous !";
			end the game in victory;
		otherwise;
			say "Cela pourrait être dangeureux si c'est actionné ainsi sans raison !";
	end if.
	
Photographing is an action applying to one thing.

Understand "viser [someone]" or "photographier [someone]" as  photographing.

Carry out Photographing:
	say "Cela n[']as beaucoup d[']intérêt.".
	
Instead of photographing croquemitaine:
	if the player is carrying fusil
		begin;
			say "Vous actionner le fusil qui déclenche un flash aveuglant sur ce monstre ! Il se recule vivement et s[']assomme sur le mur derrière lui. Vous trouvez ensuite la clé de la grille sur lui, vous permettant de sortir et rentrer chez vous !";
			end the game in victory;
		otherwise;
			say "Vous n[']avez rien avec vous pour faire cela.";
	end if.



The kinetoscope is inside musee. The description of kinetoscope is "[la notice][italic type]Le kinétoscope (vendu sous le nom commercial kinetoscope peep show machine) est l'un des premiers appareils de visualisation cinématographique. Bien qu'il ne soit pas un projecteur — il a été conçu pour qu'une seule personne puisse visionner l'image par le biais d'une fenêtre — le kinétoscope fut le premier pas de ce qui allait devenir le standard de tous les appareils de projection avant l'avènement de la vidéo.[roman type]".

The fusil is inside musee. The printed name of fusil is "fusil photographique". Understand "fusil" or "fusil photographique" as fusil. The description of fusil is "[la notice][italic type]Inventé en 1872 par Étienne-Jules Marey, le fusil photographique est un appareil photographique adapté sur un fusil traditionnel modifié, permettant de prendre des photographies en rafale. La chambre, au lieu d'abriter les munitions, contient une pellicule tournant sur un axe. La vitesse de prise de vue est de 12 images par seconde.[roman type]".

[-- toiture musee --]

The toitFake is part of museeFake. The printed name of toitFake is "toit du musée". Understand "toit" or "toit du musée" or "toit du musee" or "toit musee" as toitFake. 

Instead of climbing toitFake, say "Il vous faut trouver un autre moyen si vous voulez faire cela.".

The toitReal is a supporter in Parc. The toitReal is scenery. The printed name of toitReal is "toit".

[The parcFake is scenery in toit. The parcFake is not reachable.]

[Instead of going north from parc, say "La porte du musée est fermée.".]

The grille2 is a female scenery door. The printed name of grille2 is "grille". Understand "barriere du musee" or "grille du musee" or "acier" or "grille" as grille2. It is locked. It is east from parc and west from musee. The description of grille2 is "Une grande grille en acier recouvre toute l[']entrée du musée lorsque celui-ci est fermé. Un petit panneau est fixé sur la grille.".

The barriere is female scenery in sortie. The printed name of barriere is "barrière".

The petit panneau is part of grille2. The description of petit panneau is "Les horaires, de 10h à 17h, sont rayés et remplacés par la mention : 'Le musée est fermé pour travaux de mars à octobre.'". Understand "pancarte" as petit panneau.
Instead of reading petit panneau, try examining petit panneau.

Instead of climbing grille2:
	say "Au risque de déchirer vos habits, vous escaladez la grille pour monter sur le toit du musée.";
	now nid is reachable;
	move player to toitReal.

[Parc is down from toit. ]

After exiting when the player is on toitReal:
	now nid is not reachable;
	say "Vous redescendez en vous accrochant à la grille.".

After DownGoing when the player is on toitReal:
	now nid is not reachable;
	say "Vous redescendez en vous accrochant à la grille.".


Instead of going inside when the location is parc, try going north.

The porte is a scenery door. The printed name of porte is "porte". Understand "porte" or "porte de l'institut" or "porte institut" as porte. It is north from parc and south from institut.

Instead of attacking cigogne when the player is on toitReal:
	say "Vous effrayez la pauvre cignogne qui s[']envole gracieusement dans les cieux.";
	remove cigogne from play.
	
Instead of entering nid:
	if cigogne is inside nid
		begin;
			say "La cigogne ne vous laisse pas passer.";
		otherwise;
		say "Vous entrez dans le nid, et passez à travers la paille et le toit !";
		move player to musee;
	end if.
		
		
The sacoche is female in parc. The sacoche is female openable container. 


SevenHour is a scene.
SevenHour begins when the time of day is after 7:00 PM.


When SevenHour begins:
	now institut is dark;
	now croquemitaine is in sortie.


Alarme is a scene.
Alarme begins when the time of day is after 7:05 PM.

Every turn when alarme is happening:
	if the location is institut
		begin;
			end the game saying "L[']alarme se déclenche [if croquemitaine is in location]faisant fuir le bonhomme sept-heure, [end if]et rapidement la police est sur les lieux et neutralise le monstre. Les policiens vous découvrent tremblant comme une feuille dans un recoin noir de l[']institut. Vous vous en êtes quand même sorti !";
	end if.

The former location is a room that varies.

First carry out going rule: 
    change the former location to the location.


Waiting for minutes is an action applying to one topic.
Understand "attendre [text] minutes/minute" as waiting for minutes.

Carry out waiting for minutes:
[	Let the duree be the topic;]
	Let the duree be a random number between 5 and 15;
	Change the time of day to time of day + (duree minutes - 1 minute);
	say "[one of]Quelques minutes passèrent...[or]Un court moment passa...[or]Quelques instants passèrent...[at random]".
	
Every turn when sevenhour is happening:
	say "[if croquemitaine is not in location]Le bonhomme sept-heure vous cherche.[otherwise]Le bonhomme sept-heure est là ![end if]";
	[move croquemitaine to the former location.]
	if player is not on toitReal
		begin;
			move croquemitaine to the location;
		otherwise;
			say "Le bonhomme sept-heure lève ses yeux vides vers votre refuge, l'air dépité.";
			move croquemitaine to sortie;
		end if.

[Every turn when sevenhour is happening and the former location is the location:
	move croquemitaine to the location.]

[Every turn when croquemitaine is in location:
	say "Le bonhomme sept-heure est là !".	]

The croquemitaine is a man in loge.

The printed name of croquemitaine is "bonhomme sept-heure". Understand "bonhomme" or "bonhomme sept-heure" or "haillons" or "vagabond" or "monstre" as croquemitaine. The description of croquemitaine is "Il ressemble a un vagabond en haillons, avec des yeux vitreux et un rictus de haine, seule trace d[']humanité qui lui reste.". The indefinite article of croquemitaine is "le".


ImminentDeath is a recurring scene.
ImminentDeath begins when the croquemitaine is in location.
ImminentDeath ends when the croquemitaine is not in location.

When ImminentDeath begins:
	say "Le bonhomme sept-heure est très près de vous.".
	
[When ImminentDeath ends:
	say "Vous vous éloignez de ce monstre.".]

Death is a recurring scene.
Death begins when ImminentDeath is happening and the time since ImminentDeath began is 4 minutes.
Death ends when ImminentDeath is happening and the time since ImminentDeath began is 5 minutes.

When Death begins:
	if ImminentDeath is not happening
		begin;
		otherwise;
					if player is on toitReal
				begin;
					move croquemitaine to Sortie; 
					say "Le bonhomme sept-heure s[']éloigne, dépité.";
				otherwise;
					end the game saying "Le bonhomme sept-heure vous a pris !";
				end if;
	end if.
	
	


test me with "ouvrir la porte/n/sud/sud/sud/x grille/nord/x grille/lire pancarte/escalader la grille/attaquer la cigogne/entrer dans le nid/x fusil/x breda/x kinetoscope/z/z/z/z/allumer mitrailleuse".
		
	
[
"Des inscriptions à vérifier avant le bouclage de l[']année ! Ils en avaient de bonnes avec leurs 'inscriptions à vérifier avant le bouclage de l[']année' ! Cela faisait trois jours que vous pestiez contre ces fonctionnaires qui ne vous faisaient parvenir les dossiers de leurs académies qu[']au dernier moment. 

]		



