! ######################### Grammar + Actions
! ---------------------
! Base verbs
! ---------------------
!FRENCH
[ RemoveHeld;
   if (noun has clothing && parent(noun) == actor) rtrue;
   rfalse;
];

[ sGoUpSub;   <<Go FAKE_U_OBJ>>; ];

![ sGoDownSub; <<Go FAKE_D_OBJ>>; ];

[ sGetOffSub   o;
   o = parent(player);
#Ifdef OPTIONAL_NO_DARKNESS;
   if (o == location || o == real_location) {
#Ifnot;
   if (o == location || (location == thedark && o == real_location)) {
#Endif;
      <<Go  FAKE_D_OBJ>>;
   }
   <<GetOff (o)>>;
];

[ ADirection;
   if (noun == Directions) rtrue;
   rfalse;
];

[ GoInSub;
	! shortcut to <<Go in>>
	<Go FAKE_IN_OBJ>;
];

[ GoOutSub;
	! shortcut to <<Go out>>
	<Go FAKE_OUT_OBJ>;
];

#IfDef OPTIONAL_TALK_TO;
[ TalkToSub;
    if (noun == actor) print_ret (string) MSG_TELL_PLAYER;
    if (RunLife(noun, ##TalkTo)) return;
    print_ret (string) MSG_TELL_SUCCESS;
];

Verb 'parler'
   * 'à'/'au'/'aux'/'avec' creature                  -> TalkTo
   * creature                                        -> TalkTo
   * 'à'/'au'/'aux'/'avec' creature 
                          'de'/'d^'/'du'/'des' topic -> Tell
   * creature 'de'/'d^'/'du'/'des' topic             -> Tell
;
#Ifnot;
Verb 'parler'
   * 'à'/'au'/'aux'/'avec' creature 
                          'de'/'d^'/'du'/'des' topic -> Tell
   * creature 'de'/'d^'/'du'/'des' topic             -> Tell
;
#Endif;

Verb 'répondre'
   * creature topic                                  -> Answer reverse
   * topic 'à'/'au'/'aux' creature                   -> Answer
;

Verb 'demander'
   * noun 'à'/'au'/'aux' creature                    -> AskFor reverse
   * creature noun                                   -> AskFor
   * 'à'/'au'/'aux' creature 'de'/'d^' topic         -> AskTo
   * creature 'de'/'d^' topic                        -> AskTo
;

Verb 'dire'
   * 'à'/'au'/'aux' creature 'de'/'d^' topic         -> AskTo
   * creature 'de'/'d^' topic                        -> AskTo
   * creature topic                                  -> Answer reverse
   * topic 'à'/'au'/'aux' creature                   -> Answer
;

Verb 'interroger'
   * creature 'sur' topic                            -> Ask ! concernant à_propos_de
;

Verb 'montrer'
   * held 'à'/'au'/'aux' creature                    -> Show
   * creature held                                   -> Show reverse
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'réveiller'
   * 'se'                                            -> Wake
   * creature                                        -> WakeOther
;

Verb 'embrasser'
   * creature                                        -> Kiss
;

Verb 'saluer'
   *                                                 -> WaveHands
!   * noun                                            -> WaveHands
;
#Endif;

Verb 'regarder' 'l//' 'r//'
   *                                                 -> Look
   * noun                                            -> Examine
   * 'sur'/'dans'/'par'/'par-dessus' noun            -> Search ! derrière
!   * 'à'/'au'/'en'/'vers' noun=ADirection            -> Examine ! compass_look
   * 'à'/'au' 'travers' noun                         -> Search
!   * 'sous' noun                                     -> LookUnder
!   * topic 'à'/'au'/'sur'/'dans' noun                -> Consult
;

Verb 'examiner' 'x//'
   * noun                                            -> Examine
;

Verb 'lire' !TODO FIXME
   * noun                                            -> Examine
   * noun 'sur'/'de'/'d^' topic                      -> Consult
   * topic 'au'/'sur'/'dans' noun                    -> Consult
;

Verb 'fouiller'
   * noun                                            -> Search
   * 'dans' noun                                     -> Search
;

!Verb 'chercher' 'rechercher'
!   * noun                                           -> VagueVerb
!   * topic 'dans' noun                              -> Consult ! look_up
!;

Verb 'aller'
   * 'à'/'au'/'en'/'vers' noun=ADirection            -> Go
   * 'à'/'au'/'aux'/'sur'/'dans'/'sous' noun         -> Enter
;

Verb 'entrer'
   *                                                 -> GoIn
   * 'dans'/'par'/'sur'/'sous' noun                  -> Enter
;

Verb 'sortir'
   *                                                 -> GoOut ! de_là/d'ici
   * multiinside 'de'/'d^'/'du'/'des' noun           -> Remove
   * 'de'/'d^'/'du'/'des' noun                       -> Exit
   * 'par' noun                                      -> Enter !Exit?
;

Verb 'passer'
   * 'sur'/'dans'/'par'/'sous' noun                  -> Enter
   * 'par-dessus' noun                               -> Enter
   * 'à' 'travers' noun                              -> Enter
;

Verb 'monter'
   *                                                 -> sGoUp
   * 'à'/'au'/'aux'/'sur'/'dans'/'par'/'en' noun     -> Enter
;

Verb 'descendre' 'd//'
   *                                                 -> sGetOff
   * 'de'/'d^'/'du'/'des' noun                       -> GetOff
   * 'à'/'au'/'aux'/'sur'/'dans'/'par' noun          -> Enter
;

Verb 'grimper'
   * 'sur'/'à'/'au'/'aux'/'dans'/'par' noun          -> Enter
;

Verb 'sauter'
   *                                                 -> Jump
!  * 'à' noun                                        -> Jump ! la corde
   * 'sur'/'dans' noun                               -> Enter
   * 'par-dessus' noun                               -> JumpOver
   * 'par'/'de'/'du'/'des' noun                      -> Exit
;

Verb 'asseoir' 'coucher' 'allonger' 
   * 'se' 'sur'/'dans' noun                          -> Enter
;

Verb 'lever'
   * 'se'                                            -> Exit
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'nager' 'conduire'
   *                                                 -> Swim
;

Verb 'balancer' 'suspendre'
   * 'se' 'à'/'au'/'aux'/'sur'/'dans' noun           -> Swing
;
#Endif;

Verb 'prendre'
   * multi                                           -> Take
   * multiinside 'à'/'au'/'aux' noun                 -> Remove
   * multiinside 'de'/'d^'/'du'/'des'/'dans'/'sur' 
                                              noun   -> Remove
;

Verb 'décoller' 'détacher'
   * noun                                            -> Take
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'acheter'
   * noun                                            -> Buy
;
#Endif;

Verb 'donner'
   * held 'à'/'au'/'aux' creature                    -> Give
   * creature held                                   -> Give reverse
;

Verb 'lancer' 'jeter'
   * noun                                            -> ThrowAt
   * held 'à'/'au'/'aux' noun                        -> ThrowAt
   * held 'sur'/'dans'/'contre'/
                             'par'/'par-dessus' noun -> ThrowAt
   * creature held                                   -> ThrowAt reverse
;

Verb 'poser'
   * multiheld                                       -> Drop
   * multiexcept 'dans'/'sous'/'entre' noun          -> Insert
   * multiexcept 'sur' noun                          -> PutOn
;

Verb 'insérer'
   * multiexcept 'dans'/'sous'/'entre' noun          -> Insert
;

Verb 'mettre'
   * held                                            -> Wear
   * multiexcept 'dans'/'sous'/'entre' noun          -> Insert
   * multiexcept 'sur' noun                          -> PutOn
;

Verb 'enlever' 'retirer' !TODO FIXME
   * noun=RemoveHeld                                 -> Disrobe ! held
   * multi                                           -> Take
   * multiinside 'de'/'d^'/'du'/'des' noun           -> Remove
;

!Verb 'quitter'
!   *                                                 -> Quit !TODO
!   * held                                            -> Disrobe
!;

Verb 'remplir'
   * noun                                            -> Fill
!   * noun 'de'/'d^'/'avec' noun                      -> Fill
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'vider'
   * noun                                            -> Empty
   * noun 'sur'/'dans' noun                          -> EmptyT
;
#Endif;

Verb 'pousser'
   * noun                                            -> Push
   * noun 'à'/'au'/'en'/'vers' noun                  -> PushDir !contre?
   * noun 'sur'/'dans' noun                          -> Transfer
;

Verb 'tirer'
   * noun                                            -> Pull
;

Verb 'manger'
   * held                                            -> Eat
;

Verb 'boire'
   * noun                                            -> Drink
;

Verb 'ouvrir'
   * noun                                            -> Open
   * noun 'avec' held                                -> Unlock
;

Verb 'fermer'
   * noun                                            -> Close
   * noun 'à'/'avec' held                            -> Lock
;

Verb 'verrouiller'
   * noun 'avec' held                                -> Lock
;

Verb 'déverrouiller'
   * noun 'avec' held                                -> Unlock
;

Verb 'forcer' 'fracturer'
   * noun 'avec' held                                -> Unlock
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'écraser' 'presser'
   * noun                                            -> Squeeze !appuyer_sur? (!=Push)
;
#Endif;

Verb 'appuyer'
   * 'sur' noun                                      -> Push ! Squeeze !?
;

Verb 'allumer' 'démarrer'
   * noun                                            -> SwitchOn
;

Verb 'éteindre' 'arrêter'
   * noun                                            -> SwitchOff
;

Verb 'attacher'
   * noun                                            -> Tie
   * noun 'à'/'au'/'aux'/'avec'/'sur'/'dans' noun    -> Tie
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'régler'
   * noun                                            -> Set
   * noun 'à'/'sur' special                          -> SetTo
;

Verb 'agiter' 'secouer'
   * noun                                            -> Wave
;
#Endif;

Verb 'tourner'
   * noun                                            -> Turn
;

Verb 'creuser'
   * noun                                            -> Dig
   * noun 'avec' held                                -> Dig
   * 'sur'/'dans' noun                               -> Dig
   * 'sur'/'dans' noun 'avec' held                   -> Dig
;

Verb 'couper' 'déchirer'
   * noun                                            -> Cut
   * noun 'avec' held                                -> Attack
;

Verb 'attaquer' 'casser' 'détruire' 'briser'
   * noun                                            -> Attack !attaquer creature?
   * noun 'avec ' held                               -> Attack
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'brûler'
   * noun                                            -> Burn
   * noun 'avec' held                                -> Burn
;

Verb 'souffler'
!  * held                                            -> Blow !#
   * 'sur'/'dans' held                               -> Blow  !noun?
;
#Endif;

Verb 'nettoyer'
   * noun                                            -> Rub
;

!Verb 'utiliser' 'actionner' 'faire' 'déplacer' 
!   * topic                                          -> VagueVerb
!;

Verb 'toucher' 'caresser'
   * noun                                            -> Touch
;

Verb 'écouter'
   *                                                 -> Listen
   * noun                                            -> Listen
;

Verb 'sentir'
   *                                                 -> Smell
   * noun                                            -> Smell
;

#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'goûter'
   * noun                                            -> Taste
;

Verb 'chanter'
   *                                                 -> Sing
;

Verb 'penser' 'réfléchir'
   *                                                 -> Think
;

Verb 'prier'
   *                                                 -> Pray
;

Verb 'merde'
   *                                                 -> Strong !FIXME utile?
   * topic                                           -> Strong
;

Verb 'excuser'
   * 'se'                                            -> Sorry
;

Verb 'zut'
   *                                                 -> Mild !FIXME utile?
   * topic                                           -> Mild
;

#Endif;

Verb 'attendre' 'z//'
   *                                                 -> Wait
;

#IfDef OPTIONAL_EXTENDED_VERBSET;

Verb 'dormir'
   *                                                 -> Sleep
;

Verb 'oui'
   *                                                 -> Yes !'o//'
;

Verb 'non' 
   *                                                 -> No
;
#Endif;

Verb 'inventaire' 'i//' 
   *                                                 -> Inv
;

[ AnswerSub;
	if (second > 1 && RunLife(second,##Answer) ~= 0) rfalse;
	PrintMsg(MSG_ANSWER_SUCCESS);
];

[ AskSub;
	if (RunLife(noun,##Ask) ~= 0) rfalse;
	PrintMsg(MSG_ASK_SUCCESS);
];

[ AskToSub;
	PrintMsg(MSG_ASKTO_SUCCESS);
];

[ AskForSub;
	if (noun == player) <<Inv>>;
	PrintMsg(MSG_ASKFOR_SUCCESS);
];

[ AttackSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate && RunLife(noun, ##Attack) ~= 0) rfalse;
	PrintMsg(MSG_ATTACK_SUCCESS);
];

[ CloseSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_CLOSE_YOU_CANT, 'fermer'); rtrue; }
	if(noun hasnt open) { PrintMsg(MSG_CLOSE_NOT_OPEN, noun); rtrue; }
	give noun ~open;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;
	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_CLOSE_SUCCESS, 'fermer');
];

[ ConsultSub;
	PrintMsg(MSG_CONSULT_NOTHING_INTERESTING);
];

[ CutSub;
	PrintMsg(MSG_CUT_NO_USE);
];

[ DigSub;
	PrintMsg(MSG_DIG_NO_USE);
];

[ DisrobeSub;
    if (noun notin player || noun hasnt worn) { PrintMsg(MSG_DISROBE_NOT_WEARING); rtrue; }
    give noun ~worn;
    if (AfterRoutines()) rtrue;
    if (keep_silent) rtrue;
    PrintMsg(MSG_DISROBE_SUCCESS);
];

[ DrinkSub;
	PrintMsg(MSG_DRINK_NOTHING_SUITABLE);
];

[ DropSub _p;
	if(noun notin player) { PrintMsg(MSG_DROP_NOT_HOLDING); rtrue; }
	if(_DisrobeIfWorn(noun)) rtrue;
	_p = parent(player);
	!if(_p ~= location) <<Insert noun _p>>;
	move noun to parent(player);
	give noun moved;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;
	if(AfterRoutines()) rtrue;
	if(keep_silent) return;
	PrintMsg(MSG_DROP_DROPPED);
];

[ EatSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun has animate) { PrintMsg(MSG_EAT_ANIMATE); rtrue; }
	if(noun hasnt edible) { PrintMsg(MSG_EAT_INEDIBLE); rtrue; }
	remove noun;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_EAT_SUCCESS);
];

#IfDef OPTIONAL_SIMPLE_DOORS;
[ EnterSub _door_dir _i _k;
#IfNot;
[ EnterSub _door_dir;
#EndIf;
	if(noun has door) {
#IfDef OPTIONAL_SIMPLE_DOORS;
		_k = (noun.#door_dir) / 2;
		if(_k > 1) {
			! This is a PunyDoor
			for(_i=0 : _i<_k : _i++)
				if(real_location == noun.&found_in-->_i)
					_door_dir = noun.&door_dir-->_i;
		} else {
#EndIf;
			! Normal Inform door
			_door_dir = noun.door_dir;
			if(UnsignedCompare(_door_dir, top_object) > 0) {
				_door_dir = noun.door_dir();
			}
#IfDef OPTIONAL_SIMPLE_DOORS;
		}
#EndIf;
		! Convert to fake object
		_door_dir = DirPropToFakeObj(_door_dir);
		<<Go _door_dir>>;
	}
	if(noun hasnt enterable) { PrintMsg(MSG_ENTER_YOU_CANT, 'entrer'); rtrue; }
	if(player in noun) { PrintMsg(MSG_ENTER_ALREADY); rtrue; }
	if(noun has container && noun hasnt open) { PrintMsg(MSG_ENTER_NOT_OPEN, noun); rtrue; }
	if(parent(noun) ~= parent(player)) { PrintMsg(MSG_ENTER_BAD_LOCATION); rtrue; }
	PlayerTo(noun, true);
	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_ENTER_SUCCESS, 'entrer');
];

[ ExamineSub x;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		PrintMsg(MSG_EXAMINE_DARK);
		rtrue;
	}
#Endif;
    if (noun.description == 0) {
        if (noun has container) {
            if (noun has open or transparent) <<Search noun>>;
            else { PrintMsg(MSG_EXAMINE_CLOSED, noun); rtrue;	}
		}
        if (noun has switchable) { PrintMsg(MSG_EXAMINE_ONOFF); rtrue; }
		PrintMsg(MSG_EXAMINE_NOTHING_SPECIAL);
    }
	x = PrintOrRun(noun, description);
	if (x == 0 && noun has switchable) PrintMsg(MSG_EXAMINE_ONOFF);
	AfterRoutines();
];

[ ExitSub _p;
	_p = parent(player);
	if(parent(_p) == 0) { PrintMsg(MSG_EXIT_ALREADY); rtrue; }
	if(noun == 0) <<Exit _p>>;
	if(player notin noun) {
		if(IndirectlyContains(noun, player)) { PrintMsg(MSG_EXIT_FIRST_LEAVE, parent(player)); rtrue; }
		if(noun has supporter) { PrintMsg(MSG_EXIT_NOT_ON); rtrue; }
		PrintMsg(MSG_EXIT_NOT_IN);
		rtrue;
	}
	if(noun has container && noun hasnt open) { PrintMsg(MSG_EXIT_NOT_OPEN, noun); rtrue; }
	PlayerTo(parent(noun), true);
	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_EXIT_SUCCESS, 'sortir'); !FIXME
];

[ FillSub;
	PrintMsg(MSG_FILL_NO_WATER);
];

[ GetOffSub;
	if (parent(player) == noun) <<Exit noun>>;
	PrintMsg(MSG_EXIT_NOT_ON); rtrue;
];


[ GiveSub;
	if(ObjectIsUntouchable(second)) return;
	if (parent(noun) ~= player) { PrintMsg(MSG_GIVE_NOT_HOLDING); rtrue; }
	if (second == player)  { PrintMsg(MSG_GIVE_PLAYER); rtrue; }
	if (RunLife(second, ##Give) ~= 0) rfalse;
	PrintMsg(MSG_GIVE_SUCCESS);
];

[ GoSub _prop;
	! when called Directions have been set properly
	_prop = selected_direction;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(_prop == 0) return RuntimeError(ERR_INVALID_DIR_PROP);
#EndIf;

	GoDir(_prop);
];

[ InsertSub _ancestor;
   if(noun == player) <<Enter second>>;
	receive_action = ##Insert;
	if(ObjectIsUntouchable(second)) return;
	if (parent(noun) == second) { PrintMsg(MSG_INSERT_ALREADY); rtrue; }
	_ancestor = CommonAncestor(noun, second);
	if (_ancestor == noun) { PrintMsg(MSG_INSERT_ITSELF); rtrue; }
	if (second ~= _ancestor && second has container && second hasnt open) {
		PrintMsg(MSG_INSERT_NOT_OPEN, second);
		rtrue;
	}

	if(noun ~=player && _GrabIfNotHeld(noun)) rtrue;
	if(_DisrobeIfWorn(noun)) rtrue;

	! run before on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
	action = ##Receive;
	if(RunRoutines(second, before) ~= 0) { action = ##Insert; rtrue; }
	action = ##Insert;

	if (second hasnt container) { PrintMsg(MSG_INSERT_NOT_CONTAINER, second); rtrue; }
	if (_AtFullCapacity(second)) { PrintMsg(MSG_INSERT_NO_ROOM); rtrue; }

	move noun to second;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;

	! run after on object
	if(AfterRoutines()) rtrue;

	! run after on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").after()^";
#EndIf;
	action = ##Receive;
	if(RunRoutines(second, after) ~= 0) { action = ##Insert; rtrue; }
	action = ##Insert;

	if (keep_silent) return;
	PrintMsg(MSG_INSERT_SUCCESS);
];

[ InvSub;
    if(PrintMsg(MSG_INVENTORY_SUCCESS)) {
		AfterRoutines();
	} else {
		PrintMsg(MSG_INVENTORY_EMPTY);
	}
];

[ JumpSub;
	PrintMsg(MSG_JUMP);
];

[ JumpOverSub;
	PrintMsg(MSG_JUMP_OVER);
];

[ ListenSub;
    PrintMsg(MSG_LISTEN_SUCCESS);
];

[ LockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (ObjectIsUntouchable(second)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_LOCK_NOT_A_LOCK, 'verrouiller'); rtrue; }
	if (noun has locked)  { PrintMsg(MSG_LOCK_ALREADY_LOCKED, 'verrouiller'); rtrue; }
	if (noun has open) { PrintMsg(MSG_LOCK_CLOSE_FIRST); rtrue; }
	if (RunRoutines(noun, with_key) ~= second) { PrintMsg(MSG_LOCK_KEY_DOESNT_FIT); rtrue; }
	give noun locked;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_LOCK_SUCCESS, 'verrouiller');
];

[ LookSub _old_lookmode;
	_old_lookmode = lookmode;
	lookmode = 2; ! force long description
	Look();
	lookmode = _old_lookmode;
];

[ OpenSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_OPEN_YOU_CANT, 'ouvrir'); rtrue; }
	if(noun has locked) { PrintMsg(MSG_OPEN_LOCKED); rtrue; }
	if(noun has open) { PrintMsg(MSG_OPEN_ALREADY); rtrue; }
	give noun open;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;
	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_OPEN_SUCCESS);
];

[ PullSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_PULL_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_PULL_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_PULL_ANIMATE); rtrue; }
	PrintMsg(MSG_PULL_SUCCESS); !Nothing obvious happens
];

[ PushSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_PUSH_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_PUSH_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_PUSH_ANIMATE); rtrue; }
	PrintMsg(MSG_PUSH_SUCCESS);
];

[ PushDirSub;
	PrintMsg(MSG_PUSHDIR_DEFAULT);
];

[ PutOnSub _ancestor;
	if(noun == player) <<Enter second>>;
	receive_action = ##PutOn;
	if (ObjectIsUntouchable(second)) return;
	if (parent(noun) == second) { PrintMsg(MSG_PUTON_ALREADY); rtrue; }
	_ancestor = CommonAncestor(noun, second);
	if (_ancestor == noun) { PrintMsg(MSG_PUTON_ITSELF); rtrue; }
	if(noun ~= player && _GrabIfNotHeld(noun)) rtrue;
	if(_DisrobeIfWorn(noun)) rtrue;

	! run before on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
	action = ##Receive;
	if(RunRoutines(second, before) ~= 0) { action = ##PutOn; rtrue; }
	action = ##PutOn;

	if (second hasnt supporter) { PrintMsg(MSG_PUTON_NOT_SUPPORTER); rtrue; }
	if (_AtFullCapacity(second)) { PrintMsg(MSG_PUTON_NO_ROOM); rtrue; }

	move noun to second;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;

	! run after on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").after()^";
#EndIf;
	action = ##Receive;
	if(RunRoutines(second, after) ~= 0) { action = ##PutOn; rtrue; }
	action = ##PutOn;

	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_PUTON_SUCCESS);
];

[ RemoveSub _i;
	_i = parent(noun);
	if (_i has container && _i hasnt open) { PrintMsg(MSG_REMOVE_CLOSED, _i); rtrue; }
	if (_i ~= second) { PrintMsg(MSG_REMOVE_NOT_HERE); rtrue; }
	if (_i has animate) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
	if(TryToTakeNoun() == 1) rtrue;
	action = ##Remove; if (AfterRoutines()) rtrue;
	action = ##Take;   if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_REMOVE_SUCCESS);
];

[ RubSub;
	PrintMsg(MSG_RUB_DEFAULT);
];

[ SearchSub _f _i;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) { PrintMsg(MSG_SEARCH_DARK); rtrue; }
#Endif;
	if (ObjectIsUntouchable(noun)) return;
	objectloop(_i in noun) if(_i hasnt concealed && _i hasnt scenery) _f++;
	if(noun has supporter) {
		if(_f == 0)
			PrintMsg(MSG_SEARCH_NOTHING_ON);
		else
			PrintMsg(MSG_SEARCH_ON_IT_ISARE);
		rtrue;
	}
	if(noun hasnt container) { PrintMsg(MSG_SEARCH_NOTHING_SPECIAL); rtrue; }
	if(noun hasnt transparent && noun hasnt open) {
		PrintMsg(MSG_SEARCH_CANT_SEE_CLOSED); rtrue;
	}
	if(AfterRoutines()) rtrue;
	if(_f == 0)
		PrintMsg(MSG_SEARCH_EMPTY);
	else
		PrintMsg(MSG_SEARCH_IN_IT_ISARE);
];

