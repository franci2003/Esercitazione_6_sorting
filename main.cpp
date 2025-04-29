#include <cmath> 
#include <iostream>
#include <numeric> 
#include <sstream>
#include <chrono> 

#include "SortingAlgorithm.hpp"
using namespace std;

template<typename T>
string ArrayToString(const vector<T>& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
};

struct ClassObj{
    double value;

    // bool operator< (const ClassObj& rhs) { return value < rhs.value; }
};

inline bool operator< (const ClassObj& lhs, const ClassObj& rhs) { return lhs.value < rhs.value; }


int main(int argc, char *argv[])
{
	cout << "argc: " << argc << endl; // argc numero di argomenti da riga di comando
    for(int a = 0; a < argc; a++)
		cout << argv[a] << " ";
    cout << endl;
	
	size_t m = 10;
    if(argc > 1)
    {
        istringstream convert(argv[1]);
        convert >> m;
        cout << "use value: "  << m << endl;
    }
    else
        cerr << "use default value: "  << m << endl;
	vector<int> v1(m);
    std::iota(v1.begin(), v1.end(), -4); // crea un vettore di valori a partire da -4
	
	srand(2); // imposta il seed per la generazione casuale
    vector<double> v2(m);
    for(size_t i = 0; i < m; i++)
		v2[i] = rand() / ((double)RAND_MAX); // vengono generati numeri casuali fra 0 e 1 e messi nel vettore v2
	
	vector<int> v3(m, 0); // inizializza con zeri

    for(size_t i = floor(m * 0.5) + 1; i < m; i++)
		v3[i] = rand() % 1000;

    copy(v1.begin(), v1.begin() + floor(m * 0.5) + 1, v3.begin());
	
	unsigned int num_experiment = 100;
	
	double time_elapsed_bubble_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<int> v(v1);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::BubbleSort<int>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_bubble_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
	
    time_elapsed_bubble_v1 /= num_experiment;
    cout << "Bubble Sort - v1: " << time_elapsed_bubble_v1 << endl;
	
	double time_elapsed_bubble_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<double> v(v2);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::BubbleSort<double>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_bubble_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v2 /= num_experiment;
    cout << "Bubble Sort - v2: " << time_elapsed_bubble_v2 << endl;
	
	double time_elapsed_bubble_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<int> v(v3);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::BubbleSort<int>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_bubble_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_bubble_v3 /= num_experiment;
    cout << "Bubble Sort - v3: " << time_elapsed_bubble_v3 << endl;

	
    double time_elapsed_heap_v1 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<int> v(v1);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::HeapSort<int>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_heap_v1 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v1 /= num_experiment;
    cout << "Heap Sort - v1: " << time_elapsed_heap_v1 << endl;

	double time_elapsed_heap_v2 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<double> v(v2);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::HeapSort<double>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_heap_v2 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v2 /= num_experiment;
    cout << "Heap Sort - v2: " << time_elapsed_heap_v2 << endl;
	
	double time_elapsed_heap_v3 = 0.0;
    for(unsigned int t = 0; t < num_experiment; t++)
    {
    vector<int> v(v3);
    auto start_time = std::chrono::steady_clock::now();
    SortLibrary::HeapSort<int>(v);
    auto end_time = std::chrono::steady_clock::now();
    time_elapsed_heap_v3 += std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
    time_elapsed_heap_v3 /= num_experiment;
    cout << "Heap Sort - v3: " << time_elapsed_heap_v3 << endl;


    return 0;
}
}

