Boussole by Eric Forgeot begins here. 
 
"Ajout d'une boussole traduite en français sur la ligne de status." 


Section 1 - Improved Status Line (for Z-Machine only)

[from Emily Short's Bronze]

[This status line is designed to help the player track his exploration through the game: rooms that aren[']t explored yet are highlighted in red, and a count of explored rooms is kept in the lower left corner. We add the further refinement that, if the player is in a dark room, the compass line shows only exits which lead to lit rooms, on the assumption that he will be able to see lighted exits but not dark ones.]

Include Basic Screen Effects by Emily Short. [* An extension that provides phrases for changing text colors, modifying the status line more fully, pausing the game, and so on.]

To turn screen black:
	say white letters;
	turn the background black;
	clear the screen;
	leave space;
	
To turn screen white:
	turn the background white;
	say black letters;
	clear the screen;
	leave space.

To leave space:
	say paragraph break;
	say paragraph break;
	say paragraph break;
	say paragraph break. 
	
Table of Fancy Status
left	central	right 
""	" [story title] "	"[top rose]"
"  "	""	"[middle rose]"
" [if in darkness]Les ténèbres[otherwise][location][end if] "	""	"[bottom rose]"
 

To say red reverse:
	turn the background red.
	
To say black reverse:
	turn the background black.
	
To say white reverse:
	turn the background white.

Definition: a room is discernible: 
	if it is lit, yes;
	if in darkness, no;
	yes.

To say top rose:
	let place be the room up from the location;
	if the place is a discernible room, say "[if the place is unvisited][red reverse][end if]Haut   [default letters]"; otherwise say "    "; [* Originally I assumed that everyone would be using a white-letters-on-black status bar, and set the lettering to black and white after printing the first letter. This was a mistake, as many people on Windows Frotz have a default color scheme that makes the status bar blue-on-white -- so of course the white lettering on a white background didn[']t show at all. Moral: never ever make assumptions about the color scheme used by your audience.]
	let place be the room northwest from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if]NO[default letters]"; otherwise say "  ";
	let place be the room north from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if] N [default letters]"; otherwise say "   ";
	let place be the room northeast from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if]NE[default letters]"; otherwise say "  ".
	
To say middle rose:
	say "    ";
	let place be the room west from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if]O [default letters]"; otherwise say "  ";
	say " . ";
	let place be the room east from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if] E[default letters]"; otherwise say "  ".
	
To say bottom rose:
	let place be the room down from the location;
	if the place is a discernible room, say "[if the place is unvisited][red reverse][end if]Bas   [default letters]"; otherwise say "    ";
	let place be the room southwest from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if]SO[default letters]"; otherwise say "  ";
	let place be the room south from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if] S [default letters]"; otherwise say "   ";
	let place be the room southeast from the location;
	if place is a discernible room, say "[if the place is unvisited][red reverse][end if]SE[default letters]"; otherwise say "  ".
	 
Rule for constructing the status line:
	fill status bar with Table of Fancy Status;
	say default letters;
	rule succeeds.  


Section 3 - Boussole (for Glulx only)

Include Basic Screen Effects by Emily Short. [* An extension that provides phrases for changing text colors, modifying the status line more fully, pausing the game, and so on.]

To turn screen black:
	clear the screen;
	leave space;
	
To turn screen white:
	clear the screen;
	leave space.

To leave space:
	say paragraph break;
	say paragraph break;
	say paragraph break;
	say paragraph break. 
	
Table of Fancy Status
left	central	right 
""	" [story title] "	"[top rose]"
"  "	""	"[middle rose]"
" [if in darkness]Les ténèbres[otherwise][location][end if]"	""	"[bottom rose]"
 

Definition: a room is discernible: 
	if it is lit, yes;
	if in darkness, no;
	yes.

To say top rose:
	let place be the room up from the location;
	if the place is a discernible room, say "[if the place is unvisited][end if]Haut   "; otherwise say "    "; [* Originally I assumed that everyone would be using a white-letters-on-black status bar, and set the lettering to black and white after printing the first letter. This was a mistake, as many people on Windows Frotz have a default color scheme that makes the status bar blue-on-white -- so of course the white lettering on a white background didn[']t show at all. Moral: never ever make assumptions about the color scheme used by your audience.]
	let place be the room northwest from the location;
	if place is a discernible room, say "[if the place is unvisited][end if]NO"; otherwise say "  ";
	let place be the room north from the location;
	if place is a discernible room, say "[if the place is unvisited][end if] N "; otherwise say "   ";
	let place be the room northeast from the location;
	if place is a discernible room, say "[if the place is unvisited][end if]NE"; otherwise say "  ".
	
To say middle rose:
	say "    ";
	let place be the room west from the location;
	if place is a discernible room, say "[if the place is unvisited][end if]O "; otherwise say "  ";
	say " . ";
	let place be the room east from the location;
	if place is a discernible room, say "[if the place is unvisited][end if] E"; otherwise say "  ".
	
To say bottom rose:
	let place be the room down from the location;
	if the place is a discernible room, say "[if the place is unvisited][end if]Bas   "; otherwise say "    ";
	let place be the room southwest from the location;
	if place is a discernible room, say "[if the place is unvisited][end if]SO"; otherwise say "  ";
	let place be the room south from the location;
	if place is a discernible room, say "[if the place is unvisited][end if] S "; otherwise say "   ";
	let place be the room southeast from the location;
	if place is a discernible room, say "[if the place is unvisited][end if]SE"; otherwise say "  ".
	 
Rule for constructing the status line:
	fill status bar with Table of Fancy Status;
	rule succeeds. 
	

Boussole ends here.

---- DOCUMENTATION ----

