#include<cstdio>
#include<cstdlib>
#include<cstring>

const int MAXN = 1501;

int max(int a,int b)
{
	if (a>b) 
		return a;
	else 
		return b;
}

int main()
{
	int a[MAXN][MAXN],map[MAXN][MAXN],lu[MAXN][MAXN],ru[MAXN][MAXN],ld[MAXN][MAXN],rd[MAXN][MAXN],h[MAXN],v[MAXN];
    int m, n, k, i, j, ans=0;
    scanf("%d%d%d",&m,&n,&k);	// m和n是矩形区域的行数和列数(M,N<=1500),k是每一个承包商承包的正方形的大小（边长的块数）

    /**
     * 初始化地图
     */
    for (i=1;i<=n;i++) 
    	for (j=1;j<=m;j++) 
    		scanf("%d",&map[i][j]);


    for (i=1;i<=n;i++) 
    	for (j=1;j<=m;j++) 
    		map[i][j]+=map[i-1][j];
    for (i=1;i<=n;i++) 
    	for (j=1;j<=m;j++) 
    		map[i][j]+=map[i][j-1];
    for (i=1;i<=n-k+1;i++) 
    	for (j=1;j<=m-k+1;j++) 
    		a[i][j]=map[i+k-1][j+k-1]-map[i-1][j+k-1]-map[i+k-1][j-1]+map[i-1][j-1];
    for (i=1;i<=n-k+1;i++) 
    	for (j=1;j<=m-k+1;j++) 
    		lu[i][j]=max(max(lu[i-1][j],lu[i][j-1]),a[i][j]);
    for (i=1;i<=n-k+1;i++) 
    	for (j=m-k+1;j>0;j--) 
    		ru[i][j]=max(max(ru[i-1][j],ru[i][j+1]),a[i][j]);
    for (i=n-k+1;i>0;i--) 
    	for (j=1;j<=m-k+1;j++) 
    		ld[i][j]=max(max(ld[i+1][j],ld[i][j-1]),a[i][j]);
    for (i=n-k+1;i>0;i--) 
    	for (j=m-k+1;j>0;j--) 
    		rd[i][j]=max(max(rd[i+1][j],rd[i][j+1]),a[i][j]);
    for (i=1;i<=n;i++) 
    	for (j=1;j<=m;j++) 
    		h[i]=max(h[i],a[i][j]),v[j]=max(v[j],a[i][j]);

    /**
     * 从六种情况中找到最大值
     */
    for (i=k;i<=n-2*k;i++){
        int mx = 0;
        for (j=i+k;j<=n-k;j++){
            mx = max(mx,h[j-k+1]);
            ans = max(ans,lu[i-k+1][m-k+1]+mx+ld[j+1][m-k+1]);
        }
    }
    for (i=k;i<=n-k;i++)
        for (j=k;j<=m-k;j++) 
        	ans=max(ans,lu[i-k+1][j-k+1]+ru[i-k+1][j+1]+ld[i+1][m-k+1]);        
    for (i=k;i<=n-k;i++)
        for (j=k;j<=m-k;j++) 
        	ans=max(ans,lu[i-k+1][m-k+1]+ld[i+1][j-k+1]+rd[i+1][j+1]);
    for (i=k;i<=m-2*k;i++){
    	int mx=0;
    	for (j=i+k;j<=m-k;j++){      
        	mx = max(mx,v[j-k+1]);
        	ans = max(ans,lu[n-k+1][i-k+1]+mx+ru[n-k+1][j+1]);
    	}
    }   
    for (i=k;i<=n-k;i++)
        for (j=k;j<=m-k;j++) 
        	ans=max(ans,lu[i-k+1][j-k+1]+ru[n-k+1][j+1]+ld[i+1][j-k+1]);    
    for (i=k;i<=n-k;i++)
        for (j=k;j<=m-k;j++) 
        	ans=max(ans,lu[n-k+1][j-k+1]+ru[i-k+1][j+1]+rd[i+1][j+1]);          
    printf("%d\n",ans);
    return 0;
}

