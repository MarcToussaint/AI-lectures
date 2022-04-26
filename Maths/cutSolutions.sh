for input in ./*.tex
do
    sed -i '/begin{solution}/,/end{solution}/d' ${input}
done
