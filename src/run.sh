mkdir -p build
g++ -std=c++20 src/main.cpp src/Pokemon.cpp src/Skill.cpp -o build/main
./build/main