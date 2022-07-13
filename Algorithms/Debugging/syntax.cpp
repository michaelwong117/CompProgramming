set<pair<ll, int>> q;
int u = q.begin()->first, v = q.begin()->second;
q.erase(q.begin());

int u = *q.begin();

s.substr(4, string::npos) //(all characters till end of string)

//unordered set optimization

s.max_load_factor(0.25);s.reserve(512);