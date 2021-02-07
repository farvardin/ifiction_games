! Part of PunyInform, a standard library for writing interactive fiction using Inform 6.
!
System_file;

!FRENCH
#IfV5;
! treize emplacements disponibles ; il manque 'ä' 'ü' 'ÿ' 'ö' 'æ'
Zcharacter 'à';
Zcharacter 'â';
Zcharacter 'ç';
Zcharacter 'è';
Zcharacter 'é';
Zcharacter 'ê';
Zcharacter 'ë';
Zcharacter 'î';
Zcharacter 'ï';
Zcharacter 'ô';
Zcharacter 'œ';
Zcharacter 'ù';
Zcharacter 'û';
#EndIf;

! V3 Pas d'accents à la saisie ni dans le dictionnaire ; pas de directive Zcharacter
! V5 Avec ou sans accents à la saisie, mais pas dans le dictionnaire
! V5 Accents à la saisie et dans le dictionnaire

Constant PUNYINFORM_MAJOR_VERSION = 1;
Constant PUNYINFORM_MINOR_VERSION = 9;

#IfnDef CUSTOM_ABBREVIATIONS;
Abbreviate ". ";
Abbreviate ", ";
#EndIf;

#IfDef STATUSLINE_TIME;
#IfDef STATUSLINE_SCORE;
Message fatalerror "Can't define both STATUSLINE_TIME and STATUSLINE_SCORE."
#EndIf;
#EndIf;

Constant Grammar__Version = 2;
Constant INDIV_PROP_START 64;
Constant NULL         = $ffff;

Constant PHASE1 = 1; ! just check if pattern matches (no side effects such as which? questions or indirect actions)
Constant PHASE2 = 2; ! parse the given pattern with side effects
Constant PHASE2_SUCCESS         = 0;
Constant PHASE2_ERROR           = 1;
Constant PHASE2_DISAMBIGUATION  = 2;


!Constant WORDSIZE 2; ! set by the compiler from Inform 6.30

Constant ALL_WORD     = 'tout'; !TODO
Constant EXCEPT_WORD1 = 'sauf';
Constant EXCEPT_WORD2 = 'sauf';
Constant AND_WORD     = 'et';
Constant THEN1__WD    = 'puis'; !alors
Constant comma_word   = 'comma,';  ! An "untypeable word" used to substitute
                                   ! for commas in parse buffers

!FRENCH
!Constant SOMETHING_STR = "quelque chose";
!Constant SOMEONE_STR = "quelqu'un";

#Ifndef DEFAULT_CAPACITY;
Constant DEFAULT_CAPACITY = 100;
#Endif;

#Ifndef OPTIONAL_NO_DARKNESS;
Attribute light;
#Endif;
Attribute edible;
Attribute absent;
Attribute talkable;
Attribute supporter;
Attribute container;
Attribute enterable;
Attribute transparent;
Attribute open;
Attribute openable;
Attribute concealed;
Attribute moved;
Attribute visited alias moved;
Attribute proper;
Attribute scenery;
Attribute static;
Attribute animate;
Attribute clothing;
Attribute worn;
Attribute pluralname;
Attribute female;
Attribute neuter;
Attribute general;
Attribute switchable;
Attribute on;
Attribute door;
Attribute locked;
Attribute lockable;
Attribute workflag;


! when you order a NPC, but the command isn't understood
! See: http://www.inform-fiction.org/manual/html/s18.html
Fake_Action Order;
Fake_Action Receive;
Fake_Action LetGo;
Fake_Action ThrownAt;
Fake_Action NotUnderstood;
Fake_Action PluralFound;
Fake_Action Going;

Property additive before $ffff;
Property additive after  $ffff;
Property additive life   $ffff;

Property n_to;  Property s_to; !  Slightly wastefully, these are
Property e_to;  Property w_to; !  (they might be routines)
#IfDef OPTIONAL_FULL_DIRECTIONS;
! These have to come in this position and order if we HAVE full directions
Property ne_to;
Property nw_to;
Property se_to;
Property sw_to;
#EndIf;
Property u_to;  Property d_to;
Property in_to; Property out_to;

#Ifndef OPTIONAL_FULL_DIRECTIONS;
! These have to come outside the other direction props if we DON'T HAVE full directions
Property ne_to;
Property nw_to;
Property se_to;
Property sw_to;
#EndIf;


