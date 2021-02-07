#
# makefile to generate an inform game from the command-line
#


#/usr/local/share/inform7/Compilers/ni

INFORMPATH1=/usr/local/share/inform7/Inform7/
INFORMPATH2=/usr/share/gnome-inform7/
INFORMPATH3=../I7_6G60/
#INFORMPATH3=../I7_6L02/                #never use this!!!

INFORMCOMPILERS1=/usr/local/share/inform7/Compilers/
INFORMCOMPILERS2=/usr/lib/gnome-inform7/gnome-inform7/
INFORMCOMPILERS3=../I7_6G60/Compilers/
#INFORMCOMPILERS3=../I7_6L02/Compilers/ #never use this!!!



INFORMPATH=$(INFORMPATH3)
INFORMCOMPILERS=$(INFORMCOMPILERS3)
GAME=institut
GAMEFULLNAME=Institut
TXTEDITOR=scite
TERP=gargoyle-free

#COMMITER=hg commit
#PUSHER=hg push
#PULLER=hg pull

COMMITER=git commit -a
PUSHER=git push
PULLER=git pull


ifdef OS
   CP = copy /y
   RM = del /Q
   FixPath = $(subst /,\,$1)
else
   ifeq ($(shell uname), Linux)
      CP = cp
      RM = rm -f
      FixPath = $1
   endif
endif


commit:
	$(COMMITER)

push:
	$(PUSHER)

pull:
	$(PULLER)

all:
	make z8
	make glulx


jeu:
	make all

game:
	make all

release:
	make all


z8:
	make zdebug

	
z8release:
	$(INFORMCOMPILERS)/ni -noindex \
	-rules $(INFORMPATH)/Extensions -extension=z8 -package $(GAME).inform
	# -kw~S~Dv8
	$(INFORMCOMPILERS)/inform-6.32-biplatform -wxE2~S~Dv8 $(GAME).inform/Build/auto.inf $(GAME).z8
	$(CP) $(call FixPath,$(GAME).z8 $(GAME).inform/Build/output.z8)
	#
	$(INFORMCOMPILERS)/cBlorb \
	-unix $(GAME).inform/Release.blurb $(GAME).z8
	$(RM) -fr gameinfo.dbg
	- $(CP) $(GAME).z8 "$(GAME) Materials/Release/$(GAMEFULLNAME).zblorb"
	- $(CP) -fr "$(GAME) Materials/Figures/"* "$(GAME) Materials/Release/"
	- $(CP) -fr media_src/*.ttf "$(GAME) Materials/Release/"

zdebug:
	$(INFORMCOMPILERS)/ni \
	-rules $(INFORMPATH)/Extensions -extension=z8 -package $(GAME).inform
	#
	$(INFORMCOMPILERS)/inform-6.32-biplatform \
	-wxE2kSDv8 $(GAME).inform/Build/auto.inf $(GAME).z8
	#
	rm -fr gameinfo.dbg

glulx:
	$(INFORMCOMPILERS)/ni -noindex \
	-rules $(INFORMPATH)/Extensions -extension=ulx -package $(GAME).inform -release
	#
	$(INFORMCOMPILERS)/inform-6.32-biplatform \
	-wxE2~S~DG $(GAME).inform/Build/auto.inf $(GAME).inform/Build/output.ulx
	#
	$(INFORMCOMPILERS)/cBlorb \
	-unix $(GAME).inform/Release.blurb $(GAME).gblorb

gdebug:
	$(INFORMCOMPILERS)/ni -noindex \
	-rules $(INFORMPATH)/Extensions -extension=ulx -package $(GAME).inform -release
	#
	$(INFORMCOMPILERS)/inform-6.32-biplatform \
	-wxE2SDG $(GAME).inform/Build/auto.inf $(GAME).inform/Build/output.ulx
	#
	$(INFORMCOMPILERS)/cBlorb \
	-unix $(GAME).inform/Release.blurb $(GAME).gblorb

edit:
	$(TXTEDITOR) $(GAME).inform/Source/story.ni

play:
	$(TERP) $(GAME).z8


playglulx:
	$(TERP) $(GAME).gblorb


playweb:
	chromium-browser "$(GAME) Materials/Release/play.html"


run:
	make play

deploy:
	echo "We install the required extensions and templates in ~/Inform"
	-cp -fr Extensions/* ~/Inform/Extensions/
	-cp -fr Templates/* ~/Inform/Templates/



git_ignore:
	git update-index --assume-unchanged
