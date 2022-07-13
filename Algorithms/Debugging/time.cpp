using namespace std::chrono;
#define START auto start = high_resolution_clock::now();
#define STOP auto stop = high_resolution_clock::now(); auto span = duration_cast<milliseconds>(stop - start); cout << span.count() << endl;
