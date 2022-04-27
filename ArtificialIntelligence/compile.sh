for input in ./*.tex
do
    echo '-----------------------------------'
    echo 'compiling' ${input}
    pdflatex -interaction=nonstopmode ${input} > /dev/null
    grep "Missing" ${input%.*}.log
    grep "Undefined control sequence" ${input%.*}.log
    grep "Error" ${input%.*}.log
done

input='script.tex'
echo '-----------------------------------'
echo 'compiling' ${input}
makeindex ${input%.*}.idx 2> /dev/null
bibtex ${input%.*} > /dev/null
pdflatex -interaction=nonstopmode ${input} > /dev/null
grep "Missing" ${input%.*}.log
grep "Undefined control sequence" ${input%.*}.log
grep "Error" ${input%.*}.log
