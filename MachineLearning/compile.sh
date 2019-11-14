for input in ./*.tex
do
    echo '-----------------------------------'
    echo 'compiling' ${input}
    pdflatex -interaction=nonstopmode ${input} > /dev/null
    grep "Warning" ${input%.*}.log
    grep "Missing" ${input%.*}.log
    grep -A2 "Undefined control sequence" ${input%.*}.log
    grep -A2 "Error" ${input%.*}.log
done

pdflatex script.tex
makeindex script.idx

# for file in meshes/*
# do
#     cmd="meshlabserver -i $file -o ${file%.*}.ply -s cleanMeshes.mlx -om"
#     echo $cmd
#     $cmd
# done
