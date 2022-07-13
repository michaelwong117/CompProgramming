bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
}

bool sortbyf(pi &a, pi &b){
	return (a.f < b.f);
}

sort(vect.begin(), vect.end(), sortbysec);

struct Edge {
	int relev;
	int pp;
	int qq;
};

sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
	return a.relev > b.relev;
});
//if you care about pp and qq or any other variables second put an equal clause
