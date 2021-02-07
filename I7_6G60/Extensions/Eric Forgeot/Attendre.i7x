Version 1 of Attendre by Eric Forgeot begins here.


"Permet d'attendre."


Chapter 1 - Basic Definitions


A person can be awaiting. A person is usually not awaiting.

Waiting for one hour is an action applying to nothing.
Understand "attendre une heure" or "attendre 1 heure" as waiting for one hour.

Carry out waiting for one hour:
	now the player is awaiting;
	Change the time of day to time of day + (1 hour - 1 minute);
	say "Une heure [if using the French 3PSPa Language option]passa...[otherwise if using the French 1PSPa Language option]passa...[otherwise if using the French 1PSPr Language option]passe...[otherwise]passe...[end if]".


Waiting for two hours is an action applying to nothing.
Understand "attendre deux heure/heures" or "attendre 2 heure/heures" or "attendre quelques heures" or "x quelques heures" as waiting for two hours.

Carry out waiting for two hours:
	now the player is awaiting;
	Change the time of day to time of day + (2 hour - 1 minute);
	say "Deux heures [if using the French 3PSPa Language option]passèrent...[otherwise if using the French 1PSPa Language option]passèrent...[otherwise if using the French 1PSPr Language option]passent...[otherwise]passent...[end if]".


Waiting for three hours is an action applying to nothing.
Understand "attendre trois heure/heures" or "attendre 3 heure/heures" as waiting for three hours.

Carry out waiting for three hours:
	now the player is awaiting;
	Change the time of day to time of day + (3 hour - 1 minute);
	say "Trois heures [if using the French 3PSPa Language option]passèrent...[otherwise if using the French 1PSPa Language option]passèrent...[otherwise if using the French 1PSPr Language option]passent...[otherwise]passent...[end if]".


Waiting for more hours is an action applying to nothing.
Understand "attendre quatre/cinq/six/sept/huit/neuf/dix/onze/douze heure/heures" or "attendre 4 heure/heures"  or "attendre 5 heure/heures"  or "attendre 6 heure/heures"  or "attendre 7 heure/heures"  or "attendre 8 heure/heures"  or "attendre 9 heure/heures" or "attendre 10 heure/heures"  or "attendre 11 heure/heures"  or "attendre 12 heure/heures"  as waiting for more hours.

Carry out waiting for more hours:
	say "[if using the French 3PSPa Language option]Il n[']eut[otherwise if using the French 1PSPa Language option]Je n[']eus[otherwise if using the French 1PSPr Language option]Je n[']ai[otherwise]Vous n[']avez[end if] pas la patience d[']attendre aussi longtemps sans rien faire.".


[The attenteduration is a number variable.]

Waiting for minutes is an action applying to one number.
Understand "attendre [number] minutes/minute" or "attendre quelques minutes/minute" as waiting for minutes.

[Instead of waiting topic (called duree) for minutes:
    Change the time of day to time of day + (duree minutes - 1 minute);
    say "Vous attendez [number] minute[s]...".]

Carry out waiting for minutes:
	Let the duree be the number understood;
	[Let the duree be a random number between 5 and 15;]
	now the player is awaiting;
	Change the time of day to time of day + (duree minutes - 1 minute);
	if using the French 3PSPa Language option
		begin;
			say "[one of]Quelques minutes passèrent...[or]Un court moment passa...[or]Quelques instants passèrent...[at random]";
		otherwise if using the French 1PSPa Language option;
			say "[one of]Quelques minutes passèrent...[or]Un court moment passa...[or]Quelques instants passèrent...[at random]";
		otherwise if using the French 1PSPr Language option;
			say "[one of]Quelques minutes passent...[or]Un court moment passe...[or]Quelques instants passent...[at random]";
		otherwise;
			say "[one of]Quelques minutes passent...[or]Un court moment passe...[or]Quelques instants passent...[at random]";
		end if.
	


[After waiting for the sixth turn: 
	say "[if using the French 3PSPa Language option]S[']il voulait faire passer le temps plus vite, il pouvait[otherwise if using the French 1PSPa Language option]Si je voulais faire passer le temps plus vite, je pouvais[otherwise if using the French 1PSPr Language option]Si je veux faire passer le temps plus vite, je peux[otherwise]Si vous voulez faire passer le temps plus vite, vous pouvez[end if] essayer d'attendre pour quelques minutes ou quelques heures...".]

[After reading for the sixth turn: 
	say "Si je voulais faire passer le temps plus vite, je pouvais essayer d'attendre deux ou trois heures...".]
	

Attendre ends here.

---- DOCUMENTATION ----

Section: 


Awaiting is for testing during scenes if you want to catch the attente.


Modifying the default behavior for hybrid works is relatively painless.  For example, if we are writing an exploratory game and do not wish the player to skip rooms:
	*: Check travelling to (this is the Don't Jump To Unvisited Places rule): if the destination is unvisited, say "You don't know where [the noun] is." instead.



Example: ** Testing Area - A touching story about a lone cattle prod.

	*: "Lapin"

	Include Attendre by Eric Forgeot.  
	
	Section 1 - as the story opens
	
	Area 51 is a region. 
	Roswell is a region.   
	HQ is a region.    
	The RV is a region.
	 
	Silo 1 and a shady spot are rooms.  
	Silo 5 is a room in Area 51.   
	The general store is a room in Roswell. "Everyone in Roswell stops by this filled-to-bursting little store.  It's amazing anyone can find anything."
	The office full of answers is a room in HQ. "Ah! Yes! It's all here! Aliens are involved!".
	your RV is a room in the RV. "Looking out the window of your RV, you can see the town of Roswell and, in the distance, a couple of grain silos. [if office is visited]'Oh bother, where's that keycard? I need it as proof!'[otherwise]'How odd, to have grain silos in the desert,' you ponder.[end if]". Understand "home" as your RV.  
	  
	Mayor 'Shorty' Grein Mannie is a man in shady spot.   The gatekeeper of Roswell is Mayor Mannie. 
	The keycard is a thing in the store.  The gatekeeper of HQ is the keycard. 
	The player is in your RV. The gatekeeper of the RV is yourself. 
	  
	[ Intentionally creating "spot" as an animal, a room, and a thing.]  
	A dalmatian named Spot is an animal in silo 1.  Understand "dog" as the dalmatian. 
	A targeting spot missile is a thing in silo 5. It is not portable. 
	The printed name of shady spot is "shady spot behind silo 1".
	
	Shady spot is north of Silo 1. The general store is north of shady spot.
	
	Definition: a thing is inanimate if it is not a person.
	Definition: a region is player-owned rather than other-owned if the player is the gatekeeper of it. 
	
	First carry out taking inventory:
		if the number of player-owned regions is not 0, say "You own [the list of player-owned regions].";
		otherwise say "You don't own any real estate.  Even your apartment is rented."
	
	

	
	Test me with "TEST denied/TEST expired-invite/TEST permit/TEST forbid/TEST fixit".
	Test denied with "stan, invite me / stan, invite me to sales".
	Test expired-invite with "i/bob, invite me to sales/visit p/i/visit s/i/visit h/i".
	Test permit with "i/bob, permit me/i/visit p/visit s/i/visit r".
	Test forbid with "i/visit bob/bob, forbid me/i/visit p/visit s/i".
	Test fixit with "go to break room/sw/find wrench/take wrench/go to break room/sw".


