#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <thread>

void test_thread(){
    for(std::size_t i{0}; i<100; i++)
        std::printf("hilo %llu > %llu\n", std::this_thread::get_id(), i);
    std::printf("sali del hilo %llu.\n", std::this_thread::get_id());
}
void main_thread(){
    for(std::size_t i{0}; i<100; i++)
        std::printf("hilo %llu > %llu\n", std::this_thread::get_id(), i);
    std::printf("sali del hilo %llu.\n", std::this_thread::get_id());
}

int main(){
    std::thread hilo(&test_thread);

    main_thread();
    hilo.join();

    return EXIT_SUCCESS;
}