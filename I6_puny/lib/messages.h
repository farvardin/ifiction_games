! Part of PunyInform: A small stdlib and parser for interactive fiction
! suitable for old-school computers such as the Commodore 64.
! Designed to be similar, but not identical, to the Inform 6 library.
!
System_file;

!
! Simple string messages
!
!FRENCH
#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Vous vous êtes toujours appartenu.";
#EndIf;
#Ifndef MSG_TAKE_SCENERY;
Constant MSG_TAKE_SCENERY "C'est difficilement transportable.";
#EndIf;
#Ifndef MSG_TAKE_STATIC;
Constant MSG_TAKE_STATIC "C'est fixé sur place.";
#EndIf;
!#Ifndef MSG_TAKE_ALREADY_HAVE; !déplacé en 101
!Constant MSG_TAKE_ALREADY_HAVE "C'est déjà dans votre inventaire.";
!#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Vous avez déjà suffisamment d'objets.";
#EndIf;
#Ifndef MSG_TAKE_SUCCESS;
Constant MSG_TAKE_SUCCESS "D'accord, c'est pris.";
#EndIf;
#Ifndef MSG_EAT_INEDIBLE;
Constant MSG_EAT_INEDIBLE "Ce n'est manifestement pas comestible.";
#EndIf;
#Ifndef MSG_DRINK_NOTHING_SUITABLE;
!Constant MSG_DRINK_NOTHING_SUITABLE "Il n'y a rien de vraiment buvable ici.";
Constant MSG_DRINK_NOTHING_SUITABLE "Ce n'est pas quelque chose que vous pouvez boire.";
#EndIf;
#Ifndef MSG_DROP_DROPPED;
Constant MSG_DROP_DROPPED "D'accord, c'est posé.";
#EndIf;
#Ifndef MSG_OPEN_ALREADY;
Constant MSG_OPEN_ALREADY "C'est déjà ouvert.";
#Endif;
#Ifndef MSG_OPEN_LOCKED;
Constant MSG_OPEN_LOCKED "C'est manifestement verrouillé.";
#Endif;
#Ifndef MSG_THROW_ANIMATE;
Constant MSG_THROW_ANIMATE "C'est sans grand intérêt."; !TODO inutile futile
#Endif;
#Ifndef MSG_THROW_SUCCESS;
Constant MSG_THROW_SUCCESS "Vous renoncez au dernier moment.";
#Endif;
#Ifndef MSG_SMELL_SUCCESS;
Constant MSG_SMELL_SUCCESS "Vous ne sentez rien de particulier.";
#Endif;
#Ifndef MSG_LISTEN_SUCCESS;
Constant MSG_LISTEN_SUCCESS "Vous n'entendez rien de particulier.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Vous vous dites quelques mots.";
#Endif;
#Ifndef MSG_TELL_SUCCESS;
Constant MSG_TELL_SUCCESS "Cela ne provoque aucune réaction.";
#Endif;
#Ifndef MSG_ENTER_ALREADY;
Constant MSG_ENTER_ALREADY "Vous y êtes déjà.";
#Endif;
#Ifndef MSG_EXIT_ALREADY;
Constant MSG_EXIT_ALREADY "Vous n'êtes dans rien pour l'instant.";
#Endif;
#Ifndef MSG_EXIT_NOT_ON;
Constant MSG_EXIT_NOT_ON "Vous n'y êtes pas pour l'instant."; !FIXME
#Endif;
#Ifndef MSG_EXIT_NOT_IN;
Constant MSG_EXIT_NOT_IN "Vous n'y êtes pas pour l'instant."; !FIXME
#Endif;
#Ifndef MSG_INVENTORY_EMPTY;
Constant MSG_INVENTORY_EMPTY "Vous n'avez aucun objet.";
#Endif;
#Ifndef MSG_GO_CANT_GO;
Constant MSG_GO_CANT_GO "Vous ne pouvez pas aller par là.";
#Endif;
#Ifndef MSG_SAVE_SUCCESS;
Constant MSG_SAVE_SUCCESS "D'accord, c'est sauvegardé.";
#Endif;
#Ifndef MSG_INSERT_ITSELF;
Constant MSG_INSERT_ITSELF "Vous ne pouvez pas mettre quelque chose dans lui-même.";
#Endif;
#Ifndef MSG_PUTON_NOT_SUPPORTER;
Constant MSG_PUTON_NOT_SUPPORTER "Vous ne pouvez pas mettre quelque chose là-dessus."; !FIXME
#Endif;
#Ifndef MSG_PUTON_ITSELF;
Constant MSG_PUTON_ITSELF "Vous ne pouvez pas mettre quelque chose sur lui-même."; !TODO
#Endif;
#Ifndef MSG_ATTACK_SUCCESS;
Constant MSG_ATTACK_SUCCESS "La violence n'est pas toujours la solution.";
#Endif;
#Ifndef MSG_FILL_NO_WATER;
Constant MSG_FILL_NO_WATER "Il n'y a rien de vraiment approprié."; !TODO
#EndIf;
#Ifndef MSG_DIG_NO_USE;
Constant MSG_DIG_NO_USE "Cela n'aboutirait pas à grand-chose.";
#EndIf;
#Ifndef MSG_WAIT_SUCCESS;
Constant MSG_WAIT_SUCCESS "Il ne se passe rien de particulier.";
#EndIf;
#Ifndef MSG_TOUCH_SUCCESS;
Constant MSG_TOUCH_SUCCESS "Vous ne ressentez rien de particulier.";
#EndIf;
#Ifndef MSG_PUSHDIR_DEFAULT;
Constant MSG_PUSHDIR_DEFAULT "Vous ne pouvez rien envisager d'autre ?"; !TODO
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Vous sautez sur place en vain.";
#EndIf;
#Ifndef MSG_REMOVE_SUCCESS;
Constant MSG_REMOVE_SUCCESS "D'accord, c'est retiré.";
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "Vous ne trouvez rien d'intéressant.";
#EndIf;
#Ifndef MSG_LOOKMODE_NORMAL;
Constant MSG_LOOKMODE_NORMAL "Le jeu est maintenant en mode de description courte, qui donne des descriptions complètes de lieux jamais visités auparavant et des descriptions courtes autrement."; !TODO
#EndIf;
#Ifndef MSG_LOOKMODE_LONG;
Constant MSG_LOOKMODE_LONG "Le jeu est maintenant en mode de description longue, qui donne toujours des descriptions complètes des lieux (même si vous y êtes déjà allé)."; !TODO
#EndIf;
#Ifndef MSG_LOOKMODE_SHORT;
Constant MSG_LOOKMODE_SHORT "Le jeu est maintenant en mode de description abrégé, qui donne toujours une brève description des lieux (même si vous n'y êtes jamais allé).";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Ce n'est possible qu'avec un être ou une chose animée.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "Vous ne pouvez pas agir sur plusieurs objets avec ce verbe.";
#EndIf;
#Ifndef MSG_PARSER_BAD_NUMBER;
Constant MSG_PARSER_BAD_NUMBER "Je n'ai pas compris ce chiffre.";
#EndIf;
#Ifndef MSG_PARSER_NO_INPUT;
Constant MSG_PARSER_NO_INPUT "Et quoi d'autre ?^";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_SENTENCE;
Constant MSG_PARSER_UNKNOWN_SENTENCE "Je n'ai pas compris cette phrase.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_VERB;
Constant MSG_PARSER_UNKNOWN_VERB "Je ne reconnais pas ce verbe.";
#EndIf;
#Ifndef MSG_PARSER_CANT_DISAMBIGUATE;
Constant MSG_PARSER_CANT_DISAMBIGUATE "Je ne comprends toujours pas à quoi vous faites référence.";
#EndIf;
#Ifndef MSG_PARSER_NOSUCHTHING;
Constant MSG_PARSER_NOSUCHTHING "Vous ne pouvez voir ou interagir avec cela."; !FIXME
#EndIf;

