for input in ./*.tex
do
  echo "=============== ${input}"
  cat latex-macros.inc ${input} > z.tex
  pandoc z.tex --ascii -o z.md
  cat z.md > ${input%.*}.inc
  rm z.md
  rm z.tex
done
