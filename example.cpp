#include <vector>
#include "bench.hpp"


static BenchmarkSession gBenchmark;


int main()
{
   // Create a random huge vector
   auto CreateRandomVector = []
   {
       std::vector<double> randomValues;
       for (int i = 0; i < 500 * 1000; ++i)
           randomValues.push_back(rand() % 1000);
       return randomValues;
   };

   // Run the benchmark several times
   for (int i = 0; i < 100; ++i)
   {
       // Create a new random vector each time
       auto randomValues = CreateRandomVector();

       // Benchmark the sort function
       BENCHMARK_VOID_EXPRESSION(gBenchmark, "Sort",
       {
           std::sort(randomValues.begin(), randomValues.end());
       });
   }

   printf("Benchmark \n%s", gBenchmark.Report().c_str());
}
