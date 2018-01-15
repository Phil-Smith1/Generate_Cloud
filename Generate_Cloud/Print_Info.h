#pragma once

#include <iostream>

void Print_Iter_Summary ( clock_t start_iter, int iteration )
{
    clock_t end_iter = clock();
    double elapsed_time = (end_iter - start_iter) * 1000 / (double)(CLOCKS_PER_SEC);
    
    cout << "Iteration " << iteration + 1 << ":" << endl;
    cout << "  Duration: " << elapsed_time << " ms." << endl << endl;
}

void Print_Experiment_Summary ( clock_t start_experiment, int experiment_iter, int repetitions )
{
    clock_t end_experiment = clock();
    double elapsed_time = (end_experiment - start_experiment) * 1000 / (double)(CLOCKS_PER_SEC);
    double mean_iter_time = elapsed_time / (double)repetitions;
    
    cout << "Experiment "  << experiment_iter << ":" << endl;
    cout << "  Experiment duration: " << elapsed_time << " ms." << endl;
    cout << "  Mean iteration time: " << mean_iter_time << " ms." << endl << endl;
}

void Print_Summary ( clock_t start_time, int experiment_iter )
{
    clock_t end_time = clock();
    double elapsed_time = (end_time - start_time) * 1000 / (double)(CLOCKS_PER_SEC);
    double mean_experiment_time = elapsed_time / (double)experiment_iter;
    
    cout << "Summary:" << endl;
    cout << "  Code duration: " << elapsed_time << " ms." << endl;
    cout << "  Number of experiments: " << experiment_iter << "." << endl;
    cout << "  Mean experiment time: " << mean_experiment_time << " ms." << endl << endl;
}