Constant N_TO_CONST = n_to;
Constant OUT_TO_CONST = out_to;

Property door_to     alias n_to;     !  For economy: these properties are
Property when_closed alias s_to;     !  used only by objects which
Property with_key    alias e_to;     !  aren't rooms
Property door_dir    alias w_to;
Property invent      alias u_to;
Property add_to_scope alias se_to;
!Property list_together alias sw_to;
Property react_before alias ne_to;
Property react_after  alias in_to;
!Property grammar     alias nw_to;
Property orders      alias out_to;

Property initial;
Property when_open   alias initial;
Property when_on     alias initial;
Property when_off    alias when_closed;
Property inside_description alias d_to;
Property description;
Property additive describe $ffff;

Property cant_go;
Property article alias cant_go;

Property found_in;         !  For fiddly reasons this can't alias

Property time_left;
Property number;
Property additive time_out $ffff;
Property daemon alias time_out;
Property additive each_turn $ffff;

Property capacity alias nw_to;

Property short_name 0;
Property parse_name   alias sw_to;


! ! directions
! Property n_to;
! Property s_to;
! Property e_to;
! Property w_to;
! #IfDef OPTIONAL_FULL_DIRECTIONS;
! Property ne_to;
! Property nw_to;
! Property se_to;
! Property sw_to;
! #EndIf;
! Property u_to;
! Property d_to;
! Property in_to;
! Property out_to;

! Property cant_go;
! Property door_to alias n_to;
! Property door_dir alias s_to;
!Constant OPTIONAL_FULL_DIRECTIONS;

Constant FAKE_N_OBJ = 10001;
Constant FAKE_S_OBJ = 10002;
Constant FAKE_E_OBJ = 10003;
Constant FAKE_W_OBJ = 10004;

#IfDef OPTIONAL_FULL_DIRECTIONS;

Constant FAKE_NE_OBJ = 10005;
Constant FAKE_NW_OBJ = 10006;
Constant FAKE_SE_OBJ = 10007;
Constant FAKE_SW_OBJ = 10008;
Constant FAKE_U_OBJ = 10009;
Constant FAKE_D_OBJ = 10010;
Constant FAKE_IN_OBJ = 10011;
Constant FAKE_OUT_OBJ = 10012;

!FRENCH
Array abbr_direction_array static table 'n//' 's//' 'e//' 'o//' 'ne' 'no' 'se' 'so' 'u//' 'd//' 0 0;
Array full_direction_array static table 'nord' 'sud' 'est' 'ouest' 'nord-est' 'nord-ouest' 'sud-est' 'sud-ouest' 'monter' 'descendre' 'entrer' 'sortir';
Array direction_properties_array static table n_to s_to e_to w_to ne_to nw_to se_to sw_to u_to d_to in_to out_to;
Array direction_name_array static table "nord" "sud" "est" "ouest" "nord-est" "nord-ouest" "sud-est" "sud-ouest" "monter" "descendre" "entrer" "sortir";

#Ifdef OPTIONAL_SHIP_DIRECTIONS; !TODO
Array abbr_ship_direction_array static table 'f//' 'a//' 'sb' 'p//' 0 0 0 0 'u//' 'd//' 0 0;
Array full_ship_direction_array static table 'fore' 'aft' 'starboard' 'port' 0 0 0 0 'up' 'down' 'in' 'out';
#IfV3;
! These arrays say the position of the first and last direction which has 1, 2, 3, 4, 5 and 6+ letters respectively
Array _dir_start static -> 0  1  3  2  1 1 3;
Array _dir_end static ->   0 10 11 12 10 2 8;
#EndIf; ! V3
#IfNot; ! not OPTIONAL_SHIP_DIRECTIONS
#IfV3;
! These arrays say the position of the first and last direction which has 1, 2, 3, 4, 5 and 6+ letters respectively
Array _dir_start static -> 0  1  5 12  3 1 5;
Array _dir_end static ->   0 10 11 12 10 2 8;
#EndIf; ! V3
#EndIf; !If not OPTIONAL_SHIP_DIRECTIONS
Constant DIRECTION_COUNT = 12;

#IfNot; ! not OPTIONAL_FULL_DIRECTIONS

Constant FAKE_U_OBJ = 10005;
Constant FAKE_D_OBJ = 10006;
Constant FAKE_IN_OBJ = 10007;
Constant FAKE_OUT_OBJ = 10008;

