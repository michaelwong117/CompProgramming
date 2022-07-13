int dx[]={ 0, 0,+1,-1};
int dy[]={+1,-1, 0, 0};
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if(valid(nx,ny))
        {
            //code
            dfs(nx,ny);
        }
    }
}