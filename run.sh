echo "Compiling******************"
gcc ./main.cpp -lstdc++ -o a
echo "RUNNING *********************"
valgrind --leak-check=full ./a