!
! complex messages (enumerated)
!

Default MSG_OPEN_YOU_CANT = 1;
Default MSG_CLOSE_YOU_CANT = 2;
Default MSG_ENTER_YOU_CANT = 3;
Default MSG_EXAMINE_NOTHING_SPECIAL = 4;
Default MSG_TAKE_ANIMATE = 5;
Default MSG_TAKE_PLAYER_PARENT = 6;
Default MSG_EAT_ANIMATE = 7;
Default MSG_DROP_NOT_HOLDING = 8;
Default MSG_OPEN_SUCCESS = 9;
Default MSG_CLOSE_SUCCESS = 10;
Default MSG_LOOK_BEFORE_ROOMNAME  = 11;
Default MSG_SHOW_NOT_HOLDING = 12;
Default MSG_SHOW_SUCCESS = 13;
Default MSG_GIVE_NOT_HOLDING = 14;
Default MSG_GIVE_SUCCESS = 15;
Default MSG_ASKFOR_SUCCESS = 16;
Default MSG_ASKTO_SUCCESS = 17;
Default MSG_ENTER_SUCCESS = 18;
Default MSG_EXIT_FIRST_LEAVE = 19;
Default MSG_ENTER_NOT_OPEN = 20;
Default MSG_EXIT_NOT_OPEN = 21;
Default MSG_EXIT_SUCCESS = 22;
Default MSG_INVENTORY_SUCCESS = 23;
Default MSG_GO_FIRST_LEAVE = 24;
Default MSG_GIVE_PLAYER 25;
Default MSG_SAVE_FAILED 26;
Default MSG_RESTORE_FAILED 27;
Default MSG_RESTART_FAILED 28;
Default MSG_INSERT_SUCCESS 29;
Default MSG_INSERT_NOT_OPEN 30;
Default MSG_ASK_SUCCESS 31;
Default MSG_ANSWER_SUCCESS 32;
Default MSG_RESTART_RESTORE_OR_QUIT 33;
Default MSG_AREYOUSUREQUIT 34;
Default MSG_WEAR_ALREADY_WORN 35;
Default MSG_WEAR_NOT_CLOTHING 36;
Default MSG_WEAR_NOT_HOLDING 37;
Default MSG_WEAR_SUCCESS 38;
Default MSG_INSERT_ALREADY 39;
Default MSG_INSERT_NO_ROOM 40;
Default MSG_PUTON_ALREADY 41;
Default MSG_PUTON_NO_ROOM 42;
Default MSG_PUTON_SUCCESS 43;
Default MSG_GO_DOOR_CLOSED 44;
Default MSG_SWITCH_ON_NOT_SWITCHABLE 45;
Default MSG_SWITCH_OFF_NOT_SWITCHABLE 46;
Default MSG_SWITCH_ON_ON 47;
Default MSG_SWITCH_OFF_NOT_ON 48;
Default MSG_SWITCH_ON_SUCCESS 49;
Default MSG_SWITCH_OFF_SUCCESS 50;
Default MSG_PUSH_STATIC 51;
Default MSG_PULL_STATIC 52;
Default MSG_TURN_STATIC 53;
Default MSG_PUSH_SCENERY 54;
Default MSG_PULL_SCENERY 55;
Default MSG_TURN_SCENERY 56;
Default MSG_PUSH_ANIMATE 57;
Default MSG_PULL_ANIMATE 58;
Default MSG_TURN_ANIMATE 59;
Default MSG_TURN_SUCCESS 60;
Default MSG_PUSH_SUCCESS 61;
Default MSG_PULL_SUCCESS 62;
Default MSG_YOU_HAVE_WON 63;
Default MSG_YOU_HAVE_DIED 64;
Default MSG_PARSER_NOTHING_TO_VERB 66;
Default MSG_TOUCHABLE_FOUND_CLOSED 67;
Default MSG_CONSULT_NOTHING_INTERESTING 68;
Default MSG_CUT_NO_USE 69;
Default MSG_SACK_PUTTING 70;
Default MSG_LOCK_NOT_A_LOCK 71;
Default MSG_LOCK_ALREADY_LOCKED 72;
Default MSG_LOCK_CLOSE_FIRST 73;
Default MSG_LOCK_KEY_DOESNT_FIT 74;
Default MSG_LOCK_SUCCESS 75;
Default MSG_DISROBE_NOT_WEARING 76;
Default MSG_DISROBE_SUCCESS 77;
Default MSG_REMOVE_CLOSED 78;
Default MSG_REMOVE_NOT_HERE 79;
Default MSG_SEARCH_IN_IT_ISARE 80;
Default MSG_SEARCH_ON_IT_ISARE 81;
Default MSG_SEARCH_EMPTY 82;
Default MSG_SEARCH_NOTHING_ON 83;
Default MSG_SEARCH_CANT_SEE_CLOSED 84;
Default MSG_EAT_SUCCESS = 85;
#IfDef OPTIONAL_FULL_SCORE;
Default MSG_FULLSCORE_START 86;
Default MSG_FULLSCORE_END 87;
#EndIf;
Default MSG_SCORE_SUCCESS 88;
Default MSG_UNLOCK_NOT_A_LOCK 89;
Default MSG_UNLOCK_ALREADY_UNLOCKED 90;
Default MSG_UNLOCK_KEY_DOESNT_FIT 91;
Default MSG_UNLOCK_SUCCESS 92;
Default MSG_ENTER_BAD_LOCATION 93;
Default MSG_PROMPT 94;
#Ifndef OPTIONAL_NO_DARKNESS;
Default MSG_EXAMINE_DARK 95;
Default MSG_SEARCH_DARK 96;
#Endif;
Default MSG_EXAMINE_ONOFF 97;
Default MSG_ORDERS_WONT 98;
Default MSG_AUTO_TAKE 99;
Default MSG_AUTO_DISROBE = 100;

