Boussole by Benjamin Roux begins here. 
 
"Ajout d'une boussole traduite en fran�ais sur la ligne de status." 

Include Basic Screen Effects by Emily Short.



Table of Boussole
left		central 	right
" [location]"	""		"[En haut] [Au nord-ouest][Vers le nord][Au nord-est]"
" "		""		"     [Vers l'ouest] + [Vers l'est]"
""		""		"[En bas] [Au sud-ouest][Vers le sud][Au sud-est]"


To say En haut:
	let place be the room up from the location;
	if player is not in a dark room, say "[if the place is a room]Haut[otherwise]    [end if]";

To say En bas:
	let place be the room down from the location;
	if player is not in a dark room, say "[if the place is a room]Bas [otherwise]    [end if]";

To say Vers le nord:
	let place be the room north from the location;
	if player is not in a dark room, say "[if the place is a room] N [otherwise]   [end if]";

To say Vers le sud:
	let place be the room south from the location;
	if player is not in a dark room, say "[if the place is a room] S [otherwise]   [end if]";

To say Vers l'est:
	let place be the room east from the location;
	if player is not in a dark room, say "[if the place is a room]E [otherwise]  [end if]";

To say Vers l'ouest:
	let place be the room west from the location;
	if player is not in a dark room, say "[if the place is a room] O[otherwise]  [end if]";

To say Au nord-ouest:
	let place be the room northwest from the location;
	if player is not in a dark room, say "[if the place is a room]NO[otherwise]  [end if]";

To say Au nord-est:
	let place be the room northeast from the location;
	if player is not in a dark room, say "[if the place is a room]NE[otherwise]  [end if]";

To say Au sud-ouest:
	let place be the room southwest from the location;
	if player is not in a dark room, say "[if the place is a room]SO[otherwise]  [end if]";

To say Au sud-est:
	let place be the room southeast from the location;
	if player is not in a dark room, say "[if the place is a room]SE[otherwise]  [end if]";

Rule for constructing the status line when player is in a room:
	fill status bar with Table of Boussole;
	rule succeeds.



Boussole ends here. 

---- DOCUMENTATION ----

Cette extension permet d'ajouter une 'rose des vents' pour guider le joueur dans son exploration. 
Inspire d'un exemple de Lars Thurgoodson. Voici un exemple, avec toutes les directions 'explorables' :

	Haut NO N NE
	      O + E
	Bas  SO S SE