!FRENCH
Array abbr_direction_array static table 'n//' 's//' 'e//' 'o//' 'm//' 'd//' 0 0;
Array full_direction_array static table 'nord' 'sud' 'est' 'ouest' 'monter' 'descendre' 'entrer' 'sortir';
Array direction_properties_array static table n_to s_to e_to w_to u_to d_to in_to out_to;
Array direction_name_array static table "nord" "sud" "est" "ouest" "monter" "descendre" "entrer" "sortir";

#Ifdef OPTIONAL_SHIP_DIRECTIONS; ! TODO
Array abbr_ship_direction_array static table 'f//' 'a//' 'sb' 'p//' 'u//' 'd//' 0 0;
Array full_ship_direction_array static table 'fore' 'aft' 'starboard' 'port' 'up' 'down' 'in' 'out';
#IfV3;
! These arrays say the position of the first and last direction which has 1, 2, 3, 4, 5 and 6+ letters respectively
Array _dir_start static -> 0 1 3 2 1 1 3;
Array _dir_end static ->   0 6 7 8 6 2 3;
#EndIf; ! V3
#IfNot; ! not OPTIONAL_SHIP_DIRECTIONS
#IfV3;
! These arrays say the position of the first and last direction which has 1, 2, 3, 4, 5 and 6+ letters respectively
Array _dir_start static -> 0 1 5 8 3 1 0;
Array _dir_end static ->   0 6 7 8 6 2 0;
#EndIf; ! V3
#EndIf; ! not OPTIONAL_SHIP_DIRECTIONS
Constant DIRECTION_COUNT = 8;

#EndIf; ! not OPTIONAL_FULL_DIRECTIONS

!FRENCH
#IfDef OPTIONAL_ALLOW_WRITTEN_NUMBERS;
Array LanguageNumbers static table !TODO une
    'un' 1 'deux' 2 'trois' 3 'quatre' 4 'cinq' 5
    'six' 6 'sept' 7 'huit' 8 'neuf' 9 'dix' 10
    'onze' 11 'douze' 12 'treize' 13 'quatorze' 14 'quinze' 15
    'seize' 16 'dix-sept' 17 'dix-huit' 18 'dix-neuf' 19 'vingt' 20;
#EndIf;

Constant ARTICLE_UNE    = 0;
Constant ARTICLE_UN     = 3;
Constant ARTICLE_DES    = 6;
Constant ARTICLE_DE_LA  = 9;
Constant ARTICLE_DU     = 12;
Constant ARTICLE_UNE_   = 15;
Constant ARTICLE_UN_    = 18;
Constant ARTICLE_DE_L   = 21;

Array LanguageArticles-->
   "La "  "la "  "une "   ! 0 pomme
   "Le "  "le "  "un "    ! 1 dé
   "Les " "les " "des "   ! 2 pommes
   "La "  "la "  "de la " ! 3 confiture (en)
   "Le "  "le "  "du "    ! 4 sucre     (en)
   "L'"   "l'"   "une "   ! 5 orange
   "L'"   "l'"   "un "    ! 6 œuf
   "L'"   "l'"   "de l'"  ! 7 eau
!   ""     ""     ""      ! 8 Julia
;!End_Array

Array StorageForShortName buffer 12; !Warning, valeur à ne pas dépasser

[ LanguageContraction text; ! ï ÿ Ÿ æ Æ è È
   if (text->0 == 
         'a' or 'e' or 'h' or 'i' or 'o' or 'u' or
         'â' or 'é' or 'ê' or 'î' or 'ô' or 'œ' or 
         'A' or 'E' or 'H' or 'I' or 'O' or 'U' or
         'Â' or 'É' or 'Ê' or 'Î' or 'Ô' or 'Œ')
      rtrue;
   rfalse;
];

#IfV5; 
! From library 6.12
[ LTI_Insert i ch  b y; !WARNING vérifier pour v3

    ! Protect us from strict mode, as this isn't an array in quite the
    ! sense it expects
    b = buffer;

    ! Insert character ch into buffer at point i.
    ! Being careful not to let the buffer possibly overflow:
    y = b->1;
    if (y > b->0) y = b->0;

    ! Move the subsequent text along one character:
    for (y=y+2 : y>i : y--) b->y = b->(y-1);
    b->i = ch;
    ! And the text is now one character longer:
    if (b->1 < b->0) (b->1)++;
];
#Endif;