!FRENCH
! 101 is currently unused
Default MSG_TAKE_ALREADY_HAVE = 101;

Default MSG_TAKE_BELONGS 102;
Default MSG_TAKE_PART_OF 103;
Default MSG_TAKE_NOT_AVAILABLE 104;
Default MSG_PARSER_CONTAINER_ISNT_OPEN 105;
Default MSG_PARSER_NOT_HOLDING 106;
Default MSG_PARSER_CANT_TALK 107;
Default MSG_WAVE_NOTHOLDING 108;
Default MSG_JUMP_OVER 109;
Default MSG_TIE_DEFAULT 110;
Default MSG_CLOSE_NOT_OPEN 111;
Default MSG_RUB_DEFAULT 112;
Default MSG_SQUEEZE_DEFAULT 113;
Default MSG_EXAMINE_CLOSED 114;
Default MSG_EMPTY_IS_CLOSED 115;
Default MSG_PARSER_NO_NEED_REFER_TO 116;
Default MSG_PARSER_DONT_UNDERSTAND_WORD 117;
Default MSG_INSERT_NOT_CONTAINER 118;
Default MSG_EMPTY_CANT_CONTAIN 119; ! Extended verbset, but uses same msg as INSERT
Default MSG_YES_OR_NO 120;
Default MSG_RESTART_CONFIRM 121;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifndef MSG_BURN_DEFAULT;
Constant MSG_BURN_DEFAULT "Commettre un tel acte n'apporterait rien."; !Cela
#EndIf;
#Ifndef MSG_BUY_DEFAULT;
Constant MSG_BUY_DEFAULT "Rien n'est en vente.";
#EndIf;
#Ifndef MSG_EMPTY_WOULDNT_ACHIEVE;
Constant MSG_EMPTY_WOULDNT_ACHIEVE "Cela ne viderait rien du tout."; !ça
#EndIf;
#Ifndef MSG_RHETORICAL_QUESTION;
Constant	MSG_RHETORICAL_QUESTION "Ni oui ni non.";
#EndIf;
#Ifndef MSG_PRAY_DEFAULT;
Constant MSG_PRAY_DEFAULT "Votre prière semble sans effet.";
#EndIf;
#Ifndef MSG_SING_DEFAULT;
Constant MSG_SING_DEFAULT "Vous fredonnez un air qui vous est familier.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "Vous ne vous sentez pas particulièrement fatigué.";
#EndIf;
#Ifndef MSG_SORRY_DEFAULT;
Constant MSG_SORRY_DEFAULT "N'en faites pas trop.";
#EndIf;
#Ifndef MSG_SQUEEZE_YOURSELF;
Constant MSG_SQUEEZE_YOURSELF "Laissez vos mains tranquilles."; !FIXME
#EndIf;

