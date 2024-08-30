for input in ../../notes/*.tex
do
    filename="${input##*/}"
    echo "=============== ${input} ${filename}"
    cat latex-macros.inc ${input} > z.tex
    sed -i \
	-e 's/^\\begin{align}/\n$$\\begin{align}/' \
	-e 's/^\\end{align}$/\\end{align}$$\n/' \
	-e 's/\\eqref{\([^}]*\)}/$\\eqref{\1}$/g' \
	z.tex
    pandoc z.tex --ascii -o z.md
    sed -i \
	-e 's/SPAN-END/<\/span>/g' \
	-e 's/SPAN-CENTER/<span style="display:block; margin-left:auto; margin-right:auto; width:70%">/g' \
	-e 's/SPAN-SMALL/<span style="display: block; font-size:0.8em;">/g' \
	-e 's/HREF-START\(.*\)HREF-MID`\(.*\)`HREF-END/[\1](\2)/' \
	z.md
    cat z.md > ${filename%.*}.inc
    rm z.md
    rm z.tex
done
