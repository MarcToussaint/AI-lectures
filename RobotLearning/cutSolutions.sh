for input in ./e*.tex
do
    sed -i '/begin{solution}/,/end{solution}/d' ${input}
done
