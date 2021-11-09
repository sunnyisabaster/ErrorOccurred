#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <string>
#include <vector>


//#include "NoBed_smooth_80kV_1.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_80kV_1.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_80kV_2.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_80kV_2.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_80kV_3.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_100kV_1.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_100kV_1.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_100kV_2.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_100kV_2.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_100kV_3.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_120kV_1.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_120kV_1.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_120kV_2.0mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_120kV_2.5mAs_Focus-S_PGA6_Binning2.h"
//#include "NoBed_smooth_120kV_3.0mAs_Focus-S_PGA6_Binning2.h"
#include "data.h"


using namespace std;


//float chooseDiffKv(float kv, float mA) {
//	if (kv == 80.0 and mA == 1.0) {
//
//		Catphan_Focus_S_PGA6_Binning2_80_1* k_val = new Catphan_Focus_S_PGA6_Binning2_80_1();
//		float* K = k_val->get_kval();
//		double* dis = k_val->get_dis();
//		float* ct_vals_arr = k_val->get_ct_val();
//		float* hu_vals_arr = k_val->get_Hu_val();
//		int indexLength = k_val->get_indexLength();
//
//		return K;
//	}
//}

void split(const string& s, vector<string>& sv, const char* delim = " ") {
	sv.clear();                                 // 1.
	char* buffer = new char[s.size() + 1];      // 2.
	char* next_token = NULL;
	buffer[s.size()] = '\0';
	copy(s.begin(), s.end(), buffer);      // 3.
	char* p = strtok_s(buffer, delim, &next_token);       // 4.
	do {
		sv.push_back(p);                        // 5.
	} while ((p = strtok_s(NULL, delim, &next_token)));   // 6.
	delete[] buffer;
	return;
}