! Header constants
Constant HDR_DICTIONARY      = $8;   ! Actual address
Constant HDR_STATIC_MEM      = $e;   ! Actual address

Constant TT_OBJECT           = 1;    ! one or more words referring to an object
                                     ! it is one of NOUN_TOKEN etc. below
Constant TT_PREPOSITION      = 2;    ! e.g. 'into'
Constant TT_ROUTINE_FILTER   = 3;    ! e.g. noun=CagedCreature
Constant TT_ATTR_FILTER      = 4;    ! e.g. edible
Constant TT_SCOPE            = 5;    ! e.g. scope=Spells
Constant TT_PARSE_ROUTINE    = 6;    ! a parse routine
Constant TT_END              = 15;   ! End of grammar line

Constant NOUN_OBJECT         = 0;    ! The elementary grammar tokens, and
Constant HELD_OBJECT         = 1;    ! the numbers compiled by Inform to
Constant MULTI_OBJECT        = 2;    ! encode them
Constant MULTIHELD_OBJECT    = 3;
Constant MULTIEXCEPT_OBJECT  = 4;
Constant MULTIINSIDE_OBJECT  = 5;
Constant CREATURE_OBJECT     = 6;
Constant SPECIAL_OBJECT      = 7;
Constant NUMBER_OBJECT       = 8;
Constant TOPIC_OBJECT        = 9;

Constant GPR_FAIL           = -1;   ! Return values from General Parsing
Constant GPR_PREPOSITION    = 0;    ! Routines
Constant GPR_NUMBER         = 1;
Constant GPR_MULTIPLE       = 2;
Constant GPR_REPARSE        = 10000;

Constant TOKEN_SINGLE_PREP   = $42; ! 66
Constant TOKEN_FIRST_PREP    = $62; ! 98
Constant TOKEN_MIDDLE_PREP   = $72; ! 114
Constant TOKEN_LAST_PREP     = $52; ! 82

Constant GS_QUIT             = -1;
Constant GS_PLAYING          = 0;
Constant GS_DEAD             = 1;
Constant GS_WIN              = 2;
Constant GS_DEATHMESSAGE     = 3;

Constant FORM_CDEF           = 1;
Constant FORM_DEF            = 2;
Constant FORM_INDEF          = 3;

#IfV3;
Constant DICT_BYTES_FOR_WORD = 4;
#IfNot;
Constant DICT_BYTES_FOR_WORD = 6;
Constant HDR_SCREENHCHARS    = $20;
Constant HDR_SCREENWCHARS    = $21;

!FRENCH
Constant MOVES__TX = " Tour : "; !TODO Tour(s) énième ?
Constant SCORE__TX = " Score : ";
Constant TIME__TX = " Heure : ";
#EndIf;

#Default Story        0;
#Default Headline     0;

Default MAX_SCORE           0;
Default AMUSING_PROVIDED    1;
Default MAX_CARRIED        32;

#IfDef INITIAL_LOCATION_VALUE;
Global location = INITIAL_LOCATION_VALUE;		! Must be the first global to show location name
#IfNot;
	#Ifdef OPTIONAL_NO_DARKNESS;
	Global location = Directions;						! Must be the first global to show location name
	#IfNot;
	Global location = thedark;						! Must be the first global to show location name
	#EndIf;
#EndIf;

