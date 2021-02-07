! ==============================================================================
! Lionel Ange, 2008-2021
! Version 1.0.0
! Licence Creative Commons BY-SA 4.0 (CC BY-SA 4.0) 
! https://creativecommons.org/licenses/by-sa/4.0/
! ==============================================================================
! Source encoding UTF-8 No Mark
System_file;
!FRENCH

[ PosMot motn; return parse->(motn*4+1); ];  ! WordAddress-buffer
[ DicMot motn; return parse-->(motn*2-1); ]; ! WordValue

#Ifv5;
! To protect against a bug in early versions of the "Zip" interpreter:
[ Tokenise__ b p; b->(2 + b->1) = 0; @tokenise b p; ];
#EndIf;

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

[ NbMotPhrase   motn i w;
   i = parse->1;
   for (motn = 1 : motn <= i : motn++) {
      w = DicMot(motn);
      if (w == './/' or THEN1__WD)
         break;
   }
   return (motn - 1);
];

#Ifv3;
[ DictWord at lgm   w i j len_dic;
   len_dic = (dict_end-dict_start)/dict_entry_size; !TODO Global
   if (lgm>6) lgm = 6;
   for (i=0 : i<len_dic : i++) { !WARNING si accents
      w = HDR_DICTIONARY-->0+7+7*i;
      @output_stream 3 StorageForShortName;
      print (address) w;
      @output_stream -3;
      if (lgm ~= StorageForShortName-->0) continue;
      for (j=0 : j<lgm : j++)
         if (buffer->(j+at) ~= StorageForShortName->(j+WORDSIZE)) break;
      if (j == lgm) return w;
   }
   return 0;
];

[ InsertWordParse i w   p;
   p = parse->0;
   if (p == parse->1) --p; 
   p = parse->1 * 2 + 2;

   i = i * 2;
   while (p > i) {
      parse-->p = parse-->(p-2);
      --p;
   }
   --p;
   parse-->p = w;
   if (parse->1 < parse->0) (parse->1)++;
];

[ DecolleApostrophe motn   at lgm w1 w2 v;
   at = parse->(motn*4+1);
   ++at; 
   lgm = WordLength(motn) - 2;
   if (buffer->at ~= ''') return 0;
   --at;
   if (buffer->at == 'l')      w1 = 'l^';
   else if (buffer->at == 'd') w1 = 'de';
   else if (buffer->at == 's') w1 = 'se';
   else return 0;
   at = at + 2;
   w2 = DictWord(at, lgm);
   if (w2) {
      InsertWordParse(motn+1, w2);
      parse-->(motn*2-1) = w1;
      v = motn*4;
      parse->v = 2;
      v = v + 4;
      parse->v = lgm;      
      ++v;
      parse->v = at;
   }
   else return 0;
];
#IfNot;
[ DecolleApostrophe motn   at lgm; !TODO ssi l' ou d' ?
   at = PosMot(motn);
   lgm = WordLength(motn);
   if (lgm > 1 && buffer->(at+1) == ''') {
         if (buffer->at == 's' or 'd') buffer->(at+1) = 'e';
         LTI_Insert(at+2, ' ');
   } 
   else rfalse;
];
#EndIf;
[ Translation   n i w1 w2 r;
   !r = 0;
   n = NbMotPhrase();

   for (i=1: i<=n: i++) {
      w1 = DicMot(i);     
      switch(w1) {
         0:
#Ifv3;
            r = DecolleApostrophe(i);
            if (r) n++;
#IfNot;
            r = DecolleApostrophe(i);
            if (r) {
               n++;
               Tokenise__(buffer, parse);
            }
                 
#Endif;
         'au', 'aux':
            parse-->(i*2-1) = 'a//';
            parse->(i*4) = 1;
         'du':
            parse-->(i*2-1) = 'de';

         #IfDef DE_A_JOUER;
         'de':
            if (i == n)
               parse-->(i*2-1) = 'dj';
            else {
               w2 = DicMot(i+1);
               if (w2 && (w2->#dict_par1) & 8)
                  parse-->(i*2-1) = 'dj';
            }
         #EndIf;

      }
   }
   if (n == 1) return;

   w1 = parse-->1;
   w2 = parse-->3;
   r = 1;
   switch (w1) { !y en
      'l^':   w1 = '-l^';
      'le':   w1 = '-le';
      'la':   w1 = '-la';
      'les':  w1 = '-les';
      'se', 'lui', 'leur': ;
      default: r = 0;
   }   
   if (r) {
      if (w2 == 'lui' or 'leur') {
         parse-->1 = parse-->5;
         r = parse-->2;
         parse-->2 = parse-->6;
         parse-->5 = w1;
         parse-->6 = r;
         parse-->3 = w2;
      }
      else {
         parse-->1 = parse-->3;
         r = parse-->2;
         parse-->2 = parse-->4;
         parse-->4 = r;
         parse-->3 = w1;  
      }
   }
];