[ ShowSub;
	if (parent(noun) ~= player) { PrintMsg(MSG_SHOW_NOT_HOLDING); rtrue; }
	if (second == player) <<Examine noun>>;
	if (RunLife(second, ##Show) ~= 0) rfalse;
	PrintMsg(MSG_SHOW_SUCCESS);
];

[ SmellSub;
	if(ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_SMELL_SUCCESS);
];

[ SwitchOffSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) { PrintMsg(MSG_SWITCH_OFF_NOT_SWITCHABLE); rtrue; }
	if (noun hasnt on)         { PrintMsg(MSG_SWITCH_OFF_NOT_ON); rtrue; }
	give noun ~on;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_SWITCH_OFF_SUCCESS);
];

[ SwitchOnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) { PrintMsg(MSG_SWITCH_ON_NOT_SWITCHABLE); rtrue; }
	if (noun has on)           { PrintMsg(MSG_SWITCH_ON_ON); rtrue; }
	give noun on;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_SWITCH_ON_SUCCESS);
];

[ TakeSub;
	if(TryToTakeNoun() == 1) rtrue;
	if(AfterRoutines()) rtrue;
	if (keep_silent) return;
	PrintMsg(MSG_TAKE_SUCCESS);
];

[ TieSub;
	PrintMsg(MSG_TIE_DEFAULT);
];

