for input in ../../notes/*.tex
do
    filename="${input##*/}"
    echo "=============== ${input} ${filename}"
    cat latex-macros.inc ${input} > z.tex
    pandoc z.tex --ascii -o z.md
    cat z.md > ${filename%.*}.inc
    rm z.md
    rm z.tex
done