Global status_field_1 = 0; ! Must be the second global to show score or hours
Global status_field_2 = 0; ! Must be the third global to show turns or minutes
Global real_location;
Global score;
Global notify_mode = true;          ! Score notification
#Ifndef sys_statusline_flag;
Global sys_statusline_flag = 0;     ! non-zero if status line displays time
#Endif;
Global turns;                       ! Number of turns of play so far
Global the_time = NULL;             ! Current time (in minutes since midnight)
Global time_rate = 1;               ! How often time is updated
Global time_step;                   ! By how much
Global lookmode = 1;
Global player;
Global actor;
Global wn;               ! word number within parse
Global num_words;        ! number of words typed
Global action;           ! the current action
Global action_reverse;   ! if parameters are in reversed order
Global meta;             ! if the verb has the meta attribute or not
Global verb_word;        ! verb word, eg 'take' in "take all"
Global verb_wordnum;     ! the position of the verb in the current sentence
Global consult_from;     ! Word that a "consult" topic starts on
Global consult_words;    ! ...and number of words in topic
Global num_words_parsed; ! Number of words successfully parsed
Global special_word;     ! Dictionary address for "special" token
Global special_number;   ! Number typed special orders, e.g "john, 34"
Global parsed_number;    ! For user-supplied parsing routines
Global noun_filter;      ! For noun filtering by user routines
Global noun;
Global second;
Global selected_direction;
Global selected_direction_index;
Global inp1;             ! the same as noun, except when noun is a number
Global inp2;             ! the same as second, except when second is a number
Global num_noun_groups;  ! how many noun groups the current sentence contains
Global parser_action;    ! needed for parse_name, ##PluralFound (see DM)
Global parser_check_multiple;    ! parser should check if multiheld/multiinside
Global parser_unknown_noun_found;! parser should report unknown word
Global parser_all_found;! parser encountered 'all'
Global parser_all_except_object; ! used to filter all but/except patterns
Global deadflag;
Global scope_modified;   ! true if daemons, each_turn etc has invalidated scope
Global scope_objects;
Global scope_routine;    ! for scope=Routine grammar
Global scope_stage;      ! for scope=Routine grammar: 1, 2 then 3
Global keep_silent;

!FRENCH
Global le_obj =  0;
Global la_obj =  0;
Global l_obj =   0; !TODO
Global les_obj = 0;
Global lui_obj = 0;
Global leur_obj = 0;
!Global en_obj = 0;
!Global y_obj  = 0;

!Global _lui_obj = 0;
!Global elle_obj = 0;
!Global eux_obj = 0;
!Global elles_obj = 0;

Global top_object;
Global newline_flag;     ! Used by Look
Global also_flag;        ! Used by Look
Global inventory_stage;
Global phase2_necessary;
Global receive_action;

#IfV3;
Global dict_start;
Global dict_entry_size;
Global dict_end;
#IfDef DEBUG;
Global debug_flag = 0;
#EndIf;
#IfNot;
#IfDef DEBUG;
Global dict_start;
Global dict_entry_size;
Global dict_end;
Global debug_flag = 0;
#EndIf;
#EndIf;

#IfDef DEBUG_TIMER;
Global timer1 = 0;
Global timer2 = 0;
#EndIf;
#IfV5;
Global statusline_current_height = 0;
Global statusline_height     = 1;
Global statuswin_current     = false;
Global clr_on                = false;
Global clr_bg                = 2;
Global clr_fg                = 8;
Global clr_bgstatus          = 2;
Global clr_fgstatus          = 8;
#Endif;

Global visibility_ceiling;

Global normal_directions_enabled = true;
#Ifdef OPTIONAL_SHIP_DIRECTIONS;
Global ship_directions_enabled = true;
#EndIf;

Global _g_check_visible = 0;
Global _g_check_take = 0;
Global _g_item = 0;

Default MAX_WHICH_OBJECTS     10;
Default MAX_MULTIPLE_OBJECTS  32;
Default MAX_INPUT_CHARS       78;
Default MAX_INPUT_WORDS       20;
Default MAX_SCOPE             32;

Global scope_pov;        ! Whose POV the scope is from (usually the player)
Array scope-->MAX_SCOPE; ! objects visible from the current POV
Array scope_copy-->MAX_SCOPE; ! Used to hold a copy of a scope list, for iteration

Constant WORD_HIGHBIT = $8000;
#Ifndef MAX_TIMERS;
Constant MAX_TIMERS  32;            ! Max number timers/daemons active at once
#Endif; ! MAX_TIMERS
Array  the_timers --> MAX_TIMERS;
Global active_timers;               ! Number of timers/daemons active
Global current_timer;               ! Index of the timer which is currently being executed

Global PrintMsg = _PrintMsg;        ! Using a global for this saves one byte per call

#Ifndef MAX_FLOATING_OBJECTS;
Constant MAX_FLOATING_OBJECTS  32;            ! Max number of objects that have found_in property
#Endif; ! MAX_FLOATING_OBJECTS
Array floating_objects --> MAX_FLOATING_OBJECTS + 1;

Array which_object-->MAX_WHICH_OBJECTS;       ! options for "which book?"
Array which_level-->MAX_WHICH_OBJECTS;        ! type of which_object
Array multiple_objects-->MAX_MULTIPLE_OBJECTS;! holds nouns when multi* used

