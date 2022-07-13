#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

ofstream fout ("friendcross.out");
ifstream fin ("friendcross.in");

struct node2{
    int left, right;
    int val;
    int lch, rch;
};

struct node1{
    int left, right;
    int cnt;
    vector<node2> segtree2;
} segtree[300001];

int n, k;
int a[100001], b[100001];
int po[100001];

node2 in;

void build(int p, int l, int r)
{
    segtree[p].left=l;
    segtree[p].right=r;
    segtree[p].cnt=1;
    segtree[p].segtree2.push_back(in);
    if(l<r){
        build(2*p, l, (l+r)/2);
        build(2*p+1, (l+r)/2+1, r);
    }
}

int getSum(int p, int po, int l, int r)
{
    int x=segtree[p].segtree2[po].left, y=segtree[p].segtree2[po].right, v=segtree[p].segtree2[po].val;
    
    if(!segtree[p].segtree2[po].lch){
        in.left=x, in.right=(x+y)/2;
        segtree[p].segtree2.push_back(in);
        segtree[p].segtree2[po].lch=segtree[p].cnt, segtree[p].cnt++;
    }
    if(!segtree[p].segtree2[po].rch){
        in.left=(x+y)/2+1, in.right=y;
        segtree[p].segtree2.push_back(in);
        segtree[p].segtree2[po].rch=segtree[p].cnt, segtree[p].cnt++;
    }
    int cx=segtree[p].segtree2[po].lch, cy=segtree[p].segtree2[po].rch;
    
    if(l<=x && y<=r)
        return v;
    else{
        int ans=0;
        if(l<=(x+y)/2)
            ans+=getSum(p, cx, l, r);
        if(r>(x+y)/2)
            ans+=getSum(p, cy, l, r);
        return ans;
    }
}

void update2(int p, int po, int index, int val)
{
    int x=segtree[p].segtree2[po].left, y=segtree[p].segtree2[po].right;
    
    if(x==y){
        segtree[p].segtree2[po].val+=val;
        return;
    }
    
    if(!segtree[p].segtree2[po].lch){
        in.left=x, in.right=(x+y)/2;
        segtree[p].segtree2.push_back(in);
        segtree[p].segtree2[po].lch=segtree[p].cnt, segtree[p].cnt++;
    }
    if(!segtree[p].segtree2[po].rch){
        in.left=(x+y)/2+1, in.right=y;
        segtree[p].segtree2.push_back(in);
        segtree[p].segtree2[po].rch=segtree[p].cnt, segtree[p].cnt++;
    }
    int cx=segtree[p].segtree2[po].lch, cy=segtree[p].segtree2[po].rch;
    
    if(index<=(x+y)/2)
        update2(p, cx, index, val);
    else
        update2(p, cy, index, val);
    segtree[p].segtree2[po].val=segtree[p].segtree2[cx].val+segtree[p].segtree2[cy].val;
}

void update(int p, int x, int y, int val)
{
    if(segtree[p].left==segtree[p].right)
        update2(p, 0, y, val);
    else{
        if(x<=(segtree[p].left+segtree[p].right)/2)
            update(2*p, x, y, val);
        else
            update(2*p+1, x, y, val);
        update2(p, 0, y, val);
    }
}

int find(int p, int l, int r, int ll, int rr)
{
    if(l<=segtree[p].left && segtree[p].right<=r)
        return getSum(p, 0, 0, n)-(getSum(p, 0, 0, rr)-getSum(p, 0, 0, ll-1));
    else{
        int ans=0;
        if(l<=(segtree[p].left+segtree[p].right)/2)
            ans+=find(p*2, l, r, ll, rr);
        if(r>(segtree[p].left+segtree[p].right)/2)
            ans+=find(p*2+1, l, r, ll, rr);
        return ans;
    }
}

int main()
{
    int i, ans=0;
    
    fin >> n >> k;
    for(i=1;i<=n;i++)
        fin >> a[i];
    for(i=1;i<=n;i++)
        fin >> b[i], po[b[i]]=i;
    
    in.left=0, in.right=n, in.val=0, in.lch=0, in.rch=0;
    build(1, 1, n);
    for(i=1;i<=n;i++)
        update(1, i, b[i], 1);
    for(i=1;i<=n;i++){
        ans+=find(1, 1, po[a[i]]-1, max(a[i]-k, 1), min(a[i]+k, n));
        update(1, po[a[i]], a[i], -1);
    }
    
    fout << ans << endl;
    
    return 0;
}
