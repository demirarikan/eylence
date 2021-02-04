/**
 * @file circle.cpp
 * @brief Monte-Carlo-Simulation for approximating the pi
 *
 *
 *
 */

// for random value generation
#include<ctime>
#include<cstdlib>
#include<limits.h>
#include<iostream>
#include <ostream>


int main() {

    // seed the random variable generator for better entropy
    srand(static_cast <unsigned> (time(0)));

    float sample = 0.f;

    // samples for entropy test
    for(int i = 1; i <= 1000000; i++) {

        // for the first two sample we need different output for ultimate coolness
        if(i < 3) {

            // here we create random numbers in range 0-100 and of course they are floating point numbers boiiii
            float current_sample = 0.f + static_cast <float> (rand()) / (static_cast <float> ( (float) RAND_MAX / (100.f - 0.f)));

            // add to the sample
            sample += current_sample;

            if(i == 1) {
                std::cout << "Starting Sampling\n"
                          << "approx-sample: " << current_sample
                          << "\t number of samples: " << i << std::flush;
            }

            else {
                // normalize the result
                sample = sample / (float) 2;

                // override the last line so we don't abuse the stdout..
                std::cout << "\r"
                          << "approx-sample: " << sample
                          << "\t number of samples: " << i << std::flush;
            }

        }

        // here we create random numbers in range 0-100 and of course they are floating point numbers boiiii
        float current_sample = 0.f + static_cast <float> (rand()) / (static_cast <float> ( (float) RAND_MAX / (100.f - 0.f)));

        // add the random variable and normalize the result
        sample = ((sample * (i-1)) + current_sample) / ((float) i);

        // override the last line so we don't abuse the stdout..
        std::cout << "\r"
                  << "approx-sample: " << sample
                  << "\t number of samples: " << i << std::flush;

    }

    std::cout << "\nSampling finished.. if sample is around 50, then your entropy is high\n";

}

