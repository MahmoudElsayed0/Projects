#include <stdio.h>
#include <omp.h>
int main() {

    char str[8000000];                                         // Declaring an array of specified number of characters

    int i = 0;
    char j = 97;

    for (i = 0; i < 8000000; i++) {                            // This for loop is responsible for generating an array of letters "a - z" with ascii codes
        str[i] = j;

        j++;

        if (j > 122) {                                         // ascii codes of "a - z" ==> 97 - 122
            j = 97;
        }
    }

    char first = 'a';
    char second = 's';

    int count_first = 0;
    int count_second = 0;

    omp_set_num_threads(4);                                    // Sets the required number of threads

    double start = omp_get_wtime();                            // Returns the start time of the parallel execution

    //Starting the parallel block execution
    #pragma omp parallel
    {
        //This line tells the compiler to distribute the for iterations on the available threads,
        // it takes a variable as argument, this variable is copied to the available threads with
        // initialization of zero, after the execution finishes, the copied variables are summed
        // and return as a single variable again
        #pragma omp for reduction(+:count_first)
        for (i = 0; i < 8000000; i++) {
            if (str[i] == first) {
                count_first += 1;
            }
        }

        #pragma omp for reduction(+:count_second)
        for (i = 0; i < 8000000; i++) {
            if (str[i] == second) {
                count_second += 1;
            }
        }
    }

    double end = omp_get_wtime();                                                           // This is the end time

    double exec_time = end - start;                                                         // calculating the time of execution

    printf("a = %d and s = %d in %f \n", count_first, count_second, exec_time);             // Printing the occurrences of the two characters and the time of the execution
}

