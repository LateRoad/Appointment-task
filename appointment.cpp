#include "appointment.h"

//
//                                                          Constructor, destructor of ProgramWindow
//

Appointment::Appointment()
{
    candidates = 2;
    vacancy = 2;
}

//
//                                                          Internal methods
//

void Appointment::makeSolution()
{
    int work[10];
    for (int i = 0; i < vacancy; i++)
        work[i] = i;

    int minSum = INT_MAX;
    do {
        int sum = 0;
        for (int worker = 0; worker < vacancy; worker++)
            sum += matrix[worker][work[worker]];
        minSum = std::min(minSum, sum);
    } while (std::next_permutation(work, work + vacancy));
   solution = minSum;
}

void Appointment::getItemsForSolution()
{

}

