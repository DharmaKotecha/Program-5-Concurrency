#include <iostream>
#include <string>
#include <pthread.h>

using namespace std;

struct SearchParams {
    string text;
    string pattern;
    int result;
};

void* brute(void* arg) {
    SearchParams* params = (SearchParams*) arg;
    string text = params->text;
    string pattern = params->pattern;
    int n = text.length();
    int m = pattern.length();
    int j;
    for (int i=0; i<=(n-m); i++) {
        j = 0;
        while ((j<m)  && (text[i+j] == pattern[j])) {
            j++;
        }
        if (j == m) {
            params->result = i;
            return NULL;
        }
    }
    params->result = -1;
    return NULL;
}

int main() {
    string text = "This is a test string";
    string pattern = "test";
    SearchParams params;
    params.text = text;
    params.pattern = pattern;
    pthread_t tid;
    pthread_create(&tid, NULL, brute, (void*) &params);
    pthread_join(tid, NULL);
    int result = params.result;

    cout << "Result: " << result << endl;
    return 0;
}