#Ifndef MSG_SWIM_DEFAULT;
Constant MSG_SWIM_DEFAULT "Il n'y a pas vraiment d'endroit où nager.";
#EndIf;
#Ifndef MSG_SWING_DEFAULT;
Constant MSG_SWING_DEFAULT "Il n'y a rien de vraiment approprié.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "Vous n'éprouvez rien de particulier."; !TODO
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Quelle bonne idée.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Vous saluez d'un signe de la main."; !FIXME
#EndIf;
#Ifndef MSG_WAKE_SUCCESS;
Constant MSG_WAKE_SUCCESS "Ce n'est pourtant pas un rêve.";
#Endif;
#Ifndef MSG_WAKEOTHER_SUCCESS;
Constant MSG_WAKEOTHER_SUCCESS "Cela ne semble pas nécessaire.";
#Endif;
#Ifndef MSG_KISS_PLAYER;
Constant MSG_KISS_PLAYER "Si vous pensez que cela peut aider.";
#Endif;
#Ifndef MSG_KISS_SUCCESS;
Constant MSG_KISS_SUCCESS "Concentrez-vous plutôt sur le jeu.";
#Endif;
#Ifndef MSG_MILD_DEFAULT;
Constant MSG_MILD_DEFAULT "Assez.";
#EndIf;
#Ifndef MSG_STRONG_DEFAULT;
Constant MSG_STRONG_DEFAULT "Les vrais aventuriers n'utilisent pas un tel langage.";
#EndIf;

Default MSG_BLOW_DEFAULT 200;
Default MSG_WAVE_DEFAULT 201;
Default MSG_EMPTY_ALREADY_EMPTY 202;
Default MSG_SET_DEFAULT 203;
Default MSG_SET_TO_DEFAULT 204;
#EndIf;

