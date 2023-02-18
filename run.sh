gcc -o ./out/a.out ./src/board.c ./src/flagser.c ./src/msc.c ./src/render.c ./src/main.c

if [ $# -eq 0 ]
then
    ./out/a.out
else
    ./out/a.out $1 $2 $3
fi