Array buffer->(MAX_INPUT_CHARS + 3);
Array parse->(2 + 4 * (MAX_INPUT_WORDS + 1)); ! + 1 to make room for an extra word which is set to 0

! extra arrays to be able to ask for additional info (do you mean X or Y?)
Array buffer2->(MAX_INPUT_CHARS + 3);
Array parse2->(2 + 4 * (MAX_INPUT_WORDS + 1));
Array parse3->(2 + 4 * (MAX_INPUT_WORDS + 1));

Constant RTE_MINIMUM = 0;
Constant RTE_NORMAL  = 1;
Constant RTE_VERBOSE = 2;

#IfnDef RUNTIME_ERRORS;
#IfDef DEBUG;
Constant RUNTIME_ERRORS RTE_VERBOSE;
#IfNot;
Constant RUNTIME_ERRORS RTE_NORMAL;
#EndIf;
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
Attribute scored;
Global things_score;
Global places_score;
Default OBJECT_SCORE        4;
Default ROOM_SCORE          5;

#IfDef TASKS_PROVIDED;
Default NUMBER_TASKS        1;
Array  task_done -> NUMBER_TASKS;
#Ifndef task_scores;
Array task_scores -> 1;
#Endif;
#Endif;
#Endif;

!FRENCH
Object Directions
	with
		description "Vous ne voyez rien de particulier dans cette direction.",
		short_name [;
			if(selected_direction_index)
				print (string) direction_name_array-->selected_direction_index;
			else
				print "direction";
			rtrue;
		],
#IfV5;
		parse_name [_parse _len _i _w _arr;
#IfNot;
		parse_name [_parse _len _i _w _w1 _w2;
#EndIf;
			_parse = parse+4*wn-2;
			_w = _parse-->0;
			if(_w == 'floor' or 'ground') { !TODO FIXME
#IfDef OPTIONAL_FULL_DIRECTIONS;
				selected_direction_index = 10;
#IfNot;
				selected_direction_index = 6;
#EndIf;
        		jump match2;
			}

#IfV5;
			_len = DIRECTION_COUNT;
			_arr = abbr_direction_array + 2;
			if(normal_directions_enabled) {
				@scan_table _w _arr _len -> _i ?success;
				! not found, try full
				_arr = full_direction_array + 2;
				@scan_table _w _arr _len -> _i ?success;
			}
#IfDef OPTIONAL_SHIP_DIRECTIONS;
			if(ship_directions_enabled) {
				! not found, try abbreviated ship directions
				_arr = abbr_ship_direction_array + 2;
				@scan_table _w _arr _len -> _i ?success;
				! not found, try full ship directions
				_arr = full_ship_direction_array + 2;
				@scan_table _w _arr _len -> _i ?success;
			}
#EndIf;
			! no match
			selected_direction_index = 0;
			selected_direction = 0;
			return 0;
.success;
			selected_direction_index = _i - _arr + 2;
			@log_shift selected_direction_index (-1) -> selected_direction_index; ! Divide by 2
.match2;
			selected_direction = direction_properties_array --> selected_direction_index;
			return 1;
#IfNot;
			_w1 = _parse->2; ! length of typed word
			if(_w1 > 6)
				_w1 = 6;
			_i = _dir_start->_w1;
			if(_i > 0) {
				_len = _dir_end->_w1;
!				print "Testing from ", _i, " to ", _len, "^";
!				for(_i = 1 : _i <= _len : _i++) {
.checkNextDir;
				if(normal_directions_enabled) {
					@loadw abbr_direction_array _i -> _w1;
					@loadw full_direction_array _i -> _w2;
					@je _w _w1 _w2 ?match;
				}
#IfDef OPTIONAL_SHIP_DIRECTIONS;
				if(ship_directions_enabled) {
					@loadw abbr_ship_direction_array _i -> _w1;
					@loadw full_ship_direction_array _i -> _w2;
					@je _w _w1 _w2 ?match;
				}
#EndIf;
				@inc_chk _i _len ?~checkNextDir;
                jump fail;
.match;
    			selected_direction_index = _i;
.match2;
    			selected_direction = direction_properties_array --> selected_direction_index;
    			return 1;
			}
.fail;
      		! failure
			selected_direction_index = 0;
			selected_direction = 0;
			return 0;
#EndIf;
		]
has scenery proper;