int main(int argc, char* argv[])
{

	if (argc != 11) {
		cout<< "Opps, there is an error occured" << endl;
	}



	float Hu_val = 0;
	//int c = 0, i = 0;
	double totaltime = 0;
	float pixel_vals[] = {0};
	const int pixel_num_x = std::stof(argv[3]);  //1024
	const int pixel_num_y = std::stof(argv[4]);  //1024
	const int num_of_slices = std::stof(argv[5]);//200
	const float spacing_x = std::stof(argv[6]);
	const float spacing_y = std::stof(argv[7]);
	const float spacing_z = std::stof(argv[8]);
	const float kv = std::stof(argv[9]);
	const float mA = std::stof(argv[10]);

 	int pixel_num = pixel_num_x * pixel_num_y * num_of_slices;
	int size = sizeof(short int) * pixel_num;
	float processed_val;
	int real_index;
	float* adjust_v = new float[1024*1024];

	
	int standard_val = 5;
	float slope_arr[4];
	float intercept_arr[4];

	cout << "short int size is " << sizeof(short int) << endl;
	cout << "size is " << size << endl;   
	cout << "Pixel number x" << ": " << pixel_num_x << endl;
	cout << "Pixel number y" << ": " << pixel_num_y << endl;
	cout << "Num of slices" << ": " << num_of_slices << endl;
	cout << "spacing x" << ": " << spacing_x << endl;
	cout << "spacing y" << ": " << spacing_y << endl;
	cout << "spacing z" << ": " << spacing_z << endl;
	cout << "kv" << ": " << kv << endl;
	cout << "mAs" << ": " << mA << endl;

	float* pixel_fromFile = new float[pixel_num];
	short int* converted_hu_val = new short[pixel_num];
	
	clock_t finish;
	clock_t start = 0;

	float* K = nullptr;
	double* dis = nullptr;
	float* ct_vals_arr = nullptr;
	float* hu_vals_arr = nullptr;
	int indexLength = 0;

	if (kv == 70.0 and mA == 1.0) {

		Catphan_Focus_S_PGA6_Binning2_70_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_70_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 70.0 and mA == 1.5) {

		Catphan_Focus_S_PGA6_Binning2_70_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_70_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 70.0 and mA == 2.0) {

		Catphan_Focus_S_PGA6_Binning2_70_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_70_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 70.0 and mA == 2.5) {

		Catphan_Focus_S_PGA6_Binning2_70_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_70_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 70.0 and mA == 3.0) {

		Catphan_Focus_S_PGA6_Binning2_70_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_70_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 80.0 and mA == 1.0) {

		Catphan_Focus_S_PGA6_Binning2_80_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_80_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 80.0 and mA == 1.5) {
		
		Catphan_Focus_S_PGA6_Binning2_80_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_80_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 80.0 and mA == 2.0) {
		
		Catphan_Focus_S_PGA6_Binning2_80_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_80_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 80.0 and mA == 2.5) {
		
		Catphan_Focus_S_PGA6_Binning2_80_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_80_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 80.0 and mA == 3.0) {
		
		Catphan_Focus_S_PGA6_Binning2_80_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_80_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 90.0 and mA == 1.0) {

		Catphan_Focus_S_PGA6_Binning2_90_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_90_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 90.0 and mA == 1.5) {

		Catphan_Focus_S_PGA6_Binning2_90_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_90_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 90.0 and mA == 2.0) {

		Catphan_Focus_S_PGA6_Binning2_90_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_90_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 90.0 and mA == 2.5) {

		Catphan_Focus_S_PGA6_Binning2_90_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_90_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 90.0 and mA == 3.0) {

		Catphan_Focus_S_PGA6_Binning2_90_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_90_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 100.0 and mA == 1.0) {
		
		Catphan_Focus_S_PGA6_Binning2_100_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_100_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 100.0 and mA == 1.5) {

		Catphan_Focus_S_PGA6_Binning2_100_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_100_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 100.0 and mA == 2.0) {

		Catphan_Focus_S_PGA6_Binning2_100_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_100_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 100.0 and mA == 2.5) {

		Catphan_Focus_S_PGA6_Binning2_100_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_100_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 100.0 and mA == 3.0) {

		Catphan_Focus_S_PGA6_Binning2_100_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_100_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 110.0 and mA == 1.0) {

		Catphan_Focus_S_PGA6_Binning2_110_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_110_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 110.0 and mA == 1.5) {

		Catphan_Focus_S_PGA6_Binning2_110_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_110_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 110.0 and mA == 2.0) {

		Catphan_Focus_S_PGA6_Binning2_110_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_110_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 110.0 and mA == 2.5) {

		Catphan_Focus_S_PGA6_Binning2_110_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_110_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 110.0 and mA == 3.0) {

		Catphan_Focus_S_PGA6_Binning2_110_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_110_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 120.0 and mA == 1.0) {

		Catphan_Focus_S_PGA6_Binning2_120_1_0* k_val = new Catphan_Focus_S_PGA6_Binning2_120_1_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 120.0 and mA == 1.5) {

		Catphan_Focus_S_PGA6_Binning2_120_1_5* k_val = new Catphan_Focus_S_PGA6_Binning2_120_1_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 120.0 and mA == 2.0) {

		Catphan_Focus_S_PGA6_Binning2_120_2_0* k_val = new Catphan_Focus_S_PGA6_Binning2_120_2_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 120.0 and mA == 2.5) {

		Catphan_Focus_S_PGA6_Binning2_120_2_5* k_val = new Catphan_Focus_S_PGA6_Binning2_120_2_5();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else if (kv == 120.0 and mA == 3.0) {

		Catphan_Focus_S_PGA6_Binning2_120_3_0* k_val = new Catphan_Focus_S_PGA6_Binning2_120_3_0();
		K = k_val->get_kval();
		dis = k_val->get_dis();
		ct_vals_arr = k_val->get_ct_val();
		hu_vals_arr = k_val->get_Hu_val();
		indexLength = k_val->get_indexLength();
	}
	else {
	
		cout << "We don't have this KV and mAs' data." << endl;
		return -1; 
	}


	////Catphan_Focus_S_PGA6_Binning2* k_val = new Catphan_Focus_S_PGA6_Binning2();
	//float* K = k_val->get_kval();
	//double* dis = k_val->get_dis();  
	//float* ct_vals_arr = k_val->get_ct_val();
	//float* hu_vals_arr = k_val->get_Hu_val();
	//int indexLength = k_val->get_indexLength();

	for (unsigned __int64 i = 0; i < standard_val; i++) {

		float slope = (hu_vals_arr[i] - hu_vals_arr[i + 1]) / (ct_vals_arr[i] - ct_vals_arr[i + 1]);

		float intecept = hu_vals_arr[i] - (hu_vals_arr[i] - hu_vals_arr[i + 1]) / (ct_vals_arr[i] - ct_vals_arr[i + 1]) * ct_vals_arr[i];

		//cout << ct_vals_arr[i] << endl;
		//cout << hu_vals_arr[i] << endl;

		slope_arr[i] = slope;

		intercept_arr[i] = intecept;


	};
	
	if (pixel_vals[0] == 0) {
		/*
		 *	push in the raw file
		 */
		//ifstream rawIn("F:\\均整度\\catphan_80kV_3.0mAs_Focus-S_PGA6_Binning2.raw", ios::in | ios::binary);
		ifstream rawIn(argv[1], ios::in | ios::binary);
		if (!rawIn) {
			cout << "Cannot find file" << endl;
		}
		rawIn.read((char*)pixel_fromFile, sizeof(float) * pixel_num);
		rawIn.close();
	}
	else {
		pixel_fromFile = pixel_vals;
	}

	const float shift_x = pixel_num_x / 2.0;
	const float shift_y = pixel_num_y / 2.0;
	for (int k = 0; k < num_of_slices; k++) {
		for (int j = 0; j < pixel_num_y; j++) {
			for (int i = 0; i < pixel_num_x; i++) {
				int n = (k * pixel_num_x * pixel_num_y + j * pixel_num_x + i);
				float d = sqrt(spacing_x * spacing_x * (i - shift_x) * (i - shift_x) + \
					           spacing_y * spacing_y * (j - shift_y) * (j - shift_y));
				float e = d / spacing_x;

				if(d <= 110){

					int lower = lower_bound(dis, dis + indexLength, d) - dis;
					int upper = lower + 1;

					int index = round(indexLength - lower);

					processed_val = pixel_fromFile[n] * K[index];

					/*if (processed_val > 50) {
						printf("%f %f %f \n", processed_val, pixel_fromFile[n], K[index]);
					}*/

					
					if (processed_val < ct_vals_arr[0]) {


						//Hu_val = -1000;
						Hu_val = slope_arr[0] * processed_val + intercept_arr[0];
						//Hu_val = 0;
					}
					else if (processed_val >= ct_vals_arr[0] and processed_val < ct_vals_arr[1]) {

						Hu_val = slope_arr[0] * processed_val + intercept_arr[0];
						//Hu_val =  processed_val - 90;

					}
					else if (processed_val >= ct_vals_arr[1] and processed_val < ct_vals_arr[2]) {

						Hu_val = slope_arr[1] * processed_val + intercept_arr[1];

						//Hu_val = pixel_fromFile[n] - 90;

					}
					else if (processed_val >= ct_vals_arr[2] and processed_val < ct_vals_arr[3]) {

						Hu_val = slope_arr[2] * processed_val + intercept_arr[2];
						//Hu_val = 1 * pixel_fromFile[n] - 42.4;
					}
					else if (processed_val >= ct_vals_arr[3] and processed_val < ct_vals_arr[4]) {

						//80kv 需要这个
						//Hu_val = slope_arr[3] * processed_val + intercept_arr[3] - 20;
						Hu_val = slope_arr[3] * processed_val + intercept_arr[3];

					}
					else {//if (processed_val >= ct_vals_arr[4])

						Hu_val = slope_arr[3] * processed_val + intercept_arr[3] - 20;

					}

					//else {//if (processed_val >= ct_vals_arr[4])

					//	Hu_val = 1000; // slope_arr[3] * processed_val + intercept_arr[3];

					//}


					
					const auto value = static_cast<short>(round(Hu_val));

					converted_hu_val[n] = max<short>(value, -1030);
					
					if (d <= 1) {
						//去除中间的黑线
						if (converted_hu_val[n] <= -1030) {
							converted_hu_val[n] = (converted_hu_val[n - 3] + converted_hu_val[n - 4]) / 2;
						}
					}
					
				}
				
				else {
					converted_hu_val[n] = -1030;
				}
			}
		}
		//cout << k << endl;
	}
	ofstream outFile(argv[2], ios::out | ios::binary | ios::trunc);
	outFile.write((char*)converted_hu_val, size);
	 
	finish = clock();
	totaltime = (float)(finish - start) / CLOCKS_PER_SEC;
	cout << "Costed " << totaltime << " s" << endl;

	outFile.close();
	delete[] converted_hu_val, pixel_fromFile;
}

//F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\smooth_raw_data_test_80kV.raw F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct.raw F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\smooth_raw_data_test_80kV.raw F:\均整度\new_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\smooth_raw_data_test_80kV_HU.raw 1024 1024 300 0.25 0.25 1 C:\Users\admin\Desktop\Desktop\file\ct2hu_reranked_80KV_1mA.csv

//F:\均整度\new_data\Standard_Raw_file\tt.raw F:\均整度\new_data\Standard_Raw_file\tt_HU.raw 512 512 100 0.5 0.5 2.5 C:\Users\admin\Desktop\Desktop\file\ct2hu_reranked_80KV_1mA.csv

 //F:\均整度\Filtered_data\Catphan_80kV_2.0mAs_Focus-S_PGA6_Binning2\ct.raw F:\均整度\Filtered_data\Catphan_80kV_2.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

 //F:\均整度\Filtered_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct.raw F:\均整度\Filtered_data\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\Headneck_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct.raw F:\均整度\Filtered_data\Headneck_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1
//F:\均整度\Filtered_data\08-14\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2_Slice1mm\ct.raw F:\均整度\Filtered_data\8-14\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2_Slice1mm\adjusted_100.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\08-20\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\calibrated_raw_data.raw F:\均整度\Filtered_data\08-20\Catphan_80kV_1.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\08-20\Catphan_100kV_2.0mAs_Focus-S_PGA6_Binning2\calibrated_raw_data.raw F:\均整度\Filtered_data\08-20\Catphan_100kV_2.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\08-20\Catphan_120kV_1.0mAs_Focus-S_PGA6_Binning2\calibrated_raw_data.raw F:\均整度\Filtered_data\08-20\Catphan_120kV_1.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\08-21\Catphan_80kV_2.0mAs_Focus-S_PGA6_Binning2\calibrated_raw_data.raw F:\均整度\Filtered_data\08-21\Catphan_80kV_2.0mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1

//F:\均整度\Filtered_data\08-21\Catphan_80kV_2.5mAs_Focus-S_PGA6_Binning2\calibrated_raw_data.raw F:\均整度\Filtered_data\08-21\Catphan_80kV_2.5mAs_Focus-S_PGA6_Binning2\ct_HU.raw 1024 1024 300 0.25 0.25 1