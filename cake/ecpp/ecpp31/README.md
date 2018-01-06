// 如果impl类有修改  只需要重编译imple类即可
g++ -c ecpp31_impl.cc ecpp31_interface.cc; g++ -o main main.cc *.o