Default LibraryMessages 0;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(p_msg ofclass String)
		print_ret (string) p_msg;

	if(p_msg > 999) {
		LibraryMessages(p_msg, p_arg_1, p_arg_2);
		rtrue;
	}

	! Not a string, there should be code for the message here
	switch(p_msg) {
	MSG_TURN_SUCCESS, MSG_PUSH_SUCCESS, MSG_PULL_SUCCESS:
		"Vous n'aboutirez à rien comme cela."; !TODO
#IfDef SACK_OBJECT;
#IfTrue MSG_SACK_PUTTING < 1000;
	MSG_SACK_PUTTING:
		"(mettant ", (the) p_arg_1, " dans ", (the) SACK_OBJECT, " pour faire de la place)";
#EndIf;
#EndIf;
#IfTrue MSG_PROMPT < 1000;
	MSG_PROMPT:
		print ">";
		rtrue;
#EndIf;
#IfTrue MSG_INVENTORY_SUCCESS < 1000;
	MSG_INVENTORY_SUCCESS:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		if(PrintContents("Vous avez ", player)) {
			print ".^";
			rtrue;
		} else {
			rfalse;
		}
#EndIf;
#IfTrue MSG_EXAMINE_NOTHING_SPECIAL < 1000;
	MSG_EXAMINE_NOTHING_SPECIAL:
		"Vous ne remarquez rien de particulier concernant ", (the) noun, ".";
#EndIf;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC:
		print_ret (CTheyreorThats) noun, "fixé", (_es) noun, " sur place.";
	MSG_TURN_SCENERY, MSG_PUSH_SCENERY, MSG_PULL_SCENERY:
		"Vous ne pouvez pas faire cela."; !FIXME "What a concept!";
	MSG_TURN_ANIMATE, MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE:
		"Ce ne serait pas très correct.";
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
		MSG_WEAR_NOT_HOLDING:
		"Vous ne", (_lesl) noun, "avez pas avec vous.";
	MSG_OPEN_YOU_CANT, MSG_CLOSE_YOU_CANT, MSG_ENTER_YOU_CANT,
		MSG_LOCK_NOT_A_LOCK, MSG_UNLOCK_NOT_A_LOCK, MSG_WEAR_NOT_CLOTHING:
		print "Ce n'est pas quelque chose ";
      if (p_msg == MSG_ENTER_YOU_CANT) "où vous pouvez aller.";
      else "que vous pouvez ", (verbname) p_arg_1, ".";
	MSG_TAKE_ANIMATE, MSG_EAT_ANIMATE:
      print "Je doute que ", (the) noun, " soi"; if (noun has pluralname) print "en";
      "t d'accord avec cela.";
	MSG_TAKE_PLAYER_PARENT, MSG_GO_FIRST_LEAVE, MSG_EXIT_FIRST_LEAVE:
      print "Vous devez d'abord "; if (p_arg_1 has supporter) print "descendre"; else print "sortir";
      print_ret (_dedudes) p_arg_1, (name) p_arg_1, ".";
#Iftrue MSG_OPEN_SUCCESS < 1000;
	MSG_OPEN_SUCCESS:
		print "Vous ouvrez ", (the) noun;
		if(noun has container && noun hasnt transparent) {
			print ", révélant ";  !FIXME ne
			if(PrintContents(0, noun)==false) print "rien du tout";
		}
		".";
#Endif;
#Iftrue MSG_LOOK_BEFORE_ROOMNAME < 1000;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;
	MSG_CLOSE_SUCCESS: "Vous fermez ", (the) noun, ".";
	MSG_ENTER_SUCCESS:
      print "Vous allez "; if (noun has container) print "dans"; else print "sur";
      " ", (the) noun, ".";
	MSG_LOCK_SUCCESS:  "Vous verrouillez ", (the) noun, ".";
	MSG_UNLOCK_SUCCESS:"Vous déverrouillez ", (the) noun, ".";
	MSG_EXIT_SUCCESS: if (noun hasnt container && noun hasnt supporter) "D'accord."; !FIXME
      print "Vous "; if (noun has container) print "sortez"; else print "descendez";
      print_ret (_dedudes) noun, (name) noun, ".";
	MSG_GIVE_SUCCESS, MSG_SHOW_SUCCESS:
		print_ret (The) second, " ne semble", (_nt) second, "pas intéressé", (_es) second, ".";
	MSG_ASKFOR_SUCCESS, MSG_ASKTO_SUCCESS:
		print (The) noun; if (noun has pluralname) print " ont"; else print " a";
      " mieux à faire.";
	MSG_ENTER_NOT_OPEN, MSG_EXIT_NOT_OPEN, MSG_INSERT_NOT_OPEN, MSG_GO_DOOR_CLOSED:
		"C'est impossible car ", (the) p_arg_1, (IsorAre) p_arg_1, "fermé", (_es) p_arg_1, ".";
#IfTrue MSG_GIVE_PLAYER < 1000;
	MSG_GIVE_PLAYER:
		"Vous", (_lesl) noun, "avez déjà.";
#EndIf;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		print_ret "La commande a échoué."; !FIXME
!		print_ret (verbname) verb_word, " a échoué."; !FIXME
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY:
		print_ret (CTheyreOrThats) noun, "déjà ici.";
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"Il n'y a plus suffisamment de place."; !FIXME ne peut rien contenir d'autre
#IfTrue MSG_INSERT_SUCCESS < 1000;
	MSG_INSERT_SUCCESS:
		"Vous mettez ", (the) noun, " dans ", (the) second, "."; !TODO insérez
#EndIf;
#IfTrue MSG_PUTON_SUCCESS < 1000;
	MSG_PUTON_SUCCESS:
		"Vous mettez ", (the) noun, " sur ", (the) second, ".";
#EndIf;
	MSG_ASK_SUCCESS, MSG_ANSWER_SUCCESS:
		"Vous n'obtenez aucune réponse.";
#IfTrue MSG_WEAR_ALREADY_WORN < 1000;
	MSG_WEAR_ALREADY_WORN:
		"Vous", (_lesl) noun, "avez déjà sur vous.";
#EndIf;
#IfTrue MSG_WEAR_SUCCESS < 1000;
	MSG_WEAR_SUCCESS:
		"Vous mettez ", (the) noun, ".";
#EndIf;
#IfTrue MSG_DISROBE_NOT_WEARING < 1000;
	MSG_DISROBE_NOT_WEARING:
		"Vous ne", (_lesl) noun, "avez pas sur vous.";
#EndIf;
#IfTrue MSG_DISROBE_SUCCESS < 1000;
	MSG_DISROBE_SUCCESS:
		"Vous retirez ", (the) noun, ".";
#EndIf;
	MSG_SWITCH_ON_NOT_SWITCHABLE, MSG_SWITCH_OFF_NOT_SWITCHABLE:
		"Ce n'est pas quelque chose que vous pouvez allumer.";
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, "déjà ", (OnOff) noun, ".";
	MSG_SWITCH_ON_SUCCESS, MSG_SWITCH_OFF_SUCCESS:
		"Vous allumez ", (the) noun, ".";
#Iftrue MSG_AUTO_TAKE < 1000;
	MSG_AUTO_TAKE:
	print "(prenant d'abord ", (the) p_arg_1, ")^";
#Endif;
#Iftrue MSG_AUTO_DISROBE < 1000;
	MSG_AUTO_DISROBE:
		print "(retirant d'abord ", (the) p_arg_1, ")^";
#Endif;

!FRENCH
#Iftrue MSG_TAKE_ALREADY_HAVE < 1000;
	MSG_TAKE_ALREADY_HAVE:
		print_ret "Vous", (_lesl) p_arg_1, "avez déjà avec vous.";
#Endif;

#IfTrue MSG_PARSER_NOTHING_TO_VERB < 1000;
	MSG_PARSER_NOTHING_TO_VERB: !FIXME ALL ?
		"Il n'y a rien à ",  (verbname) verb_word, ".";
#EndIf;
	MSG_PARSER_NOT_HOLDING, MSG_WAVE_NOTHOLDING:
		print_ret "Vous ne", (_lesl) p_arg_1, "avez pas avec vous.";
#IfTrue MSG_PARSER_CANT_TALK < 1000;
	MSG_PARSER_CANT_TALK:
		print_ret "Vous ne pouvez pas parler", (_aaux) p_arg_1, (name) p_arg_1, ".";
#EndIf;
#IfTrue MSG_PARSER_NO_NEED_REFER_TO < 1000;
	MSG_PARSER_NO_NEED_REFER_TO:
		print "Vous n'avez pas besoin de vous référer à « "; !TODO
		_PrintUnknownWord();
		print_ret " » dans ce jeu.";
#EndIf;
#IfTrue MSG_PARSER_DONT_UNDERSTAND_WORD < 1000;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
			print "Désolé, je ne comprends pas ce que « "; !TODO
			_PrintUnknownWord();
			print_ret " » veut dire.";
#EndIf;
	MSG_TOUCHABLE_FOUND_CLOSED, MSG_PARSER_CONTAINER_ISNT_OPEN, MSG_CLOSE_NOT_OPEN:
      print (The) p_arg_1; IsorAre(p_arg_1, 1); "pas ouvert", (_es) p_arg_1, "."; 

#IfTrue MSG_CONSULT_NOTHING_INTERESTING < 1000;
	MSG_CONSULT_NOTHING_INTERESTING:
		"Vous ne trouvez rien d'intéressant dans ", (the) second, ".";
#EndIf;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT:
		"Vous n'arriverez à rien comme cela.";
	MSG_LOCK_ALREADY_LOCKED:
		print_ret (CTheyreOrThats) noun, "déjà verrouillé", (_es) noun, ".";
   MSG_UNLOCK_ALREADY_UNLOCKED:
		print_ret (CTheyreOrThats) noun, "déjà déverrouillé", (_es) noun, ".";

#IfTrue MSG_LOCK_CLOSE_FIRST < 1000;
	MSG_LOCK_CLOSE_FIRST:
		"Vous devez d'abord fermer ", (the) noun, ".";
#EndIf;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		print_ret (The) second, " ne semble", (_nt) second, "pas correspondre à la serrure.";
	MSG_EXAMINE_CLOSED, MSG_REMOVE_CLOSED, MSG_EMPTY_IS_CLOSED:
		print_ret (The) p_arg_1, (isorare) p_arg_1, "fermé", (_es) p_arg_1, ".";
#IfTrue MSG_REMOVE_NOT_HERE < 1000;
	MSG_REMOVE_NOT_HERE:
		print "Mais ", (the) noun; IsorAre(noun, 1); "pas ici.";
#EndIf;
#IfTrue MSG_SEARCH_IN_IT_ISARE < 1000;
	MSG_SEARCH_IN_IT_ISARE:
		print "Dans ";
		SearchInOnNoun();
		rtrue;
#EndIf;
#IfTrue MSG_SEARCH_ON_IT_ISARE < 1000;
	MSG_SEARCH_ON_IT_ISARE:
		print "Sur ";
		SearchInOnNoun();
		rtrue;
#EndIf;
#IfTrue MSG_SEARCH_EMPTY < 1000;
	MSG_SEARCH_EMPTY:
		print_ret (CTheyreOrThats) noun, "vide", (_s) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_NOTHING_ON < 1000;
	MSG_SEARCH_NOTHING_ON:
		"Il n'y a rien sur ", (the) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_CANT_SEE_CLOSED < 1000;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"Vous ne pouvez voir à l'intérieur, car ", (the) noun, (IsOrAre) noun, "fermé", (_es) noun, ".";
#EndIf;
#IfTrue MSG_EXAMINE_ONOFF < 1000;
	MSG_EXAMINE_ONOFF:
		print_ret (The) noun, (IsOrAre) noun, "actuellement ", (onoff) noun, ".";
#EndIf;
#IfTrue MSG_EAT_SUCCESS < 1000;
	MSG_EAT_SUCCESS:
		"Vous mangez ", (the) noun, ". Pas mauvais.";
#EndIf;
MSG_RUB_DEFAULT, MSG_SQUEEZE_DEFAULT:
	"Vous n'aboutirez à rien comme cela.";
#IfTrue MSG_ORDERS_WONT < 1000;
	MSG_ORDERS_WONT:
		print (The) actor; if (actor has pluralname) print " ont"; else print " a";
      " certainement mieux à faire.";
#EndIf;
#IfTrue MSG_TAKE_NOT_AVAILABLE < 1000;
	MSG_TAKE_NOT_AVAILABLE:
		print (The) noun; IsorAre(noun, 1); "pas accessible", (_s) noun, ".";
#EndIf;
#IfTrue MSG_TAKE_BELONGS < 1000;
	MSG_TAKE_BELONGS:
		print_ret (The) p_arg_1, " semble", (_nt) p_arg_1, "appartenir", (_aaux) p_arg_2, 
         (name) p_arg_2, ".";
#EndIf;
#IfTrue MSG_TAKE_PART_OF < 1000;
	MSG_TAKE_PART_OF:
		print_ret (The) p_arg_1, " semble", (_nt) p_arg_1, "faire partie", (_dedudes) p_arg_2, 
         (name) p_arg_2, ".";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Mais vous êtes dans l'obscurité.";
#Endif;
#IfTrue MSG_SCORE_SUCCESS < 1000;
	MSG_SCORE_SUCCESS:
		if (deadflag) print "Votre score final est de "; else print "Votre score est de ";
      print score, " sur ", MAX_SCORE, ", en ", turns, " tour"; if (turns > 1) print "s";
		rtrue;
#EndIf;
#IfDef OPTIONAL_FULL_SCORE;
#IfTrue MSG_FULLSCORE_START < 1000;
	MSG_FULLSCORE_START:
		print "Le score ";
		if(deadflag) print "était"; else print "est";
		" composé de :";
#EndIf;
#IfTrue MSG_FULLSCORE_END < 1000;
	MSG_FULLSCORE_END:
		print "point"; if (score > 1) print "s";
      " (sur un total de ", MAX_SCORE, ")";
#EndIf;
#EndIf;
#IfTrue MSG_RESTART_RESTORE_OR_QUIT < 1000;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^Voulez-vous recommencer, charger une partie sauvegardée";
#EndIf;
#IfDef OPTIONAL_FULL_SCORE;
		print ", voir votre score Total";
#EndIf;
		if(deadflag == 2 && AMUSING_PROVIDED == 0) print ", voir quelques actions bonus amusantes";
		print " ou quitter ? ";
		rtrue;
#IfTrue MSG_AREYOUSUREQUIT < 1000;
	MSG_AREYOUSUREQUIT: ! print and rtrue to avoid newline
		print "Êtes-vous sûr de vouloir interrompre la partie ? ";
		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_WON < 1000;
	MSG_YOU_HAVE_WON: ! print and rtrue to avoid newline
 		print "Vous avez gagné.";
 		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_DIED < 1000;
	MSG_YOU_HAVE_DIED: ! print and rtrue to avoid newline
		print "Vous êtes mort";
		rtrue;
#EndIf;
#IfTrue MSG_ENTER_BAD_LOCATION < 1000;
   MSG_ENTER_BAD_LOCATION:
      print "Vous devez d'abord ";
      if(player notin location && ~~IndirectlyContains(parent(player), noun)) {
         if (parent(player) has supporter) print "descendre"; else print "sortir";
         print (_dedudes) parent(player), (name) parent(player);
      }
      else
         print "entrer dans ", (the) parent(noun); !TODO FIXME
      ".";
#EndIf;
	MSG_INSERT_NOT_CONTAINER, MSG_EMPTY_CANT_CONTAIN:
      print "C'est impossible, car ", (the) p_arg_1, " ne peu"; if (p_arg_1 has pluralname) print "ven";
      "t rien contenir.";
#IfTrue MSG_YES_OR_NO < 1000;
	MSG_YES_OR_NO:
		print "Répondez, s'il vous plaît, par oui ou non : ";
#EndIf;
#IfTrue MSG_RESTART_CONFIRM < 1000;
	MSG_RESTART_CONFIRM:
		print "Êtes-vous sûr de vouloir recommencer ? ";
#Endif;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#IfTrue MSG_BLOW_DEFAULT < 1000;
	MSG_BLOW_DEFAULT:
		"Cela n'aboutirait pas à grand-chose.";
#EndIf;
#IfTrue MSG_EMPTY_ALREADY_EMPTY < 1000;
	MSG_EMPTY_ALREADY_EMPTY:
		print_ret (CTheyreOrThats) p_arg_1, "déjà vide", (_s) p_arg_1, ".";
#EndIf;
#IfTrue MSG_SET_DEFAULT < 1000;
	MSG_SET_DEFAULT:
		"Ce n'est pas quelque chose que vous pouvez régler.";
#EndIf;
#IfTrue MSG_SET_TO_DEFAULT < 1000;
	MSG_SET_TO_DEFAULT:
		"Vous ne pouvez pas", (ItorThem) noun, "régler sur quoi que ce soit.";
#EndIf;
#IfTrue MSG_WAVE_DEFAULT < 1000;
	MSG_WAVE_DEFAULT:
		"Vous avez l'air un peu ridicule à brandir ", (the) noun, ".";
#EndIf;
#EndIf;

default:
		! No code found. Print an error message.
		RuntimeError(ERR_UNKNOWN_MSGNO);
	}
];

