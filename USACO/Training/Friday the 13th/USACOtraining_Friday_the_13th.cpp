/*
ID: michaelwong11
PROG: friday
LANG: C++     
*/


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int incrementDay(int dayoftheWeek) {
	if (dayoftheWeek == 7) {
		dayoftheWeek = 1;
	} else {
		dayoftheWeek++;
	}
	return dayoftheWeek;
}

//void leapYearCounter(int years){
//	int startingYear = 1900;

//}
void thirteenthCounter(int years){
	int startingYear = 1900;
	int day = 1;
	//Monday is 1, Tuesday is 2, so on and so forth.
	int dayoftheWeek = 1;
	int mon13th = 0;
	int tues13th = 0;
	int wed13th = 0;
	int thurs13th = 0;
	int fri13th = 0;
	int sat13th = 0;
	int sun13th = 0;
	for (int i=0; i<years; ++i){

		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "Jan: sat13th++ = " << sat13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;

		for(day = 1; day<=28; ++day){
			
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);

			bool first = ((1900 + i) % 4 == 0);
			bool second = ((1900 + i) % 100 == 0);
			bool third = ((1900 + i) % 400 == 0);
			if ((first) && (!second)){
				if (day == 28){
					dayoftheWeek = incrementDay(dayoftheWeek);


				}
			}
			else if (third){
				if (day == 28){
					dayoftheWeek = incrementDay(dayoftheWeek);

				}

			}
		}
		//cout << "Feb: tues13th++ = " << tues13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;
		
		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "March: tues13th++ = " << tues13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;

		for(day = 1; day<=30; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "April: fri13th++ = " << fri13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;
		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		for(day = 1; day<=30; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "May: sun13th++ = " << sun13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;
		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "June: wed13th++ = " << wed13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;

		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "July: fri13th++ = " << fri13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;
		for(day = 1; day<=30; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		//cout << "Aguust: fri13th++ = " << fri13th << endl;
		//cout << "dayoftheWeek = " << dayoftheWeek << endl;
		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		for(day = 1; day<=30; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
		for(day = 1; day<=31; ++day){
			if (day == 13){
				if (dayoftheWeek == 1){
					mon13th++;
				}
				if (dayoftheWeek == 2){
					tues13th++;
				}
				if (dayoftheWeek == 3){
					wed13th++;
				}
				if (dayoftheWeek == 4){
					thurs13th++;
				}
				if (dayoftheWeek == 5){
					fri13th++;
				}
				if (dayoftheWeek == 6){
					sat13th++;
				}
				if (dayoftheWeek == 7){
					sun13th++;
				}


			}
			dayoftheWeek = incrementDay(dayoftheWeek);
		}
	}
	ofstream fout ("friday.out");œ
	fout << sat13th << " " << sun13th << " " << mon13th << " " << tues13th << " " << wed13th << " " << thurs13th << " " << fri13th << endl;	
}


int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N;
    fin >> N;
    //fout << a+b << endl;
    thirteenthCounter(N);
    return 0;
} 
