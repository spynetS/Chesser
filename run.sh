gcc -o ./out/a.out ./src/msc.c ./src/render.c ./src/main.c

if [ $# -eq 0 ]
then
    ./out/a.out
else
    ./out/a.out $1
fi