[ TellSub;
	if (noun == player) { PrintMsg(MSG_TELL_PLAYER); rtrue; }
	if (RunLife(noun, ##Tell) ~= 0) rfalse;
	PrintMsg(MSG_TELL_SUCCESS);
];

[ ThrowAtSub;
	if(_GrabIfNotHeld(noun)) rtrue;
	if(second == nothing) { PrintMsg(MSG_THROW_ANIMATE); rtrue; }
	if(ObjectIsUntouchable(second)) return;
	if(_DisrobeIfWorn(noun)) rtrue;
	if(second > 1) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
		action = ##ThrownAt;
		if (RunRoutines(second, before) ~= 0) { action = ##ThrowAt; rtrue; }
		action = ##ThrowAt;
	}
	if(second hasnt animate) { PrintMsg(MSG_THROW_ANIMATE); rtrue; }
	if(RunLife(second,##ThrowAt) ~= 0) rfalse;
	PrintMsg(MSG_THROW_SUCCESS);
];

[ TouchSub;
	if(ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_TOUCH_SUCCESS);
];

[ TransferSub;
	if(_GrabIfNotHeld(noun)) rtrue;
	if (second has supporter) <<PutOn noun second>>;
	!if (second == d_obj) <<Drop noun>>;
	<Insert noun second>;
];

[ TurnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   { PrintMsg(MSG_TURN_STATIC); rtrue; }
	if (noun has scenery)  { PrintMsg(MSG_TURN_SCENERY); rtrue; }
	if (noun has animate)  { PrintMsg(MSG_TURN_ANIMATE); rtrue; }
	PrintMsg(MSG_TURN_SUCCESS);
];

[ UnlockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_UNLOCK_NOT_A_LOCK, 'déverrouiller'); rtrue; }
	if (noun hasnt locked)  { PrintMsg(MSG_UNLOCK_ALREADY_UNLOCKED, 'déverrouiller'); rtrue; }
	if (RunRoutines(noun, with_key) ~= second) { PrintMsg(MSG_UNLOCK_KEY_DOESNT_FIT); rtrue; }
	give noun ~locked;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_UNLOCK_SUCCESS, 'déverrouiller');
];

[ WaitSub;
    PrintMsg(MSG_WAIT_SUCCESS);
];

[ WearSub;
	if (parent(noun) ~= player) { PrintMsg(MSG_WEAR_NOT_HOLDING); rtrue; }
	if (noun has worn) { PrintMsg(MSG_WEAR_ALREADY_WORN); rtrue; }
	if (noun hasnt clothing) { PrintMsg(MSG_WEAR_NOT_CLOTHING, 'mettre'); rtrue; }
	give noun worn;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	PrintMsg(MSG_WEAR_SUCCESS);
];


! ---------------------
! Extended verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_VERBSET;

[ BlowSub;
	PrintMsg(MSG_BLOW_DEFAULT);
];

[ BurnSub;
	PrintMsg(MSG_BURN_DEFAULT);
];

[ BuySub;
	PrintMsg(MSG_BUY_DEFAULT);
];

[ EmptySub;
	<EmptyT noun FAKE_D_OBJ>;
];

[ EmptyTSub _i _j _k _flag _recipient;
	if(noun == second) { PrintMsg(MSG_EMPTY_WOULDNT_ACHIEVE); rtrue; }
	if(ObjectIsUntouchable(noun) || ObjectIsUntouchable(second)) return;
!		_recipient = TouchCeiling(player);
	if(selected_direction ~= d_to) {
!	else {
		_recipient = second;
      if(second hasnt supporter) {
         if(second hasnt container) { PrintMsg(MSG_EMPTY_CANT_CONTAIN, second); rtrue; }
         if(second hasnt open) { PrintMsg(MSG_EMPTY_IS_CLOSED, second); rtrue; }
		}
	}
	_i = child(noun); _k = children(noun);
	if(_i == 0) { PrintMsg(MSG_EMPTY_ALREADY_EMPTY, noun); rtrue; }
	while(_i ~= 0) {
		_j = sibling(_i);
		_flag = 0;
		if(ObjectIsUntouchable(noun)) _flag = 1;
		if(noun hasnt container) _flag = 1;
		if(noun hasnt open) _flag = 1;
		if(selected_direction ~= d_to) {
			if(second hasnt supporter) {
				if(second hasnt container) _flag = 1;
				if(second hasnt open) _flag = 1;
			}
		}
		if(_k-- == 0) _flag = 1;
		if(_flag) break;
		if(keep_silent == 0) print (name) _i, ": ";
		if(selected_direction == d_to) {
			_GrabIfNotHeld(_i);
			<Drop _i>;
		} else
			<Transfer _i _recipient>;
		_i = _j;
	}
];

[ KissSub;
    if (ObjectIsUntouchable(noun)) return;
    if (RunLife(noun, ##Kiss) ~= 0) rfalse;
    if (noun == player) { PrintMsg(MSG_KISS_PLAYER); rtrue; }
    PrintMsg(MSG_KISS_SUCCESS);
];

[ MildSub;
	PrintMsg(MSG_MILD_DEFAULT);
];

[ NoSub;
	PrintMsg(MSG_RHETORICAL_QUESTION);
];

[ PraySub;
	PrintMsg(MSG_PRAY_DEFAULT);
];

[ SetSub;
	PrintMsg(MSG_SET_DEFAULT);
];

[ SetToSub;
	PrintMsg(MSG_SET_TO_DEFAULT);
];

[ SingSub;
	PrintMsg(MSG_SING_DEFAULT);
];

[ SleepSub;
	PrintMsg(MSG_SLEEP_DEFAULT);
];

[ SorrySub;
	PrintMsg(MSG_SORRY_DEFAULT);
];

[ StrongSub;
	PrintMsg(MSG_STRONG_DEFAULT);
];

[ SqueezeSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate) { PrintMsg(MSG_SQUEEZE_YOURSELF); rtrue; }
	PrintMsg(MSG_SQUEEZE_DEFAULT);
];

[ SwimSub;
	PrintMsg(MSG_SWIM_DEFAULT);
];

[ SwingSub;
	PrintMsg(MSG_SWING_DEFAULT);
];

[ TasteSub;
	if (ObjectIsUntouchable(noun)) return;
	PrintMsg(MSG_TASTE_DEFAULT);
];

[ ThinkSub;
	PrintMsg(MSG_THINK_DEFAULT);
];

[ WakeSub;
    PrintMsg(MSG_WAKE_SUCCESS);
];

[ WakeOtherSub;
    if (ObjectIsUntouchable(noun)) return;
    if (RunLife(noun, ##WakeOther) ~= 0) rfalse;
    PrintMsg(MSG_WAKEOTHER_SUCCESS);
];

[ WaveSub;
    if(parent(noun) ~= player) { PrintMsg(MSG_WAVE_NOTHOLDING, noun); rtrue; }
    PrintMsg(MSG_WAVE_DEFAULT);
];

[ WaveHandsSub;
	PrintMsg(MSG_WAVEHANDS_DEFAULT);
];

[ YesSub;
	PrintMsg(MSG_RHETORICAL_QUESTION);
];

#EndIf;

! ---------------------
! Base meta verbs
! ---------------------
!FRENCH
Verb meta 'encore' 'g//'
   *                                           -> Again;

Verb meta 'description'
   *                                           -> LookModeNormal
   * 'longue'                                  -> LookModeLong
   * 'courte'                                  -> LookModeShort
   * 'brève'/'normale'                         -> LookModeNormal;

#IfDef OPTIONAL_FULL_SCORE;
Verb meta 'score'
   *                                           -> Score
   * 'total'                                   -> FullScore
   * 'activer'/'on'                            -> NotifyOn
   * 'désactiver'/'off'                        -> NotifyOff;
#Ifnot;
Verb meta 'score'
   *                                           -> Score
   * 'activer'/'on'                            -> NotifyOn
   * 'désactiver'/'off'                        -> NotifyOff;
#EndIf;

Verb meta 'oups'
   *                                           -> Oops
   * special                                   -> OopsCorrection;

Verb meta 'recommencer'
   *                                           -> Restart;

Verb meta 'charger'
	*                                           -> Restore;

Verb meta 'sauvegarder'
	*                                           -> Save;

Verb meta 'version'
	*                                           -> Version;

Verb meta 'quitter' 'q//'
	*                                           -> Quit;

[ AgainSub;
	! nothing here - this is taken care of in the main game loop instead
];

#IfDef OPTIONAL_FULL_SCORE;
[ FullScoreSub _i;
	ScoreSub();
	new_line;
	PrintMsg(MSG_FULLSCORE_START);
#IfDef TASKS_PROVIDED;
	for(_i=0 : _i<NUMBER_TASKS : _i++)
		if (task_done->_i == 1) {
		PANum(task_scores->(_i));
		PrintTaskName(_i);
	}
#IfNot;
	_i = 0; ! Avoid warning
#EndIf;
	if(things_score ~= 0) {
		PANum(things_score);
		print "finding sundry items^";
	}
	if(places_score ~= 0) {
		PANum(places_score);
		print "visiting various places^";
	}
	@new_line;
	PANum(score);
	PrintMsg(MSG_FULLSCORE_END);
];
#EndIf;

[ LookModeNormalSub;
	lookmode=1;
	PrintMsg(MSG_LOOKMODE_NORMAL);
];

[ LookModeLongSub;
	lookmode=2;
	PrintMsg(MSG_LOOKMODE_LONG);
];

[ LookModeShortSub;
	lookmode=3;
	PrintMsg(MSG_LOOKMODE_SHORT);
];

[ NotifyOnSub;
	notify_mode = 1;
	"La notification du score est activée.";
];

[ NotifyOffSub;
	notify_mode = 0;
	"La notification du score est désactivée.";
];

[ OopsSub;
	"N'y pensez plus."; !FIXME
];

[ OopsCorrectionSub;
	! nothing here - this is taken care of in the main game loop instead
];

[ QuitSub;
	PrintMsg(MSG_AREYOUSUREQUIT);
	if(YesOrNo()) {
		deadflag = GS_QUIT;
	}
];

[ RestartSub;
    PrintMsg(MSG_RESTART_CONFIRM);
	if(YesOrNo()) {
		@restart;
        PrintMsg(MSG_RESTART_FAILED);
	}
];

#IfV3;
[ RestoreSub;
	@restore ?restore_success; ! can't use @restore because of compiler test
	verb_word = 'charger';
	PrintMsg(MSG_RESTORE_FAILED);
	rtrue;
.restore_success; ! This is never reached, since a successful restore continues after save opcode.
#IfNot;
[ RestoreSub _flag;
	@restore -> _flag;
	! must have failed here so no need to check the flag
	PrintMsg(MSG_RESTORE_FAILED);
#EndIf;
];

#IfV3;
[ SaveSub;
	@save ?save_success;
	PrintMsg(MSG_SAVE_FAILED);
	rtrue;
.save_success;
    PrintMsg(MSG_SAVE_SUCCESS);
#IfNot;
[ SaveSub _result;
	@save -> _result;
	if(_result == 0) { PrintMsg(MSG_SAVE_FAILED); rtrue; }
	PrintMsg(MSG_SAVE_SUCCESS); ! _result = 1: save ok, 2: Restore ok
#EndIf;
];

[ ScoreSub;
	PrintMsg(MSG_SCORE_SUCCESS);
	PrintRank();
];

[ Banner _i;
	if(Story ~= 0) {
#IfV5;
		style bold;
#EndIf;
		print (string) Story;
#IfV5;
		style roman;
#EndIf;
		if(Headline ~= 0) print (string) Headline;
    }
	print "Version ", (0-->1) & $03ff, " / numérotée ";
	for (_i = 18:_i < 24: _i++) print (char) 0->_i;
	print " / Inform v";
	inversion;
	print " PunyInform v", PUNYINFORM_MAJOR_VERSION, (char) '.', PUNYINFORM_MINOR_VERSION;
#IfDef DEBUG;
	print " D";
#EndIf;
	@new_line;
];

[ VersionSub;
	Banner();
];

! ---------------------
! Extended meta verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_METAVERBS;
Constant HDR_GAMEFLAGS     $10;
Global transcript_mode = false;        ! true when game scripting is on
Global xcommsdir = false;              ! true if command recording is on

Verb meta 'noscript' 'unscript'
	*                                           -> ScriptOff;

#Ifndef NO_PLACES;
Verb meta 'objets'
	*                                           -> Objects;
Verb meta 'lieux'
	*                                           -> Places;
#Endif; ! NO_PLACES

Verb 'commandes'
   *                                           -> CommandsOn
   * 'activer'/'on'                            -> CommandsOn
   * 'désactiver'/'off'                        -> CommandsOff
   * 'rejouer'                                 -> CommandsRead;

Verb meta 'script' 'transcription'
   *                                           -> ScriptOn
   * 'activer'/'on'                            -> ScriptOn
   * 'désactiver'/'off'                        -> ScriptOff;

Verb meta 'vérifier'
	*                                           -> Verify;

[ CommandsOnSub;
	@output_stream 4;
	xcommsdir = 1;
	"[L'enregistrement des commandes est activé.]";
];

[ CommandsOffSub;
	if (xcommsdir == 1) @output_stream -4;
	xcommsdir = 0;
	"[L'enregistrement des commandes est désactivé.]";
];

[ CommandsReadSub;
	@input_stream 1;
	xcommsdir = 2;
	"[Rejouer les commandes.]";
];

#Ifndef NO_PLACES;
[ PlacesSub i j k;
	print "Vous avez visité : ";
	objectloop(i has visited) if(parent(i) == 0) j++;
	objectloop(i has visited) {
		if(parent(i) == 0) {
			print (name) i; k++;
			if (k == j) { print ".^"; return; }
			if (k == j-1) print " et ";
			else          print ", ";
		}
	}
];

[ ObjectsSub i j f; !TODO FIXME
	print "Vous avez acquis : ";
	objectloop (i has moved) {
		j = parent(i);
		if(j) {
			if(f == 0) @new_line;
			f = 1;
			print "- ", (the) i, "   ";
			if (j == player) {
				if (i has worn) {
					print "(sur vous)";
				} else {
					print "(avec vous)"; ! dans l'inventaire
				}
			} else if(j has animate) print "(hors jeu)";
			else if(j has visited) print "(dans ", (name) j, ")";
			else if(j has container) print "(dans ", (the) j, ")";
			else if(j has supporter) print "(sur ", (the) j, ")";
			else if(j has enterable) print "(dans ", (the) j, ")";
			else print "(hors jeu)"; !FIXME
			@new_line;
		}
	}
	if(f == 0) "aucun.";
];
#Endif; ! NO_PLACES

[ ScriptOnSub;
	transcript_mode = ((HDR_GAMEFLAGS-->0) & 1);
	if (transcript_mode) "Une transcription est déjà en cours.";
	@output_stream 2;
	if (((HDR_GAMEFLAGS-->0) & 1) == 0) "La tentative de commencer la transcription a échoué.";
	print "Début de la transcription de^";
	Banner();
	transcript_mode = true;
];

[ ScriptOffSub;
	transcript_mode = ((HDR_GAMEFLAGS-->0) & 1);
	if (transcript_mode == false) "Aucune transcription n'est en cours.";
	print "^Fin de la transcription.^";
	@output_stream -2;
	if ((HDR_GAMEFLAGS-->0) & 1) "Impossible de terminer la transcription.";
	transcript_mode = false;
];

[ VerifySub;
	@verify ?Vmaybe;
	jump Vwrong;
.Vmaybe;
	"Le fichier du jeu est valide.";
.Vwrong;
	"Le fichier du jeu ne semble pas valide et peut être corrompu.";
];


#EndIf;

! ---------------------
! Debug verbs
! ---------------------

#IfDef DEBUG;
Verb meta 'pronoun' 'pronouns'
    *                                          -> Pronouns;

Verb meta 'random'
	*                                           -> RandomSeed
	* special                                   -> RandomSeed
	* 'seed' number                             -> RandomSeed;

Verb meta 'scope'
	*                                           -> Scope
	* noun                                      -> Scope;

Verb meta 'purloin'
	* noun                                      -> Purloin;

Verb meta 'tree'
	*                                           -> Tree
	* noun                                      -> Tree;

Verb meta 'gonear'
	* noun                                      -> GoNear;

Verb meta 'routines' 'messages'
	*                                           -> RoutinesOn
	* 'on'                                      -> RoutinesOn
	* 'off'                                     -> RoutinesOff;

Verb meta 'actions'
	*                                           -> ActionsOn
	* 'on'                                      -> ActionsOn
	* 'off'                                     -> ActionsOff;

Verb meta 'timers' 'daemons'
	*                                           -> TimersOn
	* 'on'                                      -> TimersOn
	* 'off'                                     -> TimersOff;


Global scope_cnt;

[ GoNearSub _obj;
	_obj = noun;
	while(parent(_obj) ~= 0) _obj = parent(_obj);
	PlayerTo(_obj);
];

!FRENCH
[ PronounsSub; !TODO nothing l'
	print "Pronoms : le ", (name) le_obj, ", la ", (name) la_obj, ", l' ", (name) l_obj, ", les ", (name) les_obj, ", lui ", (name) lui_obj, ", leur " , (name) leur_obj, ".^";
];

[ PurloinSub;
	if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; }
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	move noun to player;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;
	"Purloined.";
];

[ RandomSeedSub _i;
	! sets the random seed, making randomness predictable
	! also a test of special and number, thus the fancy grammar
	!print special_word, " ", special_number," ",parsed_number,"^";
	if(special_word ~=0) "You can't send randomness to an object!";
	_i = parsed_number;
	if(_i == 0) _i = 100; ! either 'xxxx' (unknown special) or '0'
	random(-_i);
	"The random seed is set to ", _i, ".";
];

[ _ScopeSubHelper p_obj;
	print scope_cnt++,": ", (a) p_obj, " (", p_obj, ")";
	if(ObjectIsUntouchable(p_obj, true)) print " [untouchable]";
	if(ObjectIsInvisible(p_obj, true)) print " [invisible]";
	@new_line;
];

[ ScopeSub;
	scope_cnt = 1;
	LoopOverScope(_ScopeSubHelper, noun);
	if(scope_cnt == 0) "Nothing in scope.^";
];

[ TreeSub _obj _p;
	_obj = noun;
	if(_obj==0) _obj = real_location;
	print (name) _obj;
	_p = parent(_obj);
	if(_p) {
		print " (";
		if(_p has supporter)
			@print_char 'o';
		else
			@print_char 'i';
		print "n ", (name) _p, ")";
	}
	@new_line;
	TreeSubHelper(_obj, 1);
];

[TreeSubHelper p_parent p_indent _x _i;
	objectloop(_x in p_parent) {
		for(_i = 0 : _i < p_indent : _i++) print "  ";
		print (name) _x, "^";
		if(child(_x)) TreeSubHelper(_x, p_indent + 1);
	}
];

[ RoutinesOnSub;  debug_flag = debug_flag | 1;  "[Message listing on.]"; ];

[ RoutinesOffSub; debug_flag = debug_flag & 14; "[Message listing off.]"; ];

[ ActionsOnSub;   debug_flag = debug_flag | 2;  "[Action listing on.]"; ];

[ ActionsOffSub;  debug_flag = debug_flag & 13; "[Action listing off.]"; ];

[ TimersOnSub;    debug_flag = debug_flag | 4;  "[Timers listing on.]"; ];

[ TimersOffSub;   debug_flag = debug_flag & 11; "[Timers listing off.]"; ];


#EndIf;

! ---------------------
! HELP ROUTINES
! ---------------------
!FRENCH
[ _ListObjsMsg;
	print "^Vous remarquez "; ! Il y a / Vous pouvez [...] voir
	if(also_flag) print "aussi "; ! également
];

[ _ListObjsInOnMsg p_parent;
	if(newline_flag)
		print "^";
	if(p_parent has supporter) print "Sur "; else print "Dans ";
	print (the) p_parent, " vous pouvez ";
	if(also_flag) print "aussi ";
	print "voir ";
];

[ Look _obj _top_ceil _ceil _initial_found _describe_room
	_you_can_see_1 _you_can_see_2 _desc_prop _last_level _action;
	PrintMsg(MSG_LOOK_BEFORE_ROOMNAME);
	if((lookmode == 1 && location hasnt visited) || lookmode == 2) _describe_room = true;
#IfV5;
	style bold;
#EndIf;

	! Print the room name
#Ifdef OPTIONAL_NO_DARKNESS;
	_ceil = ScopeCeiling(player, _last_level);
#Ifnot;
	if(location == thedark)
		_ceil = location;
	else
		_ceil = ScopeCeiling(player, _last_level);
#Endif;

	_top_ceil = _ceil;

	if(_ceil == location) {
#IfDef OPTIONAL_FULL_SCORE;
		if(location has scored && location hasnt visited) {
			score = score + ROOM_SCORE;
			places_score = places_score + ROOM_SCORE;
		}
#EndIf;
		_PrintObjName(location);
	} else {
		print (The) _ceil;
	}
#IfV5;
	style roman;
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		@new_line;
		PrintOrRun(location, description);
		jump EndOfLook;
	}
#Endif;
	_obj = parent(player);
!FRENCH
	while(_obj ~= _ceil or 0) {
		if(_obj has supporter)
			print " (sur ";
		else
			print " (dans ";
		print (the) _obj, ")";
		_obj = parent(_obj);
	}
	while(_ceil ~= player or 0) {
		if(_describe_room) {
			if(_ceil == location) {
				@new_line;
				PrintOrRun(_ceil, description);
			} else if(_ceil.inside_description ~= 0 or NULL) {
				@new_line;
				PrintOrRun(_ceil, inside_description);
			}
		} else if(_ceil == location)
			@new_line;
		also_flag = false;
		! write intial and describe messages in a new paragraph
		objectloop(_obj in _ceil && _obj hasnt scenery or concealed && _obj ~= player) {
			give _obj workflag;
			if(_obj.&describe) {
				if(PrintOrRun(_obj, describe, 0)) {
					_initial_found = true;
					give _obj ~workflag;
					also_flag = true;
					continue;
				}
			}
			if(_obj has container or door) {
				if(_obj has open) {
					_desc_prop = when_open;
				} else {
					_desc_prop = when_closed;
				}
			} else if(_obj has switchable) {
				if(_obj has on) {
					_desc_prop = when_on;
				} else {
					_desc_prop = when_off;
				}
			} else {
				_desc_prop = initial;
			}
			if(_obj.&_desc_prop && (_obj hasnt moved || _desc_prop == when_off)) { ! Note: when_closed in an alias of when_off
				_initial_found = true;
				give _obj ~workflag;
				@new_line;
				PrintOrRun(_obj, _desc_prop);
				also_flag = true;
			}
		}

		! write any remaining objects in a new paragraph
		if(parent(_ceil) == 0) {
			_you_can_see_1 = _ListObjsMsg;
			_you_can_see_2 = ".^";
		} else {
			_you_can_see_1 = _ListObjsInOnMsg;
			_you_can_see_2 = ".^";
		}
		newline_flag = true;
		if(PrintContents(_you_can_see_1, _ceil, true)) print (string) _you_can_see_2;


#IfDef OPTIONAL_PRINT_SCENERY_CONTENTS;
		newline_flag = true;
		objectloop(_obj in _ceil && (_obj has scenery or concealed) &&
				(_obj has supporter ||
					(_obj has container && _obj has transparent or open)) &&
					IndirectlyContains(_obj, player) == false) {
			if(PrintContents(_ListObjsInOnMsg, _obj)) {
				print (string) ". ";
				newline_flag = false;
			}
		}
		if(newline_flag == false)
			print "^";
#EndIf;

		! Descend one level
		_ceil = ScopeCeiling(player, _ceil);
	} ! while
.EndOfLook;
	! finally, call the optional library entry routine
	LookRoutine();
	_action = action; action = ##Look;
	AfterRoutines();
	action = _action;

	if(_top_ceil == location)
		give location visited;
];

#IfnDef PrintRank;
[ PrintRank; "."; ];
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ Achieved num;
    if (task_done->num == 0) {
        task_done->num = 1;
        score = score + task_scores->num;
    }
];
#EndIf;
[ PANum p_m _n;
	print "  ";
	_n = p_m;
	if(_n < 0)    { _n = -p_m; _n = _n*10; }
	if(_n < 10)   { print "   "; jump Panuml; }
	if(_n < 100)  { print "  "; jump Panuml; }
	if(_n < 1000) { print " "; }
.Panuml;
	print p_m, " ";
];
#EndIf;

[ TryToTakeNoun _i _k _ancestor _after_recipient;
    ! Try to transfer the given item to the player: return false
    ! if successful, true if unsuccessful, printing a suitable message
    ! in the latter case.
    ! People cannot ordinarily be taken.
    if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; }
    if(noun has animate) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }

	_ancestor = CommonAncestor(player, noun);

    if (_ancestor == 0) {
        _i = _ObjectScopedBySomething(noun);
        if (_i) _ancestor = CommonAncestor(player, _i);
    }

	if(noun in player) { PrintMsg(MSG_TAKE_ALREADY_HAVE, noun); rtrue; }
	if(ObjectIsUntouchable(noun, false, true)) rtrue;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	! The item is now known to be accessible.

    ! Consult the immediate possessor of the item, if it's in a container
    ! which the actor is not in.

    _i = parent(noun);
    if (_i && _i ~= _ancestor && (_i has container or supporter)) {
        _after_recipient = _i;
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _i, ").before()^";
#EndIf;
        _k = action; action = ##LetGo;
        if (RunRoutines(_i, before)) { action = _k; rtrue; }
        action = _k;
    }

    if(noun has static) { PrintMsg(MSG_TAKE_STATIC); rtrue; }
    if(noun has scenery) { PrintMsg(MSG_TAKE_SCENERY); rtrue; }

    if(_AtFullCapacity(player)) { PrintMsg(MSG_TAKE_NO_CAPACITY); rtrue; }

#IfDef OPTIONAL_FULL_SCORE;
	if(noun hasnt moved && noun has scored) {
		score = score + OBJECT_SCORE;
		things_score = things_score + OBJECT_SCORE;
	}
#EndIf;
	move noun to player;
	give noun moved ~concealed;
#IfDef OPTIONAL_MANUAL_SCOPE;
	scope_modified = true;
#EndIf;

	! Send "after" message to the object letting go of the item, if any.

	if (_after_recipient) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _after_recipient, ").after()^";
#EndIf;
		_k = action; action = ##LetGo;
		if (RunRoutines(_after_recipient, after)) { action = _k; rtrue; }
		action = _k;
	}

	rfalse;
];

#IfDef OPTIONAL_SIMPLE_DOORS;
[ GoDir p_property _new_location _door_to _vehicle _vehicle_mode _saved_location _i _j _k;
#IfNot;
[ GoDir p_property _new_location _door_to _vehicle _vehicle_mode _saved_location;
#EndIf;
	if(parent(player) ~= real_location) {
		! special rule when in enterable (veichles)
		! before routine for the object is called with Go dir, and returns
		! 0   to disallow the movement, printing a refusal;
		! 1   to allow the movement, moving vehicle and player;
		! 2   to disallow but print and do nothing; or
		! 3   to allow but print and do nothing.
		_vehicle = parent(player);
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _vehicle, ").before()^";
#EndIf;
		_saved_location = location;
#Ifndef OPTIONAL_NO_DARKNESS;
		if(location == thedark) location = real_location;
#Endif;
		_vehicle_mode = RunRoutines(_vehicle, before);
		if(_vehicle_mode ~= 3) location = _saved_location;
		if(_vehicle_mode == 0) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
		if(_vehicle_mode == 2 or 3) rtrue;
	}
	!if(player notin location) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
	if(real_location provides p_property) {
		@get_prop real_location p_property -> _new_location; ! works in z3 and z5
	}
	if(_new_location ofclass String)
		print_ret (string) _new_location;
	if(UnsignedCompare(_new_location, top_object) > 0) {
		_new_location = real_location.p_property();
		if(_new_location == 1)
			rtrue;
	}

	! Check for a door
	if(_new_location ~= 0 && _new_location has door) {
		! The destination is in fact a door
		if(_new_location has concealed)
			_new_location = 0;
		else {
			if(_new_location hasnt open) { PrintMsg(MSG_GO_DOOR_CLOSED, _new_location); rtrue; }
			_door_to = _new_location.door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
			if(_door_to == 0) {
				! PunyDoor
				_k = (_new_location.#found_in) / 2;
				for(_i=0 : _i<_k : _i++)
					if(real_location == _new_location.&found_in-->_i) {
						_j = _i & $fffe;
						if(_j == _i) _j++;
					}
				_new_location = _new_location.&found_in-->_j;
			} else {
#EndIf;
				! Normal Inform door
				if(UnsignedCompare(_door_to, top_object) > 0) {
					_new_location = _new_location.door_to();
	!				print "GoDir, door leads to ", (the) _new_location, "^";
					if(_new_location == 1)
						rtrue;
				} else
					_new_location = _door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
			}
#EndIf;
		}
	}

	! If _new_location is 0, we tell the player they can't go there and exit
	if(_new_location == 0) {
		if(real_location provides cant_go) {
			print_ret (string) real_location.cant_go;
		}
        PrintMsg(MSG_GO_CANT_GO);
		rtrue;
	}

	action = ##Going;
	if (RunRoutines(_new_location, before) ~= 0) { action = ##Go; rtrue; }
	action = ##Go;

	if(_vehicle_mode == 1) {
		move _vehicle to _new_location;
		_new_location = _vehicle;
	}
	PlayerTo(_new_location, true);
	if(deadflag ~= GS_PLAYING) rtrue;
	if (AfterRoutines()) rtrue;
	if (keep_silent) rtrue;
	Look();
];

!FRENCH
[ VerbName p_v ; !FIXME
	! first give entry routine a chance to override
	if(PrintVerb(p_v)) return;
#IfV3;
   switch(p_v) {
      'déverrouiller': print "déverrouiller"; return;
      'enlever':       print "enlever"; return;
      'insérer':       print "insérer"; return;
      'prendre':       print "prendre"; return;
      'retirer':       print "retirer"; return;
      'verrouiller':   print "verrouiller"; return;
   }
#IfNot;
   switch(p_v) {
      'déverrouiller': print "déverrouiller"; return;
      'verrouiller':   print "verrouiller"; return;
   }
#EndIf;
	print (address) p_v;
];

