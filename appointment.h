#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QMessageBox>
#include <QString>
#include <QPair>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <QVector>
#include "sqllitedelegate.h"
#include "user.h"
#include "QWidgetItem"
#include "qlineedit.h"
#include <QPoint>
#include <QMenu>

class Appointment
{
public:
    Appointment();
    //                            Setters
    void setVacancy(int v) { vacancy = v; }
    void setCandidates(int c) { candidates = c; }
    void setSolution(int s){solution = s;}
    //                            Getters
    int getVacancy() { return vacancy; }
    int getCandidates()  { return candidates; }
    int getSolution()  { return solution; }

    int getFirstItem(int i) { return rightItem[i].first; }
    int getSecondItem(int i) { return rightItem[i].second; }
    //                            Internal methods
    void setItem(int i, int j, int item) {matrix[i][j] = item;}
    void makeSolution();
    void getItemsForSolution();

protected:
    int matrix[10][10];
    int vacancy;
    int candidates;
    int solution;

    QVector <QPair<int, int>> rightItem;
};

#endif // APPOINTMENT_H
