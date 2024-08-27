for input in ../../notes/*.tex
do
    filename="${input##*/}"
    echo "=============== ${input} ${filename}"
    cat latex-macros.inc ${input} > z.tex
    pandoc z.tex --ascii -o z.md
    sed -i \
	-e 's/SPAN-END/<\/span>/g' \
	-e 's/SPAN-CENTER/<span style="display:block; margin-left:auto; margin-right:auto; width:70%">/g' \
	-e 's/SPAN-SMALL/<span style="display: block; font-size:0.8em;">/g' \
	z.md
    cat z.md > ${filename%.*}.inc
    rm z.md
    rm z.tex
done
