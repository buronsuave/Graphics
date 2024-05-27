if [[ ! -e .out ]]; then
    mkdir .out
fi

g++ -c main.cpp -o .out/main.o
g++ -c flyeye.cpp -o .out/flyeye.o
g++ .out/main.o .out/flyeye.o -o .out/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
.out/sfml-app