echo '-----------------------------------'
echo 'compiling paper'
pdflatex -interaction=nonstopmode paper.tex > /dev/null
makeindex paper.idx
bibtex paper
pdflatex -interaction=nonstopmode paper.tex > /dev/null
