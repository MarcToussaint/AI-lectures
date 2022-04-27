for input in ./e*.tex
do
echo '-----------------------------------'
    echo 'compiling' ${input}
    pdflatex -interaction=nonstopmode ${input} > /dev/null
    grep "Missing" ${input%.*}.log
    grep -A2 "Undefined control sequence" ${input%.*}.log
    grep -A2 "Error" ${input%.*}.log
done

input='paper.tex'
echo '-----------------------------------'
echo 'compiling' ${input}
pdflatex -interaction=nonstopmode ${input} > /dev/null
makeindex ${input%.*}.idx 2> /dev/null
bibtex ${input%.*} > /dev/null
pdflatex -interaction=nonstopmode ${input} > /dev/null
grep "Missing" ${input%.*}.log
grep -A2 "Undefined control sequence" ${input%.*}.log
grep -A2 "Error" ${input%.*}.log
