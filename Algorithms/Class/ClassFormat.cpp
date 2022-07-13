
struct Type {

    int memberVariable;


};

struct Interval {
	Interval(int l, int h) : low(l), high(h){}
	int low;
	int high;
};

vec.push_back(Interval(start, finish));
	
sort(vec.begin(), vec.end(), Compare());

class className {
	public:
   		int memberFunction(string &input);
        
};

int className::memberFunction(string &input) {
    //perform some operation
    return res;
}


int main(){
	className instanceOfClass;
	string in = "someinput";
	int out = instanceOfClass.memberFunction(in);
	cout << out << endl;
}

