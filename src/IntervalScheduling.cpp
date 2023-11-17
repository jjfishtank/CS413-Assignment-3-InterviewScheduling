// IntervalScheduling.cpp
// Author: Jeremy Renati
// Created: 11/16/2023
// Description: Parses input.txt for jobs, sorts them, and prints the maximum subset of mutually compatible jobs.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
  int start, finish;
};

bool jobComparator(Job s1, Job s2) {
  return (s1.finish < s2.finish);
}

void printMaxJobs(vector<Job>& jobs) {
  // sort jobs by earliest finish time
  sort(jobs.begin(), jobs.end(), jobComparator);

  cout << "Maximum subset: \n";

  int curr = 0;
  int prev = 0;

  // first job
  cout << "(" << jobs[curr].start << ", " << jobs[prev].finish << ")";

  for (curr = 1; curr < jobs.size(); curr++) {
    if (jobs[curr].start >= jobs[prev].finish) { // check compatibility
      cout << ", (" << jobs[curr].start << ", " << jobs[curr].finish << ")";
      prev = curr;
    }
  }
}

int main() {
  ifstream file("input.txt"); // place input.txt in root/build directory
  if (!file) {
    cout << "Unable to open file";
    exit(1);
  }

  int n;
  file >> n;

  vector<Job> jobs(n);
  for (int i = 0; i < n; i++) {
    char comma;
    file >> jobs[i].start >> comma >> jobs[i].finish;
  }

  printMaxJobs(jobs);

  return 0;
}