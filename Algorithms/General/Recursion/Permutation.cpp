void permute(vector<int> &final, int l, int r){
	if(l == r) //this is a permutation
	else{
		for(int i = 1; i <= r; i++){
			swap(final[l], final[i]);
			permute(final, l+1, r);
			swap(final[l], final[i]);
		}
	}

}
//cph
vector<bool> chosen (n);
vector<int> permutation;
void search() {
    if (permutation.size() == n) {
       // process permutation
    } else {
       for (int i = 0; i < n; i++) {
           if (chosen[i]) continue;
           chosen[i] = true;
           permutation.push_back(i);
           search();
           chosen[i] = false;
           permutation.pop_back();
       }
} }