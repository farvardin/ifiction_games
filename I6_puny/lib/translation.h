! ==============================================================================
! Lionel Ange, 2008-2021
! Version 1.0.0
! Licence Creative Commons BY-SA 4.0 (CC BY-SA 4.0) 
! https://creativecommons.org/licenses/by-sa/4.0/
! ==============================================================================
! Source encoding UTF-8 No Mark
System_file;
!FRENCH

! From library 6.12
! To protect against a bug in early versions of the "Zip" interpreter:
[ Tokenise__ b p; b->(2 + b->1) = 0; @tokenise b p; ];

[ PrintToBuffer str;
   @output_stream 3 StorageForShortName;
   print (string) str;
   @output_stream -3;
   return StorageForShortName-->0; !Warning si débordement
];

[ LanguagePronom w;
   switch (w) {
      '-l^':   print "l'";
      '-le':   print "le";
      '-la':   print "la";
      '-les':  print "les";
      'lui':   print "lui";
      'leur':  print "leur";
   }
];

[ PosMot motn; return parse->(motn*4+1); ];  ! WordAddress-buffer
[ DicMot motn; return parse-->(motn*2-1); ]; ! WordValue

[ NbMotPhrase   motn i w;
   i = parse->1;
   for (motn = 1 : motn <= i : motn++) {
      w = DicMot(motn);
      if (w == './/' or THEN1__WD)
         break;
   }
   return (motn - 1);
];

[ EffaceMot motn   at lgm;
   at = PosMot(motn);
   lgm = WordLength(motn) + at;
   while (at < lgm)
      buffer->at++ = ' ';
];

[ InsertMot motn chaine   at i lgc; ! motn de 1 à NbrMotPhrase() + 1
   i = NbMotPhrase();
   if (motn > i) {
      motn = i;
      at = WordLength(motn);
   }
   at = at + PosMot(motn);
   LTI_Insert(at++, ' ');
   lgc = PrintToBuffer(chaine) + at;
   i = WORDSIZE;
   while (at < lgc)
      LTI_Insert(at++, StorageForShortName->(i++));
   LTI_Insert(at, ' ');
];

[ DecolleApostrophe motn   at lgm; !TODO ssi l' ou d' ?
   at = PosMot(motn) + 1;
   lgm = WordLength(motn);
   if (lgm > 1 && buffer->at == ''')
         LTI_Insert(++at, ' '); 
   else rfalse;
];

[ Translation   n i w1 w2 r;
   !r = 0;
   n = NbMotPhrase();
   for (i=1: i<=n: i++) {
      w1 = DicMot(i);
      if (w1 == 0) { ! WARNING si >= 9 ou 6
         r = DecolleApostrophe(i);
         if (r) {
            n++;
            Tokenise__(buffer, parse);
         }
      }
   }
   if (n == 1) return;
 
   w1 =  parse-->1;
   w2 =  parse-->3;
   r = 2;
   switch (w1) { !y en
      'se', 's^': w1 = "se"; r = 1; 
      'l^': w1 = "-l'"; r = 1;
      'le':
         switch (w2) {
            'lui':    w1 = "lui -le"; 
            'leur':   w1 = "leur -le";
            default:  w1 = "-le"; r = 1;
         }
      'la':
         switch (w2) {
            'lui':    w1 = "lui -la"; 
            'leur':   w1 = "leur -la";
            default:  w1 = "-la"; r = 1;
         }
      'les':
         switch (w2) {
            'lui':    w1 = "lui -les"; 
            'leur':   w1 = "leur -les";
            default:  w1 = "-les"; r = 1;
         }
      'lui':  w1 = "lui"; r = 1;
      'leur': w1 = "leur"; r = 1;
      default: r = 0;
   }
   
   if (r) {
      if (r == 1) {
         EffaceMot(1);
         InsertMot(3, w1);
      }
      else {
         EffaceMot(1);
         EffaceMot(2);
         InsertMot(4, w1);
      }
      Tokenise__(buffer, parse);
   }
];

