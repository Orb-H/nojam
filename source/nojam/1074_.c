r,c,x;main(n){for(scanf("%d%d%d",&n,&r,&c);n+1;)x+=(2*r&2<<n|c&1<<n)<<n--;printf("%d",x);}