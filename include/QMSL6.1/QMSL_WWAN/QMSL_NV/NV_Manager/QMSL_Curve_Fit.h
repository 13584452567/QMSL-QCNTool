/******************************************************************************
 * $File: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Curve_Fit.h $
 *
 * DESCRIPTION: QMSL_Curve_Fit
 ******************************************************************************
 *
 * Copyright (c) 2014 QUALCOMM Technologies Incorporated.
 * All rights reserved.
 * Qualcomm Confidential and Proprietary
 *
 ******************************************************************************
 *
 * $Header: //depot/HTE/QDART/QMSL6.1/QMSL_WWAN/QMSL_NV/NV_Manager/QMSL_Curve_Fit.h#1 $
 * $DateTime: 2014/10/16 15:00:54 $
 *
 */

/******************************************************************************/
/**
QuadraticEstimator

The Quadratic Estimator class is designed to accept any number of points and provide a
second order curve fitting equation of the type y = a + b.x + c.(x^2).

*******************************************************************************/
#pragma once
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
using namespace std;


class QMSL_Curve_Fit
{
public:
   QMSL_Curve_Fit(void);
   void addPoint(double x,double y);
   void addDataMap(map<double,double> XY);
   void addPointYX(double y,double x);
   double getY(double x);
   vector<double> getY(vector<double> X);
   double getFirstOrderY(double x);
   vector<double> getFirstOrderY(vector<double> X);
   void initializeParams(void);
   void printPoly(void);
   void getPoly(double &A, double &B, double &C);
   void getPoly(double &A, double &B);
   void updateCoefficients(void);
private:

   map<double, double> xy;
   map<double, double>::iterator xy_iter;
   double a,b,c; // y = a + b.x + c.(x^2)
   double firstOrder_a, firstOrder_b; // y = a + bx
   bool coefficientsUpdated;
   bool firstOrderCoefficientsUpdated;

};