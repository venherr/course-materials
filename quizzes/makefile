# -----------------------------------------------------------------------------
# Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
# Released under the [MIT License] (http://opensource.org/licenses/MIT)
# -----------------------------------------------------------------------------

TEX := $(wildcard *.tex)
TEX := $(filter-out %.part.tex,$(TEX))
TEX := $(filter-out $(wildcard *.gen.*),$(TEX))
TEX := $(TEX:%.tex=.%.gen.questions.tex) $(TEX:%.tex=.%.gen.answers.tex)
PDF := $(TEX:.%.tex=%.pdf)

# -----------------------------------------------------------------------------
.PHONY: all clean cleanall

all: $(PDF)

clean:
	for i in `find ./code/ -type d`; do \
		( cd $$i; make clean; ); \
	done; \
	#
	-latexmk --shell-escape -lualatex -pdf -c *.tex
	-rm -r *.fls .minted-*

cleanall: clean
	for i in `find ./code/ -type d`; do \
		( cd $$i; make cleanall; ); \
	done; \
	#
	-latexmk --shell-escape -lualatex -pdf -C *.tex
	-rm -r .*.gen.* *.gen.*

# -----------------------------------------------------------------------------
.PHONY: view-standards

list-standards:
	@grep --color -r ' \\standard{' *

# -----------------------------------------------------------------------------
.SECONDARY: $(TEX) $(TEX:%.tex=%.pdf)

%.pdf: .%.pdf
	cp '$<' '$@'

.%.gen.questions.tex: %.tex makefile
	( echo '\\long\\def \\question #1{#1}'; \
	  echo '\\long\\def \\answer #1{}'; \
	  echo '\\input{$<}'; \
	  echo; \
	) > '$@'

.%.gen.answers.tex: %.tex makefile
	( echo '\\long\\def \\question #1{}'; \
	  echo '\\long\\def \\answer #1{#1}'; \
	  echo '\\input{$<}'; \
	  echo; \
	) > '$@'

# -----------------------------------------------------------------------------

%.pdf: %.tex document-setup.part.tex ./scripts/functions.lua
	i="`lua -e 'require("./scripts/functions"); print(jobname_root("$@"))'`"; \
	if [ -d "./code/$$i/" ]; then (cd "./code/$$i/"; make;); fi; \
	#
	latexmk --shell-escape -lualatex -pdf '$<'
	touch '$@'  # for when latexmk does nothing