[ SearchInOnNoun;
	print (the) noun, " il y a ";
	if(PrintContents(0, noun)) print ".^";
];


[ elide w;
   @output_stream 3 StorageForShortName;
   print (name) w;
   @output_stream -3;
   return (LanguageContraction(StorageForShortName + WORDSIZE));
];

[ _nt obj;
   if (obj has pluralname) print "nt ";
   else print " ";
];

[ _s obj;
   if (obj has pluralname) print "s";
];

[ _es obj;
   if (obj has female) print "e";
   _s(obj);
];

[ _lesl obj;
   if (obj has pluralname) print " les ";
   else print " l'";
];

[ _dedudes obj;
   print " ";
   if (obj has pluralname) { print "des "; return; }
   if (obj has proper) { print "de "; return; }
   if ( elide(obj) ) { print "de l'"; return; }
   if (obj has female) print "de la ";
   else print "du ";
];

[ _aaux obj;
   print " ";
   if (obj has pluralname) { print "aux "; return; }
   if (obj has proper) { print "à "; return; }
   if ( elide(obj) ) { print "à l'"; return; }
   if (obj has female) print "à la ";
   else print "au ";
];

[ ItorThem obj;
   print " ";
   if (obj == player) { print "vous "; return; }
   if (obj has pluralname) { print "les "; return; }
   if (obj has female) print "la ";
   else print "le ";
];

