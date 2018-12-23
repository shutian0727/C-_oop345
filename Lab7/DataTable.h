// Workshop 7 - STL Algorithms
// DataTable.h
// Name: Shutian XU
// ID:106932171
// Date: 11/1/2018
#ifndef DATATABLE_H			
#define DATATABLE_H

#include <iostream>
#include <iomanip> 
#include <fstream>
#include <vector>
#include <cmath> 
#include <algorithm> 
#include <numeric>   

using namespace std;


namespace w7 {
	template <typename T>
	class DataTable {
	private:
		int mDec; //Number of decimals
		int mWid; //width in characters 
		vector<T> coordX; //independent value (X coordinate)
		vector<T> coordY; //dependent value (Y coordinate)

	public:
		DataTable() {
			int mWid = 0;
			int mDec = 0;
		}


		DataTable(ifstream &fs, int fwidth, int decimals) {
			this->mDec = decimals;
			this->mWid = fwidth;
			T cdX, cdY;
			while (fs.good()) { 
				fs >> cdX >> cdY;
				this->coordX.push_back(cdX);
				this->coordY.push_back(cdY);
			}
			fs.close();
		}


		T mean() const {
			T n = coordY.size();
			T sum = accumulate(coordY.begin(), coordY.end(), 0.0);
			return (sum / n);
		}

	
		T sigma() const {
			T zMean = this->mean(); 
			T dev = 0;
			int n = coordY.size();
			for (int i = 0; i < coordY.size(); i++) {
				dev += pow(coordY[i] - zMean, 2); // (value - mean)^2
			}
			dev = dev / (T)(n - 1);
			dev = sqrt(dev); // square root
			return dev;
		}

	

		T median() const {
			vector <T> lvec = this->coordY;
			std::sort(lvec.begin(), lvec.end(), [](T i, T j) { return i > j; });		
			int quant = lvec.size();
			//T median = (lvec[(quant / 2) - 1] + lvec[quant / 2]) / 2;
			T median = lvec[round(quant / 2)];
			return median;
		}


		//formula  slope = [ n ( Σixiyi ) - Σixi Σiyi ] / [ n (Σixi^2) - (Σixi)^2 ]
		//formula y_intercept = [Σiyi - slope * Σixi] / n
        	void regression(T& slope, T& y_intercept) const {
			T sumX, sumY;
			T inProdXX, inProdXY;
			int n = coordX.size();
			// for the Σixi Σiyi (Sigma) sum up of values in vector we use std::accumulate
			sumX = accumulate(coordX.begin(), coordX.end(), (T)0);
			sumY = accumulate(coordY.begin(), coordY.end(), (T)0);
			// to solve the Σixiyi and Σixi^2 part of the formula we use std::inner_product
			inProdXX = inner_product(coordX.begin(), coordX.end(), coordX.begin(), (T)0.0);
			inProdXY = inner_product(coordX.begin(), coordX.end(), coordY.begin(), (T)0.0);
			slope = ((n * inProdXY) - (sumX * sumY)) / ((n * inProdXX) - pow(sumX, 2));
			y_intercept = (sumY - (slope * sumX)) / n;
		}

		void display(std::ostream& os) const {
			os << setw(mWid) << setprecision(mDec) << fixed << 'X';
			os << setw(mWid) << 'Y' << endl;

			int size = coordX.size();
			for (int i = 0; i < size; i++) {
				os << setw(mWid) << coordX[i];
				os << setw(mWid) << coordY[i] << endl;
			}
		}
		friend ostream& operator<<(ostream& os, const DataTable& dt) {
			dt.display(os);
			return os;
		}
	}; 
}
#endif