[ IsorAre obj negation;
   print " ";
   if (obj == player) {
      if (negation) print "n'";
      print "êtes ";
      return;
   } 
   if (obj has pluralname) {
      if (negation) print "ne ";
      print "sont ";
   }
   else {
      if (negation) print "n'";
      print "est ";
   }
];

[ OnOff obj;
	if(obj has on) print "allumé", (_es) obj;
	else print "éteint", (_es) obj;
	return;
];

[ CTheyreOrThats obj; print (The) obj, (IsorAre) obj; ];

!
! Error messages
!
Constant ERR_TOO_MANY_TIMERS_DAEMONS 1;
Constant ERR_OBJECT_HASNT_PROPERTY 2;
Constant ERR_SCOPE_FULL 3;
Constant ERR_UNKNOWN_MSGNO 4;
Constant ERR_INVALID_DIR_PROP 5;
Constant ERR_TOO_MANY_FLOATING 6;
Constant ERR_NOT_DIR_PROP 7;
Constant ERR_NOT_FAKE_OBJ 8;

[ RunTimeError p_err;
	print "[Puny error: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Too many timers/daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Object lacks that property";
		ERR_SCOPE_FULL:
			print "Scope full";
		ERR_UNKNOWN_MSGNO:
			print "Unknown message#";
		ERR_INVALID_DIR_PROP:
			print "Invalid direction prop in GoSub";
		ERR_TOO_MANY_FLOATING:
			print "Too many floating objects";
		ERR_NOT_DIR_PROP:
			print "DirPropToFakeObj called with non-dirprop";
		ERR_NOT_FAKE_OBJ:
			print "FakeObjToDirProp called with non-fakeobj";
		default:
			print "Unknown error (", p_err, ")";
		}
#IfNot;
		print p_err;
#EndIf;
	}
	"]";
];
